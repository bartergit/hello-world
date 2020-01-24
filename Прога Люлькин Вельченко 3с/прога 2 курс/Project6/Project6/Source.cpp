#include <iostream>
using namespace std;
struct node
{
	double n;
	node*left, *right;
};
class Tree
{
public:
	node*root;
	Tree() { root = 0; }
	void DelTree(node *wer);
	~Tree() { DelTree(root); }
	void print(node *nd, int level);
	void Push(node*&wer, double data);
	double Height(node *nd);
};
void Tree::DelTree(node *wer)
{
	if (wer->left != 0)DelTree(wer->left);
	if (wer->right != 0)DelTree(wer->right);
	delete wer;
}
void Tree::Push(node*&wer, double data)
{
	if (wer == 0)
	{
		wer = new node;
		wer->n = data;
		wer->left = 0; wer->right = 0;
	}
	else if (data <= wer->n)Push(wer->left, data);
	else if (data > wer->n)Push(wer->right, data);
}

void Tree::print(node* nd, int level) {
	if (nd)
	{
		print(nd->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << nd->n << endl;
		print(nd->right, level + 1);
	}
}

double Tree::Height(node* nd) {
	node *temp = nd;
	double h1 = 0, h2 = 0, h = 0;
	if (nd != 0) {
		if (nd->left) { h1 = Height(nd->left); }
		if (nd->right) { h2 = Height(nd->right); }
		if (h1 >= h2)
		{
			h = h1 + 1;
		}
		else
		{
			h = h2 + 1;
		}
	}
	return h;
}

int main(double argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	Tree tr;
	double k = 0, ht = 0;
	double max = -INT_MAX, count = 0;
	int n;
	double lvl = 1;
	while (1) {
		cout << "Выберите операцию" << endl;
		cin >> n;
		switch (n)
		{
		case 0: {
			double data;
			cout << "Сколько элементов будет?" << endl;
			double t;
			cin >> t;
			cout << "Введите числа" << endl;
			for (double g = 0; g < t; g++)
			{
				cin >> data;
				tr.Push(tr.root, data);
				if (data == max)
				{
					count++;
				}
				if (data > max)
				{
					max = data;
					count = 1;
				}
				lvl++;
			}
			ht = tr.Height(tr.root);
			k = 0;
			break;
		}
		case 1:
		{
			cout << "Максимальный элемент: " << max << endl;
			cout << "Количество максимальных элементов: " << count << endl;
			break;
		}	
		case 2:
		{
			if (tr.root == 0)cout << "Дерево пустое" << endl;
			else
			{
				cout << "Высота равна " << ht << endl;
				break;
			}
		}
		case 3:
		{
			tr.print(tr.root, ht); 
			break;
		}
		case 4: {
			exit(0);
		}
		}
	}
	system("pause");
	return 0;
}