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
#include "AvgFunction.h"

using namespace std;

AvgFunction::AvgFunction()    
{
	name = "AVG";
	useage = "AVG(x,y,z,...): average value of items.";
}


Function* AvgFunction::Create(vector<Expression*> params)
{
	if (params.size() == 0)
		throw new PkException(name+ string(" Insufficient parameters"));

	AvgFunction* f = new AvgFunction();	
	f->params = params;
	return f;
}

AvgFunction::~AvgFunction()
{
	params.erase(params.begin(), params.end());
}

double AvgFunction::Solve()
{
    int l = 0;	
	double sm = 0;

	for( 
		vector<Expression*>::iterator it = params.begin();
		it < params.end();
		it ++
		)
		{
			sm += (*it)->Solve();
			l++;
		}

    return sm/l;
}

string AvgFunction::toString(int tab)
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

