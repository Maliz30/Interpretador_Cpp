%{
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include "parser.tab.h" 
%}

/* Definições de padrões de token e ações */
%%

"int"           { return INT; }
"float"         { return FLOAT; }
"double"        { return DOUBLE; }
"char"          { return CHAR; }
"bool"          { return BOOL; }

"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"return"        { return RETURN; }

"=="            { return EQUAL; }
"!="            { return NOT_EQUAL; }
"<="            { return LESS_EQUAL; }
">="            { return GREATER_EQUAL; }
"<"             { return LESS; }
">"             { return GREATER; }
"="             { return ASSIGN; }

"+"             { return PLUS; }
"-"             { return MINUS; }
""             { return MULTIPLY; }
"/"             { return DIVIDE; }

";"             { return SEMICOLON; }
","             { return COMMA; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }

[0-9]+(.[0-9]+)?    { yylval.fval = atof(yytext); return NUMBER; }
"true"|"false"       { return BOOLLITERAL; }

[a-zA-Z][a-zA-Z0-9_]  { yylval.id = strdup(yytext); return ID; }

"//".*              { /* ignora comentários de linha / }
"/"([^]|*+[^/])*+"/" { / ignora comentários de bloco / }

[ \t\n]+            { / ignora espaços */ }

.                   { return UNRECOGNIZED; }

%%

/* Função auxiliar do Flex (quando termina o arquivo de entrada) */
int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    /* Se houver arquivo de entrada como parâmetro, redireciona o yyin */
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) {
            yyin = f;
        }
    }
    return yyparse();  /* Chama o parser gerado pelo Bison */
}