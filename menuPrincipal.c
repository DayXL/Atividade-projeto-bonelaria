#include <stdio.h>
#include <stdlib.h>
#include "funcoesAux.h"
#include "moduloBone.h"
#include "moduloFornecedor.h"
#include "moduloCliente.h"
#include "moduloEstoque.h"
#include "moduloRelatorio.h"
#include "moduloSobre.h"

char verMenuPrincipal(void);

int main(void) {

    char esc = verMenuPrincipal();

    while (esc!='0'){

        if (esc=='1'){
            moduloBone();

        }

        else if (esc=='2'){
            moduloFornecedor();

        }

        else if (esc=='3'){
            moduloCliente();

        }

        else if (esc=='4'){
            moduloEstoque();

        }

        else if (esc=='5'){
            moduloRelatorio();

        }

        else if (esc=='6'){
            verMenuSobre();

        }

        else{
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
    printf("===                 5. Relatórios                                           ===\n");
    printf("===                 6. Menu Sobre                                           ===\n");
    printf("===                 0. Sair                                                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}