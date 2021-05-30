// TestMultiMod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

extern "C" int SumArr(int * a, int n);
extern "C" int __stdcall SumArrStdCall(int * a, int n);
extern "C" int __fastcall SumArrFastCall(int * a, int n);
//extern "C" int __pascal SumArrPascal(int * a, int n);

int _tmain(int argc, _TCHAR* argv[])
{
 int a[] = {1,2,3,4,5};
 int s, sStd, sFast, sPascal;
 s = SumArr(a,5);
 cout << "s = " << s << endl;
 sStd = SumArrStdCall(a,5);
 cout << "sStd = " << sStd << endl;
 sFast = SumArrFastCall(a,5);
 cout << "sFast = " << sFast << endl;
 /*
 sPascal = SumArrPascal(a,5);
 cout << "sPascal = " << sPascal << endl;
 */
 system("pause");
 return 0;
}

