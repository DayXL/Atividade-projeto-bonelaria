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
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    validarEsc();
    
}

void validarEsc(void) {
    int a = 0;
    int tam;
    char detalhes[10];

    while (a == 0) {

        printf("Escolha: ");
        fgets(detalhes, 10, stdin);

        tam = strlen(detalhes);
        detalhes[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarNumInteiro(detalhes));

    }

}

void gerarCodigoBone(char *esc, int tam) {
    

}

void telaChapeu(void) {

    char detalhes[20];

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
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    printf("Escolha: ");
    fgets(detalhes, 20, stdin);


}

void cadastrarModelo(void) {

    validarNomeModelo();

    validarUniPorMetro();

    validarUniPorTubo();
}

void validarNomeModelo(void) {
    int a = 0;
    int tam;
    char nomeModelo[11];

    while (a == 0) {

        printf("Nome do modelo: ");
        fgets(nomeModelo, 11, stdin);

        tam = strlen(nomeModelo);
        nomeModelo[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarPalavra(nomeModelo));

    }

}

void validarUniPorMetro(void) {
    int a = 0;
    int tam;
    char uniPorMetro[3];

    while (a == 0) {

        printf("Unidades por metro de tecido: ");
        fgets(uniPorMetro, 3, stdin);

        tam = strlen(uniPorMetro);
        uniPorMetro[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarNumInteiro(uniPorMetro));

    }

}

void validarUniPorTubo(void) {
    int a = 0;
    int tam;
    char uniPorTubo[3];

    while (a == 0) {

        printf("Unidades por tubo de linha: ");
        fgets(uniPorTubo, 3, stdin);

        tam = strlen(uniPorTubo);
        uniPorTubo[tam - 1] = '\0';

        a = (tam == 1) ? 0 : (validarNumInteiro(uniPorTubo));

    }

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

