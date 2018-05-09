//---------------------------------------------------------------------------
#ifndef TestFormX3DH
#define TestFormX3DH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>

#include "X3D.h"

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Warranty1;
        TMenuItem *Loganerrororcomment1;
        TMemo *Memo1;
        TMenuItem *Clear1;
        TMenuItem *Contribute1;
        TMenuItem *Saveconsole1;
        TSaveDialog *SaveDialog1;
        TButton *Button1;
        TMenuItem *Tests1;
        TMenuItem *Simple1;
        TMenuItem *Solids1;
        TMenuItem *Genera1;
        TButton *Button2;
        TButton *Button3;
        TMenuItem *Memory1;
        TMenuItem *First1;
        TMenuItem *Second1;
        TMenuItem *Group1;
        TMenuItem *group21;
        TButton *Button4;
        TButton *Button5;
        void __fastcall AllDone(TObject *Sender);
        void __fastcall AboutMe(TObject *Sender);
        void __fastcall Warrant(TObject *Sender);
        void __fastcall UserLogger(TObject *Sender);
        void __fastcall Sizing(TObject *Sender);
        void __fastcall Clarify(TObject *Sender);
        void __fastcall Contribute(TObject *Sender);
        void __fastcall SaveConsole(TObject *Sender);
        void __fastcall Test1(TObject *Sender);
        void __fastcall Test2(TObject *Sender);
        void __fastcall GenScene(TObject *Sender);
        void __fastcall RepeatMe(TObject *Sender);
        void __fastcall Groupie(TObject *Sender);
        void __fastcall MemoryGroup(TObject *Sender);
        void __fastcall Activator(TObject *Sender);
        void __fastcall BlockTest(TObject *Sender);
        void __fastcall Aligner(TObject *Sender);
        void __fastcall Contain(TObject *Sender);
private:	// User declarations
        // Command line parameter stuff
        String myPath;
        bool block, group, contain, exit;


        void __fastcall DisplayAPIError(String context);
        void __fastcall DoScene(bool display);
        void __fastcall DoGroup(bool display);
        void __fastcall DoBlock(bool display);
        void __fastcall DoAlign(bool display);
        void __fastcall DoContain(bool display);
        void __fastcall AddAxes(X3D & scene);
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
