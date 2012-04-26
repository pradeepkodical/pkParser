/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _MINFUNCTION_H_
#define _MINFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class MinFunction: public Function
{
	friend class FunctionFactory;
private:
	vector<Expression*> params;

    MinFunction();
public:
	virtual Function* Create(vector<Expression*>);

	virtual ~MinFunction();

    virtual double Solve();

	virtual string toString(int tab);
};
#endif
