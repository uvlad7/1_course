// Magic_matrix.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите размер массива" << endl;
	cin >> n;
	if (n % 2 == 0)
		n++;
	int **p;
	p = new int*[n];
	for (int t = 0; t < n; t++)
		p[t] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;j < n;j++)
			p[i][j] = 0;
	}
	int i = (n - 1) / 2 - 1, j = (n - 1) / 2, num;
	p[i][j] = 1;
	for (num = 2; num <= n*n; num++)
	{
		i--;
		if (i == -1)
			i = n-1;
		j++;
		if (j == n)
			j = 0;
		while (p[i][j] != 0)
		{
			i--;
			if (i == -1)
				i = n - 1;
			j--;
			if (j == -1)
				j = n - 1;
		}
		p[i][j] = num;
		/*while ((i < 0) || (j < 0) || (i >= n) || (j >= n) || (p[i][j] != 0))
		{
			if (i < 0)
				i = n - 1;
			if (j < 0)
				j = n - 1;
			if (i >= n)
				i = 0;
			if (j >= n)
				j = 0;
			if (p[i][j] != 0)
			{
				i--;
				j--;
			}
		}
		p[i][j] = num;
		i--;
		j++;*/
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

