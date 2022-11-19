
typedef struct cliente Cliente;
typedef struct pedidoCliente PedidoCliente;
typedef struct boneChap BoneChap;
typedef struct estoque Estoque;

struct cliente {

    char nomeDoCliente[100];
    char cpf[12];
    char numero[12];
    char email[100];
    int ativo;

};

struct pedidoCliente {

    int pedido;
    char cpf[12];
    char codigo[6];
    float quant;
    char cor[30];

};

//Assinaturas principais

void moduloCliente(void);
char verMenuCliente(void);
void cadastrarCliente(void);
void editarCliente(void);
void excluirCliente(void);
void pesquisarCliente(void);
void pedidoCliente(void);

void validarNomeCliente(char *nomeCliente);
int validarCPF(char *cpf);
void validarNumeroCelular(char *numero);
void validarEmail(char *email);
void salArqClt(Cliente* clt);
void lerArqClt(int num);
void exibCliente(Cliente *clt);
Cliente* acharClt(char *cpf);
char telAtlClt(void);
BoneChap* selecionarModelo(char *codigo);
void lerArqBcpDif(char num);
void lerQuant(char *quant);
int verMtlDisp(BoneChap* bcp, float quant, float *novoValor, char *aux);
void acharTec(void);
int selecionarCor(char *aux, float quant, BoneChap* bcp, float *novoValor, char * cor);
Estoque* acharMtlPelNom(char* nome, int tam);
void alterValor(float *novoValor, char *aux, int quant, Estoque* est);
void salArqPedClt(PedidoCliente* pedClt);