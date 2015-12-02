/*
 * Operator.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: sina
 */
#include "Node.h"
//#include "Identifier.h"
//#include "Operator.h"

//#include "../Parser/parser.hpp"

//extern int TPLUS;

//extern auto yytokentype;

//extern int TPLUS;

extern int yyerror(const char* msg);
extern int yywarning(const char* msg);

Value* NBinaryOperator::codeGen(Arendelle* arendelle)
{
	Value* resVal;
	Value* lValue = lhs->codeGen(arendelle);
	long long lVal = static_cast<VInt*>(lValue)->value;

	Value* rValue = rhs->codeGen(arendelle);
	long long rVal = static_cast<VInt*>(rValue)->value;
	if(this->op == TPLUS)
	{
		resVal = new VInt(lVal + rVal);
	}
	if(this->op == TMINUS)
		resVal = new VInt(lVal - rVal);
	if(this->op == TMUL)
		resVal = new VInt(lVal * rVal);
	if(this->op == TDIV)
		resVal = new VInt(lVal / rVal);
	if(this->op == TMOD)
		resVal = new VInt(lVal % rVal);
	if(this->op == TPOW)
	{
		if(rVal < 0)
		{
		    yyerror("Negative Power Not Supported. Tought Zero(0) by default!");
		    rVal = 0;
		}
		long long powVal = 1;
		for(long long i=1; i<=rVal; i++)
		    powVal *= lVal;
		resVal = new VInt(powVal);
	}


	if(this->op == TCLT)
		resVal = new VBool(lVal < rVal);
	if(this->op == TCLE)
		resVal = new VBool(lVal <= rVal);
	if(this->op == TCGT)
		resVal = new VBool(lVal > rVal);
	if(this->op == TCGE)
		resVal = new VBool(lVal >= rVal);
	if(this->op == TCEQ || this->op == TEQUAL)
		resVal = new VBool(lVal == rVal);
	if(this->op == TCNE)
		resVal = new VBool(lVal != rVal);
	return resVal;
	//Value* tmpVal = new Value;
	//return tmpVal;
}

Value* NSingularOperator::codeGen(Arendelle* arendelle)
{
	Value* resVal;
	Value* dfValue = df->codeGen(arendelle);
	long long dfVal = static_cast<VInt*>(dfValue)->value;

	Value* hsValue = hs->codeGen(arendelle);
	long long hsVal = static_cast<VInt*>(hsValue)->value;
	if(this->op == TPLUS)
	{
		resVal = new VInt(dfVal + hsVal);
	}
	if(this->op == TMINUS)
		resVal = new VInt(dfVal - hsVal);
	if(this->op == TMUL)
		resVal = new VInt(dfVal * hsVal);
	if(this->op == TDIV)
		resVal = new VInt(dfVal / hsVal);
	return resVal;
	//Value* tmpVal = new Value;
	//return tmpVal;
}


