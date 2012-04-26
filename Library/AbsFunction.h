/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _ABSFUNCTION_H_
#define _ABSFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class AbsFunction: public Function
{
	friend class FunctionFactory;
private:
	Expression* param;
    
    AbsFunction();    
	
public:
	virtual Function* Create(vector<Expression*>);

	virtual ~AbsFunction();

    virtual double Solve();

	virtual string toString(int tab);
};
#endif
