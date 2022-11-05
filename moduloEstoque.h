typedef struct estoque Estoque;

struct estoque {

    char nomeDoMaterial[100];
    char cnpj[15];
    char quant[10];
    int ativo;

};

void moduloEstoque(void);
char verMenuEstoque(void);
void materiaisEstoque(void);
void pesquisarMateriaisEstoque(void);
void comprarMateriais(void);
void cadastrarMateriais(void);
void excluirMaterial(void);
void validarNomeMaterial(Estoque *est);
void cnpj(Estoque *est);
void validarQuant(Estoque *est);
void salArqEst(Estoque *est);
void lerArqEst(void);
void exibEstoque(Estoque *est);
Estoque* acharEst(char *nome);