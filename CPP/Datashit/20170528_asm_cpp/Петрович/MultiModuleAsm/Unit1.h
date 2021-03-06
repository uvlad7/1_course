//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TEdit *Edit1;
        TButton *btSumArr;
        TEdit *edSumArr;
        TButton *btSumArrStdCall;
        TEdit *edSumArrStdCall;
        TButton *btSumArrFastCall;
        TEdit *edSumArrFastCall;
        TButton *btSumArrPascal;
        TEdit *edSumArrPascal;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall btSumArrClick(TObject *Sender);
        void __fastcall btSumArrStdCallClick(TObject *Sender);
        void __fastcall btSumArrFastCallClick(TObject *Sender);
        void __fastcall btSumArrPascalClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
