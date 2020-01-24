#pragma once

template <class T>
class Node
{
	int key;
	T value;
	Node<T> * left = nullptr;
	Node<T> * right = nullptr;
public:
	Node<T>(int key, T value) {
		this->key = key;
		this->value = value;
	};

	int getKey() { return this->key; }
	T getValue() { return this->value; }
	Node<T> * getLeftChild() { return this->left; }
	Node<T> * getRightChild() { return this->right; }
	void setLeftChild(Node<T> * node) { this->left = node; }
	void setRightChild(Node<T> * node) { this->right = node; }
	int getChildrenCount();
};

