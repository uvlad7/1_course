// Ulitka.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int size, n;
	cout << "¬ведите размер массива" << endl;
	cin >> n;
	size = n;
	int num = n*n;
	int **p;
	p = new int*[n];
	for (int t = 0; t < n; t++)
		p[t] = new int[n];
	for (int c = 0; size > 0; c++)
	{
		int i, j;
		for (i = 0; i < size; i++)
		{
			p[c][c + i] = num;
			num--;
		}
		i--;
		for (j = 1; j < size; j++)
		{
			p[c + j][c + i] = num;
			num--;
		}
		j--;
		for (i = size - 2; i >= 0; i--)
		{
			p[c + j][c + i] = num;
			num--;
		}
		i++;
		for (j = size - 2; j > 0; j--)
		{
			p[c + j][c + i] = num;
			num--;
		}
		size -= 2;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;j < n;j++)
			cout << p[i][j] << "\t";
		cout << endl;
	}
	for (int t = 0; t < n; t++)
		delete[] p[t];
	delete[] p;
	system("pause");
    return 0;
}

