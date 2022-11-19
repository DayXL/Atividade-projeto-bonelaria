#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "moduloPedido.h"
#include "moduloCliente.h"
#include "moduloBone.h"
#include "moduloEstoque.h"
#include "funcoesAux.h"

typedef struct pedidoCliente PedidoCliente;
typedef struct boneChap BoneChap;
typedef struct estoque Estoque;

void moduloPedido(void) {

    char esc = verMenuPedido();

    while (esc!='0') {

        if (esc=='1') {
            pedidoCliente();

        }

        else if (esc=='2') {
            printf("\nPesquisar pedido\n");

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuPedido();
    }

}

char verMenuPedido(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Realizar pedido = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Fazer pedido                                            ===\n");
    printf("===              2. Pesquisar pedido                                        ===\n");
    printf("===              0. Voltar ao menu principal                                ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void pedidoCliente(void) {

    BoneChap* bcp;
    Cliente* clt;
    PedidoCliente* pedClt;
    pedClt = (PedidoCliente*) malloc(sizeof(PedidoCliente));
    char cpf[30];
    char codigo[30];
    char quant[20];
    char aux[45];
    char cor[30];
    int tam;
    int perm;
    int perm2;
    float novoValor[5] = {-1,-1,-1,-1,-1};
    char esc[20];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Fechar pedido = = = = =                         ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CPF(somente números): ");
    fgets(cpf, 30, stdin);

    tam = strlen(cpf);
    cpf[tam - 1] = '\0';

    clt = acharClt(cpf);
     
    if (clt == NULL) {
        printf("\nCliente não cadastrado!\n ");

    }

    else {
        bcp = selecionarModelo(codigo);

        printf("\nModelo escolhido: \n");
        exibBoneChap(bcp);

        lerQuant(quant);

        printf("\nTecidos disponíveis: \n");
        acharTec();

        perm = selecionarCor(aux, atof(quant), bcp, novoValor, cor);

        if (perm == 1) {
            perm2 = verMtlDisp(bcp, atof(quant), novoValor,aux);

            if (perm2 == 1) {
                printf("\nDeseja fechar o pedido?1 para sim, 0 para não.\n");
                fgets(esc, 20, stdin);
                        
                tam = strlen(esc);
                esc[tam - 1] = '\0';

                if (strcmp(esc, "1\0") == 0) {
                    printf("\nFechando pedido ... \n");

                    int i = 0;
                    int j = 0;

                    while (i < 35) {
                        char aux2[9] = {aux[i], aux[i + 1], aux[i + 2], aux[i + 3], aux[i + 4], aux[i + 5], aux[i + 6], aux[i + 7]}; 
                        descontarMtl(aux2, novoValor[j]);

                        j = j + 1;
                        i = i + 8;
                    }

                    strcpy(pedClt->pedido,gerarIdPed());
                    strcpy(pedClt->cpf,cpf);
                    strcpy(pedClt->codigo,bcp->codigo);
                    pedClt->quant = atof(quant);
                    strcpy(pedClt->cor,cor);

                    salArqPedClt(pedClt);

                }

                else {
                    printf("\nPedido cancelado! \n");

                }   

            }

            else {
                printf("\nO pedido não pode ser concluído por falta de materiais! \n");

            }

        }

        else {
            printf("\nO pedido não pode ser concluído! \n");

        }

        free(bcp);

    }

    free(pedClt);
    free(clt);

}

void lerArqBcpDif(char num) {
    
    FILE *fp;
    BoneChap *bcp;

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

                }
            }

            free(bcp);

        }

        fclose(fp);
    }

}

