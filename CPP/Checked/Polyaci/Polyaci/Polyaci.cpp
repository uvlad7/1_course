// Polyaci.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stack>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите выражение" << endl;
	string s;
	getline(cin, s);
	s += '#';
	stack <string> pm;
	queue <string> kn, nc;
	for (int i = 0; i < s.size(); i++)
	{
		string ch;
		if ((s[i] >= 48) && (s[i] <= 57))
		{
			if ((!nc.empty()) && (nc.back() == ")"))
				nc.push("*");
			while (((s[i] >= 48) && (s[i] <= 57)) || (s[i] == '.'))
			{
				ch += s[i];
				i++;
			}
			nc.push(ch);
			i--;
		}
		else if (s[i] != ' ')
		{
			if ((!nc.empty()) && ((nc.back() == "(") && (s[i] == '-')))
				nc.push("0");
			if ((!nc.empty()) && (((nc.back() == ")")||(((nc.back()[0] >= 48) && (nc.back()[0] <= 57)))) && (s[i] == '(')))
				nc.push("*");
			ch += s[i];
			nc.push(ch);
		}
	}
	int i = 0;
	pm.push("#");
	while (!nc.empty())
	{
		if ((nc.front()[0] >= 48) && (nc.front()[0] <= 57))
		{
			kn.push(nc.front());
			nc.pop();
		}
		else if ((nc.front() == "+") || (nc.front() == "-"))
		{
			if ((pm.top() == "(") || (pm.top() == "#"))
			{
				pm.push(nc.front());
				nc.pop();
			}
			else
			{
				kn.push(pm.top());
				pm.pop();
			}

		}
		else if ((nc.front() == "*")|| (nc.front() == "/"))
		{
			if ((pm.top() == "*") || (pm.top() == "/"))
			{
				kn.push(pm.top());
				pm.pop();
			}
			else
			{
				pm.push(nc.front());
				nc.pop();
			}
		}
		else if (nc.front() == "(")
		{
			pm.push(nc.front());
			nc.pop();
		}
		else if (nc.front() == ")")
		{
			if (pm.top() == "(")
			{
				pm.pop();
				nc.pop();
			}
			else
			{
				kn.push(pm.top());
				pm.pop();
			}
		}
		else if (nc.front() == "#")
		{
			
			if (pm.top() == "#")
				nc.pop();
			else
			{
				kn.push(pm.top());
				pm.pop();
			}
		}
	}
	pm.pop();
	if (pm.empty())
	{
		double a, b;
		stack <double> pt;
		while (!kn.empty())
		{
			cout << kn.front() << " ";
			if ((kn.front() != "+") && (kn.front() != "-") && (kn.front() != "*") && (kn.front() != "/"))
			{
				pt.push(atof(kn.front().c_str()));
				kn.pop();
			}
			else if (kn.front() == "+")
			{
				kn.pop();
				b = pt.top();
				pt.pop();
				a = pt.top();
				pt.pop();
				a = a + b;
				pt.push(a);
			}
			else if (kn.front() == "-")
			{
				kn.pop();
				b = pt.top();
				pt.pop();
				a = pt.top();
				pt.pop();
				a = a - b;
				pt.push(a);
			}
			else if (kn.front() == "*")
			{
				kn.pop();
				b = pt.top();
				pt.pop();
				a = pt.top();
				pt.pop();
				a = a * b;
				pt.push(a);
			}
			else if (kn.front() == "/")
			{
				kn.pop();
				b = pt.top();
				pt.pop();
				a = pt.top();
				pt.pop();
				a = a / b;
				pt.push(a);
			}
		}
		cout << endl;
		cout << pt.top() << endl;
	}
	else
		cout << "Неверное выражение";
	system("pause");
    return 0;
}