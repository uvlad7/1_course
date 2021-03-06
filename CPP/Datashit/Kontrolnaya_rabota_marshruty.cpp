// Контрольная работа(маршруты).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<deque>
#include<algorithm>
#include<Windows.h>
using namespace std;

class transport
{
public:
	int number_marsh;
	string name;
	int number_avto;
	string marsh;

	transport()
	{
		number_avto = 0;
		number_marsh = 0;
		name = "0";
		marsh = "0";
	}
	transport(int n_m, string n, int n_a, string m)
	{
		number_marsh = n_m;
		name = n;
		number_avto = n_a;
		marsh = m;
	}

	friend ostream& operator<<(ostream& o, transport t)
	{
		o << t.number_marsh << t.name << t.number_avto << t.marsh;
		return o;
	}

	friend istream& operator>>(istream& i, transport t)
	{
		i >> t.number_marsh >> t.name >> t.number_avto >> t.marsh;
		return i;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream out("txt.txt");
	transport T[8];
	deque<transport> ich;
	deque<transport>::iterator p=ich.begin();
	deque<transport>::iterator u = ich.begin();

	int i = 0,A;
	string B;
	while (!out.eof())
	{
		out >> A>>B;
		T[i].number_marsh = A;
		T[i].name = B;
		out >> A >> B;
		T[i].number_avto = A;
		T[i].marsh = B;
		ich.push_back(T[i]);
		i++;
	}
	for ( p=ich.begin(); p !=ich.end(); p++)
	{
		cout << p->number_marsh<<" " << p->name << " " << p->number_avto << " " << p->marsh<<endl;
	}
	cout << endl<< "Сортировка по номеру маршрута: "<<endl;
	for (p=ich.begin(); p!=ich.end(); p++)
	{
		for (u = p + 1; u != ich.end(); u++)
		{
			if (p->number_marsh > u->number_marsh)
			{
				swap(p->number_marsh, u->number_marsh);
				swap(p->marsh, u->marsh);
				swap(p->number_avto, u->number_avto);
				swap(p->name, u->name);
			}
		}
	}

	cout << endl;
	for (p = ich.begin(); p != ich.end(); p++)
	{
		cout << p->number_marsh << " " << p->name << " " << p->number_avto << " " << p->marsh << endl;
	}
	cout << endl << "Сортировка по номеру авто: " << endl;
	for (p = ich.begin(); p != ich.end(); p++)
	{
		for (u = p + 1; u != ich.end(); u++)
		{
				if (p->number_avto > u->number_avto)
				{
					swap(p->number_marsh, u->number_marsh);
					swap(p->marsh, u->marsh);
					swap(p->number_avto, u->number_avto);
					swap(p->name, u->name);
				}
		}
	}
	cout << endl;
	for (p = ich.begin(); p != ich.end(); p++)
	{
		cout << p->number_marsh << " " << p->name << " " << p->number_avto << " " << p->marsh << endl;
	}
	p = ich.begin();
	multimap<int, string> a1[8];
	multimap<int, string>::iterator z;
	for (int i = 0; i < 8; i++)
	{
		a1[i].insert(make_pair(p->number_marsh, p->name));
		p++;
	}
	pair<int, string>  a2[8];
	p = ich.begin();
	for (i=0; i < 8; i++)
	{
		a2[i] = make_pair(p->number_avto, p->marsh);
		p++;
	}
	string MARSH;
	cout << "Введите маршрут: ";
	cin >> MARSH;
	bool you = false;
	cout << "автобусы на этом маршруте: ";
	for (int i = 0; i < 8; i++)
	{
		if (a2[i].second == MARSH) {
			cout << a2[i].first << ", ";
			you = true;
		}
	}
	if (!you)
		cout << "такого маршрута нет!" << endl;
	you = false;
	cout << endl;
	int AVTO,j=0;
	cout << "Введите номер автобуса: ";
	cin >> AVTO;
	cout << "водители, работающие на этом автобусе: ";
	for (int i = 0; i < 8; i++)
	{
		if (a2[i].first == AVTO)
		{
			z = a1[i].begin(); {
				cout << z->second << ", ";
				you = true;
			}
		}
	}
	if (!you)
		cout << "такого автобуса нет!" << endl;
	cout << endl<<"Введите маршрут, который необходимо удалить: ";
	cin >> MARSH;
	you = false;
		for (int i = 0; i < 8; i++)
		{
			if (a2[i].second == MARSH)
			{
				a2[i].second.erase();
				you=true;
			}
		}
		if (!you)
			cout << "такого маршрута нет!";
		for (int i = 0; i < 8; i++)
		{
			z = a1[i].begin();
			cout << z->first << " " << z->second<<" ";
			cout << a2[i].first <<" " <<a2[i].second;
			cout << endl;
		}
		int col = 0, ne = 0;
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (a2[j].second == a2[i].second)
					ne++;
				if (col <= ne)
					col = ne;
			}
			ne = 0;
		}
		cout << "максимальное количество автобусов на маршруте: "<<col<<endl;
	return 0;
}

