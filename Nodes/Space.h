class NSAssignment : public NExpression {
public:
    NIdentifier* lhs;
    NExpression* rhs;
    NSAssignment(NIdentifier* lhs, NExpression* rhs) :
        lhs(lhs), rhs(rhs){ }
    virtual Value* codeGen(Arendelle* arendelle);
};

class NSpace : public NExpression {
public:
	NIdentifier* name;
	NSpace(NIdentifier* name) : name(name) {}
	virtual Value* codeGen(Arendelle* arendelle);
};
