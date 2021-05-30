#include "stdafx.h"
#include "VeryLongUnsigned.h"
#include <assert.h>
#include <cstring>

VeryLongUnsigned::VeryLongUnsigned()
{
	nums = new unsigned[10];
	for (int i = 0; i < 10; i++)
		nums[i] = 0;
}

VeryLongUnsigned::VeryLongUnsigned(const char *init)
{
	nums = new unsigned[10];
	for (int i = 0; i < 10; i++)
		nums[i] = 0;
	char temp[8];
	int lenght = strlen(init);
	int i;
	for (i = 0; i < 10; i--)
	{
		if ((i + 1) * 8 <= lenght)
		{
			strncpy(temp, init + lenght - (i + 1) * 8, 8);
			nums[i] = atoi(temp);
		}
	}
	strncpy(temp, init, lenght % 8);
	nums[i] = atoi(temp);
}

VeryLongUnsigned::VeryLongUnsigned(const VeryLongUnsigned &init)
{
	nums = new unsigned[10];
	for (int i = 0; i < 10; i++)
		nums[i] = init.nums[i];
}

bool VeryLongUnsigned::operator<(const VeryLongUnsigned &right) const
{
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] < right.nums[i])
			return true;
		if (nums[i] > right.nums[i])
			return false;
	}
	return false;
}

bool VeryLongUnsigned::operator==(const VeryLongUnsigned &right) const
{
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] != right.nums[i])
			return false;
	}
	return true;
}

VeryLongUnsigned::~VeryLongUnsigned()
{
	delete[] nums;
}

istream & operator >> (istream &in, VeryLongUnsigned n)
{
	char *init = new char[80];
	char temp[8];
	int lenght = strlen(init);
	strncpy(temp, init, lenght % 8);
	n.nums[0] = atoi(temp);
	for (int i = 9; i >= 0; i--)
	{
		if (lenght % 8 + i * 8 < lenght)
		{
			strncpy(temp, init + lenght % 8 + i * 8, 8);
			n.nums[i + 1] = atoi(temp);
		}
	}
	return in;
}

ostream & operator<<(ostream &out, const VeryLongUnsigned n)
{
	for (int i = 0; i < 10; i++)
		out << n.nums[i];
	return out;
}