#include "Dog.h"


Dog::Dog() {}

Dog::Dog(int age, string name, string breed, bool service) :Pet(age, name) {
	this->breed = breed;
	this->service = service;
}

string Dog::getBreeed() {
	return this->breed;
}

string Dog::toString() {
	return Pet::toString() + "\n" + "Breed: " + breed + "\n" + "Service: " + bool_cast(service);
}

void Dog::show() {
	cout << "Dog" << endl;
	cout << toString() << endl << endl;
}

void Dog::aaa() {
	cout << "Dog" << endl;
}

Dog::~Dog() {}

string Dog::bool_cast(const bool b)
{
	ostringstream ss;
	ss << boolalpha << b;
	return ss.str();
}