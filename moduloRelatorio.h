typedef struct clienteDin ClienteDin;

struct clienteDin {

    char* nomeDoCliente;
    char* cpf;
    char* numero;
    char* email;
    int ativo;
    ClienteDin* prox;

};

void moduloRelatorio(void);
char verMenuRelatorio(void);
void relatorioBone(void);
void relatorioFornecedor(void);
void relatorioEstoque(void);
void relatorioPedido(void);
void controleRelClt(void);
char verMenReltClt(void);
void arqCltOrdAlf(void);
void exibCltDin(ClienteDin *clt);