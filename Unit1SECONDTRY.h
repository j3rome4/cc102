//---------------------------------------------------------------------------

#ifndef Unit1SECONDTRYH
#define Unit1SECONDTRYH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFrame1 : public TFrame
{
__published:	// IDE-managed Components
	TLabel *Question;
	TLabel *Points;
	TLabel *Label3;
	TRadioButton *AnswerRadioButton1;
	TRadioButton *AnswerRadioButton2;
	TRadioButton *AnswerRadioButton3;
	TRadioButton *AnswerRadioButton4;
	TButton *Confirm;
	void __fastcall AnswerRadioButton1Change(TObject *Sender);
	void __fastcall AnswerRadioButton2Change(TObject *Sender);
	void __fastcall AnswerRadioButton3Change(TObject *Sender);
	void __fastcall AnswerRadioButton4Change(TObject *Sender);
	void __fastcall ConfirmClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrame1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame1 *Frame1;
//---------------------------------------------------------------------------
#endif
