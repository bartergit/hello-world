#include "Dictionary.h"

void Dictionary::show() {
	cout << langFrom << "-" << langTo << " " << author << "'s dictionary " << year << ", " << wordCount << " words." << endl;
	Item::show();
	cout << endl;
}
Dictionary::Dictionary(string langFrom, string langTo, string author, int year, int wordCount) {
	this->langFrom = langFrom;
	this->langTo = langTo;
	this->author = author;
	this->year = year;
	this->wordCount = wordCount;
}
Dictionary::~Dictionary() {};
