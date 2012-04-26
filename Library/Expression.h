/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

#include "stdafx.h"

#include<string>
#include <iostream>

#include "Helper.h"
#include "PkException.h"

using namespace std;

///This is a Node/Leaf in the tree
class Expression
{

public :
		string value;
        char eType;
public:
	Expression();
	Expression(double v);
	Expression(string v, char e);
    virtual ~Expression();	
    virtual double Solve();
	virtual string toString(int tab);	
};
#endif