#include <stdio.h>
#include <stdlib.h>

char verMenuPrincipal(void);


void moduloFornecedor(void);
char verMenuFornecedor(void);

void moduloCliente(void);
char verMenuCliente(void);

void moduloEstoque(void);
char verMenuEstoque(void);

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

        passarEnter();

        esc = verMenuFornecedor();
    }

}

char verMenuFornecedor(void) {
    system ( " clear||cls " );
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

        else if (esc=='5'){
            printf("Fechar pedido para cliente\n");

        }

        else{
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuCliente();
    }

}

char verMenuCliente(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Cliente = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar cliente                                    ===\n");
    printf("===                 2. Editar cliente                                       ===\n");
    printf("===                 3. Excluir cliente                                      ===\n");
    printf("===                 4. Pesquisar cliente                                    ===\n");
    printf("===                 5. Fechar pedido para cliente                           ===\n");
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

void moduloEstoque(void) {

    char esc = verMenuEstoque();

    while (esc!='0'){

        if (esc=='1'){
            printf("Materias em estoque\n");

        }

        else if (esc=='2'){
            printf("Pesquisar materias em estoque\n");

        }

        else if (esc=='3'){
            printf("Comprar materias para estoque\n");

        }

        else{
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

        passarEnter();

        esc = verMenuRelatorio();
    }

}

char verMenuRelatorio(void) {
    system ( " clear||cls " );
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
    system ( " clear||cls " );
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