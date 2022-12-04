#include <stdio.h>
#include <stdlib.h>
#include "moduloSobre.h"

void verMenuSobre(void) {
    system ( " clear||cls " );
    printf("\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===              = = = = = Informações do projeto = = = = =                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("===                                                                         ===\n");
    printf("===  Projeto desenvolvido na disciplina DCT1106 - Programação, para         ===\n");
    printf("===  avaliação desse período.                                               ===\n");
    printf("===  Aluna: Dayanne Xavier Lucena.                                          ===\n");
    printf("===  Segundo período.                                                       ===\n");
    printf("===                                                                         ===\n");
    printf("===    O presente projeto consiste em um gerenciamento de uma bonelaria,    ===\n");
    printf("===  onde o dono ou gerente poderia ter controle sobre:                     ===\n");
    printf("===  -  Modelos de bonés e chapéus que se encontram disponíveis para a      ===\n");
    printf("===  produção, onde se cadastra o modelo com sua características, e a       ===\n");
    printf("===  partir desses dados ele pode ter a informação do que é necessário para ===\n");
    printf("===  fazer um modelo, o sistema verifica se existe material suficiente no   ===\n");
    printf("===  estoque para essa produção, caso não, ele informa o que está em falta, ===\n");
    printf("===  e não permite concluir o pedido.                                       ===\n");
    printf("===  - Guardar dados dos clientes, assim pode saber quais clientes fizeram  ===\n");
    printf("===  pedidos, e pode manter contato com esses clientes antes, durante e     ===\n");
    printf("===  depois do seu pedido.                                                  ===\n");
    printf("===  - Guardar dados dos fornecedores de materiais necessários para a       ===\n");
    printf("===  produção dos modelos, onde existe relação entre o fornecedor e seus    ===\n");
    printf("===  materiais, dessa forma, quando um material estiver insuficiente no     ===\n");
    printf("===  estoque, basta recuperar os dados do fornecedor daquele produto, e     ===\n");
    printf("===  comprar mais.                                                          ===\n");
    printf("===  - Guardar dados do seu estoque, para saber o que se tem para a         ===\n");
    printf("===  produção dos modelos.                                                  ===\n");
    printf("===  - Módulo para realizar o pedido, onde se relaciona todos os módulos    ===\n");
    printf("===  anteriores, já que para se começar o pedido seu cliente tem que está   ===\n");
    printf("===  cadastrado, necessita ter modelos de bonés disponíveis, além de        ===\n");
    printf("===  conferir no estoque se tem material suficiente para essa produção,     ===\n");
    printf("===  após isso, se tem a confirmação do pedido final.                       ===\n");
    printf("===    De forma geral, os seguintes módulos: boné, cliente, fornecedor,     ===\n");
    printf("===  estoque, possuem o CRUD (Create (criar), Read (ler), Update            ===\n");
    printf("===  (atualizar) e Delete (apagar)) completo, mas o módulo pedido não tem,  ===\n");
    printf("===  já que estamos levando em consideração o fato que ao se fechar um      ===\n");
    printf("===  pedido logo irá entrar em produção, então não seria mais possível      ===\n");
    printf("===  editar, ou apagar, apenas recuperar esses dados.                       ===\n");
    printf("===    Além disso, se pode ter acesso a vários relatórios sobre os dados    ===\n");
    printf("===  existentes no sistema.                                                 ===\n");
    printf("===                                                                         ===\n");
    printf("===============================================================================\n");
    printf("\n");
    
}