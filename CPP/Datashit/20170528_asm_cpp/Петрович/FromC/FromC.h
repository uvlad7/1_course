//---------------------------------------------------------------------------

#ifndef FromCH
#define FromCH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *btLongMul;
        TEdit *Edit1;
        TButton *btSum;
        TEdit *edSum;
        TEdit *edSumIn;
        TLabel *Label1;
        TButton *btLenPlatform;
        TEdit *edLenPlatform;
        TButton *btSumArr;
        TEdit *edSumArr;
        TButton *btPower;
        TEdit *edPower;
        TButton *Button2;
        TButton *btSkipBlanks;
        TEdit *Edit2;
        TButton *Button4;
        TButton *Button5;
        TButton *btCnm;
        TButton *btCnmInCpp;
        TEdit *edCnmInCpp;
        TEdit *edCnm;
        TEdit *edN;
        TEdit *edM;
        TButton *btCnmInCppF;
        TEdit *edCnmInCppF;
        TButton *Button6;
        TEdit *Edit3;
        TButton *btCnmU;
        TEdit *edCnmU;
        TButton *btString;
        TButton *btScasb;
        TButton *btMultDiv;
        TEdit *edMult;
        TButton *Button8;
        TEdit *Edit5;
        TButton *Button9;
        TEdit *Edit6;
        TButton *btDivOverflow;
        TEdit *edDivOverflow;
        TButton *btLongMul64;
        TButton *btSumArr2;
        TButton *btFMultInt;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *edX;
        TEdit *edY;
        TEdit *edOverflowMultInt;
        TButton *btFMultInt64;
        void __fastcall btLongMulClick(TObject *Sender);
        void __fastcall btSumClick(TObject *Sender);
        void __fastcall btLenPlatformClick(TObject *Sender);
        void __fastcall btSumArrClick(TObject *Sender);
        void __fastcall btPowerClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall btSkipBlanksClick(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall btCnmClick(TObject *Sender);
        void __fastcall btCnmInCppClick(TObject *Sender);
        void __fastcall btCnmInCppFClick(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall btCnmUClick(TObject *Sender);
        void __fastcall btStringClick(TObject *Sender);
        void __fastcall btScasbClick(TObject *Sender);
        void __fastcall btMultDivClick(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall btDivOverflowClick(TObject *Sender);
        void __fastcall btLongMul64Click(TObject *Sender);
        void __fastcall btSumArr2Click(TObject *Sender);
        void __fastcall btFMultIntClick(TObject *Sender);
        void __fastcall btFMultInt64Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
