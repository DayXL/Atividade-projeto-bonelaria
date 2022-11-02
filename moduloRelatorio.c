#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"
#include "funcoesAux.h"
#include "moduloCliente.h"
#include "moduloFornecedor.h"

void moduloRelatorio(void) {

    char esc = verMenuRelatorio();

    while (esc!='0') {

        if (esc=='1') {
            relatorioBone();

        }

        else if (esc=='2') {
            relatorioFornecedor();

        }

        else if (esc=='3') {
            relatorioCliente();

        }

        else if (esc=='4') {
            relatorioEstoque();

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
    printf("===                 4. Relatório estoque                                    ===\n");
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

    printf("Em desenvolvimento!");

}

void relatorioFornecedor(void) {
    system ( " clear||cls " );

    lerArqFnc();

}

void relatorioCliente(void) {
    system ( " clear||cls " );

    lerArqClt();

}

void relatorioEstoque(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===          = = = = = Relatório Estoque  = = = = =                         ===\n");
    printf("===                                                                         ===\n");
    printf("===     Linha vermelha: 100 tubos                                           ===\n");
    printf("===     Bico de boné: 367                                                   ===\n");
    printf("===     Tinha branca: 10 baldes                                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}
