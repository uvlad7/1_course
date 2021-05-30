// TestMultiMod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

extern "C" int SumArr(int * a, int n);

int _tmain(int argc, _TCHAR* argv[])
{
 int a[] = {1,2,3,4,5};
 int s;
 s = SumArr(a,5);
 cout << s << endl;
 system("pause");
 return 0;
}

