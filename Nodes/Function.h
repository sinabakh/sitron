/*
 * Function.h
 *
 *  Created on: Dec 04, 2015
 *      Author: Sina
 */

class NFunction: public NBlock{
public:
	std::vector<std::string>args;
	NFunction(args) : args(args) { }
	virtual Value* codeGen(Arendelle* arendelle);
};
