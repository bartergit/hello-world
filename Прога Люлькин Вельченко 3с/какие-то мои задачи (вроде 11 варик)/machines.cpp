#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
//Создать базовый класс «Транспортное средство» и производные классы «Автомобиль», «Велосипед», «Повозка».
//Подсчитать время и стоимость пере­возки пассажиров и грузов каждым транспортным средством.
class Transport{
private:
    string model;
    string name;
    double speed;
    double charge;
public:
    Transport(){
        static int index = 65;
        this->charge = 5;
        this->name = "New"+std::to_string(index);
        this->model = char(index++);
        this->speed = 10;
    }
    Transport(string name,string model,double charge,double speed){
        this->charge = charge;
        this->name = name;
        this->model = model;
        this->speed = speed;
    }
    void show(){
        cout << "named by <" << name << ">" << model << "\nCharge is " << charge << "$ for " << speed << " km/h\n\n";
    }
    //set
    void setName(string name){
        this->name = name;
    }
    void setModel(string model){
        this->model = model;
    }
    void setSpeed(double speed){
        this->speed = speed;
    }
    void setCharge(double charge){
        this->charge = charge;
    }
    //get
    string getName(){
        return name;
    }
    string getModel(){
        return model;
    }
    double getSpeed(){
        return speed;
    }
    double getCharge(){
        return charge;
    }
    //virtual void type()=0;
};

class Car: public Transport{
public:
    Car(){
        static int index = 0;
        setName("Notthesame" + std::to_string(index++));
    }
    Car(string name,string model,double charge,double speed):Transport(name,model,charge,speed){
    }
    void unicMethod(){
        cout << "Hey. Charge increased by  5!";
        setCharge(getCharge()+5);
    }
    void type(){
        cout <<"\nCar\n";
    }
};

class Type{
public:
    void virtual type()=0;
};

class Bike: public Transport, public Type{
private:
    string unicValue;
public:
    Bike(){
        unicValue = "I am unic!!";
    }
    Bike(string name,string model,double charge,double speed):Transport(name,model,charge,speed){
        unicValue = "I am unic!!";
    }
    Bike(string unicValue){
        this->unicValue = unicValue;
    }
    void setUnicValue(){
        this->unicValue = unicValue;
    }
    string getUnicValue(){
        return unicValue;
    }
    void type(){
        cout <<"\nBike\n";
    }
};

class Wagon: public Transport{
public:
    Wagon(){}
    Wagon(string name,string model,double charge,double speed):Transport(name,model,charge,speed){}
    void type(){
        cout <<"\nWagon\n";
    }
};

double countCharge(double distance,Transport transport){
    return distance*transport.getCharge();
}

double countTime(double distance,Transport transport){
    return distance/transport.getSpeed();
}

int main(){
    Wagon w1("Shevrolet","Camaro",16,18);
    Bike b1("Carvalet","Montaro",200,0.5);
    Car c2;
    Car c3;
    Transport array[4] = {w1,c2,c3,b1};
    for (int i = 0; i < 4; i++){
        cout << "Charge and time for 1 km will be " << countCharge(1,array[i]) <<"$ and " << countTime(1,array[i]) << " h.\n";
        array[i].show();
    }
}