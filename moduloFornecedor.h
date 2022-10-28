typedef struct fornecedor Fornecedor;

struct fornecedor {

    char nomeFornecedor[100];
    char cnpj[15];
    char email[100];
    char ativo[2];

};

void moduloFornecedor(void);
char verMenuFornecedor(void);
void cadastrarFornecedor(void);
void editarFornecedor(void);
void excluirFornecedor(void);
void pesquisarFornecedor(void);

void validarNomeFornecedor(void);
void validarCnpj(void);
void validarEmail2(void);
void itens(void);