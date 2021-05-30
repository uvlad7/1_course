// Суммаэлементовмеждудиагоналямисверху.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, S = 0;
	cout << "Vvedite razmernost' matricy:" << endl;
	cin >> n;
	cout << "Vvedite elementy matricy:" << endl;
	int **ptr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ptr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> ptr[i][j];
		}
	}
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = i; j < n - j; j++)
		{
			if (j == n - j - 1)
			{
				S += ptr[i][j];
			}
			else
			{
				S += ptr[i][j] + ptr[i][n - j - 1];
			}
		}
	}
	cout << "Summa elementov matricy = " << S << endl;
	return 0;
}



