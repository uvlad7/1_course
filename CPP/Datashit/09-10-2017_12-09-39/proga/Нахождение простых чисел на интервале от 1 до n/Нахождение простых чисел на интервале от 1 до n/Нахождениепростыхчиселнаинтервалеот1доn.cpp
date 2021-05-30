// Нахождениепростыхчиселнаинтервалеот1доn.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, k = 0, f;
	cout << "Vvedite chislo:" << endl;
	cin >> n;
	int *ptr = new int[n];
	int *a = new int[k];
	for (int i = 0; i < n; i++)
		ptr[i] = i + 1;
	cout << "Prostye chisla:" << endl;
	for (int i = 1; i < n; i++)
	{
		int k = 0;
		if (ptr[i] != 0)
		{
			a[k] = ptr[i];
			k++;
			f = ptr[i];
			for (int m = 0; m < n / f; m++)
			{
				ptr[i + m*f] = 0;
			}
		}
		for (int i = 0; i < k; i++)
		{
			cout << a[i] << " ";
		}
	}
	cout << endl;
	return 0;
}

