/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <string>
#include "Expression.h"

#include "PkException.h"


PkException::PkException(Expression* exp)
{
	expression = exp;
}

PkException::PkException(Expression* exp, string error)
{
	expression = exp;
	errorObject = error;
}

PkException::PkException(string error)
{
	expression = 0;
	errorObject = error;
}


string PkException::toString()
{
	return ((expression==0)?string(""):expression->toString(0)) + errorObject;
}