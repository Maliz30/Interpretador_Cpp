%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%union {
    int intValue;
}

%token <intValue> NUM
%token '+' '-' '*' '/'

%type <intValue> expressao termo fator

%%

programa:
    expressao                 { printf("Resultado: %d\n", $1); }
    ;

expressao:
      expressao '+' termo    { $$ = $1 + $3; }
    | expressao '-' termo    { $$ = $1 - $3; }
    | termo                  { $$ = $1; }
    ;

termo:
      termo '*' fator        { $$ = $1 * $3; }
    | termo '/' fator        { $$ = $1 / $3; }
    | fator                  { $$ = $1; }
    ;

fator:
      NUM                    { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}