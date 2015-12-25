#include "Base.h"
#include "Identifier.h"
#include "Space.h"

extern int yyerror(const char* msg);
extern int yywarning(const char* msg);

void spaceStrCorrector(std::string* str)
{
	std::string::iterator it;
	it = str->begin();
	while(it != str->end())
	{
		if(*it == '@')
			str->erase(it);
		else if(*it == ' ')
			str->erase(it);
		else
			it++;
	}
}

Value* NSAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);
	Value* rVal = rhs->codeGen(arendelle);
	std::string name = static_cast<VString*>(lVal)->value;
	spaceStrCorrector(&name);
	double value = static_cast<VFloat*>(rVal)->value;
	std::cout<<std::endl<<"Define Space : "<<value<<" -> "<<name<<std::endl;
	arendelle->addOrUpdateSpace(name,value);
	Value* tmpValue = new Value;
	tmpValue = new VResult(1);
	return tmpValue;
}

Value* NSInAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);
	Value* rVal = rhs->codeGen(arendelle);
	Value* inVal = this->index->codeGen(arendelle);
	std::string name = static_cast<VString*>(lVal)->value;
	spaceStrCorrector(&name);
	double value = static_cast<VFloat*>(rVal)->value;
	long long inValue = static_cast<VInt*>(inVal)->value;
	std::cout<<std::endl<<"Define Space : "<<value<<" -> "<<name<<std::endl;
	arendelle->addOrUpdateSpace(name, value, inValue);
	Value* tmpValue = new Value;
	tmpValue = new VResult(1);
	return tmpValue;
}

Value* NSpace::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	spaceStrCorrector(&sName);
	double sVal;
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
	Value* val = new VFloat(sVal);
	return val;
}


Value* NInSpace::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	Value* inVal = this->index->codeGen(arendelle);
	long long inValue = static_cast<VInt*>(inVal)->value;
	spaceStrCorrector(&sName);
	double sVal;
	if(arendelle->spaceExist(sName))
	{
		sVal = arendelle->getLastSpaceSearch(inValue);
	}
	else
	{
		yywarning("Non Defined Space, Thought Zero(0) by Default!");
		sVal = 0;
	}
	std::cout<<std::endl<<"Access Space : "<<sName<<" -> "<<sVal<<std::endl;
	Value* val = new VFloat(sVal);
	return val;
}


void stSpaceStrCorrector(std::string* str)
{
	std::string::iterator it;
	it = str->begin();
	while(it != str->end())
	{
		if(*it == '$')
			str->erase(it);
		else if(*it == ' ')
			str->erase(it);
		else
			it++;
	}
}

Value* NSTSAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);
	Value* rVal = rhs->codeGen(arendelle);
	std::string name = static_cast<VString*>(lVal)->value;
	stSpaceStrCorrector(&name);
	double value = static_cast<VFloat*>(rVal)->value;
	std::cout<<std::endl<<"Define Stored Space : "<<value<<" -> "<<name<<std::endl;
	arendelle->addOrUpdateStoredSpace(name,value);
	Value* tmpValue = new Value;
	return tmpValue;
}

Value* NSTSInAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);
	Value* rVal = rhs->codeGen(arendelle);
	Value* inVal = this->index->codeGen(arendelle);
	long long inValue = static_cast<VInt*>(inVal)->value;
	std::string name = static_cast<VString*>(lVal)->value;
	stSpaceStrCorrector(&name);
	double value = static_cast<VFloat*>(rVal)->value;
	std::cout<<std::endl<<"Define Stored Space : "<<value<<" -> "<<name<<std::endl;
	arendelle->addOrUpdateStoredSpace(name, value, inValue);
	Value* tmpValue = new Value;
	return tmpValue;
}

Value* NSTSpace::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	stSpaceStrCorrector(&sName);
	double sVal;
	if(arendelle->storedSpaceExist(sName))
	{
		sVal = arendelle->getLastStoredSpaceSearch();
	}
	else
	{
		yywarning("Non Defined Stored Space, Thought Zero(0) by Default!");
		sVal = 0;
	}
	std::cout<<std::endl<<"Access Stored Space : "<<sName<<" -> "<<sVal<<std::endl;
	Value* val = new VFloat(sVal);
	return val;
}

Value* NSTInSpace::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	Value* inVal = this->index->codeGen(arendelle);
	long long inValue = static_cast<VInt*>(inVal)->value;
	stSpaceStrCorrector(&sName);
	double sVal;
	if(arendelle->storedSpaceExist(sName))
	{
		sVal = arendelle->getLastStoredSpaceSearch(inValue);
	}
	else
	{
		yywarning("Non Defined Stored Space, Thought Zero(0) by Default!");
		sVal = 0;
	}
	std::cout<<std::endl<<"Access Stored Space : "<<sName<<" -> "<<sVal<<std::endl;
	Value* val = new VFloat(sVal);
	return val;
}
