#include <iostream>
#include <vector>

//В задании требуется реализовать абстрактный базовый класс, объявив в
//нем чистые виртуальные функции. Эти функции определяются в
//производных классах. В базовом классе должны быть объявлены чистые
//        виртуальные функции ввода/вывода, которые реализуются в производных
//классах.
//Вызывающая программа должнаё продемонстрировать все варианты
//вызова виртуальных функций с помощью указателей на базовый класс.
//Написать внешнюю функцию вывода, получающую параметры типа
//базового класса по ссылке и демонстрирующую виртуальный вызов.
//
//Создать абстрактный базовый класс Triad (три целых числа) с
//        виртуальными методами увеличения (уменьшения) на 1. Создать
//        производные классы Date (дата, увеличение(уменьшение) на 1 день) и
//Time (время, увеличение (уменьшение) на 1 секунду).
using std::vector;

class Triad{
public:
    virtual void inc() = 0;
    virtual void dec() = 0;
    virtual void show() = 0;
};

class Time: public Triad{
    int hour;
    int min;
    int sec;
    void use_validation(){
        if (sec >= 60){
            sec -= 60;
            min++;
        }
        if (min >= 60){
            min -= 60;
            hour++;
        }
        if (hour >= 24){
            hour -= 24;
        }
        if (sec <= -1){
            sec += 60;
            min--;
        }
        if (min <= -1){
            min += 60;
            hour--;
        }
        if (hour <= -1){
            hour += 24;
        }
    }
public:
    Time():hour(0),min(0),sec(0){}
    Time(int hour,int min, int sec):hour(hour),min(min),sec(sec){}
    void inc(){
        sec++;
        use_validation();
    }
    void dec(){
        sec--;
        use_validation();
    }
    void show(){
        if (hour < 10)
            std::cout << "0";
        std::cout <<  hour << ":";
        if (min < 10)
            std::cout << "0";
        std::cout <<  min << ":";
        if (sec < 10)
            std::cout << "0";
        std::cout <<  sec << "    ";
    }
};

class Date: public Triad{
    int year;
    int month;
    int day;
    void use_validation(){
        if (day >= 32){
            day -= 31;
            month++;
        }
        if (month >= 13){
            month -= 12;
            year++;
        }
        if (day <= 0){
            day += 31;
            month--;
        }
        if (month <= 0){
            month += 12;
            year--;
        }
    }
public:
    Date(): year(2008), month(1), day(1){}
    Date(int hour,int min, int sec): year(hour), month(min), day(sec){}
    void inc(){
        day++;
        use_validation();
    }
    void dec(){
        day--;
        use_validation();
    }
    void show(){
        if (day < 10)
            std::cout << "0";
        std::cout << day << ".";
        if (month < 10)
            std::cout << "0";
        std::cout <<  month << ".";
        std::cout << year << "    ";
    }
};

int main(){
    vector <Triad*> vec;
    vec.resize(2);
    vec[0] = new Time(23,59,59);
    vec[1] = new Date(2004,12,31);
    for (int i = 0; i < 2; i++){
        vec[i]->show();
        vec[i]->inc();
        vec[i]->show();
        vec[i]->dec();
        vec[i]->show();
        std::cout << "\n";
    }
}

