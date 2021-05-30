#pragma once
#include "iostream"
#include "fstream"
#include <assert.h>
using namespace std;

class Fraction
{
	friend const Fraction& operator + (const int &left, const Fraction &right);
	friend const Fraction& operator - (const int &left, const Fraction &right);
	friend const Fraction& operator * (const int &left, const Fraction &right);
	friend const Fraction& operator / (const int &left, const Fraction &right);
	friend istream& operator >> (istream &in, Fraction &right);
	friend ostream& operator << (ostream &out, Fraction &right);
private:
	int numerator;
	int denominator;
	const Fraction& reduct();
public:
	Fraction() {};
	Fraction(int num, int den);
	Fraction(int num);
	Fraction(const Fraction &init);
	const Fraction& operator = (const Fraction &right);
	const Fraction& operator + (const Fraction &right)const;
	const Fraction& operator - (const Fraction &right)const;
	const Fraction& operator * (const Fraction &right)const;
	const Fraction& operator / (const Fraction &right)const;
	const Fraction& operator += (const Fraction &right);
	const Fraction& operator -= (const Fraction &right);
	const Fraction& operator *= (const Fraction &right);
	const Fraction& operator /= (const Fraction &right);
	const Fraction& operator += (const int &right);
	const Fraction& operator -= (const int &right);
	const Fraction& operator *= (const int &right);
	const Fraction& operator /= (const int &right);
	const Fraction& operator + (const int &right)const;
	const Fraction& operator - (const int &right)const;
	const Fraction& operator * (const int &right)const;
	const Fraction& operator / (const int &right)const;
	bool operator == (const int &right)const;
	bool operator >= (const int &right)const;
	bool operator <= (const int &right)const;
	bool operator != (const int &right)const;
	bool operator > (const int &right)const;
	bool operator < (const int &right)const;
	bool operator == (const Fraction &right)const;
	bool operator >= (const Fraction &right)const;
	bool operator <= (const Fraction &right)const;
	bool operator != (const Fraction &right)const;
	bool operator > (const Fraction &right)const;
	bool operator < (const Fraction &right)const;
	~Fraction() {};
};