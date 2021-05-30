// Multimodule.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
extern "C" int __fastcall SumFast(int, int);
extern "C" int __stdcall SumStd(int, int*);
//extern "C" int __cdecl SumCdecl(int*, int);
//PUBLIC _SumCdecl
//_SumCdecl proc
//push ebp
//mov ebp, esp
//mov edi, [ebp + 8];адрес массива
//mov ecx, [ebp + 12];длина массива
//xor eax, eax
//xor esi, esi
//cycle2 :
//add eax, [edi + 4 * esi]
//inc esi
//loop cycle2
//pop ebp
//ret
//_SumCdecl endp

int main()
{
	int a[] = { 1, 6, 7, 8 };
	int b[] = { 5, 8, 9, 3, 9, 2 };
	cout << SumFast(a[3], b[5]) << endl;
	cout << SumStd(4, a) << endl;
	//cout << SumCdecl(b, 6) << endl;
	system("pause");
	return 0;
}