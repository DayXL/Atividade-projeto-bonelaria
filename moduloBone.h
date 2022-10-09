//Assinatura das funções do módulo de bonés

//Assinaturas principais
void moduloBone(void);
char verMenuBone(void);
char escolherModelo(void);
void editarModelo(void);
void excluirModelo(void);
void pesquisarModelo(void);
void cadastrarModelo(void);
void escolhendoModelo(void);

//Assinaturas para validacao
void validarNomeModelo(void);
void validarUniPorMetro(void);
void validarUniPorTubo(void);
void telaBone(void);
void telaChapeu(void);
char* validarEsc(char tipo);
void gerarCodigoBone(char *esc, int tam, char num);
void gerarCodigoChapeu (char *esc, int tam, char num);
