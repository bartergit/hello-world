#pragma once
#include "Node.h"

template <class T>
int Node<T>::getChildrenCount() {
	int count = 0;
	if (this->left != nullptr)
		count++;
	if (this->right != nullptr)
		count++;
	return count;
}
