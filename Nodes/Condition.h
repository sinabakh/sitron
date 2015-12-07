/*
 * Condition.h
 *
 *  Created on: Dec 1, 2015
 *      Author: sina
 */
#ifndef NODES_CONDITION_H_
#define NODES_CONDITION_H_

class NCondition : public NExpression {
public:
    NExpression* condition;
    NExpression* ths;
    NExpression* fhs;
    NCondition(NExpression* condition, NExpression* ths, NExpression* fhs) :
        condition(condition), ths(ths), fhs(fhs) { }
    virtual Value* codeGen(Arendelle* arendelle);
};

#endif /* NODES_CONDITION_H_ */
