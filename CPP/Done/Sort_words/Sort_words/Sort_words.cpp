// Sort_words.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


int main()
{
	char str[40] = { "AirTransat  FedEx TWA    Quantas  PanAm" };
	char sorted[40] = { "                                       " };
	char mas[200];
	short kol = 0;
	_asm
	{
		mov esi, 0
		mov mas[2 * kol], esi
		add kol, 1
		cycle1:
		cmp esi, 40
			je end1
			cmp str[2 * esi], 32
			jne newcycle
			mov ax, si
			sub ax, mas[2 * kol]
			mov mas[2 * kol + 1], ax;�������� �����


		newcycle:
		inc esi
		jmp cycle1
			end1:
		cmp str[2 * esi], 32;����� ���������� �����
			
	}
    return 0;
}

