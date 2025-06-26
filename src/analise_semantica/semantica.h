#ifndef SEMANTICA_H
#define SEMANTICA_H

#include "../ast/ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações de símbolos
typedef struct {
    char nome[32];
    Tipo tipo;
    int declarada;
    int inicializada;
} Simbolo;

// Tabela de símbolos simples
typedef struct {
    Simbolo simbolos[100];
    int tamanho;
} TabelaSimbolos;

// Funções da tabela de símbolos
void inicializarTabela(TabelaSimbolos *tabela);
int inserirSimbolo(TabelaSimbolos *tabela, const char *nome, Tipo tipo);
Simbolo* buscarSimbolo(TabelaSimbolos *tabela, const char *nome);
void marcarInicializada(TabelaSimbolos *tabela, const char *nome);
void imprimirTabela(TabelaSimbolos *tabela);

// Funções de verificação semântica
int verificarDeclaracao(TabelaSimbolos *tabela, const char *nome);
int verificarInicializacao(TabelaSimbolos *tabela, const char *nome);
int verificarCompatibilidadeTipos(Tipo tipo1, Tipo tipo2, char operador);
Tipo inferirTipoOperacao(Tipo tipo1, Tipo tipo2, char operador);
const char* obterNomeTipo(Tipo tipo);
void reportarErro(const char *mensagem, const char *detalhes);

// Funções de análise semântica para AST
int analisarAST(NoAST *no, TabelaSimbolos *tabela);
int verificarOperacao(NoAST *no, TabelaSimbolos *tabela);

// Função para finalizar análise semântica
void finalizarAnaliseSemantica(TabelaSimbolos *tabela);

// Declaração externa da variável global (definida no parser.y)
extern TabelaSimbolos tabelaGlobal;

#endif 