// Lotereia.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct prize
{
	char name[25];
	int cost;
};
istream& operator >> (istream &in, prize &item)
{
	int num;
	in >> num >> item.name >> item.cost;
	return in;
}
struct node
{
	int key;
	int info;
	node *left = NULL;
	node *right = NULL;
};
node *winners = NULL;
int static col_nodes = 0;
void add(int k, int in)
{
	node *temp = new node;
	temp->key = k;
	temp->info = in;
	temp->left = temp->right = NULL;
	if (winners == NULL)
	{
		winners = temp;
	}
	else
	{
		node *tek = winners;
		node *prev = NULL;
		while (tek != NULL)
		{
			prev = tek;
			if (k > tek->key)
				tek = tek->right;
			else
				tek = tek->left;
		}
		if (k > prev->key)
			prev->right = temp;
		else
			prev->left = temp;
	}
	col_nodes++;
}
void deltree(node *tree)
{
	if (tree != NULL)
	{
		deltree(tree->left);
		deltree(tree->right);
		delete tree;
	}
	col_nodes = 0;
}
node* find(int k)
{
	node *temp = winners;
	while ((temp != NULL) && (temp->key != k))
	{
		if (k > temp->key)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return temp;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("Winners.txt");
	prize *gainings = new prize[100];
	int num;
	int i;
	for (i = 0; !fin.eof(); i++)
	{
		fin >> num;
		add(num, i);
		fin >> gainings[i];
	}
	fin.close();
	cout << "Введите номер билета: ";
	cin >> num;
	node *gain = find(num);
	if (gain)
		cout << "Вы выиграли " << gainings[gain->info - 1].name << " стоимостью " << gainings[gain->info - 1].cost << endl;
	else cout << "Вы выиграли огромное ничего." << endl;
	int q;
	cout << "Желаете проверить другие билеты? 1 — да, 2 — нет." << endl;
	cin >> q;
	while (q == 1)
	{
		cout << "Введите номер билета: ";
		cin >> num;
		gain = find(num);
		if (gain)
			cout << "Вы выиграли " << gainings[gain->info - 1].name << " стоимостью " << gainings[gain->info - 1].cost << endl;
		else cout << "Вы выиграли огромное ничего." << endl;
		cout << "Желаете проверить другие билеты?" << endl;
		cin >> q;
	}
	deltree(winners);
	system("pause");
    return 0;
}

