// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int  n;
	cout << "Vvedite razmernost' massiva:" << endl;
	cin >> n;
	int *ptr = new int[n];
	cout << "Vvedite elementy massiva:" << endl;
	for (int i = 0; i < n; i++)
		cin >> ptr[i];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (ptr[j] > ptr[j + 1])
		{   
				int a = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = a;
		}
	cout << "Vyvod massiva:" << endl;
	for (int i = 0; i < n; i++)
		cout << ptr[i] << " ";
	cout << endl;
    return 0;
}

