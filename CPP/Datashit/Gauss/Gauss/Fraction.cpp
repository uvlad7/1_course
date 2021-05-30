#include "stdafx.h"
#include "Fraction.h"
#include <assert.h>

const Fraction & Fraction::reduct()
{
	assert(denominator != 0);
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	if (numerator != 0)
	{
		int a = numerator, b = denominator;
		if (a < 0)
			a = -a;
		while (b)
		{
			a %= b;
			swap(a, b);
		}
		numerator /= a;
		denominator /= a;
	}
	else
		denominator = 1;
	return *this;
}

Fraction::Fraction(int num, int den)
{
	numerator = num;
	denominator = den;
	this->reduct();
}

Fraction::Fraction(int num)
{
	numerator = num;
	denominator = 1;
}

Fraction::Fraction(const Fraction & init)
{
	numerator = init.numerator;
	denominator = init.denominator;
}

const Fraction & Fraction::operator=(const Fraction & right)
{
	numerator = right.numerator;
	denominator = right.denominator;
	return *this;
}

const Fraction & Fraction::operator+(const Fraction & right)const
{
	Fraction *temp = new Fraction(numerator*right.denominator + right.numerator*denominator, denominator*right.denominator);
	return *temp;
}

const Fraction & Fraction::operator-(const Fraction & right)const
{
	Fraction *temp = new Fraction(numerator*right.denominator - right.numerator*denominator, denominator*right.denominator);
	return *temp;
}

const Fraction & Fraction::operator*(const Fraction & right)const
{
	Fraction *temp = new Fraction(numerator*right.numerator, denominator*right.denominator);
	return *temp;
}

const Fraction & Fraction::operator/(const Fraction & right)const
{
	Fraction *temp = new Fraction(numerator*right.denominator, denominator*right.numerator);
	return *temp;
}

const Fraction & Fraction::operator+=(const Fraction & right)
{
	numerator = numerator*right.denominator + right.numerator*denominator;
	denominator *= right.denominator;
	this->reduct();
	return *this;
}

const Fraction & Fraction::operator-=(const Fraction & right)
{
	numerator = numerator*right.denominator - right.numerator*denominator;
	denominator *= right.denominator;
	this->reduct();
	return *this;
}

const Fraction & Fraction::operator*=(const Fraction & right)
{
	numerator *= right.numerator;
	denominator *= right.denominator;
	this->reduct();
	return *this;
}

const Fraction & Fraction::operator/=(const Fraction & right)
{
	numerator *= right.denominator;
	denominator *= right.numerator;
	this->reduct();
	return *this;
}

const Fraction & Fraction::operator+=(const int & right)
{
	numerator = numerator + right*denominator;
	this->reduct();
	return *this;
}

const Fraction & Fraction::operator-=(const int & right)
{
	numerator = numerator - right*denominator;
	this->reduct();
	return *this;
}

const Fraction & Fraction::operator*=(const int & right)
{
	numerator *= right;
	this->reduct();
	return *this;
}

const Fraction & Fraction::operator/=(const int & right)
{
	denominator *= right;
	this->reduct();
	return *this;
}

const Fraction & Fraction::operator+(const int & right)const
{
	Fraction *temp = new Fraction(numerator + right*denominator, denominator);
	return *temp;
}

const Fraction & Fraction::operator-(const int & right)const
{
	Fraction *temp = new Fraction(numerator - right*denominator, denominator);
	return *temp;
}

const Fraction & Fraction::operator*(const int & right)const
{
	Fraction *temp = new Fraction(numerator*right, denominator);
	return *temp;
}

const Fraction & Fraction::operator/(const int & right)const
{
	Fraction *temp = new Fraction(numerator, denominator*right);
	return *temp;
}

const Fraction & operator+(const int & left, const Fraction & right)
{
	Fraction *temp = new Fraction(right.numerator + left*right.denominator, right.denominator);
	return *temp;
}

const Fraction & operator-(const int & left, const Fraction & right)
{
	Fraction *temp = new Fraction(right.numerator - left*right.denominator, right.denominator);
	return *temp;
}

const Fraction & operator*(const int & left, const Fraction & right)
{
	Fraction *temp = new Fraction(right.numerator*left, right.denominator);
	return *temp;
}

const Fraction & operator/(const int & left, const Fraction & right)
{
	Fraction *temp = new Fraction(right.denominator, right.numerator*left);
	return *temp;
}

istream & operator >> (istream & in, Fraction & right)
{
	char fr[21], *num, *den;
	in >> fr;
	if (!strchr(fr, '/'))
	{
		num = fr;
		den = "1";
	}
	else
	{
		if (strchr(fr, '/') != &fr[0])
		{
			num = strtok(fr, "/");
			den = strtok(NULL, "/");
			if (!den)
				den = "1";
		}
		else
		{
			den = strtok(fr, "/");
			num = "1";
		}
	}
	right.numerator = atoi(num);
	right.denominator = atoi(den);
	right.reduct();
	return in;
}

ostream & operator<<(ostream & out, Fraction & right)
{
	out << right.numerator << "/" << right.denominator;
	return out;
}

bool Fraction::operator==(const int & right) const
{
	return (numerator == denominator*right) ? true : false;
}

bool Fraction::operator>=(const int & right) const
{
	return (numerator >= denominator*right) ? true : false;
}

bool Fraction::operator<=(const int & right) const
{
	return (numerator <= denominator*right) ? true : false;
}

bool Fraction::operator!=(const int & right) const
{
	return (numerator != denominator*right) ? true : false;
}

bool Fraction::operator>(const int & right) const
{
	return (numerator > denominator*right) ? true : false;
}

bool Fraction::operator<(const int & right) const
{
	return (numerator < denominator*right) ? true : false;
}

bool Fraction::operator==(const Fraction & right) const
{
	return (numerator*right.denominator == denominator*right.numerator) ? true : false;
}

bool Fraction::operator>=(const Fraction & right) const
{
	return (numerator*right.denominator >= denominator*right.numerator) ? true : false;
}

bool Fraction::operator<=(const Fraction & right) const
{
	return (numerator*right.denominator <= denominator*right.numerator) ? true : false;
}

bool Fraction::operator!=(const Fraction & right) const
{
	return (numerator*right.denominator != denominator*right.numerator) ? true : false;
}

bool Fraction::operator>(const Fraction & right) const
{
	return (numerator*right.denominator > denominator*right.numerator) ? true : false;
}

bool Fraction::operator<(const Fraction & right) const
{
	return (numerator*right.denominator < denominator*right.numerator) ? true : false;
}