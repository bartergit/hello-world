#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 200
class Chair
{
	char* buffer;
public:
	int legs;
	Chair(int legs) { 
	this->legs = legs; 
	this->buffer = new char[SIZE];
	}
	Chair() { 
	this->legs = 0; 
	this->buffer = new char[SIZE];
	}
	~Chair() {};
	char * toString() {
		strcpy(buffer, "Chair. Legs: ");
		return strcat(buffer, (char*)legs);
	}
};

