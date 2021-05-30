// Words_sort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	char m1[50] = "Пять четыре три два раз       электронный унитаз ";
	char m2[50] = "                             ";
	char wmap[50];
	char lofw = 0;
	int numofw = 0;
	int sum = 0;
	int lengthofmap = 0;
	bool isspace;
	if (m1[0] == ' ')
		isspace = 1;
	else isspace = 0;
	cout << "Before" << endl;
	for (int i = 0; i < 50; i++)
	{
		wmap[i] = 0;
		m2[i] = ' ';
		cout << m1[i];
	}
	cout << endl;
	_asm
	{
		lea ebx, m1
		lea edx, wmap
		mov ecx, 50
		cycle1:
		cmp[ebx], ' '
			je space_
			cmp isspace, 1
			je wasspace
			inc lofw
			jmp frw1
			wasspace :
		inc numofw
			inc lengthofmap
			mov isspace, 0
			mov al, lofw
			mov[edx], al
			inc edx
			mov lofw, 1
			jmp frw2
			space_ :
		cmp isspace, 0
			je wasspace2
			inc lofw
			jmp frw3
			wasspace2 :
		inc lengthofmap
			mov isspace, 1
			mov al, lofw
			mov[edx], al
			inc edx
			mov lofw, 1
			jmp frw4
			frw1 :
frw2:
frw3:
frw4:

		cmp ecx, 1
			je end_
			inc ebx
			end_ :
		loop cycle1



			lea edx, m2
			mov lofw, 1
			mov esi, 0
			mov edi, 0
			cycle2:
		cmp esi, lengthofmap
			jge endofedx
			mov al, lofw
			cmp wmap[esi], al
			je foundmatch
			xor eax, eax
			mov al, wmap[esi]

			add edi, eax
			inc esi
			xor eax, eax
			mov al, wmap[esi]

			add edi, eax
			inc esi
			jmp frw5
			foundmatch :
		dec numofw
			xor ecx, ecx
			mov cl, lofw
			cycle3 :
		mov al, m1[edi]
			mov[edx], al
			inc edx
			inc edi
			loop cycle3
			mov[edx], ' '
			inc edx
			inc esi
			mov al, wmap[esi]
			add edi, eax
			inc esi
			jmp notendofedx
			endofedx :
		mov esi, 0
			mov edi, 0
			inc lofw
			notendofedx :
frw5:
		cmp numofw, 0
			jne cycle2

	}
	cout << "After" << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << m2[i];
	}
	system("pause");
	return 0;
}
