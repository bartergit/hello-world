#include <iostream>
#include <vector>

using std::istream;
using std::ostream;
using std::vector;
using std::cout;

class Complex{
private:
    double re, im;
public:
    Complex(){
        re = 0; im = 0;
    }
    Complex(double r, double i){
        re = r; im = i;
    }
    friend istream& operator >>(istream&, Complex&);
    friend ostream& operator << (ostream&, const Complex&);

    Complex operator*(Complex &com){
        return Complex(re * com.re - im * com.im, re * com.im + com.re * im);
    }
    Complex operator/(Complex &com){
        double denom = com.re * com.re + com.im * com.im;
        return Complex((re * com.re + im * com.im) / denom, (com.re * im - re * com.im) / denom);
    }
    Complex operator+(const Complex& com){
        return Complex(re + com.re, im + com.im);
    }
    Complex operator-(const Complex& com){
        return Complex(re - com.re, im - com.im);
    }
    Complex& operator+=(const Complex& com){
        re += com.re;
        im += com.im;
        return *this;
    }
    Complex& operator-=(const Complex& com){
        re -= com.re;
        im -= com.im;
        return *this;
    }
    Complex& operator*=(const Complex& com){
        re *= com.re;
        im *= com.im;
        return *this;
    }
    Complex& operator/=(const Complex& com){
        re /= com.re;
        im /= com.im;
        return *this;
    }
};
ostream& operator<<(ostream& out, const Complex& com){
    if(com.im < 0)
        out << com.re << com.im << "i";
    else
        out << com.re << "+" << com.im << "i";
    return out;
}

istream& operator>>(istream& in, Complex& com){
    cout << "Enter real part: ";
    in >> com.re;
    cout << "Enter imaginary part: ";
    in >> com.im;
    return in;
}

class ComplexVector{
private:
    vector<Complex> vec;
    int size;
public:
    ComplexVector(vector<Complex> complexVector){
        size = complexVector.size();
        vec = complexVector;
    }
    ComplexVector operator+(ComplexVector v2){
        for(int i = 0; i < v2.size; i++) {
            v2.vec[i] += this->vec[i];
        }
        return v2;
    }
    int getsize(){
        return size;
    }
    void show(){
        cout << "(";
        for (int i = 0; i < size; i++){
            if (i != 0)
                cout << ",";
            cout << vec[i];
        }
        cout << ")\n";
    }
};

int main(){
    setlocale(0, "rus");
    vector<Complex> v1 = {
            Complex(1,2),
            Complex(2,3),
            Complex(3,4)
    };
    vector<Complex> v2 = {
            Complex(4,5),
            Complex(5,6),
            Complex(6,7)
    };
    ComplexVector vec1(v1);
    vec1.show();
    ComplexVector vec2(v2);
    vec2.show();
    (vec1+vec2).show();
}