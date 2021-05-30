// TestCommandVC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// ����� ������� ��������  a
// ret a*8 + b*2 + c
// �� ����������� ����

int  FTestParam (int a, int b, int c)    // cdecl _cdecl __cdecl
{
 __asm
   {//push ebp
    //mov  ebp, esp
    mov  eax, [ebp+0x08]      // a
    shl  eax, 2
    add  eax, [ebp+0x0C]      // b
    shl  eax, 1
    add  eax, [ebp+0x10]      // c
    //pop  ebp
    //ret
   }
}

//------------------------------------------------------------------------------
// ����� ������� ��������  a
// ret a*8 + b*2 + c
// ����������� ����

int __declspec(naked)  FTestParamStd (int a, int b, int c)    // __stdcall
// __declspec(naked)   - ����� ���������� �� �������� ������ � ������
{
 __asm
   {push ebp
    mov  ebp, esp
    mov  eax, [ebp+0x08]      // a
    shl  eax, 2
    add  eax, [ebp+0x0C]      // b
    shl  eax, 1
    add  eax, [ebp+0x10]      // c
    pop  ebp
    ret  0x000C
   }
}

//------------------------------------------------------------------------------
// (a,b)->(ecx,edx) ������� �����  c
// ret (a*8 + b*2 + c)*4 + d
// ����������� ����

int __declspec(naked) FTestParamFastcall (int a, int b, int c, int d)  //  __fastcall
{
 __asm
   {push ebp
    mov  ebp, esp
    mov  eax, ecx    // ������ ��������  a
    shl  eax, 2
    add  eax, edx    // ������ ��������  b
    shl  eax, 1
    add  eax, [ebp+0x08]  //             c
    shl  eax, 2
    add  eax, [ebp+0x0C]  //             d
    pop  ebp
    ret  0x0008

   }
}

//------------------------------------------------------------------------------
// ����� ������� ��������  a
// ret a*8 + b*2 + c
// �� ����������� ����

int __cdecl FTestParamImp (int a, int b, int c)    // cdecl  _cdecl __cdecl
{
 __asm
   {//push ebp
    //mov  ebp, esp
    mov  eax, [ebp+0x08]      // a
    shl  eax, 2
    add  eax, [ebp+0x0C]      // b
    shl  eax, 1
    add  eax, [ebp+0x10]      // c
    //pop  ebp
    //ret
   }
}

//------------------------------------------------------------------------------
// ����� ������� ��������  a
// ret a*8 + b*2 + c
// ����������� ����

int __stdcall FTestParamStdImp (int a, int b, int c)    // __stdcall
{
 __asm
   {//push ebp
    //mov  ebp, esp
    mov  eax, [ebp+0x08]      // a
    shl  eax, 2
    add  eax, [ebp+0x0C]      // b
    shl  eax, 1
    add  eax, [ebp+0x10]      // c
    //pop  ebp
    //ret  0x000C
   }
}

//------------------------------------------------------------------------------
// (a,b)->(ecx,edx) ������� �����  c
// ret (a*8 + b*2 + c)*4 + d
// ����������� ����

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
    //ret  0x0008
   }
}

//======================================= ������ ������� ��� ��������� ���������� ===========================

//------------------------------------------------------------------------------
// C��������� � ������ cdecl
// - ��������� ���������� � ����:  ������ ������
// - �������� ���������� �� �����: ���������� ���������
//------------------------------------------------------------------------------
int a = 1, b = 2, c = 3, d = 4, e = 5;
int FAsmCdecl()
{
 a = 1;
 int sum = 0;
 __asm
   {
    push c
    push b
    push a
    call FTestParam
    //add  esp, 0x0C
    add  esp, 0Ch
    mov  sum, eax
   }
 return sum;
}

//------------------------------------------------------------------------------
// ���������� � ����� __stdcall
// - ��������� ���������� � ����:  ������ ������
// - �������� ���������� �� �����: ���������� �������
//------------------------------------------------------------------------------
int  FAsmStdcall()
{
 a = 1;
 int sum = 0;
 __asm
   {
    push c
    push b
    push a
    call FTestParamStd
    mov  sum, eax
   }
 return sum;
}

//------------------------------------------------------------------------------
// ���������� � ������ __fastcall
// - ������ �������� � ������� ecx
// - ������ �������� � ������� edx
// - ��������� ��������� � ����: ������ ������
// - �������� ���������� �� �����: ���������� �������
//------------------------------------------------------------------------------
int FAsmFastcall()
{
 a = 1;
 int sum = 0;
 __asm
   {
    mov  ecx, a
    mov  edx, b
    push d
    push c
    call FTestParamFastcall
    mov  sum, eax
   }
 return sum;
}
//------------------------------------------------------------------------------

int FCallCdeclImp()
{
 //
 return FTestParamImp(a,b,c);  // cdecl
}
//---------------------------------------------------------------------------

int FCallStdcallImp()
{
 return FTestParamStdImp(a,b,c);  // __stdcall
}

//---------------------------------------------------------------------------
int FCallFastcallImp()
{
 // (a,b)->(ecx,edx) ��������� ��������� - � ���� ������ ������
 // ������� ����� �����  �
 // ���� ����������� ���������� ������

 return FTestParamFastcallImp(a,b,c,d);   // __fastcall
}
//---------------------------------------------------------------------------

 

int _tmain(int argc, _TCHAR* argv[])
{
 cout << "FAsmCdecl() = " <<  FAsmCdecl() << endl;
 cout << "FAsmStdcall() = " <<  FAsmStdcall() << endl;
 //cout << "FAsmPascal() = " <<  FAsmPascal() << endl;
 cout << "FAsmFastcall() = " <<  FAsmFastcall() << endl;
 cout << "FCallCdeclImp() = " <<  FCallCdeclImp() << endl;
 cout << "FCallStdcallImp() = " <<  FCallStdcallImp() << endl;
 //cout << "FCallPascalImp() = " <<  FCallPascalImp() << endl;
 cout << "FCallFastcallImp() = " <<  FCallFastcallImp() << endl;
 //decltype


return 0;
}
