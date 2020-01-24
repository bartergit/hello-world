#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "BinaryTree.h"

using namespace std;

template <class T>
BinaryTree<T>::BinaryTree() {
	this->root = nullptr;
}

template <class T>
void BinaryTree<T>::push(Node<T> *&p, T data) {
	if (p == nullptr) {
		p = new Node<T>(data);
	}
	else if (data.compare(p->data)<0) push(p->left, data);
	else push(p->right, data);
}

template <class T>
void BinaryTree<T>::push(T n) {
	push(this->root, n);
}

//template <class T>
//void BinaryTree<T>::print() {
//	this->print(this->root);
//}
//
//template <class T>
//void BinaryTree<T>::print(Node<T>* node) {
//	if (node != nullptr) {
//		print(node->left);
//		cout << node->data.toString() << endl;
//		print(node->right);
//	}
//}

template <class T>
int BinaryTree<T>::height(Node<T>* p) {
	int h1 = 0, h2 = 0, h;
	if (p) {
		if (p->left) h1 = height(p->left);
		if (p->right) h2 = height(p->right);
		h = h1 > h2 ? h1 : h2;
		return 1 + h;
	}
	return 0;
}
template <class T>
int BinaryTree<T>::height() {
	return height(this->root);
}

template <class T>
T BinaryTree<T>::max() {
	return max(this->root);
}
template <class T>
T BinaryTree<T>::max(Node<T> *p) {
	if (p->right != nullptr)  return max(p->right);
	else return p->data;
}
template <class T>
int BinaryTree<T>::countMax(T max) {
	return countMax(this->root, max);
}
template <class T>
int BinaryTree<T>::countMax(Node<T> *p, T max) {
	int count = 0;
	if (p != nullptr) {
		if (p->data == max)count++;
		count += countMax(p->left, max);
		count += countMax(p->right, max);
	}
	return count;
}
template <class T>
void BinaryTree<T>::clean(Node<T> *& node) {
	clean(node->left);
	clean(node->right);
	delete node;
}
template <class T>
void BinaryTree<T>::clean() {
	clean(this->root);
}
template <class T>
BinaryTree<T>::~BinaryTree() {
	clean();
}

template <class T>
void BinaryTree<T>::postOrder() {
	postOrder(this->root);
}
template <class T>
void BinaryTree<T>::postOrder(Node<T> * node) {
	if (node == nullptr) {
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	cout << node->data.toString() << endl;
}

template <class T>
void BinaryTree<T>::inOrder() {
	inOrder(this->root);
}

template <class T>
void BinaryTree<T>::inOrder(Node<T> * node) {
	if (node == nullptr) {
		return;
	}
	inOrder(node->left);
	cout << node->data.toString() << endl;
	inOrder(node->right);
}

template <class T>
void BinaryTree<T>::preOrder() {
	preOrder(this->root);
}
template <class T>
void BinaryTree<T>::preOrder(Node<T> * node) {
	if (node == nullptr) {
		return;
	}
	cout << node->data.toString() << endl;
	preOrder(node->left);
	preOrder(node->right);
}