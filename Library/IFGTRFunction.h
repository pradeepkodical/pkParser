/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _IFGTRFUNCTION_H_
#define _IFGTRFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class IFGTRFunction: public Function
{

	friend class FunctionFactory;
private:
	Expression *lcond;
	Expression *rcond;
    Expression *lhs;
    Expression *rhs;
        
    IFGTRFunction();
    	
public:
	virtual Function* Create(vector<Expression*>);

	virtual ~IFGTRFunction();

    virtual double Solve();

	virtual string toString(int tab);
};
#endif