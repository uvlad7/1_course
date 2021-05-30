// Wagons_sort.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

struct stek
{
	static const int stlen = 50;
	char b_stek[stlen];
	int tos = -1;
	int push(char symb)
	{
		if (tos >= stlen - 1)
			return 1;
		else
		{
			tos++;
			b_stek[tos] = symb;
			return 0;
		}
	}
	char pop()
	{
		if (tos >= 0)
		{
			tos--;
			return b_stek[tos + 1];
		}
		else return '\0';
	}
	char top()
	{
		return b_stek[tos];
	}
	bool empty()
	{
		return tos == -1 ? true : false;
	}
};
istream& operator >> (istream& in, stek& s)
{
	char str[s.stlen];
	in.getline(str, s.stlen);
	for (int i = 0; str[i] != '\0'; i++)
	{
		s.push(str[i]);
	}
	return in;
}
ostream& operator << (ostream& out, const stek& s)
{
	for (int i = s.tos; i >= 0; i--)
		out << s.b_stek[i];
	return out;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	stek entry, exit, dock;
	cin >> entry;
	while (!entry.empty())
	{
		if ((exit.empty()) || (entry.top() != exit.top()))
			exit.push(entry.pop());
		else
			if ((!dock.empty()) && (exit.top() != dock.top()))
				exit.push(dock.pop());
			else
				dock.push(entry.pop());
	}
	if (dock.empty())
		cout << exit << endl;
	else cout << "Ќе получилось отсортировать" << endl;
	system("pause");
    return 0;
}

