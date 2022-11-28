#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "moduloRelatorio.h"
#include "funcoesAux.h"
#include "moduloCliente.h"
#include "moduloFornecedor.h"
#include "moduloBone.h"
#include "moduloEstoque.h"
#include "moduloPedido.h"

void moduloRelatorio(void) {

    char esc = verMenuRelatorio();

    while (esc!='0') {

        if (esc=='1') {
            controleRelMdl();

        }

        else if (esc=='2') {
            controleRelFnc();

        }

        else if (esc=='3') {
            controleRelClt();

        }

        else if (esc=='4') {
            controleRelEst();

        }

        else if (esc=='5') {
            relatorioPedido();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuRelatorio();
    }

}

void controleRelMdl(void) {

    char esc = verMenReltMdl();

    while (esc!='0') {

        if (esc=='1') {
            lerArqBcp(1);

        }

        else if (esc=='2') {
            lerArqBncp('1');

        }

        else if (esc=='3') {
            lerArqBncp('0');

        }

        else if (esc=='4') {
            printf("EM BREVE");

        }

        else if (esc=='5') {
            printf("EM BREVE");

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenReltMdl();
    }

}

void controleRelClt(void) {

    char esc = verMenReltClt();

    while (esc!='0') {

        if (esc=='1') {
            lerArqClt(1);

        }

        else if (esc=='2') {
            arqCltOrdAlf();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenReltClt();
    }

}

void controleRelFnc(void) {

    char esc = verMenReltFnc();

    while (esc!='0') {

        if (esc=='1') {
            lerArqFnc(1);

        }

        else if (esc=='2') {
            printf("ordem");

        }

        else if (esc=='3') {
            printf("material");

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenReltFnc();
    }

}

void controleRelEst(void) {

    char esc = verMenReltEst();

    while (esc!='0') {

        if (esc=='1') {
            lerArqEst(1);

        }

        else if (esc=='2') {
            arqEstMaMe(0);

        }

        else if (esc=='3') {
            arqEstMaMe(1);

        }

        else if (esc=='4') {
            arqEstOrdAlf();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenReltEst();
    }

}

char verMenuRelatorio(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Relatórios = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Relatório Boné                                          ===\n");
    printf("===              2. Relatório Fornecedor                                    ===\n");
    printf("===              3. Relatório cliente                                       ===\n");
    printf("===              4. Relatório estoque                                       ===\n");
    printf("===              5. Relatório pedidos                                       ===\n");
    printf("===              0. Voltar ao menu principal                                ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

char verMenReltMdl(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Relatórios Modelos = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Todos os modelos ativos                                 ===\n");
    printf("===              2. Bonés                                                   ===\n");
    printf("===              3. Chapéus                                                 ===\n");
    printf("===              4. Gasta mais tecido                                       ===\n");
    printf("===              5. Mais vendidos                                           ===\n");
    printf("===              0. Voltar ao menu relatórios                               ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

char verMenReltClt(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Relatórios Clientes = = = = =                    ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Todos os clientes ativos                                ===\n");
    printf("===              2. Clientes por ordem alfabética                           ===\n");
    printf("===              0. Voltar ao menu relatórios                               ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

char verMenReltFnc(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Relatórios Fornecedor = = = = =                  ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Todos fornecedores                                      ===\n");
    printf("===              2. Em ordem alfabética                                     ===\n");
    printf("===              3. Fornecedor e seus materiais                             ===\n");
    printf("===              0. Voltar ao menu relatórios                               ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

char verMenReltEst(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Relatórios Estoque = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Todo estoque                                            ===\n");
    printf("===              2. Menos quantidade                                        ===\n");
    printf("===              3. Mais quantidade                                         ===\n");
    printf("===              4. Ordem alfabética                                        ===\n");
    printf("===              0. Voltar ao menu relatórios                               ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void relatorioPedido(void) {
    system ( " clear||cls " );

    lerArqPedClt();

}

void arqCltOrdAlf(void) {
    FILE *fp;
    Cliente *clt;
	ClienteDin* novoClt;
	ClienteDin* lista;
    int tam;

	if (access("arqCliente.dat", F_OK) != -1) {

        fp = fopen("arqCliente.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            lista = NULL;

            clt = (Cliente*) malloc(sizeof(Cliente));

            while(fread(clt, sizeof(Cliente), 1, fp)) {
                
                if (clt->ativo == 1) {
                    //Para o nome
                    novoClt = (ClienteDin*) malloc(sizeof(ClienteDin));

                    tam = strlen(clt->nomeDoCliente) + 1;

                    novoClt->nomeDoCliente = (char*) malloc(tam*sizeof(char));
                    strcpy(novoClt->nomeDoCliente, clt->nomeDoCliente);

                    //Para o cpf
                    tam = strlen(clt->cpf) + 1;

                    novoClt->cpf = (char*) malloc(tam*sizeof(char));
                    strcpy(novoClt->cpf, clt->cpf);

                    //Para o numero
                    tam = strlen(clt->numero) + 1;

                    novoClt->numero = (char*) malloc(tam*sizeof(char));
                    strcpy(novoClt->numero, clt->numero);

                    //Para o email
                    tam = strlen(clt->email) + 1;

                    novoClt->email = (char*) malloc(tam*sizeof(char));
                    strcpy(novoClt->email, clt->email);


                    if (lista == NULL) {
                        lista = novoClt;
                        novoClt->prox = NULL;
                    } 

                    else if (strcmp(novoClt->nomeDoCliente,lista->nomeDoCliente) < 0) {
                        novoClt->prox = lista;
                        lista = novoClt;
                    } 

                    else {
                        ClienteDin* anter = lista;
                        ClienteDin* atual = lista->prox;

                        while ((atual != NULL) && strcmp(atual->nomeDoCliente,novoClt->nomeDoCliente) < 0) {
                            anter = atual;
                            atual = atual->prox;
                        }

                        anter->prox = novoClt;
                        novoClt->prox = atual;

                    }
                }
            }

            free(clt);

            // Exibindo a lista de palavras
            novoClt = lista;
            while (novoClt != NULL) {

                exibCltDin(novoClt);
                novoClt = novoClt->prox;

            }

            // Limpando a memória
            novoClt = lista;
            while (lista != NULL) {
                lista = lista->prox;
                free(novoClt->nomeDoCliente);
                free(novoClt->cpf);
                free(novoClt->numero);
                free(novoClt->email);
                free(novoClt);
                novoClt = lista;
            }

        }

        fclose(fp);
    }

}

void exibCltDin(ClienteDin *clt) {

    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("== Nome do Cliente: ");
    printf("%s" ,clt->nomeDoCliente);
    printf("\n");
    printf("== CPF: ");
    printf("%s" ,clt->cpf);
    printf("\n");
    printf("== Número: ");
    printf("%s" ,clt->numero);
    printf("\n");
    printf("== Email: ");
    printf("%s" ,clt->email);
    printf("\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void lerArqBncp(char num) {
    
    FILE *fp;
    BoneChap *bcp;
    int i = 0;

    if (access("arqBoneChap.dat", F_OK) != -1) {

        fp = fopen("arqBoneChap.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            bcp = (BoneChap*) malloc(sizeof(BoneChap));

            while (fread(bcp, sizeof(BoneChap), 1, fp)) {

                if ((bcp->ativo == 1) && (bcp->codigo[0] == num)) {   
                    exibBoneChap(bcp);

                    i = i + 1;

                }
            }

            free(bcp);

        }

        fclose(fp);
    }

}

void arqEstMaMe(int num) {
    FILE *fp;
    Estoque *est;
	EstoqueDin* novoEst;
	EstoqueDin* lista;
    int tam;

	if (access("arqEstoq.dat", F_OK) != -1) {

        fp = fopen("arqEstoq.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            lista = NULL;

            est = (Estoque*) malloc(sizeof(Estoque));

            while(fread(est, sizeof(Estoque), 1, fp)) {
                
                if (est->ativo == 1) {
                    //Para o nome
                    novoEst = (EstoqueDin*) malloc(sizeof(EstoqueDin));

                    tam = strlen(est->nomeDoMaterial) + 1;

                    novoEst->nomeDoMaterial = (char*) malloc(tam*sizeof(char));
                    strcpy(novoEst->nomeDoMaterial, est->nomeDoMaterial);

                    //Para o codigo
                    tam = strlen(est->codigo) + 1;

                    novoEst->codigo = (char*) malloc(tam*sizeof(char));
                    strcpy(novoEst->codigo, est->codigo);

                    //Para o cnpj
                    tam = strlen(est->cnpj) + 1;

                    novoEst->cnpj = (char*) malloc(tam*sizeof(char));
                    strcpy(novoEst->cnpj, est->cnpj);

                    //Para quantidade
                    novoEst->quant = est->quant;

                    if (num == 1) {
                        if (lista == NULL) {
                            lista = novoEst;
                            novoEst->prox = NULL;
                        } 

                        else if (novoEst->quant > lista->quant) {
                            novoEst->prox = lista;
                            lista = novoEst;
                        } 

                        else {
                            EstoqueDin* anter = lista;
                            EstoqueDin* atual = lista->prox;

                            while ((atual != NULL) && atual->quant > novoEst->quant) {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novoEst;
                            novoEst->prox = atual;

                        }
                    }

                    else {
                        if (lista == NULL) {
                            lista = novoEst;
                            novoEst->prox = NULL;
                        } 

                        else if (novoEst->quant < lista->quant) {
                            novoEst->prox = lista;
                            lista = novoEst;
                        } 

                        else {
                            EstoqueDin* anter = lista;
                            EstoqueDin* atual = lista->prox;

                            while ((atual != NULL) && atual->quant < novoEst->quant) {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novoEst;
                            novoEst->prox = atual;

                        }

                    }
                }
            }

            free(est);

            novoEst = lista;
            while (novoEst != NULL) {

                exibEstDin(novoEst);
                novoEst = novoEst->prox;

            }

            novoEst = lista;
            while (lista != NULL) {
                lista = lista->prox;
                free(novoEst->nomeDoMaterial);
                free(novoEst->codigo);
                free(novoEst->cnpj);
                free(novoEst);
                novoEst = lista;
            }

        }

        fclose(fp);
    }

}

void arqEstOrdAlf(void) {
    FILE *fp;
    Estoque *est;
	EstoqueDin* novoEst;
	EstoqueDin* lista;
    int tam;

	if (access("arqEstoq.dat", F_OK) != -1) {

        fp = fopen("arqEstoq.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            lista = NULL;

            est = (Estoque*) malloc(sizeof(Estoque));

            while(fread(est, sizeof(Estoque), 1, fp)) {
                if (est->ativo == 1) {
                    //Para o nome
                    novoEst = (EstoqueDin*) malloc(sizeof(EstoqueDin));

                    tam = strlen(est->nomeDoMaterial) + 1;

                    novoEst->nomeDoMaterial = (char*) malloc(tam*sizeof(char));
                    strcpy(novoEst->nomeDoMaterial, est->nomeDoMaterial);

                    //Para o codigo
                    tam = strlen(est->codigo) + 1;

                    novoEst->codigo = (char*) malloc(tam*sizeof(char));
                    strcpy(novoEst->codigo, est->codigo);

                    //Para o cnpj
                    tam = strlen(est->cnpj) + 1;

                    novoEst->cnpj = (char*) malloc(tam*sizeof(char));
                    strcpy(novoEst->cnpj, est->cnpj);

                    //Para quantidade
                    novoEst->quant = est->quant;

                    if (lista == NULL) {
                        lista = novoEst;
                        novoEst->prox = NULL;
                    } 

                    else if (strcmp(novoEst->nomeDoMaterial, lista->nomeDoMaterial) < 0) {
                        novoEst->prox = lista;
                        lista = novoEst;
                    } 

                    else {
                        EstoqueDin* anter = lista;
                        EstoqueDin* atual = lista->prox;

                        while ((atual != NULL) && strcmp(atual->nomeDoMaterial, novoEst->nomeDoMaterial) < 0) {
                            anter = atual;
                            atual = atual->prox;
                        }

                        anter->prox = novoEst;
                        novoEst->prox = atual;

                    }        
                }
            }

            free(est);

            novoEst = lista;
            while (novoEst != NULL) {

                exibEstDin(novoEst);
                novoEst = novoEst->prox;

            }

            novoEst = lista;
            while (lista != NULL) {
                lista = lista->prox;
                free(novoEst->nomeDoMaterial);
                free(novoEst->codigo);
                free(novoEst->cnpj);
                free(novoEst);
                novoEst = lista;
            }

        }

        fclose(fp);
    }

}

void exibEstDin(EstoqueDin *est) {

    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("\n");
    printf("Código do Material: ");
    printf("%s" ,est->codigo);
    printf("\n");
    printf("Nome do Material: ");
    printf("%s" ,est->nomeDoMaterial);
    printf("\n");
    printf("CNPJ do vendedor: ");
    printf("%s" ,est->cnpj);
    printf("\n");
    printf("Quantidade: ");
    printf("%f" ,est->quant);
    printf("\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}