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

#include "OperatorFactory.h"
#include "Expression.h"
#include "BinaryOperator.h"

using namespace std;

OperatorFactory* OperatorFactory::instance = 0;

OperatorFactory *OperatorFactory ::GetInstance()
{
	if( instance == 0)
	{
		instance = new OperatorFactory();
	}
	return instance;
}

bool OperatorSorter (BinaryOperator *i,BinaryOperator *j) { return (i->Oper() < j->Oper()); }

BinaryOperator* OperatorFactory::Search(vector<BinaryOperator*>::iterator begin, vector<BinaryOperator*>::iterator end, char key)
{
    vector<BinaryOperator*>::iterator Middle;
    
    while(begin < end)
    {
        
        Middle = begin + (std::distance(begin, end) / 2);

        if((*Middle)->Oper() == key)
        {
            return *Middle;
        }
        else if((*Middle)->Oper() > key)
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
OperatorFactory::OperatorFactory()
{
	operatorPrototypes.push_back(new AddOperator(0,0));
	operatorPrototypes.push_back(new AndOperator(0,0));
	operatorPrototypes.push_back(new DivOperator(0,0));
	operatorPrototypes.push_back(new EqualOperator(0,0));
	operatorPrototypes.push_back(new GEqlOperator(0,0));
	operatorPrototypes.push_back(new GreaterOperator(0,0));
	operatorPrototypes.push_back(new LEqlOperator(0,0));
	operatorPrototypes.push_back(new LessOperator(0,0));
	operatorPrototypes.push_back(new MinusOperator(0,0));
	operatorPrototypes.push_back(new ModOperator(0,0));
	operatorPrototypes.push_back(new MulOperator(0,0));
	operatorPrototypes.push_back(new NotEqlOperator(0,0));
	operatorPrototypes.push_back(new OrOperator(0,0));
	operatorPrototypes.push_back(new PowOperator(0,0));
	operatorPrototypes.push_back(new SpecialMinusOperator(0,0));
	operatorPrototypes.push_back(new SpecialInOperator(0,0));
	
	//for binary search
	sort(operatorPrototypes.begin(),operatorPrototypes.end(),OperatorSorter);	
}

OperatorFactory::~OperatorFactory()
{
	operatorPrototypes.erase(operatorPrototypes.begin(), operatorPrototypes.end());
}


BinaryOperator* OperatorFactory::CreateOperator(char oper, Expression*lhs, Expression*rhs)
{
	BinaryOperator* protoType = GetOperatorPrototype(oper);

	return protoType->Create(lhs, rhs);	
}

BinaryOperator* OperatorFactory::GetOperatorPrototype(char o)
{
	return Search(operatorPrototypes.begin(), operatorPrototypes.end(), o);
}

string OperatorFactory::GetFactoryItems()
{
	string strFactoryItems = Helper::GetTab(1);

	for( vector<BinaryOperator*>::iterator it = operatorPrototypes.begin();
		 it != operatorPrototypes.end();
		 it++
	   )
		 {
			 if(!(*it)->Hidden())
			 {
				 strFactoryItems += (*it)->Name() + " ("+ (*it)->SpecialOper() +")" + Helper::GetNewlineTab(1);
			 }
		 }
	return strFactoryItems;
}


int OperatorFactory::Priority(char p)
{    
	BinaryOperator* protoType = GetOperatorPrototype(p);

    return (protoType!=0)?protoType->Priority():0;
}

bool OperatorFactory::isOperator(char p)
{
	if( p == '(' || p ==')')
		return true;	
	return isFuncOperator(p);
}

//every thing except '(' and ')'
bool OperatorFactory::isFuncOperator(char p)
{
	BinaryOperator* protoType = GetOperatorPrototype(p);
 
	return (protoType!=0);
}