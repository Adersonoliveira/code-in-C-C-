#include <stdio.h>
#include <string.h>

typedef struct Produto
{
    char nome[10];
    float valor;
    int Alugado; // 1 = Alugado, 0 = disponivel
} Produto;

typedef struct Estoque
{
    Produto produtos[10];
    float totalAlugado;
    int quantidadeCadastrada;
} Estoque;

void TelaLogin();
void cadastrarProduto(Estoque *Insumos);
void alugarProduto(Estoque *Insumos);
void devolverProduto(Estoque *Insumos);
void imprimeProduto(Estoque armazem);
void editarProduto(Estoque *Insumos);
void removerProduto(Estoque *Insumos);

void TelaLogin()
{
    char login[15] = "Adm";
    char login1[15];
    char senha[15] = "123";
    char senha1[15];
    int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

    while (!login_efetuado)
    {
        printf("Digite o Login: ");
        scanf("%s", login1);

        printf("Digite a Senha: ");
        scanf("%s", senha1);

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0)
        {
            printf("\n\nLOGADO!\n\n");
            login_efetuado = 1;
        }
        else
            printf("\n\nDADOS INVALIDOS!\n\n");
    }
}

int main()
{
    TelaLogin();

    Estoque armazem;
    armazem.quantidadeCadastrada = 0;
    armazem.totalAlugado = 0;

     
    printf("\n");
    printf("                        ||       |||||     |||||  |||||||| |||||    ||||||   ||||  ||||||||                                 \n");
    printf("                        ||     ||     ||  ||      ||    || ||   || ||    || ||  || ||    ||                                 \n");
    printf("                        ||     ||     ||  ||      |||||||| ||   || ||    || ||||   ||||||||                                 \n");
    printf("                        ||     ||     ||  ||      ||    || ||   || ||    || ||  |  ||    ||                                 \n");
    printf("                        ||||||   |||||     |||||  ||    || |||||    ||||||  ||  || ||    ||                                 \n");
    printf("\n");
    printf("     ||  ||||   |||     ||| |||||||  ||||||  |||||||  ||   |||||         |||||   |||||   |||||   ||||||       |||||          \n");
    printf("     || ||  ||  || |   | || ||   || ||    || ||        ||  ||   ||      ||      ||   ||  ||  ||  ||         ||               \n");
    printf("     || ||||    || || || || ||||||| ||    || |||||||       ||   ||      ||      ||   ||  ||  ||  ||||       ||               \n");
    printf("     || ||  ||  ||  |||  || ||   || ||    ||     |||       ||   ||      ||      ||   ||  ||  ||  ||         ||               \n");
    printf("     || ||   || ||       || ||   ||  ||||||  |||||||       |||||         |||||   |||||   |||||   ||||||       |||||          \n");
    printf("\n");
    printf(" +--------------------------------------------------------------------------------------------------------------------+");
    printf("\n");

                            

    int opcao = 0;
    do
    {
        printf("\nEscolha uma opcao\n");
        printf(" 1 - Cadastrar Produto\n");
        printf(" 2 - Alugar \n");
        printf(" 3 - Imprimir Relatorio\n");
        printf(" 4 - Editar Produto\n");
        printf(" 5 - Remover Produto\n");
        printf(" 6 - devolver produto\n");
        printf(" 0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarProduto(&armazem);
            break;
        case 2:
            alugarProduto(&armazem);
            break;
        case 3:
            imprimeProduto(armazem);
            break;
        case 4:
            editarProduto(&armazem);
            break;
        case 5:
            removerProduto(&armazem);
            break;
        case 6:
            devolverProduto(&armazem);
            break;
        case 0:
            printf("Fechando sistema...\n");
            break;
        default:
            printf(" Opcao invalida, tente novamente\n");
            break;
        }

    } while (opcao != 0);

    printf("\n");
    return 0;
}

void cadastrarProduto(Estoque *Insumos)
{

    Produto item;

    printf("Informe o nome do produto: ");
    scanf("%s", item.nome);
    printf("Informe o valor do produto: ");
    scanf("%f", &item.valor);

    printf("\n--CADASTRADO COM SUCESSO--\n");

    item.Alugado = 0;

    int quantidadeCadastrada = Insumos->quantidadeCadastrada;
    quantidadeCadastrada = quantidadeCadastrada + 1;

    Insumos->produtos[quantidadeCadastrada - 1] = item;
    Insumos->quantidadeCadastrada = quantidadeCadastrada;
}

