class NBinaryOperator : public NExpression {
public:
    int op;
    NExpression* lhs;
    NExpression* rhs;
    NBinaryOperator(NExpression* lhs, int op, NExpression* rhs) :
        lhs(lhs), rhs(rhs), op(op) { }
    virtual Value* codeGen(Arendelle* arendelle);
};

