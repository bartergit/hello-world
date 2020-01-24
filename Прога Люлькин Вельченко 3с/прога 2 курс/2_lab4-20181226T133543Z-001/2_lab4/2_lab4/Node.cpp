#include "stdafx.h"
#include "Node.h"

template <class T>
Node<T>::Node() {
	this->left = nullptr;
	this->right = nullptr;
}

template <class T>
Node<T>::Node(T data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}
