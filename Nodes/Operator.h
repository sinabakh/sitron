#ifndef NODES_OPERATOR_H_
#define NODES_OPERATOR_H_

class NBinaryOperator : public NExpression {
public:
    int op;
    NExpression* lhs;
    NExpression* rhs;
    NBinaryOperator(NExpression* lhs, int op, NExpression* rhs) :
        lhs(lhs), rhs(rhs), op(op) { }
    virtual Value* codeGen(Arendelle* arendelle);
};

class NSingularOperator : public NExpression{
public:
	int op;
	NExpression* hs;
	NExpression* df;
	NSingularOperator(NExpression* df,int op, NExpression* hs) :
	        df(df), hs(hs), op(op) { }
	    virtual Value* codeGen(Arendelle* arendelle);
};

#endif /* NODES_OPERATOR_H_ */
