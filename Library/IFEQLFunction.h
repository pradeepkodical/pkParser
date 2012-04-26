/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _IFEQLFUNCTION_H_
#define _IFEQLFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class IFEQLFunction: public Function
{
	friend class FunctionFactory;
private:
	Expression *lcond;
	Expression *rcond;
    Expression *lhs;
    Expression *rhs;
        
    IFEQLFunction();

public:	
	virtual Function* Create(vector<Expression*>);

	virtual ~IFEQLFunction();

    virtual double Solve();

	virtual string toString(int tab);
};
#endif