%code requires {
#include "../ast/ast.h"
}
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
    NoAST *no; 
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

%token TOKEN_INCLUDE
%token TOKEN_USING
%token TOKEN_NAMESPACE
%token TOKEN_COUT
%token TOKEN_CIN
%token TOKEN_ENDL
%token TOKEN_RETURN

%token TOKEN_IF
%token TOKEN_ELSE
%token TOKEN_WHILE
%token TOKEN_FOR
%token TOKEN_BREAK

%token TOKEN_COMMA
%token TOKEN_SEMICOLON
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LBRACE
%token TOKEN_RBRACE

%token TOKEN_HASH
%token TOKEN_LT
%token TOKEN_GT
%token TOKEN_SHIFT_L
%token TOKEN_SHIFT_R
%token TOKEN_DOUBLE_COLON
%token TOKEN_DOUBLE_QUOTES
%token TOKEN_SINGLE_QUOTES

%token TOKEN_EQ
%token TOKEN_NEQ                    
%token TOKEN_LEQ
%token TOKEN_GEQ
%token TOKEN_AND
%token TOKEN_OR

%token TOKEN_ASSIGN
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MUL
%token TOKEN_DIV
%token TOKEN_MOD

%token <v_int> TOKEN_NUMBER
%token TOKEN_BOOL_LITERAL

%token <v_string> TOKEN_ID
%token TOKEN_STRING_LITERAL

%type <no> operacao_matematica
%type <no> operacao_matematica_atribuicao_valor
%type <no> declaracao_variavel
%type <no> variavel
%type <no> condicional_if
%type <no> operacao_relacional
%type <no> bloco_escopo
%type <v_char> operacao_relacional_tipos
%type <no> operacoes_possiveis
%type <no> while_loop
%type <no> for_loop
%type <no> incremento

%token TOKEN_ERROR

%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MUL TOKEN_DIV TOKEN_MOD
%right TOKEN_ASSIGN

%start programa

%%

programa:
    programa_declaracao
    | programa programa_declaracao
;

programa_declaracao:
    chamada_biblioteca              
    | declaracao_namespace          
    | declaracao_variavel           
    | declaracao_funcao             
    | definicao_funcao              
;

definicao_funcao:
    tipagem TOKEN_ID TOKEN_LPAREN parametros_funcao TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE
    {
        printf("Definição de função reconhecida\n");
    }
;

bloco_escopo:
    /* Escopo vazio */ { $$ = NULL; }
    | bloco_escopo operacoes_possiveis {
        if ($1 == NULL) {
            $$ = $2;
        } else if ($2) {
            $$ = criarNoOp(';', $1, $2); 
        } else {
            $$ = $1;
        }
    }
;

operacoes_possiveis:
    declaracao_variavel { $$ = $1; }
    | declaracao_funcao { $$ = NULL; }
    | saida_dados { $$ = NULL; }
    | entrada_dados { $$ = NULL; }
    | operacao_matematica_atribuicao_valor {
        printf("AST da operação:\n");
        imprimirAST($1);
        printf("\n");
        $$ = $1;
    }
    | while_loop { 
        printf("AST do loop while:\n");
        imprimirAST($1);
        printf("\n");
        $$ = $1; 
    }
    | for_loop { 
        printf("AST do loop for:\n");
        imprimirAST($1);
        printf("\n");
        $$ = $1; 
    }
    | condicional_if {
        printf("AST do condicional:\n");
        imprimirAST($1);
        printf("\n");
        $$ = $1;
    }
    | return { $$ = NULL; }
;

declaracao_funcao:
    tipagem TOKEN_ID TOKEN_LPAREN parametros_funcao TOKEN_RPAREN TOKEN_SEMICOLON
    {
        printf("Declaração de função reconhecida\n");
    }
;

parametros_funcao:
    /* sem parametros */ 
    | funcao_declaracao_parametro
;

funcao_declaracao_parametro:
    tipagem TOKEN_ID
    | funcao_declaracao_parametro   TOKEN_COMMA tipagem TOKEN_ID
;

while_loop:
    TOKEN_WHILE TOKEN_LPAREN operacao_relacional TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE
    {
        $$ = criarNoLoop('W', $3, $6);
    }
;

for_loop:
    TOKEN_FOR TOKEN_LPAREN declaracao_variavel operacao_relacional TOKEN_SEMICOLON incremento TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE
    {
        $$ = criarNoFor($3, $4, $6, $9);
    }
