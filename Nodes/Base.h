#include "../Objects/Arendelle.h"

class NStatement;
class Value;
typedef std::vector<NStatement*> StatementList;

class Node {
public:
    virtual ~Node() {}
    virtual Value* codeGen(Arendelle* arendelle) { Value* tmpVal; return tmpVal;}
};

class NExpression : public Node {
};

class NStatement : public Node {
};

class NBlock : public NExpression {
public:
    StatementList statements;
    NBlock() { }
    virtual Value* codeGen(Arendelle* arendelle);
};


class NExpressionStatement : public NStatement {
public:
    NExpression& expression;
    NExpressionStatement(NExpression& expression) :
        expression(expression) { }
    virtual Value* codeGen(Arendelle* arendelle){Value* resVal;resVal = expression.codeGen(arendelle);return resVal;}
};

class Value{
public:
	virtual ~Value(){}
};

class VInt : public Value{
public:
	long long value;
	VInt(long long value) : value(value) {}
};

class VBool : public Value{
public:
	long long value;
	VBool(long long value) : value(value) {}
};

class VFloat : public Value{
public:
	double value;
	VFloat(double value) : value(value) {}
};

class VString : public Value{
public:
	std::string value;
	VString(std::string value) : value(value) {}
};
