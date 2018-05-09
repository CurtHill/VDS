# Makefile to compile a VDS
PGMS = C:/Program Files (x86)/
VCHOME = $(PGMS)microsoft visual studio/2017/community/vc/
VCBINS = $(VCHOME)Tools/MSVC/14.11.25503/bin/HostX64/x64/
CC = "$(VCBINS)"cl
LINK = "$(VCBINS)"link
KITS = $(PGMS)Windows Kits/10/
INCLUDES = "/I$(VCHOME)tools/14.11.25503/include/" "/I$(KITS)Include/10.0.15063.0/ucrt/"
CFLAGS = /c /TP "/I$(VCHOME)tools/MSVC/14.11.25503/include/" "/I$(PGMS)Windows Kits/10/Include/10.0.15063.0/ucrt/"  /D_MSDOS=yes
LIBPATH = /NXCOMPAT /DYNAMICBASE "kernel32.lib" "user32.lib"  "shell32.lib" /MACHINE:X64 /OPT:REF /INCREMENTAL:NO /SUBSYSTEM:CONSOLE /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1  "/libpath:$(KITS)Lib/10.0.15063.0/ucrt/x64/" "/libpath:$(PGMS)Windows Kits/10/Lib/14.11.25503/ucrt/x64/" "/libpath:$(PGMS)Windows Kits/8.1/Lib/winv6.3/um/x64/" "/libpath:$(VCHOME)Tools/MSVC/14.11.25503/lib/x64/" 
LINKFLAGS =   $(LIBPATH)
testvds.exe: DisplayType.obj LinkedList.obj
	$(LINK) $(LINKFLAGS) DisplayType.obj LinkedList.obj      

DisplayType.obj: ..\DisplayType.cpp ..\DisplayType.h 	
	$(CC) $(CFLAGS) ../DisplayType.cpp /FoDisplayType.obj 
		
# Sample programs
LinkedList.obj: ../LinkedList.cpp ../LinkedList.h
	$(CC) $(CFLAGS) ../LinkedList.cpp /FoLinkedList.obj
