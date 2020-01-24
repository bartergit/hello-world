/*
7.	Создать класс BitString как производный от класса Array (динамический массив). 
Битовая строка должна быть представлена динамическим массивом типа char, 
каждый элемент которого принимает значение 0 или 1. 
Перегрузить традиционные операции для работы с битовыми строками 
and, or, xor, not. Перегрузить операции сдвига влево и сдвига вправо 
на заданное количество битов.
*/

#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Array {
protected:
	int size;
	char *arr;
public:
	Array();
	Array(char*, int);
	Array(const Array&);

	~Array();

	void Show();  // Функция ввода на экран
	virtual void Set(); // Функция для задания

	Array& operator = (const Array&); //  Перегруженный оператор присваивания

};

Array::Array() :size(0), arr(NULL) {}

Array::Array(char* v, int n) {
	size = n;
	arr = new char[size];
	for (int i = 0; i < size; i++)
		arr[i] = v[i];
}

Array::Array(const Array& v) {
	size = v.size;
	arr = new char[size];
	for (int i = 0; i < size; i++)
		arr[i] = v.arr[i];
}

Array::~Array() {
	delete[] arr;
	size = 0;
}

Array& Array::operator = (const Array&v) {
	if (this == &v)
		return *this;
	size = v.size;
	delete[] arr;

	arr = new char[size];
	for (int i = 0; i < size; i++)
		arr[i] = v.arr[i];
	return *this;
}

void Array::Set() {
	cout << "Введите размерность битовой строки: ";
	cin >> size;
	arr = new char[size];
	for (int i = 0; i < size; i++) {
		cout << "Введите " << i + 1 << " элемент битовой строки: ";
		cin >> arr[i];
		cout << endl;
	}
	cout << endl;
}

void Array::Show() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

class BitString: public Array {
public:
	BitString();
	BitString(char *, int);

	void Set();
	void readFromIn1();
	void readFromIn2();

	const BitString operator&(const BitString &t);  //and
	const BitString operator|(const BitString &t);  //or
	const BitString operator^(const BitString &t);  //xor
	BitString& operator~();                    //not


	BitString operator<<(int);       //left
	BitString operator>>(int);       //right

	BitString rightCycleShift(int);  //rightCycleShift
	BitString leftCycleShift(int);   //leftCycleShift
};

BitString::BitString():Array() {}

BitString::BitString(char * v, int n) {
	size = n;
	for (int i = 0; i < n; i++) {
		if (v[i] != '0' && v[i] != '1')
			size--;
	}

	if (size == n) {
		arr = new char[size];
		for (int i = 0; i < size; i++)
			arr[i] = v[i];
	}
	else {
		size = 0;
		arr = NULL;
	}
}

void BitString::Set() {
	cout << "Введите размерность битовой строки: ";
	cin >> size;
	arr = new char[size];
	for (int i = 0; i < size; i++) {
		cout << "Введите " << i + 1 << " элемент: ";
		cin >> arr[i];
		if (arr[i] != '0' && arr[i] != '1') {
			cout << "Ошибка ввода! Введено чмсло, отличное от 1 или 0" << endl;
			i--;
		}
	}
}

void BitString::readFromIn1() {
	ifstream in1("in1.txt");
	while (!in1.eof()) {
		for (int i = 0; i < size; i++)
			in1 >> arr[i];
	}
	in1.close();
}

void BitString::readFromIn2() {
	ifstream in2("in2.txt");
	while (!in2.eof()) {
		for (int i = 0; i < size; i++)
			in2 >> arr[i];
	}
	in2.close();
}

const BitString BitString :: operator&(const BitString &t) {
	if (size == t.size) {
		char *temp = new char[size];

		for (int i = 0; i < t.size; i++) {
			if (arr[i] == '1' && t.arr[i] == '1')
				temp[i] = '1';
			else
				temp[i] = '0';
		}
		BitString t(temp, size);
		return t;
	}

	else {
		cout << endl << "Операция невозможна: разная размерность векторов" << endl;
		BitString t;
		return t;
	}
}

const BitString BitString :: operator|(const BitString &t) {
	if (size == t.size) {
		char *temp = new char[size];

		for (int i = 0; i < t.size; i++) {
			if (arr[i] == '1' || t.arr[i] == '1')
				temp[i] = '1';
			else
				temp[i] = '0';
		}
		BitString t(temp, size);
		return t;
	}

	else {
		cout << endl << "Операция невозможна: разная размерность векторов" << endl;
		BitString t;
		return t;
	}
}

