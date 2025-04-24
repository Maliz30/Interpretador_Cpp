%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int yylex(void);
void yyerror(const char *s);
%}



%union {
    int v_int;           
    float v_float;      
    double v_double;  
    char v_char;
    int v_bool;   
    char *v_string;    
    long v_long;
    short v_short;    
    unsigned v_unsigned;  
    signed v_signed;
}

%token <v_int> TOKEN_INT
%token <v_float> TOKEN_FLOAT
%token <v_double> TOKEN_DOUBLE
%token <v_char> TOKEN_CHAR
%token <v_bool> TOKEN_BOOL
%token <v_string> TOKEN_STRING
%token <v_long> TOKEN_LONG
%token <v_short> TOKEN_SHORT
%token <v_unsigned> TOKEN_UNSIGNED
%token <v_signed> TOKEN_SIGNED
%token TOKEN_AUTO
%token TOKEN_VOID

%token TOKEN_ID

%token TOKEN_COMMA;
%token TOKEN_SEMICOLON
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LBRACE
%token TOKEN_RBRACE



%token <intValue> NUM /* Apagar após corrigir a soma de números*/
%token '+' '-' '*' '/'

%type <intValue> expressao termo fator


%start programa

%%

programa:
    expressao                 { printf("Resultado: %d\n", $1); }
    | declaracao_variavel
    | declaracao_funcao
    | definicao_funcao
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



definicao_funcao:
    tipos TOKEN_ID TOKEN_LPAREN parametros_funcao TOKEN_RPAREN TOKEN_LBRACE escopo_funcao TOKEN_RBRACE
    {
        printf("Definição de função reconhecida\n");
    }
;

escopo_funcao:
    /* Escopo vazio */
    | declaracao_variavel /* Adicionar mais opçoes de escopo -> Pendente */
;

declaracao_funcao:
    tipos TOKEN_ID TOKEN_LPAREN parametros_funcao TOKEN_RPAREN TOKEN_SEMICOLON
    {
        printf("Declaração de função reconhecida\n");
    }
;

parametros_funcao:
    /* sem parametros */ 
    | declaracao_parametro
;

declaracao_parametro:
    tipos TOKEN_ID
    | declaracao_parametro TOKEN_COMMA tipos TOKEN_ID
;

declaracao_variavel:
    tipos TOKEN_ID TOKEN_SEMICOLON
    {
        printf("Declaração de variável reconhecida\n");
    }
;

tipos:
    TOKEN_INT        
    | TOKEN_FLOAT     
    | TOKEN_DOUBLE    
    | TOKEN_CHAR      
    | TOKEN_BOOL      
    | TOKEN_STRING    
    | TOKEN_LONG      
    | TOKEN_SHORT     
    | TOKEN_UNSIGNED  
    | TOKEN_SIGNED    
    | TOKEN_AUTO      
    | TOKEN_VOID
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}