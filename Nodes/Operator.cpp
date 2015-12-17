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
	double lVal = static_cast<VFloat*>(lValue)->value;

	Value* rValue = rhs->codeGen(arendelle);
	double rVal = static_cast<VFloat*>(rValue)->value;
	cout<<"HEY: "<<rVal<<" : "<<lVal<<endl;
	if(this->op == TPLUS)
	{
		resVal = new VFloat(lVal + rVal);
	}
	if(this->op == TMINUS)
		resVal = new VFloat(lVal - rVal);
	if(this->op == TMUL)
		resVal = new VFloat(lVal * rVal);
	if(this->op == TDIV)
		resVal = new VFloat(lVal / rVal);
	if(this->op == TMOD)
		resVal = new VFloat((double)((long long)lVal % (long long)rVal));
	if(this->op == TPOW)
	{
		if(rVal < 0)
		{
		    yyerror("Negative Power Not Supported. Tought Zero(0) by default!");
		    rVal = 0;
		}
		double powVal = 1.f;
		for(double i=1; i<=rVal; i+=1)
		    powVal *= lVal;
		resVal = new VFloat(powVal);
	}

	if(this->op == TCLT)
	{
		resVal = new VBool(lVal < rVal);
	}
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
	double dfVal = static_cast<VFloat*>(dfValue)->value;

	Value* hsValue = hs->codeGen(arendelle);
	double hsVal = static_cast<VFloat*>(hsValue)->value;
	if(this->op == TPLUS)
	{
		resVal = new VFloat(dfVal + hsVal);
	}
	if(this->op == TMINUS)
		resVal = new VFloat(dfVal - hsVal);
	if(this->op == TMUL)
		resVal = new VFloat(dfVal * hsVal);
	if(this->op == TDIV)
		resVal = new VFloat(dfVal / hsVal);
	return resVal;
	//Value* tmpVal = new Value;
	//return tmpVal;
}


