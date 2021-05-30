// RomanNumber.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
string num{ "IVXLCDM" };

void DecToRom(string &numb, short unsigned int n, short unsigned int pos)
{
	if (n <= 3)
		for (int i = 0; i < n;i++)
			numb += num[pos * 2];
	if (n == 4)
	{
		numb += num[pos * 2];
		numb += num[pos * 2 + 1];
	}
	if ((n >= 5) && (n <= 8))
	{
		numb += num[pos * 2 + 1];
		for (int i = 0; i < n - 5;i++)
			numb += num[pos * 2];
	}
	if (n == 9)
	{
		numb += num[pos * 2];
		numb += num[pos * 2 + 2];
	}
}

int main()
{
	string numb, fnumb;
	cin >> fnumb;
	for (int i = 0; i < fnumb.size(); i++)
		DecToRom(numb, fnumb[i] - '0', fnumb.size() - 1 - i);
	cout << numb << endl;
	system("pause");
    return 0;
}

