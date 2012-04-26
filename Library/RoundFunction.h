/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _ROUNDFUNCTION_H_
#define _ROUNDFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class RoundFunction: public Function
{
	friend class FunctionFactory;
private:
	Expression *lhs;
    Expression *rhs;
    
    RoundFunction();    
public:
	virtual Function* Create(vector<Expression*>);

	virtual ~RoundFunction();

    virtual double Solve();

	virtual string toString(int tab);
};
#endif
