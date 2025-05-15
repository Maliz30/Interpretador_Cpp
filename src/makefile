# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Diretórios
AST_DIR = ast
PARSER_DIR = parser
LEXER_DIR = lexer

# Arquivos gerados
FLEX_SRC = $(LEXER_DIR)/lex.yy.c
BISON_SRC = $(PARSER_DIR)/parser.tab.c
BISON_HDR = $(PARSER_DIR)/parser.tab.h

# Fontes
C_SOURCES = $(AST_DIR)/ast.c
C_OBJECTS = $(C_SOURCES:.c=.o)

# Executável
EXEC = compilador

# Includes
INCLUDES = -I. -I$(AST_DIR) -I$(PARSER_DIR) -I$(LEXER_DIR)

# Bibliotecas
LIBS = -lfl

# Regra padrão
all: $(EXEC)

# Regra principal
$(EXEC): $(BISON_SRC) $(FLEX_SRC) $(C_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(BISON_SRC) $(FLEX_SRC) $(C_OBJECTS) $(LIBS)

# Regras de Bison com inclusão automática do ast.h
$(BISON_SRC) $(BISON_HDR): $(PARSER_DIR)/parser.y
	bison --defines=$(BISON_HDR) --output=$(BISON_SRC) $<
	@echo "#include \"../ast/ast.h\"" >> $(BISON_HDR)

$(FLEX_SRC): $(LEXER_DIR)/lexer.l $(BISON_HDR)
	flex --outfile=$@ $<

# Compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpeza
clean:
	rm -f $(LEXER_DIR)/lex.yy.c
	rm -f $(PARSER_DIR)/parser.tab.[ch]
	rm -f $(C_OBJECTS)
	rm -f $(EXEC)

.PHONY: all clean