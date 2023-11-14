#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para representar um item
struct Funcionario
{
    int codigo;
    char nome[50];
    char telefone[15];
    char email[50];
    float preco;
    int idade;
};

// Função para adicionar um novo registro
void CriarRegistroDeFuncionario(struct Funcionario *itens, int *registro)
{
    printf("Digite o código: ");
    scanf("%d", &itens[*registro].codigo);

    printf("Digite o nome: ");
    scanf("%s", itens[*registro].nome);

    printf("Digite o seu email: ");
    scanf("%f", &itens[*registro].email);

    printf("Digite o seu telefone: ");
    scanf("%f", &itens[*registro].telefone);

    printf("Digite o preço de entrada para criação de novo registro: ");
    scanf("%f", &itens[*registro].preco);

    printf("Digite a sua idade: ");
    scanf("%f", &itens[*registro].idade);

    if ([*registro].idade < 18)
    {
        printf("Desculpe, mas parece que voce e menor de idade, nao podemos continuar com o cadastro =(\n");
        return 0;
    }

    (*registro)++;
}

// Função para exibir todos os registros
void ListarFuncionarios(const struct Funcionario *itens, int contador)
{
    printf("\nListagem de Registros:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("Código: %d\n", itens[i].codigo);
        printf("Nome: %s\n", itens[i].nome);
        printf("Preço: %.2f\n", itens[i].email);
        printf("Preço: %.2f\n", itens[i].telefone);
        printf("Preço: %.2f\n", itens[i].preco);
    }
}

// Função para buscar um registro por código
void buscarRegistroDeFuncionario(const struct Funcionario *itens, int contador)
{
    int codigoBusca;
    printf("Digite o código a ser buscado: ");
    scanf("%d", &codigoBusca);

    int encontrado = 0;
    for (int i = 0; i < contador; i++)
    {
        if (itens[i].codigo == codigoBusca)
        {
            printf("Registro Encontrado:\n");
            printf("Código: %d\n", itens[i].codigo);
            printf("Nome: %s\n", itens[i].nome);
            printf("Preço: %.2f\n", itens[i].email);
            printf("Preço: %.2f\n", itens[i].telefone);
            printf("Preço: %.2f\n", itens[i].preco);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("O registro ditado não foi encontrado =( \n");
        printf("Verifique se o codigo inserido esta correto. \n");
    }
}

// Função para editar um registro por código
void editarRegistroDeFuncionario(struct Funcionario *itens, int contador)
{
    int codigoEdicao;
    printf("Digite o código que deseja editar: ");
    scanf("%d", &codigoEdicao);

    int encontrado = 0;
    for (int i = 0; i < contador; i++)
    {
        if (itens[i].codigo == codigoEdicao)
        {
            printf("Digite o novo nome: ");
            scanf("%s", itens[i].nome);

            printf("Digite o novo preço: ");
            scanf("%f", &itens[i].preco);

            printf("Registro de codigo editado com sucesso.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("O registro ditado não foi encontrado =( \n");
        printf("Verifique se o codigo inserido esta correto. \n");
    }
}

// Função para deletar um registro por código
void deletarRegistroDeFuncionario(struct Funcionario *itens, int *contador)
{
    int codigoDelecao;
    printf("Digite o código a ser deletado: ");
    scanf("%d", &codigoDelecao);

    int encontrado = 0;
    for (int i = 0; i < *contador; i++)
    {
        if (itens[i].codigo == codigoDelecao)
        {
            // Move todos os registros subsequentes uma posição para trás
            for (int j = i; j < *contador - 1; j++)
            {
                itens[j] = itens[j + 1];
            }
            (*contador)--;
            printf("Registro deletado com sucesso.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("O registro ditado não foi encontrado =( \n");
        printf("Verifique se o codigo inserido esta correto. \n");
    }
}

int main()
{
    struct Funcionario itens[10]; // Supomos que você não terá mais de 100 registros
    int contador = 0;
    int escolhadousuario;

    do
    {
        printf("\nBem-vindo ao Banco app do banco Central\n");

        printf("  ┌──────────────────┐  \n");
        printf("  │  ╭┼┼╮            │  \n");
        printf("  │  ╰┼┼╮            │  \n");
        printf("  │  ╰┼┼╯            │  \n");
        printf("  │                  │  \n");
        printf("  │  C E N T R A L   │  \n");
        printf("  │  B A N K         │  \n");
        printf("  │                  │  \n");
        printf("  │                  │  \n");
        printf("  │                  │  \n");
        printf("  │                  │  \n");
        printf("  │ ║│┃┃║║│┃║│║┃│    │  \n");
        printf("  │                  │  \n");
        printf("  │ USF EXCERCISE    │  \n");
        printf("  │                  │  \n");
        printf("  └──────────────────┘  \n");

        printf("\nEscolha o tipo de operacao que deseja realizar:\n");

        printf("1 - Adicionar um novo registro de funcionario\n");
        printf("2 - Listar rregistros\n");
        printf("3 - Buscar registro\n");
        printf("4 - Editar registro\n");
        printf("5 - Deletar registro\n");

        scanf("%d", &escolhadousuario);

        switch (escolhadousuario)
        {
        case 1:
            CriarRegistroDeFuncionario(itens, &contador);
            break;
        case 2:
            ListarFuncionarios(itens, contador);
            break;
        case 3:
            buscarRegistroDeFuncionario(itens, contador);
            break;
        case 4:
            editarRegistroDeFuncionario(itens, contador);
            break;
        case 5:
            deletarRegistroDeFuncionario(itens, &contador);
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolhadousuario != 4);

    return escolhadousuario;
}