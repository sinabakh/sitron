//#include "../Objects/Arendelle.h"




class NCommand : public NExpression {
public:
    std::string cmd;
    NCommand(const std::string& cmd) : cmd(cmd) { }
    virtual Value* codeGen(Arendelle* arendelle);
};
