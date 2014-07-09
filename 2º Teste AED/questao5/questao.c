#include <stdio.h>
#include <stdlib.h>

/* Questao 5.1 - Declaracao e criacao da estrutura de dados
 ========================================================================= */
// estrutura para o tipo Data, usada para criam o campo data de expiracao
struct t_data
{
    int dia;
    int mes;
    int ano;
};

// extrutura para um no da fila(queue), usei o nome q_node (q=queue (fila) node=no)
struct q_node
{
    char designacao[30];
    int quantidade;
    struct t_data data_expiracao;
    struct q_node *next;
};

// ponteiros para inicio e fim da fila
struct q_node *primeiro = NULL;
struct q_node *ultimo = NULL;

// funcao para criar/alocar espaco na memoria para um novo produto
struct q_node *novo_no()
{
    struct q_node *novo = (struct q_node *)malloc(sizeof(struct q_node));
    if (novo == NULL)
    {
        fprintf(stderr, "Falta de memória.");
        exit(1);
    }
    printf("\tDesignação do produto: ");
    fflush(stdin);
    //fpurge(stdin);
    (void)scanf("%s", novo->designacao);

    printf("\tQuantidade: ");
    fflush(stdin);
    (void)scanf("%d", &novo->quantidade);

    printf("\tData de Expiração [dd mm aaaa]: ");
    fflush(stdin);
    //fpurge(stdin);
    (void)scanf("%d %d %d", &novo->data_expiracao.dia, &novo->data_expiracao.mes, &novo->data_expiracao.ano);

    novo->next = NULL;

    return novo;
}

// insere um novo produto na fila, sempre no final
void inserir_produto(void)
{
    struct q_node *novo = novo_no();
    novo->next = NULL;
    // Insere o primeiro no (produto)
    if (ultimo == NULL)
    {
        ultimo = novo;
        primeiro = ultimo;
        ultimo->next = NULL;
    }
    // insere os restantes produtos, sempre no final da fila
    else
    {
        ultimo->next = novo;
        ultimo = novo;
        ultimo->next = NULL;
    }
}

/* Questao 5.2 - funcao para mostrar o produto com menor prazo de expiracao
 ========================================================================= */
void menor_prazo(void)
{
    if (ultimo == NULL)
    {
        fprintf(stderr, "\n\tFila de produtos esta vazia");
        return;
    }
    struct q_node *current = primeiro;
    struct q_node *menor = primeiro;

    while (current != NULL)
    {

        if ((current->data_expiracao.ano <= menor->data_expiracao.ano))
        {
            if (current->data_expiracao.mes <= menor->data_expiracao.mes)
            {
                if (current->data_expiracao.dia <= menor->data_expiracao.dia)
                {

                    menor = current;
                }
            }
        }
        current = current->next;
    }

    if (menor != NULL)
    {
        printf("\n\tPRODUTO COM MENOR PRAZO: ");
        printf("\n\tDesignação: %s", menor->designacao);
        printf("\n\tQuantidade: %d", menor->quantidade);
        printf("\n\tData Expiração: %d/%d/%d",
               menor->data_expiracao.dia,
               menor->data_expiracao.mes,
               menor->data_expiracao.ano);
    }
}

/* Questao 5.3 - funcao para remover o produto em maior quantidade
 ========================================================================= */
void remover_maior_qtd(void)
{
    if (ultimo == NULL)
    {
        fprintf(stderr, "\n\tFila de produtos está vazia");
        return;
    }
    struct q_node *current = primeiro;
    struct q_node *maior = primeiro;
    struct q_node *anterior = NULL;

    // se existir somente um produto na fila, o maior e o primeiro
    if (primeiro->next == NULL)
    {
        maior = primeiro;
        free(maior);
        primeiro = ultimo = NULL;
    }
    else
    {
        while (current->next != NULL)
        {
            if (current->next->quantidade >= maior->quantidade)
            {
                anterior = current;
                maior = current->next;
            }
            current = current->next;
        }
        // Maior esta na ultima posciao da fila
        if (maior->next == NULL)
        {
            anterior->next = NULL;
            ultimo = anterior;
            ultimo->next = NULL;
            free(maior);
        }
        // o maior produto esta no meio da fila
        else
        {
            anterior->next = maior->next;
            free(maior);
        }
    }
}


// mostra os produtos que estão na fila
void mostrar_produtos(void)
{
    if (ultimo == NULL)
    {
        fprintf(stderr, "\n\tFila de produtos esta vazia");
        return;
    }
    struct q_node *aux = primeiro;
    printf("\n\t%-15s %-4s %-10s", "Designação", "Qtd", "Expiração.");
    printf("\n\t-----------  ----  ----------\n");
    while (aux != NULL)
    {
        printf("\t%-14s", aux->designacao);
        printf("%-5d", aux->quantidade);
        printf("%-2d/%-2d/%-4d\n", aux->data_expiracao.dia, aux->data_expiracao.mes, aux->data_expiracao.ano);
        aux = aux->next;
    }
}

int main(void)
{
    int opcao, run = 1;
    while (run)
    {
        (void)system("clear||cls");
        printf("\n\t0. Sair.");
        printf("\n\t1. Inserir produto.");
        printf("\n\t2. Mostrar produtos.");
        printf("\n\t3. Produto com menor prazo.");
        printf("\n\t4. Remover produto em maior quantidade.");
        printf("\n\tSua opção: ");
        fflush(stdin);
        (void)scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            run = 0;
            break;

        case 1:
            inserir_produto();
            break;

        case 2:
            mostrar_produtos();
            break;

        case 3:
            menor_prazo();
            break;

        case 4:
            remover_maior_qtd();
            break;

        default:
            printf("\n\tOpcao invalida.");
            break;
        }
        printf("\n\tTecle ENTER para continuar...");
        fflush(stdin);
        //fpurge(stdin);
        getchar();
    }

    return 0;
}
