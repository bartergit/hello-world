/*Определить класс Polynom степени n . Ввести операцию нахождения производной. 
Объявить массив из m  полиномов и выбрать из них полиномы с наименьшим и наибольшим значением для данного X .
*/
#include "pch.h"
#include <iostream>
using namespace std;
class  Polynom
{
	int size;
	int *arr;
public:

	Polynom();
	Polynom(int a);
	Polynom(int a, int *ar);
	void Show();
	int Proiz(int x);
};

Polynom::Polynom() {

};

Polynom::Polynom(int a) {
	size = a; arr = new int[size];
}

Polynom::Polynom(int a, int *ar) {
	size = a; arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = ar[i];
}

void Polynom::Show() {
	cout << "Coficients :";
	for (int i = 0; i < size; i++)
		cout << " " << arr[i];
	cout << endl;
}
int Polynom::Proiz(int x) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = val + pow(x, i)*arr[i];
	}
	return val;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int size, n, x; int arr[20];
	cout << "Введите количество полиномов: ";
	cin >> n;


	Polynom *obj = new Polynom[n];
	for (int j = 0; j < n; j++)
	{
		cout << "Введите степень полинома: ";
		cin >> size;

		cout << "Введите коэф полинома: " << endl;
		for (int i = 0; i < size; i++)
			cin >> arr[i];
		obj[j] = Polynom(size, arr);
	}

	cout << "Введите X: ";
	cin >> x;
	int num = 0, num1 = 0, ab = obj[0].Proiz(x);
	for (int i = 0; i < (n - 1); i++)
		if (ab < obj[i + 1].Proiz(x))
		{
			num = (i + 1); ab = obj[i + 1].Proiz(x);
		}  ab = 0;
	for (int i = 0; i < (n - 1); i++)
		if (ab > obj[i + 1].Proiz(x))
		{
			num1 = (i + 1); ab = obj[i + 1].Proiz(x);
		}
	cout << "Максимальное значение полинома" << endl;
	obj[num].Show();
	cout << endl << "Со значением: " << obj[num].Proiz(x) << endl;
	cout << "Минимальное значение полинома" << endl;
	obj[num1].Show();
	cout << endl << "Со значением: " << obj[num1].Proiz(x) << endl;
	system("Pause");
	delete obj;
}
 
