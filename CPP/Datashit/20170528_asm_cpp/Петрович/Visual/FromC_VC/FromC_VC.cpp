// FromC_VC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
//------------------------------------------------------------------------------
// s = 1 + 2 + 3 + ... + n
//------------------------------------------------------------------------------
int FSum(int n)
{// push ebp     ���������� ��������� ���
 // mov ebp, esp ���������� ��������� ���
 // eax, ecx, edx ��������� �� ���� �������
 // ��� ������ ���������� �������� ��� ���� � �� ���� ������������

 __asm {
  xor eax,eax
  mov ecx,n
  // mov ecx, [ebp+8] ; +8 �.�. � ����� ����������� ����� �������� � ���
 c1:
  add eax,ecx
  loop c1
  }         ; ��������� ������ ����������(�����������) � ���
}
//------------------------------------------------------------------------------
// ������� �������� ����� ������
//------------------------------------------------------------------------------
int FStrCmd(char * s, int n)
{
 __asm
   {
    push  ds
    pop   es
    mov   edi, s
    mov   eax, ' '
    cld
 c1:
    mov   ecx, n
    xor   edx,edx
    repe  scasb
    jnz   c2
    mov   eax,0
    jmp   c3
 c2:
    mov   eax,1
 c3:
   }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// (a,b)->(ecx,edx) ������� �����  �
// ret (a*8 + b*2 + c)*4 + d

int __fastcall FTestParamFastcallImp (int a, int b, int c, int d)  //  __fastcall
{
 __asm
   {//push ebp
    //mov  ebp, esp
    mov  eax, ecx    // ������ ��������  a
    shl  eax, 2
    add  eax, edx    // ������ ��������  b
    shl  eax, 1
    add  eax, [ebp+0x08]  //             c
    shl  eax, 2
    add  eax, [ebp+0x0C]  //             d
    //pop  ebp
    //ret 8
   }
}

int _tmain(int argc, _TCHAR* argv[])
{   int a = 1, b = 2, c = 3, d = 4;
    cout << FSum(5) << endl;
	char * s = "   fgd  jj  ";
	int n = strlen(s);
	cout << FStrCmd(s, n) << endl;
	int m;
	m = FTestParamFastcallImp(a, b, c, d);
	cout << m << endl;
	return 0;
}

