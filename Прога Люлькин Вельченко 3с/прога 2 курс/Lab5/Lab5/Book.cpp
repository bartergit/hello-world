#include "Book.h"
#include <string.h>
#include <iostream>

using namespace std;

Book::Book(char * title, char * author, char * publisher, int year)
{
	this->year = year;
	this->title = new char[strlen(title)];
	strcpy(this->title, title);
	this->publisher = new char[strlen(publisher)];
	strcpy(this->publisher, publisher);
	this->author = new char[strlen(author)];
	strcpy(this->author, author);
}

void Book::show() {
	cout << "This is a book " << this->title << " by " << this->author<< " " << this->year<< ". Published by " << this->publisher << endl;
}
