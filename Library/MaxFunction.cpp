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
#include "MaxFunction.h"

using namespace std;

MaxFunction::MaxFunction()    
{
	name = "MAX";
	useage = "MAX(x,y,w,z,....): Max value of items";
}

Function* MaxFunction::Create(vector<Expression*> params)
{
	if (params.size() == 0)
		throw new PkException(name+ string(" Insufficient parameters"));

	MaxFunction* f = new MaxFunction();	
	f->params = params;
	return f;
}

MaxFunction::~MaxFunction()
{
	params.erase(params.begin(), params.end());
}

double MaxFunction::Solve()
{
    double l;
	bool first = true;
	double mx;

	for( 
		vector<Expression*>::iterator it = params.begin();
		it < params.end();
		it ++
		)
		{
			if( first )
			{
				mx = (*it)->Solve();
				first = false;
			}
			else
			{
				l = (*it)->Solve();
				if( l > mx )
				{
					mx = l;
				}
			}
		}

    return mx;
}

string MaxFunction::toString(int tab)
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

