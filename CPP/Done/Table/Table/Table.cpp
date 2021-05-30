// Table.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	short int i = 1, j = 1, k;
	int tkm3, tkm2;
	char m[800], d;
	for (int z = 0; z < 800; z++)
	{
		m[i] = ' ';
	}
	cout << "Osnovanie?" << endl;
	cin >> k;
	d = k;
	j = k - 1;
	tkm3 = 2 * k - 3;
	tkm2 = 2 * k - 2;
	_asm
	{

		mov cx, k
		dec cx
		cycle_out :
		mov esi, tkm3
			push cx
			mov cx, k
			dec cx
			cycle_in :
		mov ax, i
			imul j
			mov bl, d
			div bl
			cmp ah, 9
			jg lttrs1
			mov bl, ah
			add bl, 48
			jmp frnmb1
			lttrs1 :
		mov bl, ah
			add bl, 55
			frnmb1 :
			mov m[esi], bl
			dec si
			cmp al, 0
			je nol
			cmp al, 9
			jg lttrs2
			mov bl, al
			add bl, 48
			jmp frnmb2
			lttrs2 :
		mov bl, al
			add bl, 55
			frnmb2 :
			mov m[esi], bl
			jmp nenol
			nol :
		mov m[esi], ' '
			nenol :
			dec esi
			dec j
			loop cycle_in

			inc i
			mov ax, k
			dec ax
			mov j, ax
			mov eax, tkm2
			add tkm3, eax
			pop cx
			loop cycle_out
	}

	for (int z = 1; z <= 2 * (k - 1)*(k - 1); z++)
	{
		cout << m[z - 1];
		if (z % 2 == 0)
			cout << ' ';
		if (z % (2 * k - 2) == 0)
			cout << endl;
	}
	system("pause");
	return 0;
}

