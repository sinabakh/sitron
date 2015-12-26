/*
 * Function.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: sina
 */

#include "Base.h"
#include "Identifier.h"
#include "Function.h"
#include "../Objects/Function.h"

extern NBlock* programBlock;
extern int yyparse();

extern FILE* yyin;

Value* NFunction::codeGen(Arendelle* arendelle)
{
	Value* resVal = new Value;
	Value* funcNameVal = this->name->codeGen(arendelle);
	string funcName = static_cast<VString*>(funcNameVal)->value;
	cout<<"Running Function: "<<funcName<<endl;
	if(!arendelle->functionExist(funcName))
		return resVal;
	Function* func = arendelle->getLastFunctionSearch();

	for(int i=0; i<this->args.size(); i++)
	{
		if(i >= func->args.size())
			break;
		Value* argVal = args[i]->codeGen(arendelle);
		long long arg = (long long)static_cast<VFloat*>(argVal)->value;
		arendelle->addOrUpdateSpace(func->args[i],arg);
	}

	char* c = &func->code[0];
	//char *cmd = new char [strlen(c)+16];
	FILE* funcMem; //= fmemopen(c, strlen(c),"r");
	//cmd=malloc(strlen(c)+16);
	//sprintf(cmd, "echo %s", c);
	funcMem = fmemopen(c, strlen(c),"r");
	yyin = funcMem;
	programBlock = new NBlock();
	yyparse();
	arendelle->addOrUpdateSpace("return", 0);
	if(programBlock->statements.size()!=0)
	       programBlock->codeGen(arendelle);
	arendelle->spaceExist("return");
	resVal = new VFloat(arendelle->getLastSpaceSearch());
	return resVal;
}



