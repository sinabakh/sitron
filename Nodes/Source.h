/*
 * Source.h
 *
 *  Created on: Nov 29, 2015
 *      Author: sina
 */
#ifndef NODES_SOURCE_H_
#define NODES_SOURCE_H_

class NSource : public NExpression{
public:
	NIdentifier* name;
	NSource(NIdentifier* name) : name(name) {}
	virtual Value* codeGen(Arendelle* arendelle);
};

#endif /* NODES_SOURCE_H_ */
