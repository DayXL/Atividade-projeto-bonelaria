#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

    fp = fopen("arqBoneChap.dat","ab");

    if (fp == NULL){

        printf("Arquivo inexistente!\n");
        printf("Criando novo arquivo!");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

        else {
            fwrite(bcp, sizeof(BoneChap), 1, fp);

        }

    }

    else {
        fwrite(bcp, sizeof(BoneChap), 1, fp);

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
    printf("===============================================================================\n");
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
    printf("===              1. Boné                                                    ===\n");
    printf("===              2. Chapéu                                                  ===\n");
    printf("===              0. Voltar                                                  ===\n");
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

    char detalhes[4] = "000";
    int tam;
    int jaCad;
    char nomeModelo[100];
    char uniPorMetro[20];
    char uniPorTubo[20];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Cadastrar modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              Escolha o que deseja e pressione enter                     ===\n");
    printf("===                                                                         ===\n");
    printf("===              1. Botão                                                   ===\n");
    printf("===              2. Tela                                                    ===\n");
    printf("===              3. Regulador de Fivela                                     ===\n");
    printf("===              4. Regulador de Plástico                                   ===\n");
    printf("===              5. Regulador de Velcro                                     ===\n");
    printf("===              6. Sem nada                                                ===\n");
    printf("===              0. Encerrar                                                ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    validarEsc('1', detalhes);
    tam = strlen(detalhes);

    jaCad = gerarCodigoBone(detalhes, tam, '1', bcp);

    if (jaCad == 1) {
        printf("\nBoné já cadastrado!\n");

    }

    else {
        cadastrarModelo(nomeModelo,uniPorMetro,uniPorTubo);

        char* nomeMais = pasMaisc(nomeModelo);

        strcpy(bcp->nomeBonChap, nomeMais);
        bcp->uniPorMetro = atof(uniPorMetro);
        bcp->uniPorTubo = atof(uniPorTubo);
        bcp->ativo = 1;

        free(nomeMais);
        salArqBonChap(bcp);

        printf("Boné cadastrado com sucesso!");
    }

    free(bcp);

}

void lerArqBcp(int num) {
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

                if (bcp->ativo == num) {   
                    exibBoneChap(bcp);

                }
            }
            free(bcp);

        }

        fclose(fp);
    }

}

BoneChap* acharMdl(char *codigo) {
    FILE* fp;
    BoneChap* bcp;

    if (access("arqBoneChap.dat", F_OK) != -1) {
        fp = fopen("arqBoneChap.dat", "rb");

        if (fp == NULL) {
            printf("Ocorreu um erro na abertura do arquivo!\n");

        }

        else {

            bcp = (BoneChap*) malloc(sizeof(BoneChap));

            while(fread(bcp, sizeof(BoneChap), 1, fp)) {

                if ((strcmp(bcp->codigo, codigo) == 0) && (bcp->ativo != 0)) {
                    fclose(fp);
                    return bcp;

                } 

            }

        }

        fclose(fp);
    }

    return NULL;
}

