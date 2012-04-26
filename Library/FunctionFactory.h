/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#ifndef _FUNCTIONFACTORY_H_
#define _FUNCTIONFACTORY_H_

#include <vector>
#include <string>
#include "Function.h"

using namespace std;

class FunctionFactory
{
private:
	//Prototypes 
	vector<Function*> functionPrototypes;
	Function* GetFunctionPrototype(string &token);
	Function* Search(vector<Function*>::iterator begin, vector<Function*>::iterator end, string& key);
	FunctionFactory();
	~FunctionFactory();

public:	

	static FunctionFactory *GetInstance();
	bool isFunction(string &token);
	Function* CreateFunction(string &token, vector<Expression*> &expressionParts);	
	string GetFactoryItems();

private:
	static FunctionFactory *instance;
	
	
};

#endif