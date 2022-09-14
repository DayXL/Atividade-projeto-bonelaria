#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"

void passarEnter(void) {

    printf("Tecle ENTER para continuar");
    getchar();

}

char auxEscolha(void) {

    printf("Selecione sua opção:");
    char esc;
    scanf("%c" , &esc);
    getchar();

    return esc;

}

int validarPalavra(char *palavra) {
    
    int i = 0;

    while (palavra[i] != '\0') {
        //printf("%c\t", palavra[i]);
        //printf("%d\n", palavra[i]);
        

        if (((palavra[i] >= 'a') && (palavra[i] <= 'z')) || (palavra[i] == ' ')) {
            i = i + 1;
            //printf("a");

        }

        else if ((palavra[i] >= 'A') && (palavra[i] <= 'Z')) {
            i = i + 1;
            //printf("b");

        }

        else {
            //printf("\nfinal should be => %c", palavra[i]);
            return 0;

        }

    }

    //printf("s");
    return 1;

}