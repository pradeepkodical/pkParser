// Parser.cpp : Implementation of CParser
#include "stdafx.h"
#include "PkParserCom.h"
#include "Parser.h"

#include <string>
#include <iostream>
#include <comdef.h>

#include "Expression.h"
#include "PkParser.h"
#include "PkException.h"

/////////////////////////////////////////////////////////////////////////////
// CParser

STDMETHODIMP CParser::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IParser
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CParser::Solve(BSTR expression, double *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())


	try
	{

		double results = 0;
		
		std::string infix = _bstr_t(expression);

		Expression *exp = PkParser::Solve(infix);

		//	cout <<"Equation: " << exp->toString(0) <<endl;

		results = exp->Solve();

		//cout << results <<endl;

		delete exp;
	}
	catch(PkException *ex)
	{
		Error(ex->toString().c_str());
		return S_FALSE;
	}
	catch(...)
	{
		Error("Unknown Error");
		return S_FALSE;
	}
	
	return S_OK;
}
