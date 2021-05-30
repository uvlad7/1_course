// Нахождение3maxэлементовмассиваза1просмотр.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, max1 = -1000000, max2 = -1000000, max3 = -1000000;
	cout << "Vvedite razmernost' massiva:" << endl;
	cin >> n;
	cout << "Vvedite elementy massiva:" << endl;
	int *ptr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> ptr[i];
	for (int i = 0; i < n; i++)
	{
		if (max1 < ptr[i])
		{
			max3 = max2;
			max2 = max1;
			max1 = ptr[i];
		}
		else
		{
			if (max2 < ptr[i])
			{
				max3 = max2;
				max2 = ptr[i];
			}
			else
			{
				if (max3 < ptr[i])
				{
					max3 = ptr[i];
				}
			}
		}
	}
	cout << "Maksimalnye elementy:" << endl;
	cout << "max3" << " = " << max3 << endl;
	cout << "max2" << " = " << max2 << endl;
	cout << "max1" << " = " << max1 << endl;
    return 0;
}

