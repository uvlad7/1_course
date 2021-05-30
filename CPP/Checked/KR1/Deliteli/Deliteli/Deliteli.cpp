// deliteli.cpp: определ€ет точку входа дл€ консольного приложени€.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class IntNumber
{
private:
	int field, kol_mn, kol_del, kol_all_del, kol_del2, kol_del_minpr;
	int *pr, *prd, *alldel, *del2, *delminpr;
	void razl(int n1, int n2); //рекурсивное разложение
	void razlog(); //разложение числа на простые множители
	void del();
public:
	IntNumber() {}; //конструктор класса
	IntNumber(int fi) { field = fi; } //конструктор класса
	void prdel(ostream& os);
	void delkr2(ostream& os);
	void del_min_pr(ostream& os);
	friend istream& operator >> (istream& in, IntNumber& p);
	friend ostream& operator <<(ostream& os, IntNumber& p);
	~IntNumber() { delete[] pr;  delete[] prd; delete[] alldel; delete[] del2; delete[] delminpr; } // деструктор класса
};
int prc(int n)
{
	int num = n, pr = 1;
	while (num != 0)
	{
		pr *= num % 10;
		num /= 10;
	}
	return pr;
}
void IntNumber::del_min_pr(ostream& os)
{
	del();
	kol_del_minpr = 1;
	delminpr = new int[field];
	delminpr[0] = alldel[0];
	for (int i = 1; i < kol_all_del; i++)
	{
		if (prc(alldel[i]) == prc(delminpr[kol_del_minpr - 1]))
		{
			delminpr[kol_del_minpr] = alldel[i];
			kol_del_minpr++;
		}
		if (prc(alldel[i]) < prc(delminpr[kol_del_minpr - 1]))
		{
			delminpr[0] = alldel[i];
			kol_del_minpr = 1;
		}
	}
	for (int i = 0; i < kol_del_minpr; i++)
		os << delminpr[i] << " ";
}
void IntNumber::razl(int n1, int n2)
{
	if (n1>1)
		if (n1%n2 == 0)
		{
			pr[kol_mn] = n2;
			kol_mn++;
			razl(n1 / n2, n2);
		}
		else
		{
			if (n2 == 2)
				n2++;
			else
				n2 += 2;
			razl(n1, n2);
		}
}
void IntNumber::razlog()
{
	kol_mn = 0;
	int p = (int)(log((double)field) / log(2.)) + 1;
	pr = new int[p];
	razl(field, 2);
}
void IntNumber::del()
{
	kol_all_del = 0;
	alldel = new int[field];
	for (int i = 2; i <= field; i++)
	{
		if (field % i == 0)
		{
			alldel[kol_all_del] = i;
			kol_all_del++;
		}
	}
}
void IntNumber::delkr2(ostream& os)
{
	del();
	kol_del2 = 0;
	del2 = new int[field / 2];
	for (int i = 0; i < kol_all_del; i++)
	{
		if (alldel[i] % 2 == 0)
		{
			del2[kol_del2] = alldel[i];
			kol_del2++;
		}
	}
	for (int i = 0; i < kol_del2; i++)
		os << del2[i] << " ";
}
void IntNumber::prdel(ostream& os)
{
	razlog();
	kol_del = 1;
	prd = new int[kol_mn];
	prd[0] = pr[0];
	for (int i = 1; i < kol_mn; i++)
	{
		if (pr[i] != pr[i - 1])
		{
			prd[kol_del] = pr[i];
			kol_del++;
		}
	}
	for (int i = 0; i < kol_del; i++)
		os << prd[i] << " ";
}
istream& operator >> (istream& in, IntNumber& p)
{
	in >> p.field;
	return in;
}
ostream& operator<<(ostream& os, IntNumber& p)
{
	os << p.field;
	return os;
}
int main()
{
	IntNumber n;
	cin >> n;
	ofstream fout1("ѕростые делители.txt");
	fout1 << n << endl;
	n.prdel(fout1);
	fout1.close();
	ofstream fout2("ƒелители кратности 2.txt");
	fout2 << n << endl;
	n.delkr2(fout2);
	fout2.close();
	ofstream fout3("ƒелители с наименьшим произведением цифр.txt");
	fout3 << n << endl;
	n.del_min_pr(fout3);
	fout3.close();
	system("pause");
	return 0;
}
