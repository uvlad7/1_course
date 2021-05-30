// Haffman.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <windows.h>
#include <map>
#include <bitset>
using namespace std;

struct node
{
	int key;
	char info = 0;
	node *left = NULL;
	node *right = NULL;
};

void show(ostream& out, node *tree)
{
	if (tree != NULL)
	{
		if (tree->info)
			out << tree->info << " : " << tree->key << endl;
		else
		{
			show(out, tree->left);
			show(out, tree->right);
		}
	}
}

void showcod(ostream& out, node *tree, string code)
{
	if (tree != NULL)
	{
		if (tree->info)
			out << tree->info << " : " << code << endl;
		else
		{
			showcod(out, tree->left, code + "0");
			showcod(out, tree->right, code + "1");
		}
	}
}

string cod(char symb, node *tree, string code)
{
	if (tree != NULL)
	{
		if (tree->info)
		{
			if (tree->info == symb)
				return code;
			else return "-1";
		}
		else
		{
			string temp;
			temp = cod(symb, tree->left, code + "0");
			if (temp != "-1")
				return temp;
			else
				temp = cod(symb, tree->right, code + "1");
			return temp;
		}
	}
}

class mycomp
{
public:
	bool operator()(const node *a, const node *b)
	{
		return (a->key > b->key);
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	string text, buf;
	ifstream fin("input.txt");
	getline(fin, buf);
	fin.close();
	text = buf;
	priority_queue <node*, vector<node*>, mycomp> sTable;
	int col;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i])
		{
			col = 1;
			for (int j = i + 1; j < text.length(); j++)
				if (text[i] == text[j])
				{
					col++;
					text[j] = 0;
				}

			node *temp = new node;
			temp->info = text[i];
			temp->key = col;
			sTable.push(temp);
		}
	}

	node *tree = new node;
	while (!sTable.empty())
	{
		node *temp1, *temp2, *temp;
		temp1 = sTable.top();
		sTable.pop();
		if (!sTable.empty())
		{
			temp2 = sTable.top();
			sTable.pop();
			temp = new node;
			temp->left = temp1;
			temp->right = temp2;
			temp->key = temp1->key + temp2->key;
			sTable.push(temp);
		}
		else
			tree = temp1;
	}

	show(cout, tree);
	cout << endl;
	system("pause");
	system("cls");
	showcod(cout, tree, "");
	cout << endl;
	system("pause");
	system("cls");
	string code;
	for (int i = 0; i < buf.length(); i++)
		code += cod(buf[i], tree, "");
	//ofstream fout("output.txt");
	string sbite, bcode;
	char cbite;
	for (int i = 0; i < code.length(); i += 8)
	{
		sbite = code.substr(i, 8);
		while (sbite.length() != 8)
			sbite += "0";
		bitset<8> bite(sbite);
		cbite = bite.to_ulong();
		//fout << cbite;
		bcode += cbite;
	}
	//fout << code;
	//fout.close();
	cout << bcode;
	cout << endl;
	cout << endl;
	system("pause");
	system("cls");
	//ifstream finout("output.txt");
	node *tek = tree;
	char j;
	//while (!finout.eof())
	for (int l = 0; l < bcode.length(); l++)
	{
		/*finout >> j;
		if (j == '1')
		tek = tek->right;
		else tek = tek->left;
		if (tek->info)
		{
		cout << tek->info;
		tek = tree;
		}*/
		//finout >> cbite;
		cbite = bcode[l];
		for (int i = 0; i < 8; i++)
		{
			j = 1;
			j = j << (7 - i);
			if (cbite & j)
				tek = tek->right;
			else tek = tek->left;
			if (tek->info)
			{
				cout << tek->info;
				tek = tree;
			}
		}
	}
	cout << endl;
	system("pause");
	system("cls");
	return 0;
}