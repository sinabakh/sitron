#include "Base.h"
#include "Identifier.h"
#include "Space.h"

extern int yyerror(const char* msg);
extern int yywarning(const char* msg);

Value* NSAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);
	Value* rVal = rhs->codeGen(arendelle);
	std::string name = static_cast<VString*>(lVal)->value;
	long long value = static_cast<VInt*>(rVal)->value;
	std::cout<<std::endl<<"Define Space : "<<value<<" -> "<<name<<std::endl;
	arendelle->addOrUpdateSpace(name,value);
	Value* tmpValue = new Value;
	return tmpValue;
}

Value* NSpace::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	long long sVal;
	if(arendelle->spaceExist(sName))
	{
		sVal = arendelle->getLastSpaceSearch();
	}
	else
	{
		yywarning("Non Defined Space, Thought Zero(0) by Default!");
		sVal = 0;
	}
	std::cout<<std::endl<<"Access Space : "<<sName<<" -> "<<sVal<<std::endl;
	Value* val = new VInt(sVal);
	return val;
}
