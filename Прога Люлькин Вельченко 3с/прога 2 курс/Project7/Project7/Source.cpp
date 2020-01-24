#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	TimeFull New;
	TimeL New2;
	cout << "Текущее время в краткой форме: " << New2 << endl;
	cout << "Текущее время в полной форме: " << New << endl;
	TimeFull New3c(10, 56, 34);
	TimeL New4c(10, 56, 34);
	cout << "Введённое время в краткой форме: " << New4c << endl;
	cout << "Введённое время в полной форме: " << New3c << endl;
}