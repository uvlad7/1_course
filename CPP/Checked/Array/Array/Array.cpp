// Array.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	ifstream fin("����.txt");
	num.get(fin, f);
	fin.close();
	cout << endl << "������1 " << endl << num << endl;
	ifstream fin2("����.txt");
	fin2 >> temp;
	fin2.close();
	cout << endl << "������2 " << endl << temp << endl;
	cout << endl << "������� ����� " << endl << -temp << endl;
	cout << endl << "����������� ��������� " << endl << temp++ << endl;
	cout << endl << "���������� ��������� " << endl << ++temp << endl;
	cout << endl << "����� �������� = " << endl << num + temp << endl;
	num += temp;
	cout << endl << "����� �������� += " << endl << num << endl;
	cout << endl << "������ + ����� " << endl << num + 3 << endl;
	num += 9;
	cout << endl << "������ += ����� " << endl << num << endl;
	system("pause");
	return 0;
}