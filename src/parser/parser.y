%code requires {
#include "../ast/ast.h"
#include "../analise_semantica/semantica.h"
}
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../analise_semantica/semantica.h"

int yylex(void);
void yyerror(const char *s);

// Variável global para a tabela de símbolos
TabelaSimbolos tabelaGlobal;
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

%token TOKEN_ERROR

%start programa

%%

programa:
    programa_declaracao
    {
        printf("\n=== INICIANDO ANALISE SEMANTICA ===\n");
        inicializarTabela(&tabelaGlobal);
    }
    | programa programa_declaracao
    {
        // Finaliza a analise semantica quando o programa terminar
        finalizarAnaliseSemantica(&tabelaGlobal);
    }
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
        printf("Definicao de funcao reconhecida\n");
    }
;

bloco_escopo:
    /* Escopo vazio */
    | bloco_escopo operacoes_possiveis          
;

operacoes_possiveis:
    declaracao_variavel
    | declaracao_funcao
    | saida_dados
    | entrada_dados
    | operacao_matematica_atribuicao_valor
    | while_loop
    | for_loop
    | condicional_if
    | return
;

declaracao_funcao:
    tipagem TOKEN_ID TOKEN_LPAREN parametros_funcao TOKEN_RPAREN TOKEN_SEMICOLON
    {
        printf("Declaracao de funcao reconhecida\n");
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
        printf("Loop while reconhecido\n");
    }
;

for_loop:
    TOKEN_FOR TOKEN_LPAREN declaracao_variavel operacao_relacional TOKEN_SEMICOLON incremento TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE
    {
        printf("Loop for reconhecido\n");
    }
;

incremento:
    TOKEN_ID TOKEN_PLUS TOKEN_PLUS    // i++
    | TOKEN_ID TOKEN_MINUS TOKEN_MINUS // i--
    | TOKEN_ID TOKEN_ASSIGN TOKEN_ID operacao_matematica // i = i + 1
    | TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER operacao_matematica // i = 0 + 1
;

condicional_if:
    TOKEN_IF TOKEN_LPAREN operacao_relacional TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE
    | TOKEN_IF TOKEN_LPAREN operacao_relacional TOKEN_RPAREN TOKEN_LBRACE bloco_escopo TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE bloco_escopo TOKEN_RBRACE
    {
        printf("if reconhecido\n");
    }
;

operacao_matematica_atribuicao_valor:
    TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER TOKEN_SEMICOLON                            
    { 
        $$ = criarNoOp('=', criarNoId($1, TIPO_INT), criarNoNum($3));
        printf("AST da operacao:\n");
        imprimirAST($$);
        printf("\n");
        
        // Analise semantica
        printf("=== ANALISE SEMANTICA ===\n");
        if (analisarAST($$, &tabelaGlobal)) {
            printf("Operacao semanticamente VALIDA\n");
            printf("Tipo resultante: %s\n", obterNomeTipo($$->tipo));
        } else {
            printf("ERRO SEMANTICO na operacao!\n");
        }
        printf("========================\n\n");
    }
    | TOKEN_ID TOKEN_ASSIGN TOKEN_ID TOKEN_SEMICOLON                              
    { 
        $$ = criarNoOp('=', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT));
        printf("AST da operacao:\n");
        imprimirAST($$);
        printf("\n");
        
        // Analise semantica
        printf("=== ANALISE SEMANTICA ===\n");
        if (analisarAST($$, &tabelaGlobal)) {
            printf("Operacao semanticamente VALIDA\n");
            printf("Tipo resultante: %s\n", obterNomeTipo($$->tipo));
        } else {
            printf("ERRO SEMANTICO na operacao!\n");
        }
        printf("========================\n\n");
    }
    | TOKEN_ID TOKEN_ASSIGN operacao_matematica TOKEN_SEMICOLON                   
    { 
        $$ = criarNoOp('=', criarNoId($1, TIPO_INT), $3);
        printf("AST da operacao:\n");
        imprimirAST($$);
        printf("\n");
        
        // Analise semantica
        printf("=== ANALISE SEMANTICA ===\n");
        if (analisarAST($$, &tabelaGlobal)) {
            printf("Operacao semanticamente VALIDA\n");
            printf("Tipo resultante: %s\n", obterNomeTipo($$->tipo));
        } else {
            printf("ERRO SEMANTICO na operacao!\n");
        }
        printf("========================\n\n");
    }
;

operacao_matematica:
    TOKEN_ID TOKEN_PLUS TOKEN_ID                          { $$ = criarNoOp('+', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_MINUS TOKEN_ID                         { $$ = criarNoOp('-', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_MUL TOKEN_ID                           { $$ = criarNoOp('*', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_DIV TOKEN_ID                           { $$ = criarNoOp('/', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }
  | TOKEN_ID TOKEN_MOD TOKEN_ID                           { $$ = criarNoOp('%', criarNoId($1, TIPO_INT), criarNoId($3, TIPO_INT)); }

operacao_relacional:
    TOKEN_ID operacao_relacional_tipos TOKEN_NUMBER
    | TOKEN_ID operacao_relacional_tipos TOKEN_ID
;

operacao_relacional_tipos:
    TOKEN_LT
    | TOKEN_GT
    | TOKEN_LEQ
    | TOKEN_GEQ
    | TOKEN_EQ
    | TOKEN_NEQ
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
        printf("Saida de dados reconhecida\n");
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
    tipagem variavel TOKEN_SEMICOLON
    {
        printf("Declaracao de variavel reconhecida\n");
        // Aqui seria necessario capturar o tipo e nome da variavel
        // Por simplicidade, vamos assumir que e int por padrao
    }
;

variavel:
    TOKEN_ID
  | TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER
  | variavel TOKEN_COMMA TOKEN_ID
  | variavel TOKEN_COMMA TOKEN_ID TOKEN_ASSIGN TOKEN_NUMBER
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
        printf("Retorno de funcao reconhecido\n");
    }
;

declaracao_namespace:
    TOKEN_USING TOKEN_NAMESPACE TOKEN_ID TOKEN_SEMICOLON
    {
        printf("Declaracao de namespace reconhecida\n");
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
    fprintf(stderr, "Erro sintatico: %s\n", s);
} 