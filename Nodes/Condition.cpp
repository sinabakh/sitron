/*
 * Condition.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: sina
 */
#include "Node.h"

Value* NCondition::codeGen(Arendelle* arendelle)
{
	Value* conValue = condition->codeGen(arendelle);
	long long conVal = static_cast<VInt*>(conValue)->value;
	if(conVal != 0)
	{
		ths->codeGen(arendelle);
	}
	else
	{
		fhs->codeGen(arendelle);
	}
	Value* tmpVal = new Value;
	return tmpVal;
}



