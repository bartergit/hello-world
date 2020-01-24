#pragma once
#include <iostream>
#include <cstring>

namespace UI_Project {

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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  arraykol;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  putarray;


	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  arraynewtext;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox4;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(172, 216);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Обработать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(344, 216);
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
			this->textBox2->Location = System::Drawing::Point(305, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(383, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			// 
			// putarray
			// 
			this->putarray->AutoSize = true;
			this->putarray->Location = System::Drawing::Point(169, 55);
			this->putarray->Name = L"putarray";
			this->putarray->Size = System::Drawing::Size(130, 13);
			this->putarray->TabIndex = 5;
			this->putarray->Text = L"Введите члены массива";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(305, 92);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(383, 20);
			this->textBox3->TabIndex = 8;
			// 
			// arraynewtext
			// 
			this->arraynewtext->AutoSize = true;
			this->arraynewtext->Location = System::Drawing::Point(53, 92);
			this->arraynewtext->Name = L"arraynewtext";
			this->arraynewtext->Size = System::Drawing::Size(246, 13);
			this->arraynewtext->TabIndex = 9;
			this->arraynewtext->Text = L"Упорядоченный массив (сортировка выбором)";
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 135);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(257, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Упорядоченный массив (сортировка пузырьком)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(305, 135);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(383, 20);
			this->textBox1->TabIndex = 12;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 174);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(290, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Упорядоченный массив (сортировка перемешиванием)";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(305, 174);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(383, 20);
			this->textBox4->TabIndex = 14;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 281);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->arraynewtext);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->putarray);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->arraykol);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Сортировка массива. Вариант №5";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		void SortVybor(int* arrayPtr, int length_array) // сортировка (методом выбора)
		{
			for (int repeat_counter = 0; repeat_counter < length_array - 1; repeat_counter++)
			{
				int temp = arrayPtr[0];
				for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
				{
					if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
					{
						temp = arrayPtr[repeat_counter];
						arrayPtr[repeat_counter] = arrayPtr[element_counter];
						arrayPtr[element_counter] = temp;
					}
				}
			}
		}

		void SortPyzyr(int* arrayPtr, int length_array) // сортировка (методом пузырька)
		{
			for (int i = length_array - 1; i >= 0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if (arrayPtr[j] > arrayPtr[j + 1])
					{
						int temp = arrayPtr[j];
						arrayPtr[j] = arrayPtr[j + 1];
						arrayPtr[j + 1] = temp;
					}
				}
			}
		}

		void SortPeremesh(int* arrayPtr, int length_array) // сортировка (методом перемешивания)
		{
			int last = length_array - 1, left = 1, right = length_array - 1;
			do
			{
				for (int j = right; j >= left; j--)
				{
					if (arrayPtr[j - 1] > arrayPtr[j])
					{
						int temp = arrayPtr[j];
						arrayPtr[j] = arrayPtr[j - 1];
						arrayPtr[j - 1] = temp;
						last = j;
					}
				}

				left = last + 1;

				for (int j = left; j <= right; j++)
				{
					if (arrayPtr[j - 1] > arrayPtr[j])
					{
						int temp = arrayPtr[j];
						arrayPtr[j] = arrayPtr[j - 1];
						arrayPtr[j - 1] = temp;
						last = j;
					}
				}
				right = last - 1;
			} while (left < right);
		}

	private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (((e->KeyChar >= '0') && (e->KeyChar <= '9')) || (e->KeyChar == 8) || (e->KeyChar == ' ') || (e->KeyChar == '-')) return;
		// то, что написано сверху: разрешаем вводить циферки от 0 до 9, пробел, бекспейс (чтобы удалить элемент)
		e->Handled = true; // Остальные символы запрещены, поэтому просто не даём вводить
	}

			 // действие при нажатии первой кнопки "Обработать"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		int size_array = System::Convert::ToInt32(numericUpDown1->Value); // переводим в переменную значение бокса "Введите количество членов массива"
		String^ str = ""; // вводим строку, через которую будем выводить в конце массив
		array<String^>^ as; // массив строк, в котором будут временно храниться числа
		array<Char>^ ar; // массив строк, такой же, что и выше, но побочный (перевод String^ -> array Char^ -> Array String^)
		ar = gcnew array<Char>(1); // создаём стоку в массиве char
		ar[0] = ' ';
		as = textBox2->Text->Split(ar); // переводим в массив все значения
		if (as->Length != size_array || as[0] == "") // сравниваем количество членов массива строк с количеством перемнной из бокса "Кол-во членов массива"
		{
			MessageBox::Show("Не введены все данные данные или количество данных превышает определённое!\nОбработка невозможна", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return; //В случае ошибки покадываем дополнительное окно с ошибкой и прекращаем дальнейшую работу кнопки
		}

		int *main_array = new int[size_array]; // создаём массив
		for (int i = 0; i < size_array; i++) // в который вводим значения из массива строк
		{
			main_array[i] = Convert::ToInt32(as[i]);
		}
		/////////////////////////

		int *sorted_array = new int[size_array]; // создаём массив, который будем сортировать
		for (int i = 0; i < size_array; i++) sorted_array[i] = main_array[i];
		SortVybor(sorted_array, size_array); // сортируем массив выбором
		str = ""; // чистим строку вывода
		for (int counter = 0; counter < size_array; counter++) // формируем строку уже отсортированным массивом
		{
			str = str->Format(str + "{0} ", sorted_array[counter]);
		}
		textBox3->Text = str; // выводим строку в бокс "Упорядоченный массив"

		//////////////////////////

		for (int i = 0; i < size_array; i++) sorted_array[i] = main_array[i];
		SortPyzyr(sorted_array, size_array); // сортируем массив пузырьком
		str = ""; // чистим строку вывода
		for (int counter = 0; counter < size_array; counter++) // формируем строку уже отсортированным массивом
		{
			str = str->Format(str + "{0} ", sorted_array[counter]);
		}
		textBox1->Text = str; // выводим строку в бокс "Упорядоченный массив"

		//////////////////////////

		for (int i = 0; i < size_array; i++) sorted_array[i] = main_array[i];
		SortPeremesh(sorted_array, size_array); // сортируем массив методом перемешивания
		str = ""; // чистим строку вывода
		for (int counter = 0; counter < size_array; counter++) // формируем строку уже отсортированным массивом
		{
			str = str->Format(str + "{0} ", sorted_array[counter]);
		}
		textBox4->Text = str; // выводим строку в бокс "Упорядоченный массив"

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		// Чистим все боксы от мусора. В общем, приводим к оригинальному состоянию
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		numericUpDown1->Value = 1;
	}

	};
}