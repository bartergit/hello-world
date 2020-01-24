#include "Item.h"

void Item::take() {
	if (this->isAvailable)
		this->isAvailable = false;
	else
		cout << "can't take. it is alerady taken" << endl;
}

void Item::refund() {
	if (!this->isAvailable)
		this->isAvailable = true;
	else
		cout << "can't refund. it is not taken" << endl;
}

void Item::show() {
	if (isAvailable)
		cout << "status: available" << endl;
	else
		cout << "status: not available" << endl;
}