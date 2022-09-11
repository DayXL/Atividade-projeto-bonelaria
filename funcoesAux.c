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

int validarLetras(char palavra[30]) {
    int i = 0;

    while (palavra[i] != '\0') {

        if (palavra[i] >= 'a' && palavra[i] <= 'z') {
            i = i + 1;

        }

        else if (palavra[i] >= 'A' && palavra[i] <= 'Z') {
            i = i + 1;

        }

        else if (i != '0' && palavra[i] == ' ') {
            i = i + 1;

        }

        else {
            printf("%d", palavra[i]);
            return 0;

        }
    }

    return 1;

}