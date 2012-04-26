# Microsoft Developer Studio Project File - Name="PkParserLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=PkParserLib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PkParserLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PkParserLib.mak" CFG="PkParserLib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PkParserLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "PkParserLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PkParserLib - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "PkParserLib - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "PkParserLib - Win32 Release"
# Name "PkParserLib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Functions"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\AbsFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\AvgFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\CaseFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\FunctionFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\IFEQLFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\IFGTRFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\IIFFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\InFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\MaxFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\MinFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\RoundFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\SwitchFunction.cpp
# End Source File
# End Group
# Begin Group "Operators"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\BinaryOperator.cpp
# End Source File
# Begin Source File

SOURCE=.\OperatorFactory.cpp
# End Source File
# End Group
# Begin Group "PkParser"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\Expression.cpp
# End Source File
# Begin Source File

SOURCE=.\Helper.cpp
# End Source File
# Begin Source File

SOURCE=.\PkException.cpp
# End Source File
# Begin Source File

SOURCE=.\PkParser.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "PkParserHeader"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=.\Expression.h
# End Source File
# Begin Source File

SOURCE=.\Helper.h
# End Source File
# Begin Source File

SOURCE=.\PkException.h
# End Source File
# Begin Source File

SOURCE=.\PkMacro.h
# End Source File
# Begin Source File

SOURCE=.\PkParser.h
# End Source File
# End Group
# Begin Group "FunctionsHeader"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=.\AbsFunction.h
# End Source File
# Begin Source File

SOURCE=.\AvgFunction.h
# End Source File
# Begin Source File

SOURCE=.\CaseFunction.h
# End Source File
# Begin Source File

SOURCE=.\Function.h
# End Source File
# Begin Source File

SOURCE=.\FunctionFactory.h
# End Source File
# Begin Source File

SOURCE=.\IFEQLFunction.h
# End Source File
# Begin Source File

SOURCE=.\IFGTRFunction.h
# End Source File
# Begin Source File

SOURCE=.\IIFFunction.h
# End Source File
# Begin Source File

SOURCE=.\InFunction.h
# End Source File
# Begin Source File

SOURCE=.\MaxFunction.h
# End Source File
# Begin Source File

SOURCE=.\MinFunction.h
# End Source File
# Begin Source File

SOURCE=.\RoundFunction.h
# End Source File
# Begin Source File

SOURCE=.\SwitchFunction.h
# End Source File
# End Group
# Begin Group "OperatorsHeader"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=.\BinaryOperator.h
# End Source File
# Begin Source File

SOURCE=.\OperatorFactory.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Readme.txt
# End Source File
# End Target
# End Project
