// Bashni.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n;
void show(vector <vector <int> > &bs, int n)
{
	for (int a = 1; a <= n; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			for (int k = 0; k < bs[b][n - a]; k++)
				cout << "*";
			for (int p = 0; p < n - bs[b][n - a] + 1; p++)
				cout << " ";
		}
		cout << endl;
	}
}
void hanoi(vector <vector <int> > &b, int from, int to, int razm)
{
	if (razm == 1)
	{
		int i = 0;
		while (b[to][i] != 0)
			i++;
		b[to][i] = 1;
		i = 0;
		while (b[from][i] != 1)
			i++;
		b[from][i] = 0;
		show(b, n);
	}
	else
	{
		hanoi(b, from, 3 - from - to, razm - 1);
		int i = 0;
		while (b[to][i] != 0)
			i++;
		b[to][i] = razm;
		i = 0;
		while (b[from][i] != razm)
			i++;
		b[from][i] = 0;
		show(b, n);
		hanoi(b, 3 - from - to, to, razm - 1);
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите количество колец" << endl;
	cin >> n;
	system("cls");
	vector <vector <int> > bs(3, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		bs[0][n - i] = i;
	}
	show(bs, n);
	cout << endl;
	hanoi(bs, 0, 2, n);
	system("pause");
    return 0;
}

