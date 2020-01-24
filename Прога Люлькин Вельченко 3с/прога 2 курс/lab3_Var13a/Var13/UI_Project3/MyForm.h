#pragma once
#include <cmath>
#define M_E 2.71828
#define M_PI 3.14159265358979323846

namespace UI_Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-1, -1);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(484, 367);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 367);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Лаб №3. Вариант №4.";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		int l, b, h, w;

	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		h = pictureBox1->Height;            
		w = pictureBox1->Width;             

		e->Graphics->DrawLine(Pens::Black, 0, h / 2, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w / 2, 0, w / 2, h);

		e->Graphics->DrawLine(Pens::Black, w - 25, h / 2 + 8, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w - 25, h / 2 - 8, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w / 2 - 8, 25, w / 2, 0);
		e->Graphics->DrawLine(Pens::Black, w / 2 + 8, 25, w / 2, 0);

		e->Graphics->DrawString("X", this->Font, Brushes::Black, (float)w - 15, (float)h / 2 - 25); 
		e->Graphics->DrawString("Y", this->Font, Brushes::Black, (float)w / 2 - 25, 5);

		double x1, x2, y1, y2, x, y, dx, my, mx;
		
		//////////////////////////////////////////
		// График №1

		x1 = -10.7;  
		x2 = 10.7; 
		dx = 0.001; 

		////////////////////

		y1 = pow(1/M_E,pow(x1,2.0)); 
		y2 = pow(1/M_E, pow(x2, 2.0)); 
		for (x = x1; x<=x2; x += dx) 
		{
					y = pow(1/M_E, pow(x, 2.0)); 
					if (y < y1) y1 = y; 
					if (y > y2) y2 = y; 			
		}

		my = 0.5*h / (y2 - y1); 
		mx = w / (x2 - x1); 

		// Рисуем график
		y1 = pow(1/M_E, pow(x1, 2.0)); 
		for (x = x1+dx; x <= x2; x += dx) 
		{
				y = pow(1/M_E, pow(x, 2.0)); 
				e->Graphics->DrawLine(Pens::Red, (int)(x1*mx + w / 2), (int)(h / 2 - y1*my), (int)(x*mx + w / 2), (int)(h / 2 - y*my));
				x1 = x; 
				y1 = y;
		}
		
		double phi1 = 0, phi2 = 2 * M_PI, r, phi, dphi, mY, mX, X1, X2, Y1, Y2, X, Y;
		//////////////////////////////////////////
		// График №2
		r = 5;
		dphi = 0.001;
		X1 = r * cos(phi1);
		X2 = r * cos(phi2);
		Y1 = r * sin(phi1);
		Y2 = r * sin(phi2);
		for (phi = phi1; phi <= phi2; phi += dphi) {
			X = r * cos(phi); Y = r * sin(phi);
			if (X < X1) X1 = X;
			if (X > X2) X2 = X;
			if (Y < Y1) Y1 = Y;
			if (Y > Y2) Y2 = Y;
		}

		mY = h / (Y2 - Y1);
		mX = w / (X2 - X1);

		X1 = r * cos(phi1); Y1 = r * sin(phi1);
		for (phi = phi1 + dphi; phi <= phi2; phi += dphi) {
			X = r * cos(phi); Y = r * sin(phi);
			e->Graphics->DrawLine(Pens::Blue, (int)(X1*mX + w / 2), (int)(h / 2 - Y1 * mY), (int)(X*mX + w / 2), (int)(h / 2 - Y * mY));
			X1 = X;
			Y1 = Y;
		}

	}
	};
}
