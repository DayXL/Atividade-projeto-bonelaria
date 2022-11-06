#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloEstoque.h"
#include "moduloFornecedor.h"
#include "funcoesAux.h"

typedef struct estoque Estoque;
typedef struct fornecedor Fornecedor;

void moduloEstoque(void) {

    char esc = verMenuEstoque();

    while (esc!='0') {

        if (esc=='1') {
            cadastrarMateriais();

        }

        else if (esc=='2') {
            excluirMaterial();

        }

        else if (esc=='3') {
            materiaisEstoque();

        }

        else if (esc=='4') {
            pesquisarMateriaisEstoque();

        }

        else if (esc=='5') {
            comprarMateriais();

        }

        else {
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
    printf("===                 1. Cadastrar materiais                                  ===\n");
    printf("===                 2. Deletar materiais                                    ===\n");
    printf("===                 3. Ver materiais em estoque                             ===\n");
    printf("===                 4. Pesquisar materias em estoque                        ===\n");
    printf("===                 5. Comprar materiais para estoque                       ===\n");
    printf("===                 0. Voltar ao menu principal                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void salArqEst(Estoque *est) {
    FILE *fp;

    fp = fopen("arqEstoq.dat","ab");

    if (fp == NULL){

        fp = fopen("arqEstoq.dat","wb");
        printf("Arquivo inexistente!\n");
        printf("Criando novo arquivo!");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {
            fwrite(est, sizeof(Estoque), 1, fp);

        }

    }

    else {
        fwrite(est, sizeof(Estoque), 1, fp);

    }

    fclose(fp);

}

void lerArqEst(void) {
    FILE *fp;
    Estoque *est;
    est = (Estoque*) malloc(sizeof(Estoque));

    fp = fopen("arqEstoq.dat","rb");

    if (fp == NULL) {

        fp = fopen("arqEstoq.dat","wb");
        printf("Arquivo inexistente!\n");
        printf("Criando novo arquivo!");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

    }

    else {

        while (fread(est, sizeof(Estoque), 1, fp)) {

            if (est->ativo != 0) {
                fread(est, sizeof(Estoque), 1, fp);
                
                exibEstoque(est);

                free(est);

            }
        }
    }

    fclose(fp);

}

Estoque* acharEst(char *nome) {
    FILE* fp;
    Estoque* est;

    est = (Estoque*) malloc(sizeof(Estoque));
    fp = fopen("arqEstoq.dat", "rb");

    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");

    }


    else {

        while(!feof(fp)) {
            fread(est, sizeof(Estoque), 1, fp);

            if (strcmp(est->nomeDoMaterial, nome) == 0) {

                if (est->ativo != 0) {
                    fclose(fp);
                    return est;
                }

                else {
                    fclose(fp);
                    return NULL;
                }

            } 

        }

    }

    fclose(fp);
    return NULL;
}

void exibEstoque(Estoque *est) {
    
    printf("\n");
    printf("Nome do Material: ");
    printf("%s" ,est->nomeDoMaterial);
    printf("\n");
    printf("CNPJ do vendedor: ");
    printf("%s" ,est->cnpj);
    printf("\n");
    printf("Quantidade: ");
    printf("%s" ,est->quant);
    printf("\n");

}

void cadastrarMateriais(void) {
    system ( " clear||cls " );

    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));
    int jaCad;

    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===             = = = = = Cadastrar material = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    jaCad = validarNomeMaterial(est);

    if (jaCad == 1) {
        printf("\nMaterial já cadastrado! ");

    }

    else {
        jaCad = cnpj(est);

        if (jaCad == 1) {
            printf("\nFornecedor não cadastrado!\n");

        }

        else {

            validarQuant(est);

            est->ativo = 1;

            salArqEst(est);

            printf("\nMaterial cadastrado com sucesso!\n");
        
        }

        
    }
    
    printf("\n===============================================================================\n");
    printf("\n");

    free(est);
}

int validarNomeMaterial(Estoque *est) {
    int tam;
    char nomeMaterial[100];
    Estoque* aux;

    do {

        printf("Nome do material: ");
        fgets(nomeMaterial, 100, stdin);

        tam = strlen(nomeMaterial);
        nomeMaterial[tam - 1] = '\0';

        aux = acharEst(nomeMaterial);

        if (aux != NULL) {
            return 1;

        }

    } while ((tam == 1) || !validarPalavra(nomeMaterial));

    strcpy(est->nomeDoMaterial, nomeMaterial);

    return 0;

}

int cnpj(Estoque *est) {
    int tam;
    char cnpj[30];
    Fornecedor* fnc;

    do {

        printf("CNPJ(somente números): ");
        fgets(cnpj, 30, stdin);

        tam = strlen(cnpj);
        cnpj[tam - 1] = '\0';

        fnc = acharFnc(cnpj);

        if (fnc != NULL) {
            return 0;

        }

    } while ((tam != 15) || !validarNumInteiro(cnpj));

    strcpy(est->cnpj, cnpj);

    return 1;

}

void validarQuant(Estoque *est) {
    int tam;
    char quant[10];

    do {

        printf("Qual a quantidade? ");
        fgets(quant, 10, stdin);

        tam = strlen(quant);
        quant[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(quant)));

    strcpy(est->quant, quant);

}

void excluirMaterial(void) {

    char material[100];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir material = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("Nome do material: ");
    fgets(material, 100, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void materiaisEstoque(void) {
    system ( " clear||cls " );
    
    lerArqEst();

}

void pesquisarMateriaisEstoque(void) {
    Estoque* est;
    char material[100];
    int tam;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===             = = = = = Materiais em Estoque  = = = = =                   ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    printf("Nome material: ");
    fgets(material, 100, stdin);

    tam = strlen(material);
    material[tam - 1] = '\0';

    est = acharEst(material);
     
    if (est == NULL) {
        printf("Material não cadastrado! ");

    }

    else {
        exibEstoque(est);

    }

    free(est);

}

void comprarMateriais(void) {

    char material[100];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Comprar material  = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    printf("Nome material: ");
    fgets(material, 100, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}
