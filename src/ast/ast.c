#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

NoAST *criarNoOp(char op, NoAST *esq, NoAST *dir) { //
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) {
        return NULL;
    }
    no->operador = op;
    no->esquerda = esq;
    no->direita = dir;
    no->tipo = (esq && dir && esq->tipo == dir->tipo) ? esq->tipo : TIPO_ERROR;
    return no;
}

NoAST *criarNoNum(int val) {
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) {
        return NULL;
    }
    no->valor = val;
    no->operador = 0;
    no->tipo = TIPO_INT; //Ver como fazer cm o TIPO_INT. É uma operação de soma pra cada tipo ou dá pra fazer tudo em uma única função
    no->esquerda = no->direita = NULL;
    return no;
}

NoAST *criarNoId(char *nome, Tipo tipo) {
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) {
        return NULL;
    }
    if (nome) {
        strcpy(no->nome, nome);
    } else {
        no->nome[0] = '\0';
    }
    no->operador = 0;
    no->tipo = tipo;
    no->esquerda = no->direita = NULL;
    return no;
}

void imprimirAST(NoAST *no) {
    if (!no) return;
    
    switch(no->operador) {
        case 'D': 
            printf("DECL(%s)", no->nome);
            break;
        case 'I': 
            printf("IF(");
            imprimirAST(no->esquerda);
            printf(", ");
            if (no->direita && no->direita->operador == 'B') {
                printf("THEN(");
                imprimirAST(no->direita->esquerda);
                printf("), ELSE(");
                imprimirAST(no->direita->direita);
                printf(")");
            } else {
                imprimirAST(no->direita);
            }
            printf(")");
            break;
        case 'W': 
            printf("WHILE(");
            imprimirAST(no->esquerda);
            printf(", ");
            imprimirAST(no->direita);
            printf(")");
            break;
        case 'F': 
            printf("FOR(");
            if (no->esquerda && no->esquerda->operador == 'C' && 
                no->direita && no->direita->operador == 'R') {
                printf("INIT(");
                imprimirAST(no->esquerda->esquerda);
                printf("), COND(");
                imprimirAST(no->esquerda->direita);
                printf("), INCR(");
                imprimirAST(no->direita->esquerda);
                printf("), BODY(");
                imprimirAST(no->direita->direita);
                printf(")");
            } else {
                imprimirAST(no->esquerda);
                printf(", ");
                imprimirAST(no->direita);
            }
            printf(")");
            break;
        case 'P': 
            printf("(");
            imprimirAST(no->esquerda);
            printf("++)");
            break;
        case 'M': 
            printf("(");
            imprimirAST(no->esquerda);
            printf("--)");
            break;
        case 'C': 
            printf("INIT_COND(");
            imprimirAST(no->esquerda);
            printf(", ");
            imprimirAST(no->direita);
            printf(")");
            break;
        case 'R': // Remainder (incremento+corpo do for)
            printf("INCR_BODY(");
            imprimirAST(no->esquerda);
            printf(", ");
            imprimirAST(no->direita);
            printf(")");
            break;
        case ',': 
            printf("LIST(");
            imprimirAST(no->esquerda);
            printf(", ");
            imprimirAST(no->direita);
            printf(")");
            break;
        case ';': 
            printf("SEQ(");
            imprimirAST(no->esquerda);
            printf(", ");
            imprimirAST(no->direita);
            printf(")");
            break;
        case '<': 
        case '>': 
        case 'L': 
        case 'G':
        case 'E': 
        case 'N': 
            printf("(");
            imprimirAST(no->esquerda);
            switch(no->operador) {
                case '<': printf(" < "); break;
                case '>': printf(" > "); break;
                case 'L': printf(" <= "); break;
                case 'G': printf(" >= "); break;
                case 'E': printf(" == "); break;
                case 'N': printf(" != "); break;
            }
            imprimirAST(no->direita);
            printf(")");
            break;
        case 0: 
            if (strlen(no->nome) > 0) {
                printf("%s", no->nome);
            } else {
                printf("%d", no->valor);
            }
            break;
        default: 
            printf("(");
            imprimirAST(no->esquerda);
            printf(" %c ", no->operador);
            imprimirAST(no->direita);
            printf(")");
            break;
    }
}

int tiposCompativeis(Tipo t1, Tipo t2) {
    return t1 == t2;
}

NoAST *criarNoDeclaracao(Tipo tipo, char *nome) {
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) return NULL;
    
    no->tipo = tipo;
    if (nome) {
        strcpy(no->nome, nome);
    } else {
        no->nome[0] = '\0';
    }
    no->operador = 'D'; // declaração
    no->esquerda = no->direita = NULL;
    return no;
}

NoAST *criarNoCondicional(NoAST *condicao, NoAST *bloco_se, NoAST *bloco_senao) {
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) return NULL;
    
    no->operador = 'I'; // if
    no->esquerda = condicao;
    
    if (bloco_senao) {
        NoAST *blocos = malloc(sizeof(NoAST));
        if (!blocos) {
            free(no);
            return NULL;
        }
        blocos->operador = 'B'; // if-else
        blocos->esquerda = bloco_se;
        blocos->direita = bloco_senao;
        blocos->tipo = TIPO_VOID;
        no->direita = blocos;
    } else {
        no->direita = bloco_se;
    }
    
    no->tipo = TIPO_VOID;
    return no;
}

NoAST *criarNoLoop(char tipo_loop, NoAST *condicao, NoAST *corpo) {
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) return NULL;
    
    no->operador = tipo_loop; 
    no->esquerda = condicao;
    no->direita = corpo;
    no->tipo = TIPO_VOID;
    return no;
}

NoAST *criarNoFor(NoAST *init, NoAST *condicao, NoAST *incremento, NoAST *corpo) {
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) return NULL;
    
    no->operador = 'F'; // for loop
    no->tipo = TIPO_VOID;
    
    NoAST *init_cond = malloc(sizeof(NoAST));
    if (!init_cond) {
        free(no);
        return NULL;
    }
    init_cond->operador = 'C'; // componentes do for
    init_cond->esquerda = init;
    init_cond->direita = condicao;
    init_cond->tipo = TIPO_VOID;
    
    NoAST *incr_corpo = malloc(sizeof(NoAST));
    if (!incr_corpo) {
        free(no);
        free(init_cond);
        return NULL;
    }
    incr_corpo->operador = 'R'; // R para Remainder (incremento+corpo)
    incr_corpo->esquerda = incremento;
    incr_corpo->direita = corpo;
    incr_corpo->tipo = TIPO_VOID;
    
    no->esquerda = init_cond;
    no->direita = incr_corpo;
    
    return no;
}

void liberarAST(NoAST *no) {
    if (!no) return;
    liberarAST(no->esquerda);
    liberarAST(no->direita);
    free(no);
}