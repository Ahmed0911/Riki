using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Diagnostics;

namespace WinEthApp
{
    public partial class FormMain : Form
    {
        MainSystem mainSystem;
        Navigation navigation;
        Gateway gateway;
        GimbaledTracker gimbaledTracker;

        // Filtered Data (RPY)
        public double FilteredRoll;
        public double FilteredPitch;
        public double FilteredYaw;

        public double[] FilteredTuningLastData = new double[10];
        public double[] FilteredTuningData = new double[10];

        public FormMain()
        {
            InitializeComponent();

            mainSystem = new MainSystem(this);
            gateway = new Gateway(this);
            navigation = new Navigation(this, mainSystem, gateway);
            gimbaledTracker = new GimbaledTracker();
            comboBoxMapSelector.SelectedIndex = comboBoxMapSelector.Items.Count-1; // Load default map            
            comboBoxGWTrackerMode.SelectedIndex = 0;
            // Fill Default Params
            labelParam1.Text = "AltRateBias";
            labelParam2.Text = "AltRateKp";
            labelParam3.Text = "AltRateKi";
            labelParam4.Text = "AltKp";
            labelParam5.Text = "";
            labelParam6.Text = "";
            labelParam7.Text = "";
            labelParam8.Text = "VelKp";
            labelParam9.Text = "VelKi";
            labelParam10.Text = "PosKp";

            labelTuning1.Text = "SBUS-Thr";
            labelTuning2.Text = "SBUS-Mode";
            labelTuning3.Text = "SBUS-AuxMode";
            labelTuning4.Text = "SBUS-System";
            labelTuning5.Text = "VertVelRef";
            labelTuning6.Text = "VertVelOut";
            labelTuning7.Text = "VertVelRef5";
            labelTuning8.Text = "VertVelOut5";
            labelTuning9.Text = "";
            labelTuning10.Text = "";
        }

        private void buttonConnectSystem_Click(object sender, EventArgs e)
        {
            mainSystem.Connect(textBoxAddressSystem.Text);
            buttonConnectSystem.Enabled = false;
            buttonConnectSystem.Text = "Opened";
        }

        private void buttonConnectGateway_Click(object sender, EventArgs e)
        {
            gateway.Connect(textBoxAddressGateway.Text);
            buttonConnectGateway.Enabled = false;
            buttonConnectGateway.Text = "Opened";
        }

        private double T = 0;
        private void timerCommUpdate_Tick(object sender, EventArgs e)
        {
            mainSystem.Update();
            navigation.Update();
            gateway.Update();
            UpdateTracker();

            // REMOVE START
            // dummy, REMOVE ME
            /*float altitude = (float)((Math.Cos(T+0.3)+1)*50);
            double N = Math.Cos(T) * 20;
            double E = Math.Sin(T) * 20;
            T += 0.1;
            gimbaledTracker.UpdateTargetPosition(altitude, N, E);
            textBoxGWTrackerTargetN.Text = string.Format("{0:0.00} m", N);
            textBoxGWTrackerTargetE.Text = string.Format("{0:0.00} m", E);
            textBoxGWTrackerTargetZ.Text = string.Format("{0:0.00} m", altitude);*/
            // REMOVE END
        }       

        private void buttonLocAssist_Click(object sender, EventArgs e)
        {
            mainSystem.ExecuteAssistNow();            
        }

        private void buttonWpnCommand_Click(object sender, EventArgs e)
        {
            if (sender == buttonWpnArm1)
            {
                if( buttonWpnArm1.Text == "Arm") 
                {
                    buttonWpnArm1.Text = "Dearm";
                    mainSystem.WpnCommand(0, 1);
                }
                else
                {
                    buttonWpnArm1.Text = "Arm";
                    mainSystem.WpnCommand(0, 3);
                }
            }
            if (sender == buttonWpnArm2)
            {
                if( buttonWpnArm2.Text == "Arm") 
                {
                    buttonWpnArm2.Text = "Dearm";
                    mainSystem.WpnCommand(1, 1);
                }
                else
                {
                    buttonWpnArm2.Text = "Arm";
                    mainSystem.WpnCommand(1, 3);
                }
            }
            if( sender == buttonWpnFire1 )
            {
                mainSystem.WpnCommand(0, 2);
            }
            if (sender == buttonWpnFire2)
            {
                mainSystem.WpnCommand(1, 2);
            }
        }  

