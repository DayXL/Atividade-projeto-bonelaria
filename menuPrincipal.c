#include <stdio.h>
#include <stdlib.h>

char verMenuPrincipal(void);

void moduloBone(void);
char verMenuBone(void);

void moduloFornecedor(void);
char verMenuFornecedor(void);

void moduloCliente(void);
char verMenuCliente(void);

void moduloRelatorio(void);
char verMenuRelatorio(void);

void verMenuSobre(void);

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
            moduloRelatorio();

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
    printf("===                 1. Módulo Boné                                          ===\n");
    printf("===                 2. Módulo Fornecedor                                    ===\n");
    printf("===                 3. Módulo Cliente                                       ===\n");
    printf("===                 4. Relatórios                                           ===\n");
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

        printf("Tecle ENTER para continuar");
        getchar();

        esc = verMenuBone();
    }

}

char verMenuBone(void) {
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

void moduloFornecedor(void) {

    char esc = verMenuFornecedor();

    while (esc!='0'){

        if (esc=='1'){
            printf("Cadastrar fornecedor\n");

        }

        else if (esc=='2'){
            printf("Editar fornecedor\n");

        }

        else if (esc=='3'){
            printf("Excluir fornecedor\n");

        }

        else if (esc=='4'){
            printf("Pesquisar fornecedor\n");

        }

        else{
            printf("Opção inválida!\n");
        
        }

        printf("Tecle ENTER para continuar");
        getchar();

        esc = verMenuFornecedor();
    }

}

char verMenuFornecedor(void) {
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Fornecedor = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar fornecedor                                 ===\n");
    printf("===                 2. Editar fornecedor                                    ===\n");
    printf("===                 3. Excluir fornecedor                                   ===\n");
    printf("===                 4. Pesquisar fornecedor                                 ===\n");
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

void moduloCliente(void) {

    char esc = verMenuCliente();

    while (esc!='0'){

        if (esc=='1'){
            printf("Cadastrar cliente\n");

        }

        else if (esc=='2'){
            printf("Editar cliente\n");

        }

        else if (esc=='3'){
            printf("Excluir cliente\n");

        }

        else if (esc=='4'){
            printf("Pesquisar cliente\n");

        }

        else{
            printf("Opção inválida!\n");
        
        }

        printf("Tecle ENTER para continuar");
        getchar();

        esc = verMenuCliente();
    }

}

char verMenuCliente(void) {
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Cliente = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar cliente                                    ===\n");
    printf("===                 2. Editar cliente                                       ===\n");
    printf("===                 3. Excluir cliente                                      ===\n");
    printf("===                 4. Pesquisar cliente                                    ===\n");
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

void moduloRelatorio(void) {

    char esc = verMenuRelatorio();

    while (esc!='0'){

        if (esc=='1'){
            printf("Relatório Boné\n");

        }

        else if (esc=='2'){
            printf("Relatório Fornecedor\n");

        }

        else if (esc=='3'){
            printf("Relatório cliente\n");

        }

        else{
            printf("Opção inválida!\n");
        
        }

        printf("Tecle ENTER para continuar");
        getchar();

        esc = verMenuRelatorio();
    }

}

char verMenuRelatorio(void) {
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Relatórios = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Relatório Boné                                       ===\n");
    printf("===                 2. Relatório Fornecedor                                 ===\n");
    printf("===                 3. Relatório cliente                                    ===\n");
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