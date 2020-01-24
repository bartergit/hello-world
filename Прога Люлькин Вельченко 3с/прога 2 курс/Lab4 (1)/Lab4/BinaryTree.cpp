#pragma once

#include "BinaryTree.h"
#include <iostream>
using namespace std;


/*BinaryTree::BinaryTree(Node * root)
{
	this->root = root;
}*/
template <class T>
BinaryTree<T>::BinaryTree()
{
	this->root = nullptr;
}

template <class T>
void BinaryTree<T>::add(int key, T value) {
	Node<T> * node = new Node<T>(key, value);
	if (this->root == nullptr)
		this->root = node;
	else {
		int key = node->getKey();
		Node<T> * currentNode = this->root;
		Node<T> * temp;
		while (true) {
			if (key > currentNode->getKey()) {
				temp = currentNode->getRightChild();
				if (temp == nullptr) {
					currentNode->setRightChild(node);
					break;
				}
			}
			else {
				temp = currentNode->getLeftChild();
				if (temp == nullptr) {
					currentNode->setLeftChild(node);
					break;
				}
			}

			currentNode = temp;
		
		}
		
	}
}

template <class T>
T BinaryTree<T>::find(int key) {
	Node<T> * currentNode = this->root;
	
		while (true) {
			if (currentNode == nullptr)
				throw(1);
			if (key == currentNode->getKey())
				return currentNode->getValue();
			if (key > currentNode->getKey())
				currentNode = currentNode->getRightChild();
			else
				currentNode = currentNode->getLeftChild();
		}

	
}

template <class T>
void BinaryTree<T>::remove(int key) {
	if (this->find(key) == NULL) {
		cout << "key not found" << endl;
		return;
	}
	Node<T> * parent = this->root;
	Node<T> * currentNode = parent;
	Node<T> * replace;
	bool isLeft = false;
	while (true) {

		if (key == currentNode->getKey()) {
			break;
		}
		parent = currentNode;
		if (key > parent->getKey()) {
			isLeft = false;
			currentNode = parent->getRightChild();
		}
		else {
			currentNode = parent->getLeftChild();
			isLeft = true;
		}
	}
	if (currentNode->getChildrenCount() == 0) { //has no children
		if (currentNode == this->root) {
			this->root = nullptr;
			return;
		}
		if (isLeft)
			parent->setLeftChild(nullptr);
		else
			parent->setRightChild(nullptr);
	}
	else if (currentNode->getChildrenCount() == 1) { // has one child

		if (currentNode->getLeftChild() != nullptr) {
			replace = currentNode->getLeftChild();
			if (currentNode == this->root) {
				this->root = replace;
				return;
			}
			if (isLeft)
				parent->setLeftChild(replace);
			else
				parent->setRightChild(replace);

		}
		else {
			replace = currentNode->getRightChild();
			if (currentNode == this->root) {
				this->root = replace;
				return;
			}
			if (isLeft)
				parent->setLeftChild(replace);
			else
				parent->setRightChild(replace);
		}
			
	}
	else {
		Node<T> * left = currentNode->getLeftChild();
		Node<T> * right = currentNode->getRightChild();
		Node<T> * replace = right;
		while (replace->getLeftChild() != nullptr) {
			replace = replace->getLeftChild();
		}
		if(replace != left)
		replace->setLeftChild(left);
		if (replace != right)
		replace->setRightChild(right);
		if (currentNode == this->root) {
			this->root = replace;
			return;
		}
		if (isLeft)
			parent->setLeftChild(replace);
		else
			parent->setRightChild(replace);
	}
}

template <class T>
void BinaryTree<T>::preOrder(Node<T> * node) {
	if (node != nullptr) {
		preOrder(node->getLeftChild());
		cout << "key: " << node->getKey() << " value: " << node->getValue().legs << endl;
		preOrder(node->getRightChild());
	}
}

template <class T>
void BinaryTree<T>::preOrder() {
	cout << "root: " << this->root->getKey() << endl;
	preOrder(this->root);
}

template <class T>
void BinaryTree<T>::inOrder(Node<T> * node) {
	if (node != nullptr) {
		cout << "key: " << node->getKey() << " value: " << node->getValue().legs << endl;
		inOrder(node->getLeftChild());
		inOrder(node->getRightChild());
	}
}

template <class T>
void BinaryTree<T>::inOrder() {
	cout << "root: " << this->root->getKey() << endl;
	inOrder(this->root);
}

template <class T>
void BinaryTree<T>::postOrder(Node<T> * node) {
	if (node != nullptr) {
		postOrder(node->getRightChild());
		cout << "key: " << node->getKey() << " value: " << node->getValue().toString() << endl;
		postOrder(node->getLeftChild());
	}
}

template <class T>
void BinaryTree<T>::postOrder() {
	cout << "root: " << this->root->getKey() << endl;
	postOrder(this->root);
}

template <class T>
int BinaryTree<T>::getLeavesCount() {
	return getLeavesCount(this->root);
}

template <class T>
int BinaryTree<T>::getLeavesCount(Node<T> * node) {
	int count = 0;
	if (node != nullptr) {
		if (node->getChildrenCount() == 0) {
			count++;
		}
		if (node->getLeftChild()!= nullptr) {
			count += getLeavesCount(node->getLeftChild());
		}
		if (node->getRightChild() != nullptr) {
			count += getLeavesCount(node->getRightChild());
		}
	}
	return count;
}

template <class T>
void BinaryTree<T>::clean() {
	clean(this->root);
}
template <class T>
void BinaryTree<T>::clean(Node<T> * node) {
	if (node != nullptr) {
		clean(node->getLeftChild());
		clean(node->getRightChild());
		delete node;
	}
}
template <class T>
BinaryTree<T>::~BinaryTree() {
	clean();
}