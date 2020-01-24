#pragma once
#include "Pet.h"

class Parrot :
	public Pet
{
	bool speaking;
	string breed;

public:
	Parrot();
	Parrot(int, string, string, bool);
	string getBreeed();
	string toString();
	void show();
	string bool_cast(const bool);
	void aaa();
	~Parrot();
};
