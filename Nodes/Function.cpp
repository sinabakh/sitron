/*
 * Function.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: sina
 */
#include "Function.h"

Value* NFunction::codeGen(Arendelle* arendelle)
{
	StatementList::const_iterator it;
	Value* lVal = new Value;
	        //std::cout<<"HEY : "<<statements.size()<<std::endl;
	        for (it = statements.begin(); it != statements.end(); it++) {
	                std::cout <<std::endl<< "Generating code for " << typeid(**it).name() << std::endl;
	                lVal = (**it).codeGen(arendelle);
	        }
	        return lVal;
}



