#include "Pet.h"
#include "ExeptoinAge.h"


Pet::Pet() {}

Pet::Pet(int age, string name) {
	this->name = name;
	setAge(age);
}

void Pet::setAge(int age) {
	if (age > 0 && age < 25) this->age = age;
	else throw ExeptoinAge("Invalid age!!!");
}

int Pet::getAge() {
	return this->age;
}

string Pet::getName() {
	return this->name;
}

string Pet::toString() {
	return "Name: " + name + "\n" + "Age: " + to_string(age);
}

void Pet::show() {
	cout << "Pet" << endl;
	cout << toString() << endl << endl;
}

void Pet::aaa() {
	cout << "Pet" << endl;
}

Pet::~Pet() {}

