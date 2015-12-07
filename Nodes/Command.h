#ifndef NODES_COMMAND_H_
#define NODES_COMMAND_H_

//#include "../Objects/Arendelle.h"




class NCommand : public NExpression {
public:
    std::string cmd;
    NCommand(const std::string& cmd) : cmd(cmd) { }
    virtual Value* codeGen(Arendelle* arendelle);
};

#endif /* NODES_COMMAND_H_ */
