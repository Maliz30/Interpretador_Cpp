#include "tabela.h"
#include "../ast/ast.h"

TabelaSimbolos* criarTabelaSimbolos() {
    TabelaSimbolos* tabela = malloc(sizeof(TabelaSimbolos));
    if (!tabela) return NULL;
    
    tabela->simbolos = NULL;
    tabela->escopo_atual = 0;
    tabela->capacidade = 0;
    return tabela;
}

void destruirTabelaSimbolos(TabelaSimbolos* tabela) {
    if (!tabela) return;
    
    Simbolo* atual = tabela->simbolos;
    while (atual) {
        Simbolo* proximo = atual->proximo;
        if (atual->tipo == TIPO_STRING && atual->valor.v_string) {
            free(atual->valor.v_string);
        }
        free(atual);
        atual = proximo;
    }
    free(tabela);
}

Simbolo* inserirSimbolo(TabelaSimbolos* tabela, const char* nome, TipoSimbolo tipo) {
    if (!tabela || !nome) return NULL;
    
    // Verificar se já existe no escopo atual
    Simbolo* existente = buscarSimbolo(tabela, nome);
    if (existente && existente->escopo == tabela->escopo_atual) {
        return existente; // Já existe no escopo atual
    }
    
    Simbolo* novo = malloc(sizeof(Simbolo));
    if (!novo) return NULL;
    
    strncpy(novo->nome, nome, 63);
    novo->nome[63] = '\0';
    novo->tipo = tipo;
    novo->inicializada = 0;
    novo->escopo = tabela->escopo_atual;
    novo->proximo = tabela->simbolos;
    tabela->simbolos = novo;
    tabela->capacidade++;
    
    return novo;
}

Simbolo* buscarSimbolo(TabelaSimbolos* tabela, const char* nome) {
    if (!tabela || !nome) return NULL;
    
    Simbolo* atual = tabela->simbolos;
    while (atual) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void atualizarValorSimbolo(TabelaSimbolos* tabela, const char* nome, ValorSimbolo valor) {
    Simbolo* simbolo = buscarSimbolo(tabela, nome);
    if (simbolo) {
        simbolo->valor = valor;
        simbolo->inicializada = 1;
    }
}

void entrarEscopo(TabelaSimbolos* tabela) {
    if (tabela) {
        tabela->escopo_atual++;
    }
}

void sairEscopo(TabelaSimbolos* tabela) {
    if (tabela && tabela->escopo_atual > 0) {
        // Remover símbolos do escopo atual
        Simbolo** atual = &tabela->simbolos;
        while (*atual) {
            if ((*atual)->escopo == tabela->escopo_atual) {
                Simbolo* temp = *atual;
                *atual = temp->proximo;
                if (temp->tipo == TIPO_STRING && temp->valor.v_string) {
                    free(temp->valor.v_string);
                }
                free(temp);
                tabela->capacidade--;
            } else {
                atual = &(*atual)->proximo;
            }
        }
        tabela->escopo_atual--;
    }
}

void imprimirTabelaSimbolos(TabelaSimbolos* tabela) {
    if (!tabela) return;
    
    printf("\n=== TABELA DE SÍMBOLOS ===\n");
    printf("Escopo atual: %d\n", tabela->escopo_atual);
    printf("Total de símbolos: %d\n\n", tabela->capacidade);
    
    Simbolo* atual = tabela->simbolos;
    while (atual) {
        printf("Nome: %-15s | Tipo: %-8s | Escopo: %d | Inicializada: %s\n",
               atual->nome,
               (atual->tipo == TIPO_INT) ? "int" :
               (atual->tipo == TIPO_FLOAT) ? "float" :
               (atual->tipo == TIPO_DOUBLE) ? "double" :
               (atual->tipo == TIPO_CHAR) ? "char" :
               (atual->tipo == TIPO_BOOL) ? "bool" :
               (atual->tipo == TIPO_STRING) ? "string" : "void",
               atual->escopo,
               atual->inicializada ? "Sim" : "Não");
        atual = atual->proximo;
    }
    printf("==========================\n\n");
}

TipoSimbolo converterTipo(Tipo tipo) {
    return tipo;
}

Tipo converterTipoSimbolo(TipoSimbolo tipo) {
    return tipo;
}
