# Cronograma Individualizado - Interpretador C++ para Python

## Sprint 1 - Definição do Projeto
_(07/04 - 13/04)_

| Membro                                                                                   | Tarefa                                    | Entregável                             |
|------------------------------------------------------------------------------------------|-------------------------------------------|----------------------------------------|
| Gabriel Saraiva, Luis Miranda, Maria Alice, Milena Baruc, Nicolas Bomfim, Pablo S. Costa | Instalar Dependências                     | -                                      |
| Gabriel Saraiva, Luis Miranda, Maria Alice, Milena Baruc, Nicolas Bomfim, Pablo S. Costa | Git clone do repositório                  | -                                      |
| Maria Alice                                                                              | Criar documentação inicial                | Criar e subir Mkdocs                   |
| Maria Alice                                                                              | Definir cronograma                        | Adicionar cronograma ao pages          |
| Luis Eduardo                                                                             | Criar Template de documentação de sprints | -                                      |
| Gabriel Saraiva, Luis Miranda, Milena Baruc, Nicolas Bomfim, Pablo S. Costa              | Revisar Cronograma                        | -                                      |
| Gabriel Saraiva, Luis Miranda, Maria Alice, Milena Baruc, Nicolas Bomfim, Pablo S. Costa | Definir subconjunto C++ a ser suportado   | Documentar o subset escolhido no pages |


**Principal pauta da reunião semanal (09/04):** Divisão de tarefas e preparação de ambiente

---

## Sprint 2 - Análise Léxica I
_(14/04 - 20/04)_

| Membro | Tarefa                                 | Entregável                 |
|--------|----------------------------------------|----------------------------|
| M1     | Tokens: tipos primitivos               | `src/lexer/types.l`        |
| M2     | Tokens: operadores                     | `src/lexer/operators.l`    |
| M3     | Tokens: delimitadores                  | `src/lexer/delimiters.l`   |
| M4     | Sistema de erro léxico                 | `src/error/lexer_errors.h` |
| M5     | Testes: criar casos de teste positivos | `tests/positive/`          |
| M6     | Testes: criar casos de teste negativos | `tests/negative/`          |

**Principal pauta da reunião semanal (16/04):** Mostrar código ao professor, combinar arquivos e realizar testes

---

## Sprint 3 - Análise Léxica II (Ponto de controle 1)
_(21/04 - 27/04)_

| Membro      | Tarefa                           | Entregável                  |
|-------------|----------------------------------|-----------------------------|
| M1          | Otimização: palavras reservadas  | `src/lexer/keywords.opt`    |
| M2          | Integração com arquivos          | `src/io/file_reader.cpp`    |
| M3          | Geração de logs                  | `src/logging/lexer_logs.md` |
| M4          | Script de build ou Makefile      | `scripts/build_lexer.sh`    |
| M5          | Relatório P1 (parte técnica*)    | `docs/`                     |
| M6          | Relatório P1 (parte gerencial**) | `docs/`                     |
| ?           | Preparação do slide              | Slide do P1 no pages        |
| Maria Alice | Preencher e entregar forms P1    | -                           |

***parte técnica:**

- Arquitetura do lexer
- Tabela completa de tokens
- Exemplos de saída
- Limitações conhecidas

****parte gerencial:**

- Cronograma executado vs planejado
- Riscos identificados
- Planejamento para as próximas sprints

**Principal pauta da reunião semanal (23/04):** Teste integrado do lexer completo e organização pré entrega

---

## Sprint 4 - Análise Sintática I
_(28/04 - 04/05)_

| Membro      | Tarefa                                          | Entregável             |
|-------------|-------------------------------------------------|------------------------|
| M1          | Gramática: declarações                          | `src/parser/decl.y`    |
| M2          | Gramática: expressões                           | `src/parser/expr.y`    |
| M3          | Gramática: controles                            | `src/parser/control.y` |
| M4          | Árvore Sintática Abstrata (AST): estrutura base | `src/ast/base_nodes.h` |
| M5          | Testes: parsing válido                          | `tests/parser/valid/`  |
| M6          | Diagrama da gramática                           | `docs/`                |
| Maria Alice | Revisão do Cronograma                           | -                      |

**Principal pauta da reunião semanal (30/04):** Resolver conflitos na gramática combinada

---

## Sprint 5  - Análise Sintática II
_(05/05 - 11/05)_

| Membro | Tarefa                  | Entregável                    |
|--------|-------------------------|-------------------------------|
| M1     | Gramática: funções      | `src/parser/functions.y`      |
| M2     | Gramática: classes      | `src/parser/classes.y`        |
| M3     | AST: nós específicos    | `src/ast/special_nodes/`      |
| M4     | Erros sintáticos        | `src/error/parser_errors.cpp` |
| M5     | Testes: casos complexos | `tests/parser/complex/`       |
| M6     | Visualizador de AST     | `scripts/visualize_ast.py`    |

