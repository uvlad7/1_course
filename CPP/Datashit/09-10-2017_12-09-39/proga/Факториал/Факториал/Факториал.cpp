// Факториал.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int long fact(int long n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return n*fact(n - 1);
}

int main()
{
	int n;
	cout << "Vvedite chislo:" << endl;
	cin >> n;
	cout << "Rezultat:" << endl;
	for (int k = 0; k <= n; k++)
	{
		cout << k << "! = " << fact(k) << endl;
	}
    return 0;
}

