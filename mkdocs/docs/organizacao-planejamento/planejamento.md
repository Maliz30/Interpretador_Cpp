
# Cronograma do Projeto

Com auxílio da LLM [Deepseek](https://chat.deepseek.com/), foi gerado um cronograma para ser executado ao longo do desenvolvimento do interpretador. O cronograma foi ajustado para se adequar as necessidades da equipe e as datas de entrega da disciplina.

Uma versão detalhada contendo a divisão de tarefas entre os membros por sprint pode ser encontrada [aqui](./cronograma-interno.md).


## Visão Geral

| Sprint | Período       | Objetivo Principal                   | Entregáveis                                  |
|--------|---------------|--------------------------------------|----------------------------------------------|
| 1      | 07/04 - 13/04 | Definição do projeto e ambiente      | Documentação inicial, escolha de ferramentas |
| 2      | 14/04 - 20/04 | Desenvolvimento do analisador léxico | Especificação léxica completa                |
| 3      | 21/04 - 27/04 | Implementação do léxico              | Analisador léxico funcional (P1)             |
| 4      | 28/04 - 04/05 | Análise sintática inicial            | Gramática básica definida                    |
| 5      | 05/05 - 11/05 | Implementação do parser              | Parser funcional para subconjunto C++        |
| 6      | 12/05 - 18/05 | Análise semântica inicial            | Tabela de símbolos básica                    |
| 7      | 19/05 - 25/05 | Geração de código intermediário      | Tradutor para Python simples (P2)            |
| 8      | 26/05 - 01/06 | Otimização e testes                  | Melhorias no código gerado                   |
| 9      | 02/05 - 08/06 | Tratamento de erros                  | Sistema de mensagens de erro                 |
| 10     | 09/05 - 15/06 | Testes integrados                    | Casos de teste completos                     |
| 11     | 16/05 - 22/06 | Ajustes Finais                       | Documentação final, vídeo de apresentação    |

## Detalhamento por Sprint

### Sprint 1  - Definição do Projeto
_(07/04 - 13/04)_

**Objetivo:** Estabelecer fundamentos do projeto

**Tarefas:**

- Criação do repositório GitHub
- Documentação do projeto (Mkdocs, templates)
- Configuração do ambiente de desenvolvimento
- Planejamento das sprints
- Definição do subconjunto C++ a ser suportado


### Sprint 2 - Análise Léxica
_(14/04 - 20/04)_

**Objetivo:** Especificar e implementar tokens básicos

**Tarefas:**

- Definição de tokens para tipos básicos (int, float, bool, string, etc.)
- Expressões regulares para operadores (+,-,&&,||,==,!=,++,--)
- Tratamento de comentários e whitespace
- Implementação do scanner/lexer
- Testes unitários para tokens
- Atualização da documentação


### Sprint 3 - Finalização Léxica (Ponto de controle 1)
_(21/04 - 27/04)_

**Objetivo:** Lexer completo e preparação para P1

**Tarefas:**

- Tratamento de erros léxicos
- Otimização do lexer
- Integração com sistema de arquivos
- Testes com exemplos reais
- Preparação da apresentação P1 (Slide)
- Documentação final do léxico


### Sprint 4 - Análise Sintática Inicial
_(28/04 - 04/05)_

**Objetivo:** Gramática básica para declarações

**Tarefas:**

- Gramática para declaração de variáveis
- Gramática para estruturas de controle (if, for)
- Implementação do parser básico
- Geração de Árvore Sintática Abstrata (AST) simples
- Testes com exemplos simples
- Revisão do Cronograma
- Atualização da documentação

### Sprint 5 - Parser Completo
_(05/05 - 11/05)_

**Objetivo:** Parser para subconjunto C++ completo

**Tarefas:**

- Gramática para funções
- Gramática para classes (simples)
- Tratamento de erros sintáticos
- Otimização do parser
- Testes integrados lexer+parser
- Documentação da gramática

### Sprint 6  - Análise Semântica
_(12/05 - 18/05)_

**Objetivo:** Verificação de tipos e escopo

**Tarefas:**

- Tabela de símbolos básica
- Verificação de tipos simples
- Verificação de escopo
- Mensagens de erro semânticas
- Testes semânticos
- Documentação semântica

### Sprint 7 - Geração de Código (Ponto de controle 2)
_(19/05 - 25/05)_

**Objetivo:** Tradutor C++ → Python funcional

**Tarefas:**

- Tradução de expressões
- Tradução de estruturas de controle
- Tradução de funções
- Testes de tradução
- Preparação da apresentação P2 (Slide)
- Documentação do tradutor

### Sprint 8 - Otimização
_(26/05 - 01/06)_

**Objetivo:** Melhorar qualidade do código gerado

**Tarefas::**

- Otimização de expressões
- Testes de desempenho
- Correção de bugs
- Revisão do Cronograma
- Atualização da documentação

### Sprint 9 - Tratamento de Erros
_(02/06 - 08/06)_

**Objetivo:** Sistema robusto de mensagens

**Tarefas::**

- Mensagens de erro claras
- Recuperação de erros
- Logging de processos
- Testes de falha
- Documentação de erros

### Sprint 10 - Testes Integrados
_(09/06 - 15/06)_

**Objetivo:** Validação completa

**Tarefas::**

- Casos de teste complexos
- Testes de regressão
- Validação com exemplos reais
- Relatório de testes
- Polimento da documentação

### Sprint 11 - Ajustes Finais
_(16/06 - 22/06)_

**Objetivo:** Preparação para entrega final

**Tarefas::**

- Testes finais
- Revisão final de código
- Revisão da documentação
- Preparação da entrevista
- Slides da apresentação
- Vídeo de apresentação

- Entrega final no GitHub

## Histórico de Versão

| Versão | Data | Descrição | Autor | Revisor |
|--------|------|-----------|-------|---------|
| `1.0`  |11/04/2025| Criação do cronograma | [Maria Alice](https://github.com/Maliz30) |[Luis Miranda](https://github.com/LuisMiranda10)  |