        private unsafe void buttonWriteParams_Click(object sender, EventArgs e)
        {
            // Get data from form
            SCommParams p = new SCommParams();            
            p.Params[0] = float.Parse(textBoxParam1.Text);
            p.Params[1] = float.Parse(textBoxParam2.Text);
            p.Params[2] = float.Parse(textBoxParam3.Text);
            p.Params[3] = float.Parse(textBoxParam4.Text);
            p.Params[4] = float.Parse(textBoxParam5.Text);
            p.Params[5] = float.Parse(textBoxParam6.Text);
            p.Params[6] = float.Parse(textBoxParam7.Text);
            p.Params[7] = float.Parse(textBoxParam8.Text);
            p.Params[8] = float.Parse(textBoxParam9.Text);
            p.Params[9] = float.Parse(textBoxParam10.Text);

            mainSystem.WriteParams(p);            
        }

        private void buttonReadParams_Click(object sender, EventArgs e)
        {
            mainSystem.ReadParams();
        }

        public unsafe void DisplayParams(SCommParams p)
        {
            textBoxParam1.Text = p.Params[0].ToString();
            textBoxParam2.Text = p.Params[1].ToString();
            textBoxParam3.Text = p.Params[2].ToString();
            textBoxParam4.Text = p.Params[3].ToString();
            textBoxParam5.Text = p.Params[4].ToString();
            textBoxParam6.Text = p.Params[5].ToString();
            textBoxParam7.Text = p.Params[6].ToString();
            textBoxParam8.Text = p.Params[7].ToString();
            textBoxParam9.Text = p.Params[8].ToString();
            textBoxParam10.Text = p.Params[9].ToString();
        }

        public unsafe void DisplayTuningData()
        {
            textBoxTuning1.Text = FilteredTuningLastData[0].ToString("0.000");
            textBoxTuning2.Text = FilteredTuningLastData[1].ToString("0.000");
            textBoxTuning3.Text = FilteredTuningLastData[2].ToString("0.000");
            textBoxTuning4.Text = FilteredTuningLastData[3].ToString("0.000");
            textBoxTuning5.Text = FilteredTuningLastData[4].ToString("0.000");
            textBoxTuning6.Text = FilteredTuningLastData[5].ToString("0.000");
            textBoxTuning7.Text = FilteredTuningLastData[6].ToString("0.000");
            textBoxTuning8.Text = FilteredTuningLastData[7].ToString("0.000");
            textBoxTuning9.Text = FilteredTuningLastData[8].ToString("0.000");
            textBoxTuning10.Text = FilteredTuningLastData[9].ToString("0.000");

            textBoxTuningFiltered1.Text = FilteredTuningData[0].ToString("0.000");
            textBoxTuningFiltered2.Text = FilteredTuningData[1].ToString("0.000");
            textBoxTuningFiltered3.Text = FilteredTuningData[2].ToString("0.000");
            textBoxTuningFiltered4.Text = FilteredTuningData[3].ToString("0.000");
            textBoxTuningFiltered5.Text = FilteredTuningData[4].ToString("0.000");
            textBoxTuningFiltered6.Text = FilteredTuningData[5].ToString("0.000");
            textBoxTuningFiltered7.Text = FilteredTuningData[6].ToString("0.000");
            textBoxTuningFiltered8.Text = FilteredTuningData[7].ToString("0.000");
            textBoxTuningFiltered9.Text = FilteredTuningData[8].ToString("0.000");
            textBoxTuningFiltered10.Text = FilteredTuningData[9].ToString("0.000");
        }

