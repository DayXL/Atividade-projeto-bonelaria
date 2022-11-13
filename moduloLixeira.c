#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"
#include "funcoesAux.h"
#include "moduloCliente.h"
#include "moduloFornecedor.h"
#include "moduloBone.h"
#include "moduloEstoque.h"
#include "moduloLixeira.h"

void moduloLixeira(void) {

    char esc = verMenuLix();

    while (esc!='0') {

        if (esc=='1') {
            lixBone();

        }

        else if (esc=='2') {
            lixFornecedor();

        }

        else if (esc=='3') {
            lixCliente();

        }

        else if (esc=='4') {
            lixEstoque();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuLix();
    }

}

char verMenuLix(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Lixeira = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Lixo Boné                                            ===\n");
    printf("===                 2. Lixo Fornecedor                                      ===\n");
    printf("===                 3. Lixo cliente                                         ===\n");
    printf("===                 4. Lixo estoque                                         ===\n");
    printf("===                 0. Voltar ao menu principal                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void lixBone(void) {
    system ( " clear||cls " );

    lerArqBcp(0);

}

void lixFornecedor(void) {
    system ( " clear||cls " );

    lerArqFnc(0);

}

void lixCliente(void) {
    system ( " clear||cls " );

    lerArqClt(0);

}

void lixEstoque(void) {
    system ( " clear||cls " );

    lerArqEst(0);

}
