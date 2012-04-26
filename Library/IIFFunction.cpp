/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <vector>
#include "Expression.h"
#include "IIFFunction.h"

using namespace std;
IIFFunction::IIFFunction()            
{ 
	name = "IIF";

	useage = "IIF(x>y,w,z): if x > y then w else z";
	
	lhs = 0;
	rhs = 0;
	condition = 0;
}


Function* IIFFunction::Create(vector<Expression*> params)
{
	if( params.size() != 3)
		throw new PkException(name + string(" Insufficient parameters"));

	IIFFunction * func = new IIFFunction();
	func->condition = params[0];
	func->lhs = params[1];
	func->rhs = params[2];
	return func;
}

IIFFunction::~IIFFunction()
{
	if( condition != 0 ) delete condition;
	if( lhs != 0 ) delete lhs;
	if( rhs != 0 ) delete rhs;
}

double IIFFunction::Solve()
{
    return condition->Solve()!=0? lhs->Solve() : rhs->Solve();
}

string IIFFunction::toString(int tab)
{
	string str = name;

	if (condition == 0)
		throw new PkException(string("Condition empty"));
	if (lhs == 0)
		throw new PkException(string("LHS expression empty"));
	if (rhs == 0)
		throw new PkException(string("RHS expression empty"));

	
	str += Helper::GetNewlineTab(++tab);
	str += "(";
	++tab;

	str += condition->toString(tab) + ", " + lhs->toString(tab) +" ," + rhs->toString(tab);
	
	str += Helper::GetNewlineTab(--tab);
	str += ")";
	
	return str;
}