const BitString BitString :: operator^(const BitString &t) {
	cout << "Operator ^: " << endl;
	if (size == t.size) {
		char *temp = new char[size];
		for (int i = 0; i < t.size; i++) {
			if ((arr[i] == '1') && (t.arr[i] == '1') || (arr[i] == '0') && (t.arr[i] == '0'))
				temp[i] = '0';
			else
				temp[i] = '1';
		}
		BitString t(temp, size);
		return t;
	}

	else {
		cout << endl << "Операция невозможна: разная размерность векторов" << endl;
		BitString t;
		return t;
	}
}

BitString &BitString :: operator~() {
	cout << "Operator ~: " << endl;
	BitString temp = *this;
	for (int i = 0; i < temp.size; i++) {
		if (temp.arr[i] == '1')
			temp.arr[i] = '0';
		else
			temp.arr[i] = '1';
	}
	return temp;
}

BitString BitString::operator<<(int a) {
	BitString temp = *this;

	temp.arr = new char[size + 1];
	*temp.arr = 0;

	for (int i = 0; (i < (size - a)); i++)
		temp.arr[i] = arr[a + i];

	for (int i = 0; i < a; i++)
		temp.arr[size - a + i] = '0';

	return temp;
}

BitString BitString::operator>>(int a) {
	BitString temp = *this;

	temp.arr = new char[size + 1];
	*temp.arr = 0;

	for (int i = 0; i < a; i++)
		arr[0] == '0' ? temp.arr[i] = '0' : temp.arr[i] = '1';

	for (int i = 0; i < size - a; i++)
		temp.arr[a + i] = arr[i];

	return temp;
}


BitString BitString::rightCycleShift(int a) {
	BitString temp = *this;

	while (a) {
		int t = temp.arr[size - 1];

		for (int i = size - 1; i > 0; --i)
			temp.arr[i] = temp.arr[i - 1];

		temp.arr[0] = t;

		a--;
	}

	return temp;
}

BitString BitString::leftCycleShift(int a) {
	BitString temp = *this;

	while (a) {
		int t = temp.arr[0];

		for (int i = 0; i < size; i++)
			temp.arr[i] = temp.arr[i + 1];

		temp.arr[size - 1] = t;

		a--;
	}

	return temp;
}

void SetArr(BitString *arr, int n) {
	for (int i = 0; i < n; i++)
		arr[i].Set();
}

void ShowArr(BitString *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << endl << i + 1 << ": ";
		arr[i].Show();
	}
}

