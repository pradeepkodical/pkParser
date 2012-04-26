/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#ifndef _OPERATORFACTORY_H_
#define _OPERATORFACTORY_H_

#include <vector>
#include <string>
#include "BinaryOperator.h"

using namespace std;

class OperatorFactory
{
private:
	//Prototypes 
	vector<BinaryOperator*> operatorPrototypes;
	BinaryOperator* GetOperatorPrototype(char oper);
	BinaryOperator* Search(vector<BinaryOperator*>::iterator begin, vector<BinaryOperator*>::iterator end, char oper);
	OperatorFactory();
	~OperatorFactory();

public:	

	static OperatorFactory *GetInstance();	
	BinaryOperator* CreateOperator(char oper, Expression*lhs,Expression*rhs);	
	string GetFactoryItems();
	int NoOfOperators(){return operatorPrototypes.size();}
	BinaryOperator *Operator(int index)	{return operatorPrototypes[index];}

	
	int Priority(char e);
    bool isOperator(char p);
    bool isFuncOperator(char p);
	

private:
	static OperatorFactory *instance;
	
	
};

#endif