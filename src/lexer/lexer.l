%{
#include "../parser/parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

/* Definições de padrões de token e ações */

%%

"int"           { return TOKEN_INT; }
"float"         { return TOKEN_FLOAT; }
"double"        { return TOKEN_DOUBLE; }
"char"          { return TOKEN_CHAR; }
"bool"          { return TOKEN_BOOL; }
"string"        { return TOKEN_STRING; }
"long"          { return TOKEN_LONG; }
"short"         { return TOKEN_SHORT; }
"unsigned"      { return TOKEN_UNSIGNED; }
"signed"        { return TOKEN_SIGNED; }
"void"          { return TOKEN_VOID; }
"auto"          { return TOKEN_AUTO; }

"include"       { return TOKEN_INCLUDE; }
"using"         { return TOKEN_USING; }
"namespace"     { return TOKEN_NAMESPACE; }
"cout"          { return TOKEN_COUT; }
"cin"           { return TOKEN_CIN; }
"endl"          { return TOKEN_ENDL; }
"return"        { return TOKEN_RETURN; }

"if"            { return TOKEN_IF; }
"else"          { return TOKEN_ELSE; }
"while"         { return TOKEN_WHILE; }
"for"           { return TOKEN_FOR; }
"break"         { return TOKEN_BREAK; }

","             { return TOKEN_COMMA; }
";"             { return TOKEN_SEMICOLON; }
"("             { return TOKEN_LPAREN; }
")"             { return TOKEN_RPAREN; }
"{"             { return TOKEN_LBRACE; }
"}"             { return TOKEN_RBRACE; }

"#"             { return TOKEN_HASH; }
"<"             { return TOKEN_LT; }
">"             { return TOKEN_GT; }
"<<"            { return TOKEN_SHIFT_L; }
">>"            { return TOKEN_SHIFT_R; }
"::"            { return TOKEN_DOUBLE_COLON; }
"\""            { return TOKEN_DOUBLE_QUOTES; }
"\'"            { return TOKEN_SINGLE_QUOTES; }

"=="            { return TOKEN_EQ; }
"!="            { return TOKEN_NEQ; }
"<="            { return TOKEN_LEQ; }
">="            { return TOKEN_GEQ; }
"&&"            { return TOKEN_AND; }
"||"            { return TOKEN_OR; }

"="             { return TOKEN_ASSIGN; }
"+"             { return TOKEN_PLUS; }
"-"             { return TOKEN_MINUS; }
"*"             { return TOKEN_MUL; }
"/"             { return TOKEN_DIV; }
"%"             { return TOKEN_MOD; }


[0-9]+(\.[0-9]+)?                   { yylval.v_int = atoi(yytext); return TOKEN_NUMBER; }
"true"|"false"                      { return TOKEN_BOOL_LITERAL; }

[a-zA-Z_][a-zA-Z0-9_]*              { yylval.v_string = strdup(yytext); return TOKEN_ID; }
\"([^\\\"]|\\.)*\"                  { return TOKEN_STRING_LITERAL; }

"//".*                              { /* ignora comentários de linha */ }
"/*"([^*]|\*+[^*/])*\*+"/"          { /* ignora comentários de bloco */ }

[ \t\n]+                            { /* ignora espaços em branco */ }
[0-9]+[a-zA-Z_]+                    { return TOKEN_ERROR; }        

.                                   { return TOKEN_ERROR;  }

%%

/* Função auxiliar do Flex (quando termina o arquivo de entrada) */

int yywrap(void) {
    return 1;
}

/* Função principal: chamará o parser ao ser executado */
int main(int argc, char **argv) {
    yyparse();
    return 0;  
}