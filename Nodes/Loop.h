#ifndef NODES_LOOP_H_
#define NODES_LOOP_H_

class NLoop : public NExpression {
public:
    //std::string type;
    NExpression* lhs;
    //NExpression* rhs;
    NBlock* statements;
    NLoop(NExpression* lhs, NBlock* statements/*, std::string type*/): lhs(lhs),statements(statements)/*,type(type)*/ {}
    virtual Value* codeGen(Arendelle* arendelle);
};

#endif /* NODES_LOOP_H_ */
