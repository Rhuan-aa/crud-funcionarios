/*
Defina um registro de Funcionário capaz de armazenar o CPF, o nome, o
cargo, o número de dependentes e o salário-base. Em seguida, crie um
vetor de registros de Funcionário com capacidade para armazenar até 500
funcionários. Faça um programa principal que apresente o seguinte menu de opções para
o usuário e implemente cada operação do menu por meio de funções.

Menu de Opções:
1. Inserir um novo funcionário
2. Consultar dados de um funcionário
3. Imprimir todos os funcionários
4. Excluir um funcionário
5. Alterar um funcionário
6. Sair do programa

Atenção:
Não é permitido o uso de variáveis globais. Use parâmetros para fazer a
transferência de valores entre as variáveis das funções.
Ao inserir um novo funcionário, lembre-se de verificar se o mesmo já
existe no vetor (faça a busca pelo CPF).
Sempre que possível, reutilize o código de uma função (ao invés de repetir
o código em outra função).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definição da estrutura T_FUNCIONARIO
typedef struct {
    char CPF[16];
    char nome[64];
    char cargo[32];
    int num_dependentes;
    float salario;
} T_FUNCIONARIO;

// Função para exibir o menu principal e obter a opção do usuário
int menu(){
    int opcao;
    do {
        printf("====== MENU ======\n");
        printf("1 - Inserir um novo funcionario\n");
        printf("2 - Consultar dados de um funcionario\n");
        printf("3 - Imprimir todos os funcionarios\n");
        printf("4 - Excluir um funcionario\n");
        printf("5 - Alterar um funcionario\n");
        printf("6 - Sair do programa\n");
        printf("\nDigite a opcao que deseja: ");
        scanf("%d", &opcao);
    } while (!(opcao >= 1 && opcao <= 6));
    return opcao;
}

// Função para exibir o menu de alteração e obter a opção do usuário
int alt_menu(){
    int opcao_alt;
    do {
        printf("====== ALT MENU ======\n");
        printf("1 - Nome\n");
        printf("2 - Cargo\n");
        printf("3 - Numero de Dependentes\n");
        printf("4 - Salario\n");
        scanf("%d", &opcao_alt);
    } while (!(opcao_alt >= 1 && opcao_alt <= 4));
    return opcao_alt;
}

// Função para inserir um novo funcionário
T_FUNCIONARIO* inserir_funcionario(T_FUNCIONARIO* funcionarios, int* num_funcionarios){
    getchar(); // Limpa o buffer de entrada
    printf("Digite o CPF do funcionario: ");
    fgets(funcionarios[(*num_funcionarios)].CPF, 16, stdin);
    funcionarios[(*num_funcionarios)].CPF[strcspn(funcionarios[(*num_funcionarios)].CPF, "\n")] = 0; // Remove newline

    printf("Digite o nome do funcionario: ");
    fgets(funcionarios[(*num_funcionarios)].nome, 64, stdin);
    funcionarios[(*num_funcionarios)].nome[strcspn(funcionarios[(*num_funcionarios)].nome, "\n")] = 0; // Remove newline

    printf("Digite o cargo do funcionario: ");
    fgets(funcionarios[(*num_funcionarios)].cargo, 32, stdin);
    funcionarios[(*num_funcionarios)].cargo[strcspn(funcionarios[(*num_funcionarios)].cargo, "\n")] = 0; // Remove newline

    printf("Digite o numero de depedentes do funcionario: ");
    scanf("%d", &funcionarios[(*num_funcionarios)].num_dependentes);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionarios[(*num_funcionarios)].salario);

    (*num_funcionarios)++; // Incrementa o número de funcionários
    return funcionarios;
}

// Função para verificar se um funcionário existe pelo CPF
int existe_funcionario(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* CPF){
    for (int i = 0; i < num_funcionarios; i++){
        if (strcmp(CPF, funcionarios[i].CPF) == 0){
            return i; // Retorna o índice do funcionário
        }
    }
    return -1; // Retorna -1 se o funcionário não for encontrado
}

// Função para consultar os dados de um funcionário pelo CPF
T_FUNCIONARIO* consultar_funcionario(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* CPF){
    int i = existe_funcionario(funcionarios, num_funcionarios, CPF);
    if (i >= 0){
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Numero de Dependentes: %d\n", funcionarios[i].num_dependentes);
        printf("Salario: %.2f\n", funcionarios[i].salario);
        return &funcionarios[i];
    } else {
        printf("ERRO: Funcionario não cadastrado\n");
        return NULL;
    }
}

// Função para listar todos os funcionários
void lista_funcionarios(T_FUNCIONARIO* funcionarios, int num_funcionarios){
    for (int i = 0; i < num_funcionarios; i++){
        printf("%s\n", funcionarios[i].nome);
    }
}

// Função para remover um funcionário pelo CPF
void remover_funcionario(T_FUNCIONARIO* funcionarios, int* num_funcionarios, char* CPF){
    int i = existe_funcionario(funcionarios, *num_funcionarios, CPF);
    if (i >= 0){
        for (int j = i; j < (*num_funcionarios) - 1 ; j++) {
            funcionarios[j] = funcionarios[j + 1];
        }
        (*num_funcionarios)--; // Decrementa o número de funcionários
    } else {
        printf("ERRO: Funcionario não cadastrado\n");
    }
}

// Função para alterar o nome de um funcionário pelo CPF
void alterar_nomes(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* CPF){
    int i = existe_funcionario(funcionarios, num_funcionarios, CPF);
    if (i >= 0){
        char novo_nome[64];
        getchar(); // Limpa o buffer de entrada

        printf("Digite a alteração no nome do funcionario: ");
        fgets(novo_nome, 64, stdin);
        novo_nome[strcspn(novo_nome, "\n")] = 0; // Remove newline

        strcpy(funcionarios[i].nome, novo_nome); // Copia o novo nome para a estrutura
    } else {
        printf("ERRO: Funcionario não cadastrado\n");
    }
}

// Função para alterar o número de dependentes de um funcionário pelo CPF
void alterar_dependentes(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* CPF){
    int i = existe_funcionario(funcionarios, num_funcionarios, CPF);
    if (i >= 0){
        int novo_dependentes;
        getchar(); // Limpa o buffer de entrada

        printf("Digite a alteração no numero de dependentes do funcionario: ");
        scanf("%d", &novo_dependentes);

        funcionarios[i].num_dependentes = novo_dependentes; // Atualiza o número de dependentes
    } else {
        printf("ERRO: Funcionario não cadastrado\n");
    }
}

// Função para alterar o salário de um funcionário pelo CPF
void alterar_salarios(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* CPF){
    int i = existe_funcionario(funcionarios, num_funcionarios, CPF);
    if (i >= 0){
        float novo_salario;
        getchar(); // Limpa o buffer de entrada

        printf("Digite a alteração no salario do funcionario: ");
        scanf("%f", &novo_salario);

        funcionarios[i].salario = novo_salario; // Atualiza o salário
    } else {
        printf("ERRO: Funcionario não cadastrado\n");
    }
}

// Função para alterar o cargo de um funcionário pelo CPF
void alterar_cargos(T_FUNCIONARIO* funcionarios, int num_funcionarios, char* CPF){
    int i = existe_funcionario(funcionarios, num_funcionarios, CPF);
    if (i >= 0){
        char novo_cargo[32];
        getchar(); // Limpa o buffer de entrada

        printf("Digite a alteração no cargo do funcionario: ");
        fgets(novo_cargo, 32, stdin);
        novo_cargo[strcspn(novo_cargo, "\n")] = 0; // Remove newline

        strcpy(funcionarios[i].cargo, novo_cargo); // Copia o novo cargo para a estrutura
    } else {
        printf("ERRO: Funcionario não cadastrado\n");
    }
}

// Função principal
int main(int argc, char const *argv[]){
    T_FUNCIONARIO* funcionarios;
    funcionarios = (T_FUNCIONARIO *) malloc(sizeof(T_FUNCIONARIO) * 500); // Aloca memória para 500 funcionários
    int num_funcionarios = 0;

    bool start = true;
    while (start){
        int opc = menu(); // Exibe o menu e obtém a opção do usuário
        if (opc == 1){
            if(num_funcionarios < 499){
                inserir_funcionario(funcionarios, &num_funcionarios); // Insere um novo funcionário
            } else {
                printf("ERRO: O numero de usuarios ja esta no limite maximo de armazenamento\n");
            }
        }
        if (opc == 2){
            char CPF[16];
            getchar(); // Limpa o buffer de entrada

            printf("Digite o CPF do funcionario que deseja consultar: ");
            fgets(CPF, 16, stdin);
            CPF[strcspn(CPF, "\n")] = 0; // Remove newline

            consultar_funcionario(funcionarios, num_funcionarios, CPF); // Consulta os dados do funcionário
        }
        if (opc == 3){
            lista_funcionarios(funcionarios, num_funcionarios); // Lista todos os funcionários
        }
        if (opc == 4){
            char CPF[16];
            getchar(); // Limpa o buffer de entrada

            printf("Digite o CPF do funcionario que deseja remover do sistema: ");
            fgets(CPF, 16, stdin);
            CPF[strcspn(CPF, "\n")] = 0; // Remove newline

            remover_funcionario(funcionarios, &num_funcionarios, CPF); // Remove o funcionário
        }
        if (opc == 5){
            char CPF[16];
            getchar(); // Limpa o buffer de entrada

            printf("Digite o CPF do funcionario que deseja alterar no sistema: ");
            fgets(CPF, 16, stdin);
            CPF[strcspn(CPF, "\n")] = 0; // Remove newline

            int alt_opc = alt_menu(); // Exibe o menu de alteração e obtém a opção do usuário
            if (alt_opc == 1){
                alterar_nomes(funcionarios, num_funcionarios, CPF); // Altera o nome do funcionário
            }
            if (alt_opc == 2){
                alterar_cargos(funcionarios, num_funcionarios, CPF); // Altera o cargo do funcionário
            }
            if (alt_opc == 3){
                alterar_dependentes(funcionarios, num_funcionarios, CPF); // Altera o número de dependentes do funcionário
            }
            if (alt_opc == 4){
                alterar_salarios(funcionarios, num_funcionarios, CPF); // Altera o salário do funcionário
            }
        }
        if (opc == 6){
            start = false; // Encerra o loop e o programa
        }
    }

    free(funcionarios); // Libera a memória alocada
    return 0;
}