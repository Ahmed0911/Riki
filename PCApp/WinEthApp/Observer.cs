using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinEthApp
{
    class Observer
    {
        private FormMain formMain;
        private MainSystem mainSystem;

        public LLConverter llConv = new LLConverter();

        // Map
        Image mapBitmap;
        private double MetersPerPix;
        private double ZoomLevel;
        private double CenterLatitude;
        private double CenterLongitude;
        private double HomeLatitude;
        private double HomeLongitude;
        private bool HomeSet = false;
        private Size MapImageSizePix;
        private int CircleSize = 0;

        private Font fontWaypoints;
        private Font fontHome;

        // Current position
        SWaypoint CurrentPosition;

        // Target To Watch
        SWaypoint TargetPosition;

        // Observer/Drone Target Position
        SWaypoint TargetWaypoint;

        // Double buffering
        BufferedGraphicsContext DBcurrentContext;
        BufferedGraphics DBmyBuffer;

        public Observer(FormMain formMain, MainSystem mainSystem)
        {
            this.formMain = formMain;
            this.mainSystem = mainSystem;            

            // Create DB objects
            DBcurrentContext = BufferedGraphicsManager.Current;
            DBmyBuffer = DBcurrentContext.Allocate(formMain.pictureBoxMapObs.CreateGraphics(), formMain.pictureBoxMapObs.DisplayRectangle);
            fontWaypoints = new Font("Arial", 14, FontStyle.Regular);
            fontHome = new Font("Arial", 24, FontStyle.Regular);

            EnumerateMaps("Map");

            // TEST
            SetHome(15.88388, 45.80349); // REMOVE ME!!!
            UpdateCurrentPosition(21.4f, 15.88288, 45.80449, 2); // REMOVE ME!!!
        }

        private void EnumerateMaps(string mapFolder)
        {
            formMain.comboBoxNavSelector.Items.Clear();
            string[] maps = Directory.EnumerateFiles(mapFolder, "*-X.jpg").ToArray();
            formMain.comboBoxNavSelector.Items.AddRange(maps);
        }

        public void LoadMap(string mapFilname)
        {
            mapBitmap = Bitmap.FromFile(mapFilname);            

            // get data
            string[] toks = mapFilname.Split('-');
            CenterLatitude = double.Parse(toks[1]);
            CenterLongitude = double.Parse(toks[2]);
            ZoomLevel = double.Parse(toks[3]);           

            MapImageSizePix = mapBitmap.Size;
            MetersPerPix = 156543.04 * Math.Cos(CenterLatitude / 180 * Math.PI) / (Math.Pow(2, ZoomLevel));
        }

        public void Update()
        {
            DrawMap();

            // check colors and states
            int numOfSats = int.Parse(formMain.textBoxObsLocSatNr.Text);
            if (numOfSats < 5) formMain.textBoxObsLocSatNr.BackColor = Color.Red;
            else if(numOfSats < 10) formMain.textBoxObsLocSatNr.BackColor = Color.Yellow;
            else formMain.textBoxObsLocSatNr.BackColor = Color.Lime;

            // check colors and states
            int mode = int.Parse(formMain.textBoxObsMode.Text);
            if (mode < 3) formMain.textBoxObsMode.BackColor = SystemColors.Control;
            else if (mode < 5 ) formMain.textBoxObsMode.BackColor = Color.Yellow;
            else formMain.textBoxObsMode.BackColor = Color.Lime;
        }

        public void DrawMap()
        {
            // clear backbuffer
            DBmyBuffer.Graphics.Clear(Color.Black);

            if (mapBitmap == null) return;

            // draw map
            DBmyBuffer.Graphics.DrawImageUnscaled(mapBitmap, formMain.pictureBoxMapObs.DisplayRectangle);

	        // draw location
	        float mapX, mapY;
	        ConvertLocationLL2Pix(CurrentPosition.Longitude, CurrentPosition.Latitude, out mapX, out mapY);
	        // clip to map!
	        if (mapX < 0) mapX = 0;
	        if (mapY < 0) mapY = 0;
            if (mapX > MapImageSizePix.Width) mapX = (float)MapImageSizePix.Width;
            if (mapY > MapImageSizePix.Height) mapY = (float)MapImageSizePix.Height;
            DBmyBuffer.Graphics.FillEllipse(new SolidBrush(Color.White), mapX-5, mapY-5, 10, 10);
            DBmyBuffer.Graphics.DrawEllipse(new Pen(Color.Red, 3), mapX-5-CircleSize/2, mapY-5 - CircleSize/2, 10 + CircleSize, 10 + CircleSize );
	        if (++CircleSize > 30) CircleSize = 0;
            StringFormat strF = new StringFormat();
            strF.Alignment = StringAlignment.Center;
            DBmyBuffer.Graphics.DrawString(string.Format("{0:0.0}", CurrentPosition.Altitude), fontWaypoints, Brushes.BlanchedAlmond, mapX - 1, mapY + 20, strF);

	        // draw home
	        if (HomeSet)
	        {
		        ConvertLocationLL2Pix(HomeLongitude, HomeLatitude, out mapX, out mapY);
                DBmyBuffer.Graphics.DrawEllipse(new Pen(Color.White, 3), mapX - 16, mapY - 16, 32, 32);
                DBmyBuffer.Graphics.DrawString("H", fontHome, Brushes.White, mapX-16, mapY - 17 );		        
	        }
           
            // Draw Target to Observe
            if(TargetPosition.Latitude != 0)
            {
                ConvertLocationLL2Pix(TargetPosition.Longitude, TargetPosition.Latitude, out mapX, out mapY);
                //DBmyBuffer.Graphics.DrawEllipse(new Pen(Color.White, 3), mapX - 16, mapY - 16, 32, 32);
                DBmyBuffer.Graphics.DrawRectangle(new Pen(Color.OrangeRed, 3), mapX - 16, mapY - 16, 32, 32);
                DBmyBuffer.Graphics.DrawLine(new Pen(Color.OrangeRed, 2), mapX - 16, mapY - 16, mapX + 16, mapY + 16);
                DBmyBuffer.Graphics.DrawLine(new Pen(Color.OrangeRed, 2), mapX + 16, mapY - 16, mapX - 16, mapY + 16);

                // Draw Drone Observation Circle
                float DistanceM = 50; // TODO: Calculate this crap
                float areaSize = DistanceM / (float)MetersPerPix;
                DBmyBuffer.Graphics.DrawEllipse(new Pen(Color.Yellow, 2), mapX - areaSize, mapY - areaSize, areaSize * 2, areaSize * 2);
            }
            
            // immediate mode
            if (TargetWaypoint.Latitude != 0)
		    {
			    ConvertLocationLL2Pix(TargetWaypoint.Longitude, TargetWaypoint.Latitude, out mapX, out mapY);
                DBmyBuffer.Graphics.DrawEllipse(new Pen(Color.White, 3), mapX-16, mapY-16, 32, 32 );
                DBmyBuffer.Graphics.DrawLine(new Pen(Color.White, 1), mapX - 20, mapY - 20, mapX + 20, mapY + 20);
                DBmyBuffer.Graphics.DrawLine(new Pen(Color.White, 1), mapX + 20, mapY - 20, mapX - 20, mapY + 20);

                StringFormat stringFormat = new StringFormat();
                stringFormat.Alignment = StringAlignment.Center;
                DBmyBuffer.Graphics.DrawString(string.Format("{0}", TargetWaypoint.Altitude), fontWaypoints, Brushes.White, mapX - 1, mapY + 20, stringFormat);
            }
	   
            // render to screen            
            DBmyBuffer.Render();
        }    

        public void GoHome()
        {
            float Altitude;
            if (float.TryParse(formMain.comboBoxObsAltitude.Text, out Altitude) == false)
            {
                Altitude = 10; //default
            }

            TargetWaypoint.Altitude = Altitude;
            TargetWaypoint.Latitude = HomeLatitude;
            TargetWaypoint.Longitude = HomeLongitude;
            // send target
            Goto(TargetWaypoint);        
        }

        public void SetTarget()
        {
            // Set target Location (target for observation)
            TargetPosition = CurrentPosition;
            TargetPosition.Altitude = 0; // set altitude to zero!

            formMain.textBoxObsTargetLat.Text = TargetPosition.Latitude.ToString("0.000000");
            formMain.textBoxObsTargetLong.Text = TargetPosition.Longitude.ToString("0.000000");
        }

        private void Goto(SWaypoint targetWaypoint)
        {
            SCommGotoExecute gotoExecuteCmd = new SCommGotoExecute();
            gotoExecuteCmd.Command = 0x01; // execute GOTO
            gotoExecuteCmd.TargetWaypoint.Altitude = targetWaypoint.Altitude;
            gotoExecuteCmd.TargetWaypoint.Longitude = (int)(targetWaypoint.Longitude * 1e7);
            gotoExecuteCmd.TargetWaypoint.Latitude = (int)(targetWaypoint.Latitude * 1e7);

            // Send
            byte[] toSend = Comm.GetBytes(gotoExecuteCmd);
            formMain.SendData(0x80, toSend);
        }

        public void UpdateCurrentPosition(float altitude, double longitude, double latitude, int actualMode)
        {
            CurrentPosition.Altitude = altitude;
            CurrentPosition.Longitude = longitude;
            CurrentPosition.Latitude = latitude;
        }

        // Helpers
        public void ConvertLocationLL2Pix(double longitude, double latitude, out float mapX, out float mapY)
        {
	        double deltaX = longitude - CenterLongitude;
	        double pixelX = (deltaX / 360) * 256 * Math.Pow(2, ZoomLevel);
	        mapX = (float)(pixelX + MapImageSizePix.Width/2);

	        double sinLatitudeCenter = Math.Sin(CenterLatitude * Math.PI / 180);
	        double pixelYCenter = (0.5 - Math.Log((1 + sinLatitudeCenter) / (1 - sinLatitudeCenter)) / (4 * Math.PI)) * 256 * Math.Pow(2, ZoomLevel); // center pix
	        double sinLatitude = Math.Sin(latitude * Math.PI / 180);
	        double pixelY = (0.5 - Math.Log((1 + sinLatitude) / (1 - sinLatitude)) / (4 * Math.PI)) * 256 * Math.Pow(2, ZoomLevel);
	        mapY = (float)(pixelY - pixelYCenter + MapImageSizePix.Height/2);
        }

        public void ConvertLocationPix2LL(out double longitude, out double latitude, float mapX, float mapY)
        {
	        double pixelX = mapX - MapImageSizePix.Width / 2;
	        double deltaX = pixelX * 360 / (256 * Math.Pow(2, ZoomLevel));
	        longitude = deltaX + CenterLongitude;

	        double sinLatitudeCenter = Math.Sin(CenterLatitude * Math.PI / 180);
	        double pixelYCenter = (0.5 - Math.Log((1 + sinLatitudeCenter) / (1 - sinLatitudeCenter)) / (4 * Math.PI)) * 256 * Math.Pow(2, ZoomLevel); // center pix
	        double pixelY = mapY + pixelYCenter - MapImageSizePix.Height / 2;
	        double deltaY = 0.5 - pixelY / (256 * Math.Pow(2, ZoomLevel));
	        latitude = 90 - 360 * Math.Atan(Math.Exp(-deltaY * 2 * Math.PI)) / Math.PI;
        }

        public void SetHome(double longitude, double latitude)
        {
	        HomeLongitude = longitude;
	        HomeLatitude = latitude;
	        HomeSet = true;

            llConv.SetHome(HomeLatitude, HomeLongitude);
        }

        public bool HaveHome()
        {
	        return HomeSet;
        }

        private double DistanceFromHomeMeters(double longitude, double latitude)
        {
	        double distance = 0; // no home set
	        if (HomeSet)
	        {
		        distance = LLDistanceM(longitude, latitude, HomeLongitude, HomeLatitude);
	        }
	
	        return distance;
        }

        private double LLDistanceM(double longitude1, double latitude1, double longitude2, double latitude2)
        {
	        double R = 6371000; // [m]
            double dLat = (latitude2 - latitude1) * Math.PI / 180;
            double dLon = (longitude2 - longitude1) * Math.PI / 180;
            double lat1 = latitude1 * Math.PI / 180;
            double lat2 = latitude2 * Math.PI / 180;

            double a = Math.Sin(dLat / 2) * Math.Sin(dLat / 2) + Math.Sin(dLon / 2) * Math.Sin(dLon / 2) * Math.Cos(lat1) * Math.Cos(lat2);
            double c = 2 * Math.Atan2(Math.Sqrt(a), Math.Sqrt(1 - a));
	        double distance = R * c;

	        return distance;
        }
    }
}
