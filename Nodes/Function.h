/*
 * Function.h
 *
 *  Created on: Dec 04, 2015
 *      Author: Sina
 */

#ifndef NODES_FUNCTION_H_
#define NODES_FUNCTION_H_


class NFunction: public NBlock{
public:
	NIdentifier* name;
	std::vector<NExpression*>args;
	NFunction(NIdentifier* name, std::vector<NExpression*> args) : name(name) , args(args) { }
	NFunction(NIdentifier* name) : name(name) { }
	virtual Value* codeGen(Arendelle* arendelle);
};

class NFunctionSize: public NBlock{
public:
	NExpression* func;
	NFunctionSize(NExpression* func) : func(func) { }
	virtual Value* codeGen(Arendelle* arendelle);
};

#endif /* NODES_FUNCTION_H_ */
