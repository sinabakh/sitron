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

Value* NBinaryOperator::codeGen(Arendelle* arendelle)
{
	Value* resVal;
	if(this->op == TPLUS)
	{
		Value* lValue = lhs->codeGen(arendelle);
		int lVal = static_cast<VInt*>(lValue)->value;

		Value* rValue = rhs->codeGen(arendelle);
		int rVal = static_cast<VInt*>(rValue)->value;

		resVal = new VInt(lVal + rVal);
	}
	return resVal;
	//Value* tmpVal = new Value;
	//return tmpVal;
}



