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


class Expression;

class PkException
{
public:
	PkException(Expression* exp);
	PkException(std::string error);
	PkException(Expression* exp, std::string error);
	std::string toString();
};
#endif