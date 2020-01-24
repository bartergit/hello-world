#pragma once
#include <iostream>
#include <cstring>
#include "MyForm1.h"

namespace UI_Project2 {

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
		MyForm1 ^ resForm;
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  arraykol;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  putarray;


	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  arraynewtext;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->arraykol = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->putarray = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->arraynewtext = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(171, 271);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Обработать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(350, 271);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(166, 44);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// arraykol
			// 
			this->arraykol->AutoSize = true;
			this->arraykol->Location = System::Drawing::Point(215, 11);
			this->arraykol->Name = L"arraykol";
			this->arraykol->Size = System::Drawing::Size(195, 13);
			this->arraykol->TabIndex = 3;
			this->arraykol->Text = L"Введите количество членов массива";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 71);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(325, 183);
			this->textBox2->TabIndex = 4;
			// 
			// putarray
			// 
			this->putarray->AutoSize = true;
			this->putarray->Location = System::Drawing::Point(97, 46);
			this->putarray->Name = L"putarray";
			this->putarray->Size = System::Drawing::Size(130, 13);
			this->putarray->TabIndex = 5;
			this->putarray->Text = L"Введите члены массива";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(350, 71);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(338, 183);
			this->textBox3->TabIndex = 8;
			// 
			// arraynewtext
			// 
			this->arraynewtext->AutoSize = true;
			this->arraynewtext->Location = System::Drawing::Point(449, 46);
			this->arraynewtext->Name = L"arraynewtext";
			this->arraynewtext->Size = System::Drawing::Size(129, 13);
			this->arraynewtext->TabIndex = 9;
			this->arraynewtext->Text = L"Элементы";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(416, 8);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(69, 20);
			this->numericUpDown1->TabIndex = 10;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 327);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->arraynewtext);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->putarray);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->arraykol);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Выборка элементов. Вариант №13";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		int i = 0;
		void Sort(int* arrayPtr, int length_array, int* sort)
		{
			for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
			{
				for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
				{
					if (arrayPtr[element_counter] == arrayPtr[repeat_counter])
					{
						sort[i] = arrayPtr[repeat_counter];
						i++;
					}
				}
			}
		}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		int size_array = System::Convert::ToInt32(numericUpDown1->Value);
		array<String^>^ as;
		array<Char>^ ar;
		String^ str = "";
		ar = gcnew array<Char>(1);
		ar[0] = ' ';
		as = textBox2->Text->Split(ar);
		if (as->Length != size_array || as[0] == "")
		{
			MessageBox::Show("Не введены все данные данные или количество данных превышает определённое!\nОбработка невозможна", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		int *sorted_array = new int[size_array];
		int *sort = new int;
		for (int q = 0; q < size_array; q++)
		{
			sorted_array[q] = Convert::ToInt32(as[q]);
		}
		Sort(sorted_array, size_array, sort);
		delete resForm;
		str = "";
		for (int a = 0; a < i; a++)
			str += sort[a].ToString() + " ";
		resForm = gcnew MyForm1();
		resForm->Set(str);
		resForm->Show();
		delete sort;

		button1->Enabled = false;
		button2->Enabled = true;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		textBox2->Text = "";
		textBox3->Text = "";
		numericUpDown1->Value = 1;
		button1->Enabled = true;
		button2->Enabled = false;
	}

	};
}
