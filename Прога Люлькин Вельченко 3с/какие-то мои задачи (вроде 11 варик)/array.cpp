#include <iostream>
#include <cassert>
using std::cout;
//11. Создать базовый класс Array с полями: динамический массив типа char и
//поле для хранения количества элементов. Перегрузить операцию
//индексирования []. При этом должна выполняться проверка индекса на
//        допустимость. Реализовать в классе Array виртуальную функцию
//поэлементного сложения двух массивов. Реализовать два следующих
//        производных класса, переопределив виртуальную функцию сложения.
//Вызывающая программа должна продемонстрировать все варианты
//вызова виртуальных функций.
//
//Создать класс Octal (длинное целое восьмеричное) и класс BitString
//(битовая строка, сложение заменяется дизъюнкцией).

class Array{
protected:
    char *ptr;
    int size;
public:
    Array(int size = 0,char def = 65){
        this->size = size;
        ptr = new char[size+1];
        for (int i = 0; i < size; i++){
            ptr[i] = def;
        }
        ptr[size] = '\0';
    }
    virtual Array operator+(Array other){
        Array min = (this->size < other.size) ? *this : other;
        Array max = (this->size > other.size) ? *this : other;
        Array toReturn(size,'0');
        for (int i = 0; i < min.size; i++){
            toReturn[i] = this->ptr[i] + other.ptr[i];
        }
        for (int i = min.size; i < max.size; i++){
            toReturn[i] = max.ptr[i];
        }
        return toReturn;
    }
    virtual char& operator[](int index){
        assert (!(index < 0) && !(index >= size));
        return ptr[index];
    }
    void print(){
        cout << ptr << "\n";
    }
};

class Octal: public Array{
    int decimal;
public:
    Octal(int x){
        this->decimal = x;
        int remainder;
        this->size = 0;
        while (true){
            x /= 8;
            size++;
            if (x == 0) break;
        }
        x = this->decimal;
        this->ptr = new char[size+1];
        for (short i = size - 1; i >= 0; i--) {
            remainder = x % 8;
            x /= 8;
            ptr[i] = '0' + remainder;
        }
        ptr[size] = '\0';
    };
    Octal operator+(Octal other){
        return Octal(this->decimal + other.decimal);
    }
};
class BitString: public Array{
    int decimal;
public:
    BitString(int x){
        this->decimal = x;
        int remainder;
        this->size = 0;
        while (true){
            x /= 2;
            size++;
            if (x == 0) break;
        }
        x = this->decimal;
        this->ptr = new char[size+1];
        for (short i = size - 1; i >= 0; i--) {
            remainder = x % 2;
            x /= 2;
            ptr[i] = '0' + remainder;
        }
        ptr[size] = '\0';
    };

    BitString operator+(BitString other){
        BitString min = (this->size < other.size) ? *this : other;
        BitString max = (this->size > other.size) ? *this : other;
        BitString to_return(max);                       //
        for (int i = max.size-1; i >= 0; i--){
            to_return[i] = max.ptr[i];
        }
        for (int i = max.size - 1, j = min.size - 1; j >= 0; i--, j--){
            to_return[i] = '0' + (to_return[i] - '0' || min.ptr[j] - '0');
        }
        return BitString(to_return);
    }
};

int main(){
    Array a(3,'b');
    Array b(2,'k');
    a.print();
    cout << "[0] - " << (a)[0] << "\n";
    b.print();
    cout << "[0] - " << (b)[1] << "\n";
    a[2] = 'v';
    (a+b).print();
    Octal c(1265);
    Octal c2(15);
    (c2+c).print();
    cout << "[0] - " << (c2+c)[0];
    cout << "\n[1] - " << (c2+c)[1];
    BitString bs(10);   //15 =     8 + 4 + 2 + 1   //  01010
    BitString bs2(53); //21 = 16 +     4 +    1   //  110101 21+32
    cout << "\n  "; bs.print();
    cout << "[0] - " << bs[0];
    cout << "\n[1] - "<< bs[1] << "\n";
    bs2.print();
    BitString bs3 = (bs+bs2);
    (bs3).print();
}
//
// Created by Lenovo on 16.12.2019.
//

