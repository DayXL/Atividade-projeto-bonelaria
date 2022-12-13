#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

        else if (esc=='6') {
            editarMaterial();

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
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar material                                   ===\n");
    printf("===                 2. Deletar material                                     ===\n");
    printf("===                 3. Ver materiais em estoque                             ===\n");
    printf("===                 4. Pesquisar material                                   ===\n");
    printf("===                 5. Comprar material                                     ===\n");
    printf("===                 6. Editar material                                      ===\n");
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

    if (fp == NULL) {

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

void lerArqEst(int num) {
    FILE *fp;
    Estoque *est;

    if (access("arqEstoq.dat", F_OK) != -1) {

        fp = fopen("arqEstoq.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            est = (Estoque*) malloc(sizeof(Estoque));

            while (fread(est, sizeof(Estoque), 1, fp)) {

                if (est->ativo == num) {    
                    exibEstoque(est);

                }
            }
            
            free(est);
        }

        fclose(fp);
    }

}

Estoque* acharEst(char *codigo) {
    FILE* fp;
    Estoque* est;

    if (access("arqEstoq.dat", F_OK) != -1) {
        fp = fopen("arqEstoq.dat", "rb");

        if (fp == NULL) {
            printf("Ocorreu um erro na abertura do arquivo!\n");

        }

        else {
            
            est = (Estoque*) malloc(sizeof(Estoque));

            while(fread(est, sizeof(Estoque), 1, fp)) {

                if ((strcmp(est->codigo, codigo) == 0) && (est->ativo != 0)) {
                    fclose(fp);
                    return est;

                } 

            }

        }

        fclose(fp);
    }

    return NULL;
}

void exibEstoque(Estoque *est) {

    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("== Código do Material: ");
    printf("%s" ,est->codigo);
    printf("\n");
    printf("== Nome do Material: ");
    printf("%s" ,est->nomeDoMaterial);
    printf("\n");
    printf("== CNPJ do vendedor: ");
    printf("%s" ,est->cnpj);
    printf("\n");
    printf("== Quantidade: ");
    printf("%f" ,est->quant);
    printf("\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");
    
}

void cadastrarMateriais(void) {

    Estoque* est;
    est = (Estoque*) malloc(sizeof(Estoque));

    char codigo[30];
    char cnpj[30];
    char nomeMaterial[100];
    char quant[30];
    int jaCad;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===             = = = = = Cadastrar material = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    jaCad = lerCodMat(codigo);

    if (jaCad == 1) {
        printf("\nMaterial já cadastrado! ");

    }

    else {
        jaCad = lerCnpjEst(cnpj);

        if (jaCad == 1) {
            printf("\nFornecedor não cadastrado!\n");

        }

        else {
            validarNomeMaterial(nomeMaterial);

            validarQuant(quant);

            char* nomeMais = pasMaisc(nomeMaterial);

            strcpy(est->codigo, codigo);
            strcpy(est->cnpj, cnpj);
            strcpy(est->nomeDoMaterial, nomeMais);
            est->quant = atof(quant);
            est->ativo = 1;

            salArqEst(est);
            free(nomeMais);

            printf("\nMaterial cadastrado com sucesso!\n");
        
        }

        
    }
    
    printf("\n===============================================================================\n");
    printf("\n");

    free(est);
}

int lerCodMat(char *codigo) {
    int tam;
    Estoque* est;

    do {

        printf("Código do material (Oito números): ");
        fgets(codigo, 30, stdin);

        tam = strlen(codigo);
        codigo[tam - 1] = '\0';

    } while ((tam != 9) || !validarNumInteiro(codigo));

    est = acharEst(codigo);

    if (est != NULL) {
        free(est);
        return 1;

    }

    free(est);
    return 0;

}

void validarNomeMaterial(char *nomeMaterial) {
    int tam;

    do {

        printf("Nome do material: ");
        fgets(nomeMaterial, 100, stdin);

        tam = strlen(nomeMaterial);
        nomeMaterial[tam - 1] = '\0';

    } while ((tam <=3 ) || !validarPalavra(nomeMaterial));

}

int lerCnpjEst(char *cnpj) {
    int tam;
    Fornecedor* fnc;

    do {

        printf("CNPJ(somente números): ");
        fgets(cnpj, 30, stdin);

        tam = strlen(cnpj);
        cnpj[tam - 1] = '\0';

    } while ((tam != 15) || !validarNumInteiro(cnpj));

    fnc = acharFnc(cnpj);

    if (fnc != NULL) {
        return 0;

    }

    return 1;

}

void validarQuant(char *quant) {
    int tam;

    do {

        printf("Qual a quantidade? ");
        fgets(quant, 30, stdin);

        tam = strlen(quant);
        quant[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(quant)));

}

void excluirMaterial(void) {

    FILE* fp;
    Estoque* est;
    Estoque* aux;
    char codigo[30];
    int tam;
    char aux2[20];
    int achou = 0;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir material = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("Código do material: ");
    fgets(codigo, 30, stdin);

    tam = strlen(codigo);
    codigo[tam - 1] = '\0';

    est = acharEst(codigo);
     
    if (est == NULL) {

        printf("\nMaterial não cadastrado!\n ");

    }

    else {

        if (access("arqEstoq.dat", F_OK) != -1) {

            aux = (Estoque*) malloc(sizeof(Estoque));
            fp = fopen("arqEstoq.dat", "r+b");

            if (fp == NULL) {
                printf("Não foi possível deletar!\n");

            }

            else {

                while(fread(aux, sizeof(Estoque), 1, fp) && (achou == 0)) {

                    if ((strcmp(aux->codigo, codigo) == 0) && (aux->ativo != 0)) {

                        achou = 1;
                        exibEstoque(aux);

                        printf("\nDeseja realmente deletar?1 para sim, 0 para não.\n");
                        fgets(aux2, 20, stdin);
                        
                        tam = strlen(aux2);
                        aux2[tam - 1] = '\0';

                        if (strcmp(aux2, "1\0") == 0) {
                            aux->ativo = 0;

                            fseek(fp, -1*sizeof(Estoque), SEEK_CUR);
                            fwrite(aux, sizeof(Estoque), 1, fp);

                            printf("\nMaterial excluído com sucesso!\n");
                        }

                        else {
                            printf("\nCancelado!\n");

                        }

                    }

                }

            }

            fclose(fp);
            free(aux);

        }

        else {
            printf("\nErro com arquivo\n");

        }

    }

    free(est);
}

void editarMaterial(void) {

    FILE* fp;
    Estoque* est;
    Estoque* aux;
    char codigo[30];
    int tam;
    int jaCad;
    char aux2[20];
    int achou = 0;
    char nomeMaterial[100];
    char cnpj[30];
    char quant[30];
    char esc;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Editar material = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("Código do material: ");
    fgets(codigo, 30, stdin);

    tam = strlen(codigo);
    codigo[tam - 1] = '\0';

    est = acharEst(codigo);
     
    if (est == NULL) {
        printf("\nMaterial não cadastrado!\n");

    }

    else {

        if (access("arqEstoq.dat", F_OK) != -1) {

            aux = (Estoque*) malloc(sizeof(Estoque));
            fp = fopen("arqEstoq.dat", "r+b");

            if (fp == NULL) {
                printf("\nNão foi possível atualizar!\n");
                
            }

            else {

                while(fread(aux, sizeof(Estoque), 1, fp) && (achou == 0)) {

                    if ((strcmp(aux->codigo, codigo) == 0) && (aux->ativo != 0)) {
                        achou = 1;
                        exibEstoque(aux);

                        printf("\nDeseja realmente atualizar?1 para sim, 0 para não.\n");
                        fgets(aux2, 20, stdin);
                        
                        tam = strlen(aux2);
                        aux2[tam - 1] = '\0';

                        if (strcmp(aux2, "1\0") == 0) {

                            esc = telAtlEst();

                            while (esc!='0') {

                                if (esc=='1') {

                                    validarNomeMaterial(nomeMaterial);

                                    char* nomeMais = pasMaisc(nomeMaterial);

                                    printf("%s", nomeMais);
                                    strcpy(aux->nomeDoMaterial,nomeMais);

                                    free(nomeMais);

                                }

                                else if (esc=='2') {
                                    lerCnpjEst(cnpj);

                                    jaCad = lerCnpjEst(cnpj);

                                    if (jaCad == 1) {
                                        printf("\nFornecedor não cadastrado!\n");

                                    }

                                    else {
                                        strcpy(aux->cnpj,cnpj);

                                    }

                                }

                                else if (esc=='3') {
                                    validarQuant(quant);
                                    aux->quant = atof(quant); 

                                }

                                else if (esc=='4') {
                                    validarNomeMaterial(nomeMaterial);

                                    lerCnpjEst(cnpj);

                                    validarQuant(quant);

                                    char* nomeMais = pasMaisc(nomeMaterial);

                                    strcpy(aux->nomeDoMaterial,nomeMais);
                                    strcpy(aux->cnpj,cnpj);
                                    aux->quant = atof(quant);

                                    free(nomeMais);
                                }

                                else {
                                    printf("Opção inválida!\n");
                                
                                }

                                esc = telAtlEst();
                            }
  
                            fseek(fp, -1*sizeof(Estoque), SEEK_CUR);
                            fwrite(aux, sizeof(Estoque), 1, fp);

                            printf("\nMaterial atualizado com sucesso!\n");
                        }

                        else {
                            printf("\nCancelado!\n");

                        }

                    }

                }

            }

            free(aux);
            fclose(fp);

        }

        else {
            printf("\nErro com arquivo\n");

        }
        
    }

    free(est);
}

char telAtlEst(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 = = = = = Atualizar = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Nome                                                 ===\n");
    printf("===                 2. Cnpj                                                 ===\n");
    printf("===                 3. Quantidade                                           ===\n");
    printf("===                 4. Atualizar tudo                                       ===\n");
    printf("===                 0. Sair                                                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void materiaisEstoque(void) {
    system ( " clear||cls " );
    
    lerArqEst(1);

}

void pesquisarMateriaisEstoque(void) {
    Estoque* est;
    char codigo[100];
    int tam;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===             = = = = = Materiais em Estoque  = = = = =                   ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    printf("Código material: ");
    fgets(codigo, 30, stdin);

    tam = strlen(codigo);
    codigo[tam - 1] = '\0';

    est = acharEst(codigo);
     
    if (est == NULL) {
        printf("Material não cadastrado! ");

    }

    else {
        exibEstoque(est);

    }

    free(est);

}

void comprarMateriais(void) {
    FILE* fp;
    Estoque* est;
    Estoque* aux;
    char codigo[30];
    char quant[30];
    int tam;
    int achou = 0;
    float estocado;
    float novoValor = 0;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Comprar material  = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    printf("Código do material: ");
    fgets(codigo, 30, stdin);

    tam = strlen(codigo);
    codigo[tam - 1] = '\0';

    est = acharEst(codigo);
     
    if (est == NULL) {
        printf("\nMaterial não cadastrado!\n ");

    }

    else {

        if (access("arqEstoq.dat", F_OK) != -1) {

            aux = (Estoque*) malloc(sizeof(Estoque));
            fp = fopen("arqEstoq.dat", "r+b");

            if (fp == NULL) {
                printf("Não foi possível atualizar!\n");
                
            }

            else {

                while(fread(aux, sizeof(Estoque), 1, fp) && (achou == 0)) {

                    if ((strcmp(aux->codigo, codigo) == 0) && (aux->ativo != 0)) {
                        achou = 1;
                        exibEstoque(aux);

                        printf("\n");
                        validarQuant(quant);

                        estocado = aux->quant;

                        novoValor = estocado + atof(quant);

                        aux->quant = novoValor;

                        fseek(fp, -1*sizeof(Estoque), SEEK_CUR);
                        fwrite(aux, sizeof(Estoque), 1, fp);

                        exibEstoque(aux);
                        printf("\nRegistrado com sucesso!\n");

                    }
                }
            }

            free(aux);
            fclose(fp);

        }

    }

    free(est);

}

void descontarMtl(char *codigo, float quant) {

    FILE* fp;
    Estoque* aux;
    int achou = 0;

    if (access("arqEstoq.dat", F_OK) != -1) {

        aux = (Estoque*) malloc(sizeof(Estoque));
        fp = fopen("arqEstoq.dat", "r+b");

        if (fp == NULL) {
            printf("Não foi possível descontar!\n");
                
        }

        else {

            while(fread(aux, sizeof(Estoque), 1, fp) && (achou == 0)) {

                if ((strcmp(aux->codigo, codigo) == 0) && (aux->ativo != 0)) {
                    achou = 1;

                    aux->quant = quant;

                    fseek(fp, -1*sizeof(Estoque), SEEK_CUR);
                    fwrite(aux, sizeof(Estoque), 1, fp);


                }
            }

        }

    }

    free(aux);
    fclose(fp);
}
