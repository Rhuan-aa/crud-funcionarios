# CRUD.C CONTEXT

Este programa implementa um sistema de gerenciamento de funcionários utilizando um vetor de registros em C. O sistema permite inserir, consultar, listar, excluir e alterar dados de funcionários. A seguir, são descritas as funcionalidades e a estrutura do código.

## Estrutura do Registro de Funcionário

O registro de funcionário (`T_FUNCIONARIO`) é definido com os seguintes campos:
- `CPF`: uma string de até 15 caracteres para armazenar o CPF do funcionário.
- `nome`: uma string de até 63 caracteres para armazenar o nome do funcionário.
- `cargo`: uma string de até 31 caracteres para armazenar o cargo do funcionário.
- `num_dependentes`: um inteiro para armazenar o número de dependentes do funcionário.
- `salario`: um float para armazenar o salário-base do funcionário.

## Funcionalidades

### Menu Principal

O programa apresenta um menu principal com as seguintes opções:
1. Inserir um novo funcionário
2. Consultar dados de um funcionário
3. Imprimir todos os funcionários
4. Excluir um funcionário
5. Alterar um funcionário
6. Sair do programa

### Inserir um Novo Funcionário

A função `inserir_funcionario` permite inserir um novo funcionário no vetor. Antes de inserir, verifica se o CPF já está cadastrado.

### Consultar Dados de um Funcionário

A função `consultar_funcionario` permite consultar os dados de um funcionário pelo CPF.

### Imprimir Todos os Funcionários

A função `lista_funcionarios` imprime o nome de todos os funcionários cadastrados.

### Excluir um Funcionário

A função `remover_funcionario` permite excluir um funcionário do vetor pelo CPF.

### Alterar Dados de um Funcionário

A função `alterar_funcionario` permite alterar os dados de um funcionário pelo CPF. O usuário pode escolher alterar o nome, cargo, número de dependentes ou salário.

### Sair do Programa

A opção de sair encerra o programa e libera a memória alocada para o vetor de funcionários.

## Observações

- Não é permitido o uso de variáveis globais. Todos os dados são passados por parâmetros entre as funções.
- O programa utiliza a função `existe_funcionario` para verificar a existência de um funcionário pelo CPF.
- A memória para o vetor de funcionários é alocada dinamicamente para armazenar até 500 funcionários.
- O programa utiliza a função `menu` para exibir o menu principal e obter a opção do usuário.
- O programa utiliza a função `alt_menu` para exibir o menu de alteração e obter a opção do usuário.

## Compilação e Execução

Para compilar e executar o programa, utilize os seguintes comandos:
