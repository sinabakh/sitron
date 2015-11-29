/*
 * Identifier.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: sina
 */
#include "Base.h"
#include "Identifier.h"

Value* NIdentifier::codeGen(Arendelle* arendelle)
{
	Value* val = new VString(this->name);
	//std::cout<<std::endl<<"Just IDNTF"<<std::endl;
	return val;
}



