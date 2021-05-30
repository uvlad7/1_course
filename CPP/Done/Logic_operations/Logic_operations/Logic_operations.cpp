// Logic_operations.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	/*int kolvedinic = 0, number;
	cout << "Enter something" << endl;
	cin >> number;
	_asm
	{
		mov ebx, 1
		mov edx, number
		mov ecx, 32
		out_cycle:
		test edx, ebx
			jz null_
			inc kolvedinic
	null_:
		shl ebx, 1
			loop out_cycle
	}
	cout <<"Edinic: " << kolvedinic << endl;*/

	//////////////////////////////////////////////////

	/*int a, kol = 0;
	_asm
	{
		mov a, 0xfedcba21
		mov ebx, 1
		mov eax, a
		mov ecx, 8
		out_cycle:
		test eax, ebx
			jnz nechet
			inc kol
			nechet:
		shl ebx, 4
			loop out_cycle
	}
	cout << "Chetnuh chifr: " << kol << endl;*/

	////////////////////////////////////////////

	/*int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int col, sum;
	_asm
	{
		mov col, 0
		mov sum, 0
		xor esi, esi
		mov ecx, 10

		maincycle :
		test A[esi], 1
			jnz nechet
			mov eax, A[esi]
			add sum, eax
			inc col
			nechet:
		add esi, 4
			loop maincycle
	}
	cout << col << " " << sum << endl;*/

	////////////////////////////////////////////

	short int x, n, y;
	cin >> x >> n;
	_asm
	{
		mov y, 1
		mov bx, 1
		mov ecx, 16
		mov ax, x

		out_cycle:
		test n, bx
			jz null_
			
			push ax
			mul y
			jo ovf
			mov y, ax
			pop ax
			
			null_ :
		mul ax
		shl bx, 1
			loop out_cycle
			jmp norm
			ovf:
		mov y, 0
			norm:
	}
	cout << y << endl;
	system("pause");
    return 0;
}

