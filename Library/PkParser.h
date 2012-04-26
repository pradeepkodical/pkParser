/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _PKPARSER_H_
#define _PKPARSER_H_

#include <string>
#include <vector>
#include <stack>

#include"Expression.h"
#include"BinaryOperator.h"

#include"Function.h"
#include"FunctionFactory.h"

#include "Helper.h"
#include "PkException.h"

using namespace std;

class PkParser
{
public:	
	static Expression* Solve(string &infix);
	static string GetHelp();
private:

    static void PreFormat(string &infix);
    static void HandleOperators(string &infix);
    static void HandleMinus(string &infix);

	static vector<Expression*>* InfixToPostFix(vector<Expression*> &infix);
    static Expression *ConstructExpression(string infix);
    static Expression* Solve(vector<Expression*> &infix);
	static vector<Expression*>* MakeParts(string &funcCode);    
};
#endif