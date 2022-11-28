#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"
#include "funcoesAux.h"
#include "moduloCliente.h"
#include "moduloFornecedor.h"
#include "moduloBone.h"
#include "moduloEstoque.h"
#include "moduloPedido.h"

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
            controleRelClt();

        }

        else if (esc=='4') {
            relatorioEstoque();

        }

        else if (esc=='5') {
            relatorioPedido();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuRelatorio();
    }

}

void controleRelClt(void) {

    char esc = verMenReltClt();

    while (esc!='0') {

        if (esc=='1') {
            lerArqClt(1);

        }

        else if (esc=='2') {
            printf("Ordem");

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenReltClt();
    }

}

char verMenuRelatorio(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Relatórios = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Relatório Boné                                          ===\n");
    printf("===              2. Relatório Fornecedor                                    ===\n");
    printf("===              3. Relatório cliente                                       ===\n");
    printf("===              4. Relatório estoque                                       ===\n");
    printf("===              5. Relatório pedidos                                       ===\n");
    printf("===              0. Voltar ao menu principal                                ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void relatorioBone(void) {
    system ( " clear||cls " );

    lerArqBcp(1);

}

void relatorioFornecedor(void) {
    system ( " clear||cls " );

    lerArqFnc(1);

}

char verMenReltClt(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Relatórios Clientes = = = = =                    ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Todos os clientes ativos                                ===\n");
    printf("===              2. Clientes por ordem alfabética                           ===\n");
    printf("===              0. Voltar ao menu relatórios                               ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void relatorioEstoque(void) {
    system ( " clear||cls " );

    lerArqEst(1);

}

void relatorioPedido(void) {
    system ( " clear||cls " );

    lerArqPedClt();

}
