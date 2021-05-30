// Gauss.cpp: определяет точку входа для консольного приложения.
//

#include"stdafx.h"
#include "Fraction.h"
#include <iostream>

int main()
{
	Fraction a(1, 1), b(3, 2), c(1, 2);
	cin >> a;
	a += 5;
	cout << (a < b) << endl;
	b *= 2;
	cout << b << endl;
	a = b * c;
	cout << a << endl;
	c /= b;
	cout << c << endl;
	system("pause");
	return 0;
}
