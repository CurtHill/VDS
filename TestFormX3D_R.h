//---------------------------------------------------------------------------

#ifndef TestFormX3D_RH
#define TestFormX3D_RH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include "X3D.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Saveconsole1;
	TMenuItem *Clear1;
	TMenuItem *Exit1;
	TMenuItem *ests1;
	TMenuItem *Memory1;
	TMenuItem *First1;
	TMenuItem *Second1;
	TMenuItem *Simple1;
	TMenuItem *Solids1;
	TMenuItem *Scene1;
	TMenuItem *Group1;
	TMenuItem *Block1;
	TMenuItem *About1;
	TMenuItem *About2;
	TSaveDialog *SaveDialog1;
	TMemo *Memo1;
	void __fastcall Closer(TObject *Sender);
	void __fastcall SaveConsole(TObject *Sender);
	void __fastcall Clarify(TObject *Sender);
	void __fastcall Test1(TObject *Sender);
	void __fastcall Solids1Click(TObject *Sender);
	void __fastcall Scene1Click(TObject *Sender);
	void __fastcall Groupie(TObject *Sender);
	void __fastcall BlockTest(TObject *Sender);
	void __fastcall Aligner(TObject *Sender);
	void __fastcall MemoryGroup(TObject *Sender);
	void __fastcall Contain(TObject *Sender);
private:	// User declarations
	void __fastcall DoScene(bool display);
	void __fastcall DoGroup(bool display);
	void __fastcall DoBlock(bool display);
	void __fastcall DoAlign(bool display);
	void __fastcall DoContain(bool display);
    void __fastcall AddAxes(X3D & scene);

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
