// 1.Создать шаблон класса для работы с бинарным деревом. 
// Приме¬нить его для сортировки действительных чисел и строк, вводимых с клавиатуры или из файла.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h> 
using namespace std;

void TreeForInt();
void TreeForString();

template<class T>
class Tree{
public:
	struct node
	{
		T data; 
		node*left, *right;
	};
	node * root;
	Tree() { root = 0; };
	void GetData();
	void CopyTree(node*&rootnew, node*rootold);
	Tree(const Tree&ob); 
	void DelTree(node *wer);
	~Tree() { DelTree(root); }
	void Push(node*&wer, T data);
	void Show(node*, int);   
	int Height(node *nd);
};

template<class T> void Tree<T>::GetData() {
	cout << "Введите количество узлов: ";
	T Data;
	int n;
	cin >> n;
	cout << endl<<"Введите данные: ";
	for (int i = 0; i < n; i++) {
		cin >> Data;
		Push(root, Data);
	}
}

template<class T> void Tree<T>::CopyTree(node*&rootnew, node*rootold){
	if (rootold->left != 0){
		Push(rootnew, (rootold->left)->data); 
		CopyTree(rootnew, rootold->left);
	}
	if (rootold->right != 0){
		Push(rootnew, (rootold->right)->data); 
		CopyTree(rootnew, rootold->right);
	}
}

template<class T>Tree<T>::Tree(const Tree&ob){
	if (ob.root == 0)root = 0;
	else {
		root = new node;
		root->data = ob.root->data;
		root->left = 0;
		root->right = 0;
		CopyTree(root, ob.root);
	}
}

template<class T>int Tree<T>::Height(node* nd) {
	node *temp = nd;
	int h1 = 0, h2 = 0, h = 0;
	if (nd != 0) {
		if (nd->left) { h1 = Height(nd->left); }
		if (nd->right) { h2 = Height(nd->right); }
		if (h1 >= h2)	h = h1 + 1;
		else h = h2 + 1;
	}
	return h;
}

template<class T> void Tree<T>::DelTree(node *wer){
	if (!wer) {
		delete wer;
		DelTree(wer->left);
		DelTree(wer->right);
	}
}

template<class T> void Tree<T>::Push(node*&wer, T data){
	if (wer == 0){
		wer = new node;
		wer->data = data;
		wer->left = 0; wer->right = 0;
	}
	else if (data < wer->data) Push(wer->left, data);
	else if (data > wer->data) Push(wer->right, data);
}

template<class T> void Tree<T>::Show(node*nd, int level){
	if (nd)
	{
		Show(nd->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << nd->data << endl;
		Show(nd->right, level + 1);
	}
}

void TreeForInt() {
	int ht;
	Tree<double>IntT;
	IntT.GetData();
	ht = IntT.Height(IntT.root);
	IntT.Show(IntT.root, ht);
}

void TreeForString() {
	int ht;
	Tree <string> StrT;
	StrT.GetData();
	ht = StrT.Height(StrT.root);
	StrT.Show(StrT.root, ht);
}

//-------------------------------- MAIN ----------------------------------------
int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "1. Числовое бинарное дерево" << endl << "2. Строковое бинарное дерево" << endl << "3. Выход" << endl;
	int number;
	while (1) {
		cout << "Введите номер пункта: ";
		cin >> number;
		switch (number) {
			case 1: {
				TreeForInt();
				break;
			}
			case 2: {
				TreeForString();
				break;
			}
			case 3: {
				exit(0);
			}
		}
	}
	system("pause");
	return 0;
}

