#include <iostream>

using namespace std;

struct node
{
	int n; //информационное поле узла дерева
	int count;
	node*left, *right;
};
class Tree
{
public:
	node*root;
	Tree() { root = 0; }
	Tree(int t); // Формирование дерева из t случайных чисел	
	void CopyTree(node*&rootnew, node*rootold);
	/* Копирует дерево с корнем rootold в дерево с  корнем rootnew. В результате деревья находятся в различных динамических участках памяти.*/
	Tree(const Tree&ob); //конструктор копирования
  // Рекурсивная функция, используемая в деструкторе (освобождение памяти)
	void DelTree(node *wer);
	~Tree() { DelTree(root); }
	void Push(node*&wer, int data);// Вставка элемента в дерево
	void Look(node*wer);          //- Вывод дерева на экран
	node*Find(node*wer, int key);  // Поиск по ключу
	void PrintLeaves(node *wer);  // Вывод листьев дерева на экран
	int Node_Height(const node* p) {
		int l, r, h = 0;
		if (p != NULL) {
			l = Node_Height(p->left);
			r = Node_Height(p->right);
			h = ((l > r) ? l : r) + 1;
		}
		return h;
	}
	void print_Tree(node *p, int level)
	{
		if (p)
		{
			print_Tree(p->left, level + 1);
			for (int i = 0; i < level; i++) cout << "   ";
			cout << p->n << endl;
			print_Tree(p->right, level + 1);
		}
	}
};
//********************** Tree::Tree(int t) *******************
Tree::Tree(int t)
{
	root = 0;
	for (int i = 0; i < t; i++)
		Push(root, rand() % 10 - 5);
}
void Tree::CopyTree(node*&rootnew, node*rootold)
{
	if (rootold->left != 0)
	{
		Push(rootnew, (rootold->left)->n); CopyTree(rootnew, rootold->left);
	}
	if (rootold->right != 0)
	{
		Push(rootnew, (rootold->right)->n); CopyTree(rootnew, rootold->right);
	}
}
Tree::Tree(const Tree&ob)
{
	if (ob.root == 0)root = 0;
	else {
		root = new node;
		root->n = ob.root->n;
		root->count = 1;
		root->left = 0;
		root->right = 0;
		CopyTree(root, ob.root);
	}
}
void Tree::DelTree(node *wer)
{
	if (wer->left != 0)DelTree(wer->left);
	if (wer->right != 0)DelTree(wer->right);
	delete wer;
}
void Tree::Push(node*&wer, int data)
{
	if (wer == 0)
	{
		wer = new node;
		wer->n = data;
		wer->left = 0; wer->right = 0;
		wer->count = 1;
	}
	else if (data < wer->n)Push(wer->left, data);
	else if (data > wer->n)Push(wer->right, data);
	else wer->count++;
}
void Tree::Look(node*wer)
{
	if (wer != 0)
	{
		Look(wer->left);
		cout << "Number: " << wer->n << " - " << wer->count;
		cout << endl;
		Look(wer->right);
	}
}
node* Tree::Find(node*wer, int key)
{
	if (wer == 0) return 0;
	else if (key < wer->n) return Find(wer->left, key);
	else if (key > wer->n) return Find(wer->right, key);
	else return wer;
}
void Tree::PrintLeaves(node *wer)
{
	if (wer == 0)return;
	else if ((wer->left == 0) && (wer->right == 0)) {
		cout << "Number: " << wer->n << " - " << wer->count;
		cout << endl;
	}
	else
	{
		PrintLeaves(wer->left);
		PrintLeaves(wer->right);
	}
}
//-------------------------------- MAIN ----------------------------------------
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	Tree tr;
	node *u = NULL;
	int k = 0, ht;
	int n, max = -INT_MAX, cnt;
	int lvl = 1;
	while (1) {
		cout << "choose operation" << endl;
		cin >> n;
		switch (n)
		{
		case 0: {
			int data;
			cout << "How much do you want to insert?" << endl;
			int t;
			cin >> t;
			for (int g = 0; g < t; g++)
			{
				cout << "Insert number" << endl;
				cin >> data;
				tr.Push(tr.root, data);
				if (data == max)
				{
					cnt++;
				}
				if (data > max)
				{
					max = data;
					cnt = 1;
				}
				lvl++;
			}
			ht = tr.Node_Height(tr.root);
			k = 0;
			break;
		}
		case 1: {
			if (tr.root == 0)cout << "Tree is empty" << endl;
			else
			{
				cout << "Our Tree:" << endl;
				tr.Look(tr.root);
			}
			k = 1; break;
		}
		case 2: {
			if (tr.root == 0)cout << "Tree is empty" << endl;
			else
			{
				int key;
				cout << "Insert required number" << endl;
				cin >> key;
				if ((u = tr.Find(tr.root, key)) != 0) {
					cout << "Elements: " << endl;
					cout << key;
					cout << " found ";
					cout << u->count << " leaves" << endl;
				}
				else cout << "No such elements" << endl;
			}
			k = 2; break;
		}
		case 3: {
			if (tr.root == 0)cout << "Tree is empty" << endl;
			else {
				cout << "Leaves:" << endl;
				tr.PrintLeaves(tr.root);
			}
			k = 3; break;
		}
		case 4:
		{
			cout << "Maximum element: " << max << endl;
			cout << "Number of maximum elements: " << cnt << endl;
			break;
		}
		case 5:
		{
			if (tr.root == 0)cout << "Tree is empty" << endl;
			else
			{
				cout << "Height: " << ht << endl;
				break;
			}
		}
		case 6:
		{
			if (tr.root == 0)cout << "Tree is empty" << endl;
			else
			{
				tr.print_Tree(tr.root, ht);
				break;
			}
		}
		case 9: {
			exit(0);
		}
		}
	}
	system("pause");
	return 0;
}