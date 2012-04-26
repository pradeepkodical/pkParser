/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#ifndef _PKMACRO_H_
#define _PKMACRO_H_

#define CREATE_OPERATOR_CLASS(CLASS_NAME,C,SC,P,H)\
class CLASS_NAME: public BinaryOperator\
{\
		friend class OperatorFactory;\
private:\
	CLASS_NAME(Expression *l, Expression *r):BinaryOperator(l,r,#@C)\
	{\
		priority = P;\
		specialOper = #SC;\
		name = #CLASS_NAME;\
		hidden = H;\
	}\
public:\
    virtual double Solve();\
	virtual BinaryOperator* Create(Expression *l, Expression *r);\
};

#define CREATE_OPERATOR_CREATE(CLASS_NAME)\
BinaryOperator* CLASS_NAME::Create(Expression *l, Expression *r)\
{\
	return new CLASS_NAME(l,r);\
}

#define CREATE_OPERATOR_SOLVE(CLASS_NAME,o)\
double CLASS_NAME::Solve()\
{\
	return (lhs->Solve() o rhs->Solve());\
}

#define CREATE_OPERATOR_CLASS_BODY(CLASS_NAME,o)\
CREATE_OPERATOR_CREATE(CLASS_NAME)\
CREATE_OPERATOR_SOLVE(CLASS_NAME,o)\


#endif
