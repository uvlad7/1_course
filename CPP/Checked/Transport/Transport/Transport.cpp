// Transport.cpp: ���������� ����� ����� ��� ����������� ����������.
//12 �������

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<deque>
#include <iterator>
#include <map>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin("input.txt");
	deque <pair<string, pair<int, pair<int, string>>>> transport; //��������, <�������, <����� ��������, �����>>
	int route, bus;
	string driver, brand;
	while (fin >> route >> driver >> bus >> brand)
		transport.push_back(make_pair(driver, make_pair(route, make_pair(bus, brand))));
	deque <pair<string, pair<int, pair<int, string>>>> ::iterator i, j;
	for (i = transport.begin(); i != transport.end(); advance(i, 1))
		cout << i->second.first << " " << i->first << " " << i->second.second.first << " " << i->second.second.second << endl;
	cout << endl;
	for (i = transport.begin(); i != transport.end(); advance(i, 1))
		for (j = i + 1; j != transport.end(); advance(j, 1))
			if ((i->second.first > j->second.first) || ((i->second.first == j->second.first) && (i->second.second.first > j->second.second.first)))
				swap(*i, *j);
	for (i = transport.begin(); i != transport.end(); advance(i, 1))
		cout << i->second.first << " " << i->first << " " << i->second.second.first << " " << i->second.second.second << endl;
	cout << endl;
	map <string, pair<int, pair<int, string>>> buses; //��������, <�������, <����� ��������, �����>>
	for (i = transport.begin(); i != transport.end(); advance(i, 1))
		buses.insert(*i);
	map <string, pair<int, pair<int, string>>>::iterator it;
	for (it = buses.begin(); it != buses.end(); advance(it, 1))
		cout << it->first << " " << it->second.first << " " << it->second.second.first << " " << it->second.second.second << endl;
	cout << endl;
	map <string, string> drivers; //�����, ��������
	bool founded = 0;
	cout << "����� ��������: ";
	cin >> route;
	for (it = buses.begin(); it != buses.end(); advance(it, 1))
	{
		if (it->second.first == route)
		{
			cout << it->second.second.first << " ";
			founded = 1;
		}
		try
		{
			drivers.at(it->second.second.second) += " " + it->first;
		}
		catch (out_of_range)
		{
			drivers.insert(make_pair(it->second.second.second, it->first));
		}
	}
	if (founded)
		cout << endl;
	else cout << "��� ������" << endl;
	cout << endl;
	map <string, string> ::iterator br;
	for (br = drivers.begin(); br != drivers.end(); advance(br, 1))
		cout << br->first << " : " << br->second << endl;
	cout << endl;
	cout << "���������� ������ ����� � " << drivers.size() << endl;
	cout << endl;
	cout << "��������: ";
	cin >> driver;
	try
	{
		pair<int, pair<int, string>> &dr = buses.at(driver);
		cout << "����� �������" << endl;
		cout << "�����: ";
		cin >> dr.second.first;
		cout << "�����: ";
		cin >> dr.second.second;
		cout << "�������: ";
		cin >> dr.first;
		cout << endl;
		for (it = buses.begin(); it != buses.end(); advance(it, 1))
			cout << it->first << " " << it->second.first << " " << it->second.second.first << " " << it->second.second.second << endl;
		cout << endl;
		for (it = buses.begin(); it != buses.end(); advance(it, 1))
		{
			try
			{
				drivers.at(it->second.second.second) += " " + it->first;
			}
			catch (out_of_range)
			{
				drivers.insert(make_pair(it->second.second.second, it->first));
			}
		}
		cout << "���������� ������ ����� � " << drivers.size() << endl;
	}
	catch (out_of_range)
	{
		cout << "��� ��������" << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}