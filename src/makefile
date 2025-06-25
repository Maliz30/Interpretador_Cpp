# Compilador e flags
CC = gcc
FLEX = flex
BISON = bison

# Diretórios
SRC_DIR = .
LEXER_DIR = lexer
PARSER_DIR = parser
AST_DIR = ast
TABELA_DIR = tabela_simbolos
TEST_DIR = codigos_teste

# Arquivos
LEXER = $(LEXER_DIR)/lex.yy.c
PARSER_C = $(PARSER_DIR)/parser.tab.c
PARSER_H = $(PARSER_DIR)/parser.tab.h
AST = $(AST_DIR)/ast.c
TABELA = $(TABELA_DIR)/tabela.c

# Executável
EXEC = interpretador

# Regra principal
all: $(EXEC)

# Gera parser
$(PARSER_C) $(PARSER_H): $(PARSER_DIR)/parser.y
	$(BISON) -d -o $(PARSER_C) $(PARSER_DIR)/parser.y

# Gera lexer
$(LEXER): $(LEXER_DIR)/lexer.l
	$(FLEX) -o $(LEXER) $(LEXER_DIR)/lexer.l

# Compila tudo
$(EXEC): $(PARSER_C) $(LEXER) $(AST) $(TABELA)
	$(CC) $(PARSER_C) $(LEXER) $(AST) $(TABELA) -o $(EXEC)

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

run-entrada-saida:
	./$(EXEC) < $(TEST_DIR)/entrada_saida.cpp

run-teste_expressao:
	./$(EXEC) < $(TEST_DIR)/teste_expressao.cpp

# Teste simples
test-simple:
	echo "int a = 5; int b = 3; int c = a + b;" | ./$(EXEC)