/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _MAXFUNCTION_H_
#define _MAXFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class MaxFunction: public Function
{
	friend class FunctionFactory;
private:
	vector<Expression*> params;
    
    MaxFunction();    
public:
	virtual Function* Create(vector<Expression*>);

	virtual ~MaxFunction();

    virtual double Solve();

	virtual string toString(int tab);
};
#endif
