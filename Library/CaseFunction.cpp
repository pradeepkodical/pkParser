/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <vector>
#include <string>
#include "Expression.h"
#include "CaseFunction.h"

using namespace std;

CaseFunction::CaseFunction()    
{
	name = "CASE";
	useage = "CASE(exp,a,x,b,y,...,z): if exp=a then x else if exp=b then y default z";	
}

Function* CaseFunction::Create(vector<Expression*> params)
{
	if (params.size() == 0)
		throw new PkException(name+ string(" Insufficient parameters"));
	
	CaseFunction* f = new CaseFunction();	
	f->params = params;
	return f;
}

CaseFunction::~CaseFunction()
{
	params.erase(params.begin(), params.end());
}

double CaseFunction::Solve()
{
	double exp = params[0]->Solve();

    for(int i = 1; i < params.size() - 1; i+=2)
	{
		if( params[i]->Solve() == exp)
		{
			return params[++i]->Solve();
		}		
	}
	return params[params.size()-1]->Solve();

}

string CaseFunction::toString(int tab)
{
	string str = name;
	int size = params.size();

	str += Helper::GetNewlineTab(++tab);
	
	str += "(";
	++tab;

	for( 
		vector<Expression*>::iterator it = params.begin();
		it < params.end();
		it ++
		)
		{
			str += (*it)->toString(tab) + (--size>0?", ":"");			
		}
	
	str += Helper::GetNewlineTab(--tab);
	str += ")";
	return str;
}

