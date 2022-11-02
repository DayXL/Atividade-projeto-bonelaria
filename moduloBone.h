typedef struct boneChap BoneChap;

struct boneChap {

    char nomeBonChap[100];
    char codigo[6];
    char uniPorMetro[3];
    char uniPorTubo[3];
    int ativo;

};

//Assinatura das funções do módulo de bonés

//Assinaturas principais
void moduloBone(void);
char verMenuBone(void);
char escolherModelo(void);
void editarModelo(void);
void excluirModelo(void);
void pesquisarModelo(void);
void cadastrarModelo(BoneChap *bcp);
void escolhendoModelo(void);

//Assinaturas para validacao
void validarNomeModelo(BoneChap *bcp);
void validarUniPorMetro(BoneChap *bcp);
void validarUniPorTubo(BoneChap *bcp);
void telaBone(void);
void telaChapeu(void);
char* validarEsc(char tipo);
void gerarCodigoBone(char *esc, int tam, char num, BoneChap *bcp);
void gerarCodigoChapeu (char *esc, int tam, char num, BoneChap *bcp);
void lerArqBcp(void);
void exibBoneChap(BoneChap *bcp);
