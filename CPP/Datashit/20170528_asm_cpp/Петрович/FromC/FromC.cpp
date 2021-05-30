//---------------------------------------------------------------------------

#include <vcl.h>
//#include <exception>
#include <stdexcept>
#pragma hdrstop

using namespace std;
#include "FromC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//------------------------------------------------------------------------------
// X * Y -> Y, а также return X * Y
//------------------------------------------------------------------------------
long int LongMul(int x, int& y)
{asm {
    mov     eax,x
    mov     ecx,y   ;   //  ; - не комментарий
    imul    [ecx]
    //MOV     Y,EAX
    mov     [ecx],eax
}
 //return Y;
}

//------------------------------------------------------------------------------
//  return X * Y
//------------------------------------------------------------------------------
__int64 LongMul64(int x, int y)
{asm {
      mov     eax,x
      mov     ecx,y
      imul    ecx
     }
 //return Y;
}

//------------------------------------------------------------------------------
// s = 1 + 2 + 3 + ... + n
//------------------------------------------------------------------------------
int FSum(int n)
{
 asm {
  xor eax,eax
  mov ecx,n
 c1:
  add eax,ecx
  loop c1
  }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btLongMulClick(TObject *Sender)
{
 int x = 2,
     y = 5,
     z;

 z = LongMul(x,y);

 Edit1->Text = "y=" + IntToStr(y) + " z=" + IntToStr(z);;
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btLongMul64Click(TObject *Sender)
{
     int x = 0xFFFFFFF,
         y = 0xFFFFFFF;
 __int64 z = 0xFFFFFFFFFFFFFFFFui64;
 //unsigned long long z = 0xFFFFFFFFFFFFFFFFui64;
 //long long v;

 z = LongMul64(x,y);

 //Edit1->Text = IntToStr(sizeof(v));
 Edit1->Text = "x=" + IntToStr(x) + " y=" + IntToStr(y)
               + " z=" + IntToStr(z);;
}

//------------------------------------------------------------------------------
void __fastcall TForm1::btSumClick(TObject *Sender)
{
 int s;
 int N = 5;
 N = StrToInt(edSumIn->Text);
 s = FSum(N);  // s = 1 + 2 + 3 + ... + N
 edSum->Text = IntToStr(s);
}

//------------------------------------------------------------------------------
// Найти длину самой длинной площадки
//------------------------------------------------------------------------------
int FLenPlatform (int * a,int n)
{
 asm
  { mov   ecx, n
    dec   ecx
    mov   esi, a      //  esi - адрес a[0]
    mov   ebx, esi
    add   ebx,4         // ebx - адрес a[i]   i = 1
    jecxz c3
  c1:
    mov eax, [esi]  // a[i-l] -> eax
    cmp eax, [ebx]  // a[i-l] : a[i]
    je c2
    add esi,4
  c2:
    add ebx,4
    loop c1
  c3:
    sub ebx, esi
    mov eax,ebx
    shr eax,2

  }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btLenPlatformClick(TObject *Sender)
{
 int a[] = {2,2,3,4,5,6};
 int n = sizeof(a)/sizeof(a[0]);
 int L = FLenPlatform(a,n);
 edLenPlatform->Text = IntToStr(L);
}

//------------------------------------------------------------------------------
// Сумма элементов массива a
//------------------------------------------------------------------------------
int FSumArr (int * a,int n)
{
 asm
  { mov ecx, n
    mov esi, a    // esi - адрес a[0]
    xor eax,eax
  c11:
    add eax, [esi]
    add esi,4
    loop c11
  }
}

//------------------------------------------------------------------------------
// Сумма элементов массива a
//------------------------------------------------------------------------------
int FSumArrI (int * a,int n)
{
 asm
  { mov ecx, n
    mov esi, a    // esi - адрес a[0]
    mov edi, 0
    xor eax,eax
  c11:
    add eax, [esi+edi*4]
    //add eax, [esi][edi*4]
    inc edi
    loop c11
  }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btSumArrClick(TObject *Sender)
{
 int a[] = {2,2,3,4,5,6};
 int n = sizeof(a)/sizeof(a[0]);

 int xSum = FSumArr(a,n);

 edSumArr->Text = IntToStr(xSum);
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btSumArr2Click(TObject *Sender)
{
 int a[] = {2,2,3,4,5,6};
 int n = sizeof(a)/sizeof(a[0]);

 int xSum = FSumArrI(a,n);
 
 edSumArr->Text = IntToStr(xSum);
}

//------------------------------------------------------------------------------
// FPower(int a, int m): Возвести a в степень m за log m
//------------------------------------------------------------------------------
//    c = a; b = 1; k = m;
//[И: a^m = b*c^k ]
//    while (k!=0)
//      {if (k - нечетное)
//         b = b*c;
//       k = k/2;
//       c = c*c;
//      }
//[ a^m = b ]
//------------------------------------------------------------------------------
int FPower(int a, int m)
{
 asm
  { mov    ecx, m     // m -> ecx
    mov    eax, a     // c:=a
    mov    ebx, 1     // b:=1
  lp:
    jecxz   fin
    shr    ecx,1       // k = k div 2
    jnc    cc
    // Теперь выполнить b := b * c
    push   eax
    imul   ebx       // b * c -> eax
    mov    ebx,eax   // b = b * c
    pop    eax
  cc:
    imul   eax
    jmp    lp
  fin:
    mov    eax,ebx
  }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btPowerClick(TObject *Sender)
{
 //
 int b = 2,
     m = 20;
 int s = FPower(b,m);
 edPower->Text = IntToStr(s);
}
//------------------------------------------------------------------------------

int F_NEG()
{
 asm
  {
   mov eax, 0
 c1:

   mov al,-1
   movsx ebx,al

  }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 //
 F_NEG();
}

//------------------------------------------------------------------------------
// Пропуск пробелов перед словом
//------------------------------------------------------------------------------
int FStrCmd(char * s, int n)
{
 asm
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

char * s = "";

void __fastcall TForm1::btSkipBlanksClick(TObject *Sender)
{
 // Пропуск пробелов перед словом
 if ( FStrCmd(s,0) )
   Edit2->Text = "Есть слово";
 else
   Edit2->Text = "Нет слова";
}
//------------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 char * ps1 = "abcdefghk";
}

//---------------------------------------------------------------------------
int mx = 76;

// Всякая всячина
int FTestMinus0()
{
 asm
   {mov  eax, mx
    mov   mx, eax
    lea  ebx, mx
    mov  ecx, mx + 2
    //mov  ecx, [2]
    mov  ecx, 80000000h
    mov  eax, 1
    imul ecx
    mov  ebx, ecx
    mov  eax, ecx
    mov   ax, cx
    pop  cx
    pop  ecx
    mov  eax, [ebp+8]
    mov  ebx, [eax+eax]
    mov  [eax+eax], ebx
    mov  ebx, [ecx+edx]
    mov  ebx, [ecx+edx*2]
    mov  ebx, [ecx*2+edx]+5
    mov  ebx, [ecx*2]
    mov  ebx, [ecx]
    mov  ebx, [esp+eax]
    mov  ebx, 2[esp+eax]
    mov  ebx, [esp]
    mov  ebx, [ebp+ebp]
    //mov  ebx, [esp*2+edx]     // esp не может использоваться в качестве индексного регистра
   }
}

//------------------------------------------------------------------------------
// Тестирование -0
//------------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 FTestMinus0();

}

//------------------------------------------------------------------------------
// Вычисление C(n,m) знаковое. Если результат занимает более 4-х байтов, то функция
// возвращает 0
// Примечание: умножение и деление здесь знаковые
//------------------------------------------------------------------------------
int FCnmS(int n, int m)
{
 asm
   {
    mov  eax, 1
    mov  ebx, n    // n - k + 1 -> ebx
    mov  edx, ebx
    mov  ecx, m    // m -> ecx
    sub  edx, ecx  // n - m
    cmp  edx, ecx  // n - m ? m
    jge  c0
    mov  ecx, edx  // n - m -> ecx
 c0:
    mov  esi, 1    // k
    jecxz cFin
 c1:// Cnk = Cn(k-1) * (n - k + 1) / k ;
    //  Пусть Cn(k-1) = b*k + r. Тогда Cnk = b*(n-k+1) + r(n-k+1)/k
    xor  edx,edx
    idiv esi       // eax / esi -> (eax,edx);  Cn(k-1) / k -> (b,r)
    push edx       // r -> стек
    imul ebx       // b*(n-k+1) -> eax,edx
    jnc  c3        // Переход, если результат умножения вмещается в eax
    pop  edx       // Восстановить стек
 c2:
    mov  eax, 0   // Результат = -1, если вычисление невозможно
    jmp  cFin
 c3:
    mov  edi, eax  // b*(n-k+1) -> edi
    pop  eax       // r -> eax
    mov  eax,[ebp-16]
    imul ebx       // r*(n-k+1) -> eax,edx
    idiv esi       // r*(n-k+1)/k -> eax,edx   -- edx = 0
    add  eax, edi  // r*(n-k+1)/k + b*(n-k+1)
    jo   c2
    //jc   c2
    //js   c2
    inc esi
    dec ebx
    loop c1
 cFin:
   }
}


//------------------------------------------------------------------------------
// Вычисление C(n,m) беззнаковое. Если результат занимает более 4-х байтов, то функция
// возвращает -1
//------------------------------------------------------------------------------
unsigned int FCnmU(unsigned int n, unsigned int m)
{
 asm
   {
    mov  eax, 1
    mov  ebx, n    // n - k + 1 -> ebx
    mov  edx, ebx
    mov  ecx, m    // m -> ecx
    sub  edx, ecx  // n - m
    cmp  edx, ecx  // n - m ? m
    jge  c0
    mov  ecx, edx  // n - m -> ecx
 c0:
    mov  esi, 1    // k
    jecxz cFin
 c1:// Cnk = Cn(k-1) * (n - k + 1) / k ;
    //  Пусть Cn(k-1) = b*k + r. Тогда Cnk = b*(n-k+1) + r(n-k+1)/k
    xor  edx,edx
    div  esi       // eax / esi -> (eax,edx);  Cn(k-1) / k -> (b,r)
    push edx       // r -> стек
    mul  ebx       // b*(n-k+1) -> eax,edx
    jnc  c3        // Переход, если результат умножения вмещается в eax
    pop  edx       // Восстановить стек
 c2:
    mov  eax, 0   // Результат = -1, если вычисление невозможно
    jmp  cFin
 c3:
    mov  edi, eax  // b*(n-k+1) -> edi
    pop  eax       // r -> eax
    mul  ebx       // r*(n-k+1) -> eax,edx
    div  esi       // r*(n-k+1)/k -> eax,edx   -- edx = 0
    add  eax, edi  // r*(n-k+1)/k + b*(n-k+1)
    jc   c2
    inc esi
    dec ebx
    loop c1
 cFin:
   }
}
//------------------------------------------------------------------------------

int FCnmCppS(int n, int m)
{
 int Cnm = FCnmS(n,m);
 if (Cnm == 0)
   throw out_of_range ("Переполнение");
 return Cnm;
}

//------------------------------------------------------------------------------
unsigned int FCnmCppU(unsigned int n, unsigned int m)
{
 unsigned int Cnm = FCnmU(n,m);
 if (Cnm == 0)
   throw out_of_range ("Переполнение");
 return Cnm;
}
//------------------------------------------------------------------------------

int n, m;

void __fastcall TForm1::btCnmClick(TObject *Sender)
{
 n = StrToInt(edN->Text);
 m = StrToInt(edM->Text);
 try
   {
    int Cnm = FCnmCppS(n,m);
    edCnm->Text = IntToStr(Cnm);
   }
 catch (out_of_range& e)
   {ShowMessage(e.what());
    edCnm->Text = "";
   }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btCnmInCppClick(TObject *Sender)
{
 n = StrToInt(edN->Text);
 m = StrToInt(edM->Text);
 if (m > n / 2) m = n - m;
 int Cnm = 1;
 for (int k = 1; k <= m; ++k)
   Cnm = Cnm *(n - k + 1) / k;

 edCnmInCpp->Text = IntToStr(Cnm);
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btCnmInCppFClick(TObject *Sender)
{
 n = StrToInt(edN->Text);
 m = StrToInt(edM->Text);
 if (m > n / 2) m = n - m;
 double nx = n, mx = m;
 double Cnm = 1;
 for (int k = 1; k <= m; ++k)
   Cnm = (Cnm *(n - k + 1)) / k;

 edCnmInCppF->Text = FloatToStr(Cnm);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 Edit3->Text = IntToStr(0x7FFFFFFF);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btCnmUClick(TObject *Sender)
{
 n = StrToInt(edN->Text);
 m = StrToInt(edM->Text);
 try
   {
    unsigned int Cnm = FCnmCppU(n,m);
    double CnmD = Cnm;
    //edCnmU->Text = FloatToStr(CnmD);
    edCnmU->Text = IntToStr((__int64)CnmD);
   }
 catch (out_of_range& e)
   {ShowMessage(e.what());
    edCnmU->Text = "";
   }
}

//------------------------------------------------------------------------------
int  FStrComand(char * sd,char * s, int n)
{
 asm
   {
    push ds
    pop  es
    mov  ecx,n
    mov  esi,s
    mov  edi,sd
    rep movsb
    }

}
//------------------------------------------------------------------------------

void __fastcall TForm1::btStringClick(TObject *Sender)
{
 char * s = "asd";
 char * sd = new char [strlen(s)+1];
 int n = strlen(s)+1;
 FStrComand(sd,s,n);
}
//---------------------------------------------------------------------------
int  FScasb(char * s, int n)
{
 asm
   {
    mov  al,' '
    push ds
    pop  es
    mov  ecx,n
    mov  edi,s
    repne scasb
   }
}
void __fastcall TForm1::btScasbClick(TObject *Sender)
{
 char * s = "word y";
 n = strlen(s);
 FScasb(s,n);
}

//------------------------------------------------------------------------------
//int FMultDiv (int x, int y) //, int& x1, int& y1)
short FMultDiv (short x, short y) //, int& x1, int& y1)
{
 asm
   {/*
    mov  eax, x
    mov  ebx, y
    imul ebx
    idiv ebx
    */
    mov  ax, x
    mov  bx, y
    imul bx
    idiv bx

   }
}

//------------------------------------------------------------------------------
void __fastcall TForm1::btMultDivClick(TObject *Sender)
{
 //int x = 128800, y = 250700;
 short x = 28800, y = 25700;
 //int z = FMultDiv(x,y);
 short z = FMultDiv(x,y);
 edMult->Text = IntToStr(z);
}
//------------------------------------------------------------------------------

int FExtends(int x, int y)
{
 asm
   {mov  eax, x
    cdq
    mov  ebx, y
    idiv ebx
   }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 int x = -1280000, y = 1000;
 int z = FExtends(x,y);
 Edit5->Text = IntToStr(z);
}
//------------------------------------------------------------------------------

short FExtends(short x, short y)
{
 __asm
   {mov  ax, x
    cwd
    mov  bx, y
    idiv bx

    db 0FFH
    
   }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
 short x = -28000, y = 1000;
 short z = FExtends(x,y);
 Edit6->Text = IntToStr(z);
}
//------------------------------------------------------------------------------

int FDivOverflow (int x, int y)
{
 asm
   {mov eax, x
    mov edx, y
    mov ecx, 1 //07FFFFFFFh
   }
   try
    {
     asm div ecx
    }
  catch (EIntOverflow& e)
    {
     asm mov eax, 0
     return 0;
    }
}
//------------------------------------------------------------------------------

void __fastcall TForm1::btDivOverflowClick(TObject *Sender)
{
 //
 int x = 34500, y = 17800, z;
 try
   {
    z = FDivOverflow(x,y);
    edDivOverflow->Text = IntToStr(z);
   }
  catch (EIntOverflow& e)
    {ShowMessage ("Переполнение: " + e.Message);
    }
  catch (EDivByZero& e)
    {ShowMessage ("Деление на нуль: " + e.Message);
    }
  catch (Exception& e)
    {ShowMessage ("Неожиданно: " + e.Message);
    }
}

//------------------------------------------------------------------------------
int FMultInt (int x, int y, int& z)
{
 asm
   {
    mov  eax, x
    mov  ebx, y
    //imul eax,ebx
    //imul edx,eax,0xFFFFFFF
    imul edx,x,0xFFFFFFF
    jc   m1
    mov  eax, 0
    jmp  m2
m1:
    mov  eax, 1
m2:
    mov  ecx, z
    mov  [ecx], edx
   }
}
//------------------------------------------------------------------------------

int FMultInt64 (int x, int y, __int64& z)
{
 asm
   {
    mov  eax, x
    mov  ebx, y
    mov  ecx, z
    imul ebx
    mov  [ecx], eax     // вначале младшая часть,
    mov  [ecx+4], edx   // затем старшая часть
    jc   m1
    mov  eax, 0
    jmp  m2
m1:
    mov  eax, 1
m2:
   }
}
//------------------------------------------------------------------------------


void __fastcall TForm1::btFMultIntClick(TObject *Sender)
{
 int x = 0xFFFFFFFF;
 int y = 0xFFFFFFF;

 //int x = 0x7FFFFFFF;
 //int y = 0x7FFFFFFF;
 //x = StrToInt(edX->Text);
 //y = StrToInt(edY->Text);
 edX->Text = IntToStr(x);
 edY->Text = IntToStr(y);
 int b, z;
 b = FMultInt(x,y,z);
 edMult->Text = IntToStr(z);
 if (b)
   edOverflowMultInt->Text = "Переполнение";
 else
   edOverflowMultInt->Text = "Нет переполнения";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btFMultInt64Click(TObject *Sender)
{
 //int x = 0x7FFFFFFF;
 int x = 1;
 int y = 0x7FFFFFFF;
 //int x = 777777;
 //int y = 100000;
 //x = StrToInt(edX->Text);
 //y = StrToInt(edY->Text);
 edX->Text = IntToStr(x);
 edY->Text = IntToStr(y);
     int b;
 __int64 z;
 z = 1;
 b = FMultInt64(x,y,z);
 edMult->Text = IntToStr((__int64)z);
 if (b)
   edOverflowMultInt->Text = "Переполнение";
 else
   edOverflowMultInt->Text = "Нет переполнения";
}
//---------------------------------------------------------------------------

