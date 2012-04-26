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
#include "InFunction.h"

using namespace std;

InFunction::InFunction()    
{
	name = "EXISTS_IN";
	useage = "a EXISTS_IN(x,y,z,...): return 1 if a is equal to x,y,z...";
}


Function* InFunction::Create(vector<Expression*> params)
{
	if (params.size() == 0)
		throw new PkException(name+ string(" Insufficient parameters"));

	InFunction* f = new InFunction();	
	f->params = params;
	return f;
}

InFunction::~InFunction()
{
	params.erase(params.begin(), params.end());
}

double InFunction::Solve()
{
    return 0;
}

double InFunction::Solve(Expression* e)
{
    	for( 
		vector<Expression*>::iterator it = params.begin();
		it < params.end();
		it ++
		)
		{
			if( (*it)->Solve() == e->Solve())
				return 1.0;
		}
		return 0.0;
}

string InFunction::toString(int tab)
{
	string str = name;
	int size = params.size();

	str += Helper::GetNewlineTab(++tab);	
	str += "(";
	str += Helper::GetNewlineTab(++tab);

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

