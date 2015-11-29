class NInteger : public NExpression {
public:
    long long value;
    NInteger(long long value) : value(value) { }
    virtual Value* codeGen(Arendelle* arendelle);
};

class NDouble : public NExpression {
public:
    double value;
    NDouble(double value) : value(value) { }
    //virtual llvm::Value* codeGen(CodeGenContext& context);
};

