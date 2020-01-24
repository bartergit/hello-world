#pragma once
#include "stdafx.h"
#include "Node.h"
#include "Node.cpp"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Cat.h"
#include <iostream>
using namespace std;
int main()
{
	BinaryTree<Cat> tree;
	//float s, max;
	
	while (1) {
		cout << "\n1. Add element\n"
			<< "2. Print tree\n"
			<< "3. Find height of tree\n"
			<< "4. Find number of maximal element\n"
			<< "5. Exit\n";
		int k; cin >> k;
		switch (k) {
		case 1: {
			int age;
			char name[20];
			cout << "Enter cat's age: ";
			cin >> age;
			cout << "Enter cat's name: ";
			cin.ignore();
			gets_s(name);
			Cat cat(age, name);
			tree.push(cat);
		}
			break;
		case 2:
			system("cls");
			tree.inOrder();
			break;
		case 3:
			cout << endl << "height of tree: " << tree.height() << endl;
			break;
		//case 4:{
		//	Cat max = tree.max();
		//	cout << "max element: " << max.toString();// << max;
		//	cout << "\nnumber of maximal: " << tree.countMax(max) << endl;
		//	}
		//	break;
		case 5:
			exit(1);
		default:
			cout << "invalid number\n";
			system("pause");
			exit(1);
		}
	}
}