        public unsafe void DisplaySystemData(int ReceivedPacketsCounter, SCommEthData MainSystemData)
        {
            if (radioButtonWifi.Checked || radioButtonWifiHopeRF.Checked)
            {
                // GPS
                textBoxLocTime.Text = MainSystemData.GPSTime.ToString();
                textBoxLocSatNr.Text = MainSystemData.NumSV.ToString();
                textBoxNavLocSatNr.Text = MainSystemData.NumSV.ToString();
                textBoxLocLat.Text = (MainSystemData.Latitude * 1e-7).ToString("0.000000");
                textBoxLocLon.Text = (MainSystemData.Longitude * 1e-7).ToString("0.000000");
                textBoxHomeLat.Text = (MainSystemData.HomeLatitude * 1e-7).ToString("0.000000");
                textBoxHomeLon.Text = (MainSystemData.HomeLongitude * 1e-7).ToString("0.000000");
                textBoxLocVelocityN.Text = (MainSystemData.VelN / 1000.0).ToString("0.00 m/s");
                textBoxLocVelocityE.Text = (MainSystemData.VelE / 1000.0).ToString("0.00 m/s");
                textBoxLocPressure.Text = (MainSystemData.Pressure / 100).ToString("0.00 hPa");
                textBoxLocTemperature.Text = (MainSystemData.Temperature).ToString("0.0 °C");
                textBoxLocAlt.Text = (MainSystemData.Altitude).ToString("0.0 m");
                textBoxLocVertSpeed.Text = (MainSystemData.Vertspeed).ToString("0.0 m/s");
                textBoxLocAssist.Text = MainSystemData.AssistNextChunkToSend.ToString();
                string cnos1 = "";
                string cnos2 = "";
                for (int i = 0; i != 16; i++)
                {
                    cnos1 += string.Format("{0}", MainSystemData.SatCNOs[i]) + Environment.NewLine;
                    cnos2 += string.Format("{0}", MainSystemData.SatCNOs[i + 16]) + Environment.NewLine;
                }
                textBoxSatCNOs1.Text = cnos1;
                textBoxSatCNOs2.Text = cnos2;

                // Attitude
                textBoxRoll.Text = MainSystemData.Roll.ToString("0.0 °");
                textBoxPitch.Text = MainSystemData.Pitch.ToString("0.0 °");
                textBoxYaw.Text = MainSystemData.Yaw.ToString("0.0 °");
                textBoxAccX.Text = MainSystemData.AccX.ToString("0.0 m/s2");
                textBoxAccY.Text = MainSystemData.AccY.ToString("0.0 m/s2");
                textBoxAccZ.Text = MainSystemData.AccZ.ToString("0.0 m/s2");
                textBoxMagX.Text = MainSystemData.MagX.ToString("0.0 uT");
                textBoxMagY.Text = MainSystemData.MagY.ToString("0.0 uT");
                textBoxMagZ.Text = MainSystemData.MagZ.ToString("0.0 uT");

                textBoxdRoll.Text = MainSystemData.dRoll.ToString("0.0 °/s");
                textBoxdPitch.Text = MainSystemData.dPitch.ToString("0.0 °/s");
                textBoxdYaw.Text = MainSystemData.dYaw.ToString("0.0 °/s");

                textBoxdRollFiltered.Text = FilteredRoll.ToString("0.000 °/s");
                textBoxdPitchFiltered.Text = FilteredPitch.ToString("0.000 °/s");
                textBoxdYawFiltered.Text = FilteredYaw.ToString("0.000 °/s");

                // System
                textBoxSystemEthFrames.Text = ReceivedPacketsCounter.ToString();
                textBoxSystemEthSent.Text = MainSystemData.EthSentCount.ToString();
                textBoxSystemEthReceived.Text = MainSystemData.EthReceivedCount.ToString();

                textBoxSystemLoop.Text = MainSystemData.LoopCounter.ToString();
                textBoxSystemLoopTime.Text = MainSystemData.PerfLoopTimeMS.ToString("0.000 ms");
                textBoxSystemCPUTime.Text = MainSystemData.PerfCpuTimeMS.ToString("0.000 ms");
                textBoxSystemCPUTimeMax.Text = MainSystemData.PerfCpuTimeMSMAX.ToString("0.000 ms");
                textBoxSystemBattery.Text = MainSystemData.BatteryVoltage.ToString("0.00 V");
                textBoxSystemBatteryPercent.Text = MainSystemData.FuelLevel.ToString("0.0 ") + "%";
                textBoxNavigationBatteryPercent.Text = MainSystemData.FuelLevel.ToString("0.0 ") + "%";
                textBoxSystemMode.Text = MainSystemData.ActualMode.ToString();
                textBoxNavigationMode.Text = MainSystemData.ActualMode.ToString();
                textBoxSystemT1.Text = MainSystemData.MotorThrusts[0].ToString();
                textBoxSystemT2.Text = MainSystemData.MotorThrusts[1].ToString();
                textBoxSystemT3.Text = MainSystemData.MotorThrusts[2].ToString();
                textBoxSystemT4.Text = MainSystemData.MotorThrusts[3].ToString();

                // HopeRF
                textBoxHopeRXCount.Text = MainSystemData.HopeRXFrameCount.ToString();
                textBoxHopeRSSI.Text = MainSystemData.HopeRSSI.ToString();
                textBoxHopeRXRSSI.Text = MainSystemData.HopeRXRSSI.ToString();

                textBoxWaypointsCnt.Text = MainSystemData.WaypointCnt.ToString();
                textBoxWaypointsDownloadCnt.Text = MainSystemData.WaypointDownloadCounter.ToString();

                // Download map
                textBoxMapDownloadLat.Text = (MainSystemData.Latitude * 1e-7).ToString("0.000000");
                textBoxMapDownloadLon.Text = (MainSystemData.Longitude * 1e-7).ToString("0.000000");

                // Launch
                string[] launchStatus = { "Idle", "Armed", "Firing" };
                textBoxWpnStatus1.Text = launchStatus[MainSystemData.LaunchStatus1];
                textBoxWpnStatus2.Text = launchStatus[MainSystemData.LaunchStatus2];

                // Update Home
                navigation.SetHome(MainSystemData.HomeLongitude * 1e-7, MainSystemData.HomeLatitude * 1e-7);
                // Update current position
                navigation.UpdateCurrentPosition(MainSystemData.Altitude, MainSystemData.Longitude * 1e-7, MainSystemData.Latitude * 1e-7, MainSystemData.ActualMode);
                
                // Update Target Position
                if( navigation.llConv.IsHomeSet() )
                {
                    float N, E;
                    navigation.llConv.ConvertLLToM(MainSystemData.Latitude * 1e-7, MainSystemData.Longitude * 1e-7, out N, out E);
                    gimbaledTracker.UpdateTargetPosition(MainSystemData.Altitude, N, E);
                    textBoxGWTrackerTargetN.Text = string.Format("{0:0.00} m", N);
                    textBoxGWTrackerTargetE.Text = string.Format("{0:0.00} m", E);
                    textBoxGWTrackerTargetZ.Text = string.Format("{0:0.00} m", MainSystemData.Altitude);
                }
            }               
        }
        public unsafe void DisplayRelayedData(SCommHopeRFData RelayedData)
        {
            if (radioButtonHopeRF.Checked || radioButtonWifiHopeRF.Checked)
            {
                // GPS
                textBoxLocSatNr.Text = RelayedData.NumSV.ToString();
                textBoxNavLocSatNr.Text = RelayedData.NumSV.ToString();
                textBoxLocLat.Text = (RelayedData.Latitude * 1e-7).ToString("0.000000");
                textBoxLocLon.Text = (RelayedData.Longitude * 1e-7).ToString("0.000000");
                textBoxLocVelocityN.Text = (RelayedData.VelN / 1000.0).ToString("0.00 m/s");
                textBoxLocVelocityE.Text = (RelayedData.VelE / 1000.0).ToString("0.00 m/s");
                textBoxLocAlt.Text = (RelayedData.Altitude).ToString("0.0 m");
                textBoxLocVertSpeed.Text = (RelayedData.Vertspeed).ToString("0.0 m/s");

                // Attitude
                textBoxRoll.Text = RelayedData.Roll.ToString("0.0 °");
                textBoxPitch.Text = RelayedData.Pitch.ToString("0.0 °");
                textBoxYaw.Text = RelayedData.Yaw.ToString("0.0 °");

                // System
                textBoxSystemLoop.Text = RelayedData.LoopCounter.ToString();
                textBoxSystemBattery.Text = RelayedData.BatteryVoltage.ToString("0.00 V");
                textBoxSystemBatteryPercent.Text = RelayedData.FuelLevel.ToString("0.0 ") + "%";
                textBoxNavigationBatteryPercent.Text = RelayedData.FuelLevel.ToString("0.0 ") + "%";
                textBoxSystemMode.Text = RelayedData.ActualMode.ToString();
                textBoxNavigationMode.Text = RelayedData.ActualMode.ToString();

                // HopeRF
                textBoxHopeRXCount.Text = RelayedData.HopeRXFrameCount.ToString();
                textBoxHopeRXRSSI.Text = RelayedData.HopeRXRSSI.ToString();

                // Download map
                textBoxMapDownloadLat.Text = (RelayedData.Latitude * 1e-7).ToString("0.000000");
                textBoxMapDownloadLon.Text = (RelayedData.Longitude * 1e-7).ToString("0.000000");

                // Update current position
                navigation.UpdateCurrentPosition(RelayedData.Altitude, RelayedData.Longitude * 1e-7, RelayedData.Latitude * 1e-7, RelayedData.ActualMode);
                // Update Target Position
                if (navigation.llConv.IsHomeSet())
                {
                    float N, E;
                    navigation.llConv.ConvertLLToM(RelayedData.Latitude * 1e-7, RelayedData.Longitude * 1e-7, out N, out E);
                    gimbaledTracker.UpdateTargetPosition(RelayedData.Altitude, N, E);
                    textBoxGWTrackerTargetN.Text = string.Format("{0:0.00} m", N);
                    textBoxGWTrackerTargetE.Text = string.Format("{0:0.00} m", E);
                    textBoxGWTrackerTargetZ.Text = string.Format("{0:0.00} m", RelayedData.Altitude);
                }
            }
        }

