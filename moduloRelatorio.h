typedef struct clienteDin ClienteDin;
typedef struct estoqueDin EstoqueDin;

struct clienteDin {

    char* nomeDoCliente;
    char* cpf;
    char* numero;
    char* email;
    ClienteDin* prox;

};

struct estoqueDin {

    char* nomeDoMaterial;
    char* codigo;
    char* cnpj;
    float quant;
    EstoqueDin* prox;

};

void moduloRelatorio(void);
char verMenuRelatorio(void);
void relatorioPedido(void);
void controleRelClt(void);
char verMenReltClt(void);
void arqCltOrdAlf(void);
void exibCltDin(ClienteDin *clt);
void lerArqBncp(char num);
void controleRelMdl(void);
char verMenReltMdl(void);
void controleRelEst(void);
char verMenReltEst(void);
void arqEstMaMe(int num);
void arqEstOrdAlf(void);
void exibEstDin(EstoqueDin *est);
void controleRelFnc(void);
char verMenReltFnc(void);