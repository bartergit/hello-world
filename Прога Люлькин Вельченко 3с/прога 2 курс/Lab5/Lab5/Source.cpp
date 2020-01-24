#include <iostream>
#include "Book.h"
#include "Magazine.h"
#include "Item.h"
#include "Dictionary.h"
#include "Magazine.h"
#include <string.h>
#include <ctime>


using namespace std;

const string authors[] = {"Dal", "Dud", "Johnson", "Webster", "Cawdrey", "Weiner", "Fowler"};
const string magazineTitles [] = { "forbes", "fortunte", "times", "washington post", "guardian", "new york post", "daily mail" };

void main() {
	srand(time(NULL));
	Item ** items = new Item * [10];
	for (int i = 0; i < 5; i++)
		items[i] = new Dictionary("eng", "rus", authors[rand() % 7], rand() % 30 + 1988, rand() % 3000 + 3000);
	for (int i = 5; i < 10; i++)
		items[i] = new Magazine(i , i, rand() % 30 + 1988, magazineTitles[rand() % 7]);
	cout << endl << "/////////////////////////   Before taking" << endl;
	for (int i = 0; i < 10; i++)
		items[i]->show();
	for (int i = 0; i < 5 + rand() % 10; i++)
		items[rand() % 10]->take();
	cout << endl << "/////////////////////////   After taking" << endl;
	for (int i = 0; i < 10; i++)
		items[i]->show();
	system("pause");
}
