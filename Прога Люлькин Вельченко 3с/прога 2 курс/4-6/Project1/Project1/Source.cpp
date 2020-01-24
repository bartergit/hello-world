#include <iostream>
using namespace std;
class Polynom
{
public:
	Polynom();
	~Polynom();
	Polynom(int);
	Polynom(int, int*);
	Polynom operator+(Polynom ob);
	friend istream& operator>>(istream&, Polynom&);
	friend ostream& operator<<(ostream&, Polynom&);
	int getPower();
	int getNum(int i);
private:
	int n;
	int *num;
};
bool Derivate(Polynom&);
Polynom::Polynom()
{
	num = new int[n];
	for (int i = 0; i < n; i++) {
		num[i] = 0;
	}
}
Polynom::Polynom(int N) {
	n = N;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		num[i] = 0;
	}
}
Polynom::Polynom(int N, int *Num) {
	n = N;
	for (int i = 0; i < n; i++) {
		num[i] = Num[i];
	}
}
int Polynom::getNum(int i){
	return num[i];
}
int Polynom::getPower() {
	return n;
}
bool Derivate(Polynom& ob1) {
	int sum = 0, x = 0;
	for (int i = 0; i < ob1.getPower() + 1; i++)
	{
		cout << i << endl;
		x = i*pow(ob1.getNum(i), i - 1);
	}
	sum = sum + x;
	cout << "AAAAAA" << endl;
	cout << sum;
	return true;
}
Polynom::~Polynom()
{
	delete[] num;
}
istream& operator>>(istream& is, Polynom& ob) {
	for (int i = 0; i < ob.n; i++)
	{
		is >> ob.num[i];
	}
	return is;
}
ostream& operator<<(ostream& os, Polynom& ob) {
	for (int i = 0; i < ob.n; i++)
	{
		os << ob.num[i];
	}
	return os;
}
int main(){
	setlocale(LC_ALL, "Russian");
	int n, num;
	cout << "¬ведите степень многочлена = ";
	cin >> n;
	cout << "¬ведите значение x = ";
	Polynom a(n);
	cout << Derivate(a);
	system("pause");
	return 0;
}