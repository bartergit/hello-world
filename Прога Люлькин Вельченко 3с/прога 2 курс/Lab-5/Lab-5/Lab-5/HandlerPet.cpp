#include "HandlerPet.h"
#include <iostream>
using namespace std;


HandlerPet::HandlerPet()
{
}


HandlerPet::~HandlerPet()
{
}

void HandlerPet::arrayShow(vector<Pet*> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		array[i]->show();
	}

}
