// Улитка.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n, k = 1;
	cout << "Vvedite razmernost' matricy:" << endl;
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
	int i = (n - 1) / 2;
	int j = (n - 1) / 2;
	ptr[i][j] = k;
	j++;
	k++;
	while (k <= n*n)
	{
		while (k <= n*n && ptr[i][j - 1] > 0)
		{
			ptr[i][j] = k;
			k++;
			i++;
		}
		while (k <= n*n && ptr[i - 1][j] > 0)
		{
			ptr[i][j] = k;
			k++;
			j--;
		}
		while (k <= n*n && ptr[i][j + 1] > 0)
		{
			ptr[i][j] = k;
			k++;
			i--;
		}
		while (k <= n*n && ptr[i + 1][j] > 0)
		{
			ptr[i][j] = k;
			k++;
			j++;
		}
	}
	cout << "Ulitka:" << endl;
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

