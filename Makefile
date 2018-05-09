# Makefile to compile a VDS
PGMS = C:/Program Files (x86)/
VCHOME = $(PGMS)microsoft visual studio/2017/community/vc/
VCBINS = $(VCHOME)Tools/MSVC/14.11.25503/bin/HostX64/x64/
CC = "$(VCBINS)"cl
LINK = "$(VCBINS)"link
KITS = $(PGMS)Windows Kits/10/
INCLUDES = "/I$(VCHOME)tools/14.11.25503/include/" "/I$(KITS)Include/10.0.15063.0/ucrt/"
CFLAGS = /DVS /c /TP "/I$(VCHOME)tools/MSVC/14.11.25503/include/" "/I$(PGMS)Windows Kits/10/Include/10.0.15063.0/ucrt/"  /D_MSDOS=yes
LIBPATH = /NXCOMPAT /DYNAMICBASE "kernel32.lib" "user32.lib"  "shell32.lib" /MACHINE:X64 /OPT:REF /INCREMENTAL:NO /SUBSYSTEM:CONSOLE /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1  "/libpath:$(KITS)Lib/10.0.15063.0/ucrt/x64/" "/libpath:$(PGMS)Windows Kits/10/Lib/14.11.25503/ucrt/x64/" "/libpath:$(PGMS)Windows Kits/8.1/Lib/winv6.3/um/x64/" "/libpath:$(VCHOME)Tools/MSVC/14.11.25503/lib/x64/" 
LINKFLAGS =   $(LIBPATH)
testx3d.exe: vs/vsmain.obj vs/Display_Type.obj vs/X3D_Color.obj vs/X3D_Coordinate.obj vs/X3D_Solid.obj vs/X3D_Sphere.obj vs/X3D_Text.obj vs/X3D_Box.obj
	$(LINK) $(LINKFLAGS) vs/vsmain.obj vs/Display_Type.obj vs/X3D_Color.obj vs/X3D_Coordinate.obj vs/X3D_Solid.obj vs/X3D_Sphere.obj vs/X3D_Text.obj vs/X3D_Box.obj

vs/vsmain.obj: vsmain.cpp  	
	$(CC) $(CFLAGS) vsmain.cpp /Fovs/vsmain.obj 
		
vs/Display_Type.obj: Display_Type.cpp Display_Type.h 	
	$(CC) $(CFLAGS) Display_Type.cpp /Fovs/Display_Type.obj 
		
vs/X3D_Color.obj: X3D_Color.cpp X3D_Color.h 	
	$(CC) $(CFLAGS) X3D_Color.cpp /Fovs/X3D_Color.obj 
		
vs/X3D_Coordinate.obj: X3D_Coordinate.cpp X3D_Coordinate.h 	
	$(CC) $(CFLAGS) X3D_Coordinate.cpp /Fovs/X3D_Coordinate.obj 
		
vs/X3D_Solid.obj: X3D_Solid.cpp X3D_Solid.h 	
	$(CC) $(CFLAGS) X3D_Solid.cpp /Fovs/X3D_Solid.obj 
		
vs/X3D_Box.obj: X3D_Box.cpp X3D_Box.h 	
	$(CC) $(CFLAGS) X3D_Box.cpp /Fovs/X3D_Box.obj 
		
vs/X3D_Sphere.obj: X3D_Sphere.cpp X3D_Sphere.h 	
	$(CC) $(CFLAGS) X3D_Sphereb.cpp /Fovs/X3D_Sphere.obj 
		
vs/X3D_Text.obj: X3D_Text.cpp X3D_Text.h 	
	$(CC) $(CFLAGS) X3D_Text.cpp /Fovs/X3D_Text.obj 
		
# Sample programs
vs/LinkedList.obj: LinkedList.cpp LinkedList.h LinkedNode.h
	$(CC) $(CFLAGS) LinkedList.cpp /Fovs/LinkedList.obj

vs/LinkedNode.obj: LinkedNode.cpp LinkedNode.h
	$(CC) $(CFLAGS) LinkedNode.cpp /Fovs/LinkedNode.obj
	