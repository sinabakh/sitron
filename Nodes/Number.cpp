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
	Value* val = new VFloat((double)this->value);
	return val;
}

Value* NDouble::codeGen(Arendelle* arendelle){
	//std::cout<<std::endl<<"Number : "<<std::endl;
	Value* val = new VFloat(this->value);
	return val;
}

