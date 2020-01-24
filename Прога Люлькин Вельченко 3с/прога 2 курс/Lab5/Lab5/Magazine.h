#pragma once
#include "Item.h"
#include <string>
class Magazine : public Item
{
	int volume;
	int number;
	int year;
	string title;
public:
	virtual void show();
	Magazine(int, int, int, string);
	~Magazine();
};

