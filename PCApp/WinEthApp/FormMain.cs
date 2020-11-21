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
        Observer observer;

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
            navigation = new Navigation(this, mainSystem);
            observer = new Observer(this, mainSystem);
            comboBoxMapSelector.SelectedIndex = comboBoxMapSelector.Items.Count - 1; // Load default map            
            comboBoxNavSelector.SelectedIndex = comboBoxNavSelector.Items.Count - 1; // Load default map    

            comboBoxObsAltitude.SelectedIndex = 2;
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
        }

        private void buttonConnectSystem_Click(object sender, EventArgs e)
        {
            mainSystem.Connect(textBoxAddressSystem.Text);
            buttonConnectSystem.Enabled = false;
            buttonConnectSystem.Text = "Opened";
        }

        private void timerCommUpdate_Tick(object sender, EventArgs e)
        {
            mainSystem.Update();
            navigation.Update();
            observer.Update();

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

        public unsafe void DisplaySystemData(int ReceivedPacketsCounter, SCommEthData MainSystemData)
        {
            // GPS
            textBoxLocTime.Text = MainSystemData.GPSTime.ToString();
            textBoxLocSatNr.Text = MainSystemData.NumSV.ToString();
            textBoxNavLocSatNr.Text = MainSystemData.NumSV.ToString();
            textBoxObsLocSatNr.Text = MainSystemData.NumSV.ToString();
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

            // GPS2
            textBoxLocTime2.Text = MainSystemData.GPSTime2.ToString();
            textBoxLocSatNr2.Text = MainSystemData.NumSV2.ToString();
            textBoxLocLat2.Text = (MainSystemData.LatitudeHP * 1e-7 + MainSystemData.LatitudeHPP * 1e-9).ToString("0.000000000");
            textBoxLocLon2.Text = (MainSystemData.LongitudeHP * 1e-7 + MainSystemData.LongitudeHPP * 1e-9).ToString("0.000000000");

            textBoxRelaN.Text = (MainSystemData.RelPosN + MainSystemData.RelPosHPN / 100.0).ToString("0.00 cm");
            textBoxRelaE.Text = (MainSystemData.RelPosE + MainSystemData.RelPosHPE / 100.0).ToString("0.00 cm");
            textBoxRelaD.Text = (MainSystemData.RelPosD + MainSystemData.RelPosHPD / 100.0).ToString("0.00 cm");

            textBoxLocVelocityN2.Text = (MainSystemData.VelN2 / 1000.0).ToString("0.00 m/s");
            textBoxLocVelocityE2.Text = (MainSystemData.VelE2 / 1000.0).ToString("0.00 m/s");
            textBoxLocVelocityD2.Text = (MainSystemData.VelD2 / 1000.0).ToString("0.00 m/s");

            textBoxLocRelAccN.Text = (MainSystemData.RelAccN / 10.0).ToString("0.0 mm");
            textBoxLocRelAccE.Text = (MainSystemData.RelAccE / 10.0).ToString("0.0 mm");
            textBoxLocRelAccD.Text = (MainSystemData.RelAccD / 10.0).ToString("0.0 mm");

            textBoxLocHeight2.Text = ((MainSystemData.HeightEllipsoidHP + MainSystemData.HeightEllipsoidHPP/10.0)/1000.0).ToString("0.000 m");
            //textBoxLocHeight2.Text = ((MainSystemData.HeightEllipsoidHPP / 10.0)).ToString("0.00 mm");


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
            textBoxdYawFiltered.Text = FilteredYaw.ToString("0.000 °" +
                "/s");

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
            textBoxObsBatteryPercent.Text = MainSystemData.FuelLevel.ToString("0.0 ") + "%";
            textBoxSystemMode.Text = MainSystemData.ActualMode.ToString();
            textBoxNavigationMode.Text = MainSystemData.ActualMode.ToString();
            textBoxObsMode.Text = MainSystemData.ActualMode.ToString();
            textBoxSystemT1.Text = MainSystemData.MotorThrusts[0].ToString();
            textBoxSystemT2.Text = MainSystemData.MotorThrusts[1].ToString();
            textBoxSystemT3.Text = MainSystemData.MotorThrusts[2].ToString();
            textBoxSystemT4.Text = MainSystemData.MotorThrusts[3].ToString();

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
            observer.SetHome(MainSystemData.HomeLongitude * 1e-7, MainSystemData.HomeLatitude * 1e-7);
            // Update current position
            navigation.UpdateCurrentPosition(MainSystemData.Altitude, MainSystemData.Longitude * 1e-7, MainSystemData.Latitude * 1e-7, MainSystemData.ActualMode);
            observer.UpdateCurrentPosition(MainSystemData.Altitude, MainSystemData.Longitude * 1e-7, MainSystemData.Latitude * 1e-7, MainSystemData.ActualMode, MainSystemData.Yaw, MainSystemData.MotorThrusts[0] > 30);

            // Update Target Position
            if ( navigation.llConv.IsHomeSet() )
            {
                float N, E;
                navigation.llConv.ConvertLLToM(MainSystemData.Latitude * 1e-7, MainSystemData.Longitude * 1e-7, out N, out E);
                observer.llConv.ConvertLLToM(MainSystemData.Latitude * 1e-7, MainSystemData.Longitude * 1e-7, out N, out E);
            }            
        }
        
        // Send data to Wifi/HopeRF
        public void SendData(byte type, byte[] buffer)
        {
            mainSystem.SendData(type, buffer);
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

        private void comboBoxNavSelector_SelectedIndexChanged(object sender, EventArgs e)
        {
            observer.LoadMap(comboBoxNavSelector.SelectedItem.ToString());
        }

        // Observer Class
        private void buttonObsGoHome_Click(object sender, EventArgs e)
        {
            observer.GoHome();
        }

        private void buttonObsSetTarget_Click(object sender, EventArgs e)
        {
            observer.SetTarget();
        }

        private void buttonObserverExecute_Click(object sender, EventArgs e)
        {
            observer.Execute();
        }
    }
}
