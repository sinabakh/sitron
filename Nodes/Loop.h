class NLoop : public NExpression {
public:
    //std::string type;
    NExpression* lhs;
    //NExpression* rhs;
    NBlock* statements;
    NLoop(NExpression* lhs, NBlock* statements/*, std::string type*/): lhs(lhs),statements(statements)/*,type(type)*/ {}
    virtual Value* codeGen(Arendelle* arendelle);
};