;

incremento:
    TOKEN_ID TOKEN_PLUS TOKEN_PLUS                                     { $$ = criarNoOp('P', criarNoId($1, TIPO_INT), NULL); }   
    | TOKEN_ID TOKEN_MINUS TOKEN_MINUS                                 { $$ = criarNoOp('M', criarNoId($1, TIPO_INT), NULL); } 
    | TOKEN_ID TOKEN_ASSIGN TOKEN_ID TOKEN_PLUS TOKEN_NUMBER           { $$ = criarNoOp('=', criarNoId($1, TIPO_INT), criarNoOp('+', criarNoId($3, TIPO_INT), criarNoNum($5))); }   
    | TOKEN_ID TOKEN_ASSIGN TOKEN_ID TOKEN_MINUS TOKEN_NUMBER          { $$ = criarNoOp('=', criarNoId($1, TIPO_INT), criarNoOp('-', criarNoId($3, TIPO_INT), criarNoNum($5))); } 
;

condicional_if:
    TOKEN_IF TOKEN_LPAREN operacao_relacional TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE {
        $$ = criarNoCondicional($3, $6, NULL);
    }
    | TOKEN_IF TOKEN_LPAREN operacao_relacional TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE bloco_escopo TOKEN_RBRACE {
        $$ = criarNoCondicional($3, $6, $10);
    }
;

operacao_matematica_atribuicao_valor:
    TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER TOKEN_SEMICOLON                            { $$ = criarNoOp('=', criarNoId($1, TIPO_INT), criarNoNum($3));}
    | TOKEN_ID TOKEN_ASSIGN TOKEN_ID TOKEN_SEMICOLON                              { $$ = criarNoOp('=', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT));}
    | TOKEN_ID TOKEN_ASSIGN operacao_matematica TOKEN_SEMICOLON                   { $$ = criarNoOp('=', criarNoId($1, TIPO_INT), $3); } 
;

