/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <vector>
#include <stack>

#include <ctype.h>

#include "Expression.h"
#include "Helper.h"

using namespace std;
/*
int Helper::Priority(char e)
{
    int pri = 0;

    if (e == '~')
        pri = 40;
    else if (e == '*' || e == '/' || e == '%' || e == '^')
        pri = 30;
    else if (e == '+' || e == '-')
            pri = 20;
    else if (e == '=' || e == '<'|| e == '>'|| e == '['|| e == ']'|| e == '!')
            pri = 15;
    else if (e == '|')
            pri = 14;
    else 
        pri = 10;
    
    return pri;
}

bool Helper::isOperator(char p)
{
	char opers[] = "~+*-/()<>!=[]^&|";
	for(int i = 0; opers[i]!=0; i++)
	{
		if( opers[i] == p )
			return true;
	}
	return false;
}

//every thing except '(' and ')'
bool Helper::isFuncOperator(char p)
{
    char opers[] = "~+*-/<>!=[]^&|";
	for(int i = 0; opers[i]!=0; i++)
	{
		if( opers[i] == p )
			return true;
	}
	return false;
}
*/
string Helper::Replace(string &source, string &victim, string &replacement)
{
	string answer = source;
	string::size_type j = 0;
	if( victim == replacement)
		return answer;
	
	while ((j = answer.find(victim, j )) != string::npos )
	{
		answer.replace(j, victim.length(), replacement);
		j = j + replacement.length();
	}
	return answer;
}

string Helper::StringToUpper(string &source)
{
	string answer = source;
	
	for(int i=0; i<answer.length(); i++)
	{
		answer[i] = toupper(answer[i]);
	}
	return answer;
}

string Helper::GetNewlineTab(int tab)
{
	return string("\n") + GetTab(tab);		
}

string Helper::GetTab(int tab)
{
	string str = "";
	for(int i = 0; i < tab; i++)
		str += "  ";
	return str;
}

string Helper::ToString(char ch)
{
	char s[2];
	s[0] = ch;
	s[1] = 0;
	return string(s);
}