#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
class Date{
public:
    int day, month, year;
    Date(){
//        cout << "()";
        SYSTEMTIME st;
        GetSystemTime(&st);
        day = st.wDay;
        month = st.wMonth;
        year = st.wYear;
    }
    Date(Date& d){
//        cout << "(1)";
        day = d.day;
        month = d.month;
        year = d.year;
    }
    Date(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }
    Date& operator =(Date& d){
//        cout << "(2)";
        day = d.day;
        month = d.month;
        year = d.year;
        return *this;
    }
    bool leep();
};

class Time : public Date{
public:
    int h, m, s;
    Time(){
        SYSTEMTIME st;
        GetSystemTime(&st);
        h = st.wHour + 3;
        m = st.wMinute;
        s = st.wSecond;
    }
    Time(Time& d){
        month = d.month;
        year = d.year;
        day = d.day;
        h = d.h;
        m = d.m;
        s = d.s;
    }
    Time(int ho, int mi, int se){
        h = ho;
        m = mi;
        s = se;
    }
    Time(int h, int m, int s,int day1, int month1, int year1):Date(day1,month1,year1){
        this->h = h;
        this->m = m;
        this->s = s;
    }
    Time& operator =(Time& d){
        h = d.h;
        m = d.m;
        s = d.s;
        return *this;
    }
};

ostream& operator <<(ostream& out, Date d)
{
    return out << d.day << '.' << d.month << '.' << d.year;
}

ostream& operator <<(ostream& out, Time d)
{
    return out << "\nDate: " << d.day << '.' << d.month << '.' << d.year << "  ---- Time:" << d.h << ':' << d.m << ':' << d.s;
}

bool Date::leep(){
    if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0)))
        return true;
    else return false;

}

class InheritancedDate : public virtual Time{
public:
    InheritancedDate(int h, int m, int s):Time(h,m,s){}
    InheritancedDate(int h, int m, int s,int day, int month, int year):Time(h,m,s,day,month,year){}
};

ostream& operator <<(ostream& out, InheritancedDate d){
    out << "\nDate: ";
    if (d.day < 10)
        out << "0";
    out << d.day << ".";
    if (d.month < 10)
        out << "0";
    out << d.month << ".";
    if (d.year < 10)
        out << "0";
    out << d.year << "  ---- Time: ";
    if (d.h < 10)
        out << "0";
    out << d.h << ":";
    if (d.m < 10)
        out << "0";
    out << d.m << ":";
    if (d.s < 10)
        out << "0";
    out << d.s;
    if (d.h < 10) {
        out << " morning ";
    }
    else {
        if (d.h < 18) {
            out << " daytime ";
        }
        else {
            out << " night ";
        }
    }
    return out;
}

int main(){
    Time time;
    cout << time;
    InheritancedDate inheritancedDate(11,23,15);
    cout << inheritancedDate;
    InheritancedDate inheritancedDate2(1,2,3,11,23,15);
    cout << inheritancedDate2;
    return 0;
}