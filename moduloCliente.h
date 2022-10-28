
typedef struct cliente Cliente;

struct cliente {

    char nomeDoCliente[100];
    char cpf[12];
    char numero[12];
    char email[100];
    int ativo;

};

//Assinaturas principais

void moduloCliente(void);
char verMenuCliente(void);
void cadastrarCliente(void);
void editarCliente(void);
void excluirCliente(void);
void pesquisarCliente(void);
void pedidoCliente(void);

void validarNomeCliente(void);
void validarCPF(void);
void validarNumeroCelular(void);
void validarEmail(void);