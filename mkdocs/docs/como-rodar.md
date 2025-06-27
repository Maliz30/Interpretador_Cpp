# Como gerar o executável do léxico + sintático

## Pré requisitos

- Ter o flex, bison e gcc instalados

## Passo a passo

Dentro da pasta _/parser_:

- rode o bison: `bison -d parser.y`

<br>

Dentro da pasta _/lexer_:


- rode o léxico: `$ flex lexer.l`

<br>

Dentro da pasta _/src_:

- gere o executável: `gcc -o executavel parser/parser.tab.c lexer/lex.yy.c -lfl`
- rode (inserindo dados manualmente): `./executavel`
- rode (inserindo um arquivo de teste): `./executavel < codigos_teste/nomeArquivoDeTeste.cpp`
- para rodar com makefile: 
```bash
make        # compila tudo
make run    # roda o programa compilado
make clean  # apaga os arquivos gerados
make run-hello       # roda com o teste hello.cpp
make run-conditional # roda com o teste conditional.cpp
# e assim vai...
```


## Histórico de Versões

| Versão |    Data    | Descrição                       | Autor(es)                                 | Revisor(es)                                         |
|--------|:----------:|---------------------------------|-------------------------------------------|-----------------------------------------------------|
| 1.0    | 28/04/2025 | Versão inicial | [Maria Alice](https://github.com/Maliz30) | [Milena Baruc](https://github.com/MilenaBaruc) |
| 2.0    | 26/06/2025 | Edição de como rodar | [Milena Baruc](https://github.com/MilenaBaruc) | [Luis Miranda](https://github.com/LuisMiranda10) |

</center>