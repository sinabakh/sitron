#ifndef NODES_SPACE_H_
#define NODES_SPACE_H_

class NSAssignment : public NExpression {
public:
    NIdentifier* lhs;
    NExpression* rhs;
    NSAssignment(NIdentifier* lhs, NExpression* rhs) :
        lhs(lhs), rhs(rhs){ }
    virtual Value* codeGen(Arendelle* arendelle);
};

class NSInAssignment : public NExpression {
public:
    NIdentifier* lhs;
    NExpression* rhs;
    NExpression* index;
    NSInAssignment(NIdentifier* lhs, NExpression* rhs, NExpression* index) :
        lhs(lhs), rhs(rhs), index(index){ }
    virtual Value* codeGen(Arendelle* arendelle);
};

class NSpace : public NExpression {
public:
	NIdentifier* name;
	NSpace(NIdentifier* name) : name(name) {}
	virtual Value* codeGen(Arendelle* arendelle);
};

class NInSpace : public NExpression {
public:
	NIdentifier* name;
	NExpression* index;
	NInSpace(NIdentifier* name, NExpression*index) : name(name), index(index) {}
	virtual Value* codeGen(Arendelle* arendelle);
};

class NSTSAssignment : public NExpression {
public:
    NIdentifier* lhs;
    NExpression* rhs;
    NSTSAssignment(NIdentifier* lhs, NExpression* rhs) :
        lhs(lhs), rhs(rhs){ }
    virtual Value* codeGen(Arendelle* arendelle);
};

class NSTSInAssignment : public NExpression {
public:
    NIdentifier* lhs;
    NExpression* rhs;
    NExpression* index;
    NSTSInAssignment(NIdentifier* lhs, NExpression* rhs, NExpression* index) :
        lhs(lhs), rhs(rhs), index(index){ }
    virtual Value* codeGen(Arendelle* arendelle);
};

class NSTSpace : public NExpression {
public:
	NIdentifier* name;
	NSTSpace(NIdentifier* name) : name(name) {}
	virtual Value* codeGen(Arendelle* arendelle);
};

class NSTInSpace : public NExpression {
public:
	NIdentifier* name;
	NExpression* index;
	NSTInSpace(NIdentifier* name, NExpression* index) : name(name), index(index) {}
	virtual Value* codeGen(Arendelle* arendelle);
};

#endif /* NODES_SPACE_H_ */
