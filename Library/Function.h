/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "Expression.h"

#include<string>
#include <iostream>

using namespace std;

class Function: public Expression
{

protected :		
		Function()
		{
			value = "E";
			eType = 'E';	
		}
		virtual ~Function()
		{
		}
public:
		string name;
		string useage;
		virtual Function* Create(vector<Expression*>) = 0;
};
#endif