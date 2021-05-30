// Base_element.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class point
{
	private:
		int x, y;
	public:
		point() { x, y; }
		point(int i, int j) { x = j; y = i; }
		void num(int i, int j) { x = j; y = i; }
		void operator = (point &b) { x = b.x; y = b.y; }
		int rx();
		int ry();
		bool operator ==(point& b) { return ((x == b.x) && (y == b.y)) ? true : false; }
};
int point :: rx()
{
	return x;
}
int point::ry()
{
	return y;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int  n, m;
	cout << "������� ������ �������" << endl;
	cin >> n >> m;
	int **p;
	p = new int*[n];
	for (int i = 0; i < n; i++)
		p[i] = new int[m];
	point max_on_min_str, min_on_max_stl, min_str(0, 0), max_stl(0, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> p[i][j];
		}
	}
	for (int j = 1; j < m; j++)
	{
		if (p[0][j] < p[min_str.ry()][min_str.rx()])
			min_str.num(0, j);
	}
	for (int i = 1; i < n; i++)
	{
		if (p[i][0] > p[max_stl.ry()][max_stl.rx()])
			max_stl.num(i, 0);
	}
	max_on_min_str = min_str;
	min_on_max_stl = max_stl;
	for (int i = 1; i < n; i++)
	{
		min_str.num(i, 0);
		for (int j = 1; j < m; j++)
		{
			if (p[i][j] < p[min_str.ry()][min_str.rx()])
				min_str.num(i, j);
		}
		if (p[max_on_min_str.ry()][max_on_min_str.rx()] < p[min_str.ry()][min_str.rx()])
			max_on_min_str = min_str;
	}
	for (int j = 1; j < m; j++)
	{
		max_stl.num(0, j);
		for (int i = 1; i < n; i++)
		{
			if (p[i][j] > p[max_stl.ry()][max_stl.rx()])
				max_stl.num(i, j);
		}
		if (p[min_on_max_stl.ry()][min_on_max_stl.rx()] > p[max_stl.ry()][max_stl.rx()])
			min_on_max_stl = max_stl;
	}
	if (max_on_min_str == min_on_max_stl)
		cout << "�������� ������� ��������� � ����� " << max_on_min_str.ry() + 1 << ", " << max_on_min_str.rx() + 1 << " � ����� " << p[max_on_min_str.ry()][max_on_min_str.rx()] << endl;
	else cout << "��������� �������� �� ����������." << endl << "�������� ����� ����������� ��������� ����� ��������� � ����� " << max_on_min_str.ry() + 1 << ", " << max_on_min_str.rx() + 1 << " � ����� " << p[max_on_min_str.ry()][max_on_min_str.rx()] << endl << "������� ����� ������������ ��������� �������� ��������� � ����� " << min_on_max_stl.ry() + 1 << ", " << min_on_max_stl.rx() + 1 << " � ����� " << p[min_on_max_stl.ry()][min_on_max_stl.rx()] << endl;
	for (int i = 0; i < n; i++)
		delete[] p[i];
	delete[] p;
	system("pause");
	return 0;
}