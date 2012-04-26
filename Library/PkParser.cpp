/*---------------------------------------------------------------------------
 * Copyright 2004-2012 Pradeep Kodical
 * This source code is licensed under the terms of the
 * Lesser Gnu Public License (see license.txt) and carries
 * NO WARRANTY
 * 
 *
 * Main Parser Engine
 *-------------------------------------------------------------------------*/
#include "stdafx.h"
#include <string>
#include <vector>
#include <stack>

#include"Expression.h"
#include"BinaryOperator.h"

#include"FunctionFactory.h"
#include"OperatorFactory.h"

#include "Helper.h"

#include "PkParser.h"

using namespace std;

Expression* PkParser::Solve(string &infix)
{

    PreFormat(infix);

    return ConstructExpression(infix);		
}

void PkParser::PreFormat(string &infix)
{
	infix = Helper::Replace(infix, string(" "), string(""));
	infix = Helper::Replace(infix, string("\t"), string(""));
	
	infix = Helper::StringToUpper(infix);

    HandleMinus(infix);
    HandleOperators(infix);
}

void PkParser::HandleOperators(string &infix)
{
	string src = infix;	

	for(int i = 0; i < OperatorFactory::GetInstance()->NoOfOperators(); i++)
	{
		src = Helper::Replace
			(
				src, 
				OperatorFactory::GetInstance()->Operator(i)->SpecialOper(),
				Helper::ToString(OperatorFactory::GetInstance()->Operator(i)->Oper())
			);		
	}
	
	src = Helper::Replace(src,string("EXISTS_IN"),string("#EXISTS_IN"));

	infix = src;	
}

void PkParser::HandleMinus(string &infix)
{
	string ret;
    for (int index = 0; index < infix.size(); index++)
    {
        if (infix[index] == '-')
        {
            if (index == 0 || 
				(
					(
						OperatorFactory::GetInstance()->isOperator(infix[index - 1]) 
						||
						infix[index - 1] == ',' 
					)

					&& 
					infix[index + 1] != '(' 
					&& 
					infix[index - 1] != ')'
				)
			   )
            {
                ret += "0~";
            }
            else
            {
                ret += infix[index];
            }
        }
        else
        {
            ret += infix[index];
        }
    }
    infix = ret;
}

Expression* PkParser::ConstructExpression(string infix)
{
	vector<Expression*> tokenized;
    string token;
	Expression* result;
    int brackets = 0;
    bool isd = false;
    for (int index = 0; index < infix.size(); index++)
    {              
        isd = false;
        while (index < infix.size() && ( isdigit(infix[index]) || infix[index] == '.'))
        {
            token += infix[index];
            index++;
            isd = true;
        }
        if (isd)
        {
            tokenized.push_back(new Expression(token, 'N'));
            token = "";
            index--;
            continue;
        }
        if (index < infix.size() && OperatorFactory::GetInstance()->isFuncOperator(infix[index]))
        {
           	tokenized.push_back(OperatorFactory::GetInstance()->CreateOperator(infix[index],0,0));
            token = "";
            continue;
        }
        if (FunctionFactory::GetInstance()->isFunction(token) )
        {

            index++; 
            brackets++; 
            
            string funcCode = "";
            while (!(infix[index] == ')' && brackets == 1))
            {
                if (infix[index] == '(') brackets++;
                if (infix[index] == ')') brackets--;
        
                funcCode += infix[index];
                index++;

                if (index >= infix.size())
                    break;
            }

			vector<Expression*> *parts = MakeParts(funcCode);
            tokenized.push_back(FunctionFactory::GetInstance()->CreateFunction(token, *parts));
			parts->erase(parts->begin(), parts->end());			
			delete parts;
            brackets = 0;
            token = "";
        }
        if (infix[index] == '(')
        {
            brackets++;
            index++;

            string funcCode = "";
            while (!(infix[index] == ')' && brackets == 1))
            {
                if (infix[index] == '(') brackets++;
                if (infix[index] == ')') brackets--;

                funcCode += infix[index];
                index++;
                if (index >= infix.size())
                    break;
            }
            tokenized.push_back(ConstructExpression(funcCode));
            brackets = 0;
            token = "";
            
            continue;
        }
        if (index >= infix.size())
            break;
        if (infix[index] == ')')
        {
            brackets--;
        }
        token += infix[index];
        
    }
    if (token != "" && OperatorFactory::GetInstance()->isFuncOperator(token[0]))
    {
		tokenized.push_back(OperatorFactory::GetInstance()->CreateOperator(token[0],0,0));		
    }
	result = Solve(tokenized);
	tokenized.erase(tokenized.begin(), tokenized.end());
    return result;
}

