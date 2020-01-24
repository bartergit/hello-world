#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Chair.h"

using namespace std;

void menu() {
	BinaryTree<Chair> bt;

	int key,value;
	cout << "enter 1 to add node" << endl;
	cout << "enter 2 to find node" << endl;
	cout << "enter 3 to get leaves count" << endl;
	cout << "enter 4 to preorder" << endl;
	cout << "enter 5 to postorder" << endl;
	cout << "enter 6 to in order" << endl;
	int choise;
	while (true) {
		cin >> choise;
		switch (choise) {
		case 1:
			cout << "enter key: ";
			cin >> key;
			cout << "enter legs number: ";
			cin >> value;
			break;
		case 2:
			cout << "enter key: ";
			cin >> key;
			try{
				cout << bt.find(key).legs << endl;
			}
			catch (int i) {
				cout << "key not found!" << endl;
			}
			
			break;
	//	case 3:
	//		cout << "leaves count: " << bt.getLeavesCount() << endl;
	//		break;
		case 4:
			bt.preOrder();
			break;
		case 5:
			bt.postOrder();
			break;
		case 6:
			bt.inOrder();
			break;
		default:
			cout << "enter 1 to add node" << endl;
			cout << "enter 2 to find node" << endl;
			cout << "enter 3 to get leaves count" << endl;
			cout << "enter 4 to preorder" << endl;
			cout << "enter 5 to postorder" << endl;
			cout << "enter 6 to in order" << endl;
			break;
		}
	}
}

void main() {
	menu();
	system("pause");
}