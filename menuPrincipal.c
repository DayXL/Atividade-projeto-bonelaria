#include <stdio.h>

int verMenuPrincipal();
void verMenuSobre();

int main(void) {
    verMenuPrincipal();
    verMenuSobre();

    //int esc = verMenuPrincipal();//

    /*while (esc!=0){

        if (esc==1){
            printf("Módulo em desenvolvimento!1");

        }

        else if (esc==2){
            printf("Módulo em desenvolvimento!2");

        }

        else if (esc==3){
            printf("Módulo em desenvolvimento!3");

        }

        else if (esc==4){
            printf("Módulo em desenvolvimento!4");

        }

        else if (esc==5){
            verMenuSobre();

        }

        else{
            printf("Opção inválida!");
        }
        

        /*switch (esc)
            {
                case 1:
                    printf("Módulo em desenvolvimento!1");
                    break;

                case 2:
                    printf("Módulo em desenvolvimento!2");
                    break;
                
                case 3:
                    printf("Módulo em desenvolvimento!3");
                    break;
                
                case 4:
                    printf("Módulo em desenvolvimento!4");
                    break;

                case 5:
                    verMenuSobre();
                    break;

                default:
                    printf("Opção inválida!");
                    break;
            } */

        //int esc = verMenuPrincipal();
    //}//

    //printf("Programa finalizado!");//

    return 0;
}

int verMenuPrincipal() {
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
    int esc;
    scanf("&d" , &esc);

    return esc;

}


void verMenuSobre() {
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
