// Circles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int max(int a, int b) { return a>b?a:b; }

class Point {
public:
	int x;
	Point() : x(0) {}
	Point(int cx) : x(cx) {}
	Point(const Point& a) : x(a.x) {}
	Point& operator=(const Point& a) {
		if (this != &a) {
			x = a.x;
		}
		return *this;
	}
	/*
	ostream& operator<< (ostream& os, const Point& s) {
		return os << "(" << s.x << ", " << s.y << ")";
	}
	*/
};

class Circle : public Point {
public:
	int r;
	Circle() : r(0) {}
	Circle(int cx, int cr) : r(cr) { x = cx; }
	Circle(const Point& a) : r(0) { x = a.x; }
	Circle(const Point& a, int cr) : r(cr) { x = a.x; }
	Circle(const Point& a, const Point& b) : r(b.x) { x = a.x; }
	Circle(const Circle& a, const Point& b) : r(max(abs(b.x-a.x),a.r)) { x = a.x; }
	Circle(const Circle& a, const Circle& b) : r(max(abs(b.x-a.x)+b.r,a.r)) { x = a.x; }
	Circle(const Circle& a) : r(a.r) { x = a.x; }
	Circle& operator=(const Circle& a) {
		if (this != &a) {
			x = a.x;
			r = a.r;
		}
		return *this;
	}
};


Circle& operator+(const Point& a, const Point& b) {
	return *(new Circle(a,b));
}

Circle& operator+(const Circle& a, const Point& b) {
	return *(new Circle(a,b));
}

Circle& operator+(const Circle& a, const Circle& b) {
	return *(new Circle(a,b));
}

bool myCompare(Point* a, Point* b) {
	return a->x < b->x;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Point a(5);
	Point b(7);
	Point c(11);
	Circle s(20,2);
	Point* arr[10];
	s=s+b;
	cout << s.x << " " << s.r << endl;
	s=s+a;
	cout << s.x << " " << s.r << endl;
	Circle d(20);
	s=s+b+a;
	cout << s.x << " " << s.r << endl;

	for (int i=0; i<10; i++) {
		if (i%2==0)	arr[i] = new Point(rand() % 30); else arr[i] = new Circle(rand()%30, rand()%10);
		//cout << i+1 << ": ";
		//if (dynamic_cast<Circle*>(arr[i])==0) cout << "Point" << endl; else cout << "Circle" << endl;
	}
	sort(arr,arr+10,myCompare);
	for (int i=0; i<10; i++) cout << arr[i]->x << endl;
	return 0;
}

