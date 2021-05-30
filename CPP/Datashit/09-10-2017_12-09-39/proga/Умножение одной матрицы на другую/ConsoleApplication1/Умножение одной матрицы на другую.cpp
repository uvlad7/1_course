// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int n, m, v;
	cout << "Vvedite kolichestvo strok 1 matricy:" << endl;
	cin >> n;
	cout << "Vvedite kolichestvo stolbtsov 1 matricy:" << endl;
	cin >> m;
	cout << "Vvedite elementy 1 matricy:" << endl;
	int **ptr1 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ptr1[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> ptr1[i][j];
		}
	}
	cout << "Vvedite kolichestvo stolbtsov 2 matricy:" << endl;
	cin >> v;
	cout << "Vvedite elementy 2 matricy:" << endl;
	int **ptr2 = new int*[m];
	for (int i = 0; i < m; i++)
	{
		ptr2[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			cin >> ptr2[i][j];
		}
	}
	int **ptr3 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ptr3[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			ptr3[i][j] = 0;
			for (int k = 0; k < m; k++)
				ptr3[i][j] += ptr1[i][k] * ptr2[k][j];
		}
	}
	cout << "Vyvod matricy:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v; j++)
		{
			cout << setw(5) << ptr3[i][j];
		}
		cout << endl;
	}
	return 0;
}


