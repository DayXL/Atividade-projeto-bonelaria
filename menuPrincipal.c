#include <stdio.h>
#include <stdlib.h>

char verMenuPrincipal(void);
void verMenuSobre(void);

int main(void) {

    char esc = verMenuPrincipal();

    while (esc!='0'){

        if (esc=='1'){
            printf("Módulo em desenvolvimento!1");

        }

        else if (esc=='2'){
            printf("Módulo em desenvolvimento!2");

        }

        else if (esc=='3'){
            printf("Módulo em desenvolvimento!3");

        }

        else if (esc=='4'){
            printf("Módulo em desenvolvimento!4");

        }

        else if (esc=='5'){
            verMenuSobre();

        }

        else{
            printf("Opção inválida!");
        
        }

        printf("Tecle ENTER para continuar");
        getchar();

        esc = verMenuPrincipal();
    }
        

    printf("Programa finalizado!");

    return 0;
}

char verMenuPrincipal(void) {
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                   = = = = = SIG HAT = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Módulo em desenvolvimento                            ===\n");
    printf("===                 2. Módulo em desenvolvimento                            ===\n");
    printf("===                 3. Módulo em desenvolvimento                            ===\n");
    printf("===                 4. Módulo em desenvolvimento                            ===\n");
    printf("===                 5. Menu Sobre                                           ===\n");
    printf("===                 0. Sair                                                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    printf("Selecione sua opção:");
    char esc;
    scanf("%c" , &esc);
    getchar();

    return esc;

}


void verMenuSobre(void) {
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Informações do projeto = = = = =                 ===\n");
    printf("===                                                                         ===\n");
    printf("===  Projeto desenvolvido na disciplina DCT1106 - Programação, para         ===\n");
    printf("===  avaliação desse período.                                               ===\n");
    printf("===  Aluna: Dayanne Xavier Lucena.                                          ===\n");
    printf("===  Segundo período.                                                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");
}