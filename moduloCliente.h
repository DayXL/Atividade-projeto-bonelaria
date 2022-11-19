
typedef struct cliente Cliente;
typedef struct boneChap BoneChap;
typedef struct estoque Estoque;

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

void validarNomeCliente(char *nomeCliente);
int validarCPF(char *cpf);
void validarNumeroCelular(char *numero);
void validarEmail(char *email);
void salArqClt(Cliente* clt);
void lerArqClt(int num);
void exibCliente(Cliente *clt);
Cliente* acharClt(char *cpf);
char telAtlClt(void);