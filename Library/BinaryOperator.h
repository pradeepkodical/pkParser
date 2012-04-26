/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _BINARYOPERATOR_H_
#define _BINARYOPERATOR_H_

#include "Expression.h"
#include "PkMacro.h"


///This is a Node in the tree
class BinaryOperator: public Expression
{
protected:
	Expression *lhs;
    char oper;
	string specialOper;
    Expression *rhs;
	int priority;
	string name;
	int hidden;

	BinaryOperator(Expression *l, Expression *r, char o);
	
	virtual ~BinaryOperator();

public:
	char Oper(){return oper;}
	string SpecialOper(){return specialOper;}
	int Hidden(){return hidden;}
	int Priority(){return priority;}
	string Name(){return name;}
	virtual BinaryOperator *Create(Expression *lhs, Expression *rhs)=0;
	virtual double Solve()=0;
	virtual string toString(int tab);	
};

CREATE_OPERATOR_CLASS(SpecialMinusOperator,-,~,40,0);


CREATE_OPERATOR_CLASS(DivOperator,/,/,30,0);
CREATE_OPERATOR_CLASS(PowOperator,^,^,30,0);
CREATE_OPERATOR_CLASS(ModOperator,%,%,30,0);
CREATE_OPERATOR_CLASS(MulOperator,*,*,30,0);

CREATE_OPERATOR_CLASS(AddOperator,+,+,20,0);
CREATE_OPERATOR_CLASS(MinusOperator,-,-,20,0);


CREATE_OPERATOR_CLASS(EqualOperator,=,=,15,0);
CREATE_OPERATOR_CLASS(GEqlOperator,],>=,15,0);
CREATE_OPERATOR_CLASS(GreaterOperator,>,>,15,0);
CREATE_OPERATOR_CLASS(LEqlOperator,[,<=,15,0);
CREATE_OPERATOR_CLASS(LessOperator,<,<,15,0);
CREATE_OPERATOR_CLASS(NotEqlOperator,!,!=,15,0);

CREATE_OPERATOR_CLASS(OrOperator,|,OR,14,0);

CREATE_OPERATOR_CLASS(AndOperator,&,AND,10,0);
CREATE_OPERATOR_CLASS(SpecialInOperator,#,#,40,1);;

#endif