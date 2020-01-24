#include <iostream>
#include <string>
using std::string;

//11.Создать класс Man (человек) с полями: имя, возраст, пол и вес.
//Определить методы переназначения имени, изменения возраста и изменения
//веса. Создать производный класс Student, имеющий поле для года обучения.
//Определить методы переназначения и увеличения года обучения.
//Перегрузить операции ++, --.


class Man{
protected:
    char gender;
    string name;
    int age;
    float weight;
public:
    Man(char gender, string name, unsigned int age, float weight):
    gender(gender),name(name),age(age),weight(weight){
        if (gender != 'm' || gender != 'f') gender = '?';
        if (weight < 0) weight = 0;
    }
    void rename(string name){
        this->name = name;
    }
    void reage(unsigned int age){
        this->age = age;
    }
    void reweight(float weight){
        this->weight = weight;
        if (weight < 0) weight = 0;
    }
    friend std::ostream& operator<<(std::ostream &out, const Man &man1);
};


class Student : public Man{
private:
    unsigned short year;
public:
    Student(char gender, string name, unsigned int age, float weight, unsigned short year):Man(gender,name,age,weight),year(year){
    }
    void operator++(){
        year++;
    }
    void operator--(){
        year++;
    }
    unsigned short getYear(){
        return year;
    }
    void setYear(unsigned short year){
        this->year = year;
    }
    friend std::ostream& operator<<(std::ostream &out, const Student &student);
};

std::ostream& operator<<(std::ostream &out, const Man &man1){
    out << man1.name << " "  << man1.gender << " " << man1.weight << " " << man1.age;
    return out;
}

std::ostream& operator<<(std::ostream &out, const Student &man1){
    out << man1.name << " "  << man1.gender << " " << man1.weight << " " << man1.age << " " << man1.year;
    return out;
}

int main() {
    Man me('m',"Vanya",19,56.8);
    std::cout << me;
    Student st('m',"Vanya",19,56.8,5);
    ++st;
    std::cout << "\n" << st;
}