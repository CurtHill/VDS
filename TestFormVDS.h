//---------------------------------------------------------------------------
#ifndef TestFormVDSH
#define TestFormVDSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "Visual_data_structure.h"
#include <ComCtrls.hpp>
#include "CurtTree.h"

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
        TMenuItem *Clear1;
        TMenuItem *Contribute1;
        TMenuItem *Saveconsole1;
        TSaveDialog *SaveDialog1;
        TButton *Button1;
        TMenuItem *Tests1;
        TButton *Button2;
        TButton *Button3;
        TMenuItem *Memory1;
        TRichEdit *Memo1;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TCheckBox *ViewBox;
        void __fastcall AllDone(TObject *Sender);
        void __fastcall AboutMe(TObject *Sender);
        void __fastcall Warrant(TObject *Sender);
        void __fastcall UserLogger(TObject *Sender);
        void __fastcall Sizing(TObject *Sender);
        void __fastcall Clarify(TObject *Sender);
        void __fastcall Contribute(TObject *Sender);
        void __fastcall SaveConsole(TObject *Sender);
        void __fastcall ListBuilder(TObject *Sender);
        void __fastcall Test1(TObject *Sender);
        void __fastcall TreeBuild(TObject *Sender);
        void __fastcall BuildCircular(TObject *Sender);
        void __fastcall PointerBad(TObject *Sender);
private:	// User declarations
        // Command line parameter stuff
        String myPath;

        void __fastcall DoAdd(CurtTree & badguys, AnsiString line);
        void __fastcall DisplayAPIError(String context);
public:		// User declarations
        VDS vds;

        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
