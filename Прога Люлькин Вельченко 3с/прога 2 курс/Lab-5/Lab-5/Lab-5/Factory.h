#pragma once
#include <vector>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"


class Factory
{
public:
	static vector<Pet*> petFactory(int);
};

