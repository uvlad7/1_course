// Определениечисларазличныхсимволовмассиваchar.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, k = 1;
	cout << "Vvedite razmernost' massiva:" << endl;
	cin >> n;
	char *ptr = new char[n];
	char *a = new char[k];
	cout << "Vvedite elmenty massiva:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> ptr[i];
	}
	a[k - 1] = ptr[0];
	for (int i = 1; i < n; i++)
	{
		if (ptr[0] != ptr[i])
		{
			a[k] = ptr[i];
			for (int j = i + 1; j < n; j++)
			{
				if (ptr[i] == ptr[j])
				{
					ptr[j] = ptr[0];
				}
			}
			ptr[i] = ptr[0];
			k++;
		}
	}
	cout << "Razlichnye simvoly:" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Chislo razlichnyh simvolov:" << endl;
	cout << k << endl;
    return 0;
}

