#include <stdio.h>
#include "moduloBone.h"

void moduloBone(void) {

    char esc = verMenuBone();

    while (esc!='0'){

        if (esc=='1'){
            printf("Cadastrar modelo\n");

        }

        else if (esc=='2'){
            printf("Editar modelo\n");

        }

        else if (esc=='3'){
            printf("Excluir modelo\n");

        }

        else if (esc=='4'){
            printf("Pesquisar modelo\n");

        }

        else{
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

    printf("Selecione sua opção:");
    char esc;
    scanf("%c" , &esc);
    getchar();

    return esc;

}