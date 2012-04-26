/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#ifndef _PKEXCEPTION_H_
#define _PKEXCEPTION_H_

#include <string>
#include "Expression.h"

using namespace std;
class Expression;

class PkException
{
private:
	Expression* expression;
	string errorObject;
public:
	
	PkException(Expression* exp);
	PkException(string error);

	PkException(Expression* exp, string error);

	string toString();
};
#endif