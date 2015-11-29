class NLoop : public NExpression {
public:
    //std::string type;
    NExpression& lhs;
    NExpression& rhs;
    NLoop(NExpression& lhs, NExpression& rhs/*, std::string type*/): lhs(lhs),rhs(rhs)/*,type(type)*/ {}
    virtual Value* codeGen(Arendelle* arendelle);
};

