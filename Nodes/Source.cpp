/*
 * Source.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: sina
 */
#include "Base.h"
#include "Identifier.h"
#include "Source.h"

extern int yyerror(const char* msg);
extern int yywarning(const char* msg);

Value* NSource::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	long long sVal;
	if(arendelle->sourceExist(sName))
	{
		sVal = arendelle->getLastSourceSearch();
	}
	else
	{
		yywarning("Non Defined Source, Thought Zero(0) by Default!");
		sVal = 0;
	}
	std::cout<<std::endl<<"Access Source : "<<sName<<" -> "<<sVal<<std::endl;
	Value* val = new VInt(sVal);
	return val;
}
