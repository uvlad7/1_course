// ЧислаФибоначчи.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int fibo(int n)
{
	if (n == 1 || n == 2)
	{
		return n - 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}
int main()
{
	int n;
	cout << "Vvedite poriadkovyj nomer chisla Fibonachchi:" << endl;
	cin >> n;
	cout << "Chisla Fibonachchi:" << endl;
	for (int k = 1; k <= n; k++)
		cout << setw(2) << k << " = " << fibo(k) << endl;
    return 0;
}