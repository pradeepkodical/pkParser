/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _CONVERTERITOP_H_
#define _CONVERTERITOP_H_
    
#include <vector>
#include <stack>
#include "Expression.h"

using namespace std;

class Helper
{
public:	
	static string Replace(string &source, string &victim, string &replacement);
	static string StringToUpper(string &source);

	static string ToString(char ch);
	static string GetNewlineTab(int tab);
	static string GetTab(int tab);	
};
#endif
