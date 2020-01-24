#pragma once
#include "Pet.h"

class Cat :
	public Pet
{
	int numberOfLives;
	string breed;

public:
	Cat();
	Cat(int, string, string, int);
	string getBreeed();
	string toString();
	void show();
	void aaa();
	~Cat();
};


