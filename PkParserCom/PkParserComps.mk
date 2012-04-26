
PkParserComps.dll: dlldata.obj PkParserCom_p.obj PkParserCom_i.obj
	link /dll /out:PkParserComps.dll /def:PkParserComps.def /entry:DllMain dlldata.obj PkParserCom_p.obj PkParserCom_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del PkParserComps.dll
	@del PkParserComps.lib
	@del PkParserComps.exp
	@del dlldata.obj
	@del PkParserCom_p.obj
	@del PkParserCom_i.obj
