#pragma once

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

	protected:




	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SaveResultToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;







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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveResultToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1135, 28);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->openFileToolStripMenuItem,
					this->SaveResultToolStripMenuItem, this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(57, 24);
			this->fileToolStripMenuItem->Text = L"Файл";
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(229, 26);
			this->openFileToolStripMenuItem->Text = L"Открыть файл";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openFileToolStripMenuItem_Click);
			// 
			// SaveResultToolStripMenuItem
			// 
			this->SaveResultToolStripMenuItem->Name = L"SaveResultToolStripMenuItem";
			this->SaveResultToolStripMenuItem->Size = System::Drawing::Size(229, 26);
			this->SaveResultToolStripMenuItem->Text = L"Сохранить результат";
			this->SaveResultToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::SaveResultToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(226, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(229, 26);
			this->exitToolStripMenuItem->Text = L"Выход";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 113);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(308, 195);
			this->textBox1->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(406, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Слово1";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(337, 147);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(172, 22);
			this->textBox2->TabIndex = 11;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(923, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 17);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Итоговый текст";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(108, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 17);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Исходный текст";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(631, 77);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 17);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Слово2";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(578, 147);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(150, 22);
			this->textBox3->TabIndex = 15;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(822, 113);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(301, 220);
			this->textBox4->TabIndex = 16;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(357, 338);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(152, 55);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Обработать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(589, 338);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 54);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1135, 426);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Лаб. №2. Вариант 13";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close(); 
	}

	private: System::Void openFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult dr; 
		String^ fn; 
		openFileDialog1->FileName = String::Empty; 
		dr = openFileDialog1->ShowDialog(); 
		if (dr == System::Windows::Forms::DialogResult::OK)
		{
			fn = openFileDialog1->FileName; 
			try
			{
				System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(fn); 
				textBox1->Text = sr->ReadToEnd(); 
				sr->Close(); 
			}
			catch (System::IO::FileLoadException^ e) 
			{
				MessageBox::Show("Ошибка ввода:\n" + e->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void SaveResultToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		saveFileDialog1->Filter = "Итоговый текст (*.txt)|*.txt"; 
		System::Windows::Forms::DialogResult dr; 
		String^ fn; 
		dr = saveFileDialog1->ShowDialog(); 
		if (dr == System::Windows::Forms::DialogResult::OK) 
		{
			fn = saveFileDialog1->FileName; 
			try
			{
				System::IO::FileInfo^ fi = gcnew System::IO::FileInfo(fn); 
				System::IO::StreamWriter^ sw = fi->CreateText(); 
				sw->Write(textBox4->Text); 
				sw->Close(); 

			}
			catch (System::IO::IOException^ e) 
			{
				MessageBox::Show(e->ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

			 int i = 0;
			 void Sort(char* arrayPtr, char* sort, char* word1, char* word2) 
			 {
				 for (int a = 0; a < 4; a++)
				 {
					 if (arrayPtr[a] == word1[0])
					 {
						 sort[i] = word2[0];
					 }
					 else sort[i] = arrayPtr[a];
					 i++;
				 }
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		array<String^>^ as; 
		array<Char>^ ar; 
		ar = gcnew array<Char>(10); 
		ar[0] = ' ';
		as = textBox1->Text->Split(ar); 
		char *sorted_array = new char[4]; 
		for (int b = 0; b < 4; b++) 
		{
			sorted_array[b] = Convert::ToChar(as[b]); 
		}

		array<String^>^ aq; 
		array<Char>^ aw; 
		aw = gcnew array<Char>(10); 
		aw[0] = ' ';
		aq = textBox2->Text->Split(aw); 
		char *word1 = new char[1]; 
		word1[0] = Convert::ToChar(aq[0]);

		array<String^>^ ae; 
		array<Char>^ at; 
		at = gcnew array<Char>(10); 
		at[0] = ' ';
		ae = textBox3->Text->Split(at); 
		char *word2 = new char[1]; 
		word2[0] = Convert::ToChar(ae[0]);

		char *sort = new char;
		Sort(sorted_array, sort, word1, word2); 
		String^ str = ""; 
		for (int counter = 0; counter < i; counter++)
		{
			str = str->Format(str + "{0} ", Convert::ToChar(sort[counter]));
		}
		textBox4->Text = str; 
		delete sort;
		delete sorted_array;
		delete word1;
		delete word2;

		button1->Enabled = false; 
	}

			 private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 textBox1->Text = "";
				 textBox4->Text = "";
				 textBox2->Text = "";
				 textBox3->Text = "";
				 button1->Enabled = true;
				 button2->Enabled = false;
			 }

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

};
}
