#include "semantica.h"

// Inicializa a tabela de símbolos
void inicializarTabela(TabelaSimbolos *tabela) {
    tabela->tamanho = 0;
    for (int i = 0; i < 100; i++) {
        tabela->simbolos[i].nome[0] = '\0';
        tabela->simbolos[i].tipo = TIPO_ERROR;
        tabela->simbolos[i].declarada = 0;
        tabela->simbolos[i].inicializada = 0;
    }
}

// Insere um símbolo na tabela
int inserirSimbolo(TabelaSimbolos *tabela, const char *nome, Tipo tipo) {
    // Verifica se já existe
    for (int i = 0; i < tabela->tamanho; i++) {
        if (strcmp(tabela->simbolos[i].nome, nome) == 0) {
            reportarErro("Variavel ja declarada", nome);
            return 0; // Falha
        }
    }
    
    // Insere novo símbolo
    if (tabela->tamanho < 100) {
        strcpy(tabela->simbolos[tabela->tamanho].nome, nome);
        tabela->simbolos[tabela->tamanho].tipo = tipo;
        tabela->simbolos[tabela->tamanho].declarada = 1;
        tabela->simbolos[tabela->tamanho].inicializada = 0;
        tabela->tamanho++;
        return 1; // Sucesso
    }
    
    reportarErro("Tabela de simbolos cheia", "");
    return 0; // Falha
}

// Busca um símbolo na tabela
Simbolo* buscarSimbolo(TabelaSimbolos *tabela, const char *nome) {
    for (int i = 0; i < tabela->tamanho; i++) {
        if (strcmp(tabela->simbolos[i].nome, nome) == 0) {
            return &tabela->simbolos[i];
        }
    }
    return NULL; // Não encontrado
}

// Marca uma variável como inicializada
void marcarInicializada(TabelaSimbolos *tabela, const char *nome) {
    Simbolo *simbolo = buscarSimbolo(tabela, nome);
    if (simbolo) {
        simbolo->inicializada = 1;
    }
}

// Imprime a tabela de símbolos
void imprimirTabela(TabelaSimbolos *tabela) {
    printf("\n=== TABELA DE SIMBOLOS ===\n");
    for (int i = 0; i < tabela->tamanho; i++) {
        printf("Nome: %-15s | Tipo: %-10s | Declarada: %s | Inicializada: %s\n",
               tabela->simbolos[i].nome,
               obterNomeTipo(tabela->simbolos[i].tipo),
               tabela->simbolos[i].declarada ? "Sim" : "Nao",
               tabela->simbolos[i].inicializada ? "Sim" : "Nao");
    }
    printf("==========================\n\n");
}

// Verifica se uma variável foi declarada
int verificarDeclaracao(TabelaSimbolos *tabela, const char *nome) {
    Simbolo *simbolo = buscarSimbolo(tabela, nome);
    if (!simbolo) {
        reportarErro("Variavel nao declarada", nome);
        return 0; // Erro
    }
    return 1; // OK
}

// Verifica se uma variável foi inicializada
int verificarInicializacao(TabelaSimbolos *tabela, const char *nome) {
    Simbolo *simbolo = buscarSimbolo(tabela, nome);
    if (!simbolo) {
        reportarErro("Variavel nao declarada", nome);
        return 0; // Erro
    }
    if (!simbolo->inicializada) {
        reportarErro("Variavel nao inicializada", nome);
        return 0; // Erro
    }
    return 1; // OK
}

// Verifica compatibilidade de tipos para operações
int verificarCompatibilidadeTipos(Tipo tipo1, Tipo tipo2, char operador) {
    // Operações matemáticas
    if (operador == '+' || operador == '-' || operador == '*' || operador == '/' || operador == '%') {
        // Int com Int
        if (tipo1 == TIPO_INT && tipo2 == TIPO_INT) return 1;
        // Float com Float
        if (tipo1 == TIPO_FLOAT && tipo2 == TIPO_FLOAT) return 1;
        // Double com Double
        if (tipo1 == TIPO_DOUBLE && tipo2 == TIPO_DOUBLE) return 1;
        // Int com Float (promoção)
        if ((tipo1 == TIPO_INT && tipo2 == TIPO_FLOAT) || 
            (tipo1 == TIPO_FLOAT && tipo2 == TIPO_INT)) return 1;
        // Int com Double (promoção)
        if ((tipo1 == TIPO_INT && tipo2 == TIPO_DOUBLE) || 
            (tipo1 == TIPO_DOUBLE && tipo2 == TIPO_INT)) return 1;
        // Float com Double (promoção)
        if ((tipo1 == TIPO_FLOAT && tipo2 == TIPO_DOUBLE) || 
            (tipo1 == TIPO_DOUBLE && tipo2 == TIPO_FLOAT)) return 1;
        
        return 0; // Incompatível
    }
    
    // Operações de comparação
    if (operador == '<' || operador == '>' || operador == '=' || operador == '!') {
        // Qualquer tipo numérico pode ser comparado
        if ((tipo1 == TIPO_INT || tipo1 == TIPO_FLOAT || tipo1 == TIPO_DOUBLE) &&
            (tipo2 == TIPO_INT || tipo2 == TIPO_FLOAT || tipo2 == TIPO_DOUBLE)) {
            return 1;
        }
        // Char pode ser comparado com char
        if (tipo1 == TIPO_CHAR && tipo2 == TIPO_CHAR) return 1;
        return 0; // Incompatível
    }
    
    // Operações lógicas (AND, OR)
    if (operador == '&' || operador == '|') {
        // Apenas booleanos para operações lógicas
        if (tipo1 == TIPO_BOOL && tipo2 == TIPO_BOOL) return 1;
        return 0; // Incompatível
    }
    
    // Atribuição
    if (operador == '=') {
        return tipo1 == tipo2 || 
               (tipo1 == TIPO_FLOAT && tipo2 == TIPO_INT) ||
               (tipo1 == TIPO_DOUBLE && (tipo2 == TIPO_INT || tipo2 == TIPO_FLOAT));
    }
    
    return 0; // Operador não reconhecido
}

