#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE  1
#define FALSE 0


typedef struct list_node
{
    int nif;
    char nome[50];
    char funcao[50];
    float salario;
    struct list_node *next;
} lista;

int is_onlist(lista *cabeca, int nif)
{

    if (cabeca == NULL)
    {
        return FALSE;
    }
    lista *temp = cabeca;
    while (temp != NULL)
    {
        if (temp->nif == nif)
        {
            return TRUE;
        }
        temp = temp->next;
    }
    return FALSE;
}
//cria um novo nodo
lista *new_nod(lista **cabeca, int nif)
{
    lista *temp = (lista *)malloc(sizeof(lista));
    int opcao = -1;
    if (temp == NULL)
    {
        fprintf(stderr, "Falta de memória.");
        exit(1);
    }
    temp->nif = nif;

    // nome do funcionario
    printf("Nome: ");
    fpurge(stdin);
    (void)scanf("%s", temp->nome);


    do
    {
        //funcao do funcionario
        printf("Funcao: 1=Help Desk, 2=Chefe Servico: ");
        fpurge(stdin);
        (void)scanf("%d", &opcao);
        if (opcao == 1)
        {
            strcpy(temp->funcao, "Help desk");
            break;
        }
        else if (opcao == 2)
        {
            strcpy(temp->funcao, "Chefe Servico");
            break;
        }
        else
        {
            printf("\nFuncao invalida.\n");
        }
    }
    while (opcao != 1 || opcao != 2);
    // salario do funcionario
    printf("Salario: ");
    fpurge(stdin);
    (void)scanf("%f", &temp->salario);
    return temp;
}

void insert_onlist(lista **cabeca, int nif)
{
    lista *new = new_nod(cabeca, nif);
    if ((*cabeca) == NULL)
    {
        new->next = (*cabeca);
        (*cabeca) = new;
    }
    else
    {
        lista *aux = (*cabeca);
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        new->next = NULL;
        aux->next = new;
    }
}

void show_list(lista *cabeca)
{

    if (cabeca == NULL)
    {
        printf("Lista vazia.");
    }
    else
    {
        lista *temp = cabeca;
        while (temp != NULL)
        {
            printf("\nNIF:%d\n", temp->nif);
            printf("Nome: %s\n", temp->nome);
            printf("Funcao: %s\n", temp->funcao);
            printf("Salario: %.2f\n", temp->salario);
            temp = temp->next;
        }
    }
}

float gastos_funcionario(char funcao[], lista *cabeca)
{
    float total = 0;
    int funcao_existe = FALSE;
    lista *temp = cabeca;
    while (temp != NULL)
    {
        // nota: strcasecmp, compara ignorando maiuscula e minuscula
        if (strcasecmp(temp->funcao, funcao) == 0)
        {
            total += temp->salario;
            funcao_existe = TRUE;
        }
        temp = temp->next;
    }
    if (funcao_existe == TRUE)
    {
        return total; // funcao (do funcionario) procurada existe
    }
    else
    {
        return -1; // funcao (do funcionario) procururada nao existe
    }
}
int main(void)
{
    int opcao, run = TRUE;
    int nif, i = 0;
    int num;
    float gasto = 0;
    char tmp_funcao[50];
    lista *funcionario = NULL;
    do
    {
        (void)system("clear");
        printf("\n1. Inserir funcionarios");
        printf("\n2. Gasto com funcionários");
        printf("\n3. Mostras funcionarios");
        printf("\n0. Sair");
        printf("\nSua opcao: ");
        (void)scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Quantos funcionarios inserir? ");
            (void)scanf("%d", &num);
            for (i = 0; i < num; ++i)
            {
                printf("\nNif: ");
                (void)scanf("%d", &nif);
                if (is_onlist(funcionario, nif) == TRUE)
                {
                    printf("\nEste funcionario ja esta na lista");
                    getchar();
                    i--;
                }
                else
                {
                    insert_onlist(&funcionario, nif);
                }
            }
            break;
        case 2:


            if (funcionario == NULL )
            {
                printf("\nLista vazia\n");
            }
            else
            {
                printf("Informe a funcao: ");
                (void)scanf("%s", tmp_funcao);
                gasto = gastos_funcionario(tmp_funcao, funcionario);


                if (gasto == -1)
                {
                    printf("\nFuncao %s nao existe\n", tmp_funcao);
                }
                else
                {
                    printf("\nGasto Total: %.2f\n", gasto);
                }
            }
            break;
        case 3:
            show_list(funcionario);
            break;
        case 0:
            run = FALSE;
            break;
        }
        printf("\nEnter para continuar\n");
        fpurge(stdin);
        getchar();
    }
    while (run == TRUE);

    return 0;
}

