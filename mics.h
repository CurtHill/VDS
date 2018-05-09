//---------------------------------------------------------------------------
#ifndef micsH
#define micsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "tree.h"

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
        TOpenDialog *OpenDialog1;
        TButton *Button2;
        TEdit *Edit1;
        TButton *Button3;
        void __fastcall AllDone(TObject *Sender);
        void __fastcall AboutMe(TObject *Sender);
        void __fastcall Warrant(TObject *Sender);
        void __fastcall UserLogger(TObject *Sender);
        void __fastcall Sizing(TObject *Sender);
        void __fastcall Clarify(TObject *Sender);
        void __fastcall Contribute(TObject *Sender);
        void __fastcall SaveConsole(TObject *Sender);
        void __fastcall AddFile(TObject *Sender);
        void __fastcall Finder(TObject *Sender);
        void __fastcall DoIt(TObject *Sender);
private:	// User declarations
        // Command line parameter stuff
        String myPath;
        Tree all_data;
        VDS vds;

        void __fastcall DisplayAPIError(String context);
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
