// Parser.h : Declaration of the CParser

#ifndef __PARSER_H_
#define __PARSER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CParser
class ATL_NO_VTABLE CParser : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CParser, &CLSID_Parser>,
	public ISupportErrorInfo,
	public IDispatchImpl<IParser, &IID_IParser, &LIBID_PKPARSERCOMLib>
{
public:
	CParser()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PARSER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CParser)
	COM_INTERFACE_ENTRY(IParser)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IParser
public:
	STDMETHOD(Solve)(BSTR infix, /*[out, retval]*/ double *pVal);
};

#endif //__PARSER_H_
