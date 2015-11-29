class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) { }
    virtual Value* codeGen(Arendelle* arendelle);
};

