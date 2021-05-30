// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, m, minmax, maxmin, index_i, index_j, x, y;
	cout << "Vvedite kolichestvo strok matricy:" << endl;
	cin >> n;
	cout << "Vvedite kolichestvo stolbtsov matricy:" << endl;
	cin >> m;
	cout << "Vvedite elementy matricy:" << endl;
	int **ptr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ptr[i] = new int[m];
		for (int j = 0; j < m; j++)
			cin >> ptr[i][j];
	}
	maxmin = -100000000;
	for (int i = 0; i < n; i++)
	{
		int min = ptr[i][0];
		for (int j = 1; j < m; j++)
		{
			if (ptr[i][j] < min)
			{
				 min = ptr[i][j];
			}
			x = min;	
		}
		if (maxmin < x)
		{
			maxmin = x;
			index_i = i;
		}
	}
	minmax = 1000000000;
	for (int j = 0; j < m; j++)
	{
		int max = ptr[0][j];
		for (int i = 1; i < n; i++)
		{
			if (ptr[i][j] > max)
			{
				 max = ptr[i][j];
			}
				y = max;
		}
		if (minmax > y)
		{
			minmax = y;
			index_j = j;
		}
	}
	if (minmax == maxmin)
	{
		cout << "Sedlovaja tochka:" << endl;
		cout << minmax << "(" << index_i << ", " << index_j << ")" << endl;
	}
	else 
		cout << "Sedlovoj tochki net" << endl;
	return 0;
}

