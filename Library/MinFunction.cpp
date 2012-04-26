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
#include "MinFunction.h"

using namespace std;

MinFunction::MinFunction()    
{
	name = "MIN";
	useage = "MIN(x,y,w,z,....): Min value of items";	
}

Function* MinFunction::Create(vector<Expression*> params)
{
	if (params.size() == 0)
		throw new PkException(name+ string(" Insufficient parameters"));
	MinFunction* f = new MinFunction();	
	f->params = params;
	return f;
}

MinFunction::~MinFunction()
{
	params.erase(params.begin(), params.end());
}

double MinFunction::Solve()
{
    double l;
	bool first = true;
	double mi;

	for( 
		vector<Expression*>::iterator it = params.begin();
		it < params.end();
		it ++
		)
		{
			if( first )
			{
				mi = (*it)->Solve();
				first = false;
			}
			else
			{
				l = (*it)->Solve();
				if( l < mi )
				{
					mi = l;
				}
			}
		}

    return mi;
}

string MinFunction::toString(int tab)
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

