#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloCliente.h"
#include "funcoesAux.h"

void moduloCliente(void) {

    char esc = verMenuCliente();

    while (esc!='0') {

        if (esc=='1') {
            cadastrarCliente();

        }

        else if (esc=='2') {
            editarCliente();

        }

        else if (esc=='3') {
            excluirCliente();

        }

        else if (esc=='4') {
            pesquisarCliente();

        }

        else if (esc=='5') {
            pedidoCliente();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuCliente();
    }

}

char verMenuCliente(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Cliente = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar cliente                                    ===\n");
    printf("===                 2. Editar cliente                                       ===\n");
    printf("===                 3. Excluir cliente                                      ===\n");
    printf("===                 4. Pesquisar cliente                                    ===\n");
    printf("===                 5. Fechar pedido para cliente                           ===\n");
    printf("===                 0. Voltar ao menu principal                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void cadastrarCliente(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Cadastrar cliente = = = = =                     ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    
    validarNomeCliente();

    validarCPF();

    validarNumeroCelular();

    validarEmail();

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void validarNomeCliente(void) {
    int a = 0;
    int tam;
    char nomeCliente[100];

    while (a == 0) {

        printf("Nome do cliente: ");
        fgets(nomeCliente, 100, stdin);

        tam = strlen(nomeCliente);
        nomeCliente[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarPalavra(nomeCliente));

    }

}

void validarCPF(void) {
    int a = 0;
    int tam;
    char cpf[13];

    while (a == 0) {
        int b = 0;

        printf("CPF(somente números): ");
        fgets(cpf, 13, stdin);

        tam = strlen(cpf);
        cpf[tam - 1] = '\0';

        b = ((tam == 1) || (tam < 12)) ? 0 : (validarNumInteiro(cpf));

        if (b == 1) {

            
            if (verificarCpf(cpf)) {

                printf(" ");
                printf("CPF válido!\n");
                a = 1;

            }

            else {

                printf(" ");
                printf("CPF inválido!\n");
                a = 0;

            }

            /*if (verificarCpf(cpf[0] - '0', cpf[1] - '0', cpf[2] - '0', cpf[3] - '0',
                cpf[4] - '0', cpf[5] - '0', cpf[6] - '0', cpf[7] - '0', cpf[8] - '0',
                cpf[9] - '0', cpf[10] - '0')) {

                printf(" ");
                printf("CPF válido!\n");
                a = 1;

            }

            else {
                printf(" ");
                printf("CPF inválido!\n");
                a = 0;

            } */

        }

        else {
            printf("b");
            a = 0;

        } 

    }

}

void validarNumeroCelular(void) {
    int a = 0;
    int tam;
    char numero[13];

    while (a == 0) {

        printf("Número de celular(somente números): ");
        fgets(numero, 13, stdin);

        tam = strlen(numero);
        numero[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarNumInteiro(numero));

    }

}

void validarEmail(void) {
    int a = 0;
    int tam;
    char email[100];

    while (a == 0) {

        printf("Email: ");
        fgets(email, 100, stdin);

        tam = strlen(email);
        email[tam - 1] = '\0';

        a = 1;

        //a = (tam == 1) ? 0 : (validarPalavra(email));

    }

}

void editarCliente(void) {

    char cpf[13];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Editar cliente = = = = =                         ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CPF do cliente: ");
    fgets(cpf, 13, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void excluirCliente(void) {

    char cpf[13];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir cliente = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CPF do cliente: ");
    fgets(cpf, 13, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void pesquisarCliente(void) {

    char cpf[13];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Pesquisar cliente = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CPF do cliente: ");
    fgets(cpf, 13, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void pedidoCliente(void) {

    char nomeCliente[100];
    char cpf[13];
    char nomeModelo[11];
    char quantidade[10];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Fechar pedido = = = = =                         ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");


    printf("Nome do cliente: ");
    fgets(nomeCliente, 100, stdin);

    printf("CPF(somente números): ");
    fgets(cpf, 13, stdin);

    printf("Nome do modelo: ");
    fgets(nomeModelo, 11, stdin);

    printf("Quantidade: ");
    fgets(quantidade, 11, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}