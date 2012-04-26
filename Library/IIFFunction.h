/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _IIFFUNCTION_H_
#define _IIFFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class IIFFunction: public Function
{

	friend class FunctionFactory;
private:
	Expression *condition;
    Expression *lhs;
    Expression *rhs;
        
    IIFFunction();
public:
	virtual Function* Create(vector<Expression*>);

	virtual ~IIFFunction();

    virtual double Solve();

	virtual string toString(int tab);
};
#endif