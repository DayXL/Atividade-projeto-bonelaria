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
void cadastrarModelo(char *nomeModelo, char *uniPorMetro, char *uniPorTubo);
void escolhendoModelo(void);

//Assinaturas para validacao
void validarNomeModelo(char *nomeModelo);
void validarUniPorMetro(char *uniPorMetro);
void validarUniPorTubo(char *uniPorTubo);
void telaBone(void);
void telaChapeu(void);
char* validarEsc(char tipo);
int gerarCodigoBone(char *esc, int tam, char num, BoneChap *bcp);
int gerarCodigoChapeu (char *esc, int tam, char num, BoneChap *bcp);
void lerArqBcp(int num);
void exibBoneChap(BoneChap *bcp);
BoneChap* acharMdl(char *codigo);
char telAtlBcp(void);