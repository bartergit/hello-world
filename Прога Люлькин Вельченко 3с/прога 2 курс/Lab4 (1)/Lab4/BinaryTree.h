#pragma once
#include "Node.h"

template <class T>
class BinaryTree
{
	Node<T> * root;
	void preOrder(Node<T> *);
	void postOrder(Node<T> *);
	void inOrder(Node<T> *);
	void clean(Node<T> *);
	int getLeavesCount(Node<T> *);

public:
	void add(int key, T value);
	void remove(int key);
	void inOrder();
	void preOrder();
	void postOrder();
	T find(int key);
	BinaryTree();
	~BinaryTree();
	void clean();
	int getLeavesCount();
};

