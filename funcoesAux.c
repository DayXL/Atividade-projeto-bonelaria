#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int verificarCpf(char *cpf) {

    int soma = 0;
    int resto = 0;
    int tam;
    
    tam = strlen(cpf);
    cpf[tam - 1] = '\0';

    if ((validarNumInteiro(cpf)) && (tam == 12)) {
        for (int i = 0; i < 9; i++) {
            soma = soma + ((cpf[i] - '0' ) * (i + 1));

        }

        resto = soma % 11;

        resto = (resto == 10) ? 0 : resto;

        if (resto == (cpf[9] - '0' )) {
            soma = 0;

            for (int i = 0; i < 10; i++) {
                    soma = soma + ((cpf[i] - '0' ) * (i));

            }

            resto = soma % 11;

            resto = (resto == 10) ? 0 : resto;

            if (resto == (cpf[10] - '0' )) {
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

    else {
        return 0;

    }

}

int verificarCnpj(char *cnpj) {

    int parteUm[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int parteDois[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

    int soma = 0;
    int resto = 0;
    int tam;
    
    tam = strlen(cnpj);
    cnpj[tam - 1] = '\0';

    if ((validarNumInteiro(cnpj)) && (tam == 15)) {

        for (int i = 0; i < 12; i++) {
            soma = soma + ((cnpj[i] - '0' ) * (parteUm[i]));

        }

        resto = soma % 11;

        resto = (resto == 0 || resto == 1) ? 0 : 11 - resto;

        if (resto == (cnpj[12] - '0' )) {
            soma = 0;

            for (int i = 0; i < 13; i++) {
                soma = soma + ((cnpj[i] - '0' ) * (parteDois[i]));

            }

            resto = soma % 11;

            resto = (resto == 0 || resto == 1) ? 0 : 11 - resto;

            if (resto == (cnpj[13] - '0' )) {
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

    else {
        return 0;

    }

}

int sortear(void) {

    int num;

    num = rand()%10;

    return num;

}

void gerarCpf(void) {
    int cpf[11] = {};

    for (int i = 0; i < 9 ; i++ ) {
        int num = 0;

        num = sortear();

        cpf[i] = num;

    }

    escolheVerificadoCpf(cpf);

    for (int i = 0; i < 11 ; i++ ) {

        printf("%d" , cpf[i]);

    }

}

void escolheVerificadoCpf(int *cpf) {

    int soma = 0;
    int resto = 0;

    for (int i = 0; i < 9; i++) {
        soma = soma + (cpf[i] * (i + 1));

    }

    resto = soma % 11;

    resto = (resto == 10) ? 0 : resto;

    cpf[9] = resto;

    soma = 0;

    for (int i = 0; i < 10; i++) {
        soma = soma + (cpf[i] * (i));

    }

    resto = soma % 11;

    resto = (resto == 10) ? 0 : resto;

    cpf[10] = resto;

}

int verificarEmail(char *email, int tam) {
    int i = 0;
    int controleArroba = 0;
    int controle2 = 0;
    int controlePonto = 0;

    while (email[i] != '\0') {

        if (email[i] == '@') {

            controleArroba = i;

            i = i + 1;

            controle2 = controle2 + 1;

        }

        if ((i > controleArroba) && (email[i] == '.')) {

            controlePonto = i;

            if ((email[i + 1] == 'c') && (email[i + 2] == 'o') && (email[i + 3] == 'm') && (email[i + 4] == '\0')) {
                i = i + 1;

            }

            else {
                return 0;

            }

        }

        i = i + 1;

    }

    if ((controle2 == 0) || (controle2 > 1)) {
        return 0;
        
    }

    else if (controleArroba < 3) {
        return 0;

    }

    else if ((controlePonto - controleArroba) < 5 ) {
        return 0;

    }

    return 1;


}

void gerarCnpj(void) {
    
    int cnpj[14] = {};

    for (int i = 0; i < 12 ; i++ ) {
        int num = 0;

        num = sortear();

        cnpj[i] = num;

    }

    escolheVerificadoCNPJ(cnpj);

    for (int i = 0; i < 14 ; i++ ) {

        printf("%d" , cnpj[i]);

    }

}

void escolheVerificadoCNPJ(int *cnpj) {

    int parteUm[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int parteDois[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

    int soma = 0;
    int resto = 0;

    for (int i = 0; i < 12; i++) {
        soma = soma + ((cnpj[i]) * (parteUm[i]));

    }

    resto = soma % 11;

    resto = (resto == 0 || resto == 1) ? 0 : 11 - resto;

    cnpj[12] = resto;

    soma = 0;

    for (int i = 0; i < 13; i++) {
        soma = soma + ((cnpj[i]) * (parteDois[i]));

    }

    resto = soma % 11;

    resto = (resto == 0 || resto == 1) ? 0 : 11 - resto;

    cnpj[13] = resto;

}

char* pasMaisc(char *nome) {

    int i = 0;
    int tam = strlen(nome);
    char* nomeMaisc = (char*) malloc(tam * sizeof(char));

    strcpy(nomeMaisc, nome);

    while (nome[i] != '\0') { 
        if (((nome[i] >= 'a') && (nome[i] <= 'z'))) {
            nomeMaisc[i] = toupper(nome[i]);

        }

        else {
            nomeMaisc[i] = nome[i];

        }

        i = i + 1;

    }

    return nomeMaisc;
}

