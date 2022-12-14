typedef struct estoque Estoque;

struct estoque {

    char nomeDoMaterial[100];
    char codigo[9];
    char cnpj[15];
    float quant;
    int ativo;

};

void moduloEstoque(void);
char verMenuEstoque(void);
void materiaisEstoque(void);
void pesquisarMateriaisEstoque(void);
void comprarMateriais(void);
void cadastrarMateriais(void);
void excluirMaterial(void);
void editarMaterial(void);
int lerCodMat(char *codigo);
void validarNomeMaterial(char *nomeMaterial);
int lerCnpjEst(char *cnpj);
void validarQuant(char *quant);
void salArqEst(Estoque *est);
void lerArqEst(int num);
void exibEstoque(Estoque *est);
Estoque* acharEst(char *nome);
char telAtlEst(void);
void descontarMtl(char *codigo, float quant);