// Нахождение НОД и НОК двух натуральных чисел.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int NOD(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	if (b < a)
	{
		return NOD(a - b, b);
	}
	if (a < b)
	{
		return NOD(a, b - a);
	}
}
int main()
{
	int a, b;
	cout << "Vvedite 2 naturalnyh chisla:" << endl;
	cin >> a;
	cin >> b;
	int NOK = (a*b) / NOD(a, b);
	cout << "NOD raven:" << endl;
	cout << NOD(a, b) << endl;
	cout << "NOK raven:" << endl;
	cout << NOK << endl;
	return 0;
}
