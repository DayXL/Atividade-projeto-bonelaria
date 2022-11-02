#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloFornecedor.h"
#include "funcoesAux.h"

typedef struct fornecedor Fornecedor;

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

void salArqFnc(Fornecedor* fnc) {
    FILE *fp;

    fp = fopen("arqFornecedor.dat","ab");

    if (fp == NULL){

        fp = fopen("arqFornecedor.dat","wb");
        printf("Arquivo inexistente!\n");
        printf("Criando novo arquivo!");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {
            fwrite(fnc, sizeof(Fornecedor), 1, fp);

        }

    }

    else {
        fwrite(fnc, sizeof(Fornecedor), 1, fp);

    }

    fclose(fp);

}

void lerArqFnc(void) {
    FILE *fp;
    Fornecedor *fnc;
    fnc = (Fornecedor*) malloc(sizeof(Fornecedor));

    fp = fopen("arqFornecedor.dat","rb");

    if (fp == NULL) {

        fp = fopen("arqFornecedor.dat","wb");
        printf("Arquivo inexistente!\n");
        printf("Criando novo arquivo!");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

    }

    else {

        while (fread(fnc, sizeof(Fornecedor), 1, fp)) {

            if (fnc->ativo != 0) {
                fread(fnc, sizeof(Fornecedor), 1, fp);
                
                exibFornecedor(fnc);

                free(fnc);

            }
        }
    }

    fclose(fp);

}

void exibFornecedor(Fornecedor *fnc) {
    
    printf("\n");
    printf("Nome do Fornecedor: ");
    printf("%s" ,fnc->nomeFornecedor);
    printf("\n");
    printf("CNPJ: ");
    printf("%s" ,fnc->cnpj);
    printf("\n");
    printf("Email: ");
    printf("%s" ,fnc->email);
    printf("\n");

}

void cadastrarFornecedor(void) {

    Fornecedor* fnc;
    fnc = (Fornecedor*) malloc(sizeof(Fornecedor));

    char nomeFornecedor[100];
    char cnpj[30];
    char email[100];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===            = = = = = Cadastrar fornecedor = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    
    validarNomeFornecedor(nomeFornecedor);

    gerarCnpj();
    printf("\n");

    validarCnpj(cnpj);

    validarEmail2(email);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    strcpy(fnc->nomeFornecedor,nomeFornecedor);
    strcpy(fnc->cnpj,cnpj);
    strcpy(fnc->email,email);
    fnc->ativo = 1;

    salArqFnc(fnc);

    free(fnc);
}

void validarNomeFornecedor(char *nomeFornecedor) {
    int tam;

    do {

        printf("Nome do fornecedor: ");
        fgets(nomeFornecedor, 100, stdin);

        tam = strlen(nomeFornecedor);
        nomeFornecedor[tam - 1] = '\0';

    } while ((tam == 1) || !validarPalavra(nomeFornecedor));
 
}

void validarCnpj(char *cnpj) {
    int tam;

    do {

        do {

            printf("CNPJ(somente números): ");
            fgets(cnpj, 30, stdin);

            tam = strlen(cnpj);
            cnpj[tam - 1] = '\0';
        
        } while ((tam != 15) || !validarNumInteiro(cnpj));

    } while (!verificarCnpj(cnpj));

    printf(" ");
    printf("CNPJ válido!\n");

}

void validarEmail2(char *email) {
    int tam;

    do {

        printf("Email: ");
        fgets(email, 100, stdin);

        tam = strlen(email);
        email[tam - 1] = '\0';

    } while ((tam == 1) || !verificarEmail(email, tam));

}

void editarFornecedor(void) {

    char cnpj[16];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Editar fornecedor = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CNPJ(somente números): ");
    fgets(cnpj, 16, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void excluirFornecedor(void) {

    char cnpj[16];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir fornecedor = = = = =                   ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CNPJ(somente números): ");
    fgets(cnpj, 16, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void pesquisarFornecedor(void) {

    char cnpj[16];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Pesquisar fornecedor = = = = =                   ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CNPJ(somente números): ");
    fgets(cnpj, 16, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}
