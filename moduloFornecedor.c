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

    fp = fopen("arqFornecedor.txt","at");

    if (fp == NULL){
      fp = fopen("arqFornecedor.txt","wt");
      printf("Erro com arquivo!");

    }

    else {
        fprintf(fp,fnc->nomeFornecedor, "\n");
        fprintf(fp,"\n");

        fprintf(fp,fnc->cnpj, "\n");
        fprintf(fp,"\n");

        fprintf(fp,fnc->email, "\n");
        fprintf(fp,"\n");

        fprintf(fp,fnc->ativo, "\n");
        fprintf(fp,"\n");

    }

    fclose(fp);

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
    strcpy(fnc->ativo, "S");

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
