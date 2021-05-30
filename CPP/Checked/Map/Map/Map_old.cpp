// Map.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <Windows.h>
#include <cstdio>
using namespace std;

typedef pair<int, string> pp; //цена, магазин
multimap <string, pp> A; //продукт, пара
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream in("input.txt");
	string mag, pr;
	int cost;
	while (in >> mag >> pr >> cost)
		A.insert(make_pair(pr, make_pair(cost, mag)));
	multimap <string, pp> ::iterator it;
	for (it = A.begin(); it != A.end(); ++it)
	{
		cout << it->second.second << " : " << it->first << " — " << it->second.first << endl;
	}
	int com;
	cout << "Введите команду" << endl;
	cout << "1. Поиск самого дешевого продукта в магазине" << endl;
	cout << "2. Поиск самой низкой цены на продукт" << endl;
	cout << "3. Стоимость набора продуктов в магазине" << endl;
	cout << "4. Поиск самой низкой цены на набор продуктов" << endl;
	cin >> com;
	switch (com)
	{
	case 1:
	{
		cout << "Введите название магазина" << endl;
		cin >> mag;
		multimap <string, pp> ::iterator j = A.begin();
		for (it = A.begin(); it != A.end(); ++it)
		{
			if ((it->second.second == mag) && ((it->second.first <= j->second.first) || (j->second.second != mag)))
				j = it;
		}
		if (j->second.second == mag)
			cout << "Самый дешевый продукт в магазине " << j->second.second << " : " << j->first << " — " << j->second.first << endl;
		else cout << "Нет данных" << endl;
		break;
	}
	case 2:
	{
		cout << "Введите название продукта" << endl;
		cin >> pr;
		multimap <string, pp> ::iterator j = A.begin();
		for (it = A.begin(); it != A.end(); ++it)
		{
			if ((it->first == pr) && ((it->second.first <= j->second.first) || (j->first != pr)))
				j = it;
		}
		if (j->first == pr)
			cout << "Самая низкая цена на " << j->first << " : " << j->second.second << " — " << j->second.first << endl;
		else cout << "Нет данных" << endl;
		break;
	}
	case 3:
	{
		cout << "Введите название магазина" << endl;
		cin >> mag;
		bool en = true;
		int sum = 0, col;
		char prs[256], *tmp;
		cout << "Введите название и количество каждого продукта" << endl;
		cin.ignore(1, '\n');
		cin.getline(prs, 255);
		tmp = strtok(prs, " *,");
		while (tmp != NULL)
		{
			pr = tmp;
			col = atoi(strtok(NULL, " *,"));
			for (it = A.begin(); it != A.end(); ++it)
			{
				if ((it->second.second == mag) && (it->first == pr))
				{
					sum += col*it->second.first;
					break;
				}
			}
			if (it == A.end())
			{
				en = false;
				break;
			}
			tmp = strtok(NULL, " *,");
		}
		if (en)
			cout << "Стоимость набора в магазине " << mag << " — " << sum << endl;
		else cout << "Нет данных" << endl;
		break;
	}
	case 4:
	{

	}
	default:
	{
		cout << "Неверный ввод" << endl;
	}
	}
	system("pause");
	return 0;
}