#ifndef NODES_IDENTIFIER_H_
#define NODES_IDENTIFIER_H_

class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) { }
    virtual Value* codeGen(Arendelle* arendelle);
};

#endif /* NODES_IDENTIFIER_H_ */
