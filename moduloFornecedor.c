#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloFornecedor.h"
#include "funcoesAux.h"

void moduloFornecedor(void) {

    char esc = verMenuFornecedor();

    while (esc!='0') {

        if (esc=='1') {
            cadastrarFornecedor();

        }

        else if (esc=='2') {
            editarFornecedor();

        }

        else if (esc=='3') {
            excluirFornecedor();

        }

        else if (esc=='4') {
            pesquisarFornecedor();

        }

        else {
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

    char esc;
    esc = auxEscolha();

    return esc;

}

void cadastrarFornecedor(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===            = = = = = Cadastrar fornecedor = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    
    validarNomeFornecedor();

    validarCnpj();

    validarEmail2();

    itens();

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void validarNomeFornecedor(void) {
    int a = 0;
    int tam;
    char nomeFornecedor[100];

    while (a == 0) {

        printf("Nome do fornecedor: ");
        fgets(nomeFornecedor, 100, stdin);

        tam = strlen(nomeFornecedor);
        nomeFornecedor[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarPalavra(nomeFornecedor));

    }

}

void validarCnpj(void) {
    int a = 0;
    int tam;
    char cnpj[16];

    while (a == 0) {
        int b = 0;

        printf("CNPJ(somente números): ");
        fgets(cnpj, 16, stdin);

        tam = strlen(cnpj);
        cnpj[tam - 1] = '\0';

        b = ((tam == 1) || (tam < 15)) ? 0 : (validarNumInteiro(cnpj));

        if (b == 1) {
            
            if (verificarCnpj(cnpj)) {

                printf(" ");
                printf("CNPJ válido!\n");
                a = 1;

            }

            else {

                printf(" ");
                printf("CNPJ inválido!\n");
                a = 0;

            }

        }

        else {
            a = 0;

        } 

    }

}

void validarEmail2(void) {
    int a = 0;
    int tam;
    char email[100];

    while (a == 0) {

        printf("Email: ");
        fgets(email, 100, stdin);

        tam = strlen(email);
        email[tam - 1] = '\0';

        a = 1;

        //a = (tam == 1) ? 0 : (validarPalavra(email));

    }

}

void itens(void) {
    int a = 0;
    int tam;
    char itensQueVende[100];

    while (a == 0) {

        printf("Itens que vende: ");
        fgets(itensQueVende, 100, stdin);

        tam = strlen(itensQueVende);
        itensQueVende[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarPalavra(itensQueVende));

    }

}

void editarFornecedor(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Editar fornecedor = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===                   Informe o CNPJ:                                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void excluirFornecedor(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir fornecedor = = = = =                   ===\n");
    printf("===                                                                         ===\n");
    printf("===                   Informe o CNPJ:                                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void pesquisarFornecedor(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Pesquisar fornecedor = = = = =                   ===\n");
    printf("===                                                                         ===\n");
    printf("===                   Informe o CNPJ:                                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}
