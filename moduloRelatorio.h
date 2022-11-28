typedef struct clienteDin ClienteDin;
typedef struct estoqueDin EstoqueDin;
typedef struct fornecedorDin FornecedorDin;
typedef struct pedidoClienteDin PedidoClienteDin;
typedef struct boneChapDin BoneChapDin;

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

struct fornecedorDin {

    char* nomeFornecedor;
    char* cnpj;
    char *email;
    FornecedorDin* prox;

};

struct pedidoClienteDin {

    char* pedido;
    char* cpf;
    char* codigo;
    float quant;
    char* cor;
    PedidoClienteDin* prox;

};

struct boneChapDin {

    char* nomeBonChap;
    char* codigo;
    float uniPorMetro;
    float uniPorTubo;
    BoneChapDin* prox;

};

void moduloRelatorio(void);
char verMenuRelatorio(void);
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
void arqFncOrdAlf(void);
void exibFncDin(FornecedorDin *fnc);
void controleRelPed(void);
char verMenReltPed(void);
void arqPedMaMe(int num);
void exibPedDin(PedidoClienteDin *pedClt);
void arqPedPorClt (void);
void acharPedClt(char *cpf);
void arqMdlMaMe(int num);
void exibBcpDin(BoneChapDin *bcp); 
void arqEstPorFnc (void);
void acharEstFnc(char *cnpj);