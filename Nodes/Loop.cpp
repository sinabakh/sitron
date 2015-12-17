/*
 * Loop.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: sina
 */
#include "Base.h"
#include "Loop.h"

Value* NLoop::codeGen(Arendelle* arendelle)
{
	Value* tmpVal = new Value;
	Value* lVal = lhs->codeGen(arendelle);
	bool isBool = dynamic_cast<const VBool*>(lVal) != 0;
	std::cout<<std::endl<<"Loop : "<<" isBool: "<<isBool;
	StatementList::const_iterator it;
	if(! isBool)
	{
		long long times = (long long)static_cast<VFloat*>(lVal)->value;
		std::cout<<std::endl<<times<<" times"<<std::endl<<"{"<<std::endl;
		for(unsigned int i = 0; i<times; i++)
		{
			//rhs->codeGen(arendelle);
			for(it = statements->statements.begin(); it != statements->statements.end(); it++)
			{
				(*it)->codeGen(arendelle);
			}
		}
	}
	else
	{
		std::cout<<std::endl<<" Till True :) "<<std::endl<<"{"<<std::endl;
		while(true)
		{
			lVal = lhs->codeGen(arendelle);
			bool canC = static_cast<VBool*>(lVal)->value;
			if(!canC)
				break;
			//rhs->codeGen(arendelle);
			for(it = statements->statements.begin(); it != statements->statements.end(); it++)
				{
							(*it)->codeGen(arendelle);
				}
		}
	}
	std::cout<<std::endl<<"End of Loop"<<std::endl<<"}"<<std::endl;
	/*if(type == "numeric")
	{
		long long times = static_cast<VInt*>(lVal)->value;
		for(unsigned int i = 0; i<times; i++)
		{
			rhs.codeGen(arendelle);
		}
	}*/
	return tmpVal;
}



