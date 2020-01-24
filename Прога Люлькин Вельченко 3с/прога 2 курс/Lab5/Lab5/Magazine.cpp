#include "Magazine.h"
#include <string.h>
#include <iostream>

using namespace std;

Magazine::Magazine(int volume, int number, int year, string title)
{	
	this->volume = volume;
	this->number= number;
	this->year = year;
	this->title = title;
}

void Magazine::show() {
	cout << "This is a magazine " << this->title << " #" << this->number << " vol. " << this->volume << " of " << this->year << endl;
	Item::show();
	cout << endl;
}

Magazine::~Magazine()
{
}
