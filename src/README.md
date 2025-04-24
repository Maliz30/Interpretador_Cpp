# Como gerar o executável do léxico + sintático

## Pré requisitos

- Ter o flex, bison e gcc instalados

## Passo a passo

- rode o bison `bison -d nomeDoArquivoSintatico.y`
- rode o léxico `$ flex nomeDoArquivoLexico.l`
- gere o executável `gcc -o nomeDoExecutavel parser.tab.c lex.yy.c -lfl`
- rode `./nomeDoExecutavel`