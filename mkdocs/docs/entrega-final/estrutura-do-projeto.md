## Estrutura do Projeto

A estrutura atual do interpretador foi definida para organizar e separar responsabilidades, facilitando manutenção e entendimento do código.

```bash
Interpretador_Cpp/
├── mkdocs/                # Arquivos para documentação com MkDocs
├── src/
│   ├── analise_semantica/ # Implementação da análise semântica
│   ├── ast/                # Implementação e estrutura da Árvore de Sintaxe Abstrata
│   ├── codigos_teste/      # Códigos de exemplo para testar o interpretador
│   ├── lexer/              # Analisador léxico (Flex): regras e implementação
│   ├── parser/             # Analisador sintático (Bison): gramática e implementação
│   ├── tabela_simbolos/    # Estruturas e lógica para a tabela de símbolos
│   ├── makefile            # Makefile para compilação e execução
│   └── README.md           # Descrição do conteúdo e instruções específicas para `src`
│   └── teste.txt           # Arquivo de teste simples para verificar entradas
├── .gitignore              # Arquivos e pastas a serem ignorados pelo git
├── LICENSE                # Licença do projeto
└── README.md              # Documento principal do repositório, com instruções e detalhes gerais
```

## Histórico de Versões

| Versão |    Data    | Descrição                       | Autor(es)                                 | Revisor(es)                                         |
|--------|:----------:|---------------------------------|-------------------------------------------|-----------------------------------------------------|
| 1.0    | 26/06/2025 | Criação da página | [Milena Baruc](https://github.com/MilenaBaruc) | [Maria Alice](https://github.com/Maliz30) |