**Principal pauta da reunião semanal (07/05):** Validação do visualizador de AST (M6)

---

## Sprint 6 - Análise Semântica
_(12/05 - 18/05)_

| Membro | Tarefa                 | Entregável                       |
|--------|------------------------|----------------------------------|
| M1     | Tabela de símbolos     | `src/symtable/symbol_table.h`    |
| M2     | Checagem de tipos      | `src/semantic/type_checker.cpp`  |
| M3     | Checagem de escopo     | `src/semantic/scope_checker.cpp` |
| M4     | Erros semânticos       | `src/error/semantic_errors.h`    |
| M5     | Testes semânticos      | `tests/semantic/`                |
| M6     | Documentação semântica | `docs/`                          |

**Principal pauta da reunião semanal (14/05):** Integração tabela de símbolos + checkers

---

## Sprint 7 - Geração de Código (Ponto de controle 2)
_(19/05 - 25/05)_

| Membro | Tarefa                  | Entregável                           |
|--------|-------------------------|--------------------------------------|
| M1     | Tradutor: expressões    | `src/codegen/expr_translator.py`     |
| M2     | Tradutor: controles     | `src/codegen/control_translator.py`  |
| M3     | Tradutor: funções       | `src/codegen/function_translator.py` |
| M4     | Testes de tradução      | `tests/codegen/basic/`               |
| M5     | Relatório P2 (técnico)  | `docs/`                              |
| M6     | Relatório P2 (métricas) | `docs/`                              |
| ?      | Preparação do slide     | Slide do P2 no pages                 |

**Principal pauta da reunião semanal (21/05):** Validar o fluxo completo de tradução com os componentes integrados

---

## Sprint 8 - Otimização
_(26/05 - 01/06)_

| Membro      | Tarefa                        | Entregável                   |
|-------------|-------------------------------|------------------------------|
| Maria Alice | Preencher e entregar forms P2 | -                            |
| M1          | Otimização: constantes        | `src/optimize/const_fold.py` |
| M2          | Otimização: dead code         | `src/optimize/dead_code.py`  |
| M3          | Testes de regressão           | `tests/regression/`          |
| M4          | Perfilamento                  | `scripts/profile.py`         |
| M5          | Docs otimização               | `docs/`       |
| Maria Alice | Revisão do Cronograma         | -                            |


**Principal pauta da reunião semanal (28/05):** Validação das Otimizações e Preparação para a Entrega P2

---

## Sprint 9 - Tratamento de Erros
_(02/06 - 08/06)_

| Membro | Tarefa                  | Entregável                       |
|--------|-------------------------|----------------------------------|
| M1     | Sistema de mensagens    | `src/error/user_messages.md`     |
| M2     | Recuperação de erros    | `src/error/recovery.py`          |
| M3     | Logging detalhado       | `src/logging/detailed_logs/`     |
| M4     | Testes de falha         | `tests/failure/`                 |
| M5     | Ajustes na documentação | `docs/`                          |
| M6     | CI: validação           | `.github/workflows/validate.yml` |

**Principal pauta da reunião semanal (04/06):** Teste de cenarios de erro complexos

---

## Sprint 10 - Testes Integrados
_(09/06 - 15/06)_

| Membro | Tarefa                    | Entregável            |
|--------|---------------------------|-----------------------|
| M1     | Testes: projetos reais    | `tests/real_world/`   |
| M2     | Testes: projetos reais    | `tests/real_world/`   |
| M3     | Validação: cppreference   | `tests/cppreference/` |
| M4     | Validação: cppreference   | `tests/cppreference/` |
| M5     | Relatório de cobertura    | `docs/`               |
| M6     | Documentação: Como rodar? | `docs/`               |

**Principal pauta da reunião semanal (11/06):** Validação com o professor

---

## Sprint 11 - Ajustes Finais
_(16/06 - 22/06)_

| Membro | Tarefa                                     | Entregável                             |
|--------|--------------------------------------------|----------------------------------------|
| M1     | Revisão dos testes                         | -                                      |
| M2     | Revisão de código                          | -                                      |
| M3     | Revisão de documentação                    | -                                      |
| M4     | Revisão de documentação                    | -                                      |
| M5     | Preparação do slide                        | Slide finalizado e adicionado ao pages |
| M6     | Gravação e edição do vídeo de apresentação | Vídeo no pages                         |

**Principal pauta da reunião semanal (18/06):** Organização para a apresentação final


## Histórico de Versão

| Versão | Data | Descrição | Autor | Revisor |
|--------|------|-----------|-------|---------|
| `1.0`  |11/04/2025| Criação do cronograma detalhado | [Maria Alice](https://github.com/Maliz30) |[Luis Miranda](https://github.com/LuisMiranda10)  |