#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloBone.h"
#include "funcoesAux.h"

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
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    detalhes = validarEsc('1');
    tam = strlen(detalhes);

    gerarCodigoBone(detalhes, tam, '1');

    cadastrarModelo();

}

char* validarEsc(char tipo) {
    int a = 1;
    int tam;
    char detalhes[10];
    char *ponDet;

    do {


        do {

            printf("Escolha: ");
            fgets(detalhes, 10, stdin);

            tam = strlen(detalhes);
            detalhes[tam - 1] = '\0';

        } while (((tam == 1) || (tam > 4)) || !validarNumInteiro(detalhes));


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

void gerarCodigoBone(char *esc, int tam, char num) {
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

}

void telaChapeu(void) {

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
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    detalhes = validarEsc('0');
    tam = strlen(detalhes);

    gerarCodigoChapeu(detalhes, tam, '0');

    cadastrarModelo();

}

void gerarCodigoChapeu (char *esc, int tam, char num) {
    char codigo[3];

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

}

void cadastrarModelo(void) {

    validarNomeModelo();

    validarUniPorMetro();

    validarUniPorTubo();
}

void validarNomeModelo(void) {
    int tam;
    char nomeModelo[11];

    do {

        printf("Nome do modelo: ");
        fgets(nomeModelo, 11, stdin);

        tam = strlen(nomeModelo);
        nomeModelo[tam - 1] = '\0';

    } while ((tam == 1) || !(validarPalavra(nomeModelo))); 

}

void validarUniPorMetro(void) {
    int tam;
    char uniPorMetro[3];

    do {

        printf("Unidades por metro de tecido: ");
        fgets(uniPorMetro, 3, stdin);

        tam = strlen(uniPorMetro);
        uniPorMetro[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(uniPorMetro)));

}

void validarUniPorTubo(void) {
    int tam;
    char uniPorTubo[3];

    do {

        printf("Unidades por tubo de linha: ");
        fgets(uniPorTubo, 3, stdin);

        tam = strlen(uniPorTubo);
        uniPorTubo[tam - 1] = '\0';


    } while ((tam == 1) || !(validarNumInteiro(uniPorTubo))); 

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

