#include "Parrot.h"



Parrot::Parrot() {}

Parrot::Parrot(int age, string name, string breed, bool speaking) :Pet(age, name) {
	this->breed = breed;
	this->speaking = speaking;
}

string Parrot::getBreeed() {
	return this->breed;
}

string Parrot::toString() {
	return Pet::toString() + "\n" + "Breed: " + breed + "\n" + "Speaking: " + bool_cast(speaking);
}

string Parrot::bool_cast(const bool b)
{
	ostringstream ss;
	ss << boolalpha << b;
	return ss.str();
}

void Parrot::aaa() {
	cout << "Parrot" << endl;
}

void Parrot::show() {
	cout << "Parrot" << endl;
	cout << toString() << endl << endl;
}

Parrot::~Parrot() {}
