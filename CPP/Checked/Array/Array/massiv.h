#pragma once
#include "iostream"
#include "fstream"
#include <assert.h>
#include <algorithm>
using namespace std;

template <typename type = int>
class Array
{
	template <typename type>
	friend istream& operator >> (istream &in,const Array<type> &a);
	template <typename type>
	friend ostream& operator << (ostream &out,const Array<type> &a);
	friend Array<int>& operator + (const int &left, const Array<int> &right);
	friend Array<int>& operator += (const int &left, Array<int> &right);
	friend const Array<int>& operator+(const Array<int>& i);
	friend const Array<int>& operator-(const Array<int>& i);
	friend const Array<int>& operator++(Array<int>& i);
	friend const Array<int>& operator++(Array<int>& i, int);
public:
	Array(int size);
	Array(int size, type elem);
	Array(const Array &init);
	type& operator [] (int pos);
	void get(istream &in, int n);
	void get(istream &in, bool(*f)(istream&));
	void show(ostream &out, int n, int fst = 0);
	int find(int fst, int lst, type el);
	int find(type el);
	int size() { return ArraySize; }
	bool operator == (const Array &right) const;
	const Array& operator = (const Array &right);
	int getcount() { return ArrayCount; }
	~Array() { --ArrayCount; delete[] ArrayPtr; }
	const Array& operator += (const type &right);
	Array& operator + (const Array &right)const;
	const Array& operator += (const Array &right);
	Array& operator + (const type &right)const;
private:
	type *ArrayPtr;
	int ArraySize;
	static int ArrayCount;
};
template <typename type>
int Array<type>::ArrayCount = 0;
template <typename type>
Array<type>::Array(int size)
{
	++ArrayCount;
	ArraySize = size;
	ArrayPtr = new type[ArraySize];
	assert(ArrayPtr != 0);
}
template <>
Array<char>::Array(int size)
{
	++ArrayCount;
	ArraySize = size;
	ArrayPtr = new char[ArraySize + 1];
	assert(ArrayPtr != 0);
	for (int i = 0; i <= ArraySize; i++)
		ArrayPtr[i] = '\0';
}
template <>
Array<int>::Array(int size)
{
	++ArrayCount;
	ArraySize = size;
	ArrayPtr = new int[ArraySize + 1];
	assert(ArrayPtr != 0);
	for (int i = 0; i <= ArraySize; i++)
		ArrayPtr[i] = INT_MIN;
}
template <typename type>
Array<type>::Array(int size, type elem)
{
	++ArrayCount;
	ArraySize = size;
	ArrayPtr = new type[ArraySize];
	assert(ArrayPtr != 0);
	for (int i = 0; i < ArraySize; i++)
		ArrayPtr[i] = elem;
}
template <>
Array<char>::Array(int size, char elem)
{
	++ArrayCount;
	ArraySize = size;
	ArrayPtr = new char[ArraySize + 1];
	assert(ArrayPtr != 0);
	for (int i = 0; i < ArraySize; i++)
		ArrayPtr[i] = elem;
	ArrayPtr[ArraySize] = '\0';
}
template <>
Array<int>::Array(int size, int elem)
{
	++ArrayCount;
	ArraySize = size;
	ArrayPtr = new int[ArraySize + 1];
	assert(ArrayPtr != 0);
	for (int i = 0; i < ArraySize; i++)
		ArrayPtr[i] = elem;
	ArrayPtr[ArraySize] = INT_MIN;
}
template <typename type>
Array<type>::Array(const Array<type> &init)
{
	++ArrayCount;
	ArraySize = init.ArraySize;
	ArrayPtr = new type[ArraySize];
	assert(ArrayPtr != 0);
	for (int i = 0; i < ArraySize; i++)
		ArrayPtr[i] = init.ArrayPtr[i];
}
template <typename type>
const Array<type>& Array<type>::operator = (const Array<type> &right)
{
	if (&right != this)
	{
		delete[] ArrayPtr;
		ArraySize = right.ArraySize;
		ArrayPtr = new type[ArraySize];
		assert(ArrayPtr != 0);
		for (int i = 0; i < ArraySize; i++)
			ArrayPtr[i] = right.ArrayPtr[i];
	}
	return *this;
}
template <typename type>
type& Array<type>::operator [](int pos)
{
	assert((0 <= pos) && (pos < ArraySize));
	return ArrayPtr[pos];
}
template<typename type>
void Array<type>::get(istream & in, int n)
{
	for (int i = 0; i < n && i < ArraySize; i++)
		in >> ArrayPtr[i];
}
template<typename type>
void Array<type>::get(istream & in, bool(*f)(istream&))
{
	for (int i = 0; f(in) && i < ArraySize; i++)
		in >> ArrayPtr[i];
}
template<typename type>
void Array<type>::show(ostream & out, int n, int fst = 0)
{
	for (int i = 0; i + fst < ArraySize && i < n; i++)
	{
		out << ArrayPtr[i + fst];
		if (i % 10 == 9)
			out << endl;
		else out << '\t';
	}
	out << endl;
}
template<>
void Array<char>::show(ostream & out, int n, int fst)
{
	for (int i = 0; i < n && ArrayPtr[i + fst] != '\0'; i++)
	{
		out << ArrayPtr[i + fst];
		if (i % 10 == 9)
			out << endl;
		else out << '\t';
	}
	out << endl;
}
template<>
void Array<int>::show(ostream & out, int n, int fst)
{
	for (int i = 0; i < n && ArrayPtr[i + fst] != INT_MIN; i++)
	{
		out << ArrayPtr[i + fst];
		if (i % 10 == 9)
			out << endl;
		else out << '\t';
	}
	out << endl;
}
template<typename type>
int Array<type>::find(int fst, int lst, type el)
{
	int n = -1;
	for (int i = fst; i < ArraySize && i < lst && n == -1; i++)
		if (ArrayPtr[i] == el)
			n = i;
	return n;
}
template<typename type>
int Array<type>::find(type el)
{
	int n = -1;
	for (int i = 0; i < ArraySize && n == -1; i++)
		if (ArrayPtr[i] == el)
			n = i;
	return n;
}
template <typename type>
bool Array<type>::operator == (const Array<type> &right) const
{
	if (ArraySize != right.ArraySize)
		return false;
	for (int i = 0; i < ArraySize; i++)
		if (ArrayPtr[i] != right.ArrayPtr[i])
			return false;
	return true;
}
template <>
bool Array<char>::operator == (const Array<char> &right) const
{
	int i;
	for (i = 0; i <= ArraySize && i <= right.ArraySize; i++)
		if (ArrayPtr[i] != right.ArrayPtr[i])
			return false;
	return true;
}
template <>
bool Array<int>::operator == (const Array<int> &right) const
{
	int i;
	for (i = 0; i <= ArraySize && i <= right.ArraySize; i++)
		if (ArrayPtr[i] != right.ArrayPtr[i])
			return false;
	return true;
}
template <typename type>
istream& operator >> (istream &in,const Array<type> &a)
{
	for (int i = 0; i < a.ArraySize; i++)
		in >> a.ArrayPtr[i];
	return in;
}
template <typename type>
ostream& operator << (ostream &out,const Array<type> &a)
{
	for (int i = 0; i < a.ArraySize; i++)
	{
		out << a.ArrayPtr[i];
		if (i % 10 == 9)
			out << endl;
		else out << "\t";
	}
	return out;
}
template<>
ostream& operator << (ostream &out,const Array<char> &a)
{
	for (int i = 0; a.ArrayPtr[i] != '\0'; i++)
	{
		out << a.ArrayPtr[i];
		if (i % 10 == 9)
			out << endl;
		else out << "\t";
	}
	return out;
}
template<>
ostream& operator << (ostream &out,const Array<int> &a)
{
	for (int i = 0; a.ArrayPtr[i] != INT_MIN; i++)
	{
		out << a.ArrayPtr[i];
		if (i % 10 == 9)
			out << endl;
		else out << "\t";
	}
	return out;
}
template <typename type>
const Array<type>& Array<type>::operator += (const type &right)
{
	Array<type> *temp = new Array<type>(ArraySize + 1);
	for (int i = 0; i < ArraySize; i++)
		temp->ArrayPtr[i] = ArrayPtr[i];
	temp->ArrayPtr[ArraySize] = right;
	delete[] ArrayPtr;
	ArraySize = temp->ArraySize;
	ArrayPtr = new type[ArraySize];
	assert(ArrayPtr != 0);
	for (int i = 0; i < ArraySize; i++)
		ArrayPtr[i] = temp->ArrayPtr[i];
	return *this;
}
template <>
const Array<char>& Array<char>::operator += (const char &right)
{
	int i;
	for (i = 0; ArrayPtr[i] != '\0'; i++);
	if (i < ArraySize)
		ArrayPtr[i] = right;
	else
	{
		Array<char> *temp = new Array<char>(ArraySize + 1);
		int j;
		for (j = 0; j < ArraySize; j++)
			temp->ArrayPtr[j] = ArrayPtr[j];
		temp->ArrayPtr[j] = right;
		delete[] ArrayPtr;
		ArraySize = temp->ArraySize;
		ArrayPtr = new char[ArraySize + 1];
		assert(ArrayPtr != 0);
		for (j = 0; j < ArraySize; j++)
			ArrayPtr[j] = temp->ArrayPtr[j];
		ArrayPtr[j] = '\0';
	}
	return *this;
}
template <>
const Array<int>& Array<int>::operator += (const int &right)
{
	int i;
	for (i = 0; ArrayPtr[i] != INT_MIN; i++);
	if (i < ArraySize)
		ArrayPtr[i] = right;
	else
	{
		Array<int> *temp = new Array<int>(ArraySize + 1);
		int j;
		for (j = 0; j < ArraySize; j++)
			temp->ArrayPtr[j] = ArrayPtr[j];
		temp->ArrayPtr[j] = right;
		delete[] ArrayPtr;
		ArraySize = temp->ArraySize;
		ArrayPtr = new int[ArraySize + 1];
		assert(ArrayPtr != 0);
		for (j = 0; j < ArraySize; j++)
			ArrayPtr[j] = temp->ArrayPtr[j];
		ArrayPtr[j] = INT_MIN;
	}
	return *this;
}
template <typename type>
Array<type>& Array<type>::operator + (const type &right)const
{
	Array<type> *temp = new Array<type>(ArraySize + 1);
	int i;
	for (i = 0; i < ArraySize; i++)
		temp->ArrayPtr[i] = ArrayPtr[i];
	temp->ArrayPtr[i] = right;
	return *temp;
}
template <>
Array<char>& Array<char>::operator + (const char &right)const
{
	Array<char> *temp = new Array<char>(ArraySize + 1);
	int i;
	for (i = 0; ArrayPtr[i] != '\0'; i++)
		temp->ArrayPtr[i] = ArrayPtr[i];
	temp->ArrayPtr[i] = right;
	return *temp;
}
template <>
Array<int>& Array<int>::operator + (const int &right)const
{
	Array<int> *temp = new Array<int>(ArraySize + 1);
	int i;
	for (i = 0; ArrayPtr[i] != INT_MIN; i++)
		temp->ArrayPtr[i] = ArrayPtr[i];
	temp->ArrayPtr[i] = right;
	return *temp;
}
template<typename type>
Array<type> & Array<type>::operator+(const Array<type> & right) const
{
	Array<type> *temp = new Array<type>(ArraySize + right.ArraySize);
	int i, j;
	for (i = 0, j = 0; j < ArraySize; i++, j++)
		temp->ArrayPtr[i] = ArrayPtr[j];
	for (j = 0; j < right.ArraySize; i++, j++)
		temp->ArrayPtr[i] = right.ArrayPtr[j];
	return *temp;
}
template<>
Array<char> & Array<char>::operator+(const Array<char> & right) const
{
	Array<char> *temp = new Array<char>(ArraySize + right.ArraySize);
	int i, j;
	for (i = 0, j = 0; ArrayPtr[j] != '\0'; i++, j++)
		temp->ArrayPtr[i] = ArrayPtr[j];
	for (j = 0; right.ArrayPtr[j] != '\0'; i++, j++)
		temp->ArrayPtr[i] = right.ArrayPtr[j];
	return *temp;
}
template<>
Array<int> & Array<int>::operator+(const Array<int> & right) const
{
	Array<int> *temp = new Array<int>(ArraySize + right.ArraySize);
	int i, j;
	for (i = 0, j = 0; ArrayPtr[j] != INT_MIN; i++, j++)
		temp->ArrayPtr[i] = ArrayPtr[j];
	for (j = 0; right.ArrayPtr[j] != INT_MIN; i++, j++)
		temp->ArrayPtr[i] = right.ArrayPtr[j];
	return *temp;
}
template<typename type>
const Array<type> & Array<type>::operator+=(const Array<type> & right)
{
	Array<char> *temp = new Array<char>(ArraySize + right.ArraySize);
	int i, j;
	for (i = 0, j = 0; j < ArraySize; i++, j++)
		temp->ArrayPtr[i] = ArrayPtr[j];
	for (j = 0; j < right.ArraySize; i++, j++)
		temp->ArrayPtr[i] = right.ArrayPtr[j];
	delete[] ArrayPtr;
	ArraySize = temp->ArraySize;
	ArrayPtr = new char[ArraySize + 1];
	assert(ArrayPtr != 0);
	for (i = 0; i < temp->ArraySize; i++)
		ArrayPtr[i] = temp->ArrayPtr[i];
	return *this;
}
template<>
const Array<char> & Array<char>::operator+=(const Array<char> & right)
{
	Array<char> *temp = new Array<char>(ArraySize + right.ArraySize);
	int i, j;
	for (i = 0, j = 0; ArrayPtr[j] != '\0'; i++, j++)
		temp->ArrayPtr[i] = ArrayPtr[j];
	for (j = 0; right.ArrayPtr[j] != '\0'; i++, j++)
		temp->ArrayPtr[i] = right.ArrayPtr[j];
	delete[] ArrayPtr;
	ArraySize = temp->ArraySize;
	ArrayPtr = new char[ArraySize + 1];
	assert(ArrayPtr != 0);
	for (int i = 0; i <= ArraySize; i++)
		ArrayPtr[i] = '\0';
	for (i = 0; temp->ArrayPtr[i] != '\0'; i++)
		ArrayPtr[i] = temp->ArrayPtr[i];
	return *this;
}
template<>
const Array<int> & Array<int>::operator+=(const Array<int> & right)
{
	Array<int> *temp = new Array<int>(ArraySize + right.ArraySize);
	int i, j;
	for (i = 0, j = 0; ArrayPtr[j] != INT_MIN; i++, j++)
		temp->ArrayPtr[i] = ArrayPtr[j];
	for (j = 0; right.ArrayPtr[j] != INT_MIN; i++, j++)
		temp->ArrayPtr[i] = right.ArrayPtr[j];
	delete[] ArrayPtr;
	ArraySize = temp->ArraySize;
	ArrayPtr = new int[ArraySize + 1];
	assert(ArrayPtr != 0);
	for (int i = 0; i <= ArraySize; i++)
		ArrayPtr[i] = INT_MIN;
	for (i = 0; temp->ArrayPtr[i] != INT_MIN; i++)
		ArrayPtr[i] = temp->ArrayPtr[i];
	return *this;
}

