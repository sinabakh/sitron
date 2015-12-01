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


void sourceStrCorrector(std::string* str)
{
        std::string::iterator it;
        it = str->begin();
        while(it != str->end())
        {
                if(*it == '#')
                        str->erase(it);
                else if(*it == ' ')
                        str->erase(it);
                else
                        it++;
        }
}



Value* NSource::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	sourceStrCorrector(&sName);
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
