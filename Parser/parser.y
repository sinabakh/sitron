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
%token <string> TIDENTIFIER TTEXT TINTEGER TDOUBLE TCMD TSPACE TSOURCE
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TNOT
%token <token> TLBRACK TRBRACK TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TATSIGN TDOLLAR TSHARP
%token <token> TPLUS TMINUS TMUL TDIV TMOD TPOW

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <ident> text
%type <cmd> cmd
//%type <space> space
%type <expr> numeric expr loop condition func_cal space_decl source space mel term_lone term_ltwo mel_base
//%type <varvec> func_decl_args
//%type <exprvec> call_args
%type <block> program stmts block func_decl
%type <stmt> stmt
%type <token> operator_lone operator_ltwo operator_lthree

/* Operator precedence for mathematical operators */
//%left TPLUS TMINUS
//%left TMUL TDIV

%start program

%%

program : stmts { programBlock = $1; }
        ;

stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
      | stmts stmt { $1->statements.push_back($<stmt>2); }
      ;

stmt : expr {$$ = new NExpressionStatement(*$1); }
     | ident{errno=ERR_UNKNOWN_CMD;yyerror("");}
     ;

expr : mel | cmd | loop | condition | space_decl | func_cal
     ;

cmd : TCMD {;$$ = new NCommand(*$1); delete $1;}
    ;

func_cal : TNOT text TLPAREN TRPAREN {$$ = new NFunction(new NIdentifier(*$2));}
         ;

loop : TLBRACK mel TCOMMA expr TRBRACK { $$ = new NLoop($2,$4);}
     | TLBRACK mel TCOMMA TRBRACK {yyerror("Empty Loop");}
     ;

condition : TLBRACE mel TCOMMA expr TRBRACE {NIdentifier* fcd = new NIdentifier("");$$ = new NCondition($2,$4,fcd);}
          | TLBRACE mel TCOMMA expr TCOMMA expr TRBRACE {$$ = new NCondition($2,$4,$6);}
          ;

space_decl : TLPAREN text TCOMMA mel TRPAREN {$$ = new NSAssignment($2,$4);}
           | TLPAREN TDOLLAR text TCOMMA mel TRPAREN {printf("Stored Space... \n");$$ = new NSTSAssignment($3,$5);}
      ;

space : TSPACE { NIdentifier* tmp = new NIdentifier(*$1) ;$$ = new NSpace(tmp);}
      | TDOLLAR text {$$ = new NSTSpace($2);}
      ;

source : TSOURCE { NIdentifier* tmp = new NIdentifier(*$1) ; $$ = new NSource(tmp);}
       ;


ident : TIDENTIFIER {;$$ = new NIdentifier(*$1); delete $1;}
      ;

text : TTEXT {$$ = new NIdentifier(*$1); delete $1;}
      ;

mel : term_lone{}
    | mel operator_lthree term_lone {$$ = new NBinaryOperator($1,$2,$3);}

term_lone : term_ltwo
    | term_lone operator_lone term_ltwo {$$ = new NBinaryOperator($1,$2,$3);}
    ;

term_ltwo: mel_base | term_ltwo operator_ltwo mel_base {$$ = new NBinaryOperator($1,$2,$3);}
         ;

mel_base : source | space | numeric | TLPAREN mel TRPAREN {$$ = $2;}
         ;

numeric : TINTEGER {$$ = new NInteger(atol($1->c_str())); delete $1;}
        | TDOUBLE { $$ = new NDouble(atof($1->c_str())); delete $1; }
        ;

operator_lone : TPLUS | TMINUS
              ;

operator_ltwo : TMUL | TDIV | TMOD | TPOW
              ;

operator_lthree : TCLT | TCLE | TEQUAL | TCEQ | TCNE
                | TCGT | TCGE
                ;

%%
