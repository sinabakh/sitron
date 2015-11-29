/*
 * Source.h
 *
 *  Created on: Nov 29, 2015
 *      Author: sina
 */
class NSource : public NExpression{
public:
	NIdentifier* name;
	NSource(NIdentifier* name) : name(name) {}
	virtual Value* codeGen(Arendelle* arendelle);
};
