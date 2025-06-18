# Como gerar o executável do léxico + sintático

## Pré requisitos

- Ter o flex, bison e gcc instalados

## Passo a passo

Dentro da pasta _/parser_:
- rode o bison: `bison -d parser.y`

Dentro da pasta _/lexer_:
- rode o léxico: `flex lexer.l`

Dentro da pasta _/src_:
- gere o executável: `gcc parser/parser.tab.c lexer/lex.yy.c ast/ast.c -o executavel`

- rode (inserindo dados manualmente): `./executavel`
- rode (inserindo um arquivo de teste): `./executavel < codigos_teste/nomeArquivoDeTeste.cpp`
