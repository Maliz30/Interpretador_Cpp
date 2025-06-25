#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast/ast.h"

// Usar os tipos da AST
typedef Tipo TipoSimbolo;

// Union para valores (usar a mesma da AST)
typedef Valor ValorSimbolo;

// Estrutura do símbolo
typedef struct Simbolo {
    char nome[64];
    TipoSimbolo tipo;
    ValorSimbolo valor;
    int inicializada;
    int escopo;
    struct Simbolo* proximo;
} Simbolo;

// Estrutura da tabela de símbolos
typedef struct {
    Simbolo* simbolos;
    int escopo_atual;
    int capacidade;
} TabelaSimbolos;

// Funções da tabela de símbolos
TabelaSimbolos* criarTabelaSimbolos();
void destruirTabelaSimbolos(TabelaSimbolos* tabela);
Simbolo* inserirSimbolo(TabelaSimbolos* tabela, const char* nome, TipoSimbolo tipo);
Simbolo* buscarSimbolo(TabelaSimbolos* tabela, const char* nome);
void atualizarValorSimbolo(TabelaSimbolos* tabela, const char* nome, ValorSimbolo valor);
void entrarEscopo(TabelaSimbolos* tabela);
void sairEscopo(TabelaSimbolos* tabela);
void imprimirTabelaSimbolos(TabelaSimbolos* tabela);

// Funções auxiliares
TipoSimbolo converterTipo(Tipo tipo);
Tipo converterTipoSimbolo(TipoSimbolo tipo);

#endif