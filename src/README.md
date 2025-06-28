# Interpretador C++ - Guia Completo

## Visão Geral

Este projeto implementa um **interpretador C++** completo que vai além de um simples parser. Ele é capaz de:
- Analisar sintaxe C++ básica
- Construir uma Árvore Sintática Abstrata (AST)
- **Executar código C++ em tempo real**
- Gerenciar variáveis e escopo
- Realizar operações matemáticas e lógicas
- **Suportar entrada e saída (cin/cout)**
- **Interpretar estruturas de controle (if, while, for)**

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
│   ├── simple.cpp      # Teste básico com operações matemáticas
│   ├── io_minimal.cpp  # Teste de entrada/saída
│   ├── teste_expressao.cpp # Teste de expressões
│   ├── hello.cpp       # Hello World (sintaxe complexa)
│   ├── math.cpp        # Operações matemáticas (sintaxe complexa)
│   ├── conditional.cpp # Estruturas condicionais (sintaxe complexa)
│   ├── loop.cpp        # Loops (sintaxe complexa)
│   └── entrada_saida.cpp # Entrada/saída (sintaxe complexa)
├── makefile            # Sistema de build avançado
└── interpretador       # Executável final
```

## Compilação e Execução

### Compilação Automática (Recomendado)
```bash
cd src/
make clean    # Limpa arquivos gerados
make          # Compila o interpretador
# ou
make rebuild  # Limpa e recompila tudo
```

### Compilação Manual
```bash
cd src/
bison -d -o parser/parser.tab.c parser/parser.y
flex -o lexer/lex.yy.c lexer/lexer.l
gcc -Wall -Wextra -std=c99 parser/parser.tab.c lexer/lex.yy.c ast/ast.c tabela_simbolos/tabela.c -o interpretador
```

### Execução
```bash
# Execução com arquivo de teste
./interpretador codigos_teste/simple.cpp
./interpretador codigos_teste/io_minimal.cpp
./interpretador codigos_teste/teste_expressao.cpp
./interpretador codigos_teste/hello.cpp
./interpretador codigos_teste/math.cpp
./interpretador codigos_teste/conditional.cpp
./interpretador codigos_teste/loop.cpp
./interpretador codigos_teste/entrada_saida.cpp
./interpretador codigos_teste/teste_simples.cpp
./interpretador codigos_teste/teste_simples_io.cpp

# Execução interativa
./interpretador

# Teste interativo
make test-interactive

# Teste automático
make test-auto
```

## Funcionalidades Implementadas

### Análise Léxica
- Reconhecimento de tokens C++ básicos
- Números inteiros e float
- Identificadores
- Operadores matemáticos e relacionais
- Palavras-chave (int, float, if, while, for, etc.)
- Comentários (// e /* */)
- **Tokens de entrada/saída (cin, cout, >>, <<)**

### Análise Sintática
- Gramática C++ básica
- Construção de AST
- Verificação de sintaxe
- Tratamento de erros
- **Suporte a múltiplos comandos no topo do programa**

### Árvore Sintática Abstrata (AST)
- Representação em árvore do código
- Nós para operações matemáticas (+, -, *, /, %)
- Nós para estruturas de controle (if, while, for)
- Nós para declarações e atribuições
- **Nós para entrada/saída (cin, cout)**
- **Nós para sequência de comandos**

### Tabela de Símbolos
- Gerenciamento de variáveis
- Controle de escopo
- Verificação de declaração
- Rastreamento de inicialização
- **Suporte a múltiplos tipos de dados**

### Interpretador Completo
- **Execução real** de código C++
- Operações matemáticas (+, -, *, /, %)
- Operações relacionais (<, >, <=, >=, ==, !=)
- Estruturas de controle (if, while, for)
- Atribuições e incrementos/decrementos
- **Entrada e saída (cin/cout)**
- Tratamento de erros em tempo de execução
- **Gerenciamento de memória automático**

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

**Saída:**
```
Variável 'a' declarada e inicializada com valor 10
Variável 'b' declarada e inicializada com valor 5
Variável 'c' declarada e inicializada com valor 15
Variável 'd' declarada e inicializada com valor 5
Variável 'e' declarada e inicializada com valor 50
Variável 'f' declarada e inicializada com valor 2
```

### Exemplo 2: Entrada e Saída
```cpp
int a;
int b;
cin >> a;
cin >> b;
cout << a;
cout << b;
```

**Execução:**
```
Digite o valor para a: 5
Digite o valor para b: 8
5 
8 
```

### Exemplo 3: Expressões Complexas
```cpp
int a = 10;
int b = 5;
a = 15;
b = a + 5;
```

**Saída:**
```
Variável 'a' declarada e inicializada com valor 10
Variável 'b' declarada e inicializada com valor 5
Variável 'a' atualizada com valor 15
Variável 'b' atualizada com valor 20
```

### Exemplo 4: Estruturas Condicionais
```cpp
int x = 15;
if (x > 10) {
    int y = x + 5;
}
```

### Exemplo 5: Loops
```cpp
int i = 0;
while (i < 5) {
    i = i + 1;
}
```
