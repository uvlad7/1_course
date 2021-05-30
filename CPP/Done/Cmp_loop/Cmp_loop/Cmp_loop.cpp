// Cmp_loop.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	/*int sum;
	char i, j;
	_asm
	{
		mov sum, 0
		mov i, 1
		cycle1:
		cmp i, 10
			jg end_cycle1
			mov j, 91
			mov al, i
			imul al
			cwde//(eax) = i ^ 2
			mov ecx, eax
			cycle2 :
			cmp j, 100
			jg end_cycle2
			add sum, ecx
			mov al, j
			cbw
			cwde//(eax) = j
			add sum, eax
			inc j
			jmp cycle2
			end_cycle2 :
		inc i
			jmp cycle1
			end_cycle1 :
	}*/

	/*short int i;
	int sum, j;
	sum;
	_asm
	{
	mov sum, 0
	mov eax, 0
	mov cx, 10
	cycle13:
	mov i, cx
	mov ecx, 10
	cycle23 :
	mov ax, i
	imul ax
	mov ebx, 101
	sub ebx, ecx
	add eax, ebx
	add sum, eax
	loop cycle23
	mov cx, i
	loop cycle13
	}
	cout << sum << endl;*/

//////////////////////////////////////////////////////////////////////

	/**int A[5] = { 0,0, 0, 0, 0 }, B[5] = { 2,4,5,8,10 }, i = 1, j = 1, k = 1, C[10];
	for (int i = 0; i < 10; i++)
	C[i] = 0;
	_asm
	{
	mov eax, 0
	mov esi, 0
	mov ebx, 0
	mov ecx, 0

	maincycle:
	cmp i, 5
	jg work2
	cmp j, 5
	jg work1
	mov eax, A[ebx]
	cmp  eax,  B[ecx]
	jle work1
	work2 : mov eax, B[ecx]
	mov C[esi], eax
	add ecx, 4
	add esi, 4
	inc k
	inc j
	jmp endof

	work1 : mov eax, A[ebx]
	mov C[esi], eax
	add ebx, 4
	add esi, 4
	inc k
	inc i
	endof :
	cmp k, 10
	jle maincycle
	}
	for (int h = 0; h < 10; h++)
	cout << C[h] << " ";
	cout << endl;**/

//////////////////////////////////////////////////////////////////////

	/**int A[10] = { 0, 5, 2, 0, 4, -5, -7, 10, 9, -1 };
	int sum1, sum3, avr3;
	short int col2, col3;
	_asm
	{
	mov esi, 0
	mov sum1, 0
	mov sum3, 0
	mov col2, 0
	mov col3, 0

	maincycle:
	cmp A[esi], 0
	jg ifgrtr
	jl iflss
	je ifeql
	ifgrtr :
	mov eax, A[esi]
	add sum1, eax
	jmp endcycle
	iflss :
	mov eax, A[esi]
	add sum3, eax
	add col3, 1
	jmp endcycle
	ifeql :
	add col2, 1
	jmp endcycle
	endcycle :
	add esi, 4
	cmp esi, 40
	jl maincycle
	}
	cout << sum1 << " " << col2 << " " << sum3/col3;**/

//////////////////////////////////////////////////////////////////////

	//short int B[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	///*for (int i = 0; i < 100; i++)
	//	B[i] = rand() % 200;*/
	//_asm
	//{
	//	mov eax, 0
	//	mov ebx, 16
	//	maincycle:
	//	cmp eax, ebx
	//		jge eofcl
	//		mov cx, B[eax]
	//		mov dx, B[ebx]
	//		mov B[eax], dx
	//		mov B[ebx], cx
	//	add eax, 2
	//	sub ebx, 2
	//	jmp maincycle
	//		eofcl:
	//}
	//for (int i = 0; i < 9; i++)
	//	cout<<B[i]<<" ";

//////////////////////////////////////////////////////////////////////

	/*short int a[10] = { 10, 4, 3, 7, 11, 9, 4, 8, 5, 8 };
	_asm
	{
		mov cx, 9
		povt: push cx
			  mov esi, 0
			  cycle : mov ax, a[esi]
					  cmp ax, a + 2[esi]
					  jng nxt
					  push a[esi]
					  push a + 2[esi]
					  pop a[esi]
					  pop a + 2[esi]
					  nxt: add si, 2
						   loop cycle
						   pop cx
						   loop povt
	}
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";*/

//////////////////////////////////////////////////////////////////////

int m[10] = { 1, 3, 5, 7, 10, 2, 4, 6, 8, 9 };
_asm
{
	lea ebx, m
	mov ecx, 9
	i_for:
	mov esi, 0
	push ecx
	j_for:
	mov eax, [ebx + esi * 4]
	mov edx, [ebx + esi * 4 + 4]
	cmp eax, edx
	jle noswap
	mov[ebx + esi * 4], edx
	mov[ebx + esi * 4 + 4], eax
	noswap:
	inc esi
	loop j_for
	pop ecx
	loop i_for
}
cout << "Ascending:" << endl;
for (int i = 0; i < 10; i++)
	cout << m[i] << " ";


	system("pause");
	return 0;
}

