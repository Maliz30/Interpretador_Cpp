#ifndef AST_H
#define AST_H

typedef enum { 
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_DOUBLE,
    TIPO_CHAR,
    TIPO_BOOL,
    TIPO_STRING,
    TIPO_LONG,
    TIPO_SHORT,
    TIPO_UNSIGNED,
    TIPO_SIGNED,
    TIPO_VOID,
    TIPO_AUTO,
    TIPO_ERROR
} Tipo; // Colocar tipos que estão no lexer

typedef struct noAST {
    char operador;
    int valor;
    char nome[32];
    Tipo tipo;
    struct noAST *esquerda;
    struct noAST *direita;
} NoAST;

NoAST *criarNoOp(char op, NoAST *esq, NoAST *dir);
NoAST *criarNoNum(int val);
NoAST *criarNoId(char *nome, Tipo tipo);

void imprimirAST(NoAST *no);
int tiposCompativeis(Tipo t1, Tipo t2);

#endif