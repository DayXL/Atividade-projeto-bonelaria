#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesAux.h"           //Compile os .h -> gcc -c -Wall *.h
#include "moduloBone.h"          //Compile os .c -> gcc -c -Wall *.c
#include "moduloFornecedor.h"   //Junte os arquivos -> gcc -o Hat *.o
#include "moduloCliente.h"
#include "moduloEstoque.h"  //teste
#include "moduloPedido.h"
#include "moduloRelatorio.h"
#include "moduloSobre.h"
#include "moduloLixeira.h"

char verMenuPrincipal(void);

int main(void) {

    srand(time(NULL));

    char esc = verMenuPrincipal();

    while (esc!='0') {

        if (esc=='1') {
            moduloBone();

        }

        else if (esc=='2') {
            moduloFornecedor();

        }

        else if (esc=='3') {
            moduloCliente();

        }

        else if (esc=='4') {
            moduloEstoque();

        }

        else if (esc=='5') {
            moduloPedido();

        }

        else if (esc=='6') {
            moduloRelatorio();

        }

        else if (esc=='7') {
            verMenuSobre();

        }

        else if (esc=='8') {
            moduloLixeira();

        }

        else {
            printf("Opção inválida!");
        
        }

        passarEnter();

        esc = verMenuPrincipal();
    }
        

    printf("Programa finalizado!");

    return 0;
}

char verMenuPrincipal(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                   = = = = = SIG HAT = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Módulo Boné                                          ===\n");
    printf("===                 2. Módulo Fornecedor                                    ===\n");
    printf("===                 3. Módulo Cliente                                       ===\n");
    printf("===                 4. Módulo Estoque                                       ===\n");
    printf("===                 5. Módulo pedido                                        ===\n");
    printf("===                 6. Relatórios                                           ===\n");
    printf("===                 7. Menu Sobre                                           ===\n");
    printf("===                 8. Lixeira                                              ===\n");
    printf("===                 0. Sair                                                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}