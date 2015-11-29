%{
    #include "../Nodes/Node.h"
    #include <stdio.h>
    NBlock *programBlock; /* the top level root node of our final AST */

    extern int yylex();
    extern int yylineno,yychar;
    extern char* yytext;
    int errno;
    #define ERR_UNKNOWN_CMD 1
    void yywarning(const char* msg){
        printf("WARNING: %s \n",msg);
    }
    void yyerror(const char *msg) {
        switch (errno){
        case ERR_UNKNOWN_CMD:
          printf("ERROR: %d:%d Unknown Command '%s' \n",yylineno,yychar,yytext);
          break;
        default:
          printf("ERROR: %s \n", msg);
          break;
        }
    }
%}

/* Represents the many different ways we can access our data */
%union {
    Node *node;
    NBlock *block;
    NExpression *expr;
    NStatement *stmt;
    NIdentifier *ident;
    NCommand *cmd;
    NSource *source;
    NSpace *space;
    //NVariableDeclaration *var_decl;
    //std::vector<NVariableDeclaration*> *varvec;
    //std::vector<NExpression*> *exprvec;
    std::string *string;
    int token;
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TINTEGER TDOUBLE TCMD
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> TLBRACK TRBRACK TLPAREN TRPAREN TCOMMA TATSIGN TSHARP
%token <token> TPLUS TMINUS TMUL TDIV

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <cmd> cmd
//%type <space> space
%type <expr> numeric expr loop space_decl source space mel
//%type <varvec> func_decl_args
//%type <exprvec> call_args
%type <block> program stmts block
%type <stmt> stmt func_decl
%type <token> comparison

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : stmts { programBlock = $1; }
        ;

stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
      | stmts stmt { $1->statements.push_back($<stmt>2); }
      ;

stmt :  expr { $$ = new NExpressionStatement(*$1); } | ident{errno=ERR_UNKNOWN_CMD;yyerror("");}
     ;

expr : mel | cmd | loop | space_decl
     ;

cmd : TCMD {printf("CMD... \n");$$ = new NCommand(*$1); delete $1;}
    ;

loop : TLBRACK mel TCOMMA cmd TRBRACK { $$ = new NLoop(*$2,*$4);}
     | TLBRACK mel TCOMMA loop TRBRACK { $$ = new NLoop(*$2,*$4);}
     | TLBRACK mel TCOMMA TRBRACK {yyerror("Empty Loop");}
     ;

space_decl : TLPAREN ident TCOMMA numeric TRPAREN {$$ = new NSAssignment($2,$4);}
      ;

space : TATSIGN ident { $$ = new NSpace($2);}
      ;

source : TSHARP ident { $$ = new NSource($2);}
       ;


ident : TIDENTIFIER {;$$ = new NIdentifier(*$1); delete $1;}
      ;

mel : source | space | numeric
    ;

numeric : TINTEGER {$$ = new NInteger(atol($1->c_str())); delete $1;}
        | TDOUBLE { $$ = new NDouble(atof($1->c_str())); delete $1; }
        ;

%%
