// Обратная польская запись.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

int prioritet(char n)
{
	switch (n)
	{
	case '(': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	}
}
bool operacii(char o)
{
	return o == '+' || o == '-' || o == '*' || o == '/';
}
bool peremennye(char p)
{
	return p >= 'a' && p <= 'z';
}
void polskaja_zapis(char *in, char *out)
{
	stack <char> S;
	int i = 0, j = 0;
	while (in[i] != '\0')
	{
		if (peremennye(in[i]))
		{
			out[j] = in[i];
			j++;
			i++;
		}
		else if (operacii(in[i]))
		{
			if (S.empty() || prioritet(S.top()) < prioritet(in[i]))
			{
				S.push(in[i]);
				i++;
			}
			else if (prioritet(S.top()) >= prioritet(in[i]))
			{
				out[j] = S.top();
				S.pop();
				S.push(in[i]);
				j++;
				i++;
			}
		}
		else if (in[i] == '(')
		{
			S.push(in[i]);
			i++;
		}
		else if (in[i] == ')')
		{
			if (S.empty() || S.top() == '(')
			{
				cout << "Oshibka" << endl;
				exit(1);
			}
			else
			{
				while (S.top() != '(')
				{
					out[j] = S.top();
					S.pop();
					j++;
				}
			}
			S.pop();
			i++;
		}
	}
	while (!S.empty())
	{
		if (S.top() == '(')
		{
			cout << "Oshibka" << endl;
			exit(1);
		}
		else
		{
			out[j] = S.top();
			S.pop();
			j++;
		}
	}
}
int vychislenija(char *out)
{
	int j = 0, c = 0, rez1 = 0, rez2 = 0;
	stack <int> S;
	while (out[j] != '\0')
	{
		if (out[j] >= 'a'&& out[j] <= 'z')
		{
			cout << "Vvedite: " << out[j] << ": " << endl;
			cin >> c;
			S.push(c);
		}
		else if (operacii(out[j]))
		{
			rez1 = S.top();
			S.pop();
			rez2 = S.top();
			S.pop();
			switch (out[j])
			{
			case '+': S.push(rez2 + rez1); break;
			case '-': S.push(rez2 - rez1); break;
			case '*': S.push(rez2 * rez1); break;
			case '/': S.push(rez2 / rez1); break;
			}
		}
		j++;
	}
	return(S.top());
	cout << endl;
}
int main()
{
	char in[100] = { 0 };
	char out[100] = { 0 };
	stack <char> S;
	cout << "Vvedite vyrazhenije:" << endl;
	gets_s(in);
	polskaja_zapis(in, out);
	cout << "Obratnaja polskaja zapis: " << endl;
	cout << out << endl;
	cout << "Otvet: " << endl << vychislenija(out) << endl;
	return 0;
}