// Infere o tipo resultante de uma operação
Tipo inferirTipoOperacao(Tipo tipo1, Tipo tipo2, char operador) {
    // Para operações matemáticas, retorna o tipo mais amplo
    if (operador == '+' || operador == '-' || operador == '*' || operador == '/') {
        if (tipo1 == TIPO_DOUBLE || tipo2 == TIPO_DOUBLE) return TIPO_DOUBLE;
        if (tipo1 == TIPO_FLOAT || tipo2 == TIPO_FLOAT) return TIPO_FLOAT;
        return TIPO_INT;
    }
    
    // Para módulo, só funciona com inteiros
    if (operador == '%') {
        if (tipo1 == TIPO_INT && tipo2 == TIPO_INT) return TIPO_INT;
        return TIPO_ERROR;
    }
    
    // Para comparações, retorna bool
    if (operador == '<' || operador == '>' || operador == '=' || operador == '!') {
        return TIPO_BOOL;
    }
    
    // Para operações lógicas, retorna bool
    if (operador == '&' || operador == '|') {
        return TIPO_BOOL;
    }
    
    return TIPO_ERROR;
}

// Converte tipo enum para string
const char* obterNomeTipo(Tipo tipo) {
    switch (tipo) {
        case TIPO_INT: return "int";
        case TIPO_FLOAT: return "float";
        case TIPO_DOUBLE: return "double";
        case TIPO_CHAR: return "char";
        case TIPO_BOOL: return "bool";
        case TIPO_STRING: return "string";
        case TIPO_LONG: return "long";
        case TIPO_SHORT: return "short";
        case TIPO_UNSIGNED: return "unsigned";
        case TIPO_SIGNED: return "signed";
        case TIPO_VOID: return "void";
        case TIPO_AUTO: return "auto";
        case TIPO_ERROR: return "error";
        default: return "unknown";
    }
}

// Analisa semanticamente uma AST
int analisarAST(NoAST *no, TabelaSimbolos *tabela) {
    if (!no) return 1; // Nó vazio é válido
    
    // Se é uma operação
    if (no->operador) {
        return verificarOperacao(no, tabela);
    }
    
    // Se é um identificador
    if (strlen(no->nome) > 0) {
        return verificarDeclaracao(tabela, no->nome);
    }
    
    // Se é um número, sempre válido
    return 1;
}

// Verifica uma operação na AST
int verificarOperacao(NoAST *no, TabelaSimbolos *tabela) {
    if (!no || !no->operador) return 1;
    
    // Analisa os operandos
    int esq_valido = analisarAST(no->esquerda, tabela);
    int dir_valido = analisarAST(no->direita, tabela);
    
    if (!esq_valido || !dir_valido) return 0;
    
    // Obtém os tipos dos operandos
    Tipo tipo_esq = no->esquerda ? no->esquerda->tipo : TIPO_ERROR;
    Tipo tipo_dir = no->direita ? no->direita->tipo : TIPO_ERROR;
    
    // Verifica compatibilidade de tipos
    if (!verificarCompatibilidadeTipos(tipo_esq, tipo_dir, no->operador)) {
        char erro[100];
        sprintf(erro, "Tipos incompatives para operacao '%c': %s e %s", 
                no->operador, obterNomeTipo(tipo_esq), obterNomeTipo(tipo_dir));
        reportarErro(erro, "");
        return 0;
    }
    
    // Infere o tipo resultante
    Tipo tipo_resultado = inferirTipoOperacao(tipo_esq, tipo_dir, no->operador);
    if (tipo_resultado == TIPO_ERROR) {
        char erro[100];
        sprintf(erro, "Operacao '%c' nao suportada para tipos %s e %s", 
                no->operador, obterNomeTipo(tipo_esq), obterNomeTipo(tipo_dir));
        reportarErro(erro, "");
        return 0;
    }
    
    // Atualiza o tipo do nó
    no->tipo = tipo_resultado;
    return 1;
}

// Reporta erros semânticos
void reportarErro(const char *mensagem, const char *detalhes) {
    fprintf(stderr, "ERRO SEMANTICO: %s", mensagem);
    if (strlen(detalhes) > 0) {
        fprintf(stderr, " '%s'", detalhes);
    }
    fprintf(stderr, "\n");
}

// Funcao para finalizar a analise semantica
void finalizarAnaliseSemantica(TabelaSimbolos *tabela) {
    printf("\n=== RESUMO DA ANALISE SEMANTICA ===\n");
    imprimirTabela(tabela);
    printf("Analise semantica concluida!\n");
    printf("===================================\n");
} 
