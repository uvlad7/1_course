// Определениечисларазличныхэлементовмассива.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, k = 1;
	cout << "Vvedite razmernost' massiva:" << endl;
	cin >> n;
	cout << "Vvedite elementy massiva:" << endl;
	int *ptr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> ptr[i];
	for (int i = 1; i < n; i++)
	{
		if (ptr[0] != ptr[i])
		{
			for (int j = i + 1; j < n; j++)
			{
				if (ptr[j] == ptr[i])
				{
					ptr[j] = ptr[0];
				}
			}
			ptr[i] = ptr[0];
			k++;
		}
	}
	cout << "Chislo razlichnyh elementov:" << endl;
	cout << k << endl;
    return 0;
}

