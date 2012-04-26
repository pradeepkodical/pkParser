/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _PKPARSER_H_
#define _PKPARSER_H_

#include <string>

#include"Expression.h"
#include "PkException.h"

class PkParser
{
public:	
	static Expression* Solve(string &infix);
	static std::string GetHelp();	
};
#endif