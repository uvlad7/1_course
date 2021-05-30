// Factorial.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct bigint {

	static const long long BASE = 1e9;
	static const long long SIZE = 500;
	unsigned long long digits[SIZE];
	bool NUL = 0;
	bigint(unsigned long long x)
	{
		for (int i = 0; i < SIZE; i++)
		{
			digits[i] = 0;
		}
		int next = 0;
		while (x)
		{
			digits[next++] = x % BASE;
			x /= BASE;
		}
	}
	void bigint:: operator*(const int other)
	{
		for (int i = 0; i < SIZE; i++)
		{
				digits[i] = digits[i] * other;
		}

		for (int i = 0; i < SIZE - 1; i++)
		{
			digits[i + 1] += digits[i] / BASE;
			digits[i] %= BASE;
		}
		if (digits[SIZE - 1] / BASE != 0)
			NUL = true;
	}
	bool bigint:: null ()
	{
		return NUL;
	}
};

ostream& operator<<(ostream& out, const bigint& num) {
	string result;
	char buffer[10];
	for (int i = bigint::SIZE - 1; i >= 0; i--)
	{
		sprintf_s(buffer, "%09d", num.digits[i]);
		result += buffer;
	}
	int first_idx = result.find_first_not_of('0');
	if (first_idx == string::npos)
	{
		out << "0";
	}
	else
	{
		out << result.substr(first_idx).c_str();
	}
	return out;
}

void f(int n, bigint& big)
{
	if ((n != 1) && (n != 0) && (!big.null()))
	{
		big*n;
		f(n-1, big);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	bigint big(1);
	f(n, big);
	if (big.null())
		cout << "Infinity" << endl;
	else cout << n << "! = " << big << endl;
	system("pause");
    return 0;
}

