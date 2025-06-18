# Compilador e flags
CC = gcc
FLEX = flex
BISON = bison

# Diretórios
SRC_DIR = .
LEXER_DIR = lexer
PARSER_DIR = parser
AST_DIR = ast
TEST_DIR = codigos_teste

# Arquivos
LEXER = $(LEXER_DIR)/lex.yy.c
PARSER_C = $(PARSER_DIR)/parser.tab.c
PARSER_H = $(PARSER_DIR)/parser.tab.h
AST = $(AST_DIR)/ast.c

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

# Compila tudo
$(EXEC): $(PARSER_C) $(LEXER) $(AST)
	$(CC) $(PARSER_C) $(LEXER) $(AST) -o $(EXEC)

# Limpa arquivos gerados
clean:
	rm -f $(LEXER) $(PARSER_C) $(PARSER_H) $(EXEC)

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