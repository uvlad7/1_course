// Map.cpp: ���������� ����� ����� ��� ����������� ����������.
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

map <pair<string, string>, int> A; //<�������, �������>, ����
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream in("input.txt");
	string mag, pr;
	int cost;
	while (in >> mag >> pr >> cost)
		A.insert(make_pair(make_pair(pr, mag), cost));
	map <pair<string, string>, int> ::iterator it, j = A.begin(); //old: �������, <����, �������>
	for (it = A.begin(); it != A.end(); advance(it, 1))
	{
		cout << it->first.second << " : " << it->first.first << " � " << it->second << endl;
	}
	int com;
	cout << "1. ����� ������ �������� �������� � ��������" << endl;
	cout << "2. ����� ����� ������ ���� �� �������" << endl;
	cout << "3. ��������� ������ ��������� � ��������" << endl;
	cout << "4. ����� ����� ������ ���� �� ����� ���������" << endl;
point:
	cout << "������� �������" << endl;
	cin >> com;
	switch (com)
	{
	case 1:
	{
		cout << "������� �������� ��������" << endl;
		cin >> mag;
		for (it = A.begin(); it != A.end(); advance(it, 1))
		{
			if ((it->first.second == mag) && ((it->second <= j->second) || (j->first.second != mag)))
				j = it;
		}
		if (j->first.second == mag)
			cout << "����� ������� ������� � �������� " << j->first.second << " : " << j->first.first << " � " << j->second << endl;
		else cout << "��� ������" << endl;
		break;
	}
	case 2:
	{
		cout << "������� �������� ��������" << endl;
		cin >> pr;
		for (it = A.begin(); it != A.end(); advance(it, 1))
		{
			if ((it->first.first == pr) && ((it->second <= j->second) || (j->first.first != pr)))
				j = it;
		}
		if (j->first.first == pr)
			cout << "����� ������ ���� �� " << j->first.first << " : " << j->first.second << " � " << j->second << endl;
		else cout << "��� ������" << endl;
		break;
	}
	case 3:
	{
		cout << "������� �������� ��������" << endl;
		cin >> mag;
		bool en = true;
		int sum = 0, col;
		char prs[256], *tmp;
		cout << "������� �������� � ���������� ������� ��������" << endl;
		cin.ignore(1, '\n');
		cin.getline(prs, 255);
		tmp = strtok(prs, " *,");
		while (tmp != NULL)
		{
			pr = tmp;
			col = atoi(strtok(NULL, " *,"));
			try
			{
				sum += col*A.at(make_pair(pr, mag));
			}
			catch (out_of_range)
			{
				en = false;
				break;
			}
			tmp = strtok(NULL, " *,");
		}
		if (en)
			cout << "��������� ������ � �������� " << mag << " � " << sum << endl;
		else cout << "��� ������" << endl;
		break;
	}
	case 4:
	{
		map <string, int> M;
		for (it = A.begin(); it != A.end(); advance(it, 1))
			M.insert(make_pair(it->first.second, 0));
		map <string, int>::iterator i, jt = M.begin();
		int col;
		char prs[256], *tmp;
		cout << "������� �������� � ���������� ������� ��������" << endl;
		cin.ignore(1, '\n');
		cin.getline(prs, 255);
		tmp = strtok(prs, " *,");
		while (tmp != NULL)
		{
			pr = tmp;
			col = atoi(strtok(NULL, " *,"));
			for (i = M.begin(); i != M.end(); advance(i, 1))
			{
				if (i->second != -1)
				{
					try
					{
						i->second += col*A.at(make_pair(pr, i->first));
					}
					catch (out_of_range)
					{
						i->second = -1;
					}
				}
			}
			tmp = strtok(NULL, " *,");
		}
		for (i = M.begin(); i != M.end(); advance(i, 1))
			if ((i->second != -1) && ((i->second < jt->second) || (jt->second == -1)))
				jt = i;
		if (jt->second != -1)
			cout << "����������� ��������� ������ � �������� " << jt->first << " � " << jt->second << endl;
		else cout << "��� ������" << endl;
		break;
	}
	default:
	{
		cout << "�������� ����" << endl;
		break;
	}
	}
	bool re;
	cout << "����������? 1 - ��, 0 - ���" << endl;
	cin >> re;
	if (re)
		goto point;
	system("pause");
	return 0;
}