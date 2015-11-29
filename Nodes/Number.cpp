/*
 * Number.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: sina
 */
#include "Base.h"
#include "Number.h"

Value* NInteger::codeGen(Arendelle* arendelle){
	//std::cout<<std::endl<<"Number : "<<std::endl;
	Value* val = new VInt(this->value);
	return val;
}



