#pragma once
#include<iostream>
using namespace std;
class Item
{
protected:
	bool isAvailable;
	int invNumber;
public:
	virtual void show();
	bool getIsAvailable() { return this->isAvailable; }
	int getInvNumber() { return this->invNumber; }
	void take();
	void refund();
};

