# Como gerar o executável do léxico + sintático

## Pré requisitos

- Ter o flex, bison e gcc instalados

## Passo a passo

Dentro da pasta _/src_:
- rode o bison: `bison -d -o parser/parser.tab.c parser/parser.y`
- rode o léxico: `flex -o lexer/lex.yy.c lexer/lexer.l`
- gere o executável: `gcc parser/parser.tab.c lexer/lex.yy.c ast/ast.c -o executavel`

- rode (inserindo dados manualmente): `./executavel`
- rode (inserindo um arquivo de teste): `./executavel < codigos_teste/nomeArquivoDeTeste.cpp`
