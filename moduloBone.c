#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloBone.h"
#include "funcoesAux.h"

void moduloBone(void) {

    char esc = verMenuBone();

    while (esc!='0') {

        if (esc=='1') {
            cadastrarModelo();

        }

        else if (esc=='2') {
            editarModelo();

        }

        else if (esc=='3') {
            excluirModelo();

        }

        else if (esc=='4') {
            pesquisarModelo();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuBone();
    }

}

char verMenuBone(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 = = = = = Menu Boné = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar modelo                                     ===\n");
    printf("===                 2. Editar modelo                                        ===\n");
    printf("===                 3. Excluir modelo                                       ===\n");
    printf("===                 4. Pesquisar modelo                                     ===\n");
    printf("===                 0. Voltar ao menu principal                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void cadastrarModelo(void) {

    char uniPorMetro[3];
    char uniPorTubo[3];
    
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Cadastrar modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    validarNomeModelo();
    
    printf("Unidades por metro de tecido: ");
    fgets(uniPorMetro, 3, stdin);

    printf("Unidades por tubo de linha: ");
    fgets(uniPorTubo, 3, stdin);

    printf("\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void validarNomeModelo(void) {
    int a = 0;
    int tam;
    char nomeModelo[11];

    while (a == 0) {

        printf("Nome do modelo: ");
        fgets(nomeModelo, 11, stdin);

        tam = strlen(nomeModelo);
        nomeModelo[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarPalavra(nomeModelo));

    }

}

void editarModelo(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Editar modelo = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===                   Informe o modelo:                                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void excluirModelo(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir modelo = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===                   Informe o modelo:                                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void pesquisarModelo(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Pesquisar modelo = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===                   Informe o modelo:                                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

