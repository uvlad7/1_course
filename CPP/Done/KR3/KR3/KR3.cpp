// KR3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<queue>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

class comp
{
public:
	bool operator()(const pair<int, pair<string, vector<string>>> &a, const pair<int, pair<string, vector<string>>> &b)
	{
		return (a.first > b.first);
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin("input.txt");
	priority_queue <pair<int, pair<string, vector<string>>>, vector <pair<int, pair<string, vector<string>>>>, comp> pqBeds; //номер, форма, цветы
	int num;
	string form;
	vector <string> flowers;
	string flower;
	while (!fin.eof())
	{
		fin >> num >> form;
		while ((!fin.eof()) && (fin.peek() != '\n'))
		{
			fin >> flower;
			flowers.push_back(flower);
		}
		pqBeds.push(make_pair(num, make_pair(form, flowers)));
		flowers.clear();
	}
	multimap <string, pair<int, vector<string>>> mmBeds; //форма, <номер, цветы>
	while (!pqBeds.empty())
	{
		cout << pqBeds.top().first << " " << pqBeds.top().second.first << " ";
		for (int i = 0; i < pqBeds.top().second.second.size(); i++)
			cout << pqBeds.top().second.second[i] << " ";
		cout << endl;
		num = pqBeds.top().first;
		form = pqBeds.top().second.first;
		flowers = pqBeds.top().second.second;
		mmBeds.insert(make_pair(form, make_pair(num, flowers)));
		pqBeds.pop();
	}
	cout << endl;
	multimap <string, pair<int, vector<string>>>::iterator it, jt;
	for (it = mmBeds.begin(); it != mmBeds.end(); advance(it, 1))
	{
		cout << it->first << " " << it->second.first << " ";
		for (int i = 0; i < it->second.second.size(); i++)
			cout << it->second.second[i] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "Список форм клумб:" << endl;
	it = mmBeds.begin();
	cout << it->first << " ";
	for (jt = mmBeds.begin(), advance(jt, 1); jt != mmBeds.end(); advance(it, 1), advance(jt, 1))
		if (it->first != jt->first)
			cout << jt->first << " ";
	cout << "\n \n";
	int col;
	cout << "Количество видов цветов: ";
	cin >> col;
	bool founded = 0;
	for (it = mmBeds.begin(); it != mmBeds.end(); advance(it, 1))
		if (it->second.second.size() == col)
		{
			founded = 1;
			cout << it->second.first << " " << it->first << " ";
			for (int i = 0; i < it->second.second.size(); i++)
				cout << it->second.second[i] << " ";
			cout << endl;
		}
	if (!founded)
		cout << "Нет такой клумбы" << endl;
	cout << endl;
	string newflower;
	cout << "Сменить цветок: ";
	cin >> flower;
	cout << "На: ";
	cin >> newflower;
	founded = 0;
	for (it = mmBeds.begin(); it != mmBeds.end(); advance(it, 1))
		for (int i = 0; i < it->second.second.size(); i++)
			if (it->second.second[i] == flower)
			{
				founded = 1;
				it->second.second[i] = newflower;
			}
	if (founded)
	{
		for (it = mmBeds.begin(); it != mmBeds.end(); advance(it, 1))
		{
			cout << it->first << " " << it->second.first << " ";
			for (int i = 0; i < it->second.second.size(); i++)
				cout << it->second.second[i] << " ";
			cout << endl;
		}
	}
	else
		cout << "Нет таких цветов" << endl;
	cout << endl;
	system("pause");
	return 0;
}