void alugarProduto(Estoque *Insumos)
{

    printf("\nProdutos disponíveis para locação:\n");
    int quantidadeCadastrada = Insumos->quantidadeCadastrada;
    int opcaoEscolhida;

    printf("--------------------\n");

    for (int i = 0; i < quantidadeCadastrada; i++)
    {
        Produto item = Insumos->produtos[i];
        if (item.Alugado == 0)
        {
            printf("Código: %d - %s Valor: %.2f \n", i, item.nome, item.valor);
        }
    }

    printf("Escolha uma das opções acima: ");
    scanf("%d", &opcaoEscolhida);

    Produto itemEscolhido = Insumos->produtos[opcaoEscolhida];

    Insumos->produtos[opcaoEscolhida].Alugado = 1;
    float valor = itemEscolhido.valor;
    float totalAlugado = Insumos->totalAlugado;
    Insumos->totalAlugado = totalAlugado + valor;

    printf("\nProduto Alugado!\n");
}
void devolverProduto(Estoque *Insumos)
{
    printf("\nProdutos alugados disponíveis para devolução:\n");
    int quantidadeCadastrada = Insumos->quantidadeCadastrada; 
    int opcaoEscolhida;

    printf("--------------------\n");

    for (int i = 0; i < quantidadeCadastrada; i++)
    {
        Produto item = Insumos->produtos[i];
        if (item.Alugado == 1)
        {
            printf("Código: %d - %s Valor: %.2f \n", i, item.nome, item.valor);
        }
    }

    printf("Escolha o código do produto a ser devolvido: ");
    scanf("%d", &opcaoEscolhida);

    Produto *itemDevolvido = &(Insumos->produtos[opcaoEscolhida]);

    if (itemDevolvido->Alugado == 1)
    {
        itemDevolvido->Alugado = 0;
        float valor = itemDevolvido->valor;
        float totalAlugado = Insumos->totalAlugado;
        Insumos->totalAlugado = totalAlugado - valor;

        printf("\nProduto Devolvido!\n");
    }
    else
    {
        printf("\n--O PRODUTO NÃO ESTÁ ALUGADO--\n");
    }
}


void editarProduto(Estoque *Insumos)
{
    printf("\nProdutos disponíveis para edição:\n");
    int quantidadeCadastrada = Insumos->quantidadeCadastrada;
    int opcaoEscolhida;

    printf("--------------------\n");

    for (int i = 0; i < quantidadeCadastrada; i++)
    {
        Produto item = Insumos->produtos[i];
        printf("Código: %d - %s Valor: %.2f \n", i, item.nome, item.valor);
    }

    printf("Escolha o código do produto a ser editado: ");
    scanf("%d", &opcaoEscolhida);

    Produto *itemEditado = &(Insumos->produtos[opcaoEscolhida]);

    printf("Digite o novo nome do produto: ");
    scanf("%s", itemEditado->nome);
    printf("Digite o novo valor do produto: ");
    scanf("%f", &(itemEditado->valor));

    printf("\n--PRODUTO EDITADO COM SUCESSO--\n");
}

void removerProduto(Estoque *Insumos)
{
    printf("\nProdutos disponíveis para remoção:\n");
    int quantidadeCadastrada = Insumos->quantidadeCadastrada;
    int opcaoEscolhida;

    printf("--------------------\n");

    for (int i = 0; i < quantidadeCadastrada; i++)
    {
        Produto item = Insumos->produtos[i];
        printf("Código: %d - %s Valor: %.2f \n", i, item.nome, item.valor);
    }

    printf("Escolha o código do produto a ser removido: ");
    scanf("%d", &opcaoEscolhida);

    if (opcaoEscolhida >= 0 && opcaoEscolhida < quantidadeCadastrada)
    {
        Produto *itemRemovido = &(Insumos->produtos[opcaoEscolhida]);
        if (itemRemovido->Alugado == 0)
        {
            for (int i = opcaoEscolhida; i < quantidadeCadastrada - 1; i++)
            {
                Insumos->produtos[i] = Insumos->produtos[i + 1];
            }
            quantidadeCadastrada--;
            Insumos->quantidadeCadastrada = quantidadeCadastrada;
            printf("\n--PRODUTO REMOVIDO COM SUCESSO--\n");
        }
        else
        {
            printf("\n--O PRODUTO ESTÁ ALUGADO E NÃO PODE SER REMOVIDO--\n");
        }
    }
    else
    {
        printf("\n--CÓDIGO DO PRODUTO INVÁLIDO--\n");
    }
}

void imprimeProduto(Estoque armazem)
{

    printf("\nRelatorio do Estoque:\n");

    printf("--------------------\n");

    int quantidadeCadastrada = armazem.quantidadeCadastrada;
    for (int i = 0; i < quantidadeCadastrada; i++)
    {
        Produto item = armazem.produtos[i];
        printf("Produto: %s, Valor: %.2f, Alugado: %s \n", item.nome, item.valor, item.Alugado == 1 ? "Sim" : "Não");
    }

    printf("--------------------\n");

    printf("Total Alugado: %.2f\n", armazem.totalAlugado);
}
