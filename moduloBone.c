#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloBone.h"
#include "funcoesAux.h"

typedef struct boneChap BoneChap;

void moduloBone(void) {

    char esc = verMenuBone();

    while (esc!='0') {

        if (esc=='1') {
            escolhendoModelo();

        }

        else if (esc=='2') {
            editarModelo();

        }

        else if (esc=='3') {
            excluirModelo();

        }

        else if (esc=='4') {
            pesquisarModelo();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuBone();
    }

}

void salArqBonChap(BoneChap* bcp) {
    FILE *fp;

    
    fp = fopen("arqBonChap.txt","at");

    if (fp == NULL){
      fp = fopen("arqBonChap.txt","wt");
      printf("Erro com arquivo!");

    }

    else {
        fprintf(fp,bcp->nomeBonChap, "\n");
        fprintf(fp,"\n");

        fprintf(fp,bcp->codigo, "\n");
        fprintf(fp,"\n");

        fprintf(fp,bcp->uniPorMetro, "\n");
        fprintf(fp,"\n");

        fprintf(fp,bcp->uniPorTubo, "\n");
        fprintf(fp,"\n");

        fprintf(fp,bcp->ativo, "\n");
        fprintf(fp,"\n");

    }

    fclose(fp);

}

char verMenuBone(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 = = = = = Menu Boné = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar modelo                                     ===\n");
    printf("===                 2. Editar modelo                                        ===\n");
    printf("===                 3. Excluir modelo                                       ===\n");
    printf("===                 4. Pesquisar modelo                                     ===\n");
    printf("===                 0. Voltar ao menu principal                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void escolhendoModelo(void) {

    char esc = escolherModelo();

    while (esc!='0') {

        if (esc=='1') {
            telaBone();

        }

        else if (esc=='2') {
            telaChapeu();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = escolherModelo();
    }

}

char escolherModelo(void) {

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Cadastrar modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Boné                                                 ===\n");
    printf("===                 2. Chapéu                                               ===\n");
    printf("===                 0. Voltar                                               ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void telaBone(void) {

    BoneChap* bcp;
    bcp = (BoneChap*) malloc(sizeof(BoneChap));

    char *detalhes;
    int tam;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Cadastrar modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 Escolha o que deseja e pressione enter                  ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Botão                                                ===\n");
    printf("===                 2. Tela                                                 ===\n");
    printf("===                 3. Regulador de Fivela                                  ===\n");
    printf("===                 4. Regulador de Velcro                                  ===\n");
    printf("===                 5. Regulador de Plástico                                ===\n");
    printf("===                 6. Sem nada                                             ===\n");
    printf("===                 0. Encerrar                                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    detalhes = validarEsc('1');
    tam = strlen(detalhes);

    gerarCodigoBone(detalhes, tam, '1', bcp);

    cadastrarModelo(bcp);

    strcpy(bcp->ativo, "S");

    salArqBonChap(bcp);

    free(bcp);

}

char* validarEsc(char tipo) {
    int a = 1;
    int tam;
    char aux[5];
    int aux2 = 0;
    char detalhes[4] = "000";
    char *ponDet;

    do {

        do {

            do {

                printf("Escolha: ");
                fgets(aux, 5, stdin);

                if ((aux[0] == '1') && (tipo == '1')) {
                    detalhes[0] = aux[0];
                    printf("Você escolheu Botão!");
                    printf("\n");

                }

                else if ((aux[0] == '1') && (tipo == '0')) {
                    detalhes[0] = aux[0];
                    printf("Você escolheu Cordão!");
                    printf("\n");

                }

                else if ((aux[0] == '2') && (tipo == '1')) {
                    detalhes[1] = aux[0];
                    printf("Você escolheu Tela!");
                    printf("\n");

                }

                else if ((aux[0] == '2') && (tipo == '0')) {
                    detalhes[1] = aux[0];
                    printf("Você escolheu Proteção!");
                    printf("\n");

                }

                else if ((aux[0] == '3') && (tipo == '1')) {
                    detalhes[2] = aux[0];
                    printf("Você escolheu Fivela!");
                    printf("\n");

                }

                else if ((aux[0] == '3') && (tipo == '0')) {
                    detalhes[0] = '3';
                    detalhes[1] = '3';
                    printf("Você escolheu Chapéu normal!");
                    printf("\n");
                    break;

                }

                else if (aux[0] == '4') {
                    detalhes[2] = aux[0];
                    printf("Você escolheu Velcro!");
                    printf("\n");

                }

                else if (aux[0] == '5') {
                    detalhes[2] = aux[0];
                    printf("Você escolheu Plástico!");
                    printf("\n");

                }

                else if (aux[0] == '6') {
                    detalhes[0] = '6';
                    detalhes[1] = '6';
                    detalhes[2] = '6';

                    printf("Você escolheu boné todo liso!");
                    printf("\n");
                    break;

                }

                else if (aux[0] == '0') {
                    printf("Encerrando escolha!");
                    printf("\n");
                    break;

                }

                else {
                    printf("Você digitou algo inválido!");
                    printf("\n");
                }

                aux2 = aux2 + 1;

            } while (aux2 < 9);

            tam = strlen(detalhes);
            detalhes[tam - 1] = '\0';

        } while ((tam == 1) || !validarNumInteiro(detalhes));


        if (tipo == '1') {
            int i = 0;

            while (detalhes[i] != '\0') {
                a = ((detalhes[i] >= '1') && (detalhes[i] <= '6')) ? 0 : 1;

                i = i + 1;

            }

        }

        else {
            int i = 0;

            while ((detalhes[i] != '\0') && (a == 1)) {
                a = ((detalhes[i] >= '1') && (detalhes[i] <= '3')) ? 0 : 1;

                i = i + 1;

            }

        }

    } while (a);

    //Reservando o espaço necessário para armazenar no ponteiro
    ponDet = (char*) malloc((tam + 1) * sizeof(char));

    //Colocando oq quero no ponteiro
    strcpy(ponDet, detalhes);

    return ponDet;

}

void gerarCodigoBone(char *esc, int tam, char num, BoneChap *bcp) {
    char codigo[6];

    codigo[0] = num;

    for (int i = 1; i < 5; i++) {
        codigo[i] = '0';

    }

    for (int i = 0; i < tam; i++) {
        if (esc[i] == '1') {
            codigo[1] = '1';

        }

        else if (esc[i] == '2') {
            codigo[2] = '1';

        }

        else if (esc[i] == '3') {
            codigo[3]= '0';
            codigo[4]= '1';

        }

        else if (esc[i] == '4') {
            codigo[3]= '1';
            codigo[4]= '0';

        }

        else if (esc[i] == '5') {
            codigo[3]= '1';
            codigo[4]= '1';

        }

    }

    printf("Código do Boné:\n");
    printf("%s", codigo);
    printf("\n");

    strcpy(bcp->codigo,codigo);
}

void telaChapeu(void) {

    BoneChap* bcp;
    bcp = (BoneChap*) malloc(sizeof(BoneChap));

    char *detalhes;
    int tam;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Cadastrar modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 Escolha o que deseja e pressione enter                  ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cordão                                               ===\n");
    printf("===                 2. Proteção                                             ===\n");
    printf("===                 3. Sem nada                                             ===\n");
    printf("===                 0. Encerrar                                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    detalhes = validarEsc('0');
    tam = strlen(detalhes);

    gerarCodigoChapeu(detalhes, tam, '0',bcp);

    cadastrarModelo(bcp);

    strcpy(bcp->ativo, "S");

    salArqBonChap(bcp);

    free(bcp);
}

void gerarCodigoChapeu (char *esc, int tam, char num, BoneChap *bcp) {
    char codigo[4];

    codigo[0] = num;

    for (int i = 1; i < 3; i++) {
        codigo[i] = '0';

    }

    for (int i = 0; i < tam; i++) {
        if (esc[i] == '1') {
            codigo[1] = '1';

        }

        else if (esc[i] == '2') {
            codigo[2] = '1';

        }

    }

    printf("Código do Chapéu:\n");
    printf("%s", codigo);
    printf("\n");

    strcpy(bcp->codigo,codigo);
}

void cadastrarModelo(BoneChap *bcp) {
    
    validarNomeModelo(bcp);

    validarUniPorMetro(bcp);

    validarUniPorTubo(bcp);
}

void validarNomeModelo(BoneChap *bcp) {
    int tam;
    char nomeModelo[11];

    do {

        printf("Nome do modelo: ");
        fgets(nomeModelo, 11, stdin);

        tam = strlen(nomeModelo);
        nomeModelo[tam - 1] = '\0';

    } while ((tam == 1) || !(validarPalavra(nomeModelo))); 

    strcpy(bcp->nomeBonChap, nomeModelo);
}

void validarUniPorMetro(BoneChap *bcp) {
    int tam;
    char uniPorMetro[3];

    do {

        printf("Unidades por metro de tecido: ");
        fgets(uniPorMetro, 3, stdin);

        tam = strlen(uniPorMetro);
        uniPorMetro[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(uniPorMetro)));

    strcpy(bcp->uniPorMetro, uniPorMetro);

}

void validarUniPorTubo(BoneChap *bcp) {
    int tam;
    char uniPorTubo[3];

    do {

        printf("Unidades por tubo de linha: ");
        fgets(uniPorTubo, 3, stdin);

        tam = strlen(uniPorTubo);
        uniPorTubo[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(uniPorTubo))); 

    strcpy(bcp->uniPorTubo, uniPorTubo);
}

void editarModelo(void) {

    char nomeModelo[11];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Editar modelo = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    printf("Nome do modelo: ");
    fgets(nomeModelo, 11, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void excluirModelo(void) {

    char nomeModelo[11];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    printf("Nome do modelo: ");
    fgets(nomeModelo, 11, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void pesquisarModelo(void) {

    char nomeModelo[11];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Pesquisar modelo = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    
    printf("Nome do modelo: ");
    fgets(nomeModelo, 11, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}
