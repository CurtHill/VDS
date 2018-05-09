//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("..\OBJECTS\userlog\UserLog.cpp", UserLogWindow);
USEFORM("..\OBJECTS\about\Curt_About.cpp", CurtAbout);
USEFORM("TestFormX3D.cpp", MainForm);
USELIB("..\OBJECTS\Objects.lib");
USEUNIT("X3D_Color.cpp");
USEUNIT("X3D_Coordinate.cpp");
USEUNIT("X3D_Solid.cpp");
USEUNIT("X3D_Sphere.cpp");
USEUNIT("X3D_Box.cpp");
USEUNIT("X3D.cpp");
USEUNIT("X3D_Text.cpp");
USEUNIT("X3D_Cone.cpp");
USEUNIT("X3D_Cylinder.cpp");
USEUNIT("X3D_Group.cpp");
USEUNIT("X3D_Block.cpp");
USEUNIT("X3D_Arrow.cpp");
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