void Operators(BitString *arr, int n) {
	int m1, m2;
	int vibor;

	unsigned int s;

	BitString arrK;
	BitString arrD;
	BitString arrOr;
	do {
		cout << "\n Введите номер пункта:\n";
		cout << "Выберите номера битовых строк для проверки-->1" << endl	
			<< "Конъюнкция битовой строки------------------->2" << endl
			<< "Дизъюнкция битовой строки------------------->3" << endl
			<< "Исключающее ИЛИ для битовой строки---------->4" << endl
			<< "Инверсия битовых строк---------------------->5" << endl
			<< "Сдвиг вправо-------------------------------->6" << endl
			<< "Сдвиг влево--------------------------------->7" << endl
			<< "Циклический сдвиг вправо-------------------->8" << endl
			<< "Циклический сдвиг влево--------------------->9" << endl
			<< "Выход -------------------------------------->0" << endl;
		cin >> vibor;

		switch (vibor) {
		case 1:
			cout << "Первая строка: "; cin >> m1;
			cout << "Вторая строка: "; cin >> m2;

			cout << "Выбранные строки: " << endl;

			cout << "Первая: "; arr[m1 - 1].Show();
			cout << endl << "Вторая: "; arr[m2 - 1].Show();
			cout << endl;
			break;
		case 2:
			arrK = (arr[m1 - 1] & arr[m2 - 1]);

			cout << "Бит строка 1: ";
			(arr[m1 - 1]).Show();
			cout << endl;

			cout << "Бит строка 2: ";
			(arr[m2 - 1]).Show();
			cout << endl << endl;

			cout << "Конъюнкция: ";
			arrK.Show();

			cout << endl;
			break;
		case 3:
			arrD = arr[m1 - 1] | arr[m2 - 1];

			cout << "Бит строка 1: ";
			(arr[m1 - 1]).Show();
			cout << endl;

			cout << "Бит строка 2: ";
			(arr[m2 - 1]).Show();
			cout << endl << endl;

			cout << "Дизъюнкция: ";
			arrD.Show();

			cout << endl;
			break;
		case 4:
			arrOr = arr[m1 - 1] ^ arr[m2 - 1];

			cout << "Бит строка 1: ";
			(arr[m1 - 1]).Show();
			cout << endl;

			cout << "Бит строка 2: ";
			(arr[m2 - 1]).Show();
			cout << endl << endl;

			cout << "Искл ИЛИ для бит строк: ";
			arrOr.Show();

			cout << endl;
			break;
		case 5:
			cout << "Инверсия первой бит строки: ";
			~arr[m1 - 1];
			(arr[m1 - 1]).Show();
			cout << endl;

			cout << "Инверсия второй бит строки: ";
			~arr[m2 - 1];
			arr[m2 - 1].Show();
			
			cout << endl;
			break;
		case 6:
			cout << " На сколько будем двигать первую строку?" << endl;
			cin >> s;

			cout << "Строка 1" << endl;
			(arr[m1 - 1]).Show();
			cout << endl;

			cout << "Строка 1 AFTER >>" << endl;
			(arr[m1 - 1] << s).Show();
			cout << endl;


			cout << " На сколько будем двигать вторую строку?" << endl;
			cin >> s;

			cout << "Строка 2" << endl;
			(arr[m2 - 1]).Show();
			cout << endl;

			cout << endl << "Строка 2 ARTER >>" << endl;
			(arr[m2 - 1] << s).Show();


			cout << endl;
			break;
		case 7:
			cout << " На сколько будем двигать первую строку?" << endl;
			cin >> s;

			cout << "Строка 1" << endl;
			(arr[m1 - 1]).Show();
			cout << endl;

			cout << "Строка 1 AFTER <<" << endl;
			(arr[m1 - 1] << s).Show();
			cout << endl;


			cout << " На сколько будем двигать вторую строку?" << endl;
			cin >> s;

			cout << "Строка 2" << endl;
			(arr[m2 - 1]).Show();
			cout << endl;

			cout << endl << "Строка 2 ARTER <<" << endl;
			(arr[m2 - 1] << s).Show();
			
			cout << endl;
			break;
		case 8:
			cout << " На сколько будем двигать первую строку?" << endl;
			cin >> s;

			cout << "Строка 1" << endl;
			(arr[m1 - 1]).Show();
			cout << endl;

			cout << "Строка 1 AFTER rightCycleShift" << endl;
			((arr[m1 - 1]).rightCycleShift(s)).Show();
			cout << endl;


			cout << " На сколько будем двигать вторую строку?" << endl;
			cin >> s;

			cout << "Строка 2" << endl;
			(arr[m2 - 1]).Show();
			cout << endl;

			cout << "Строка 2 AFTER rightCycleShift";
			((arr[m2 - 1]).rightCycleShift(s)).Show();

			cout << endl;
			break;

		case 9:
			cout << " На сколько будем двигать первую строку?" << endl;
			cin >> s;

			cout << "Строка 1" << endl;
			(arr[m1 - 1]).Show();
			cout << endl;

			cout << "Строка 1 AFTER leftCycleShift" << endl;
			((arr[m1 - 1]).leftCycleShift(s)).Show();
			cout << endl;


			cout << " На сколько будем двигать вторую строку?" << endl;
			cin >> s;

			cout << "Строка 2" << endl;
			(arr[m2 - 1]).Show();
			cout << endl;

			cout << "Строка 2 AFTER rightCycleShift" << endl;
			((arr[m2 - 1]).leftCycleShift(s)).Show();

			cout << endl;
			break;

		case 10:
			cout << "Good-Bye!   ";
			system("pause");
			exit(1);

		}

	} while (vibor != 11);
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введите количество векторов: ";
	cin >> n;
	BitString *arr = new BitString[n];

	int vibor;
	while (1) {
		cout << "\n Введите номер пункта:\n";
		cout << "Создать битовую строку-------->1" << endl
			<< "Выход из программы------------>0" << endl;
		cin >> vibor;
		switch (vibor) {
		case 1:
			SetArr(arr, n);
			ShowArr(arr, n);
			Operators(arr, n);
			break;
		case  0:
			cout << "Good-Bye!   ";
			system("pause");
			exit(1);
		}
	}

}

