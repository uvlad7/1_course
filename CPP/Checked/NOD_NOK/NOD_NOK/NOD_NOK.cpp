// NOD_NOK.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int nod(int a, int b)
{
	if (a == b)
		return a;
	if (a > b)
		return nod(a - b, b);
	if (a < b)
		return (a, b - a);
}
int nok(int a, int b)
{
	return a*b / nod(a, b);
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << "NOD(" << x << ", " << y << ") = " << nod(x, y) << ", " << "NOK(" << x << ", " << y << ") = " << nok(x, y) << endl;
	system("pause");
}