BoneChap* selecionarModelo(char *codigo) {

    BoneChap* bcp;
    char esc;
    int tam;

    do {
        esc = escolha();

        if (esc == '1') {
            esc = '0';
            printf("\nBonés disponíveis: \n");
            lerArqBcpDif('1');

        }

        else if (esc == '2') {
            //esc = '0';
            //printf("\nChapéus disponíveis: \n");
            //lerArqBcpDif('0');
            printf("\nSem fabricação de chapéu no momento!\n");
            passarEnter();

        }

        else {
            printf("Opção inválida!\n");

        }

    } while (esc != '0');

    do {

        printf("\nDigite o código: \n");
        fgets(codigo, 30, stdin);

        tam = strlen(codigo);
        codigo[tam - 1] = '\0';

        bcp = acharMdl(codigo);
        
    } while (bcp == NULL); 

    return bcp;
}

void lerQuant(char *quant) {
    int tam;

    do {

        printf("Qual a quantidade: ");
        fgets(quant, 20, stdin);

        tam = strlen(quant);
        quant[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(quant)));

}

int verMtlDisp(BoneChap* bcp, float quant, float *novoValor, char *aux) {

    Estoque* est;
    char regul[3] = {bcp->codigo[3], bcp->codigo[4]};

    if (bcp->codigo[0] == '1') {

        est = acharMtlPelNom("ABA", 2);

        if (est == NULL) {
            printf("\nSem Aba no estoque!\n");
            return 0;

        }

        else {
            if (est->quant > quant) {
                alterValor(novoValor,aux, quant, est);

            }

            else {
                printf("\nAba insuficiente!\n");
                return 0;

            }
        }

        if (bcp->codigo[1] == '1') {
            est = acharMtlPelNom("BOTAO", 4);

            if (est == NULL) {
                printf("\nSem botão no estoque!\n");
                return 0;

            }

            else {
                if (est->quant > quant) {
                    alterValor(novoValor,aux, quant, est);

                }

                else {
                    printf("\nBotão insuficiente!\n");
                    return 0;

                }

            }

        }

        if (bcp->codigo[2] == '1') {
            est = acharMtlPelNom("TELA", 3);

            if (est == NULL) {
                printf("\nSem tela no estoque!\n");
                return 0;

            }

            else {
                if (est->quant > quant) {
                    alterValor(novoValor,aux, quant, est);

                }

                else {
                    printf("\nTela insuficiente!\n");
                    return 0;

                }

            }
        }
        
        if ((strcmp(regul, "01") == 0)) {
            
            est = acharMtlPelNom("REGULADOR DE FIVELA", 17);

            if (est == NULL) {
                printf("\nSem regulador de fivela no estoque!\n");
                return 0;

            }

            else {
                if (est->quant > quant) {
                    alterValor(novoValor,aux, quant, est);

                }

                else {
                    printf("\nRegulador de fivela insuficiente!\n");
                    return 0;

                }

            }

        }

        else if ((strcmp(regul, "10") == 0)) {
            est = acharMtlPelNom("REGULADOR DE PLASTICO", 20);

            if (est == NULL) {
                printf("\nSem regulador de plástico no estoque!\n");
                return 0;

            }

            else {
                if (est->quant > quant) {
                    alterValor(novoValor,aux, quant, est);

                }

                else {
                    printf("\nRegulador de plástico insuficiente!\n");
                    return 0;

                }

            }

        }
        
        else if ((strcmp(regul, "11") == 0)) {
            est = acharMtlPelNom("REGULADOR DE VELCRO", 18);

            if (est == NULL) {
                printf("\nSem regulador de velcro no estoque!\n");
                return 0;

            }

            else {
                if (est->quant > quant) {
                    alterValor(novoValor,aux, quant, est);

                }

                else {
                    printf("\nRegulador de velcro insuficiente!\n");
                    return 0;

                }

            }

        }
        
    }

    else {

        if (bcp->codigo[1] == '3') {
            est = acharMtlPelNom("CORDAO", 4);

            if (est == NULL) {
                printf("\nSem cordão no estoque!\n");
                return 0;

            }

            else {
                if (est->quant > quant) {
                    alterValor(novoValor,aux, quant, est);

                }

                else {
                    printf("\nCordão insuficiente!\n");
                    return 0;

                }

            }

        }   

        if (bcp->codigo[2] == '4') {
           est = acharMtlPelNom("PROTECAO", 3);

           if (est == NULL) {
                printf("\nSem proteção no estoque!\n");
                return 0;

            }

            else {
                if (est->quant > quant) {
                    alterValor(novoValor,aux, quant, est);

                }

                else {
                    printf("\nProteção insuficiente!\n");
                    return 0;

                }

            }

        }

    }

    free(est);
    return 1;
}

