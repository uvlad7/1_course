// SystemsAsm.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#define colosn 3
#define colreg 2
using namespace std;

extern "C" int __cdecl Syst(int*);

int main()
{
	
	int vect[colosn + 2];
	char *outinss;
	int v0 = colreg, v1 = colosn;
	

	int v2 = 8, v3 = 10, v4 = 16;//, v5 = 10, v6 = 16; //основания
	

	_asm
	{
		lea edi, v0
		mov vect[0], edi
		lea edi, v1
		mov vect[4], edi
		lea edi, v2
		mov vect[8], edi
		lea edi, v3
		mov vect[12], edi
		lea edi, v4
		mov vect[16], edi
		/*lea edi, v5
		mov vect[20], edi
		lea edi, v6
		mov vect[24], edi*/

		//mov ebx, 3
		mov ecx, 15
		mov edx, 22
		
		push edx
		push ecx
		//push ebx
		
		lea eax, vect
		push eax

		call Syst

		mov outinss, eax
		pop eax
		pop eax
		//pop eax
		pop eax
	}
	for (int i = outinss[0]; i > 0; i--)
		cout << outinss[i];
	cout << endl;
	system("pause");
    return 0;
}

