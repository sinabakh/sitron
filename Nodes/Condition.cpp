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
	bool cVal = static_cast<VFloat*>(conValue)->value;
	long long conVal = cVal;
	if(conVal != 0)
	{
		ths->codeGen(arendelle);
	}
	else
	{
		fhs->codeGen(arendelle);
	}
	Value* tmpVal = new Value;
	tmpVal = new VResult(1);
	return tmpVal;
}



