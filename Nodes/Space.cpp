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
	long long inValue = (long long)static_cast<VFloat*>(inVal)->value;
	std::cout<<std::endl<<"Define Space : "<<value<<" -> "<<name<< "| index: "<<inValue<<std::endl;
	arendelle->addOrUpdateSpace(name, value, inValue);
	Value* tmpValue = new Value;
	tmpValue = new VResult(1);
	return tmpValue;
}

Value* NSArrAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);

	std::string name = static_cast<VString*>(lVal)->value;
	spaceStrCorrector(&name);
	for(long long i=0; i<this->indexes.size(); i++)
	{
		Value* inVal = this->indexes[i]->codeGen(arendelle);
		long long inValue = (long long)static_cast<VFloat*>(inVal)->value;
		arendelle->addOrUpdateSpace(name, inValue, i);
	}
	std::cout<<std::endl<<"Define Space with Array "<<std::endl;
	Value* tmpValue = new Value;
	tmpValue = new VResult(1);
	return tmpValue;
}

Value* NSSAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);
	std::string name = static_cast<VString*>(lVal)->value;
	spaceStrCorrector(&name);

	Value* rVal = rhs->codeGen(arendelle);
	std::string rName = static_cast<VString*>(rVal)->value;
	spaceStrCorrector(&rName);


	if(is_space && arendelle->spaceExist(rName))
	{
		std::cout<<std::endl<<"Define Space with Array Space! "<<std::endl;
		vector<double>vals = arendelle->getLastSpaceSearchArr();
		for(long long i=0; i<vals.size(); i++)
			arendelle->addOrUpdateSpace(name, vals[i], i);
	}
	else if(!is_space && arendelle->storedSpaceExist(rName))
	{
		std::cout<<std::endl<<"Define Space with Array Space! "<<std::endl;
		vector<double>vals = arendelle->getLastStoredSpaceSearchArr();
		for(long long i=0; i<vals.size(); i++)
			arendelle->addOrUpdateSpace(name, vals[i], i);
	}

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
	long long inValue = (long long)static_cast<VFloat*>(inVal)->value;
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
	std::cout<<std::endl<<"Access Space : "<<sName<<" -> "<<sVal<<"| index: "<<inValue<<std::endl;
	Value* val = new VFloat(sVal);
	return val;
}

Value* NSpaceSize::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	spaceStrCorrector(&sName);
	long long size;
	if(arendelle->spaceExist(sName))
	{
		size = arendelle->getLastSpaceSearchArr().size();
	}
	else
	{
		yywarning("Non Defined Space, Thought its size Zero(0) by Default!");
		size = 0;
	}
	std::cout<<std::endl<<" Space Size : "<<sName<<" -> "<<size<<std::endl;
	Value* val = new VFloat(size);
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
	long long inValue = (long long)static_cast<VFloat*>(inVal)->value;
	std::string name = static_cast<VString*>(lVal)->value;
	stSpaceStrCorrector(&name);
	double value = static_cast<VFloat*>(rVal)->value;
	std::cout<<std::endl<<"Define Stored Space : "<<value<<" -> "<<name<<std::endl;
	arendelle->addOrUpdateStoredSpace(name, value, inValue);
	Value* tmpValue = new Value;
	return tmpValue;
}

Value* NSTSArrAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);
	std::string name = static_cast<VString*>(lVal)->value;
	stSpaceStrCorrector(&name);
	std::cout<<std::endl<<"Define Stored Space with Array "<<std::endl;
	for(long long i=0; i<this->indexes.size(); i++)
	{
		Value* inVal = this->indexes[i]->codeGen(arendelle);
		long long inValue = (long long)static_cast<VFloat*>(inVal)->value;
		arendelle->addOrUpdateStoredSpace(name, inValue, i);
	}
	Value* tmpValue = new Value;
	return tmpValue;
}

Value* NSTSSAssignment::codeGen(Arendelle* arendelle)
{
	Value* lVal = lhs->codeGen(arendelle);
		std::string name = static_cast<VString*>(lVal)->value;
		spaceStrCorrector(&name);

		Value* rVal = rhs->codeGen(arendelle);
		std::string rName = static_cast<VString*>(rVal)->value;
		spaceStrCorrector(&rName);


		if(is_space && arendelle->spaceExist(rName))
		{
			std::cout<<std::endl<<"Define Stored Space with Array Space! "<<std::endl;
			vector<double>vals = arendelle->getLastSpaceSearchArr();
			for(long long i=0; i<vals.size(); i++)
				arendelle->addOrUpdateStoredSpace(name, vals[i], i);
		}
		else if(!is_space && arendelle->storedSpaceExist(rName))
		{
			std::cout<<std::endl<<"Define Stored Space with Array Space! "<<std::endl;
			vector<double>vals = arendelle->getLastStoredSpaceSearchArr();
			for(long long i=0; i<vals.size(); i++)
				arendelle->addOrUpdateStoredSpace(name, vals[i], i);
		}

		Value* tmpValue = new Value;
		tmpValue = new VResult(1);
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
	long long inValue = (long long)static_cast<VFloat*>(inVal)->value;
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

Value* NSTSpaceSize::codeGen(Arendelle* arendelle)
{
	Value* nVal = name->codeGen(arendelle);
	std::string sName = static_cast<VString*>(nVal)->value;
	stSpaceStrCorrector(&sName);
	long long size;
	if(arendelle->storedSpaceExist(sName))
	{
		size = arendelle->getLastStoredSpaceSearchArr().size();
	}
	else
	{
		yywarning("Non Defined Stored Space, Thought its size Zero(0) by Default!");
		size = 0;
	}
	std::cout<<std::endl<<"Access Stored Space Size : "<<sName<<" -> "<<size<<std::endl;
	Value* val = new VFloat(size);
	return val;
}
