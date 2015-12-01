#include <iostream>
#include <typeinfo>
#include "Nodes/Node.h"
#include "Objects/Arendelle.h"
#include "Objects/Screen.h"
#include "Parser/parser.hpp"

//typedef struct yy_buffer_state * YY_BUFFER_STATE;
//extern YY_BUFFER_STATE yy_scan_string(char * str);
//extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

//extern yy_buffer_state;
//typedef yy_buffer_state *YY_BUFFER_STATE;
extern NBlock* programBlock;
extern int yyparse();
extern int yyerror(const char* str);

int main(int argc, char **argv)
{
    Arendelle* arendelle = new Arendelle();
    //char string[] = "p";
    //YY_BUFFER_STATE buffer = yy_scan_string(string);
    yyparse();
    //yy_delete_buffer(buffer);
    if(programBlock->statements.size()!=0)
       programBlock->codeGen(arendelle);
    std::cout<<"_______________________"<<std::endl<<std::endl;
    arendelle->getScreen()->prettyPrint();
    std::cout<<std::endl;
    return 0;
}