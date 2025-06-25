# Interpretador C++ - Guia Completo

## Visão Geral

Este projeto implementa um **interpretador C++** completo que vai além de um simples parser. Ele é capaz de:
- Analisar sintaxe C++ básica
- Construir uma Árvore Sintática Abstrata (AST)
- Executar código C++ em tempo real
- Gerenciar variáveis e escopo
- Realizar operações matemáticas e lógicas

## Pré-requisitos

- **Flex** - Gerador de analisadores léxicos
- **Bison** - Gerador de analisadores sintáticos  
- **GCC** - Compilador GNU para C/C++

### Instalação no Ubuntu/Debian:
```bash
sudo apt update
sudo apt install flex bison gcc build-essential
```

## Estrutura do Projeto

```
src/
├── lexer/              # Analisador léxico (Flex)
│   ├── lexer.l         # Especificação dos tokens
│   └── lex.yy.c        # Código gerado pelo Flex
├── parser/             # Analisador sintático (Bison)
│   ├── parser.y        # Gramática do parser
│   ├── parser.tab.c    # Código gerado pelo Bison
│   └── parser.tab.h    # Header gerado pelo Bison
├── ast/                # Árvore Sintática Abstrata
│   ├── ast.h           # Definições da AST
│   └── ast.c           # Implementação da AST e interpretador
├── tabela_simbolos/    # Tabela de símbolos
│   ├── tabela.h        # Definições da tabela
│   └── tabela.c        # Implementação da tabela
├── codigos_teste/      # Arquivos de teste
│   ├── simple.cpp      # Teste básico
│   ├── hello.cpp       # Hello World
│   ├── math.cpp        # Operações matemáticas
│   ├── conditional.cpp # Estruturas condicionais
│   ├── loop.cpp        # Loops
│   └── entrada_saida.cpp # Entrada/saída
├── makefile            # Sistema de build
└── interpretador       # Executável final
```

## Compilação e Execução

### Compilação Automática (Recomendado)
```bash
cd src/
make clean    # Limpa arquivos gerados
make          # Compila o interpretador
```

### Compilação Manual
```bash
cd src/
bison -d -o parser/parser.tab.c parser/parser.y
flex -o lexer/lex.yy.c lexer/lexer.l
gcc parser/parser.tab.c lexer/lex.yy.c ast/ast.c tabela_simbolos/tabela.c -o interpretador
```

### Execução
```bash
# Execução interativa
./interpretador

# Execução com arquivo de teste
./interpretador < codigos_teste/hello.cpp
./interpretador < codigos_teste/math.cpp
./interpretador < codigos_teste/conditional.cpp
./interpretador < codigos_teste/loop.cpp
./interpretador < codigos_teste/entrada_saida.cpp
./interpretador < codigos_teste/simple.cpp
./interpretador < codigos_teste/teste_simples.cpp
./interpretador < codigos_teste/teste_expressao.cpp

# Testes específicos
make run-hello
make run-math
make run-conditional
make run-loop
make run-entrada-saida
make test-simple
```

## Funcionalidades Implementadas

### Análise Léxica
- Reconhecimento de tokens C++ básicos
- Números inteiros e float
- Identificadores
- Operadores matemáticos e relacionais
- Palavras-chave (int, float, if, while, for, etc.)
- Comentários (// e /* */)

### Análise Sintática
- Gramática C++ básica
- Construção de AST
- Verificação de sintaxe
- Tratamento de erros

### Árvore Sintática Abstrata (AST)
- Representação em árvore do código
- Nós para operações matemáticas
- Nós para estruturas de controle
- Nós para declarações e atribuições

### Tabela de Símbolos
- Gerenciamento de variáveis
- Controle de escopo
- Verificação de declaração
- Rastreamento de inicialização

### Interpretador
- **Execução real** de código C++
- Operações matemáticas (+, -, *, /, %)
- Operações relacionais (<, >, <=, >=, ==, !=)
- Estruturas de controle (if, while, for)
- Atribuições e incrementos/decrementos
- Tratamento de erros em tempo de execução

### Gerenciamento de Memória
- Liberação automática da AST
- Limpeza da tabela de símbolos
- Prevenção de vazamentos de memória

## Exemplos de Uso

### Exemplo 1: Operações Matemáticas
```cpp
int a = 10;
int b = 5;
int c = a + b;
int d = a - b;
int e = a * b;
int f = a / b;
```

### Exemplo 2: Estruturas Condicionais
```cpp
int x = 15;
if (x > 10) {
    int y = x + 5;
}
```

### Exemplo 3: Loops
```cpp
int i = 0;
while (i < 5) {
    i = i + 1;
}
```
