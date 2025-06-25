#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "../tabela_simbolos/tabela.h"

// Variável global para a tabela de símbolos
TabelaSimbolos* tabela_global = NULL;

NoAST *criarNoOp(char op, NoAST *esq, NoAST *dir) {
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
    no->valor.v_int = val;
    no->operador = 0;
    no->tipo = TIPO_INT;
    no->esquerda = no->direita = NULL;
    return no;
}

NoAST *criarNoFloat(float val) {
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) {
        return NULL;
    }
    no->valor.v_float = val;
    no->operador = 0;
    no->tipo = TIPO_FLOAT;
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
                printf("%d", no->valor.v_int);
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

NoAST *criarNoFor(NoAST *inicializacao, NoAST *condicao, NoAST *incremento, NoAST *corpo) {
    NoAST *no = malloc(sizeof(NoAST));
    if (!no) return NULL;
    
    no->operador = 'F';
    
    // Criar nó para inicialização e condição
    NoAST *init_cond = malloc(sizeof(NoAST));
    if (!init_cond) {
        free(no);
        return NULL;
    }
    init_cond->operador = 'C';
    init_cond->esquerda = inicializacao;
    init_cond->direita = condicao;
    
    // Criar nó para incremento e corpo
    NoAST *incr_body = malloc(sizeof(NoAST));
    if (!incr_body) {
        free(init_cond);
        free(no);
        return NULL;
    }
    incr_body->operador = 'R';
    incr_body->esquerda = incremento;
    incr_body->direita = corpo;
    
    no->esquerda = init_cond;
    no->direita = incr_body;
    
    return no;
}

void liberarAST(NoAST *no) {
    if (!no) return;
    
    liberarAST(no->esquerda);
    liberarAST(no->direita);
    free(no);
}

