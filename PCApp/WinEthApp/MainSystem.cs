using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinEthApp
{
    class MainSystem
    {
        public FormMain formMain;

        // UDP Communication
        private const int TargetPort = 12000;
        private int LocalPort = 0; // autoselect port (will be sent in ping command)
        private string TargetAdress = "";
        private UdpClient udp = null;
        private int ReceivedPacketsCounter = 0;
        private int PingCounter = 0;

        // Assist now
        private AssistNow assistNow = new AssistNow();

        // Data
        SCommEthData MainSystemData;

        // Log File
        FileStream logStream = null;

        public MainSystem(FormMain form)
        {
            formMain = form;

            // parse data
            //ExtractLogFile(@"D:\RikiLogs\LogWifi-13-14-48.bin");
            //ExtractLogFile(@"C:\Users\Ivan\Desktop\DTW\Projects\Riki\PCApp\WinEthApp\bin\Debug\Log\LogWifi-9-2-43.bin");
            //ExtractLogFileRF(@"C:\Users\Ivan\Desktop\Riki-Gradiliste 29.5.2016\LogHopeRF-11-36-46.bin");

            // open log file
            string filename = string.Format("Log\\LogWifi-{0}-{1}-{2}.bin", DateTime.Now.Hour, DateTime.Now.Minute, DateTime.Now.Second);
            logStream = File.Create(filename);
        }

        public void Connect(string targetAddress)
        {
            TargetAdress = targetAddress;

            udp = new UdpClient(LocalPort);
            LocalPort = ((IPEndPoint)udp.Client.LocalEndPoint).Port;
        }

        ///////////////////////////////
        // DATA PARSER
        ///////////////////////////////
        public unsafe void Update()
        {
            if (udp == null) return;

            // Get data from UDP
            while (udp.Available > 0)
            {
                // get data
                IPEndPoint endP = new IPEndPoint(IPAddress.Any, 0); // any port of the sender
                byte[] bytes = udp.Receive(ref endP);

                // process data
                ReceivedPacketsCounter++;
                if (PacketIsValid(bytes))
                {
                    // remove header
                    byte[] withoutHeader = bytes.Skip(3).ToArray();
                    switch (bytes[2])
                    {
                        case 0x20:
                            // data                            
                            SCommEthData commData = (SCommEthData)Comm.FromBytes(withoutHeader, new SCommEthData());
                            MainSystemData = commData;
                            
                            // filter data
                            formMain.FilteredRoll = 0.9998 * formMain.FilteredRoll + 0.0002 * MainSystemData.dRoll;
                            formMain.FilteredPitch = 0.9998 * formMain.FilteredPitch + 0.0002 * MainSystemData.dPitch;
                            formMain.FilteredYaw = 0.9998 * formMain.FilteredYaw + 0.0002 * MainSystemData.dYaw;

                            for (int i = 0; i != 10; i++)
                            {
                                formMain.FilteredTuningData[i] = 0.999 * formMain.FilteredTuningData[i] + 0.001 * Math.Abs(commData.TuningData[i] - formMain.FilteredTuningLastData[i]);
                                formMain.FilteredTuningLastData[i] = commData.TuningData[i];
                            }

                            logStream.Write(withoutHeader, 0, withoutHeader.Length);
                            break;

                        case 0x62: // get params data
                            SCommParams p = (SCommParams)Comm.FromBytes(withoutHeader, new SCommParams());

                            // Display
                            formMain.DisplayParams(p);                            
                            break;
                    }
                }

            }

            // send PING
            if (++PingCounter > 20)
            {
                PingCounter = 0;
                byte[] lp = BitConverter.GetBytes(LocalPort); // send port
                SendData(0x10, lp);
            }

            // GUI update
            formMain.DisplaySystemData(ReceivedPacketsCounter, MainSystemData);

            // Update assist now
            byte[] toSend = assistNow.Update(MainSystemData.AssistNextChunkToSend);
            if (toSend != null) SendData(0x30, toSend);
        }
                
        
        ///////////////////////////////
        // COMMANDS
        ///////////////////////////////
        public void ExecuteAssistNow()
        {
            assistNow.Execute();
        }
        public void ReadParams()
        {
            // Send read request
            byte[] toSend = new byte[1];
            SendData(0x61, toSend);
        }

        public void WriteParams(SCommParams p)
        {
            // Send
            byte[] toSend = Comm.GetBytes(p);
            SendData(0x60, toSend);
        }
        public void WpnCommand(byte index, byte command)
        {
            uint code = 0x43782843;
            uint timer = 400; // ticks, 1 sec
            SCommLaunch launch = new SCommLaunch();
            launch.Command = command;
            launch.Index = index;
            if (command == 2) launch.CodeTimer = timer;
            else launch.CodeTimer = code;

            // Send
            byte[] toSend = Comm.GetBytes(launch);
            SendData(0x90, toSend);
        }

        ///////////////////////////////
        // HELPERS
        ///////////////////////////////
        private bool PacketIsValid(byte[] bytes)
        {
            bool valid = true;
            if (bytes[0] != 0x42) valid = false;
            if (bytes[1] != 0x24) valid = false;

            return valid;
        }

        public void SendData(byte type, byte[] buffer)
        {
            if (udp == null) return;

            byte[] data = new byte[buffer.Length + 3];
            // assemble
            data[0] = 0x42;
            data[1] = 0x24;
            data[2] = type; // Type
            Array.Copy(buffer, 0, data, 3, buffer.Length);
            udp.Send(data, data.Length, TargetAdress, TargetPort);
        }

        private unsafe void ExtractLogFile(string filename)
        {
            // open txt file
            StreamWriter sw = File.CreateText("matlab.txt");
            // create header
            sw.Write("Loop ");
            sw.Write("Voltage Battery ");
            sw.Write("MagX MagY MagZ ");
            sw.Write("AccX AccY AccZ ");
            sw.Write("Roll Pitch Yaw ");
            sw.Write("dRoll dPitch dYaw ");
            sw.Write("Pressure Temperature Altitude Vertspeed ");
            sw.Write("PWM1 PWM2 PWM3 PWM4 ");
            sw.Write("NumSV VelN VelE VelD HeightMSL HorizontalAccuracy ");
            sw.Write("Mode ");
            // GPS2 Data
            sw.Write("GPSTime2 NumSV2 FixType2 FixFlags2 Longitude2 Latitude2 HeightMSL2 HorizontalAccuracy2 VerticalAccuracy2 VelN2 VelE2 VelD2 SpeedAcc2 ");
            // HPPOSLLH
            sw.Write("GPSTimeHP LongitudeHP LatitudeHP HeightEllipsoidHP HeightMSLHP LongitudeHPP LatitudeHPP HeightEllipsoidHPP HeightMSLHPP HorizontalAccuracyHP VerticalAccuracyHP ");
            // RELPOSNED
            sw.Write("GPSTimeRelPos RelPosN RelPosE RelPosD RelPosHPN RelPosHPE RelPosHPD RelAccN RelAccE RelAccD ");
            sw.WriteLine("");

            SCommEthData data = new SCommEthData();
            logStream = File.OpenRead(filename);
            int size = Marshal.SizeOf(data);
            byte[] dataArray = new byte[size];
            while (logStream.Read(dataArray, 0, size) > 0)
            {
                data = (SCommEthData)Comm.FromBytes(dataArray, new SCommEthData());
                sw.Write("{0} ", data.LoopCounter);
                sw.Write("{0} {1} ", data.BatteryVoltage, data.FuelLevel);
                sw.Write("{0} {1} {2} ", data.MagX, data.MagY, data.MagZ);
                sw.Write("{0} {1} {2} ", data.AccX, data.AccY, data.AccZ);
                sw.Write("{0} {1} {2} ", data.Roll, data.Pitch, data.Yaw);
                sw.Write("{0} {1} {2} ", data.dRoll, data.dPitch, data.dYaw);
                sw.Write("{0} {1} {2} {3} ", data.Pressure, data.Temperature, data.Altitude, data.Vertspeed);
                sw.Write("{0} {1} {2} {3} ", data.MotorThrusts[0], data.MotorThrusts[1], data.MotorThrusts[2], data.MotorThrusts[3]);
                sw.Write("{0} {1} {2} {3} {4} {5} ", data.NumSV, data.VelN / 1000.0, data.VelE / 1000.0, data.VelD / 1000.0, data.HeightMSL / 1000.0, data.HorizontalAccuracy / 1000.0);
                sw.Write("{0} ", data.ActualMode);
                sw.Write("{0} {1} {2} {3} {4} {5} {6} {7} {8} {9} {10} {11} {12} ", data.GPSTime2, data.NumSV2, data.FixType2, data.FixFlags2, data.Longitude2, data.Latitude2, data.HeightMSL2, data.HorizontalAccuracy2, data.VerticalAccuracy2, data.VelN2, data.VelE2, data.VelD2, data.SpeedAcc2);
                sw.Write("{0} {1} {2} {3} {4} {5} {6} {7} {8} {9} {10} ", data.GPSTimeHP, data.LongitudeHP, data.LatitudeHP, data.HeightEllipsoidHP, data.HeightMSLHP, data.LongitudeHPP, data.LatitudeHPP, data.HeightEllipsoidHPP, data.HeightMSLHPP, data.HorizontalAccuracyHP, data.VerticalAccuracyHP);
                sw.Write("{0} {1} {2} {3} {4} {5} {6} {7} {8} {9} ", data.GPSTimeRelPos, data.RelPosN, data.RelPosE, data.RelPosD, data.RelPosHPN, data.RelPosHPE, data.RelPosHPD, data.RelAccN, data.RelAccE, data.RelAccD);
                sw.WriteLine("");
            }

            sw.Close();
        }

        private unsafe void ExtractLogFileRF(string filename)
        {
            // open txt file
            StreamWriter sw = File.CreateText("matlabRF.txt");
            // create header
            sw.Write("Loop ");
            sw.Write("Voltage Battery ");
            sw.Write("Roll Pitch Yaw ");
            sw.Write("Altitude Vertspeed ");
            sw.Write("NumSV VelN VelE ");
            sw.Write("NumSV VelN VelE ");        
            sw.WriteLine("HopeRXRSSI HopeTXTSSI ");

            SCommHopeRFData data = new SCommHopeRFData();
            logStream = File.OpenRead(filename);
            int size = Marshal.SizeOf(data);
            byte[] dataArray = new byte[size];
            while (logStream.Read(dataArray, 0, size) > 0)
            {
                data = (SCommHopeRFData)Comm.FromBytes(dataArray, new SCommHopeRFData());
                sw.Write("{0} ", data.LoopCounter);
                sw.Write("{0} {1} ", data.BatteryVoltage, data.FuelLevel);
                sw.Write("{0} {1} {2} ", data.Roll, data.Pitch, data.Yaw);
                sw.Write("{0} {1} ", data.Altitude, data.Vertspeed);
                sw.Write("{0} {1} {2} ", data.NumSV, data.VelN / 1000.0, data.VelE / 1000.0);
                sw.Write("{0} {1} ", data.HopeRXRSSI, data.HopeTXRSSI);
                sw.WriteLine("");
            }

            sw.Close();
        }
    }
}
