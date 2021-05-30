// TestCommandVC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// Здесь наверху параметр  a
// ret a*8 + b*2 + c
// НЕ освобождает стек

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
// Здесь наверху параметр  a
// ret a*8 + b*2 + c
// Освобождает стек

int __declspec(naked)  FTestParamStd (int a, int b, int c)    // __stdcall
// __declspec(naked)   - чтобы компилятор не вставлял пролог и эпилог
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
// (a,b)->(ecx,edx) Наверху стека  c
// ret (a*8 + b*2 + c)*4 + d
// Освобождает стек

int __declspec(naked) FTestParamFastcall (int a, int b, int c, int d)  //  __fastcall
{
 __asm
   {push ebp
    mov  ebp, esp
    mov  eax, ecx    // первый параметр  a
    shl  eax, 2
    add  eax, edx    // второй параметр  b
    shl  eax, 1
    add  eax, [ebp+0x08]  //             c
    shl  eax, 2
    add  eax, [ebp+0x0C]  //             d
    pop  ebp
    ret  0x0008

   }
}

//------------------------------------------------------------------------------
// Здесь наверху параметр  a
// ret a*8 + b*2 + c
// НЕ освобождает стек

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
// Здесь наверху параметр  a
// ret a*8 + b*2 + c
// Освобождает стек

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
// (a,b)->(ecx,edx) Наверху стека  c
// ret (a*8 + b*2 + c)*4 + d
// Освобождает стек

int __fastcall FTestParamFastcallImp (int a, int b, int c, int d)  //  __fastcall
{
 __asm
   {//push ebp
    //mov  ebp, esp
    mov  eax, ecx    // первый параметр  a
    shl  eax, 2
    add  eax, edx    // второй параметр  b
    shl  eax, 1
    add  eax, [ebp+0x08]  //             c
    shl  eax, 2
    add  eax, [ebp+0x0C]  //             d
    //pop  ebp
    //ret  0x0008
   }
}

//======================================= Вызовы функций для различных соглашений ===========================

//------------------------------------------------------------------------------
// Cоглашения о вызове cdecl
// - помещение параметров в стек:  справо налево
// - удаление параметров из стека: вызывающая программа
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
// Соглашение о взове __stdcall
// - помещение параметров в стек:  справо налево
// - удаление параметров из стека: вызываемая функция
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
// Соглашение о вызове __fastcall
// - первый параметр в регистр ecx
// - второй параметр в регистр edx
// - остальные параметры в стек: справа налево
// - удаление параметров из стека: вызываемая функция
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
 // (a,b)->(ecx,edx) Остальные параметры - в стек справа налево
 // наверху стека будет  с
 // Стек освобождает вызываемая функци

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
