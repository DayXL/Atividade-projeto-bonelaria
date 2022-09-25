#include <stdio.h>
#include <stdlib.h>
#include "moduloEstoque.h"
#include "funcoesAux.h"

void moduloEstoque(void) {

    char esc = verMenuEstoque();

    while (esc!='0') {

        if (esc=='1') {
            materiaisEstoque();

        }

        else if (esc=='2') {
            printf("Pesquisar materias em estoque\n");

        }

        else if (esc=='3') {
            printf("Comprar materias para estoque\n");

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuEstoque();
    }

}

char verMenuEstoque(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Menu Estoque = = = = =                          ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Ver materiais em estoque                             ===\n");
    printf("===                 2. Pesquisar materias em estoque                        ===\n");
    printf("===                 3. Comprar materiais para estoque                       ===\n");
    printf("===                 0. Voltar ao menu principal                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void materiaisEstoque(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===        = = = = = Materiais em Estoque  = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===     Linha vermelha: 100 tubos                                           ===\n");
    printf("===     Bico de boné: 367                                                   ===\n");
    printf("===     Tinha branca: 10 baldes                                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}
