/*Адрес, этаж, количество комнат, площадь. Создать массив объектов.
а) список квартир, имеющих заданное число комнат.
б) список квартир, имеющих заданное число комнат и расположенных на этаже, который находится в определенном промежутке.
в) список квартир, имеющих площадь, превосходящую заданную.*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
using namespace std;
class House {
	char adr[10];
	int kol, floor, sq;
public:
	void set();
	void show();
	int getFloor();
	int getRoom();
	int getSquare();
	void WriteToFile();
};
void House::set() {
	ifstream fin("input.txt", ios::in);
	ofstream fout("output.txt", ios::out);
	House hs;
	fin.get((char*)&hs, ' ');
	while (fin) {
		fin.read((char*)&hs, sizeof(House));
		fin >> hs.adr; 
		fin >> hs.floor;
		fin >> hs.kol;
		fin >> hs.sq;
		fout.write((char*)&hs, sizeof(House));
	}
	fin.close();
	fout.close();
};
void House::show() {
	ifstream fin("input.txt", ios::in);
	ofstream fout("output.txt", ios::out);
	House hs;
	while (fin) {
		fin.read((char*)&hs, sizeof(House));
		if (fin)cout << "Адрес: " << hs.adr << endl
			<< "Этаж: " << hs.floor << endl
			<< "Кол-во комнат: " << hs.kol << endl
			<< "Площадь: " << hs.sq << endl;
		cout << endl;
		if (fin)fout << "\r\n" << "Адрес: " << hs.adr << endl
			<< "Этаж: " << hs.floor << endl
			<< "Кол-во комнат: " << hs.kol << endl
			<< "Площадь: " << hs.sq << endl;
	}
	cout << endl;
	fout.close();
	fin.close();
	cout << "Adress " << hs.adr << endl;
	cout << "Floor " << hs.floor << endl;
	cout << "Room " << hs.kol << endl;
	cout << "Square " << hs.sq << endl;
	cout << "------------" << endl;
};

int House::getFloor() { return floor; };
int House::getRoom() { return kol; };
int House::getSquare() { return sq; };
void komnata(House hs[], int n) {
	int chislo;
	cout << "Enter kol-vo room = "; cin >> chislo;
	cout << "---------------" << endl;
	for (int i = 0; i < n; i++) {
		if (chislo == hs[i].getRoom()) {
			hs[i].show();
		}
	}
}
void prom(House hs[], int n) {
	int Room, l, b;
	cout << "Enter kol-vo room = "; cin >> Room;
	cout << "Enter lowest floor = "; cin >> l;
	cout << "Enter largest floor = "; cin >> b;
	for (int i = 0; i < n; i++) {
		if (Room == hs[i].getRoom()) {
			if (hs[i].getFloor() > l && hs[i].getFloor() < b)
				hs[i].show();
		}
	}
}
void square(House hs[], int n) {
	int square;
	cout << "Enter square = "; cin >> square;
	for (int i = 0; i < n; i++) {
		if (hs[i].getSquare() > square)
			hs[i].show();
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, vibor; bool status = true;
	House *hs;
	cout << "Enter kol house " << endl;
	cin >> n;
	hs = new House[n];
	while (1) { //добавляем меню
		cout << "\n vvedite nomer punkta:\n";
		cout << "vvod------>1" << endl
			<< "kol-vo room----->2" << endl
			<< "interval------>3" << endl
			<< "square------>4" << endl
			<< "vivod------>5" << endl
			<< "exit------>6" << endl;
		cin >> vibor;
		switch (vibor) {
		case 1:
			for (int i = 0; i < n; i++) {
				hs[i].set();
				hs[i].show();
			}break;
		case 2:
			komnata(hs, n); break;
		case 3:
			prom(hs, n); break;
		case 4:
			square(hs, n); break;
		case 5:
			for (int i = 0; i < n; i++)
				hs[i].show(); break;
		case 6:
			cout << "Good-Bye!";
			delete[] hs; //высвобождаем память
			break;
		}
	}
	system("pause");
}