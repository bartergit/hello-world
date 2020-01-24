#pragma once
#include "Item.h"
class Book : public Item
{
	char * title;
	char * author;
	char * publisher;
	int year;
public:
	char * getAuthor() { return this->author; }
	char * getPublisher() { return this->publisher; }
	int getYear() { return this->year; }
	char * getTitle() { return this->title; }
	Book(char * title, char * author, char * publisher, int year);
	void show();
};

