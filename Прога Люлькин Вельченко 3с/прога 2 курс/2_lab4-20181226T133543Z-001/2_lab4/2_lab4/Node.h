#pragma once

template <class T>
class Node {
public:
	T data;
	Node<T> *left;
	Node<T> *right;
	Node();
	Node(T);
};