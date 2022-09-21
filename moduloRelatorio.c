#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"
#include "funcoesAux.h"

void moduloRelatorio(void) {

    char esc = verMenuRelatorio();

    while (esc!='0') {

        if (esc=='1') {
            relatorioBone();

        }

        else if (esc=='2') {
            printf("Relatório Fornecedor\n");

        }

        else if (esc=='3') {
            printf("Relatório cliente\n");

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuRelatorio();
    }

}

char verMenuRelatorio(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Relatórios = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Relatório Boné                                       ===\n");
    printf("===                 2. Relatório Fornecedor                                 ===\n");
    printf("===                 3. Relatório cliente                                    ===\n");
    printf("===                 0. Voltar ao menu principal                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void relatorioBone(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Relatório Boné  = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===     Boné de 6 partes:                                                   ===\n");
    printf("===      - 4 bonés a cada 1 metro de tecido                                 ===\n");
    printf("===      - 5 bonés a cada 1 tubo de linha                                   ===\n");
    printf("===                                                                         ===\n");
    printf("===     Boné aba reta:                                                      ===\n");
    printf("===      - 5 bonés a cada 1 metro de tecido                                 ===\n");
    printf("===      - 7 bonés a cada 1 tubo de linha                                   ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}