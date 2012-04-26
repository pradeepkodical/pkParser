/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <vector>
#include <string>
#include <math.h>
#include "Expression.h"
#include "RoundFunction.h"

using namespace std;

RoundFunction::RoundFunction()    
{
	name = "ROUND";
	useage = "ROUND(x,y): Rounds x to y decimal places";
	lhs = 0;
	rhs = 0;
}

Function* RoundFunction::Create(vector<Expression*> params)
{
	if( params.size() != 2)
		throw new PkException(name + string(" Insufficient parameters"));

	RoundFunction* f = new RoundFunction();	
	
	f->lhs = params[0];
    f->rhs = params[1];	
	return f;
}

RoundFunction::~RoundFunction()
{
	if( lhs != 0 ) delete lhs;
	if( rhs != 0 ) delete rhs;
}

double RoundFunction::Solve()
{
	
	double l = lhs->Solve();
	int precesion = (int)rhs->Solve();
	double fac = pow(10,precesion);
	long result;

	if( l >= 0 )
	{
		result = (l + 0.5/fac)* fac;
	}
	else
	{
		result = (l - 0.5/fac)* fac;
	}    
	l = result/fac;
	return l;
}

string RoundFunction::toString(int tab)
{

	if (lhs == 0)
		throw new PkException(string("LHS expression empty"));
	if (rhs == 0)
		throw new PkException(string("RHS expression empty"));

	string str = name;	

	str += Helper::GetNewlineTab(++tab);	
	str += "(";
	++tab;

	str += lhs->toString(tab) + ", " + rhs->toString(tab);
	
	str += Helper::GetNewlineTab(--tab);
	str += ")";	
	return str;
}

