/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <string>
#include <vector>

#include <algorithm>

#include "Helper.h"

#include "FunctionFactory.h"
#include "Function.h"

#include "IIFFunction.h"
#include "IFGTRFunction.h"
#include "IFEQLFunction.h"

#include "MaxFunction.h"
#include "MinFunction.h"

#include "AvgFunction.h"

#include "AbsFunction.h"

#include "RoundFunction.h"

#include "SwitchFunction.h"

#include "CaseFunction.h"

#include "InFunction.h"



using namespace std;
FunctionFactory* FunctionFactory::instance = 0;

FunctionFactory *FunctionFactory ::GetInstance()
{
	if( instance == 0)
	{
		instance = new FunctionFactory();
	}
	return instance;
}


bool FunctionSorter (Function *i,Function *j) { return (i->name < j->name); }

Function* FunctionFactory::Search(vector<Function*>::iterator begin, vector<Function*>::iterator end, string& key)
{
    vector<Function*>::iterator Middle;
    
    while(begin < end)
    {
        
        Middle = begin + (std::distance(begin, end) / 2);

        if((*Middle)->name == key)
        {
            return *Middle;
        }
        else if((*Middle)->name > key)
        {
            end = Middle;
        }
        else
        {
            begin = Middle + 1;
        }
    }

    return 0;
}

//private constructor singleton
FunctionFactory::FunctionFactory()
{
	functionPrototypes.push_back(new IIFFunction());
	functionPrototypes.push_back(new IFGTRFunction());
	functionPrototypes.push_back(new IFEQLFunction());
	
	functionPrototypes.push_back(new MaxFunction());
	functionPrototypes.push_back(new MinFunction());

	functionPrototypes.push_back(new AvgFunction());

	functionPrototypes.push_back(new AbsFunction());

	functionPrototypes.push_back(new RoundFunction());

	functionPrototypes.push_back(new SwitchFunction());	
	
	functionPrototypes.push_back(new CaseFunction());	

	functionPrototypes.push_back(new InFunction());	
	
	//for binary search
	sort(functionPrototypes.begin(),functionPrototypes.end(),FunctionSorter);	
}

FunctionFactory::~FunctionFactory()
{
	functionPrototypes.erase(functionPrototypes.begin(), functionPrototypes.end());
}

bool FunctionFactory::isFunction(string &token)
{
	if (token.size() < 3) return false;
    return (GetFunctionPrototype(token) != 0);
}

Function* FunctionFactory::CreateFunction(string &token, vector<Expression*> &expressionParts)
{
	Function* protoType = GetFunctionPrototype(token);

	return protoType->Create(expressionParts);	
}

Function* FunctionFactory::GetFunctionPrototype(string &token)
{
	string t = Helper::StringToUpper(token);	
	return Search(functionPrototypes.begin(), functionPrototypes.end(), t);
}

string FunctionFactory::GetFactoryItems()
{
	string strFactoryItems = Helper::GetTab(1);

	for( vector<Function*>::iterator it = functionPrototypes.begin();
		 it != functionPrototypes.end();
		 it++
	   )
		 {
			 strFactoryItems += (*it)->name + Helper::GetNewlineTab(2) + (*it)->useage + Helper::GetNewlineTab(1);
		 }
	return strFactoryItems;
}