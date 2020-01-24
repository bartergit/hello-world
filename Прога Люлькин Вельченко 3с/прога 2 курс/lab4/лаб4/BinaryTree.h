#pragma once

#include "Node.h"

template <class T>
class BinaryTree {
	Node<T> *root;
	void push(Node<T> *&, T);
	//void print(Node<T> *);
	int height(Node<T> *);
	void clean(Node<T> *&);
	T max(Node<T>*);
	int countMax(Node<T>*, T);
	void postOrder(Node<T> *);
	void inOrder(Node<T> *);
	void preOrder(Node<T> *);
public:
	BinaryTree();
	void push(T);
	//void print();
	int height();
	void clean();
	T max();
	int countMax(T);
	~BinaryTree();
	void postOrder();
	void inOrder();
	void preOrder();
};
//#include "BinaryTree.cpp"