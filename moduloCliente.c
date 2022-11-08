#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloCliente.h"
#include "funcoesAux.h"

typedef struct cliente Cliente;

void moduloCliente(void) {

    char esc = verMenuCliente();

    while (esc!='0') {

        if (esc=='1') {
            cadastrarCliente();

        }

        else if (esc=='2') {
            editarCliente();

        }

        else if (esc=='3') {
            excluirCliente();

        }

        else if (esc=='4') {
            pesquisarCliente();

        }

        else if (esc=='5') {
            pedidoCliente();

        }

        else {
            printf("Opção inválida!\n");
        
        }

        passarEnter();

        esc = verMenuCliente();
    }

}

char verMenuCliente(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Menu Cliente = = = = =                           ===\n");
    printf("===                                                                         ===\n");
    printf("===                 1. Cadastrar cliente                                    ===\n");
    printf("===                 2. Editar cliente                                       ===\n");
    printf("===                 3. Excluir cliente                                      ===\n");
    printf("===                 4. Pesquisar cliente                                    ===\n");
    printf("===                 5. Fechar pedido para cliente                           ===\n");
    printf("===                 0. Voltar ao menu principal                             ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

    char esc;
    esc = auxEscolha();

    return esc;

}

void salArqClt(Cliente* clt) {
    FILE *fp;

    fp = fopen("arqCliente.dat","ab");

    if (fp == NULL){

      fp = fopen("arqCliente.dat","wb");
      printf("Arquivo inexistente!\n");
      printf("Criando novo arquivo!");

      if (fp == NULL) {
        printf("Erro com arquivo!");

      }

      else {
        fwrite(clt, sizeof(Cliente), 1, fp);

      }

    }

    else {
        fwrite(clt, sizeof(Cliente), 1, fp);

    }

    fclose(fp);

}

void lerArqClt(void) {
    FILE *fp;
    Cliente *clt;
    clt = (Cliente*) malloc(sizeof(Cliente));

    fp = fopen("arqCliente.dat","rb");

    if (fp == NULL) {

        fp = fopen("arqCliente.dat","wb");
        printf("Arquivo inexistente!\n");
        printf("Criando novo arquivo!");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

    }

    else {

        while (fread(clt, sizeof(Cliente), 1, fp)) {

            if (clt->ativo != 0) {
                
                exibCliente(clt);


            }
        }
    }

    free(clt);
    fclose(fp);

}

Cliente* acharClt(char *cpf) {
    FILE* fp;
    Cliente* clt;

    clt = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("arqCliente.dat", "rb");

    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");

    }


    else {

        while(!feof(fp)) {
            fread(clt, sizeof(Cliente), 1, fp);

            if (strcmp(clt->cpf, cpf) == 0) {

                if (clt->ativo != 0) {
                    fclose(fp);
                    return clt;
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

void exibCliente(Cliente *clt) {
    
    printf("\n");
    printf("Nome do Cliente: ");
    printf("%s" ,clt->nomeDoCliente);
    printf("\n");
    printf("CPF: ");
    printf("%s" ,clt->cpf);
    printf("\n");
    printf("Número: ");
    printf("%s" ,clt->numero);
    printf("\n");
    printf("Email: ");
    printf("%s" ,clt->email);
    printf("\n");

}

void cadastrarCliente(void) {

    Cliente* clt;
    clt = (Cliente*) malloc(sizeof(Cliente));

    char nomeCliente[100];
    char cpf[30];
    char numero[30];
    char email[100];
    int jaCad;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Cadastrar cliente = = = = =                     ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    
    gerarCpf();

    printf("\n");

    jaCad = validarCPF(cpf);
    
    if (jaCad == 1) {
        printf("\nCliente já cadastrado!\n");

    }

    else {

        validarNomeCliente(nomeCliente);

        validarNumeroCelular(numero);

        validarEmail(email);

        strcpy(clt->nomeDoCliente,nomeCliente);
        strcpy(clt->cpf,cpf);
        strcpy(clt->numero,numero);
        strcpy(clt->email,email);
        clt->ativo = 1;

        salArqClt(clt);

        printf("\nCliente cadastrado com sucesso!\n");
    }

    printf("\n===============================================================================\n");
    printf("\n");

    free(clt);
    
}

void validarNomeCliente(char *nomeCliente) {
    int tam;

    do {

        printf("Nome do cliente: ");
        fgets(nomeCliente, 100, stdin);

        tam = strlen(nomeCliente);
        nomeCliente[tam - 1] = '\0';

    } while ((tam == 1) || !(validarPalavra(nomeCliente))); 

}

int validarCPF(char *cpf) {
    int tam;
    Cliente* clt;

    do {

        do {

            printf("CPF(somente números): ");
            fgets(cpf, 30, stdin);

            tam = strlen(cpf);
            cpf[tam - 1] = '\0';

            clt = acharClt(cpf);

            if (clt != NULL) {

                free(clt);

                return 1;

            }

        } while ((tam != 12) || !validarNumInteiro(cpf));

    } while (!verificarCpf(cpf));

    printf(" ");
    printf("CPF válido!\n");

    return 0;
}

void validarNumeroCelular(char *numero) {
    int tam;

    do {

        printf("Número de celular(somente números): ");
        fgets(numero, 30, stdin);

        tam = strlen(numero);
        numero[tam - 1] = '\0';

    } while ((tam != 12) || !validarNumInteiro(numero));

} 

void validarEmail(char *email) {
    int tam;

    do {

        printf("Email: ");
        fgets(email, 100, stdin);

        tam = strlen(email);
        email[tam - 1] = '\0';

    } while ((tam == 1) || !verificarEmail(email, tam));

}

void editarCliente(void) {

    char cpf[13];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Editar cliente = = = = =                         ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CPF do cliente: ");
    fgets(cpf, 13, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void excluirCliente(void) {

    char cpf[13];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===                = = = = = Excluir cliente = = = = =                      ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CPF do cliente: ");
    fgets(cpf, 13, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}

void pesquisarCliente(void) {
    Cliente* clt;
    char cpf[50];
    int tam;

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Pesquisar cliente = = = = =                     ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");

    printf("CPF do cliente: ");
    fgets(cpf, 50, stdin);

    tam = strlen(cpf);
    cpf[tam - 1] = '\0';

    clt = acharClt(cpf);
     
    if (clt == NULL) {
        printf("Cliente não cadastrado! ");

    }

    else {
        exibCliente(clt);

    }

    free(clt);

}

void pedidoCliente(void) {

    char nomeCliente[100];
    char cpf[13];
    char nomeModelo[11];
    char quantidade[11];

    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===               = = = = = Fechar pedido = = = = =                         ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");


    printf("Nome do cliente: ");
    fgets(nomeCliente, 100, stdin);

    printf("CPF(somente números): ");
    fgets(cpf, 13, stdin);

    printf("Nome do modelo: ");
    fgets(nomeModelo, 11, stdin);

    printf("Quantidade: ");
    fgets(quantidade, 11, stdin);

    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");

}