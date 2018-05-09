//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("..\OBJECTS\userlog\UserLog.cpp", UserLogWindow);
USEFORM("..\OBJECTS\about\Curt_About.cpp", CurtAbout);
USEFORM("mics.cpp", MainForm);
USELIB("..\OBJECTS\Objects.lib");
USELIB("x3d_lib.lib");
USEUNIT("tree.cpp");
USELIB("vds_lib.lib");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TUserLogWindow), &UserLogWindow);
                 Application->CreateForm(__classid(TCurtAbout), &CurtAbout);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
