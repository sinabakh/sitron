/*
 * Condition.h
 *
 *  Created on: Dec 1, 2015
 *      Author: sina
 */
class NCondition : public NExpression {
public:
    NExpression* condition;
    NExpression* hs;
    NCondition(NExpression* condition, NExpression* hs) :
        condition(condition), hs(hs) { }
    virtual Value* codeGen(Arendelle* arendelle);
};
