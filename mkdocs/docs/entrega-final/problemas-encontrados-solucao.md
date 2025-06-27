# Problemas Encontrados e Soluções Adotadas

### 1. Conflitos de Redução ou Deslocamento no Parser

**Problema:** Ambiguidade em algumas regras gramaticais.  
**Solução:** Refatoração das regras e adição de precedência definida no arquivo `parser.y`.

---

### 2. Dificuldade em Integrar Léxico e Parser

**Problema:** Tokens não reconhecidos corretamente e conflitos entre Flex e Bison.  
**Solução:** Padronização dos nomes e ajuste nas expressões regulares para garantir alinhamento entre `lexer.l` e `parser.y`.

---

### 3. Limitações do Subconjunto de C++

**Problema:** Algumas operações não implementadas (ex.: structs, templates).  
**Solução:** Definição clara do escopo inicial e documentação para futura implementação.

---

### 4. Problemas de Ambiente

**Problema:** Variações de ambiente (Windows, Linux, Mac) para compilação e execução.  
**Solução:** Documentação clara para cada ambiente e manutenção de Makefile simples para tornar o build previsível.

---

### Resultado Final

Apesar dos desafios, o interpretador cumpre o escopo proposto e servirá para exclusão de elementos complexos do C++ para focar no entendimento dos conceitos básicos de compilação.

## Histórico de Versões

| Versão |    Data    | Descrição                       | Autor(es)                                 | Revisor(es)                                         |
|--------|:----------:|---------------------------------|-------------------------------------------|-----------------------------------------------------|
| 1.0    | 26/06/2025 | Criação da página               | [Milena Baruc](https://github.com/MilenaBaruc) | [Maria Alice](https://github.com/Maliz30)      |
