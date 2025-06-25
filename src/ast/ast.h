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

typedef union {
    int v_int;
    float v_float;
    double v_double;
    char v_char;
    int v_bool;
    char* v_string;
} Valor;

typedef struct noAST {
    char operador;
    Valor valor;
    char nome[32];
    Tipo tipo;
    struct noAST *esquerda;
    struct noAST *direita;
} NoAST;

NoAST *criarNoOp(char op, NoAST *esq, NoAST *dir);
NoAST *criarNoNum(int val);
NoAST *criarNoFloat(float val);
NoAST *criarNoId(char *nome, Tipo tipo);
NoAST *criarNoDeclaracao(Tipo tipo, char *nome);
NoAST *criarNoCondicional(NoAST *condicao, NoAST *bloco_se, NoAST *bloco_senao);
NoAST *criarNoLoop(char tipo_loop, NoAST *condicao, NoAST *corpo);
NoAST *criarNoFor(NoAST *inicializacao, NoAST *condicao, NoAST *incremento, NoAST *corpo);
NoAST *criarNoSaida(NoAST *param);
NoAST *criarNoEntrada(NoAST *param); // operador 'N' para entrada (cin)

void imprimirAST(NoAST *no);
void liberarAST(NoAST *no);
int tiposCompativeis(Tipo t1, Tipo t2);

Valor interpretarAST(NoAST *no);
void executarPrograma(NoAST *raiz);

#endif 