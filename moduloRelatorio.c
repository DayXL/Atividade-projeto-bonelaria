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
            controleRelPed();

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
            arqMdlMaMe(0);

        }

        else if (esc=='5') {
            arqMdlMaMe(1);

        }

        else if (esc=='6') {
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

        else if (esc=='3') {
            arqPedPorClt();

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
            arqFncOrdAlf();

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

void controleRelPed(void) {

    char esc = verMenReltPed();

    while (esc!='0') {

        if (esc=='1') {
            lerArqPedClt();

        }

        else if (esc=='2') {
            printf("Por data\n");

        }

        else if (esc=='3') {
            arqPedMaMe(1);

        }

        else if (esc=='4') {
            arqPedMaMe(0);
        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenReltPed();
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
    printf("===              5. Gasta menos tecido                                      ===\n");
    printf("===              6. Mais vendidos                                           ===\n");
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
    printf("===              3. Pedidos por cliente                                     ===\n");
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

char verMenReltPed(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Relatórios Pedidos = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Todos os pedidos                                        ===\n");
    printf("===              2. Pedidos por datas                                       ===\n");
    printf("===              3. Maior quantidade                                        ===\n");
    printf("===              4. Menor quantidade                                        ===\n");
    printf("===              0. Voltar ao menu relatórios                               ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

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

void arqFncOrdAlf(void) {
    FILE *fp;
    Fornecedor *fnc;
	FornecedorDin* novoFnc;
	FornecedorDin* lista;
    int tam;

	if (access("arqFornecedor.dat", F_OK) != -1) {

        fp = fopen("arqFornecedor.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            lista = NULL;

            fnc = (Fornecedor*) malloc(sizeof(Fornecedor));

            while(fread(fnc, sizeof(Fornecedor), 1, fp)) {
                
                if (fnc->ativo == 1) {
                    //Para o nome
                    novoFnc = (FornecedorDin*) malloc(sizeof(FornecedorDin));

                    tam = strlen(fnc->nomeFornecedor) + 1;

                    novoFnc->nomeFornecedor = (char*) malloc(tam*sizeof(char));
                    strcpy(novoFnc->nomeFornecedor, fnc->nomeFornecedor);

                    //Para o cnpj
                    tam = strlen(fnc->cnpj) + 1;

                    novoFnc->cnpj = (char*) malloc(tam*sizeof(char));
                    strcpy(novoFnc->cnpj, fnc->cnpj);

                    //Para o email
                    tam = strlen(fnc->email) + 1;

                    novoFnc->email = (char*) malloc(tam*sizeof(char));
                    strcpy(novoFnc->email, fnc->email);


                    if (lista == NULL) {
                        lista = novoFnc;
                        novoFnc->prox = NULL;
                    } 

                    else if (strcmp(novoFnc->nomeFornecedor,lista->nomeFornecedor) < 0) {
                        novoFnc->prox = lista;
                        lista = novoFnc;
                    } 

                    else {
                        FornecedorDin* anter = lista;
                        FornecedorDin* atual = lista->prox;

                        while ((atual != NULL) && strcmp(atual->nomeFornecedor,novoFnc->nomeFornecedor) < 0) {
                            anter = atual;
                            atual = atual->prox;
                        }

                        anter->prox = novoFnc;
                        novoFnc->prox = atual;

                    }
                }
            }

            free(fnc);

            // Exibindo a lista de palavras
            novoFnc = lista;
            while (novoFnc != NULL) {

                exibFncDin(novoFnc);
                novoFnc = novoFnc->prox;

            }

            // Limpando a memória
            novoFnc = lista;
            while (lista != NULL) {
                lista = lista->prox;
                free(novoFnc->nomeFornecedor);
                free(novoFnc->cnpj);
                free(novoFnc->email);
                free(novoFnc);
                novoFnc = lista;
            }

        }

        fclose(fp);
    }

}

void exibFncDin(FornecedorDin *fnc) {

    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("\n");
    printf("== Nome do Fornecedor: ");
    printf("%s" ,fnc->nomeFornecedor);
    printf("\n");
    printf("== CNPJ: ");
    printf("%s" ,fnc->cnpj);
    printf("\n");
    printf("== Email: ");
    printf("%s" ,fnc->email);
    printf("\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void arqPedMaMe(int num) {
    FILE *fp;
    PedidoCliente *ped;
	PedidoClienteDin* novoPed;
	PedidoClienteDin* lista;
    int tam;

	if (access("arqPedClt.dat", F_OK) != -1) {

        fp = fopen("arqPedClt.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            lista = NULL;

            ped = (PedidoCliente*) malloc(sizeof(PedidoCliente));

            while(fread(ped, sizeof(PedidoCliente), 1, fp)) {

                //Para o pedido
                novoPed = (PedidoClienteDin*) malloc(sizeof(PedidoClienteDin));

                tam = strlen(ped->pedido) + 1;

                novoPed->pedido = (char*) malloc(tam*sizeof(char));
                strcpy(novoPed->pedido, ped->pedido);

                //Para o cpf
                tam = strlen(ped->cpf) + 1;

                novoPed->cpf = (char*) malloc(tam*sizeof(char));
                strcpy(novoPed->cpf, ped->cpf);
                
                //Para o codigo
                tam = strlen(ped->codigo) + 1;

                novoPed->codigo = (char*) malloc(tam*sizeof(char));
                strcpy(novoPed->codigo, ped->codigo);

                //Para quantidade
                novoPed->quant = ped->quant;

                //Para a cor
                tam = strlen(ped->cor) + 1;

                novoPed->cor = (char*) malloc(tam*sizeof(char));
                strcpy(novoPed->cor, ped->cor);

                if (num == 1) {
                    if (lista == NULL) {
                        lista = novoPed;
                        novoPed->prox = NULL;
                    } 

                    else if (novoPed->quant > lista->quant) {
                        novoPed->prox = lista;
                        lista = novoPed;
                    } 

                    else {
                            PedidoClienteDin* anter = lista;
                            PedidoClienteDin* atual = lista->prox;

                        while ((atual != NULL) && atual->quant > novoPed->quant) {
                            anter = atual;
                            atual = atual->prox;
                        }

                        anter->prox = novoPed;
                        novoPed->prox = atual;

                    }
                }

                else {
                    if (lista == NULL) {
                        lista = novoPed;
                        novoPed->prox = NULL;
                    } 

                    else if (novoPed->quant < lista->quant) {
                        novoPed->prox = lista;
                        lista = novoPed;
                    } 

                    else {
                        PedidoClienteDin* anter = lista;
                        PedidoClienteDin* atual = lista->prox;

                        while ((atual != NULL) && atual->quant < novoPed->quant) {
                            anter = atual;
                            atual = atual->prox;
                        }

                        anter->prox = novoPed;
                        novoPed->prox = atual;

                    }

                }
            }

            free(ped);

            novoPed = lista;
            while (novoPed != NULL) {

                exibPedDin(novoPed);
                novoPed = novoPed->prox;

            }

            novoPed = lista;
            while (lista != NULL) {
                lista = lista->prox;
                free(novoPed->pedido);
                free(novoPed->cpf);
                free(novoPed->codigo);
                free(novoPed->cor);
                free(novoPed);
                novoPed = lista;
            }

        }

        fclose(fp);
    }

}

void exibPedDin(PedidoClienteDin *pedClt) {
    
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("\n");
    printf("== Número do pedido: ");
    printf("%s" ,pedClt->pedido);
    printf("\n");
    printf("== CPF do cliente: ");
    printf("%s" ,pedClt->cpf);
    printf("\n");
    printf("== Código do boné: ");
    printf("%s" ,pedClt->codigo);
    printf("\n");
    printf("== Quantidade: ");
    printf("%f" ,pedClt->quant);
    printf("\n");
    printf("== Cor: ");
    printf("%s" ,pedClt->cor);
    printf("\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void arqPedPorClt (void) {
    FILE *fp;
    Cliente *clt;
    
    if (access("arqCliente.dat", F_OK) != -1) {

        fp = fopen("arqCliente.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            clt = (Cliente*) malloc(sizeof(Cliente));

            while (fread(clt, sizeof(Cliente), 1, fp)) {

                if (clt->ativo == 1) {
                    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");

                    exibCliente(clt);

                    acharPedClt(clt->cpf);
                    
                    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");

                }
            }
            free(clt);

        }

        fclose(fp);
    }

}

void acharPedClt(char *cpf) {
    
    FILE *fp;
    PedidoCliente *pedClt;
    
    if (access("arqPedClt.dat", F_OK) != -1) {

        fp = fopen("arqPedClt.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            pedClt = (PedidoCliente*) malloc(sizeof(PedidoCliente));

            while (fread(pedClt, sizeof(PedidoCliente), 1, fp)) {

                if ((strcmp(cpf, pedClt->cpf) == 0)) {
                    exibPedido(pedClt);
                }
            }

            free(pedClt);

        }

        fclose(fp);
    }

}

void arqMdlMaMe(int num) {
    FILE *fp;
    BoneChap *bcp;
	BoneChapDin* novoMdl;
	BoneChapDin* lista;
    int tam;

	if (access("arqBoneChap.dat", F_OK) != -1) {

        fp = fopen("arqBoneChap.dat","rb");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {

            lista = NULL;

            bcp = (BoneChap*) malloc(sizeof(BoneChap));

            while(fread(bcp, sizeof(BoneChap), 1, fp)) {
                
                if (bcp->ativo == 1) {
                    //Para o nome
                    novoMdl = (BoneChapDin*) malloc(sizeof(BoneChapDin));

                    tam = strlen(bcp->nomeBonChap) + 1;

                    novoMdl->nomeBonChap = (char*) malloc(tam*sizeof(char));
                    strcpy(novoMdl->nomeBonChap, bcp->nomeBonChap);

                    //Para o codigo
                    tam = strlen(bcp->codigo) + 1;

                    novoMdl->codigo = (char*) malloc(tam*sizeof(char));
                    strcpy(novoMdl->codigo, bcp->codigo);

                    //Para unidadepor metro
                    novoMdl->uniPorMetro = bcp->uniPorMetro;

                    //Para unidadepor linha
                    novoMdl->uniPorTubo = bcp->uniPorTubo;

                    if (num == 1) {
                        if (lista == NULL) {
                            lista = novoMdl;
                            novoMdl->prox = NULL;
                        } 

                        else if (novoMdl->uniPorMetro > lista->uniPorMetro) {
                            novoMdl->prox = lista;
                            lista = novoMdl;
                        } 

                        else {
                            BoneChapDin* anter = lista;
                            BoneChapDin* atual = lista->prox;

                            while ((atual != NULL) && atual->uniPorMetro > novoMdl->uniPorMetro) {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novoMdl;
                            novoMdl->prox = atual;

                        }
                    }

                    else {
                        if (lista == NULL) {
                            lista = novoMdl;
                            novoMdl->prox = NULL;
                        } 

                        else if (novoMdl->uniPorMetro < lista->uniPorMetro) {
                            novoMdl->prox = lista;
                            lista = novoMdl;
                        } 

                        else {
                            BoneChapDin* anter = lista;
                            BoneChapDin* atual = lista->prox;

                            while ((atual != NULL) && atual->uniPorMetro < novoMdl->uniPorMetro) {
                                anter = atual;
                                atual = atual->prox;
                            }

                            anter->prox = novoMdl;
                            novoMdl->prox = atual;

                        }

                    }
                }
            }

            free(bcp);

            novoMdl = lista;
            while (novoMdl != NULL) {

                exibBcpDin(novoMdl);
                novoMdl = novoMdl->prox;

            }

            novoMdl = lista;
            while (lista != NULL) {
                lista = lista->prox;
                free(novoMdl->nomeBonChap);
                free(novoMdl->codigo);
                free(novoMdl);
                novoMdl = lista;
            }

        }

        fclose(fp);
    }

}

void exibBcpDin(BoneChapDin *bcp) {
    
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("== Nome do Modelo: ");
    printf("%s" ,bcp->nomeBonChap);
    printf("\n");
    printf("== Código: ");
    printf("%s" ,bcp->codigo);
    printf("\n");
    printf("== Quantidade por metro: ");
    printf("%f" ,bcp->uniPorMetro);
    printf("\n");
    printf("== Quantidade por tubo de linha: ");
    printf("%f" ,bcp->uniPorTubo);
    printf("\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}
