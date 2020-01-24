#include "Cat.h"



Cat::Cat() {}

Cat::Cat(int age, string name, string breed, int numberOfLives) :Pet(age, name) {
	this->breed = breed;
	this->numberOfLives = numberOfLives;
}

string Cat::getBreeed() {
	return this->breed;
}

string Cat::toString() {
	return Pet::toString() + "\n" + "Breed: " + breed + "\n" + "Number of lives: " + to_string(numberOfLives);
}

void Cat::aaa() {
	cout << "Cat" << endl;
}

void Cat::show() {
	cout << "Cat" << endl;
	cout << toString() << endl << endl;
}

Cat::~Cat() {}

