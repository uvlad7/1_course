// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, m, f, k = 0, i = 0, j = 0;
	cout << "Vvedite razmernost' 1 massiva:" << endl;
	cin >> n;
	int *ptrn = new int[n];
	cout << "Vvedite elementy 1 massiva:" << endl;
	for (int i = 0; i < n; i++)
		cin >> ptrn[i];
	cout << "Vvedite razmernost' 2 massiva:" << endl;
	cin >> m;
	int *ptrm = new int[m];
	int *ptrf = new int[n + m];
	cout << "Vvedite elementy 2 massiva:" << endl;
	for (int j = 0; j < m; j++)
	{

		cin >> ptrm[j];
	}
	while (i < n && j < m)
		if (ptrn[i] < ptrm[j])
		{
			ptrf[k] = ptrn[i];
			i++;
			k++;
		}
		else
		{
			ptrf[k] = ptrm[j];
			j++;
			k++;
		}
	if (i == n)
		while (j < m)
		{
			ptrf[k] = ptrm[j];
			j++;
			k++;
		}
	else
		while (i < n)
		{
			ptrf[k] = ptrn[i];
			i++;
			k++;
		}
	cout << "Vyvod 3 massiva:" << endl;
	for (int k = 0; k < n + m; k++)
		cout << ptrf[k] << " ";
	cout << endl;
	return 0;
}

