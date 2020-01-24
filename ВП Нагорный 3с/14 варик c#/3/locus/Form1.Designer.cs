namespace locus
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series4 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.DataPoint dataPoint1 = new System.Windows.Forms.DataVisualization.Charting.DataPoint(30D, 0D);
            System.Windows.Forms.DataVisualization.Charting.Series series5 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.backgroundWorker2 = new System.ComponentModel.BackgroundWorker();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.label1 = new System.Windows.Forms.Label();
            this.a_track = new System.Windows.Forms.TrackBar();
            this.b_track = new System.Windows.Forms.TrackBar();
            this.k1_track = new System.Windows.Forms.TrackBar();
            this.k2_track = new System.Windows.Forms.TrackBar();
            this.b1_track = new System.Windows.Forms.TrackBar();
            this.b2_track = new System.Windows.Forms.TrackBar();
            this.a = new System.Windows.Forms.Label();
            this.k1 = new System.Windows.Forms.Label();
            this.b = new System.Windows.Forms.Label();
            this.k2 = new System.Windows.Forms.Label();
            this.b1 = new System.Windows.Forms.Label();
            this.b2 = new System.Windows.Forms.Label();
            this.graphName = new System.Windows.Forms.Label();
            this.from = new System.Windows.Forms.MaskedTextBox();
            this.from1 = new System.Windows.Forms.MaskedTextBox();
            this.to = new System.Windows.Forms.MaskedTextBox();
            this.to1 = new System.Windows.Forms.MaskedTextBox();
            this.redraw = new System.Windows.Forms.Button();
            this.label10 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.a_track)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.b_track)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.k1_track)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.k2_track)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.b1_track)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.b2_track)).BeginInit();
            this.SuspendLayout();
            // 
            // chart1
            // 
            chartArea1.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chart1.Legends.Add(legend1);
            this.chart1.Location = new System.Drawing.Point(71, 69);
            this.chart1.Name = "chart1";
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.IsVisibleInLegend = false;
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            series2.ChartArea = "ChartArea1";
            series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series2.Legend = "Legend1";
            series2.Name = "Series2";
            series3.ChartArea = "ChartArea1";
            series3.Legend = "Legend1";
            series3.Name = "Series3";
            series4.ChartArea = "ChartArea1";
            series4.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Point;
            series4.Label = "X";
            series4.Legend = "Legend1";
            series4.MarkerSize = 0;
            series4.Name = "Series4";
            series4.Points.Add(dataPoint1);
            series5.ChartArea = "ChartArea1";
            series5.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Point;
            series5.IsVisibleInLegend = false;
            series5.Label = "Y";
            series5.Legend = "Legend1";
            series5.MarkerSize = 0;
            series5.Name = "Series5";
            series5.SmartLabelStyle.CalloutLineColor = System.Drawing.Color.PeachPuff;
            series5.SmartLabelStyle.Enabled = false;
            this.chart1.Series.Add(series1);
            this.chart1.Series.Add(series2);
            this.chart1.Series.Add(series3);
            this.chart1.Series.Add(series4);
            this.chart1.Series.Add(series5);
            this.chart1.Size = new System.Drawing.Size(300, 300);
            this.chart1.TabIndex = 0;
            this.chart1.Text = "chart1";
            this.chart1.Click += new System.EventHandler(this.chart1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(133, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(120, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Click to change a graph";
            // 
            // a_track
            // 
            this.a_track.Location = new System.Drawing.Point(418, 69);
            this.a_track.Name = "a_track";
            this.a_track.Size = new System.Drawing.Size(104, 45);
            this.a_track.TabIndex = 9;
            this.a_track.Scroll += new System.EventHandler(this.a_track_Scroll);
            // 
            // b_track
            // 
            this.b_track.Location = new System.Drawing.Point(418, 120);
            this.b_track.Name = "b_track";
            this.b_track.Size = new System.Drawing.Size(104, 45);
            this.b_track.TabIndex = 10;
            this.b_track.Scroll += new System.EventHandler(this.b_track_Scroll);
            // 
            // k1_track
            // 
            this.k1_track.Location = new System.Drawing.Point(418, 171);
            this.k1_track.Name = "k1_track";
            this.k1_track.Size = new System.Drawing.Size(104, 45);
            this.k1_track.TabIndex = 11;
            this.k1_track.Scroll += new System.EventHandler(this.k1_track_Scroll);
            // 
            // k2_track
            // 
            this.k2_track.Location = new System.Drawing.Point(418, 222);
            this.k2_track.Name = "k2_track";
            this.k2_track.Size = new System.Drawing.Size(104, 45);
            this.k2_track.TabIndex = 12;
            this.k2_track.Scroll += new System.EventHandler(this.k2_track_Scroll);
            // 
            // b1_track
            // 
            this.b1_track.Location = new System.Drawing.Point(418, 273);
            this.b1_track.Name = "b1_track";
            this.b1_track.Size = new System.Drawing.Size(104, 45);
            this.b1_track.TabIndex = 13;
            this.b1_track.Scroll += new System.EventHandler(this.b1_track_Scroll);
            // 
            // b2_track
            // 
            this.b2_track.Location = new System.Drawing.Point(418, 320);
            this.b2_track.Name = "b2_track";
            this.b2_track.Size = new System.Drawing.Size(104, 45);
            this.b2_track.TabIndex = 14;
            this.b2_track.Scroll += new System.EventHandler(this.b2_track_Scroll);
            // 
            // a
            // 
            this.a.AutoSize = true;
            this.a.Location = new System.Drawing.Point(399, 69);
            this.a.Name = "a";
            this.a.Size = new System.Drawing.Size(13, 13);
            this.a.TabIndex = 15;
            this.a.Text = "a";
            // 
            // k1
            // 
            this.k1.AutoSize = true;
            this.k1.Location = new System.Drawing.Point(399, 171);
            this.k1.Name = "k1";
            this.k1.Size = new System.Drawing.Size(19, 13);
            this.k1.TabIndex = 16;
            this.k1.Text = "k1";
            // 
            // b
            // 
            this.b.AutoSize = true;
            this.b.Location = new System.Drawing.Point(399, 120);
            this.b.Name = "b";
            this.b.Size = new System.Drawing.Size(13, 13);
            this.b.TabIndex = 17;
            this.b.Text = "b";
            // 
            // k2
            // 
            this.k2.AutoSize = true;
            this.k2.Location = new System.Drawing.Point(399, 222);
            this.k2.Name = "k2";
            this.k2.Size = new System.Drawing.Size(19, 13);
            this.k2.TabIndex = 18;
            this.k2.Text = "k2";
            // 
            // b1
            // 
            this.b1.AutoSize = true;
            this.b1.Location = new System.Drawing.Point(399, 273);
            this.b1.Name = "b1";
            this.b1.Size = new System.Drawing.Size(19, 13);
            this.b1.TabIndex = 19;
            this.b1.Text = "b1";
            // 
            // b2
            // 
            this.b2.AutoSize = true;
            this.b2.Location = new System.Drawing.Point(399, 321);
            this.b2.Name = "b2";
            this.b2.Size = new System.Drawing.Size(19, 13);
            this.b2.TabIndex = 20;
            this.b2.Text = "b2";
            // 
            // graphName
            // 
            this.graphName.AutoSize = true;
            this.graphName.Location = new System.Drawing.Point(150, 395);
            this.graphName.Name = "graphName";
            this.graphName.Size = new System.Drawing.Size(60, 13);
            this.graphName.TabIndex = 21;
            this.graphName.Text = "Description";
            // 
            // from
            // 
            this.from.Location = new System.Drawing.Point(300, 384);
            this.from.Mask = "-000";
            this.from.Name = "from";
            this.from.Size = new System.Drawing.Size(31, 20);
            this.from.TabIndex = 26;
            this.from.Text = "10";
            // 
            // from1
            // 
            this.from1.Location = new System.Drawing.Point(298, 414);
            this.from1.Mask = "-000";
            this.from1.Name = "from1";
            this.from1.Size = new System.Drawing.Size(33, 20);
            this.from1.TabIndex = 27;
            this.from1.Text = "10";
            // 
            // to
            // 
            this.to.Location = new System.Drawing.Point(357, 384);
            this.to.Mask = "000";
            this.to.Name = "to";
            this.to.Size = new System.Drawing.Size(33, 20);
            this.to.TabIndex = 28;
            this.to.Text = "60";
            // 
            // to1
            // 
            this.to1.Location = new System.Drawing.Point(357, 414);
            this.to1.Mask = "000";
            this.to1.Name = "to1";
            this.to1.Size = new System.Drawing.Size(33, 20);
            this.to1.TabIndex = 29;
            this.to1.Text = "60";
            // 
            // redraw
            // 
            this.redraw.Location = new System.Drawing.Point(418, 395);
            this.redraw.Name = "redraw";
            this.redraw.Size = new System.Drawing.Size(69, 23);
            this.redraw.TabIndex = 30;
            this.redraw.Text = "Redraw";
            this.redraw.UseVisualStyleBackColor = true;
            this.redraw.Click += new System.EventHandler(this.redraw_Click);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(259, 387);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(40, 13);
            this.label10.TabIndex = 31;
            this.label10.Text = "X: from";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(257, 416);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(40, 13);
            this.label2.TabIndex = 32;
            this.label2.Text = "Y: from";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(338, 388);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(16, 13);
            this.label3.TabIndex = 33;
            this.label3.Text = "to";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(337, 417);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(16, 13);
            this.label4.TabIndex = 34;
            this.label4.Text = "to";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(560, 450);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.redraw);
            this.Controls.Add(this.to1);
            this.Controls.Add(this.to);
            this.Controls.Add(this.from1);
            this.Controls.Add(this.from);
            this.Controls.Add(this.graphName);
            this.Controls.Add(this.b2);
            this.Controls.Add(this.b1);
            this.Controls.Add(this.k2);
            this.Controls.Add(this.b);
            this.Controls.Add(this.k1);
            this.Controls.Add(this.a);
            this.Controls.Add(this.b2_track);
            this.Controls.Add(this.b1_track);
            this.Controls.Add(this.k2_track);
            this.Controls.Add(this.k1_track);
            this.Controls.Add(this.b_track);
            this.Controls.Add(this.a_track);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.chart1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.a_track)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.b_track)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.k1_track)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.k2_track)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.b1_track)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.b2_track)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.ComponentModel.BackgroundWorker backgroundWorker2;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TrackBar a_track;
        private System.Windows.Forms.TrackBar b_track;
        private System.Windows.Forms.TrackBar k1_track;
        private System.Windows.Forms.TrackBar k2_track;
        private System.Windows.Forms.TrackBar b1_track;
        private System.Windows.Forms.TrackBar b2_track;
        private System.Windows.Forms.Label a;
        private System.Windows.Forms.Label k1;
        private System.Windows.Forms.Label b;
        private System.Windows.Forms.Label k2;
        private System.Windows.Forms.Label b1;
        private System.Windows.Forms.Label b2;
        private System.Windows.Forms.Label graphName;
        private System.Windows.Forms.MaskedTextBox from;
        private System.Windows.Forms.MaskedTextBox from1;
        private System.Windows.Forms.MaskedTextBox to;
        private System.Windows.Forms.MaskedTextBox to1;
        private System.Windows.Forms.Button redraw;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
    }
}

