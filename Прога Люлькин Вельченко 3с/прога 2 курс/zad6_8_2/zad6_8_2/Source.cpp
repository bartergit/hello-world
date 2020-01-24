/*13. —оздать класс Triad (тройка чисел); определить с помощью перегрузки операций ==, != сравнение триад.
ќпределить производный класс Date (дата) с пол€ми: год, мес€ц и день.
ќпределить полный набор операций сравнени€ дат (==, !=, <, >).*/
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;
class Triad
{
protected:
	int n;
	int *num;
public:
	Triad();
	Triad(int);
	Triad(int, int*);
	int getNum(int i);
	const Triad operator==(Triad&, Triad&);
	Triad operator!=(Triad ob);
	friend istream& operator>>(istream&, Triad&);
	friend ostream& operator<<(ostream&, Triad&);
};

Triad Triad::operator==(Triad& ob1, Triad& ob2) {
	for (size_t i = 0; i < n; i++)
	{

	}
}
int Triad::getNum(int i) {
	return num[i];
}
Triad::Triad() {
	num = new int[n];
	for (int i = 0; i < n; i++)
		num[i] = 0;
};
Triad::Triad(int N) {
	n = N;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		num[i] = 0;
	}
};
Triad::Triad(int N, int* Num) {
	n = N;
	num = new int[n];
	for (int i = 0; i, n; i++) {
		num[i] = Num[i];
	}
}
istream& operator>>(istream& is, Triad& ob) {
	for (int i = 0; i < ob.n; i++) {
		is >> ob.num[i];
	}
	return is;
};
ostream& operator<<(ostream& os, Triad& ob) {
	for (int i = 0; i < ob.n; i++) {
		os << ob.num[i];
	}
	return os;
};
class RightAngled :public Triad
{
public:
	
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, num;
	cout << "¬ведите размерность = ";
	cin >> n;
	Triad v1(n), v2(n);
	cout << "¬ведите первый вектор = ";
	cin >> v1;
	cout << "ѕервый вектор = ";
	cout << v1 << endl;
	cout << "¬ведите второй вектор = ";
	cin >> v2;
	cout << "¬торой вектор = ";
	cout << v2 << endl;
	system("pause");
	return 0;
}