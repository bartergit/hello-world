#include "stdafx.h"
#include "Cat.h"
#include <cstring>
#include <iostream>
using namespace std;
const char SIZE = 20;

Cat::Cat(): age(0), name(nullptr){}

Cat::Cat(int age, char* name) {
	if(this->age>=0)	this->age = age;
	else {
		cout << "invalid age\n";
		system("pause");
		exit(1);
	}
	this->name = new char[SIZE];
	if (this->name) strcpy(this->name, name);//this->name = name;
	else {
		cout << "memory are not allocated\n";
		system("pause");
		exit(1);
	}
}
Cat::Cat(const Cat& cat) {
	if (this->age>=0)	this->age = cat.age;
	else {
		cout << "invalid age\n";
		system("pause");
		exit(1);
	}
	this->name = new char[SIZE];
	if(this->name)	strcpy(this->name, cat.name); //this->name = cat.name;
	else {
		cout << "memory are not allocated";
		system("pause");
		exit(1);
	}
}
Cat::~Cat() {
	delete[]name;
}
char* Cat::toString() {
	char* buf = new char[100];
	strcpy(buf, "Name: ");
	strcat(buf, this->name);
	strcat(buf, ", age: ");
	char str_age[5];
	sprintf(str_age, "%d", this->age);
	strcat(buf, str_age);
	return buf;
}
int Cat::compare(Cat cat) {
	if (this->age > cat.age) return 1;
	if (this->age < cat.age) return -1;
	return 0;
}
Cat& Cat::operator=(Cat& cat) {
	if (this->age >= 0)	this->age = cat.age;
	else {
		cout << "invalid age\n";
		system("pause");
		exit(1);
	}
	delete[]this->name;
	this->name = new char[SIZE];
	if (this->name)	strcpy(this->name, cat.name); //this->name = cat.name;
	else {
		cout << "memory are not allocated";
		system("pause");
		exit(1);
	}
	return *this;
}