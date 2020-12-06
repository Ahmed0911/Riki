/*
 * main.c
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/uart.h"
#include "driverlib/fpu.h"

#include "Drivers/DBGLed.h"
#include "Drivers/Timer.h"
#include "Drivers/WpnOutputs.h"
#include "Drivers/PWMDrv.h"
#include "Drivers/SerialDriver.h"
#include "Drivers/SBUSComm.h"
#include "Drivers/ADCDrv.h"
#include "Drivers/BaroDrv.h"
#include "Drivers/MPU9250Drv.h"
#include "Drivers/LSM90DDrv.h"
#include "Drivers/UBloxGPS.h"
#include "Drivers/EtherDriver.h"
#include "Drivers/HopeRF.h"
#include "Drivers/IMU.h"
#include "Drivers/swupdate.h"

#include "Ctrl/Ctrl.h"
#include "CommData.h"
#include "LLConverter.h"
#include "LaunchMgr.h"

uint32_t g_ui32SysClock;
extern bool g_swUpdateRequest;

// Drivers
DBGLed dbgLed;
Timer timerLoop;
WpnOutputs wpnOut;
PWMDrv pwmDrv;
SerialDriver serialU2;
SerialDriver serialU3;
SerialDriver serialU5;
SBUSComm sbusRecv;
ADCDrv adcDrv;
BaroDrv baroDrv;
MPU9250Drv mpu9250Drv;
LSM90DDrv lsm90Drv;
UBloxGPS gps;
UBloxGPS gps2;
EtherDriver etherDrv;
HopeRF	hopeRF;
IMU imu;
LaunchMgr launch;

// System Objects
CtrlModelClass ctrl;
LLConverter llConv;

// GPS Port (serialU2->Internal GPS, serialU5->External GPS on Ext Comm.)
#define serialGPS serialU2
#define serialGPS2 serialU5

// Systick
#define SysTickFrequency 400
volatile bool SysTickIntHit = false;

// Buffers
#define COMMBUFFERSIZE 1024
BYTE CommBuffer[COMMBUFFERSIZE];
BYTE HopeRFbuffer[255];

// Global Functions
void InitGPS(void);
void ProcessGPSData(void);
void SendPeriodicDataEth(void);
void ProcessCommand(int cmd, unsigned char* data, int dataSize);

// Global Data
int MainLoopCounter;
float PerfLoopTimeMS;
float PerfCpuTimeMS;
float PerfCpuTimeMSMAX;
float Acc[3];
float Gyro[3];
float Mag[3];
int HopeRSSI;
int AssistNextChunkToSend = 0;
float Pressure0 = 101300;

// Ref/Commands
unsigned char InputMode = 3; // RollPitch is default mode!
unsigned char PreviousActualMode = 0;

// Waypoints + TARGET
float TargetAlt = 30;
float TargetN = 0;
float TargetE = 0;

#define MAXWAYPOINTS 8
float WayAlt[MAXWAYPOINTS];
float WayN[MAXWAYPOINTS];
float WayE[MAXWAYPOINTS];
int WayCnt = 0;
int WayDownloadCnt = 0;
int WayExecute = 0;
float TrajZNEVParams[4];

// OFFSETS
#define GYROOFFX -1.004f
#define GYROOFFY 1.444f
#define GYROOFFZ -0.6995f
#define MAGOFFX 25.2328f
#define MAGOFFY 31.8127f
#define MAGOFFZ 5.1955f
#define ATTOFFROLL 1.0f
#define ATTOFFPITCH 1.5f

//double g1 = 0;
//double g2 = 0;
//double g3 = 0;

void main(void)
{
	// Enable lazy stacking for interrupt handlers.  This allows floating-point
	FPULazyStackingEnable();

	// Ensure that ext. osc is used!
	SysCtlMOSCConfigSet(SYSCTL_MOSC_HIGHFREQ);

	// set clock
	g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);

	// Init
	dbgLed.Init();
	timerLoop.Init();
	wpnOut.Init();
	pwmDrv.Init();
	pwmDrv.SetWidthUS(0, 1000); // Set zero PWMs
	pwmDrv.SetWidthUS(1, 1000); // Set zero PWMs - broken
	pwmDrv.SetWidthUS(2, 1000); // Set zero PWMs
	pwmDrv.SetWidthUS(3, 1000);	// Set zero PWMs
	pwmDrv.SetWidthUS(4, 1000); // Set zero PWMs
	serialU2.Init(UART2_BASE, 9600); // GPS
	serialU3.Init(UART3_BASE, 100000); // SBUS
	serialU5.Init(UART5_BASE, 115200); // Ext. Comm, Ext. GPS - F9
	sbusRecv.Init();
	adcDrv.Init();
	baroDrv.Init();
	mpu9250Drv.Init();
    //lsm90Drv.Init();
	InitGPS(); // init GPS
	etherDrv.Init();
	hopeRF.Init();
	imu.Init();
	launch.Init();
	ctrl.initialize();

	// GPS2
	gps2.Init();



	// Systick
	SysTickPeriodSet(g_ui32SysClock/SysTickFrequency);
	SysTickIntEnable();
	SysTickEnable();

	// Master INT Enable
	IntMasterEnable();

	// FAKE GPS
	//llConv.SetHome(45.80349, 15.88388);

	while(1)
	{
		timerLoop.Start(); // start timer
		MainLoopCounter++;

		// Check SW Update Request
		if( g_swUpdateRequest)
		{
		    SoftwareUpdateBegin(g_ui32SysClock);
		}

		/////////////////////////////////
		// INPUTS
		/////////////////////////////////
		// SBUS Data
		int rd = serialU3.Read(CommBuffer, COMMBUFFERSIZE); // read data from SBUS Recv [2500 bytes/second, read at least 3x per second for 1k buffer!!!]
		sbusRecv.NewRXPacket(CommBuffer, rd); // process data

		// ADC
		adcDrv.Update();

		// Baro
		baroDrv.Update(); // [??? us]

		// IMU1
		mpu9250Drv.Update();
		Acc[0] = -mpu9250Drv.Accel[1];
		Acc[1] = -mpu9250Drv.Accel[0];
		Acc[2] = mpu9250Drv.Accel[2];
		Gyro[0] = mpu9250Drv.Gyro[1] - GYROOFFX;
		Gyro[1] = mpu9250Drv.Gyro[0] - GYROOFFY;
		Gyro[2] = -mpu9250Drv.Gyro[2] - GYROOFFZ;
		Mag[0] = mpu9250Drv.Mag[0] - MAGOFFX;
		Mag[1] = mpu9250Drv.Mag[1] - MAGOFFY;
		Mag[2] = mpu9250Drv.Mag[2] - MAGOFFZ;
		imu.Update(Acc[0], Acc[1], Acc[2], Gyro[0], Gyro[1], Gyro[2], Mag[0], Mag[1], Mag[2]); // TODO: CHECK AXES
		// Correct IMU offsets
		imu.Roll -= ATTOFFROLL;
		imu.Pitch -= ATTOFFPITCH;
		//g1 = 0.9999*g1 + 0.0001*Gyro[0];
		//g2 = 0.9999*g2 + 0.0001*Gyro[1];
		//g3 = 0.9999*g3 + 0.0001*Gyro[2];

		// IMU2
		//lsm90Drv.Update();

		// GPS - REMOVE!!!
		rd = serialGPS.Read(CommBuffer, COMMBUFFERSIZE); // read data from GPS
		gps.NewRXPacket(CommBuffer, rd); // process data

		// GPS2
		rd = serialGPS2.Read(CommBuffer, COMMBUFFERSIZE); // read data from GPS
        gps2.NewRXPacket(CommBuffer, rd); // process data

        // set home position
        if( gps2.NumSV >= 6)
        {
            if( !llConv.IsHomeSet() )
            {
                double lat = gps2.Latitude * 1e-7;
                double lon = gps2.Longitude * 1e-7;
                llConv.SetHome(lat, lon);
            }
        }
        float XN = 0, XE = 0;
        if( llConv.IsHomeSet()) llConv.ConvertLLToM(gps2.Latitude*1e-7, gps2.Longitude*1e-7, XN, XE);

		// Hold Position Mode (automatically set Target on mode 4->5, transition is done through mode 0, see Matlab chart)
		if( (PreviousActualMode == 0) && (ctrl.Ctrl_Y.ActualMode == 5) )
		{
			// set target
			TargetN = XN;
			TargetE = XE;
			TargetAlt = ctrl.Ctrl_Y.Altitude;
		}
		PreviousActualMode = ctrl.Ctrl_Y.ActualMode;


		// Set Pressure0 on 2 sec
		if(MainLoopCounter == (SysTickFrequency * 2)) Pressure0 = baroDrv.PressurePa;

		// process ethernet (RX)
		etherDrv.Process(1000/SysTickFrequency); // 2.5ms tick

		// HopeRF
		HopeRSSI = hopeRF.ReadRSSI();
		// Hope RX Stuff
		int hopeReceived = hopeRF.Read(HopeRFbuffer);
//		if( hopeReceived > 0) // DO NOT USE HOPERF
//		{
//			// TODO: Add additional check to avoid crash on invalid RF packet!!!
//			if( (HopeRFbuffer[0] == 0x80) && ((hopeReceived-1) == sizeof(SCommGotoExecute)) ) // allow goto/abort command only
//			{
//				ProcessCommand(HopeRFbuffer[0], &HopeRFbuffer[1], hopeReceived-1);
//			}
//		}

		// set inputs
		ctrl.Ctrl_U.RPY[0] = imu.Roll;
		ctrl.Ctrl_U.RPY[1] = imu.Pitch;
		ctrl.Ctrl_U.RPY[2] = imu.Yaw;
		ctrl.Ctrl_U.dRPY[0] = Gyro[0];
		ctrl.Ctrl_U.dRPY[1] = Gyro[1];
		ctrl.Ctrl_U.dRPY[2] = Gyro[2];
		ctrl.Ctrl_U.PressureAbs = baroDrv.PressurePa;
		ctrl.Ctrl_U.Pressure0 = Pressure0;
		ctrl.Ctrl_U.BatteryVoltage = adcDrv.BATTVoltage();
		ctrl.Ctrl_U.ModeCode = InputMode;
		ctrl.Ctrl_U.Mode = sbusRecv.Channels[4]; // Mode selector
		ctrl.Ctrl_U.Thr = sbusRecv.Channels[0];
		ctrl.Ctrl_U.Aileron = sbusRecv.Channels[1];
		ctrl.Ctrl_U.Elevator = sbusRecv.Channels[2];
		ctrl.Ctrl_U.Rudder = sbusRecv.Channels[3];
		ctrl.Ctrl_U.FlatVe[0] = gps2.VelN / 1000.0f; // [m/s], Northing - X
		ctrl.Ctrl_U.FlatVe[1] = gps2.VelE / 1000.0f; // [m/s], Easting - Y
		ctrl.Ctrl_U.FlatVe[2] = gps2.VelD / 1000.0f; // [m/s], Down - Z, -> ignored, gps alt Z vel is not accurate! Probably?!
		ctrl.Ctrl_U.FlatXe[0] = XN;
		ctrl.Ctrl_U.FlatXe[1] = XE;
		ctrl.Ctrl_U.GPSHeight = gps2.HeightMSL/1000.0f; // GPS height in [m]

		// fill waypoint buffer
		ctrl.Ctrl_U.Waypoints[0] = TargetAlt;
		ctrl.Ctrl_U.Waypoints[9] = TargetN;
		ctrl.Ctrl_U.Waypoints[18] = TargetE;
		for(int i=0; i!=MAXWAYPOINTS; i++)
		{
			ctrl.Ctrl_U.Waypoints[1+i] = WayAlt[i];
			ctrl.Ctrl_U.Waypoints[10+i] = WayN[i];
			ctrl.Ctrl_U.Waypoints[19+i] = WayE[i];
		}
		ctrl.Ctrl_U.WayCnt = WayCnt;
		ctrl.Ctrl_U.ExecuteWaypoints = WayExecute;
		ctrl.Ctrl_U.TrajZNEVParams[0] = TrajZNEVParams[0];
		ctrl.Ctrl_U.TrajZNEVParams[1] = TrajZNEVParams[1];
		ctrl.Ctrl_U.TrajZNEVParams[2] = TrajZNEVParams[2];
		ctrl.Ctrl_U.TrajZNEVParams[3] = TrajZNEVParams[3];
		WayExecute = 0; // auto reset flag


		/////////////////////////////////
		// CTRL STEP
		/////////////////////////////////
		ctrl.step();


		/////////////////////////////////
		// OUTPUTS
		/////////////////////////////////
		pwmDrv.SetWidthUS(0, ctrl.Ctrl_Y.PWM1);
		pwmDrv.SetWidthUS(1, ctrl.Ctrl_Y.PWM2); // broken, replaced with "4"
		pwmDrv.SetWidthUS(2, ctrl.Ctrl_Y.PWM3);
		pwmDrv.SetWidthUS(3, ctrl.Ctrl_Y.PWM4);
		pwmDrv.SetWidthUS(4, ctrl.Ctrl_Y.PWM2);

		// Launch Process
		launch.Update();

		// DBG LED
		dbgLed.Set(ctrl.Ctrl_Y.LEDs[0]);

		// send periodic data (ethernet + hopeRF)
		SendPeriodicDataEth();



		// Get CPU Time
		PerfCpuTimeMS = timerLoop.GetUS()/1000.0f;
		if( PerfCpuTimeMS > PerfCpuTimeMSMAX ) PerfCpuTimeMSMAX = PerfCpuTimeMS;
		// wait next
		while(!SysTickIntHit);
		SysTickIntHit = false;
		// Get total loop time
		PerfLoopTimeMS = timerLoop.GetUS()/1000.0f;
	}
}

void SendPeriodicDataEth(void)
{
	// Fill data
	SCommEthData data;
	data.LoopCounter = MainLoopCounter;
	data.ActualMode = ctrl.Ctrl_Y.ActualMode;
	data.Roll = imu.Roll;
	data.Pitch = imu.Pitch;
	data.Yaw = imu.Yaw;
	data.dRoll = Gyro[0];
	data.dPitch = Gyro[1];
	data.dYaw = Gyro[2];
	data.AccX = Acc[0];
	data.AccY = Acc[1];
	data.AccZ = Acc[2];
	data.MagX = Mag[0];
	data.MagY = Mag[1];
	data.MagZ = Mag[2];

	data.Pressure = baroDrv.PressurePa;
	data.Temperature = baroDrv.TemperatureC;
	data.Altitude = ctrl.Ctrl_Y.Altitude;
	data.Vertspeed = ctrl.Ctrl_Y.VertSpeed;
	data.FuelLevel = ctrl.Ctrl_Y.FuelPercent;
	data.BatteryVoltage = adcDrv.BATTVoltage();
	data.MotorThrusts[0] = (unsigned char)(100*(ctrl.Ctrl_Y.PWM1-1000)/900);
	data.MotorThrusts[1] = (unsigned char)(100*(ctrl.Ctrl_Y.PWM2-1000)/900);
	data.MotorThrusts[2] = (unsigned char)(100*(ctrl.Ctrl_Y.PWM3-1000)/900);
	data.MotorThrusts[3] = (unsigned char)(100*(ctrl.Ctrl_Y.PWM4-1000)/900);

	// gps
	data.GPSTime = gps.GPSTime;
	data.FixType = gps.FixType;
	data.FixFlags = gps.FixFlags;
	data.NumSV = gps.NumSV;
	data.Longitude = gps.Longitude;
	data.Latitude = gps.Latitude;
	data.HeightMSL = gps.HeightMSL;
	data.HorizontalAccuracy = gps.HorizontalAccuracy;
	data.VerticalAccuracy = gps.VerticalAccuracy;
	data.VelN = gps.VelN;
	data.VelE = gps.VelE;
	data.VelD = gps.VelD;
	data.SpeedAcc = gps.SpeedAcc;
	memcpy(data.SatCNOs, gps.SatCNOs, sizeof(data.SatCNOs));

	// GPS2 - F9
	data.GPSTime2 = gps2.GPSTime;
	data.NumSV2 = gps2.NumSV;
	data.FixType2 = gps2.FixType;
	data.FixFlags2= gps2.FixFlags;
	data.Longitude2 = gps2.Longitude;
	data.Latitude2 = gps2.Latitude;
	data.HeightMSL2 = gps2.HeightMSL;
	data.HorizontalAccuracy2 = gps2.HorizontalAccuracy;
	data.VerticalAccuracy2 = gps2.VerticalAccuracy;
	data.VelN2 = gps2.VelN;
	data.VelE2 = gps2.VelE;
	data.VelD2 = gps2.VelD;
	data.SpeedAcc2 = gps2.SpeedAcc;

    // NAV-HPPOSLLH
	data.GPSTimeHP = gps2.GPSTimeHP;
	data.LongitudeHP = gps2.LongitudeHP;
	data.LatitudeHP = gps2.LatitudeHP;
	data.HeightEllipsoidHP = gps2.HeightEllipsoidHP;
	data.HeightMSLHP = gps2.HeightMSLHP;
	data.LongitudeHPP = gps2.LongitudeHPP;
	data.LatitudeHPP = gps2.LatitudeHPP;
	data.HeightEllipsoidHPP = gps2.HeightEllipsoidHPP;
	data.HeightMSLHPP = gps2.HeightMSLHPP;
	data.HorizontalAccuracyHP = gps2.HorizontalAccuracyHP;
	data.VerticalAccuracyHP = gps2.VerticalAccuracyHP;

    // NAV-RELPOSNED
	data.GPSTimeRelPos = gps2.GPSTimeRelPos;
	data.RelPosN = gps2.RelPosN;
	data.RelPosE = gps2.RelPosE;
	data.RelPosD = gps2.RelPosD;
	data.RelPosHPN = gps2.RelPosHPN;
	data.RelPosHPE = gps2.RelPosHPE;
	data.RelPosHPD = gps2.RelPosHPD;
	data.RelAccN = gps2.RelAccN;
	data.RelAccE = gps2.RelAccE;
	data.RelAccD = gps2.RelAccD;



	// RF Data + Perf
	data.EthReceivedCount = etherDrv.ReceivedFrames;
	data.EthSentCount = etherDrv.SentFrames;
	data.HopeRXFrameCount = hopeRF.ReceivedFrames;
	data.HopeRXRSSI = hopeRF.PacketRSSI;
	data.HopeRSSI = HopeRSSI;
	data.PerfCpuTimeMS = PerfCpuTimeMS;
	data.PerfCpuTimeMSMAX = PerfCpuTimeMSMAX;
	data.PerfLoopTimeMS = PerfLoopTimeMS;

	data.AssistNextChunkToSend = AssistNextChunkToSend;

	// Waypoints
	data.WaypointCnt = WayCnt;
	data.WaypointDownloadCounter = WayDownloadCnt;
	double hLat, hLong;
	llConv.GetHome(hLat, hLong);
	data.HomeLatitude = hLat*1e7;
	data.HomeLongitude = hLong*1e7;

	// Launch Mgr
	data.LaunchStatus1 = launch.WpnState[0];
	data.LaunchStatus2 = launch.WpnState[1];

	// Tuning data
	data.TuningData[0] = sbusRecv.Channels[0]; // thr
	data.TuningData[1] = sbusRecv.Channels[4]; // mode
	data.TuningData[2] = sbusRecv.Channels[5]; // aux mode
	data.TuningData[3] = sbusRecv.SystemByte; // systemByte
	data.TuningData[4] = ctrl.Ctrl_B.VertVelRef;
	data.TuningData[5] = ctrl.Ctrl_B.VertVelOut;
	data.TuningData[6] = ctrl.Ctrl_B.VertVelRef5;
	data.TuningData[7] = ctrl.Ctrl_B.VertVelOut5;
	data.TuningData[8] = 0;
	data.TuningData[9] = 0;

	// send packet (type 0x20 - data)
	etherDrv.SendPacket(0x20, (char*)&data, sizeof(data));

	// Send to HopeRF
	if( MainLoopCounter%100 == 0) // 400hz/100 = 4hz, every 250ms
	{
		SCommHopeRFData dataRF;
		dataRF.LoopCounter = MainLoopCounter;
		dataRF.ActualMode = ctrl.Ctrl_Y.ActualMode;
		dataRF.Roll = imu.Roll;
		dataRF.Pitch = imu.Pitch;
		dataRF.Yaw = imu.Yaw;
		dataRF.Altitude = ctrl.Ctrl_Y.Altitude;
		dataRF.Vertspeed = ctrl.Ctrl_Y.VertSpeed;
		dataRF.FuelLevel = ctrl.Ctrl_Y.FuelPercent;
		dataRF.BatteryVoltage = adcDrv.BATTVoltage();
		dataRF.FixType = gps.FixType;
		dataRF.FixFlags = gps.FixFlags;
		dataRF.NumSV = gps.NumSV;
		dataRF.Longitude = gps.Longitude;
		dataRF.Latitude = gps.Latitude;
		dataRF.VelN = gps.VelN;
		dataRF.VelE = gps.VelE;
		dataRF.HopeRXFrameCount = hopeRF.ReceivedFrames;
		dataRF.HopeRXRSSI = hopeRF.PacketRSSI;
		dataRF.HopeTXRSSI = 0; // will be filled on GW station

		//hopeRF.Write((BYTE*)&dataRF, sizeof(dataRF)); // DO NOT USE HOPERF!
	}
}

// Process commands received from Ethernet and HopeRF
void ProcessCommand(int cmd, unsigned char* data, int dataSize)
{
	switch( cmd )
	{
		case 0x30: // AssistNow
		{
			// send data to GPS
			serialGPS.Write(data, dataSize );
			AssistNextChunkToSend++;
			// TODO: Reset AssistNextChunkToSend somewhere!!
			break;
		}

		case 0x40: // Relay to HopeRF
		{
			// Send to hopeRF
			hopeRF.Write(data, dataSize);
			AssistNextChunkToSend = 0;
			break;
		}

		case 0x60: // new params
		{
			// fill data
			SCommParams p;
			memcpy(&p, data, dataSize);
			AltRateBias = p.Params[0];
			AltRateKp = p.Params[1];
			AltRateKi = p.Params[2];
			AltKp = p.Params[3];
			//RollPitchRateMax = p.Params[4];
			//AltRateKp = p.Params[5];
			//AltRateKi = p.Params[6];
			VelKp = p.Params[7];
			VelKi = p.Params[8];
			PosKp = p.Params[9];
			break;
		}

		case 0x61: // request params
		{
			SCommParams p;
			p.Params[0] = AltRateBias;
			p.Params[1] = AltRateKp;
			p.Params[2] = AltRateKi;
			p.Params[3] = AltKp;
			p.Params[4] = 0;
			p.Params[5] = 0;
			p.Params[6] = 0;
			p.Params[7] = VelKp;
			p.Params[8] = VelKi;
			p.Params[9] = PosKp;

			// send packet (type 0x20 - data)
			etherDrv.SendPacket(0x62, (char*)&p, sizeof(p));
			break;
		}

		case 0x80: // Goto/Execute waypoints
		{
			// fill data
			SCommGotoExecute gotoExecuteCmd;
			memcpy(&gotoExecuteCmd, data, dataSize);

			if( gotoExecuteCmd.Command == 0x01 )
			{
				// goto target
				if( llConv.IsHomeSet())
				{
					float XN = 0;
					float XE = 0;
					llConv.ConvertLLToM(gotoExecuteCmd.TargetWaypoint.Latitude*1e-7, gotoExecuteCmd.TargetWaypoint.Longitude*1e-7, XN, XE);
					TargetAlt = gotoExecuteCmd.TargetWaypoint.Altitude;
					TargetN = XN;
					TargetE = XE;
				}
			}
			if( gotoExecuteCmd.Command == 0x02 )
			{
				// start waypoints
				TrajZNEVParams[3] = gotoExecuteCmd.Velocity; // waypoint velocity
				WayExecute = 1;
			}
			if( gotoExecuteCmd.Command == 0x03 )
			{
				// start orbit mode
				if( llConv.IsHomeSet())
				{
					float XN = 0;
					float XE = 0;
					llConv.ConvertLLToM(gotoExecuteCmd.TargetWaypoint.Latitude*1e-7, gotoExecuteCmd.TargetWaypoint.Longitude*1e-7, XN, XE);
					TrajZNEVParams[0] = gotoExecuteCmd.TargetWaypoint.Altitude;
					TrajZNEVParams[1] = XN;
					TrajZNEVParams[2] = XE;
					TrajZNEVParams[3] = gotoExecuteCmd.Velocity;
					WayExecute = 2;
				}
			}
			if( gotoExecuteCmd.Command == 10 )
			{
				// Abort waypoints
				WayExecute = 10;
			}
			break;
		}

		case 0x81: // download waypoints
		{
			// fill data
			SCommWaypoints waypointDownloadCmd;
			memcpy(&waypointDownloadCmd, data, dataSize);

			if( llConv.IsHomeSet())
			{
				for(int i=0; i!= waypointDownloadCmd.WaypointCnt; i++)
				{
					float XN = 0;
					float XE = 0;
					llConv.ConvertLLToM(waypointDownloadCmd.waypoints[i].Latitude*1e-7, waypointDownloadCmd.waypoints[i].Longitude*1e-7, XN, XE);
					WayAlt[i] = waypointDownloadCmd.waypoints[i].Altitude;
					WayN[i] = XN;
					WayE[i] = XE;
				}
				WayCnt = waypointDownloadCmd.WaypointCnt;
				WayDownloadCnt++;
			}
			break;
		}
		case 0x90: // Launch codes
		{
			// fill data
			SCommLaunch launchCmd;
			memcpy(&launchCmd, data, dataSize);

			if( launchCmd.Command == 1) launch.Arm(launchCmd.Index, launchCmd.CodeTimer);
			else if( launchCmd.Command == 2  ) launch.Fire(launchCmd.Index, launchCmd.CodeTimer);
			else if( launchCmd.Command == 3  ) launch.Dearm(launchCmd.Index, launchCmd.CodeTimer);

			break;
		}
	}
}



void InitGPS(void)
{
	SysCtlDelay(g_ui32SysClock); // Wait Ext. GPS to boot

	gps.Init();
	// send GPS init commands
	int toSend = gps.GenerateMsgCFGPrt(CommBuffer, 57600); // set to 57k
	serialGPS.Write(CommBuffer, toSend);
	SysCtlDelay(g_ui32SysClock/10); // 100ms wait, flush
	serialGPS.Init(UART2_BASE, 57600); // open with 57k (115k doesn't work well??? small int FIFO, wrong INT prio?)'
	toSend = gps.GenerateMsgCFGRate(CommBuffer, 100); // 100ms rate, 10Hz
	serialGPS.Write(CommBuffer, toSend);
	toSend = gps.GenerateMsgCFGMsg(CommBuffer, 0x01, 0x07, 1); // NAV-PVT
	serialGPS.Write(CommBuffer, toSend);
	toSend = gps.GenerateMsgCFGMsg(CommBuffer, 0x01, 0x35, 1); // NAV-SAT
	serialGPS.Write(CommBuffer, toSend);
	toSend = gps.GenerateMsgNAV5Msg(CommBuffer, 6, 3); // airborne <1g, 2D/3D mode
	//toSend = m_GPS.GenerateMsgNAV5Msg(CommBuffer, 7, 2); // airborne <2g, 3D mode only
	serialGPS.Write(CommBuffer, toSend);

	// check response
	SysCtlDelay(g_ui32SysClock/10); // 100ms wait, wait response
	int rd = serialGPS.Read(CommBuffer, COMMBUFFERSIZE);
	gps.NewRXPacket(CommBuffer, rd);
}

///////////////
// INTERRUPTS
///////////////
extern "C" void UART2IntHandler(void)
{
	serialU2.IntHandler();
}

extern "C" void UART3IntHandler(void)
{
	serialU3.IntHandler();
}

extern "C" void UART5IntHandler(void)
{
	serialU5.IntHandler();
}

extern "C" void IntGPIOA(void)
{
	lsm90Drv.MotionINTG();
	lsm90Drv.MotionINTX();
}

extern "C" void IntGPIOH(void)
{
	lsm90Drv.MotionINTM();
}

extern "C" void IntGPIOK(void)
{
	mpu9250Drv.MotionINT();
}

extern "C" void IntGPION(void)
{
	hopeRF.IntHandler();
}

extern "C" void SysTickIntHandler(void)
{
	SysTickIntHit = true;
}
