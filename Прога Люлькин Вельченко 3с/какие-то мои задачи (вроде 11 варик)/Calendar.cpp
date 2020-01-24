#include <iostream>
#include <string>
#include <map>
using std::map;
using std::string;
using std::cout;
using std::cin;


class Date{
public:
    int day;
    int month;
    int year;
    Date(int day, int month, int year):day(day),year(year),month(month){}
    show(){
        cout << "\nDate: ";
        if (day < 10)
            cout << "0";
        cout << day << ".";
        if (month < 10)
            cout << "0";
        cout << month << ".";
        if (year < 10)
            cout << "0";
    }
};

class Calendar{
public:
    int month;
    int year;
    short monthInd;
    int yearInd;
    Calendar(int month, int year):year(year),month(month){
        if (month == 1 || month == 10)
            this->monthInd = 1;
        if (month == 2 || month == 3 || month == 11)
            this->monthInd = 4;
        if (month == 5)
            this->monthInd = 2;
        if (month == 8)
            this->monthInd = 3;
        if (month == 6)
            this->monthInd = 5;
        if (month == 9 || month == 12)
            this->monthInd = 6;
        if (month == 4 || month == 7)
            this->monthInd = 0;
        int temp = year - (year/100)*100;
        yearInd = (6 + temp + temp/4) % 7;
//        1 — январь, октябрь;
//        2 — май;
//        3 — август;
//        4 — февраль, март, ноябрь;
//        5 — июнь;
//        6 — декабрь, сентябрь;
//        0 — апрель, июль.
    }
    defineDayOfWeek(int day){
        return (day + monthInd + yearInd) % 7;
//        (день + код месяца + код года) % 7
    }
    datesByDayOfWeek(int dayOfWeek){
        for (int day = 1; day < 32; day++){
            if (dayOfWeek == (day + monthInd + yearInd) % 7){
                Date(day,month,year).show();
                day += 6;
            }
        }
    }
};
//Определить базовый класс Date и использующий его класс Calendar на определенный месяц.
//Объявить массив объектов Calendar на год.
//Для месяца январь вывести по дате день недели, по дню недели вывести все даты.

int main(){
    Calendar january(1,2019);
    Calendar february(2,2019);
    Calendar march(3,2019);
    Calendar april(4,2019);
    Calendar may(5,2019);
    Calendar june(6,2019);
    Calendar july(7,2019);
    Calendar august(8,2019);
    Calendar september(9,2019);
    Calendar october(10,2019);
    Calendar november(11,2019);
    Calendar december(12,2019);
    Calendar array[12] ={january,february,march,april,may,june,july,august,september,october,november,december};
    cout << december.defineDayOfWeek(8);
    january.datesByDayOfWeek(1);
}
//
// Created by Lenovo on 08.12.2019.
//

