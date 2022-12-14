typedef struct fornecedor Fornecedor;

struct fornecedor {

    char nomeFornecedor[100];
    char cnpj[15];
    char email[100];
    int ativo;

};

void moduloFornecedor(void);
char verMenuFornecedor(void);
void cadastrarFornecedor(void);
void editarFornecedor(void);
void excluirFornecedor(void);
void pesquisarFornecedor(void);

void validarNomeFornecedor(char *nomeFornecedor);
int validarCnpj(char *cnpj);
void validarEmail2(char *email);
void itens(void);

void salArqFnc(Fornecedor* fnc);
void lerArqFnc(int num);
void exibFornecedor(Fornecedor *fnc);
Fornecedor* acharFnc(char *cnpj);
char telAtlFnc(void);