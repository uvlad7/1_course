// Spisok.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

struct point1
{
	int num;
	int inf;
	point1 *next = NULL;
}; 
point1 *list = NULL;
void add(int in)
{
	point1 *temp = new point1;
	temp->inf = in;
	if (list == NULL)
	{
		temp->num = 1;
		list = temp;
	}
	else
	{
		point1 *tek = list;
		while (tek->next != NULL)
			tek = tek->next;
		temp->num = tek->num + 1;
		tek->next = temp;
	}
}
void clr()
{
	point1  *first = list, *tek = list, *prev;
	while ((tek != NULL) && (tek->next != NULL))
	{
		prev = tek;
		tek = tek->next->next;
		prev->next->next = first;
		first = prev->next;
		prev->next = tek;
	}
	list = first;
}
void inv(int n)
{
	point1  *first = list, *tek, *prev = list;
	for (int i = n; i > 1; i--)
	{
		tek = prev->next;
		prev->next = tek->next;
		tek->next = first;
		first = tek;
	}
	list = first;
}
int max_neg()
{
	point1 *temp = list;
	int i = INT_MIN;
	while (temp != NULL)
	{
		if ((temp->inf < 0) && (temp->inf > i))
			i = temp->inf;
		temp = temp->next;
	}
	return i;
}
void getlist()
{
	point1 *tek = list;
	char str[64];
	FILE * ptrFile = fopen("Ввод.txt", "r");
	fgets(str, 64, ptrFile);
	fclose(ptrFile);
	char * pch = strtok(str, " ,.;");
	while (pch != NULL)
	{
		add(atoi(pch));
		pch = strtok(NULL, " ,.;");
	}
}
int n()
{
	point1 *temp = list;
	int nm;
	while (temp != NULL)
	{
		nm = temp->num;
		temp = temp->next;
	}
	return nm;
}
ostream& operator <<(ostream& out, point1 *list)
{
	point1 *tek = list;
	while (tek != NULL)
	{
		out << tek->inf << " ";
		tek = tek->next;
	}
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	getlist();
	ofstream fout("Вывод.txt");
	fout << "Исходный список" << endl;
	fout << list << endl;
	clr();
	fout << "Переставили чётные элементы" << endl;
	fout << list << endl;
	inv(n() / 2);
	fout << "Инвертировали первую половину" << endl;
	fout << list << endl;
	int m = max_neg();
	if (m == INT_MIN)
		fout << "Нет отрицательных элементов" << endl;
	else fout << "Максимальный отрицательный элемент: " << m << endl;
	fout.close();
	system("pause");
	return 0;
}
