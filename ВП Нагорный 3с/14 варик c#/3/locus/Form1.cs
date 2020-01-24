using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;


namespace locus
{

    public partial class Form1 : Form
    {
        public static double f(double x)
        {
            return x * x * x * x * x - 3 * x * x + 2;
        }
        public Form1()
        {
            InitializeComponent();
        }
        Series series;
        Series series2;
        Series seriesX;
        Series seriesY;
        bool flag = false;
        double t_ = -5, a_ = 5, b_ = 7, k1_ = 1, k2_ = 2, b1_ = 3, b2_ = 15;
        double[] X = new double[50];
        double[] Y = new double[50];
        double[] X2 = new double[2];
        double[] Y2 = new double[2];

        private void k2_track_Scroll(object sender, EventArgs e)
        {
            k2_ = k2_track.Value;
            count();
        }

        private void b1_track_Scroll(object sender, EventArgs e)
        {
            b1_ = b1_track.Value;
            count();
        }

        private void b2_track_Scroll(object sender, EventArgs e)
        {
            b2_ = b2_track.Value;
            count();
        }

        //private void from_TextChanged(object sender, EventArgs e)
        //{
        //    if (System.Text.RegularExpressions.Regex.IsMatch(from.Text, "[^0-9]+|-"))
        //    {
        //        MessageBox.Show("Please enter only numbers.");
        //        from.Text = from.Text.Remove(from.Text.Length - 1);
        //    }
        //}

        private void redraw_Click(object sender, EventArgs e)
        {
            count();
        }

        private void count()
        {
            X2[0] = double.Parse(from.Text);
            X2[1] = double.Parse(to.Text);
            for (var i = 0; i < X2.Length; i++)
            {
                Y2[i] = 0;
            }
            seriesX.Points.DataBindXY(X2, Y2);

            Y2[0] = double.Parse(from1.Text);
            Y2[1] = double.Parse(to1.Text);
            for (var i = 0; i < X2.Length; i++)
            {
                X2[i] = 0;
            }
            seriesY.Points.DataBindXY(X2, Y2);
            chart1.Series[1] = seriesX;
            chart1.Series[2] = seriesY;
            //---------------------------
            var x = double.Parse(from.Text);
            var end = double.Parse(to.Text);
            double dx = (double.Parse(to.Text) - double.Parse(from.Text))/100;
            series.Points.Clear();
            while (true)
            {
                series.Points.AddXY(x,f(x));
                x += dx;
                if (x > end) break;
            }
            //----------------------
            series2.Points.Clear();
            for (int i = 0; i < 63; i++)
            {
                series2.Points.AddXY(a_ * Math.Sin(k1_ * t_ + b1_),b_ * Math.Sin(k2_ * t_ + b2_));
                t_ += 0.1;
            }
            chart1.ChartAreas[0].AxisX.Minimum = double.Parse(from.Text);
            chart1.ChartAreas[0].AxisX.Maximum = double.Parse(to.Text);
            chart1.ChartAreas[0].AxisY.Minimum = double.Parse(from1.Text);
            chart1.ChartAreas[0].AxisY.Maximum = double.Parse(to1.Text);
            //chart1.ChartAreas[0].AxisY.ArrowStyle = AxisArrowStyle.Triangle; //SharpTriangle
            //chart1.ChartAreas[0].AxisY.Crossing = 0;
            //chart1.ChartAreas[0].AxisX.ArrowStyle = AxisArrowStyle.Triangle; //SharpTriangle
            //chart1.ChartAreas[0].AxisX.Crossing = 0;
            chart1.Series[3].Points.Clear();
            //chart1.Series[3].Points.AddXY(double.Parse(to.Text),0);
            chart1.Series[4].Points.Clear();
            //chart1.Series[4].Points.AddXY((double.Parse(to.Text)- double.Parse(from.Text))/30, double.Parse(to1.Text));
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            series = new Series("Graph");
            series2 = new Series("Graph");
            seriesX = new Series("Graph1");
            seriesY = new Series("Graph2");
            series.ChartType = SeriesChartType.Line;
            series2.ChartType = SeriesChartType.Line;
            seriesX.ChartType = SeriesChartType.Line;
            seriesY.ChartType = SeriesChartType.Line;
            seriesX.BorderWidth = 3;
            seriesY.BorderWidth = 3;
            seriesX.Color = Color.FromArgb(0, 0, 0);
            seriesY.Color = Color.FromArgb(0, 0, 0);
            chart1.Legends.Clear();
            //graphName.Text = "x = a*sin(k1*fi + b1) \ny = b*sin(k2*fi + b2)";
            count();
            chart1_Click(this);
        }
        private void k1_track_Scroll(object sender, EventArgs e)
        {
            k1_ = k1_track.Value;
            count();
        }

        private void chart1_Click(object sender, EventArgs e = null)
        {
            a_track.Visible = flag;
            b_track.Visible = flag;
            b1_track.Visible = flag;
            b2_track.Visible = flag;
            k1_track.Visible = flag;
            k2_track.Visible = flag;
            a.Visible = flag;
            b.Visible = flag;
            b1.Visible = flag;
            b2.Visible = flag;
            k1.Visible = flag;
            k2.Visible = flag;
            if (flag) {
                graphName.Text = "x = a*sin(k1*fi + b1) \ny = b*sin(k2*fi + b2)";
                chart1.Series[0] = series2;
                flag = false;
            }
            else
            {
                graphName.Text = "y = x^5 - 3x^2 + 2";
                chart1.Series[0] = series;
                flag = true;
            }
        }

        private void b_track_Scroll(object sender, EventArgs e)
        {
            b_ = b_track.Value;
            count();
        }

        private void a_track_Scroll(object sender, EventArgs e)
        {
            a_ = a_track.Value;
            count();
        }
    }
}
