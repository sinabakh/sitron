#include <typeinfo>
#include "Base.h"


Value* NBlock::codeGen(Arendelle* arendelle)
{
        StatementList::const_iterator it;
        Value* lVal = new Value;
        //std::cout<<"HEY : "<<statements.size()<<std::endl;
        for (it = statements.begin(); it != statements.end(); it++) {
                std::cout <<std::endl<< "Generating code for " << typeid(**it).name() << std::endl;
                lVal = (**it).codeGen(arendelle);
        }
        return lVal;
}
