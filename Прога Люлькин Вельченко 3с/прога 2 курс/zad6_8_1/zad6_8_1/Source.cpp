/*
13.	Определить класс «Квадратное уравнение».
Перегрузить операции ввода/вывода. Использовать try { } – catch { },
если уравнение не имеет решения. Определить производный класс «Биквадратное уравнение».
Создать массив объектов и выполнить вычисления.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>  

using namespace std;

class MyException {
	char mes[256];
public:
	MyException(const char * s) {
		strcpy(mes, s);
	}
	void ShowMes() {
		cout << mes << endl;
	}
};

class SquareEquation {
protected:
	double a, b, c;
public:
	SquareEquation() :a(0), b(0), c(0) {};
	SquareEquation(double aa, double bb, double cc) :a(aa), b(bb), c(cc) {};

	SquareEquation(const SquareEquation&);

	friend ostream& operator<< (ostream &out, const SquareEquation &quadEq);
	friend istream& operator>> (istream &in, SquareEquation &quadEq);

	double getD();

	double rootRight();
	double rootLeft();
};

SquareEquation::SquareEquation(const SquareEquation& eq) {
	a = eq.a;
	b = eq.b;
	c = eq.c;
}


ostream& operator<<(ostream &out, const SquareEquation &quadEq) {
	if (abs(quadEq.a) == 1) {
		out << (quadEq.a > 0 ? "" : "-");
	}

	else {
		out << quadEq.a;
	}
	out << "x^2";

	if (quadEq.b) {
		out << (quadEq.b > 0 ? " + " : " - ");
		if (abs(quadEq.b) != 1) {
			out << abs(quadEq.b);
		}
		out << "x";
	}

	if (quadEq.c) {
		out << (quadEq.c > 0 ? " + " : " - ") << abs(quadEq.c);
	}
	out << " = 0";
	return out;
}

istream& operator>> (istream &in, SquareEquation &quadEq) {
	cout << "\n\nВведите коэффициент при x^2: ";
	in >> quadEq.a;

	cout << "Введите коэффициент при x: ";
	in >> quadEq.b;

	cout << "Введите свободный член: ";
	in >> quadEq.c;

	return in;
}

double SquareEquation::getD() {
	double d = (b * b - 4 * a*c);
	return d;
}

double SquareEquation::rootRight() {
	if (getD() < 0 || (a == 0 && b == 0))
		return -1;

	if ((b == 0 && c == 0) || (a == 0 && c == 0))
		return 0;

	if (a == 0)
		return (-c / b);

	if (b == 0) {
		if ((-c / a) > 0)
			return sqrt(-c / a);
	}

	if (c == 0)
		return 0;

	if (getD() == 0)
		return (-b / (2 * a));

	return ((-b - sqrt(getD())) / (2 * a));
}

double SquareEquation::rootLeft() {

	if (getD() < 0 || (a == 0 && b == 0))
		return -1;

	if ((b == 0 && c == 0) || (a == 0 && c == 0))
		return 0;

	if (a == 0)
		return (-c / b);

	if (b == 0) {
		if ((-c / a) > 0)
			return -sqrt(-c / a);
	}

	if (c == 0)
		return (-b / a);

	if (getD() == 0)
		return (-b / (2 * a));

	return ((-b + sqrt(getD())) / (2 * a));
}



class BiSquareEquation : public SquareEquation {
public:
	BiSquareEquation() :SquareEquation(0, 0, 0) {}
	BiSquareEquation(double aa, double bb, double cc) :SquareEquation(aa, bb, cc) {}
	friend ostream& operator<< (ostream &out, const BiSquareEquation &BiquadEq);
	friend istream& operator>> (istream &in, BiSquareEquation &BiquadEq);

	double rootRightFirst();
	double rootRightSecond();

	double rootLeftFirst();
	double rootLeftSecond();
};


ostream& operator<<(ostream &out, const BiSquareEquation &quadEq) {
	if (abs(quadEq.a) == 1) {
		out << (quadEq.a > 0 ? "" : "-");
	}

	else {
		out << quadEq.a;
	}
	out << "x^4";

	if (quadEq.b) {
		out << (quadEq.b > 0 ? " + " : " - ");
		if (abs(quadEq.b) != 1) {
			out << abs(quadEq.b);
		}
		out << "x^2";
	}

	if (quadEq.c) {
		out << (quadEq.c > 0 ? " + " : " - ") << abs(quadEq.c);
	}
	out << " = 0";
	return out;
}

istream& operator>> (istream &in, BiSquareEquation &quadEq) {
	cout << "\n\nВведите коэффициент при x^4: ";
	in >> quadEq.a;

	cout << "Введите коэффициент при x^2: ";
	in >> quadEq.b;

	cout << "Введите свободный член: ";
	in >> quadEq.c;

	return in;
}

double BiSquareEquation::rootRightFirst() {
	if (rootRight() >= 0) {
		return sqrt(rootRight());
	}
	return -2;
}

double BiSquareEquation::rootRightSecond() {
	if (rootRight() >= 0) {
		return -sqrt(rootRight());
	}
	return -2;
}

double BiSquareEquation::rootLeftFirst() {
	if (rootLeft() >= 0) {
		return sqrt(rootLeft());
	}
	return -2;
}

double BiSquareEquation::rootLeftSecond() {
	if (rootLeft() >= 0) {
		return -sqrt(rootLeft());
	}
	return -2;
}



void SetEq(BiSquareEquation *arr, int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void ShowEq(BiSquareEquation *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\n\nУравнение " << i + 1 << ": ";
		cout << arr[i];
	}
}

void Results(BiSquareEquation *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\n\nУравнение " << i + 1 << ": ";
		cout << arr[i];

		try {
			if (arr[i].getD() < 0) throw MyException("\nДействительных корней нет.");
		}
		catch (MyException &me) {
			me.ShowMes();
		}

		if (arr[i].getD() >= 0) {
			cout << "\nДескриминат при t=x^2: " << arr[i].getD();
		}



		if (!(arr[i].rootLeft() == arr[i].rootRight())) {

			if (arr[i].rootRightFirst() == -2 || arr[i].rootRightSecond() == -2) {
				cout << "\nПервый и второй корни мнимые.";
			}

			else  if (arr[i].rootRightFirst() == 0 && arr[i].rootRightSecond() == (-0)) {
				cout << "\nПервый и второй корни нули: " << arr[i].rootRightFirst();
			}

			else {
				cout << "\nПервый корень: " << arr[i].rootRightFirst();
				cout << "\nВторой корень: " << arr[i].rootRightSecond();
			}

			if (arr[i].rootLeftFirst() == -2 || arr[i].rootLeftSecond() == -2) {
				cout << "\nТретий и четвертый корни мнимые.";
			}

			else {
				cout << "\nТретий корень: " << arr[i].rootLeftFirst();

				try {
					if (arr[i].rootLeftFirst() == 0 && arr[i].rootLeftSecond() < 0) throw MyException("\nКорнь четыре отрицателен.");

					cout << "\nЧетвертый корень: " << arr[i].rootLeftSecond();
				}
				catch (MyException &me) {
					me.ShowMes();
				}
			}


		}

		else if (arr[i].getD() >= 0) {
			cout << "\ny=x^2 имеет один корень, значит корни биквадратного уравнения";

			if (arr[i].rootRightFirst() == 0 && arr[i].rootRightSecond() == (-0)) {
				cout << "\nПервый и второй корни нули: " << arr[i].rootRightFirst();
			}

			else {
				cout << "\nПервый корень: " << arr[i].rootRightFirst();
				cout << "\nВторой корень: " << arr[i].rootRightSecond();
			}
		}

	}
}





int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Сколько будем считать уравнений?\n";
	cout << "n = "; cin >> n;
	//SquareEquation* eq = new SquareEquation[n];

	BiSquareEquation* bieq = new BiSquareEquation[n];


	SetEq(bieq, n);
	ShowEq(bieq, n);
	cout << endl << endl;
	Results(bieq, n);
	cout << endl;
	system("pause");
}