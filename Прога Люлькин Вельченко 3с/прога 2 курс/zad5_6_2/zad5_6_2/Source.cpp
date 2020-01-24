/*
Создать класс Pair (пара чисел);
определить методы изменения полей и вычисления произведения чисел.
Определить производный класс RightAngled (прямоугольный треугольник) с полями-катетами.
Определить методы вычисления гипотенузы и площади треугольника.
*/
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;
class Pair
{
protected:
	int a, b;
public:
	void Set(int a1, int b1)
	{
		a = a1; b = b1;
	}
	int Mult()
	{
		return (a*b);
	}
};

class RightAngled :public Pair
{
public:
	float Gip()
	{
		return (sqrt(pow(a, 2) + pow(b, 2)));
	}
	int Squer()
	{
		return Mult()*1/2;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	RightAngled obj;
	cout << "Введите первый катет: ";
	cin >> a;
	cout << "Введите второй катет: ";
	cin >> b;
	obj.Set(a, b);
	cout << "Гипотенуза: " << obj.Gip() << endl;
	cout << "Площадь: " << obj.Squer() << endl;
	system("Pause");
}