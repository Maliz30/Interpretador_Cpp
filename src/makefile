# Compilador e flags
CC = gcc
FLEX = flex
BISON = bison

# Diretórios
SRC_DIR = .
LEXER_DIR = lexer
PARSER_DIR = parser
AST_DIR = ast
SEMANTICA_DIR = analise_semantica
TEST_DIR = codigos_teste

# Arquivos
LEXER = $(LEXER_DIR)/lex.yy.c
PARSER_C = $(PARSER_DIR)/parser.tab.c
PARSER_H = $(PARSER_DIR)/parser.tab.h
AST = $(AST_DIR)/ast.c
SEMANTICA = $(SEMANTICA_DIR)/semantica.c

# Executáveis
EXEC = executavel
TESTE_SEMANTICA = teste_semantica

# Regra principal
all: $(EXEC)

# Gera parser
$(PARSER_C) $(PARSER_H): $(PARSER_DIR)/parser.y
	$(BISON) -d -o $(PARSER_C) $(PARSER_DIR)/parser.y

# Gera lexer
$(LEXER): $(LEXER_DIR)/lexer.l
	$(FLEX) -o $(LEXER) $(LEXER_DIR)/lexer.l

# Compila o interpretador com análise semântica
$(EXEC): $(PARSER_C) $(LEXER) $(AST) $(SEMANTICA)
	$(CC) $(PARSER_C) $(LEXER) $(AST) $(SEMANTICA) -o $(EXEC)

# Limpa arquivos gerados
clean:
	rm -f $(LEXER) $(PARSER_C) $(PARSER_H) $(EXEC) $(TESTE_SEMANTICA)

# Roda o executável manualmente
run:
	./$(EXEC)

# Roda com um arquivo de teste
run-hello:
	./$(EXEC) < $(TEST_DIR)/hello.cpp

run-conditional:
	./$(EXEC) < $(TEST_DIR)/conditional.cpp

run-loop:
	./$(EXEC) < $(TEST_DIR)/loop.cpp

run-math:
	./$(EXEC) < $(TEST_DIR)/math.cpp

# Regra para mostrar ajuda
help:
	@echo "Comandos disponíveis:"
	@echo "  make all              - Compila tudo"
	@echo "  make clean            - Limpa arquivos gerados"
	@echo "  make run              - Roda o interpretador"
	@echo "  make teste-semantica  - Roda o teste de análise semântica"
	@echo "  make run-hello        - Roda com hello.cpp"
	@echo "  make run-conditional  - Roda com conditional.cpp"
	@echo "  make run-loop         - Roda com loop.cpp"
	@echo "  make run-math         - Roda com math.cpp"