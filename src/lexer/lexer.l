%{
#include <stdio.h>
#include <stdlib.h>
%}

/* Definições de padrões de token e ações */
%%



%%

/* Função auxiliar do Flex (quando termina o arquivo de entrada) */
int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    /* Se houver arquivo de entrada como parâmetro, redireciona o yyin */
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (f) {
            yyin = f;
        }
    }
    return yyparse();  /* Chama o parser gerado pelo Bison */
}