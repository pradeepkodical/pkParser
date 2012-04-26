/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/

#include <string>
#include <iostream>

#include "stdlib.h" 

#include "Expression.h"
#include "PkParser.h"
#include "PkException.h"

void PrintHelp()
{
	cout << PkParser::GetHelp() << endl;	
}
void PrintExpression(std::string &infix)
{
	try
	{

	double results = 0;

	Expression *exp = PkParser::Solve(infix);

//	cout <<"Equation: " << exp->toString(0) <<endl;

	results = exp->Solve();

	cout << results <<endl;

	delete exp;
	}
	catch(PkException *ex)
	{
		cout << "Exception:" << ex->toString() <<endl;
	}
	catch(...)
	{
		cout << "Unknown Error"<<endl;
	}
}

int main()
{

	std::string infix;
	char c[8000];

 	cout << "Type any math expression: (Ctrl-C to exit)" <<endl;
	while(1)
	{		
		cout << ">";
		
		gets(c);
		infix = c;
					
		if(infix == "help")
			PrintHelp();
		else
			PrintExpression(infix);
		infix = "";
	}

	return 1;
}