// Магическийквадрат.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n, k = 2;
	cout << "Vvedite razmernost' matricy(nechotnoe chislo):" << endl;
	cin >> n;
	int **ptr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ptr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			ptr[i][j] = 0;
		}
	}
	int i = ((n - 1) / 2) - 1;
	int j = (n - 1) / 2;
	ptr[i][j] = 1;
	while (k <= n*n)
	{
		i--;
		if (i < 0)
		{
			i = n - 1;
		}
		j++;
		if (j == n)
		{
			j = 0;
		}
		if (ptr[i][j] > 0)
		{
			i--;
			j--;
			if (i < 0)
			{
				i = n - 1;
			}
			if (j < 0)
			{
				j = n - 1;
			}
		}
		ptr[i][j] = k;
		k++;
	}
	cout << "Magicheskij kvadrat:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << ptr[i][j];
		}
		cout << endl;
	}
	return 0;
}

