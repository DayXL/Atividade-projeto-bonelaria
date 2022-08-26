#include <stdio.h>

char verMenuPrincipal();
void verMenuSobre(void);

int main(void) {
    char esc = verMenuPrincipal();

    switch (esc!=0)
        {
            case 1:
                printf("Módulo em desenvolvimento!");
                break;

            case 2:
                printf("Módulo em desenvolvimento!");
                break;
            
            case 3:
                printf("Módulo em desenvolvimento!");
                break;
            
            case 4:
                printf("Módulo em desenvolvimento!");
                break;

            case 5:
                printf("Módulo em desenvolvimento!");
                break;

            default:
                printf("Programa finalizado!");
                break;
        }

    return 0;
}

char verMenuPrincipal() {
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===         = = = = = Sistema de Gestão de Bonelaria = = = = =              ===\n");
    printf("===                                                                         ===\n");
    printf("===            1. Módulo em desenvolvimento                                 ===\n");
    printf("===            2. Módulo em desenvolvimento                                 ===\n");
    printf("===            3. Módulo em desenvolvimento                                 ===\n");
    printf("===            4. Módulo em desenvolvimento                                 ===\n");
    printf("===            5. Menu Sobre                                                ===\n");
    printf("===            0. Sair                                                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    printf("Selecione sua opção:");

    int esc;
    scanf("&d" , esc);
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