        public unsafe void DisplayGatewayData(int receivedHopeRFCounter, int receivedPacketsCounter, SCommEthData GatewayData)
        {           
            // System
            textBoxGatewayPressure.Text = (GatewayData.Pressure / 100).ToString("0.00 hPa");
            textBoxGatewayTemperature.Text = (GatewayData.Temperature).ToString("0.0 °C");
            textBoxGatewayEthFrames.Text = receivedPacketsCounter.ToString();
            textBoxGatewayEthSent.Text = GatewayData.EthSentCount.ToString();
            textBoxGatewayEthReceived.Text = GatewayData.EthReceivedCount.ToString();
            textBoxGatewayLoop.Text = GatewayData.LoopCounter.ToString();
            textBoxGatewayLoopTime.Text = GatewayData.PerfLoopTimeMS.ToString("0.000 ms");
            textBoxGatewayCPUTime.Text = GatewayData.PerfCpuTimeMS.ToString("0.000 ms");
            textBoxGatewayCPUTimeMax.Text = GatewayData.PerfCpuTimeMSMAX.ToString("0.000 ms");
            textBoxGatewayBattery.Text = GatewayData.BatteryVoltage.ToString("0.00 V");

            textBoxGatewaySatNr.Text = GatewayData.NumSV.ToString();
            textBoxGatewayLat.Text = (GatewayData.Latitude * 1e-7).ToString("0.000000");
            textBoxGatewayLon.Text = (GatewayData.Longitude * 1e-7).ToString("0.000000");
            textBoxGatewayRoll.Text = GatewayData.Roll.ToString("0.0");
            textBoxGatewayPitch.Text = GatewayData.Pitch.ToString("0.0");
            textBoxGatewayYaw.Text = GatewayData.Yaw.ToString("0.0");

            // HopeRF
            textBoxGatewayHopeRXCount.Text = GatewayData.HopeRXFrameCount.ToString();
            textBoxGatewayHopeRSSI.Text = GatewayData.HopeRSSI.ToString();
            textBoxGatewayHopeRXRSSI.Text = GatewayData.HopeRXRSSI.ToString();

            // ESC Data
            textBoxGWESC1OpMode.Text = ((int)GatewayData.TuningData[0]).ToString();
            textBoxGWESC2OpMode.Text = ((int)GatewayData.TuningData[1]).ToString();
            textBoxGWESC1EncoLocked.Text = ((int)GatewayData.TuningData[2]).ToString();
            textBoxGWESC2EncoLocked.Text = ((int)GatewayData.TuningData[3]).ToString();
            textBoxGWESC1Position.Text = ((int)GatewayData.TuningData[4]).ToString();
            textBoxGWESC2Position.Text = ((int)GatewayData.TuningData[5]).ToString();
            textBoxGWESC1Current.Text = GatewayData.TuningData[6].ToString("0.0 A");
            textBoxGWESC2Current.Text = GatewayData.TuningData[7].ToString("0.0 A");
        }
        
