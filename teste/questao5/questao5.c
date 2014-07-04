#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define NUM_DISC 5



typedef struct
{
    char descricao[30];
} Disciplinas;

typedef struct p_node
{
    char nome[30];
    Disciplinas discicplinas[NUM_DISC];
    int num_disciplinas;
    char estado[10];
    struct p_node *next;
} pilha;

pilha *new_node(pilha *topo)
{
    int i, opt_estado;
    pilha *aux = (pilha *)malloc(sizeof(pilha));
    if (aux == NULL)
    {
        fprintf(stderr, "Falta de memoria.");
        exit(1);
    }
    printf("Nome: ");
    fpurge(stdin);
    (void)scanf("%s", aux->nome);
    printf("Quantas disciplinas: ");
    (void)scanf("%d", &aux->num_disciplinas);
    for (i = 0; i < aux->num_disciplinas; ++i)
    {
        printf("%dº Disciplina: ", i + 1);
        fpurge(stdin);
        (void)scanf("%s", aux->discicplinas[i].descricao);
    }
    do
    {
        printf("\nEstado (1-Regular, 2-Irregular): ");
        fpurge(stdin);
        (void)scanf("%d", &opt_estado);
        if (opt_estado == 1)
        {
            strcpy(aux->estado, "regular");
            break;
        }
        else if (opt_estado == 2)
        {
            strcpy(aux->estado, "irrregular");
            break;
        }
        else
        {
            printf("\nOpcao invalida");
        }
    }
    while (opt_estado != 1 || opt_estado != 2);
    aux->next = topo;
    return aux;
}

void insert_pilha(pilha **topo)
{
    (*topo) = new_node((*topo));
}

void show_pilha(pilha *topo)
{

    if (topo == NULL)
    {
        printf("\nPilha vazia.");
        return;
    }
    pilha *aux = topo;
    int i = 0;
    while (aux != NULL)
    {
        printf("\nNome: %s", aux->nome);
        printf("\nDisciplinas: ");
        for (i = 0; i < aux->num_disciplinas; i++)
        {
            printf("%s ", aux->discicplinas[i].descricao);
        }
        printf("\nEstado: %s\n", aux->estado);
        aux = aux->next;
    }
}

pilha *search_aluno(pilha *topo, char nome_aluno[])
{
    if (topo == NULL)
    {
        return NULL;
    }
    pilha *aux = topo;
    while (aux != NULL)
    {
        if (strcasecmp(aux->nome, nome_aluno) == 0)
        {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

void delete_aluno(pilha **topo, char nome_aluno[])
{
    if ((*topo) == NULL)
    {
        printf("\n\tPilha vazia.");
        return;
    }
    pilha *aux = (*topo);
    pilha *tmp = NULL;
    if ((*topo)->next == NULL && strcasecmp((*topo)->nome, nome_aluno) == 0)
    {

        tmp = (*topo);
        free(tmp);
        (*topo) = NULL;
        printf("\n\t Unico aluno na pilha foi removido.");
    }
    else if ((*topo)->next != NULL && strcasecmp((*topo)->nome, nome_aluno) == 0)
    {
        tmp = (*topo);
        free(tmp);
        (*topo) = (*topo)->next;
        printf("\n\t Aluno removido no topo da pilha.");

    }
    else
    {

        while (aux->next != NULL && (strcasecmp(aux->next->nome, nome_aluno)) != 0)
        {
            aux = aux->next;
        }

        if (aux->next == NULL)
        {
            printf("\nAluno %s nao esta na lista.\n", nome_aluno);
        }

        else
        {
            tmp = aux->next;
            aux->next = tmp->next;
            free(tmp);
            printf("\n\t Aluno removido da pilha.");
        }


    }
}

pilha *retirar_aluno(pilha **topo)
{
    pilha *aux = (*topo);
    (*topo) = (*topo)->next;
    aux->next = NULL;
    return aux;
}

int main(void)
{
    int opcao, run = TRUE;
    int i = 0;
    pilha *alunos = NULL;
    pilha *aluno = NULL;
    char nome_aluno[30];
    do
    {
        (void)system("clear");
        printf("\n1. Inserir aluno");
        printf("\n2. Procurar aluno");
        printf("\n3. Eliminar aluno[irregular]");
        printf("\n4. Mostras alunos");
        printf("\n5. Retirar um aluno");
        printf("\n0. Sair");
        printf("\nSua opcao: ");
        (void)scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            insert_pilha(&alunos);
            break;
        case 2:
            printf("\nNome do aluno: ");
            fpurge(stdin);
            (void)scanf("%s", nome_aluno);
            if ((aluno = search_aluno(alunos, nome_aluno)) != NULL)
            {
                printf("\nNome: %s", aluno->nome);
                printf("\nDisciplinas: ");
                for (i = 0; i < aluno->num_disciplinas; i++)
                {
                    printf("%s ", aluno->discicplinas[i].descricao);
                }
                printf("\nEstado: %s", aluno->estado);
            }
            break;
        case 3:
            printf("\nNome do aluno: ");
            fpurge(stdin);
            (void)scanf("%s", nome_aluno);
            delete_aluno(&alunos, nome_aluno);
            break;
        case 4:
            show_pilha(alunos);
            break;
        case 5:
        {
            if (alunos != NULL)
            {

                pilha *aux = retirar_aluno(&alunos);
                if (aux != NULL)
                {
                    printf("\nAluno retirado: %s\n", aux->nome);
                    free(aux);
                }
            }
            break;
        }

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

