//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("..\OBJECTS\userlog\UserLog.cpp", UserLogWindow);
USEFORM("..\OBJECTS\about\Curt_About.cpp", CurtAbout);
USEFORM("TestFormVDS.cpp", MainForm);
USELIB("..\OBJECTS\Objects.lib");
USELIB("x3d_lib.lib");
USEUNIT("Visual_Data_Structure.cpp");
USEUNIT("Pointer_Based_Object.cpp");
USEUNIT("Visual_Pointer.cpp");
USEUNIT("Display_Type.cpp");
USEUNIT("LinkedList.cpp");
USEUNIT("LinkedNode.cpp");
USEUNIT("Visual_Display.cpp");
USEUNIT("CurtNode.cpp");
USEUNIT("CurtTree.cpp");
USEUNIT("Circle_List.cpp");
USEUNIT("vds_memory.cpp");
USEUNIT("PtrStatus.cpp");
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
