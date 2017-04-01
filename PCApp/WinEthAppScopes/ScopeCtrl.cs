using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VSConfigurator
{
    struct PointChunk
    {
        public double p1;
        public double p2;
        public double p3;
    };

    public partial class ScopeCtrl : UserControl
    {
        public int OnPaintCounter = 0;

        // Double buffering
        BufferedGraphicsContext DBcurrentContext;
        BufferedGraphics DBmyBuffer;
        Font fontLabels;
        Pen gridPen;

        // Params
        public double MinY = -1.0;
        public double MaxY = 1.5;
        public double SampleTime = 1/1000.0; // seconds

        // Data
        List<PointChunk> Points = new List<PointChunk>();

        bool EnabledCh1 = true;
        bool EnabledCh2 = true;
        bool EnabledCh3 = true;

        // Trigger
        enum ETrigTypes { ROLL, AUTO, NORMAL, ONCE };
        enum ELOGPhases { STOP, ARM, RUN, HOLDOFF };
        ELOGPhases LogPhase;
        ETrigTypes TrigType;
        int LOGHOLDOFFCNT = 1000;
        int TrigChannel = 1;
        bool TrigRise = true;    
        double TrigLevel = 0;
        double TrigLastVal = 1e10;
        int TrigHoldoff;

        public ScopeCtrl()
        {
            InitializeComponent();

            // Init
            fontLabels = new Font("Arial", 12, FontStyle.Regular);
            gridPen = new Pen(Color.White, 0.5f);
            gridPen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dot;

            // trigger
            TrigType = ETrigTypes.ROLL; // no trigger, rolling
            LogPhase = ELOGPhases.ARM;

            comboBoxScope1TriggerType.SelectedIndex = 0;
            comboBoxScope1TriggerChannel.SelectedIndex = 0;
        }

        public void PointsAdd(double point1, double point2, double point3)
        {            
            if( TrigType == ETrigTypes.ROLL) // no trigger
            {
                PointChunk pc = new PointChunk();
                pc.p1 = point1;
                pc.p2 = point2;
                pc.p3 = point3;
                Points.Add(pc);
                if (Points.Count > 1000) Points.RemoveAt(0);
            }
            else 
            {
	            // check trigger
                if( LogPhase == ELOGPhases.ARM )
	            {
                    if (TrigType == ETrigTypes.AUTO)
                    {
                        PointsClear();
                        LogPhase = ELOGPhases.RUN; // always trigger
                    }
                    else if (TrigType == ETrigTypes.NORMAL || TrigType == ETrigTypes.ONCE)
                    {
                        double trigCh = point1;
                        if (TrigChannel == 2) trigCh = point2;
                        else if (TrigChannel == 3) trigCh = point3;

                        if (TrigRise)
                        {
                            if (TrigLastVal < TrigLevel && trigCh > TrigLevel)
                            {
                                LogPhase = ELOGPhases.RUN;
                                PointsClear();
                            }
                        }
                        else
                        {
                            if (TrigLastVal > TrigLevel && trigCh < TrigLevel)
                            {
                                LogPhase = ELOGPhases.RUN;
                                PointsClear();
                            }
                        }
                        TrigLastVal = trigCh;
                    }
	            }

	            // sample in RUN mode
	            if( LogPhase == ELOGPhases.RUN )
	            {
		            PointChunk pc = new PointChunk();
                    pc.p1 = point1;
                    pc.p2 = point2;
                    pc.p3 = point3;
                    Points.Add(pc);
                    if (Points.Count > 1000)
                    {
		                // buffer full, go into holdoff
			            LogPhase = ELOGPhases.HOLDOFF; // acq done
			            TrigHoldoff = LOGHOLDOFFCNT; // reset holdoff counter [samples]
		            }
	            }

	            if( LogPhase == ELOGPhases.HOLDOFF)
	            {
		            if( TrigHoldoff > 0 ) TrigHoldoff--;
		            else
		            {                        
			            if( TrigType == ETrigTypes.ONCE ) LogPhase = ELOGPhases.STOP; // done!
			            else LogPhase = ELOGPhases.ARM; // rearm
		            }
	            }
            }
        }

        public void PointsClear()
        {
            Points.Clear();
        }

        public void Draw()
        {
            Graphics g = DBmyBuffer.Graphics;
            Size size = DisplayRectangle.Size;

            // clear backbuffer
            g.Clear(SystemColors.Control);
            g.FillRectangle(Brushes.Black, 0, 0, 1060, 350);

            g.DrawRectangle(Pens.White, 50, 20, 1000, 300);
            // draw range
            double rangeY = MaxY - MinY;
            double scaleY = 300 / rangeY; //multiply points with this!
            double stepY = rangeY / 10; // 10 grid lines
            double rangeX = SampleTime * 1000;
            double stepX = rangeX / 10; // 10 grid lines

            for (double cY = MinY; cY <= MaxY; cY += stepY)
            {
                if (Math.Abs(cY) < 1E-10) cY = 0;
                float y = (float)(320-(cY-MinY) * scaleY);
                g.DrawLine(gridPen, 50, y, 1050, y);
                StringFormat strF = new StringFormat();
                strF.Alignment = StringAlignment.Far;
                strF.LineAlignment = StringAlignment.Center;
                g.DrawString(string.Format("{0}", cY), fontLabels, Brushes.BlanchedAlmond, 50, (float)y, strF);
            }
            for(double cX = 0; cX <= rangeX; cX+= stepX)
            {
                float x = (float)(50 + cX/SampleTime);
                g.DrawLine(gridPen, x, 20, x, 320);
                StringFormat strF = new StringFormat();
                strF.Alignment = StringAlignment.Center;
                strF.LineAlignment = StringAlignment.Near;
                g.DrawString(string.Format("{0}", cX), fontLabels, Brushes.BlanchedAlmond, x, 330, strF);
            }
    
            // draw points
            for(int i=0; i < (Points.Count-1); i++)
            {
                float x = 50 + i; 
                float y1 = (float)(320 - (Points[i].p1 - MinY) * scaleY);
                float y1n = (float)(320 - (Points[i+1].p1 - MinY) * scaleY);
                float y2 = (float)(320 - (Points[i].p2 - MinY) * scaleY);
                float y2n = (float)(320 - (Points[i+1].p2 - MinY) * scaleY);
                float y3 = (float)(320 - (Points[i].p3 - MinY) * scaleY);
                float y3n = (float)(320 - (Points[i+1].p3 - MinY) * scaleY);
                if( EnabledCh1 ) g.DrawLine(Pens.Red, x, y1, x + 1, y1n);
                if (EnabledCh2 ) g.DrawLine(Pens.Green, x, y2, x + 1, y2n);
                if (EnabledCh3 ) g.DrawLine(Pens.DeepSkyBlue, x, y3, x + 1, y3n);
            }

            // render to screen            
            DBmyBuffer.Render();

            textBoxScope1TriggerPhase.Text = LogPhase.ToString();

        }

        private void SetTrigger(ETrigTypes trigType, int trigChannel, double level, bool trigRise)
        {
	        TrigType = trigType;
	        TrigChannel = trigChannel;
	        TrigLevel = level;
	        TrigRise = trigRise;
	        if( TrigRise ) TrigLastVal = 1e10; // avoid triggering on first sample!
	        else TrigLastVal = -1e10;
	        LogPhase = ELOGPhases.ARM; // arm logger

            PointsClear();
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            // Min Max
            double minY = double.Parse(textBoxScope1MinY.Text);
            double maxY = double.Parse(textBoxScope1MaxY.Text);
            MinY = minY;
            MaxY = maxY;

            // Set Trigger
            ScopeCtrl.ETrigTypes trgType = (ScopeCtrl.ETrigTypes)comboBoxScope1TriggerType.SelectedIndex;
            int trgChannel = comboBoxScope1TriggerChannel.SelectedIndex + 1;
            double trgLevel = double.Parse(textBoxScope1TriggerLevel.Text);
            bool trgRising = checkBoxScope1TriggerRIsingEdge.Checked;
            SetTrigger(trgType, trgChannel, trgLevel, trgRising);
        }

        private void buttonEnabledChanged_Click(object sender, EventArgs e)
        {
            // Enables
            EnabledCh1 = checkBoxScope1Ch1.Checked;
            EnabledCh2 = checkBoxScope1Ch2.Checked;
            EnabledCh3 = checkBoxScope1Ch3.Checked;
        }

        protected override void OnPaint(PaintEventArgs pe)
        {
            base.OnPaint(pe);

            if (DBcurrentContext == null)
            {
                // Create DB objects
                DBcurrentContext = BufferedGraphicsManager.Current;
                DBmyBuffer = DBcurrentContext.Allocate(this.CreateGraphics(), this.DisplayRectangle); // get actual size!
            }

            Draw();
            OnPaintCounter++; // draw counter
        }

        // reduce flicker
        protected override CreateParams CreateParams
        {
            get
            {
                CreateParams cp = base.CreateParams;
                cp.ExStyle |= 0x02000000;  // Turn on WS_EX_COMPOSITED
                return cp;
            }
        }

    }
}
