# Ponto de Controle 1

## Formulário

### Nome da equipe
Grupo 7

### Nomes dos integrantes e respectivas matrículas

- Maria Alice Bernardo Costa - 211063210
- Luis Eduardo Carneiro Miranda - 211063200      
- Milena Baruc Rodrigues Morais - 211062339
- Nicolas Bomfim Dias Bandeira - 211062348 
- Gabriel Saraiva Canabrava -  202045769
- Pablo Santos Costa - 180128817

### Linguagem escolhida para tratamento pelo compilador/interpretador:
C++

### Tipo do projeto
Interpretador

### Metodologia adotada para o planejamento
Scrum

### Número de sprints realizadas até o momento
2

### Objetivos planejados para as sprints já concluídas

- Criação do repositório GitHub
- Documentação do projeto (Mkdocs, templates)
- Configuração do ambiente de desenvolvimento
- Planejamento das sprints
- Definição do subconjunto C++ a ser suportado
- Definição de tokens para tipos (int, float, bool, string, etc.)
- Expressões regulares para operadores (+, -, &&, ||, ==, !=, ++, --)
- Tratamento de comentários e whitespace
- Implementação do lexer e do parser
- Testes unitários para tokens

### Principais entregas já implementadas no projeto

- Definir a linguagem-fonte do interpretador (sintaxe e semântica básica)
- Análise léxica com Flex (definição dos tokens da linguagem).
- Primeiras regras sintáticas no arquivo .y, permitindo testar códigos simples na linguagem.
- Tokens testados, porém não cobre todos os casos

### Principais dificuldades enfrentadas e como foram resolvidas

- Entender o funcionamento do léxico, do parser. 
- Dificuldade para fazer o Bison funcionar em conjunto com os tokens definidos no léxico.
- Através de video-aulas e leituras, conseguimos avançar.

### O que ainda falta implementar até a próxima entrega?

- Cobrir uma maior parte de testes com o analisador sintático. 
- Gerar árvore sintática abstrata (AST)
- Implementar a interpretação da AST

### Link do repositório GitHub
https://github.com/Maliz30/Interpretador_Cpp-Py

### Comentários adicionais sobre o repositório
Há um git pages com conteúdos como documentação de sprints (planing, review), planejamento de sprints futuras, boas práticas e como rodar os testes do que foi implementado até o momento.

### O repositório está atualizado com os últimos commits?
Sim

## Outras informações

### Planejamento das sprints

A metodologia de desenvolvimento adotada é o Scrum, devido à sua abordagem ágil e iterativa que favorece a organização do trabalho em ciclos curtos com entregas frequentes. Desde o início do projeto até a entrega do Ponto de Controle 1, foram realizadas duas sprints, cada uma com metas bem definidas.

Essas sprints tiveram como principais objetivos:


**Sprint 1**: _(09/04 - 14/04)_

Objetivo: Estabelecer fundamentos do projeto

Tarefas:

- Criação do repositório GitHub
- Documentação do projeto (Mkdocs, templates)
- Configuração do ambiente de desenvolvimento
- Planejamento das sprints
- Definição do subconjunto C++ a ser suportado

<br>

**Sprint 2**: _(15/04 - 30/04)_

Objetivo: Especificar e implementar tokens básicos

Tarefas:

- Definição de tokens para tipos básicos (int, float, bool, string, etc.)
- Expressões regulares para operadores (+, -, &&, ||, ==, !=, ++, --)
- Tratamento de comentários e whitespace
- Implementação do lexer e do parser
- Testes unitários para tokens
- Preparação para P1


<br>

A documentação detalhada de cada uma delas pode ser consultada nos links abaixo:

Sprint 1:

- [planning](../sprints/sprint-1/sprint-planning.md)
- [review](../sprints/sprint-1/sprint-review.md)

Sprint 2:

- [planning](../sprints/sprint-2/sprint-planning.md)
- [review](../sprints/sprint-2/sprint-review.md)

### O que foi implementado 

- Chamada de bibliotecas
- Declaração de namespaces
- Tipo de variáveis e funções
- Declaração e Definição de funções
- Declaração de variáveis
- Operações matemáticas básicas (+ - * / % )
- Entrada e saída de dados usando `cin` e `cout`
- Condicionais e Loops (if, while, for)


### Testes realizados

Neste [link](https://maliz30.github.io/Interpretador_Cpp-Py/como-rodar/) é possível visualizar como rodar um teste.

#### Hello World

``` c++
#include <iostream>

using namespace std ;

int main ( ) {

    cout << "Hello World" << endl ;

    return 0 ;
}
```

#### Operações matemáticas

``` c++
#include <iostream>

using namespace std;

int main(){

    int a, b;
    cin >> a >> b;
    
    int soma, sub, mult, div, rest;

    soma = a + b;
    sub = a - b; 
    mult = a * b;
    div = a / b;
    rest = a % b;

    cout << "Soma: " << a << " + " << b << " = " << soma << endl;

    cout << "Subtração: " << a << " - " << b << " = " << sub << endl;

    cout << "Multiplicação: " << a << " x " << b << " = " << mult << endl;

    cout << "Divisão: " << a << " / " << b << " = " << div << endl;

    cout << "Resto: " << a << " % " << b << " = " << rest << endl;

    return 0;
}
```

#### Condicionais

``` c++
#include <iostream>

using namespace std;

int main()
{
    int x = 10;

    if (x < 11)
    {
        cout << "x < 11 is true!\n";
    } else {
        cout << "x < 11 is true!\n";
    }
}
```

#### Loops

``` c++
#include <iostream>

using namespace std ;

int main ( ) {

    for (int i = 0; i < 5; i++){
        int a;
    }
    int i = 0;
    
    while (i < 5) {
        int x = 10;
    }

    return 0 ;
}
```
## Histórico de versões

<center>

| Versão | Data       | Descrição                     | Autor(es)                                            | Revisor(es)                                      |
| ------ | ---------- | ----------------------------- | ---------------------------------------------------- | ------------------------------------------------ |
| 1.0    | 28/04/2025 | Documentação do Ponto de Controle 1 | [Maria Alice](https://github.com/MilenaBaruc)  | [Nicolas Bonfim](https://github.com/NickGehjk) |

</center>