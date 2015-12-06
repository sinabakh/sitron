/*
 * Function.h
 *
 *  Created on: Dec 04, 2015
 *      Author: Sina
 */

class NFunction: public NBlock{
public:
	NIdentifier* name;
	std::vector<NExpression*>args;
	NFunction(NIdentifier* name, std::vector<NExpression*> args) : name(name) , args(args) { }
	NFunction(NIdentifier* name) : name(name) { }
	virtual Value* codeGen(Arendelle* arendelle);
};
