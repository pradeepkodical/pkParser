/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _AVGFUNCTION_H_
#define _AVGFUNCTION_H_

#include "Expression.h"
#include "Function.h"
#include "FunctionFactory.h"

class AvgFunction: public Function
{
	friend class FunctionFactory;
private:
	vector<Expression*> params;
    
    AvgFunction();    
	
public:
	virtual Function* Create(vector<Expression*>);

	virtual ~AvgFunction();

    virtual double Solve();

	virtual string toString(int tab);
};
#endif
