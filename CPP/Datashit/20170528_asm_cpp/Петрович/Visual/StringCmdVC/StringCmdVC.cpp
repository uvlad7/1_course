// StringCmdVC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// Сосчитать число слов в строке
//------------------------------------------------------------------------------
int FCountWord (char * s, int n)
{
 __asm
   {  mov edi,s
      //mov esi,edi
      //inc esi
      //mov al,[edi]
      //cmp al,[esi]
      //sub al,[esi]
      //cmpsb
      mov ecx,n
      xor ebx,ebx
      mov al,' '
      cld
    c1:
      //jecxz fin
      test al,1
      repe  scasb      // пропустить пробелы
      je    fin
      // Находимся в начале ненулевого слова
      inc ebx
      repne scasb
      jmp c1
    fin:
      mov eax,ebx
   }
}

// Умножить элементы массива на 2
void FMultByTwo(int * a, int n)
{__asm
   {
       mov   ecx, n
	   jmp   c00 
c0:
	   mov   edi, a
	   mov   esi, edi
	   ret
c00:
	   call c0
	   cld
       jecxz fin
c1:    
	   lodsd
	   shl   eax,1
	   stosd
	   loop  c1
fin:
   }
}


int _tmain(int argc, _TCHAR* argv[])
{
	//char * s = "as  d  f g ery  ";
	//char * s = "";
	char * s = "a";
	int n = strlen(s);
	cout << FCountWord(s, n) << endl; 
	int a[] = {1,2,3,4,5};
	int m = sizeof(a)/sizeof(a[0]);
    FMultByTwo(a,m);
	for (int i = 0; i<m; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

