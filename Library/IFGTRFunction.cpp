/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <vector>
#include "Expression.h"
#include "IFGTRFunction.h"

using namespace std;
IFGTRFunction::IFGTRFunction()            
{ 
	name = "IFGTR";
	useage = "IFGTR(x,y,w,z): if x > y then w else z";

	lhs = 0;
	rhs = 0;
	lcond = 0;
	rcond = 0;
}


Function* IFGTRFunction::Create(vector<Expression*> params)
{

	if( params.size() != 4)
		throw new PkException(name + string(" Insufficient parameters"));

	IFGTRFunction * func = new IFGTRFunction();
	
	func->lcond = params[0];
	func->rcond = params[1];
	func->lhs = params[2];
	func->rhs = params[3];
	return func;
}

IFGTRFunction::~IFGTRFunction()
{
	if( lcond != 0 ) delete lcond;
	if( rcond != 0 ) delete rcond;

	if( lhs != 0 ) delete lhs;
	if( rhs != 0 ) delete rhs;
}

double IFGTRFunction::Solve()
{
    return lcond->Solve() > rcond->Solve() ? lhs->Solve() : rhs->Solve();
}

string IFGTRFunction::toString(int tab)
{
	string str = name;

	
	if (lcond == 0)
		throw new PkException(string("LHS Condition empty"));
	if (rcond == 0)
		throw new PkException(string("RHS Condition empty"));

	if (lhs == 0)
		throw new PkException(string("LHS expression empty"));
	if (rhs == 0)
		throw new PkException(string("RHS expression empty"));

	
	str += Helper::GetNewlineTab(++tab);
	str += "(";
	++tab;

	str += lcond->toString(tab) + ", " + rcond->toString(tab) + ", " + lhs->toString(tab) +" ," + rhs->toString(tab);

	str += Helper::GetNewlineTab(--tab);
	str += ")";
	
	return str;
}