// Função principal de interpretação
Valor interpretarAST(NoAST *no) {
    if (!no) {
        Valor vazio = {0};
        return vazio;
    }
    
    Valor resultado = {0};
    
    switch(no->operador) {
        case 0: // Nó folha (número ou identificador)
            if (strlen(no->nome) > 0) {
                // É um identificador
                Simbolo* simbolo = buscarSimbolo(tabela_global, no->nome);
                if (!simbolo) {
                    printf("ERRO: Variável '%s' não declarada\n", no->nome);
                    return resultado;
                }
                if (!simbolo->inicializada) {
                    printf("ERRO: Variável '%s' não inicializada\n", no->nome);
                    return resultado;
                }
                resultado = simbolo->valor;
            } else {
                // É um número
                switch(no->tipo) {
                    case TIPO_INT:
                        resultado.v_int = no->valor.v_int;
                        break;
                    case TIPO_FLOAT:
                        resultado.v_float = no->valor.v_float;
                        break;
                    default:
                        resultado.v_int = no->valor.v_int;
                        break;
                }
            }
            break;
            
        case '=': // Atribuição
            {
                Valor valor_direita = interpretarAST(no->direita);
                if (strlen(no->esquerda->nome) > 0) {
                    // Verificar se é uma declaração (operador 'D')
                    if (no->esquerda->operador == 'D') {
                        // É uma declaração com atribuição
                        inserirSimbolo(tabela_global, no->esquerda->nome, converterTipo(no->esquerda->tipo));
                        atualizarValorSimbolo(tabela_global, no->esquerda->nome, valor_direita);
                        printf("Variável '%s' declarada e inicializada com valor %d\n", no->esquerda->nome, valor_direita.v_int);
                    } else {
                        // É uma atribuição simples
                        Simbolo* simbolo = buscarSimbolo(tabela_global, no->esquerda->nome);
                        if (!simbolo) {
                            printf("ERRO: Variável '%s' não declarada\n", no->esquerda->nome);
                            return resultado;
                        }
                        atualizarValorSimbolo(tabela_global, no->esquerda->nome, valor_direita);
                        printf("Variável '%s' atualizada com valor %d\n", no->esquerda->nome, valor_direita.v_int);
                    }
                    resultado = valor_direita;
                }
            }
            break;
            
        case '+':
            {
                Valor esq = interpretarAST(no->esquerda);
                Valor dir = interpretarAST(no->direita);
                if (no->tipo == TIPO_FLOAT) {
                    resultado.v_float = esq.v_float + dir.v_float;
                } else {
                    resultado.v_int = esq.v_int + dir.v_int;
                }
            }
            break;
            
        case '-':
            {
                Valor esq = interpretarAST(no->esquerda);
                Valor dir = interpretarAST(no->direita);
                if (no->tipo == TIPO_FLOAT) {
                    resultado.v_float = esq.v_float - dir.v_float;
                } else {
                    resultado.v_int = esq.v_int - dir.v_int;
                }
            }
            break;
            
        case '*':
            {
                Valor esq = interpretarAST(no->esquerda);
                Valor dir = interpretarAST(no->direita);
                if (no->tipo == TIPO_FLOAT) {
                    resultado.v_float = esq.v_float * dir.v_float;
                } else {
                    resultado.v_int = esq.v_int * dir.v_int;
                }
            }
            break;
            
        case '/':
            {
                Valor esq = interpretarAST(no->esquerda);
                Valor dir = interpretarAST(no->direita);
                if (dir.v_int == 0) {
                    printf("ERRO: Divisão por zero\n");
                    return resultado;
                }
                if (no->tipo == TIPO_FLOAT) {
                    resultado.v_float = esq.v_float / dir.v_float;
                } else {
                    resultado.v_int = esq.v_int / dir.v_int;
                }
            }
            break;
            
        case '%':
            {
                Valor esq = interpretarAST(no->esquerda);
                Valor dir = interpretarAST(no->direita);
                if (dir.v_int == 0) {
                    printf("ERRO: Módulo por zero\n");
                    return resultado;
                }
                resultado.v_int = esq.v_int % dir.v_int;
            }
            break;
            
        case '<':
        case '>':
        case 'L': // <=
        case 'G': // >=
        case 'E': // ==
        case 'N': // !=
            {
                Valor esq = interpretarAST(no->esquerda);
                Valor dir = interpretarAST(no->direita);
                int resultado_bool = 0;
                
                switch(no->operador) {
                    case '<': resultado_bool = esq.v_int < dir.v_int; break;
                    case '>': resultado_bool = esq.v_int > dir.v_int; break;
                    case 'L': resultado_bool = esq.v_int <= dir.v_int; break;
                    case 'G': resultado_bool = esq.v_int >= dir.v_int; break;
                    case 'E': resultado_bool = esq.v_int == dir.v_int; break;
                    case 'N': resultado_bool = esq.v_int != dir.v_int; break;
                }
                resultado.v_bool = resultado_bool;
            }
            break;
            
        case 'I': // if
            {
                Valor condicao = interpretarAST(no->esquerda);
                if (condicao.v_bool) {
                    interpretarAST(no->direita);
                } else if (no->direita && no->direita->operador == 'B') {
                    // Tem else
                    interpretarAST(no->direita->direita);
                }
            }
            break;
            
        case 'W': // while
            {
                while (1) {
                    Valor condicao = interpretarAST(no->esquerda);
                    if (!condicao.v_bool) break;
                    interpretarAST(no->direita);
                }
            }
            break;
            
        case 'F': // for
            {
                // Inicialização
                if (no->esquerda && no->esquerda->operador == 'C') {
                    interpretarAST(no->esquerda->esquerda); // inicialização
                    
                    // Loop
                    while (1) {
                        Valor condicao = interpretarAST(no->esquerda->direita); // condição
                        if (!condicao.v_bool) break;
                        
                        interpretarAST(no->direita->direita); // corpo
                        interpretarAST(no->direita->esquerda); // incremento
                    }
                }
            }
            break;
            
        case 'P': // ++
            {
                if (strlen(no->esquerda->nome) > 0) {
                    Simbolo* simbolo = buscarSimbolo(tabela_global, no->esquerda->nome);
                    if (simbolo) {
                        simbolo->valor.v_int++;
                        resultado.v_int = simbolo->valor.v_int;
                    }
                }
            }
            break;
            
        case 'M': // --
            {
                if (strlen(no->esquerda->nome) > 0) {
                    Simbolo* simbolo = buscarSimbolo(tabela_global, no->esquerda->nome);
                    if (simbolo) {
                        simbolo->valor.v_int--;
                        resultado.v_int = simbolo->valor.v_int;
                    }
                }
            }
            break;
            
        case 'D': // declaração
            {
                if (strlen(no->nome) > 0) {
                    inserirSimbolo(tabela_global, no->nome, converterTipo(no->tipo));
                }
            }
            break;
            
        case ';': // sequência
            interpretarAST(no->esquerda);
            interpretarAST(no->direita);
            break;
            
        case ',': // lista
            interpretarAST(no->esquerda);
            interpretarAST(no->direita);
            break;
            
        default:
            printf("Operador não implementado: %c\n", no->operador);
            break;
    }
    
    return resultado;
}

void executarPrograma(NoAST *raiz) {
    if (!raiz) return;
    
    // Criar tabela de símbolos global
    tabela_global = criarTabelaSimbolos();
    if (!tabela_global) {
        printf("ERRO: Não foi possível criar tabela de símbolos\n");
        return;
    }
    
    printf("=== EXECUTANDO PROGRAMA ===\n");
    interpretarAST(raiz);
    printf("=== PROGRAMA FINALIZADO ===\n");
    
    // Imprimir estado final da tabela de símbolos
    imprimirTabelaSimbolos(tabela_global);
    
    // Limpar tabela de símbolos
    destruirTabelaSimbolos(tabela_global);
    tabela_global = NULL;
}