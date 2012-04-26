/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"

#include <vector>
#include <string>
#include  <math.h>

#include "Expression.h"
#include "AbsFunction.h"

using namespace std;

AbsFunction::AbsFunction()    
{
	name = "ABS";
	useage = "ABS(x): absolute value of x.";
	
}

Function* AbsFunction::Create(vector<Expression*> params)
{
	if (params.size() != 1)
		throw new PkException(name+ string(" Insufficient parameters"));

	AbsFunction* f = new AbsFunction();	
	f->param = params[0];
	return f;
}

AbsFunction::~AbsFunction()
{
	delete param;
}

double AbsFunction::Solve()
{
    return fabs(param->Solve());
}

string AbsFunction::toString(int tab)
{
	string str = name;
	
	str += Helper::GetNewlineTab(++tab);	
	str += "(";
	str += Helper::GetNewlineTab(++tab);

	str += param->toString(tab);

	str += Helper::GetNewlineTab(--tab);
	str += ")";	

	return str;
}

