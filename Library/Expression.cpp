/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Expression.h"

using namespace std;

Expression::Expression()
{
	value = "X";
    eType = 'X';
}

Expression::Expression(double v)
{
	char a[20];
	sprintf(a,"%g",v);
	value = a;
    eType = 'N';
}

Expression::Expression(string v, char e):value(v),eType(e)
{
}
Expression::~Expression()
{

} 

double Expression::Solve()
{
	switch (eType)
	{
		case 'N':
			return atof(value.c_str());
		default:
			return 0.0;
	}
}

string Expression::toString(int tab)
{
	string str = Helper::GetNewlineTab(tab);
	str += value;	

	return str;
}
