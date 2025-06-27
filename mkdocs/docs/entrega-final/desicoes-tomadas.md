# Decisões Técnicas

### 1. Linguagem e Ferramentas

- **Flex e Bison** para análise léxica e sintática.
- **C (GCC)** para compilação e execução.
- **Makefile** para automação de build e testes.

### 2. Subconjunto de C++ Suportado

Foco nas funcionalidades essenciais:

- Tipos básicos (int, float, char).
- Operações matemáticas e de controle (`if`, `else`, `while`, `for`).
- Variáveis e escopos básicos.
- Entrada e saída de dados.
- Verificação de erro semânticos no código.

### 3. Estrutura Modular

Separação clara entre:

- Léxico
- Parser
- Árvore de sintaxe
- Análise semântica
- Tabela de símbolos

### 4. Estratégia de Testes

Utilização de casos básicos para verificar:

- Operações aritméticas
- Controle de fluxo
- Declarações e escopos básicos
- Entrada e saída de dados
- Verificação de erro semânticos no código

### 5. Limitações Definidas

Exclusão de elementos complexos do C++ para focar no entendimento dos conceitos básicos de compilação.


## Histórico de Versões

| Versão |    Data    | Descrição                       | Autor(es)                                 | Revisor(es)                                         |
|--------|:----------:|---------------------------------|-------------------------------------------|-----------------------------------------------------|
| 1.0    | 26/06/2025 | Edição de como rodar | [Milena Baruc](https://github.com/MilenaBaruc) | [Maria Alice](https://github.com/Maliz30) e [Luis Miranda](https://github.com/LuisMiranda10) |
