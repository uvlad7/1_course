// Stroka.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*char text[50] = { "папа мама хан  мамай. мама. ыыымама коммунист мао" };
	char words[5] = {"мама"};
	int counter;
	_asm
	{
	mov counter, 0
	mov ecx, 50
	mov al, 'м'
	lea edi, text

	cycle :
	repne scasb
	jecxz end_of_find

	mov ebx, edi
	lea esi, words
	inc esi
	push cx
	mov cx, 3
	repe cmpsb

	cmp cx, 0
	jne mama_not_find

	cmp[edi], ' '
	je mama_find
	cmp[edi], '.'
	je mama_find
	jmp mama_not_find
	mama_find :
	cmp[edi - 5], ' '
	jne mama_not_find
	inc counter
	mama_not_find :


	mov edi, ebx
	inc edi
	pop cx
	dec cx

	cmp cx, 0
	jle end_of_find
	jmp cycle
	end_of_find :
	}
	std::cout << counter << std::endl;*/

	char text[500] = { "ћчащийс€       навстречу  автомобиль  казалс€    всего  лишь    кроваво-красным    п€тном, но,      даже на  таком рассто€нии    и несмотр€   на   жжение в  радужной оболочке  левого    глаза, √аррод   умудрилс€ определить модель Ч спортивный Ђстилетї. ѕовину€сь необъ€снимому порыву, он убрал ногу с акселератора, и машина, летевша€ со скоростью  дев€носто миль  в час, стала замедл€ть ход. Ќесмотр€ на плавность движени€ водител€,    турбодвигатель    недовольно взвыл при переходе в режим наката." };
	int words[200], sentences[26], col_words, col_sentences, spaces;
	int tek, len, next, tekw, lenw;
	char longinshort[20];
	char textsp[500];
	int lentext;
_asm
{
	lea edi, text
	mov ecx, 500
	mov col_sentences, 0
	cycle1 :
	mov al, ' '
		repe scasb
		jecxz end_of_find_points
		mov esi, col_sentences
		mov sentences[esi * 8], edi
		mov sentences[esi * 8 + 4], ecx
		mov al, '.'
		repne scasb
		jecxz end_of_find_points
		mov esi, col_sentences
		sub sentences[esi * 8 + 4], ecx
		inc col_sentences
		jmp cycle1
		end_of_find_points :

	lea edi, text
		mov ecx, 500
		mov col_words, 0
		cycle2 :
		mov al, ' '
		repe scasb
		jecxz end_of_find_words
		mov esi, col_words
		mov words[esi * 8], edi
		mov words[esi * 8 + 4], ecx
		repne scasb
		mov esi, col_words
		sub words[esi * 8 + 4], ecx
		inc col_words
		cmp [edi - 2], '.'
		jne ne2
		dec words[esi * 8 + 4]
		ne2:
		jecxz end_of_find_words
		jmp cycle2
			end_of_find_words :

		xor ebx, ebx
		xor esi, esi
		mov ecx, col_words
			dec ecx
			cycle3:
		add ebx, words[esi * 8 + 8]
			sub ebx, words[esi * 8]
			sub ebx, words[esi * 8 + 4]
			dec ebx
			inc esi
			loop cycle3
			sub ebx, col_sentences
			inc ebx
			mov spaces, ebx

			mov len, 500
			mov ecx, col_sentences
			mov esi, 0
			cycle4:
		mov edx, sentences[esi * 8 + 4]
		cmp edx, len
			jge grtr
			mov edx, sentences[esi * 8 + 4]
			mov len, edx
			mov edx, sentences[esi * 8]
			mov tek, edx
			grtr:
			inc esi
			loop cycle4

			mov lenw, 0
			mov ecx, col_words
			mov esi, 0
			cycle5:
		mov edx, words[esi * 8]
		cmp edx, tek
			je end5
			dec ecx
			inc esi
			jmp cycle5
			end5:
		mov edx, tek
			add edx, len
			mov next, edx
			cycle6:
		mov edx, next
		cmp words[esi * 8], edx
			jge end6
			mov edx, lenw
		cmp words[esi * 8 + 4], edx
			jle ifless
			mov edx, words[esi * 8 + 4]
			mov lenw, edx
			mov edx, words[esi * 8]
			mov tekw, edx
			ifless:
			inc esi
			loop cycle6
				end6:

			cld
				mov esi, tekw
				dec esi
				lea edi, longinshort
				mov ecx, lenw
				rep movsb

				mov ecx, col_words
				xor esi, esi
				mov lentext, 0
				cycle7:
				push ecx
				push esi
				lea edi, textsp
				add edi, lentext
				mov ecx, words[esi * 8 + 4]
				mov edx, words[esi * 8]
				dec edx
				mov esi, edx
				cmp [esi + ecx], '.'
				jne notpoint
				inc ecx
					notpoint:
				inc ecx
				add lentext, ecx
					cld
				rep movsb
					pop esi
					pop ecx
					inc esi
					loop cycle7
}
cout << col_sentences << endl;
for (int i = 1; i < 2 * col_sentences; i += 2)
	cout << sentences[i] << " ";
cout << endl;
cout << spaces << endl;
for (int i = 0; i < lenw; i++)
	cout << longinshort[i];
cout << endl;
for (int i = 0; i < lentext; i++)
	cout << textsp[i];
cout << endl;
system("pause");
return 0;
}

