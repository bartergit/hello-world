#pragma once
#include "Item.h"
#include <string>
class Dictionary : public Item
{
	string langFrom;
	string langTo;
	string author;
	int year;
	int wordCount;
public:
	virtual void show();
	Dictionary(string, string, string, int, int);
	~Dictionary();
};


