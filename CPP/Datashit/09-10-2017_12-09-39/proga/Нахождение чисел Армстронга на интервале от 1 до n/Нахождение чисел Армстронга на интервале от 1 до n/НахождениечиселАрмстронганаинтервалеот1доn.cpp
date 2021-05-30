// НахождениечиселАрмстронганаинтервалеот1доn.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, l = 0, i = 1;
	cout << "Vvedite chislo:" << endl;
	cin >> n;
	int *a = new int[l];
	cout << "Chisla Armstronga:" << endl;
	while (i < n)
	{
		int l = 0;
		int k = i;
		while (k != 0)
		{
			k = k / 10;
			l++;
		}
		int f = i;
		for (int j = 0; j < l; j++)
		{
			int h = f;
			f %= 10;
			a[j] = f;
			f = h / 10;
		}
		for (int j = 0; j < l; j++)
		{
			int s = 1;
			for (int m = 1; m <= l; m++)
			{
				s *= a[j];
			}
			a[j] = s;
		}
		int sum = 0;
		for (int j = 0; j < l; j++)
		{
			sum += a[j];
		}
		if (i == sum)
		{
			cout << sum << endl;
		}
		i++;
	}
	return 0;
}