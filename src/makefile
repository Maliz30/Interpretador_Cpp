# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
FLEX = flex
BISON = bison

# Diretórios
SRC_DIR = .
LEXER_DIR = lexer
PARSER_DIR = parser
AST_DIR = ast
SEMANTICA_DIR = analise_semantica
TABELA_DIR = tabela_simbolos
TEST_DIR = codigos_teste

# Arquivos
LEXER = $(LEXER_DIR)/lex.yy.c
PARSER_C = $(PARSER_DIR)/parser.tab.c
PARSER_H = $(PARSER_DIR)/parser.tab.h
AST = $(AST_DIR)/ast.c
SEMANTICA = $(SEMANTICA_DIR)/semantica.c
TABELA = $(TABELA_DIR)/tabela.c

# Executável
EXEC = executavel

# Regra principal
all: $(EXEC)

# Gera parser
$(PARSER_C) $(PARSER_H): $(PARSER_DIR)/parser.y
	$(BISON) -d -o $(PARSER_C) $(PARSER_DIR)/parser.y

# Gera lexer
$(LEXER): $(LEXER_DIR)/lexer.l
	$(FLEX) -o $(LEXER) $(LEXER_DIR)/lexer.l

# Compila o interpretador com análise semântica
$(EXEC): $(PARSER_C) $(LEXER) $(AST) $(TABELA) $(SEMANTICA)
	$(CC) $(CFLAGS) $(PARSER_C) $(LEXER) $(AST) $(TABELA) $(SEMANTICA) -o $(EXEC)

# Limpa arquivos gerados
clean:
	rm -f $(LEXER) $(PARSER_C) $(PARSER_H) $(EXEC) $(TESTE_SEMANTICA)
	rm -f *.o

# Limpa tudo e recompila
rebuild: clean all

# Roda o executável manualmente
run:
	./$(EXEC)

# Testa todos os arquivos de teste
test-all: test-simple test-io test-expressao test-math test-conditional test-loop test-hello test-entrada-saida test-semantica

# Testes individuais
test-simple:
	@echo "=== Testando simple.cpp ==="
	./$(EXEC) $(TEST_DIR)/simple.cpp

test-io:
	@echo "=== Testando io_minimal.cpp ==="
	echo -e "5\n8" | ./$(EXEC) $(TEST_DIR)/io_minimal.cpp

test-expressao:
	@echo "=== Testando teste_expressao.cpp ==="
	./$(EXEC) $(TEST_DIR)/teste_expressao.cpp

test-math:
	@echo "=== Testando math.cpp ==="
	./$(EXEC) $(TEST_DIR)/math.cpp

test-semantica:
	@echo "=== Testando semantica.cpp ==="
	./$(EXEC) $(TEST_DIR)/erro-semantico.cpp

test-conditional:
	@echo "=== Testando conditional.cpp ==="
	./$(EXEC) $(TEST_DIR)/conditional.cpp

test-loop:
	@echo "=== Testando loop.cpp ==="
	./$(EXEC) $(TEST_DIR)/loop.cpp

test-hello:
	@echo "=== Testando hello.cpp ==="
	./$(EXEC) $(TEST_DIR)/hello.cpp

test-entrada-saida:
	@echo "=== Testando entrada_saida.cpp ==="
	./$(EXEC) $(TEST_DIR)/entrada_saida.cpp

# Teste interativo
test-interactive:
	@echo "=== Teste Interativo ==="
	@echo "Digite código C++ (Ctrl+D para finalizar):"
	./$(EXEC)

# Teste com entrada automática
test-auto:
	@echo "=== Teste Automático ==="
	echo "int a = 10; int b = 5; int c = a + b; cout << c;" | ./$(EXEC)


# Ajuda
help:
	@echo "Makefile do Interpretador C++"
	@echo ""
	@echo "Targets disponíveis:"
	@echo "  all          - Compila o interpretador"
	@echo "  clean        - Remove arquivos gerados"
	@echo "  rebuild      - Limpa e recompila"
	@echo "  run          - Executa o interpretador"
	@echo "  test-all     - Testa todos os arquivos de teste"
	@echo "  test-semantica - Roda o teste de análise semântica"
	@echo "  test-simple  - Testa simple.cpp"
	@echo "  test-io      - Testa entrada/saída"
	@echo "  test-expressao - Testa expressões"
	@echo "  test-interactive - Modo interativo"
	@echo "  test-auto    - Teste automático"
	@echo "  help         - Mostra esta ajuda"

# Regra padrão
.PHONY: all clean rebuild run test-all test-simple test-io test-expressao test-math test-conditional test-loop test-hello test-entrada-saida test-interactive test-auto test-semantica help