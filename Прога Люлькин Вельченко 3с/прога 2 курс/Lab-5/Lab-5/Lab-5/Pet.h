#pragma once
#include <iostream>
#include <sstream>
#include <cstring>
#include <string.h>
#include <string>

using namespace std;

class Pet
{
	int age;
	string name;

public:
	Pet();
	Pet(int, string);
	string getName();
	void setAge(int);
	int getAge();
	void show();
	virtual string toString();
	virtual ~Pet();
	void aaa();
};