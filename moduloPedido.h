typedef struct pedidoCliente PedidoCliente;
typedef struct boneChap BoneChap;
typedef struct estoque Estoque;

struct pedidoCliente {

    char pedido[20];
    char cpf[12];
    char codigo[6];
    float quant;
    char cor[30];

};

void moduloPedido(void);
char verMenuPedido(void);
void pedidoCliente(void);
void lerArqBcpDif(char num);
void lerQuant(char *quant);
int verMtlDisp(BoneChap* bcp, float quant, float *novoValor, char *aux);
void acharTec(void);
int selecionarCor(char *aux, float quant, BoneChap* bcp, float *novoValor, char * cor);
Estoque* acharMtlPelNom(char* nome, int tam);
void alterValor(float *novoValor, char *aux, int quant, Estoque* est);
void salArqPedClt(PedidoCliente* pedClt);
void lerArqPedClt(void);
void exibPedido(PedidoCliente *pedClt);
char* gerarIdPed(void);
BoneChap* selecionarModelo(char *codigo);
char escolha(void);


