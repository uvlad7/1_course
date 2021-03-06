// Сортировка вагонов.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

void vagonchiki(char *in, char *out)
{
	stack <char> S;
	int i = 0, j = 0;
	out[j] = in[i];
	i++;
	while (in[i] != '\0')
	{
		if (in[i] == out[j])
		{
			S.push(in[i]);
			i++;
		}
		else
		{
			j++;
			out[j] = in[i];
			i++;
			while (!S.empty() && out[j] != S.top())
			{
				j++;
				out[j] = S.top();
				S.pop();
			}
		}
	}
	while (!S.empty())
	{
		j++;
		out[j] = S.top();
		S.pop();
	}
}
int main()
{
	char in[100] = { 0 };
	char out[100] = { 0 };
	stack <char> S;
	cout << "Vvedite posledovatelnost vagonov:" << endl;
	gets_s(in);
	vagonchiki(in, out);
	cout << "Otsortirovannye vagony: " << endl;
	cout << out << endl;
	return 0;
}

