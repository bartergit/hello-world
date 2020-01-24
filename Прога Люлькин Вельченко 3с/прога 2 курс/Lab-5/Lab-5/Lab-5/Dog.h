#pragma once
#include "Pet.h"

class Dog :
	public Pet
{
	bool service;
	string breed;

public:
	Dog();
	Dog(int, string, string, bool);
	string getBreeed();
	string toString();
	void show();
	string bool_cast(const bool);
	void aaa();
	~Dog();
};

