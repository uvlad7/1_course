//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//------------------------------------------------------------------------------
extern "C" int DOTOTAL(int x, int y);
//extern "C" int DoTotal(int x, int y);
extern "C" int SumArr(int * a, int n);
extern "C" int __stdcall SumArrStdCall(int * a, int n);
extern "C" int __fastcall SumArrFastCall(int * a, int n);
extern "C" int __pascal SumArrPascal(int * a, int n);

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//------------------------------------------------------------------------------
int __stdcall FSum (int x, int y)
//int FSum (int x, int y)
{
 return x+y;      
}

//------------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 int a=5, b=7, c;
 c = DOTOTAL(a,b);
// c = DoTotal(a,b);
 Edit1->Text = IntToStr(c);

}
//------------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int a=5, b=7, c;
 c=FSum(a,b);
 Edit1->Text = IntToStr(c);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::btSumArrClick(TObject *Sender)
{
 int a[] = {1,2,3,4,5};
 int s;
 s = SumArr(a,5);
 edSumArr->Text = IntToStr(s);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::btSumArrStdCallClick(TObject *Sender)
{
 int a[] = {1,2,3,4,5};
 int s;
 s = SumArrStdCall(a,5);
 edSumArrStdCall->Text = IntToStr(s);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btSumArrFastCallClick(TObject *Sender)
{
 int a[] = {1,2,3,4,5};
 int s;
 s = SumArrFastCall(a,5);
 edSumArrFastCall->Text = IntToStr(s);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btSumArrPascalClick(TObject *Sender)
{
 int a[] = {1,2,3,4,5};
 int s;
 s = SumArrPascal(a,5);
 edSumArrPascal->Text = IntToStr(s);
}
//---------------------------------------------------------------------------

