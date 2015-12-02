/*
 * Condition.h
 *
 *  Created on: Dec 1, 2015
 *      Author: sina
 */
class NCondition : public NExpression {
public:
    NExpression* condition;
    NExpression* ths;
    NExpression* fhs;
    NCondition(NExpression* condition, NExpression* ths, NExpression* fhs) :
        condition(condition), ths(ths), fhs(fhs) { }
    virtual Value* codeGen(Arendelle* arendelle);
};
