// Tabl_znac.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <cmath>
using namespace std;

void sqrt_x(double x)
{
	if (x < 0)
		cout << setw(8) << "x != D";
	else
		cout << setw(8) << fixed << setprecision(3) << sqrt(x);
}

void x_umn_x(double x)
{
	cout << setw(12) << x*x;
}

void cos_x(double x)
{
	cout << setw(8) << fixed << setprecision(3) << cos(x);
}

void log_e_x(double x)
{
	if (x <= 0)
		cout << setw(8) << "x != D";
	else
		cout << setw(8) << fixed << setprecision(3) << log(x);

}

void arc_sinx(double x)
{
	if ((x >= -1) && (x <= 1))
		cout << setw(8) << fixed << setprecision(3) << asin(x);
	else cout << setw(8) << "x != D";
}

void exp_x(double x)
{
	cout << setw(18) << fixed << setprecision(3) << exp(x);
}

void tablica(double x1, double x2, int kolvrazb, void(*f1)(double), void(*f2)(double),
	void(*f3)(double), void(*f4)(double), void(*f5)(double), void(*f6)(double))
{
	double zn = 0;
	if (kolvrazb <= 0)
		kolvrazb = 1;
	cout << "_______________________________________________________________________________" << endl;
	cout << "  х  " << setw(8) << " sqrt(x) " << setw(12) << " x*x " << setw(8) << " ln(x) " << setw(8) << " cos(x) " << setw(8) << " asin(x) " << setw(18) << " e^x" << endl;
	cout << "_______________________________________________________________________________" << endl;
	for (int i = 0;i <= kolvrazb;i++)
	{
		zn = x1 + (x2 - x1)*i / kolvrazb;
		cout << fixed << setprecision(3) << setw(8) << zn;
		f1(zn);f2(zn);f3(zn);f4(zn);f5(zn);f6(zn);cout << endl;
	}
}

int main()
{

	setlocale(LC_ALL, "Russian");
	int razb;
	double a, b;
	cout << "Отрезок" << endl;
	cin >> a >> b;
	if (a > b)
	{
		swap(a, b);
	}
	cout << "Кол-во разбиений" << endl;
	cin >> razb;
	tablica(a, b, razb, &sqrt_x, &x_umn_x, &log_e_x, &cos_x, &arc_sinx, &exp_x);
	system("pause");
	return 0;
}
