// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{ 
	int n;
	cout << "Vvedine rarmernost' matricy:"<<endl;
	cin >> n;
	int **ptr = new int*[n];
	for (int i = 0; i < n; i++)
		{
			ptr[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				ptr[i][j] = 0;
			}
		}
	for (int i = 0; i < n; i++)
	{
		ptr[i][0] = 1;
		ptr[i][i] = 1;
		for (int i = 2; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				ptr[i][j] = ptr[i - 1][j - 1] + ptr[i - 1][j];
			}
		}
	}
	cout << "Vyvod matricy:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << ptr[i][j];
		}
		cout << endl;
	}
    return 0;
}

