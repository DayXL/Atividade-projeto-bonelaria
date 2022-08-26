#include <stdio.h>

void verMenuPrincipal(void);
void verMenuSobre(void);

int main(void) {
    verMenuPrincipal();
    verMenuSobre();
    return 0;
}

void verMenuPrincipal(void) {
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===         = = = = = Sistema de Gestão de Bonelaria = = = = =              ===\n");
    printf("===                                                                         ===\n");
    printf("===            1. Módulo em desenvolvimento                                 ===\n");
    printf("===            2. Módulo em desenvolvimento                                 ===\n");
    printf("===            3. Módulo em desenvolvimento                                 ===\n");
    printf("===            4. Módulo em desenvolvimento                                 ===\n");
    printf("===            5. Módulo em desenvolvimento                                 ===\n");
    printf("===            0. Sair                                                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");
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
