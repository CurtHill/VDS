//---------------------------------------------------------------------------

#ifndef TestFVDS_RH
#define TestFVDS_RH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include "Visual_data_structure.h"
#include "CurtTree.h"
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Saveconsole1;
	TMenuItem *Clear1;
	TMenuItem *Exit1;
	TSaveDialog *SaveDialog1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TMenuItem *ests1;
	TMenuItem *Memory1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TMemo *Memo1;
	TCheckBox *ViewBox;
	void __fastcall Closer(TObject *Sender);
	void __fastcall Clarify(TObject *Sender);
	void __fastcall Saver(TObject *Sender);
	void __fastcall ListBuilder(TObject *Sender);
private:	// User declarations
	void __fastcall DoAdd(CurtTree & badguys, AnsiString line);
    VDS vds;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
