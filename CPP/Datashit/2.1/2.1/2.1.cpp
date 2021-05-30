// 2.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

class point
{
protected:
	double x;
	double y;
public:
	point(double a, double b) { x = a; y = b; }
	double getx() { return x; }
	double gety() { return y; }
	point& operator += (const point &r);
	point& operator + (otr &r);
	bool operator == (const point &r);
	virtual bool operator < (const point &r);
	~point() {};
};

class otr : public point
{
protected:
	double l;
public:
	otr(double a, double b, double c) : point(a, b) { l = c; }
	double getl() { return l; }
	otr& operator += (const otr &r);
	otr& operator + (point &r);
	bool operator == (otr &r);
	bool operator <= (otr &r);
	virtual bool operator < (otr &r);
	~otr() {};
};

point& point::operator+=(const point & r)
{
	assert(y == r.y);
	x = (x + r.x) / 2;
	return *this;
}

otr & otr::operator+=(const otr & r)
{
	assert(y == r.y);
	if (x <= r.x)
		l = max(r.x - x + r.l, l);
	else
	{
		l = max(x - r.x + l, r.l);
		x = r.x;
	}
	return *this;
}

point & point::operator+(otr &r)
{
	assert(y == r.y);
	if (x <= r.x)
	{
		point i(x + (r.x - x + r.getl()) / 2, y);
		return i;
	}
	else
	{
		point i(r.x + max(x - r.x, r.getl()) / 2, y);
		return i;
	}
}

otr & otr::operator+(point & r)
{
	assert(y == r.gety());
	if (x <= r.getx())
	{
		otr i(x, y, max(l, r.getx() - x));
		return i;
	}
	else
	{
		otr i(r.getx(), y, x - r.getx() + l);
		return i;
	}
}

bool point::operator==(const point & r)
{
	return ((x == r.x) && (y == r.y)) ? true : false;
}

bool otr::operator==(otr & r)
{
	return (l == r.l) ? true : false;
}

bool otr::operator<=(otr & r)
{
	return (l <= r.l) ? true : false;
}

bool otr::operator<(otr & r)
{
	return (l < r.l) ? true : false;
}

bool point::operator<(const point & r)
{
	return (x*x + y*y < r.x*r.x + r.y*r.y) ? true : false;
}

int main()
{
	point **m = new point*[10];
	m[0] = new point(1, 3);
	m[1] = new otr(2, 3, 3);
	m[2] = new otr(4, 3, 4);
	m[3] = new point(2, 3);
	m[4] = &(*m[3] + *(static_cast <otr*>(m[1])));
	m[5] = &(*(static_cast <otr*>(m[1])) + *m[0]);
	m[6] = new point(6, 4);
	m[7] = new point(9, 4);
	m[8] = new otr(2, 4, 10);
	m[9] = &(*m[7] + *(static_cast <otr*>(m[8])));
	*m[8] += *m[7];
	*m[2] += *m[1];
	for (int i = 0; i < 9; i++)
	{
		if (m[i] < m[i + 1])
			cout << i << " " << i + 1 << endl;
	}
	return 0;
}