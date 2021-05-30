// Array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "massiv.h"
#include <fstream>
#include <iostream>
using namespace std;

bool f(istream &in)
{
	return !in.eof();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Array<> num(50), temp(5);
	ifstream fin("Ввод.txt");
	num.get(fin, f);
	fin.close();
	cout << endl << "Массив1 " << endl << num << endl;
	ifstream fin2("Ввод.txt");
	fin2 >> temp;
	fin2.close();
	cout << endl << "Массив2 " << endl << temp << endl;
	cout << endl << "Унарный минус " << endl << -temp << endl;
	cout << endl << "Постфиксный инкремент " << endl << temp++ << endl;
	cout << endl << "Префиксный инкремент " << endl << ++temp << endl;
	cout << endl << "Сумма массивов = " << endl << num + temp << endl;
	num += temp;
	cout << endl << "Сумма массивов += " << endl << num << endl;
	cout << endl << "Массив + число " << endl << num + 3 << endl;
	num += 9;
	cout << endl << "Массив += число " << endl << num << endl;
	system("pause");
	return 0;
}