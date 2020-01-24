#include <ctime>
#include "Factory.h"
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"


vector<Pet*> Factory::petFactory(int n) {
	vector<Pet*> pets;
	srand(time(0));
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			Pet* pet = new Pet(i + 2, "Vlad");
			pets.push_back(pet);
		}
		if (i % 2 == 0) {
			Dog* dog = new Dog(i + 2, "Vitaly", "Gogi", i % 2 == 0 ? 0 : 1);
			pets.push_back(dog);
		}
		else if (i % 3 == 0) {
			Cat* cat = new Cat(i + 2, "Pasha", "Buga", rand() % 9);
			pets.push_back(cat);
		}
		else {
			Parrot* parrot = new Parrot(i + 2, "Alex", "Bibo", i % 2 == 0 ? 0 : 1);
			pets.push_back(parrot);
		}
	}
	return pets;
}
