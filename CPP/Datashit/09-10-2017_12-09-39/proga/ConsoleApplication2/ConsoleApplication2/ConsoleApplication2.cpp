// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int v;
	setlocale(LC_ALL, "RUS");
	char a[100];
	cout << "1 - новый пациент стал в очередь;" << endl;
	cout << "2 - первый пациент пошёл на приём;" << endl;
	cout << "3 - закончить приём пациентов;" << endl;
	cout << "Список пациентов на сегодня:" << endl;
	ifstream m("Поликлиника.txt");
	m.getline(a, 100);
	cout << a << endl;
	m.close();
	cout << "Введите число: ";
	cin >> v;
	switch (v)
	{
	case 1:	while (v != 3 && v != 2)
	{
		ofstream f("Поликлиника.txt", ios_base::app);
		cout << "Введите имя пациента: "; cin >> a; f << a << " ";
		f.close();
		cout << "Введите число: ";
		cin >> v;
	}
	case 2: while (v != 3 && v != 1)
	{
		cout << "Врач вызвал пациента" << endl;
		ifstream k("Поликлиника.txt");
		k.getline(a, 100);
		k.close();
		for (int i = 0; i < 100; i++)
		{
			if (a[i] == ' ')
			{
				i++;
				for (int j = 0; j < 100; j++)
				{
					a[j] = a[i++];
				}
			}
		}
		ofstream n("Поликлиника.txt", ios_base::trunc);
		n << a;
		n.close();
		cout << "Введите число: ";
		cin >> v;
	}
	case 3: cout << "Приём пациентов окончен" << endl; break;
	default: cout << "Ошибка. Введено неверное число" << endl;
	}
	cout << "Список пациентов на завтра:" << endl;
	ifstream c("Поликлиника.txt");
	c.getline(a, 100);
	cout << a << endl;
	c.close();
	return 0;
}