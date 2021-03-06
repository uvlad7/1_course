// Gaus.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define N 50
#pragma hdrstop
using namespace std;
void glavelem(int k, double mas[][N + 1], int n, int otv[]);

int main(void)
{
	double mas[N][N + 1];
	double x[N]; //Корни системы
	int otv[N]; //Отвечает за порядок корней
	int i, j, k, n;
	//Ввод данных

	do
	{
		cout << "Vvedite chislo yravnenii sistemi: " << endl;
		cin >> n;
		if (N < n)
			cout << "Slishkom bolshoe chislo yravnenii. Povtorite vvod\n";
	} while (N < n);
	cout << "Vvedite sistemy:\n";
	for (i = 0; i < n; i++)
		for (j = 0; j < n + 1; j++)
			cin >> mas[i][j];

	//Вывод введенной системы
	cout << "sistema:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}



	//Прямой ход метода Гаусса
	for (k = 0; k < n; k++)
	{ //На какой позиции должен стоять главный элемент
		glavelem(k, mas, n, otv); //Установка главного элемента
		if (fabs(mas[k][k]) < 0.0001)
		{
			cout << "Sistema ne imeet edinstvennogo resheniay";
			return (0);
		}
		for (j = n; j >= k; j--)
			mas[k][j] /= mas[k][k];
		for (i = k + 1; i < n; i++)
			for (j = n; j >= k; j--)
				mas[i][j] -= mas[k][j] * mas[i][k];
	}
	//Обратный ход
	for (i = 0; i < n; i++)
		x[i] = mas[i][n];
	for (i = n - 2; i >= 0; i--)
		for (j = i + 1; j < n; j++)
			x[i] -= x[j] * mas[i][j];
	//Вывод результата
	cout << "Otvet:\n";
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == otv[j])
			{ //Расставляем корни по порядку
				cout << x[j] << " ";
				break;
			}
	getch();
	return 0;
}
//---------------------------------------------------------------------------
//Описание функции
//----------------------------------------------
void glavelem(int k, double mas[][N + 1], int n, int otv[])
{
	int i, j, i_max = k, j_max = k;
	double temp;
	//Ищем максимальный по модулю элемент
	for (i = k; i < n; i++)
		for (j = k; j < n; j++)
			if (fabs(mas[i_max][j_max]) < fabs(mas[i][j]))
			{
				i_max = i;
				j_max = j;
			}
	//Переставляем строки
	for (j = k; j < n + 1; j++)
	{
		temp = mas[k][j];
		mas[k][j] = mas[i_max][j];
		mas[i_max][j] = temp;
	}
	//Переставляем столбцы
	for (i = 0; i < n; i++)
	{
		temp = mas[i][k];
		mas[i][k] = mas[i][j_max];
		mas[i][j_max] = temp;
	}
	//Учитываем изменение порядка корней
	i = otv[k];
	otv[k] = otv[j_max];
	otv[j_max] = i;
}