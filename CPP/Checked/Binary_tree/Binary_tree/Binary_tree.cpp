// Binary_tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct node
{
	int key;
	int info;
	node *left = NULL;
	node *right = NULL;
};
node *tree = NULL;
node **leaves, **nodes;
int col_nodes = 0;
int  numleave, numnode;
void add(int k, int in)
{
	node *temp = new node;
	temp->key = k;
	temp->info = in;
	temp->left = temp->right = NULL;
	if (tree == NULL)
	{
		tree = temp;
	}
	else
	{
		node *tek = tree;
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
void get(istream& in)
{
	int key, inf;
	in >> key >> inf;
	add(key, inf);

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
	node *temp = tree;
	while ((temp != NULL) && (temp->key != k))
	{
		if (k > temp->key)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return temp;
}
void delnode(int k)
{
	node *tek = tree, *prev = NULL;
	while ((tek != NULL) && (tek->key != k))
	{
		prev = tek;
		if (k > tek->key)
			tek = tek->right;
		else
			tek = tek->left;
	}
	if (tek != NULL)
	{
		if (prev != NULL)
		{
			if ((tek->right != NULL) && (tek->left != NULL))
			{
				node *tekn = tek->right, *prevn = tek;
				while (tekn->left != NULL)
				{
					prevn = tekn;
					tekn = tekn->left;
				}
				prevn->left = tekn->right;
				if (k > prev->key)
					prev->right = tekn;
				else
					prev->left = tekn;
				tekn->left = tek->left;
				tekn->right = tek->right;
			}
			else
			{
				if (k > prev->key)
				{
					if (tek->left != NULL)
						prev->right = tek->left;
					else
						prev->right = tek->right;
				}
				else
				{
					if (tek->left != NULL)
						prev->left = tek->left;
					else
						prev->left = tek->right;
				}
			}
		}
		else
		{
			if ((tek->right != NULL) && (tek->left != NULL))
			{
				node *tekn = tek->right, *prevn = tek;
				while (tekn->left != NULL)
				{
					prevn = tekn;
					tekn = tekn->left;
				}
				prevn->left = tekn->right;
				tree = tekn;
				tekn->left = tek->left;
				tekn->right = tek->right;
			}
			else
			{
				if (tek->left != NULL)
					tree = tek->left;
				else
					tree = tek->right;
			}
		}
		delete tek;
		col_nodes--;
	}
}
ostream& operator << (ostream& out, node *tree)
{
	if (tree != NULL)
	{
		out << tree->left;
		out << tree->key << " " << tree->info << endl;
		out << tree->right;
	}
	return out;
}
void show(ostream& out, node *tree)
{
	if (tree != NULL)
	{
		out << tree->key << " " << tree->info << endl;
	}
	else out << "NULL" << endl;
}
int height(node *tree)
{
	if (tree != NULL)
	{
		return max(height(tree->left), height(tree->right)) + 1;
	}
	else
		return 0;
}
void find_leaves(node *tree)
{
	if (tree != NULL)
	{
		find_leaves(tree->left);
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			leaves[numleave] = tree;
			numleave++;
		}
		find_leaves(tree->right);
	}
}
void find_nodes(node *tree, int k)
{
	if ((tree != NULL) && (k > 0))
	{
		find_nodes(tree->left, k - 1);
		if (k == 1)
		{
			nodes[numnode] = tree;
			numnode++;
		}
		find_nodes(tree->right, k - 1);
	}
}

int main()
{
	/*add(4, 42143);
	add(3, 33234);
	add(5, 51233);
	add(1, 11233);
	add(2, 21331);
	add(8, 12345);
	add(0, 32453);
	add(7, 324234);*/
	int n;
	ifstream fin("input.txt");
	while (!fin.eof())
	{
		fin >> n;
		add(n, n);
	}
	cout << tree;
	/*show(cout, find(5));
	delnode(3);
	cout << tree;*/
	leaves = new node*[col_nodes / 2];
	numleave = 0;
	find_leaves(tree);
	nodes = new node*[col_nodes / 2];
	numnode = 0;
	find_nodes(tree, 3);
	for (int i = 0; i < numleave; i++)
		cout << leaves[i]->key << " ";
	cout << endl;
	for (int i = 0; i < numnode; i++)
		cout << nodes[i]->key << " ";
	cout << endl;
	cout << height(tree) << endl;
	system("pause");
	return 0;
}