void exibBoneChap(BoneChap *bcp) {
    
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

void validarEsc(char tipo, char *detalhes) {
    int tam;
    char aux[5];

    do {

        printf("Escolha: ");
        fgets(aux, 5, stdin);

        tam = strlen(aux);
        aux[tam - 1] = '\0';

        if ((strcmp(aux, "1\0") == 0) && (tipo == '1')) {
            detalhes[0] = aux[0];
            printf("Você escolheu Botão!");
            printf("\n");

        }

        else if ((strcmp(aux, "1\0") == 0) && (tipo == '0')) {
            detalhes[0] = aux[0];
            printf("Você escolheu Cordão!");
            printf("\n");

        }

        else if ((strcmp(aux, "2\0") == 0) && (tipo == '1')) {
            detalhes[1] = aux[0];
            printf("Você escolheu Tela!");
            printf("\n");

        }

        else if ((strcmp(aux, "2\0") == 0) && (tipo == '0')) {
            detalhes[1] = aux[0];
            printf("Você escolheu Proteção!");
            printf("\n");

        }

        else if ((strcmp(aux, "3\0") == 0) && (tipo == '1')) {
            detalhes[2] = aux[0];
            printf("Você escolheu Fivela!");
            printf("\n");

        }

        else if ((strcmp(aux, "3\0") == 0) && (tipo == '0')) {
            detalhes[0] = '3';
            detalhes[1] = '3';
            printf("Você escolheu Chapéu normal!");
            printf("\n");

        }

        else if ((strcmp(aux, "4\0") == 0)) {
            detalhes[2] = aux[0];
            printf("Você escolheu Velcro!");
            printf("\n");

        }

        else if ((strcmp(aux, "5\0") == 0)) {
            detalhes[2] = aux[0];
            printf("Você escolheu Plástico!");
            printf("\n");

        }

        else if ((strcmp(aux, "6\0") == 0)) {
            detalhes[0] = '6';
            detalhes[1] = '6';
            detalhes[2] = '6';

            printf("Você escolheu boné todo liso!");
            printf("\n");

        }

        else {
            printf("Você digitou algo inválido!");
            printf("\n");
        }

    } while (aux[0] != '0');

}

int gerarCodigoBone(char *esc, int tam, char num, BoneChap *bcp) {
    char codigo[6];
    BoneChap* aux;

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
            printf("a");
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

    aux = acharMdl(codigo);

    if (aux != NULL) {
        return 1;

    }

    else {
        printf("Código do Boné:\n");
        printf("%s", codigo);
        printf("\n");

        strcpy(bcp->codigo,codigo);
    }

    return 0;
}

void telaChapeu(void) {

    BoneChap* bcp;
    bcp = (BoneChap*) malloc(sizeof(BoneChap));

    char detalhes[4] = "000";
    int tam;
    int jaCad;
    char nomeModelo[100];
    char uniPorMetro[20];
    char uniPorTubo[20];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Cadastrar modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              Escolha o que deseja e pressione enter                     ===\n");
    printf("===                                                                         ===\n");
    printf("===              1. Cordão                                                  ===\n");
    printf("===              2. Proteção                                                ===\n");
    printf("===              3. Sem nada                                                ===\n");
    printf("===              0. Encerrar                                                ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    validarEsc('0', detalhes);
    tam = strlen(detalhes);

    jaCad = gerarCodigoChapeu(detalhes, tam, '0',bcp);

    if (jaCad == 1) {
        printf("\nChapéu já cadastrado!\n");

    }

    else {
        cadastrarModelo(nomeModelo,uniPorMetro,uniPorTubo);
        
        char* nomeMais = pasMaisc(nomeModelo);

        strcpy(bcp->nomeBonChap, nomeMais);
        bcp->uniPorMetro = atof(uniPorMetro);
        bcp->uniPorTubo = atof(uniPorTubo);
        bcp->ativo = 1;

        free(nomeMais);
        salArqBonChap(bcp);

        printf("\nChapéu cadastrado com sucesso!\n");
    }

    free(bcp);
}

int gerarCodigoChapeu (char *esc, int tam, char num, BoneChap *bcp) {
    char codigo[6];
    BoneChap* aux;

    codigo[0] = num;

    for (int i = 1; i < 5; i++) {
        codigo[i] = '0';

    }

    for (int i = 0; i < tam; i++) {
        if (esc[i] == '1') {
            codigo[4] = '1';

        }

        else if (esc[i] == '2') {
            codigo[5] = '1';

        }

    }

    aux = acharMdl(codigo);

    if (aux != NULL) {
        return 1;

    }

    else {

        printf("Código do Chapéu:\n");
        printf("%s", codigo);
        printf("\n");

        strcpy(bcp->codigo,codigo);
    }

    return 0;
}

void cadastrarModelo(char *nomeModelo, char *uniPorMetro, char *uniPorTubo) {
    
    validarNomeModelo(nomeModelo);

    validarUniPorMetro(uniPorMetro);

    validarUniPorTubo(uniPorTubo);
}

void validarNomeModelo(char *nomeModelo) {
    int tam;

    do {

        printf("Nome do modelo: ");
        fgets(nomeModelo, 100, stdin);

        tam = strlen(nomeModelo);
        nomeModelo[tam - 1] = '\0';

    } while ((tam == 1) || !(validarPalavra(nomeModelo))); 

}

void validarUniPorMetro(char *uniPorMetro) {
    int tam;

    do {

        printf("Unidades por metro de tecido: ");
        fgets(uniPorMetro, 20, stdin);

        tam = strlen(uniPorMetro);
        uniPorMetro[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(uniPorMetro)));

}

void validarUniPorTubo(char *uniPorTubo) {
    int tam;

    do {

        printf("Unidades por tubo de linha: ");
        fgets(uniPorTubo, 20, stdin);

        tam = strlen(uniPorTubo);
        uniPorTubo[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(uniPorTubo))); 

}

void editarModelo(void) {
    FILE* fp;
    BoneChap* bcp;
    BoneChap* aux;
    char codigo[30];
    int tam;
    char aux2[20];
    int achou = 0;
    char nomeModelo[100];
    char uniPorMetro[30];
    char uniPorTubo[30];
    char esc;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Editar modelo = = = = =                        ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    printf("Código do modelo: ");
    fgets(codigo, 30, stdin);

    tam = strlen(codigo);
    codigo[tam - 1] = '\0';

    bcp = acharMdl(codigo);
     
    if (bcp == NULL) {

        printf("\nModelo não cadastrado!\n");

    }

    else {

        if (access("arqBoneChap.dat", F_OK) != -1) {

            aux = (BoneChap*) malloc(sizeof(BoneChap));
            fp = fopen("arqBoneChap.dat", "r+b");

            if (fp == NULL) {
                printf("Não foi possível atualizar!\n");
                
            }

            else {

                while(fread(aux, sizeof(BoneChap), 1, fp) && (achou == 0)) {

                    if ((strcmp(aux->codigo, codigo) == 0) && (aux->ativo != 0)) {
                        achou = 1;
                        exibBoneChap(aux);

                        printf("\nDeseja realmente atualizar?1 para sim, 0 para não.\n");
                        fgets(aux2, 20, stdin);
                        
                        tam = strlen(aux2);
                        aux2[tam - 1] = '\0';

                        if (strcmp(aux2, "1\0") == 0) {

                            esc = telAtlBcp();

                            while (esc!='0') {

                                if (esc=='1') {
                                    validarNomeModelo(nomeModelo);

                                    char* nomeMais = pasMaisc(nomeModelo);
                                    strcpy(aux->nomeBonChap,nomeMais);
                                    free(nomeMais);

                                }

                                else if (esc=='2') {
                                    validarUniPorMetro(uniPorMetro);
                                    aux->uniPorMetro = atof(uniPorMetro);

                                }

                                else if (esc=='3') {
                                    validarUniPorTubo(uniPorTubo);
                                    aux->uniPorTubo= atof(uniPorTubo);

                                }

                                else if (esc=='4') {
                                    validarNomeModelo(nomeModelo);

                                    validarUniPorMetro(uniPorMetro);

                                    validarUniPorTubo(uniPorTubo);

                                    char* nomeMais = pasMaisc(nomeModelo);

                                    strcpy(aux->nomeBonChap,nomeMais);
                                    aux->uniPorMetro = atof(uniPorMetro);
                                    aux->uniPorTubo= atof(uniPorTubo); 
                                    free(nomeMais);
                                }

                                else {
                                    printf("Opção inválida!\n");
                                
                                }

                                esc = telAtlBcp();
                            }
  
                            fseek(fp, -1*sizeof(BoneChap), SEEK_CUR);
                            fwrite(aux, sizeof(BoneChap), 1, fp);

                            printf("\nModelo atualizado com sucesso!\n");
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


    free(bcp);

}

char telAtlBcp(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                 = = = = = Atualizar = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Nome                                                 ===\n");
    printf("===                 2. Unidade por metro                                    ===\n");
    printf("===                 3. Unidades por tubo                                    ===\n");
    printf("===                 4. Atualizar tudo                                       ===\n");
    printf("===                 0. Sair                                                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void excluirModelo(void) {

    FILE* fp;
    BoneChap* bcp;
    BoneChap* aux;
    char codigo[30];
    int tam;
    char aux2[20];
    int achou = 0;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir modelo = = = = =                       ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");

    printf("Código do modelo: ");
    fgets(codigo, 30, stdin);

    tam = strlen(codigo);
    codigo[tam - 1] = '\0';

    bcp = acharMdl(codigo);
     
    if (bcp == NULL) {

        printf("Modelo não cadastrado! ");

    }

    else {

        if (access("arqBoneChap.dat", F_OK) != -1) {

            aux = (BoneChap*) malloc(sizeof(BoneChap));
            fp = fopen("arqBoneChap.dat", "r+b");

            if (fp == NULL) {
                printf("Não foi possível deletar!\n");

            }

            else {

                while(fread(aux, sizeof(BoneChap), 1, fp) && (achou == 0)) {

                    if ((strcmp(aux->codigo, codigo) == 0) && (aux->ativo != 0)) {

                        achou = 1;
                        exibBoneChap(aux);

                        printf("\nDeseja realmente deletar?1 para sim, 0 para não.\n");
                        fgets(aux2, 20, stdin);
                        
                        tam = strlen(aux2);
                        aux2[tam - 1] = '\0';

                        if (strcmp(aux2, "1\0") == 0) {
                            aux->ativo = 0;

                            fseek(fp, -1*sizeof(BoneChap), SEEK_CUR);
                            fwrite(aux, sizeof(BoneChap), 1, fp);

                            printf("\nModelo excluído com sucesso!\n");
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

    free(bcp);
}

void pesquisarModelo(void) {

    BoneChap* bcp;
    char codigo[30];
    int tam;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Pesquisar modelo = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    
    printf("Código do modelo: ");
    fgets(codigo, 30, stdin);

    tam = strlen(codigo);
    codigo[tam - 1] = '\0';

    bcp = acharMdl(codigo);
     
    if (bcp == NULL) {
        printf("Modelo não cadastrado! ");

    }

    else {
        exibBoneChap(bcp);

    }

    free(bcp);

}