Array<int>& operator+=(const int & left, Array<int>& right)
{
	for (int i = 0; right.ArrayPtr[i] != INT_MIN; i++)
		right.ArrayPtr[i] += left;
	return right;
}
Array<int>& operator + (const int &left, const Array<int> &right)
{
	Array<int> *temp = new Array<int>(right.ArraySize);
	for (int i = 0; right.ArrayPtr[i] != INT_MIN; i++)
		temp->ArrayPtr[i] = right.ArrayPtr[i] + left;
	return *temp;
}
const Array<int>& operator+(const Array<int>& i)
{
	return i;
}
const Array<int>& operator-(const Array<int>& i)
{
	for (int j = 0; i.ArrayPtr[j] != INT_MIN; j++)
		i.ArrayPtr[j] = -i.ArrayPtr[j];
	return i;
}

const Array<int>& operator++(Array<int>& i)
{
	for (int j = 0; i.ArrayPtr[j] != INT_MIN; j++)
		i.ArrayPtr[j]++;
	return i;
}

const Array<int>& operator++(Array<int>& i, int)
{
	Array<int> *temp = new Array<int>(i.ArraySize);
	for (int j = 0; i.ArrayPtr[j] != INT_MIN; j++)
		temp->ArrayPtr[j] = i.ArrayPtr[j]++;
	return *temp;
}