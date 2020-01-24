#include <iostream>
//Создать класс «Рациональная дробь» и реализовать основные методы.
//Написать функцию вычисления длины периода рациональной дроби
//m/n.
using std::cout;
using std::cin;
using std::endl;

int count(){
    return 3;
}

int gcd(int u, int v) {
    while (v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) {
        numerator = num / gcd(num, denom);
        denominator = denom / gcd(num, denom);
    }
    Fraction() {
        numerator = 0;
        denominator = 1;
    }
    Fraction(int num) {
        numerator = num;
        denominator = 1;
    }
    /*int num(Fraction ratio) {
        return ratio.numerator / gcd(ratio.numerator, ratio.denominator);
    }
    int denom(Fraction ratio) {
        return ratio.denominator / gcd(ratio.numerator, ratio.denominator);
    }*/
    double value() const {
        return double(numerator) / double(denominator);
    }
    Fraction operator+(const Fraction& ratio) const {
        int num = numerator * ratio.denominator + ratio.numerator * denominator;
        int denom = ratio.denominator * denominator;
        return Fraction(num, denom);
    }
    Fraction operator-(const Fraction& ratio) const {
        int num = numerator * ratio.denominator - ratio.numerator * denominator;
        int denom = ratio.denominator * denominator;
        return Fraction(num, denom);
    }
    Fraction operator*(const Fraction& ratio) const {
        int num = numerator * ratio.numerator;
        int denom = ratio.denominator * denominator;
        return Fraction(num, denom);
    }
    Fraction operator/(const Fraction& ratio) const {
        int num = numerator * ratio.denominator;
        int denom = ratio.numerator * denominator;
        return Fraction(num, denom);
    }
    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }
    bool operator=(const Fraction& ratio) const {
        return Fraction(numerator, denominator).value() == ratio.value();
    }
    bool operator>(const Fraction& ratio) const {
        return Fraction(numerator, denominator).value() > ratio.value();
    }
    bool operator<(const Fraction& ratio) const {
        return Fraction(numerator, denominator).value() < ratio.value();
    }
    void print(){
        if (numerator == 0 || denominator == 1)
            cout << numerator << endl;
        else
            cout << numerator << "/" << denominator << endl;
    }
    int period(){
        return count()*bool(numerator*denominator);
    }
};

int main() {
    Fraction f1 = Fraction(2, 3)+(Fraction(5, 4)/(Fraction(3, 11)+Fraction(2)));
    Fraction f2 = Fraction(6)*(Fraction(5, 8)-Fraction(3, 5));
    f1.print();
    f2.print();
    Fraction test = Fraction(1, 3);
    test.print();
    cout << "Period is " << test.period() << "\n";
    if (f1 > f2)
        cout << "more\n";
    else
    if (f1 < f2)
        cout << "less\n";
    else
        cout << "equal\n";
}