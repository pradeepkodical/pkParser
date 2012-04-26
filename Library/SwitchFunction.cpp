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
#include "SwitchFunction.h"

using namespace std;

SwitchFunction::SwitchFunction()    
{
	name = "SWITCH";
	useage = "SWITCH(a=b,x,c=d,y,...,z): if a=b then x else if c=d then y else z";	
}

Function* SwitchFunction::Create(vector<Expression*> params)
{
	if (params.size() == 0)
		throw new PkException(name+ string(" Insufficient parameters"));
	
	SwitchFunction* f = new SwitchFunction();	
	f->params = params;
	return f;
}

SwitchFunction::~SwitchFunction()
{
	params.erase(params.begin(), params.end());
}

double SwitchFunction::Solve()
{
    for(int i = 0; i < params.size() - 1; i+=2)
	{
		if( params[i]->Solve() == 1)
		{
			return params[++i]->Solve();
		}		
	}
	return params[params.size()-1]->Solve();

}

string SwitchFunction::toString(int tab)
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

