// Polyclinic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;
struct ring
{
	static const int rlen = 50;
	string b[rlen];
	int frt = 0, bck = -1;

	int push(string &symb)
	{
		if (overflow())
			return 1;
		else
		{
			bck = (bck + 1) % rlen;
			b[bck] = symb;
			return 0;
		}
	}
	string pop()
	{
		if (!empty())
		{
			frt = (frt + 1) % rlen;
			return b[frt - 1];
		}
		else return 1;
	}
	string front()
	{
		return b[frt];
	}
	string back()
	{
		return b[bck];
	}
	bool overflow()
	{
		return ((bck + 2) % rlen == frt%rlen) ? true : false;
	}
	bool empty()
	{
		return ((bck + 1) % rlen == frt%rlen) ? true : false;
	}
};
istream& operator >> (istream& in, ring& s)
{
	string str;
	in >> str;
	if (str != "")
	{
		s.push(str);
	}
	return in;
}
ostream& operator << (ostream& out, const ring& s)
{
	for (int i = s.frt; i <= s.bck; i = (i + 1) % s.rlen)
		out << s.b[i] << endl;
	return out;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ring queue;
	ifstream fin("yesterday.txt");
	while (!fin.eof())
		fin >> queue;
	fin.close();
	int i = -1;
	while (i != 3)
	{
		cin >> i;
		switch (i)
		{
			case 1:
			{
				if (queue.overflow())
					cout << "Нет мест" << endl;
				else
				{
					cout << "Фамилия пациента: ";
					cin >> queue;
				}
				break;
			}
			case 2:
			{
				if (queue.empty())
					cout << "Нет никого в очереди" << endl;
				else
				{
					cout << "Пациент " << queue.front() << " пошёл на приём" << endl;
					queue.pop();
				}
				break;
			}
			case 3:
			{
				cout << "Конец приёма, ";
				ofstream fout("yesterday.txt");
				if (queue.empty()) {
					cout << "все пациенты приняты" << endl;
				}
				else cout << "оставшиеся в очереди приходите завтра" << endl;
				fout << queue;
				break;
			}
			default:
			{
				cout << "Неверная команда" << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}