%{
#include <string>
#include "../Nodes/Node.h"
#include "../Parser/parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
//typedef struct yy_buffer_state * YY_BUFFER_STATE;
//extern YY_BUFFER_STATE yy_scan_string(char * str);
extern "C" int yywrap() { }
%}

ident [a-zA-Z_][a-zA-Z0-9_]*
whitesp [  \t\n]
shit (?=,)
text  [a-zA-Z. _]*[a-zA-Z]+

%%

\/\/.*                  ;

\/\*([^*]|[\r\n]|(\*+([^*\/]|[\r\n])))*\*+\/   ;

[@]+{text}              SAVE_TOKEN; return TSPACE;
["#"]{text}             SAVE_TOKEN; return TSOURCE;
[ ]*[p|r|d|l|u|n|c|i]+[ ]*  SAVE_TOKEN; return TCMD;
[0-9]+                  SAVE_TOKEN; return TINTEGER;
[0-9]+[.][0-9]+         SAVE_TOKEN; return TDOUBLE;
"@"                     return TOKEN(TATSIGN);
"$"                     return TOKEN(TDOLLAR);
"#"                     return TOKEN(TSHARP);
"="                     return TOKEN(TEQUAL);
"=="                    return TOKEN(TCEQ);
"!="                    return TOKEN(TCNE);
"<"                     return TOKEN(TCLT);
"<="                    return TOKEN(TCLE);
">"                     return TOKEN(TCGT);
">="                    return TOKEN(TCGE);
"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"["                     return TOKEN(TLBRACK);
"]"                     return TOKEN(TRBRACK);
"{"                     return TOKEN(TLBRACE);
"}"                     return TOKEN(TRBRACE);
","                     return TOKEN(TCOMMA);
"+"                     return TOKEN(TPLUS);
"-"                     return TOKEN(TMINUS);
"*"                     return TOKEN(TMUL);
"/"                     return TOKEN(TDIV);
"%"                     return TOKEN(TMOD);
"^"                     return TOKEN(TPOW);
{text}                  SAVE_TOKEN; return TTEXT;
{ident}                 SAVE_TOKEN; return TIDENTIFIER;
{whitesp}+              ;
.                       yyterminate();

%%
