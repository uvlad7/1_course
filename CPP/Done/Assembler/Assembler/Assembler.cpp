// Assembler.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	/*char a = 1;
	short int b = 30000;
	int c;
	_asm
	{
		mov al, a
		cbw
		mov cx, ax
		mov ax, b
		cwd
		idiv cx
		mov cx, ax; (cx) = b / a

		mov al, a
		cbw
		cwd
		idiv b; (ax) = a / b
		
		add ax, cx
		imul ax
		mov word ptr c, ax
		mov word ptr c + 2, dx
	}*/
	/*int c;
	_asm
	{
		mov al, a
		imul al
		cwde
		mov ecx, eax

		mov ax, b
		imul ax
		add eax, ecx
		mov c, eax;c = a^2 + b^2

		mov al, a
		cbw
		imul b;(dx:ax) = ab
		mov b, ax
		mov ax, word ptr c
		mov dx, word ptr c + 2 
		idiv b
		imul ax
		mov b, ax
	}*/
	/*cout << c << endl;*/
	/*char x = 15;
	short int y = 5;
	int z = 2147483647;
	int rez1 = 0;
	bool _cf = 0, _of = 0;
	_asm
	{
		MOV AL, x
		CBW
		CWD
		DIV y
		MOV DX, AX
		CWD
		IMUL EAX, AX
		ADD EAX, z
		JNC s1
		MOV _cf, 1
		s1:
		JNO s2
			MOV _of, 1
			s2 :
		ADD rez1, 1000
		ADD rez1, EAX
		JNC p1
			MOV _cf, 1
			p1:
			JNO p2
				MOV _of, 1
				p2 :
	}
	cout << "For signed: ";
	if (!_of)
		cout << (int)rez1 << endl;
	else cout << "incorrect, overflow" << endl;
	cout << "For unsigned: ";
	if (!_cf)
		cout << (unsigned int)rez1 << endl;
	else cout << "incorrect, carry" << endl;*/

	/////////////////////////////////////////////////////

	//bool a = 3;
	//short int b = 1;
	//int c = 2147483645;
	//int z;
	//bool _cf = 0, _of = 0;
	//x = 2147483647;
	//y = 2147483646;*/
	//_asm
	//{
	//	MOV AL, a
	//	CBW
	//	CWD
	//	DIV b
	//	MOV DX, AX
	//	CWD
	//	IMUL AX
	//	SUB EAX, c
	//	MOV z, EAX
	//	JNC p1
	//	MOV _cf, 1
	//	p1:
	//	JNO p2
	//		MOV _of, 1
	//		p2 :
	//	MOV z, EAX
	//	/*JNC c
	//	ADD _cf, 1
	//	c: 
	//	JNO o
	//	ADD _of, 1
	//	o:*/
	//}
	//cout << "For signed: ";
	//if (!_of)
	//	cout << (int)z << endl;
	//else cout << "incorrect" << endl;
	//cout << "For unsigned: ";
	//if (!_cf)
	//	cout << (unsigned int)z << endl;
	//else cout << "incorrect" << endl;
	system("pause");
    return 0;
}