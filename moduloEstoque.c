#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloEstoque.h"
#include "funcoesAux.h"

typedef struct estoque Estoque;

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

void salArqEst(Estoque* est) {
    FILE *fp;

    
    fp = fopen("arqEst.txt","at");

    if (fp == NULL){
      fp = fopen("arqEst.txt","wt");
      printf("Erro com arquivo!");

    }

    else {
        fprintf(fp,est->nomeDoMaterial, "\n");
        fprintf(fp,"\n");

        fprintf(fp,est->cnpj, "\n");
        fprintf(fp,"\n");

        fprintf(fp,est->quant, "\n");
        fprintf(fp,"\n");

        fprintf(fp,est->ativo, "\n");
        fprintf(fp,"\n");

    }

    fclose(fp);

}

void cadastrarMateriais(void) {
    system ( " clear||cls " );

    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));

    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===             = = = = = Cadastrar material = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    cnpj(est);

    validarNomeMaterial(est);

    validarQuant(est);
    
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    est->ativo = 1;

    salArqEst(est);

    free(est);
}

void validarNomeMaterial(Estoque *est) {
    int tam;
    char nomeMaterial[100];

    do {

        printf("Nome do material: ");
        fgets(nomeMaterial, 100, stdin);

        tam = strlen(nomeMaterial);
       nomeMaterial[tam - 1] = '\0';

    } while ((tam == 1) || !validarPalavra(nomeMaterial));

    strcpy(est->nomeDoMaterial, nomeMaterial);

}

void cnpj(Estoque *est) {
    int tam;
    char cnpj[30];

    do {

        printf("CNPJ(somente números): ");
        fgets(cnpj, 30, stdin);

        tam = strlen(cnpj);
        cnpj[tam - 1] = '\0';

    } while ((tam != 15) || !validarNumInteiro(cnpj));

    strcpy(est->cnpj, cnpj);

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
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===        = = = = = Materiais em Estoque  = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===     Linha vermelha: 100 tubos                                           ===\n");
    printf("===     Bico de boné: 367                                                   ===\n");
    printf("===     Tinha branca: 10 baldes                                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void pesquisarMateriaisEstoque(void) {

    char material[100];

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

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

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
