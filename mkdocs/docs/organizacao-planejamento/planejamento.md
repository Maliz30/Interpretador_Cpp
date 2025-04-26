
# Cronograma do Projeto

Com auxílio do [cronograma planejado pelo professor](https://github.com/Maliz30/Compiladores-1-Material-de-Aula/blob/main/semana%2001/docs/Guia%20-%20Projeto%20de%20um%20interpretador.md), a equipe gerou um novo cronograma para ser executado ao longo do desenvolvimento do interpretador. O cronograma foi ajustado para se adequar as necessidades da equipe e as datas de entrega da disciplina.



## Visão Geral

| Sprint | Período       | Objetivo Principal                   | Entregáveis                                  |
|--------|---------------|--------------------------------------|----------------------------------------------|
| 1      | 09/04 - 14/04 | Definição do projeto e ambiente      | Documentação inicial, escolha de ferramentas |
| 2      | 15/04 - 30/04 | Desenvolver do analisador léxico e analisador sintático | Arquivo .l completo, Primeiras regras sintáticas no arquivo .y e Formulário de P1              |
| 3      | 01/05 - 14/05 | Árvore Sintática Abstrata (AST) e Análise semântica | AST consolidada, Módulo de análise semântica inicial e Parser que constrói a AST           |
| 4      | 15/05 - 04/06 | Geração de código intermediário      | Módulo interpretador, Análise semântica mais robusta e Formulário do P2            |
| 5      | 05/06 - 25/06 | Otimização e testes                  | Interpretador ampliado, com eventuais otimizações e funcionalidades extras, Testes e Versão final pronta    |
| 6      | 26/06 - 09/07 | Ajustes Finais                       | Entrevistas de entrega, Documentação completa e Ajustes finais (caso necessário)    |

## Detalhamento por Sprint

### Sprint 1
_(09/04 - 14/04)_

**Objetivo:** Estabelecer fundamentos do projeto

**Tarefas:**

- Criação do repositório GitHub
- Documentação do projeto (Mkdocs, templates)
- Configuração do ambiente de desenvolvimento
- Planejamento das sprints
- Definição do subconjunto C++ a ser suportado

<br>

Acesso rápido a documentação dessa sprint:

- [planning](../sprints/sprint-1/sprint-planning.md)
- [review](../sprints/sprint-1/sprint-review.md)

### Sprint 2
_(15/04 - 30/04)_

**Objetivo:** Especificar e implementar tokens básicos

**Tarefas:**

- Definição de tokens para tipos básicos (int, float, bool, string, etc.)
- Expressões regulares para operadores (+, -, &&, ||, ==, !=, ++, --)
- Tratamento de comentários e whitespace
- Implementação do lexer e do parser
- Testes unitários para tokens
- Preparação para P1

<br>

Acesso rápido a documentação dessa sprint:

- [planning](../sprints/sprint-2/sprint-planning.md)
- [review](../sprints/sprint-2/sprint-review.md)


### Sprint 3
_(01/05 - 14/05)_

**Objetivo:** Criar a Árvore Sintática Abstrata (AST) e Análise semântica básica

**Tarefas:**

- Implementar as ações semânticas no arquivo .y
- Criar tabela de símbolos
- Tratar erros sintáticos e semânticos básicos
- Testar a AST em pequenos programas

### Sprint 4
_(15/05 - 04/06)_

**Objetivo:** Implementar a interpretação da AST, Aprimorar a análise semântica e preparação para o P2

**Tarefas:**

- Criar a lógica de interpretação recursiva
- Consolidar estruturas de controle 
- Testes com códigos reais e extensos
- Preparação para P2

### Sprint 5
_(05/06 - 25/06)_

**Objetivo:** Interpretador ampliado e versão final pronta

**Tarefas:**

- Implementar otimizações simples 
- Estender a linguagem com novos recursos (se possível no tempo restante)
- Testes finais
- Entrega final no GitHub

### Sprint 6
_(26/06 - 09/07)_

**Objetivo:** Preparação para entrega final

**Tarefas::**

- Revisão da documentação
- Revisão final de código
- Corrigir eventuais falhas
- Preparação da entrevista


## Histórico de Versão

| Versão | Data       | Descrição                                       | Autor                                     | Revisor      |
|--------|------------|-------------------------------------------------|-------------------------------------------|--------------|
| `1.0`  | 11/04/2025 | Criação do cronograma                           | [Maria Alice](https://github.com/Maliz30) | [Luis Miranda](https://github.com/LuisMiranda10) |
| `1.1`  | 25/04/2025 | Reajuste e correções nas datas do no cronograma | [Maria Alice](https://github.com/Maliz30) | [Milena Baruc](https://github.com/MilenaBaruc)   |
