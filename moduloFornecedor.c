#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

    if (access("arqCliente.dat", F_OK) != -1) {
        fp = fopen("arqFornecedor.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {
            fnc = (Fornecedor*) malloc(sizeof(Fornecedor));

            while (fread(fnc, sizeof(Fornecedor), 1, fp)) {

                if (fnc->ativo != 0) {                  
                    exibFornecedor(fnc);

                }
            }
            free(fnc);

        }
    }

    
    fclose(fp);

}

Fornecedor* acharFnc(char *cnpj) {
    FILE* fp;
    Fornecedor* fnc;

    if (access("arqCliente.dat", F_OK) != -1) {
        fp = fopen("arqFornecedor.dat", "rb");

        if (fp == NULL) {
            printf("Ocorreu um erro na abertura do arquivo!\n");

        }


        else {
                
            fnc = (Fornecedor*) malloc(sizeof(Fornecedor));

            while(fread(fnc, sizeof(Fornecedor), 1, fp)) {

                if ((strcmp(fnc->cnpj, cnpj) == 0) && (fnc->ativo != 0)) {
                    fclose(fp);
                    return fnc;

                } 

            }
        }
    }

    fclose(fp);
    return NULL;
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
    int jaCad;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===            = = = = = Cadastrar fornecedor = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    gerarCnpj();
    printf("\n");

    jaCad = validarCnpj(cnpj);

    if (jaCad == 1) {
        printf("\nFornecedor já cadastrado!\n");

    }

    else {
        validarNomeFornecedor(nomeFornecedor);

        validarEmail2(email);

        strcpy(fnc->nomeFornecedor,nomeFornecedor);
        strcpy(fnc->cnpj,cnpj);
        strcpy(fnc->email,email);
        fnc->ativo = 1;

        salArqFnc(fnc);

        printf("\nFornecedor cadastrado com sucesso!\n");
    }

    printf("\n===============================================================================\n");
    printf("\n");

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

int validarCnpj(char *cnpj) {
    Fornecedor* fnc;

    do {

        printf("CNPJ(somente números): ");
        fgets(cnpj, 30, stdin);
    
    } while (!verificarCnpj(cnpj));

    fnc = acharFnc(cnpj);

    if (fnc != NULL) {
        free(fnc);
        return 1;

    }
    
    free(fnc);
    return 0;

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

    FILE* fp;
    Fornecedor* fnc;
    Fornecedor* aux;
    char cnpj[30];
    int tam;
    char aux2[20];
    int achou = 0;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir fornecedor = = = = =                   ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CNPJ(somente números): ");
    fgets(cnpj, 30, stdin);

    tam = strlen(cnpj);
    cnpj[tam - 1] = '\0';

    fnc = acharFnc(cnpj);
     
    if (fnc == NULL) {

        printf("Fornecedor não cadastrado! ");

    }

    else {

        aux = (Fornecedor*) malloc(sizeof(Fornecedor));
        fp = fopen("arqFornecedor.dat", "r+b");

        if (access("arqFornecedor.dat", F_OK) != -1) {

            if (fp == NULL) {
                printf("Não foi possível deletar!\n");

            }

            else {

                while(fread(aux, sizeof(Fornecedor), 1, fp) && (achou == 0)) {

                    if ((strcmp(aux->cnpj, cnpj) == 0) && (aux->ativo != 0)) {

                        achou = 1;
                        exibFornecedor(aux);

                        printf("\nDeseja realmente deletar?1 para sim, 0 para não.\n");
                        fgets(aux2, 20, stdin);
                        
                        tam = strlen(aux2);
                        aux2[tam - 1] = '\0';

                        if (strcmp(aux2, "1\0") == 0) {
                            aux->ativo = 0;

                            fseek(fp, -1*sizeof(Fornecedor), SEEK_CUR);
                            fwrite(aux, sizeof(Fornecedor), 1, fp);

                            printf("\nFornecedor excluído com sucesso!\n");
                        }

                        else {
                            printf("\nCancelado!\n");

                        }

                    }

                }

            }
        }

        else {
            printf("\nErro com arquivo\n");

        }

        free(aux);
    }

    fclose(fp);
    free(fnc);

}

void pesquisarFornecedor(void) {
    Fornecedor* fnc;
    char cnpj[50];
    int tam;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Pesquisar fornecedor = = = = =                   ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CNPJ(somente números): ");
    fgets(cnpj, 50, stdin);

    tam = strlen(cnpj);
    cnpj[tam - 1] = '\0';

    fnc = acharFnc(cnpj);
     
    if (fnc == NULL) {
        printf("Fornecedor não cadastrado! ");

    }

    else {
        exibFornecedor(fnc);

    }

    free(fnc);

}
