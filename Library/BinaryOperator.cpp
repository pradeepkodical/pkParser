/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <math.h>

#include "Expression.h"
#include "BinaryOperator.h"
#include "InFunction.h"
#include "Helper.h"

CREATE_OPERATOR_CLASS_BODY(AddOperator,+);
CREATE_OPERATOR_CLASS_BODY(AndOperator,&&);
CREATE_OPERATOR_CLASS_BODY(DivOperator,/);
CREATE_OPERATOR_CLASS_BODY(EqualOperator,==);
CREATE_OPERATOR_CLASS_BODY(GEqlOperator,>=);
CREATE_OPERATOR_CLASS_BODY(GreaterOperator,>);
CREATE_OPERATOR_CLASS_BODY(LEqlOperator,<=);
CREATE_OPERATOR_CLASS_BODY(LessOperator,<);
CREATE_OPERATOR_CLASS_BODY(MinusOperator,-);
CREATE_OPERATOR_CLASS_BODY(MulOperator,*);
CREATE_OPERATOR_CLASS_BODY(NotEqlOperator,!=);
CREATE_OPERATOR_CLASS_BODY(OrOperator,||);
CREATE_OPERATOR_CLASS_BODY(SpecialMinusOperator,-);

CREATE_OPERATOR_CREATE(ModOperator);
CREATE_OPERATOR_CREATE(PowOperator);
CREATE_OPERATOR_CREATE(SpecialInOperator);

double SpecialInOperator::Solve()
{
	return ((InFunction*)rhs)->Solve(lhs);
}

double ModOperator::Solve()
{
	return ((long)lhs->Solve() % (long)rhs->Solve());
}

double PowOperator::Solve()
{
	return pow(lhs->Solve(),rhs->Solve());
}

BinaryOperator::BinaryOperator(Expression *l, Expression *r, char o)
{
	lhs = l;
	rhs = r;

	value = o;
	oper = o;
	specialOper = o;
	eType = 'O';
}
	
BinaryOperator::~BinaryOperator()
{
	if( lhs != 0) delete lhs;
	if( rhs != 0) delete rhs;
}

string BinaryOperator::toString(int tab)
{
	string str = "";
	if( !hidden )
	{


		str += Helper::GetNewlineTab(tab);
		str += "(";	
		tab++;

		str += lhs->toString(tab) + oper + rhs->toString(tab);

		str += Helper::GetNewlineTab(--tab);
		str += ")";		
		str = Helper::Replace(str, string(value), specialOper);	
	}
	return str;
};		