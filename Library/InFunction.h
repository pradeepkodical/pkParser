/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _INFUNCTION_H_
#define _INFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class InFunction: public Function
{
	friend class FunctionFactory;
private:
	vector<Expression*> params;
    
    InFunction();    
	
public:
	virtual Function* Create(vector<Expression*>);

	virtual ~InFunction();

    virtual double Solve();
	virtual double Solve(Expression*);

	virtual string toString(int tab);
};
#endif