        // Send data to Wifi/HopeRF
        public void SendData(byte type, byte[] buffer)
        {
            if( radioButtonWifi.Checked || radioButtonWifiHopeRF.Checked)
            {
                mainSystem.SendData(type, buffer);
            }
            if (radioButtonHopeRF.Checked || radioButtonWifiHopeRF.Checked)
            {
                gateway.SendDataOverRF(type, buffer);
            }
        }

        private void pictureBoxMap_Click(object sender, EventArgs e)
        {
            Point point = pictureBoxMap.PointToClient(Cursor.Position);
            navigation.OnMouseClick(point);            
        }

        private void buttonNavDownloadDelete_Click(object sender, EventArgs e)
        {
            navigation.DeleteWaypoint();
        }

        private void buttonNavDownloadWaypoints_Click(object sender, EventArgs e)
        {
            navigation.DownloadWaypoints();
        }

        private void buttonNavigationGoHome_Click(object sender, EventArgs e)
        {
            navigation.GoHome();
        }

        private void buttonNavExecuteWaypoints_Click(object sender, EventArgs e)
        {
            float Velocity;
            if (float.TryParse(comboBoxVelocity.Text, out Velocity) == false)
            {
                Velocity = 3; //default
            }

            navigation.ExecuteWaypoints(Velocity);
        }

