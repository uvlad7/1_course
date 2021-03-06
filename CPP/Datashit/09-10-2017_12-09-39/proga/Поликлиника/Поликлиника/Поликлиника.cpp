// Поликлиника.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct queue
{
	char a[100];
	int n = 0;
	int k = 0;
};
int main()
{
	queue S;
	int l = 0, i = 0, u = 0, j = 0;
	setlocale(LC_ALL, "RUS");
	char b[100], c[100];
	cout << "Список пациентов на сегодня:" << endl;
	ifstream m("Вчерашний день.txt");
	m.getline(S.a, 100);
	while (S.a[u] != ';')
	{
		S.k++;
		u++;
	}
	S.a[u] = ' ';
	cout << S.a << endl;
	m.close();
	ifstream g("Текущий день.txt");
	g.getline(b, 100);
	g.close();
	while (b[i] != ';')
	{
		switch (b[i])
		{
		case '1':
		{
			i = i + 2;
			cout << "Пациент с именем ";
			while (b[i] != ' ' && S.k < 100)
			{
				cout << b[i];
				S.k++;
				S.a[S.k] = b[i];
				i++;
			}
			S.k++;
			S.a[S.k] = ' ';
			cout << " встал в очередь" << endl;
		}
		break;
		case '2':
		{
			j = S.n;
			while (S.a[S.n] != ' ')
			{
				S.n++;
			}
			cout << "Врач вызвал пациента с именем ";
			for (int i = j; i <= S.n; i++)
			{
				cout << S.a[i];
			}
			cout << endl;
			S.n++;
		}
		break;
		case '3':
		{
			cout << "Приём пациентов окончен" << endl;
		}
		break;
		}
		i++;
	}
	ofstream p("Текущий день.txt", ios_base::trunc);
	p.close();
	ofstream v("Вчерашний день.txt", ios_base::trunc);
	for (int i = S.n; i < S.k; i++)
	{
		c[l] = S.a[i];
		l++;
	}
	cout << "Список пациентов на завтра:" << endl;
	for (int i = 0; i < S.k - S.n; i++)
	{
		cout << c[i];
		v << c[i];
	}
	cout << endl;
	c[S.k - S.n] = ';';
	v << c[S.k - S.n];
	v.close();
	return 0;
}
