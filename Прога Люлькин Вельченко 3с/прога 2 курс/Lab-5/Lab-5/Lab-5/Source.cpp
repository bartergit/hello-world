#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Parrot.h"
#include "ExeptoinAge.h"
#include "HandlerPet.h"
#include "Factory.h"

int main() {
	const int size = 10;
	try
	{

		vector<Pet*> array = Factory::petFactory(size);


		HandlerPet handler;
		handler.arrayShow(array);
		cout << endl;
	}
	catch (ExeptoinAge &ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}

	system("pause");
	return 0;
}