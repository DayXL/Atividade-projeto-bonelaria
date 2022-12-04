# Atividade-projeto-bonelaria
Repositório para o desenvolvimento do projeto avaliativo de programação.

O presente projeto consiste em um gerenciamento de uma bonelaria, onde 
o dono ou gerente poderia ter controle sobre:
-  Modelos de bonés e chapéus que se encontram disponíveis para a 
produção, onde se cadastra o modelo com sua características, e a 
partir desses dados ele pode ter a informação do que é necessário para 
fazer um modelo, o sistema verifica se existe material suficiente no 
estoque para essa produção, caso não, ele informa o que está em falta, 
e não permite concluir o pedido.
- Guardar dados dos clientes, assim pode saber quais clientes fizeram 
pedidos, e pode manter contato com esses clientes antes, durante e 
depois do seu pedido.
- Guardar dados dos fornecedores de materiais necessários para a produção dos modelos, onde existe relação entre o fornecedor e seus materiais, dessa forma, quando um material estiver insuficiente no estoque, basta recuperar os dados do fornecedor daquele produto, e comprar mais.
- Guardar dados do seu estoque, para saber o que se tem para a produção dos modelos.
- Módulo para realizar o pedido, onde se relaciona todos os módulos anteriores, já que para se começar o pedido seu cliente tem que está cadastrado, necessita ter modelos de bonés disponíveis, além de conferir no estoque se tem material suficiente para essa produção, após isso, se tem a confirmação do pedido final.
De forma geral, os seguintes módulos: boné, cliente, fornecedor, estoque, possuem o CRUD (Create (criar), Read (ler), Update (atualizar) e Delete (apagar)) completo, mas o módulo pedido não tem,  já que estamos levando em consideração o fato que ao se fechar um pedido logo irá entrar em produção, então não seria mais possível editar, ou apagar, apenas recuperar esses dados. 
Além disso, se pode ter acesso a vários relatórios sobre os dados existentes no sistema.