void acharTec(void) {
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

                if ((est->ativo == 1) && (strncmp("TECIDO", est->nomeDoMaterial, 5) == 0)) {    
                    exibEstoque(est);

                }
            }
            
            free(est);
        }

        fclose(fp);
    }

}

Estoque* acharMtlPelNom(char* nome, int tam) {
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

                if ((est->ativo == 1) && (strncmp(nome, est->nomeDoMaterial, tam) == 0)) {    
                    fclose(fp);
                    return est;

                }
            }
            
        }

        fclose(fp);

    }

    return NULL;

}

int selecionarCor(char *aux, float quant, BoneChap* bcp, float *novoValor, char * cor) {
    Estoque* est;
    int tam;
    char tec[30];
    int num;

    do {

        printf("\nDigite o código da cor desejada: \n");
        fgets(tec, 30, stdin);

        tam = strlen(tec);
        tec[tam - 1] = '\0';

        est = acharEst(tec);

    } while (est == NULL);

    printf("\nTecido escolhido:\n ");

    exibEstoque(est);

    if (((quant / bcp->uniPorMetro) + 1) <= est->quant) {

        novoValor[0] = (est->quant) - ((quant / bcp->uniPorMetro) + 1);
        strcpy(aux, est->codigo);
        strcpy(cor, est->nomeDoMaterial);
    
        num = 1;

    }

    else {
        printf("\nTecido escolhido insuficiente no estoque!\n");
        num = 0;

    }

    free(est);
    return num;

}

void alterValor(float *novoValor, char *aux, int quant, Estoque* est) {
    int i = 0;
    int achou = 0;

    while (i < 6 && achou == 0) {
        
        i = i + 1;
        if (novoValor[i] == -1) {
            achou = 1;
            novoValor[i] = (est->quant) - quant;
            strcat(aux, est->codigo);
        }

    }

}

void salArqPedClt(PedidoCliente* pedClt) {
    FILE *fp;

    fp = fopen("arqPedClt.dat","ab");

    if (fp == NULL) {

        printf("Arquivo inexistente!\n");
        printf("Criando novo arquivo!");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {
            fwrite(pedClt, sizeof(PedidoCliente), 1, fp);

        }

    }

    else {
        fwrite(pedClt, sizeof(PedidoCliente), 1, fp);

    }

    fclose(fp);

}

void lerArqPedClt(void) {
    
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

                exibPedido(pedClt);

            }

            free(pedClt);

        }

        fclose(fp);
    }

}

void exibPedido(PedidoCliente *pedClt) {
    
    printf("\n");
    printf("Número do pedido: ");
    printf("%s" ,pedClt->pedido);
    printf("\n");
    printf("CPF do cliente: ");
    printf("%s" ,pedClt->cpf);
    printf("\n");
    printf("Código do boné: ");
    printf("%s" ,pedClt->codigo);
    printf("\n");
    printf("Quantidade: ");
    printf("%f" ,pedClt->quant);
    printf("\n");
    printf("Cor: ");
    printf("%s" ,pedClt->cor);
    printf("\n");

}

char* gerarIdPed(void) {

    char* data = (char*) malloc(20 * sizeof(char));

    time_t tempo = time(NULL);

    struct tm* t = localtime(&tempo);

    strftime(data, 50, "%d%m%y%H%M%S", t);

    // dia, mes, ano, horas, minutos, segundo

    return data;

}

char escolha(void) {

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Cadastrar modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              1. Boné                                                    ===\n");
    printf("===              2. Chapéu                                                  ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}