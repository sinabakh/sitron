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
	Value* lVal = lhs.codeGen(arendelle);
	long long times = static_cast<VInt*>(lVal)->value;
	std::cout<<std::endl<<"Loop : "<<times<<" times"<<std::endl<<"{"<<std::endl;
	for(unsigned int i = 0; i<times; i++)
	{
		rhs.codeGen(arendelle);
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