operacao_matematica:
    TOKEN_ID TOKEN_PLUS TOKEN_ID                          { $$ = criarNoOp('+', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_MINUS TOKEN_ID                         { $$ = criarNoOp('-', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_MUL TOKEN_ID                           { $$ = criarNoOp('*', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_DIV TOKEN_ID                           { $$ = criarNoOp('/', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_MOD TOKEN_ID                           { $$ = criarNoOp('%', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_PLUS TOKEN_NUMBER                      { $$ = criarNoOp('+', criarNoId($1, TIPO_INT), criarNoNum($3)); }
  | TOKEN_ID TOKEN_MINUS TOKEN_NUMBER                     { $$ = criarNoOp('-', criarNoId($1, TIPO_INT), criarNoNum($3)); }
  | TOKEN_ID TOKEN_MUL TOKEN_NUMBER                       { $$ = criarNoOp('*', criarNoId($1, TIPO_INT), criarNoNum($3)); }
  | TOKEN_ID TOKEN_DIV TOKEN_NUMBER                       { $$ = criarNoOp('/', criarNoId($1, TIPO_INT), criarNoNum($3)); }
  | TOKEN_ID TOKEN_MOD TOKEN_NUMBER                       { $$ = criarNoOp('%', criarNoId($1, TIPO_INT), criarNoNum($3)); }
  | TOKEN_NUMBER TOKEN_PLUS TOKEN_ID                      { $$ = criarNoOp('+', criarNoNum($1), criarNoId($3, TIPO_INT)); }
  | TOKEN_NUMBER TOKEN_MINUS TOKEN_ID                     { $$ = criarNoOp('-', criarNoNum($1), criarNoId($3, TIPO_INT)); }
  | TOKEN_NUMBER TOKEN_MUL TOKEN_ID                       { $$ = criarNoOp('*', criarNoNum($1), criarNoId($3, TIPO_INT)); }
  | TOKEN_NUMBER TOKEN_DIV TOKEN_ID                       { $$ = criarNoOp('/', criarNoNum($1), criarNoId($3, TIPO_INT)); }
  | TOKEN_NUMBER TOKEN_MOD TOKEN_ID                       { $$ = criarNoOp('%', criarNoNum($1), criarNoId($3, TIPO_INT)); }
  | TOKEN_NUMBER TOKEN_PLUS TOKEN_NUMBER                  { $$ = criarNoOp('+', criarNoNum($1), criarNoNum($3)); }
  | TOKEN_NUMBER TOKEN_MINUS TOKEN_NUMBER                 { $$ = criarNoOp('-', criarNoNum($1), criarNoNum($3)); }
  | TOKEN_NUMBER TOKEN_MUL TOKEN_NUMBER                   { $$ = criarNoOp('*', criarNoNum($1), criarNoNum($3)); }
  | TOKEN_NUMBER TOKEN_DIV TOKEN_NUMBER                   { $$ = criarNoOp('/', criarNoNum($1), criarNoNum($3)); }
  | TOKEN_NUMBER TOKEN_MOD TOKEN_NUMBER                   { $$ = criarNoOp('%', criarNoNum($1), criarNoNum($3)); }
  | TOKEN_LPAREN operacao_matematica TOKEN_RPAREN        { $$ = $2; }
;

operacao_relacional:
    TOKEN_ID operacao_relacional_tipos TOKEN_NUMBER {
        $$ = criarNoOp($2, criarNoId($1, TIPO_INT), criarNoNum($3));
    }
    | TOKEN_ID operacao_relacional_tipos TOKEN_ID {
        $$ = criarNoOp($2, criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT));
    }
    | TOKEN_NUMBER operacao_relacional_tipos TOKEN_ID {
        $$ = criarNoOp($2, criarNoNum($1), criarNoId($3, TIPO_INT));
    }
    | TOKEN_NUMBER operacao_relacional_tipos TOKEN_NUMBER {
        $$ = criarNoOp($2, criarNoNum($1), criarNoNum($3));
    }
;

operacao_relacional_tipos:
    TOKEN_LT    { $$ = '<'; }
    | TOKEN_GT  { $$ = '>'; }
    | TOKEN_LEQ { $$ = 'L'; } // L para <=
    | TOKEN_GEQ { $$ = 'G'; } // G para >=
    | TOKEN_EQ  { $$ = 'E'; } // E para ==
    | TOKEN_NEQ { $$ = 'N'; } // N para !=
;

entrada_dados:
    TOKEN_CIN entrada_dados_parametros TOKEN_SEMICOLON
    {
        printf("Entrada de dados reconhecida\n");
    }
;

entrada_dados_parametros:
    TOKEN_SHIFT_R TOKEN_ID
    | entrada_dados_parametros TOKEN_SHIFT_R TOKEN_ID
;

saida_dados:
    TOKEN_COUT saida_dados_parametro TOKEN_SEMICOLON
    {
        printf("Saída de dados reconhecida\n");
    }
;

saida_dados_parametro:
    TOKEN_SHIFT_L saida_dados_opcoes
    | saida_dados_parametro TOKEN_SHIFT_L saida_dados_opcoes
;

saida_dados_opcoes:
    TOKEN_ID 
    | TOKEN_STRING_LITERAL 
    | TOKEN_ENDL 
;

declaracao_variavel:
    tipagem variavel TOKEN_SEMICOLON {
        printf("Declaração de variável reconhecida\n");
        imprimirAST($2);
        printf("\n");
        $$ = $2;
    }
;

variavel:
    TOKEN_ID { $$ = criarNoId($1, TIPO_INT); }
  | TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER { $$ = criarNoOp('=', criarNoId($1, TIPO_INT), criarNoNum($3)); }
  | variavel TOKEN_COMMA TOKEN_ID { $$ = criarNoOp(',', $1, criarNoId($3, TIPO_INT)); }
  | variavel TOKEN_COMMA TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER { $$ = criarNoOp(',', $1, criarNoOp('=', criarNoId($3, TIPO_INT), criarNoNum($5))); }
;

tipagem:
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

return:
    TOKEN_RETURN TOKEN_NUMBER TOKEN_SEMICOLON
    {
        printf("Retorno de função reconhecido\n");
    }
;

declaracao_namespace:
    TOKEN_USING TOKEN_NAMESPACE TOKEN_ID TOKEN_SEMICOLON
    {
        printf("Declaração de namespace reconhecida\n");
    }
;

chamada_biblioteca:
    TOKEN_HASH TOKEN_INCLUDE TOKEN_LT TOKEN_ID TOKEN_GT
    {
        printf("Chamada de biblioteca reconhecida\n");
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}
