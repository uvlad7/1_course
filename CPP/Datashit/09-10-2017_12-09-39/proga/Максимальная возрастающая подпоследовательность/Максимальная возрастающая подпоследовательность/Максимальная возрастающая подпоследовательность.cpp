// Максимальная возрастающая подпоследовательность.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, k = 0;
	cout << "Vvedite kolichestvo chisel v posledovatelnosti:" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "Vvedite posledovatelnost chisel:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int l = 1;
	int lmax = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] < a[i + 1])
		{
			l++;
			if ((i + 1) == n - 1 && lmax < l)
			{
				lmax = l;
				k = i + 1;
			}
		}
		else
		{
			if (lmax < l)
			{
				lmax = l;
				k = i;
			}
			l = 1;
		}
	}
	cout << "Maksimalnaja po dline vozrastaushchaja podposledovatelnost:" << endl;
	if (n == 1)
	{
		cout << a[k] << endl;
	}
	for (int i = k - lmax + 1; i <= k; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}



