#pragma once
#include "iostream"
#include "fstream"
#include <assert.h>
using namespace std;

class VeryLongUnsigned
{
	friend istream& operator >> (istream&, VeryLongUnsigned);
	friend ostream& operator << (ostream&, const VeryLongUnsigned);
private:
	unsigned *nums;
public:
	VeryLongUnsigned();
	VeryLongUnsigned(const char*);
	VeryLongUnsigned(const VeryLongUnsigned&);
	bool operator < (const VeryLongUnsigned&) const;
	bool operator == (const VeryLongUnsigned&) const;
	~VeryLongUnsigned();
};