        private void buttonNavAbortWaypoints_Click(object sender, EventArgs e)
        {
            navigation.AbortWaypoints();
        }

        private void buttonMapDownload_Click(object sender, EventArgs e)
        {
            try
            {                
                double latitude = double.Parse(textBoxMapDownloadLat.Text);
                double longitude = double.Parse(textBoxMapDownloadLon.Text);
                int zoom = int.Parse(comboBoxMapDownloadZoom.SelectedItem.ToString().Split(':')[0]);

                navigation.DownloadMap(latitude, longitude, zoom);

            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }        

        private void comboBoxMapSelector_SelectedIndexChanged(object sender, EventArgs e)
        {
            navigation.LoadMap(comboBoxMapSelector.SelectedItem.ToString());
        }      

        private void buttonNavigationWaypointsSave_Click(object sender, EventArgs e)
        {
            if (sender == buttonNavigationWaypointsLoad) navigation.LoadWaypoints();
            else navigation.SaveWaypoints();
        }

        private void comboBoxGWTrackerMode_SelectedIndexChanged(object sender, EventArgs e)
        {
            int trackingMode = comboBoxGWTrackerMode.SelectedIndex;
            int panRef = int.Parse(textBoxGWTrackerPanRef.Text);
            int tiltRef = int.Parse(textBoxGWTrackerTiltRef.Text);
            
            if( trackingMode == 0)
            {
                // disable all
                trackBarGWTrackerManualPanRef.Enabled = false;
                trackBarGWTrackerManualTiltRef.Enabled = false;
                textBoxGWTrackerTargetN.Enabled = false;
                textBoxGWTrackerTargetE.Enabled = false;
                textBoxGWTrackerTargetZ.Enabled = false;
                gateway.ChangeTrackerMode(trackingMode, panRef, tiltRef);
            }
            else if( trackingMode == 1)
            {
                // enable manual control
                trackBarGWTrackerManualPanRef.Enabled = true;
                trackBarGWTrackerManualTiltRef.Enabled = true;
                textBoxGWTrackerTargetN.Enabled = false;
                textBoxGWTrackerTargetE.Enabled = false;
                textBoxGWTrackerTargetZ.Enabled = false;
                gateway.ChangeTrackerMode(trackingMode, panRef, tiltRef);
            }
            else if( trackingMode == 2)
            {
                // semi auto
                trackBarGWTrackerManualPanRef.Enabled = false;
                trackBarGWTrackerManualTiltRef.Enabled = false;
                textBoxGWTrackerTargetN.Enabled = true;
                textBoxGWTrackerTargetE.Enabled = true;
                textBoxGWTrackerTargetZ.Enabled = true;
                // Tracker mode will be set/enabloed on ref send! Do not enable ESCs before position ref is initialized
            }
        }

        private void UpdateTracker()
        {
            // update Tracker
            int trackingMode = comboBoxGWTrackerMode.SelectedIndex;
            if (trackingMode == 2)
            {
                double roll = double.Parse(textBoxGatewayRoll.Text);
                double pitch = double.Parse(textBoxGatewayPitch.Text);
                double yaw = double.Parse(textBoxGatewayYaw.Text);

                TrackerAngles panTilt = gimbaledTracker.Update(roll, pitch, yaw);
                textBoxGWTrackerPanRef.Text = panTilt.PanCNT.ToString();
                textBoxGWTrackerTiltRef.Text = panTilt.TiltCNT.ToString();
                
                // do not send refs if BASE is not SET!
                if (gimbaledTracker.BaseSet != eBaseSetState.NONE)
                {
                    gateway.SendTrackerRef(panTilt.PanCNT, panTilt.TiltCNT);                
                }
            }

            textBoxGWTrackerBaseState.Text = gimbaledTracker.BaseSet.ToString();
            textBoxGWTrackerBaseRoll.Text = string.Format("{0:0.0} °", gimbaledTracker.BaseRoll);
            textBoxGWTrackerBasePitch.Text = string.Format("{0:0.0} °", gimbaledTracker.BasePitch);
            textBoxGWTrackerBaseYaw.Text = string.Format("{0:0.0} °", gimbaledTracker.BaseYaw);
        }

        private void buttonGWTrackerTargetTest_Click(object sender, EventArgs e)
        {
            float alt = float.Parse(textBoxGWTrackerTargetZ.Text);
            double N = float.Parse(textBoxGWTrackerTargetN.Text);
            double E = float.Parse(textBoxGWTrackerTargetE.Text);
            gimbaledTracker.UpdateTargetPosition(alt, N, E);           
        }

        private void buttonGWTrackerBaseSet_Click(object sender, EventArgs e)
        {
            comboBoxGWTrackerMode.SelectedIndex = 2;
            
            int startingPan = int.Parse(textBoxGWESC1Position.Text);
            int startingTilt = int.Parse(textBoxGWESC2Position.Text);

            gimbaledTracker.StartBaseSetProcedure(startingPan, startingTilt);            
        }   

        private void trackBarGWTrackerManualPanRef_Scroll(object sender, EventArgs e)
        {
            int panRef = trackBarGWTrackerManualPanRef.Value;
            int tiltRef = trackBarGWTrackerManualTiltRef.Value;
            textBoxGWTrackerPanRef.Text = panRef.ToString();
            textBoxGWTrackerTiltRef.Text = tiltRef.ToString();

            gateway.SendTrackerRef(panRef, tiltRef);
        }        
    }
}
