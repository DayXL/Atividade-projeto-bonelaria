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

int validarNumInteiro(char *numero) {
    int i = 0;

    while (numero[i] != '\0') {
        if ((numero[i] >= '0') && (numero[i] <= '9')) {
            i = i + 1;

        }

        else {
            return 0;

        }

    }

    return 1;

}

int verificarCpf(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {

    int soma = 0;
    int resto = 0;

    printf("aqui");

    soma = a * 1 + b * 2 + c * 3 + d * 4 + e * 5 + f * 6 + g * 7 + h * 8 + i * 9; 

    resto = soma % 11;

    resto = (resto == 10) ? 0 : resto;

    if (resto == j) {
        soma = 0;

        soma = b * 1 + c * 2 + d * 3 + e * 4 + f * 5 + g * 6 + h * 7 + i * 8 + j * 9;

        resto = soma % 11;

        resto = (resto == 10) ? 0 : resto;

        if (resto == k) {
            return 1;

        }

        else {
            return 0;
        }

    }

    else {
        return 0;

    }

}