Expression* PkParser::Solve(vector<Expression*> &infix)
{
	if (infix.size() == 0)
        return new Expression("0.0", 'N');
    vector<Expression*> *postFix = InfixToPostFix(infix);

    stack<Expression*> operands;;
    Expression *rhs = 0;
    Expression *lhs = 0;

    for (vector<Expression*>::iterator it = postFix->begin();
		 it < postFix->end();
		 it ++
		)
    {
		Expression *str = (*it);
		
		if (OperatorFactory::GetInstance()->isOperator(str->value[0]))
        {
			if (!operands.empty())
            {
                rhs = operands.top(); operands.pop();
            }
            if (!operands.empty())
            {
                lhs = operands.top(); operands.pop();
            }
            if (rhs != 0 && lhs != 0)
            {
                operands.push(OperatorFactory::GetInstance()->CreateOperator(str->value[0],lhs,rhs));		
            }
            else if (rhs != 0)
            {
                operands.push(rhs);
            }
        }
        else
        {
            operands.push(str);
        }
    }
	
	lhs = operands.top();
	
	operands.pop();

	return new Expression(lhs->Solve());
}

vector<Expression*>* PkParser::MakeParts(string &funcCode)
{
    vector<Expression*>* retVal = new vector<Expression*>();
    string token = "";
    int brackets = 0;

    for (int index = 0; index < funcCode.size(); index++)
    {
        if (funcCode[index] == '(') brackets++;
        if (funcCode[index] == ')') brackets--;

        if (funcCode[index] == ',' && brackets == 0)
        {
            retVal->push_back(ConstructExpression(token));
            token = "";
            continue;
        }

        token += funcCode[index];                
    }
    if (token != "")
    {
        retVal->push_back(ConstructExpression(token));
    }
    return retVal;
}

vector<Expression*>* 
PkParser::InfixToPostFix
(
	vector<Expression*> &infix
)
{
	stack<Expression*> stackOperations;
	vector<Expression*> *postFix = new vector<Expression*>();
    Expression* n1;
	Expression* n;
    
	for(
			vector<Expression*>::iterator it = infix.begin();
			it < infix.end();
			it ++
	   )
	{	
    	n = (*it);
        if (n->eType != 'O')
        {
            postFix->push_back(n);
        }
        else
        {
            if (stackOperations.size() == 0)
            {
                stackOperations.push(n);
            }
            else
            {
                n1 = stackOperations.top(); stackOperations.pop();
                while (OperatorFactory::GetInstance()->Priority(n1->value[0]) >= OperatorFactory::GetInstance()->Priority(n->value[0]))
                {
                    postFix->push_back(n1);
                    if (stackOperations.size() > 0)
                    {
                        n1 = stackOperations.top(); stackOperations.pop();
                    }
                    else 
                    {
                        n1 = 0;
                        break;
                    }
                }
                if (n1 != 0)
                {
                    stackOperations.push(n1);
                }
                stackOperations.push(n);
            }
        }
    }

    while (stackOperations.size() > 0)
    {
        postFix->push_back(stackOperations.top());
		stackOperations.pop();
    }

    return postFix;
}


string PkParser::GetHelp()
{
	string strHelp = "****   Author: Pradeep Kodical, NO WARRANTY   ****\n\n";
	strHelp += "Functions supported\n\n";
	strHelp += FunctionFactory::GetInstance()->GetFactoryItems();
	strHelp += "\n\nOperators supported\n\n";
	strHelp += OperatorFactory::GetInstance()->GetFactoryItems();

	return strHelp;
}
