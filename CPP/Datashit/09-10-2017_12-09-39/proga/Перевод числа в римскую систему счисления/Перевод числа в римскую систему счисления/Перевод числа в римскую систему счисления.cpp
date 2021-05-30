// Перевод числа в римскую систему счисления.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int f, n, k = 0, p = 10, g;
	cout << "Vvedite chislo ot 1 do 3999:" << endl;
	cin >> n;
	char a[] = { 'M','C','X','I','D','L','V' };
	int c[] = { 1000, 100, 10, 1 };
	int b[4];
	int x = n;
	while (n != 0)
	{
		n = n / 10;
		k++;
	}
	int l = k;
	while (l != 0)
	{
		int v = x;
		x %= 10;
		b[l - 1] = x;
		x = v / 10;
		l--;
	}
	cout << "Poluchennoe chislo:" << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 3; j > -1 + i; j--)
		{
			f = b[i] * pow(p, (k - i - 1)) / c[j];
			if (f == 9)
			{
				cout << a[j] << a[j - 1];
			}
			if (f > 4 && f < 9)
			{
				g = f % 5;
				cout << a[j + 3];
				for (int t = 0; t < g; t++)
				{
					cout << a[j];
				}
			}
			if (f == 4)
			{
				cout << a[j] << a[j + 3];
			}
			if (f > 0 && f < 4)
			{
				g = (f + 5) % 5;
				for (int t = 0; t < g; t++)
				{
					cout << a[j];
				}
			}
		}
	}
	cout << endl;
	return 0;
}



