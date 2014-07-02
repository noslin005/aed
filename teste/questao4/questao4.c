#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE  1
#define FALSE 0
typedef struct
{
    char descricao[30];
} Disciplina;

typedef struct q_node
{
    char nome[30];
    Disciplina disciplinas[3];
    char categoria[30];
    struct q_node *next;
} fila;

fila *new_node(void)
{
    int i;
    fila *aux = (fila *)malloc(sizeof(fila));

    if (aux == NULL)
    {
        fprintf(stderr, "Falta de memoria.");
        exit(1);
    }
    printf("Nome: ");
    fpurge(stdin);
    (void)scanf("%s", aux->nome);

    for (i = 0; i < 3; ++i)
    {
        printf("%iº Disciplina: ", i + 1);
        fpurge(stdin);
        (void)scanf("%s", aux->disciplinas[i].descricao);
    }
    printf("Categoria: ");
    fpurge(stdin);
    (void)scanf("%s", aux->categoria);

    aux->next = NULL;
    return aux;
}

void insert_fila(fila **primeiro, fila **ultimo)
{
    fila *novo = new_node();
    novo->next = NULL;
    if ((*ultimo) == NULL)
    {
        (*ultimo) =  novo;
        (*ultimo)->next = NULL;
        (*primeiro) = (*ultimo);
    }
    else
    {
        (*ultimo)->next = novo;
        (*ultimo) = (*ultimo)->next;
        (*ultimo)->next = NULL;
    }
}

void mostrar_fila(fila *primeiro)
{
    if (primeiro == NULL)
    {
        printf("Fila esta vazia.\n");
    }
    else
    {
        int i;
        fila *aux = primeiro;
        while (aux != NULL)
        {
            printf("\nNome: %s", aux->nome);
            printf("\nDisciplinas: ");
            for ( i = 0; i < 3; ++i)
            {
                printf("%s ", aux->disciplinas[i].descricao);
            }
            printf("\nCategoria: %s\n", aux->categoria);
            aux = aux->next;
        }
    }
}

int docente_categoria(fila *primeiro, char nome_categoria[30])
{
    int contador = 0;
    fila *aux = primeiro;
    while (aux != NULL)
    {
        if (strcasecmp(aux->categoria, nome_categoria) == 0)
        {
            printf("\nNome: %s", aux->nome);
            printf("\nCategoria: %s", aux->categoria);
            contador++;
        }
        aux = aux->next;
    }
    return contador;
}

int docente_disciplina(fila *primeiro, char nome_disciplina[30])
{
    int i, contador = 0;
    fila *aux = primeiro;
    while (aux != NULL)
    {
        for (i = 0; i < 3; ++i)
        {
            if (strcasecmp(aux->disciplinas[i].descricao, nome_disciplina) == 0)
            {

                printf("\nNome: %s", aux->nome);
                printf("\nCategoria: %s", aux->categoria);
                printf("\nDisciplina: %s\n", aux->disciplinas[i].descricao);
                contador++;
            }
        }
        aux = aux->next;
    }
    return contador;
}



int main(void)
{
    int opcao, run = TRUE;
    fila *primeiro = NULL;
    fila *ultimo = NULL;

    char tmp_categoria[30];
    char tmp_disciplina[30];

    int tmp_numero = 0;
    do
    {
        (void)system("clear");
        printf("\n1. Inserir docente");
        printf("\n2. Nº docentes[categoria]");
        printf("\n3. Docentes AED[Disciplina]");
        printf("\n4. Mostras docentes");
        printf("\n0. Sair");
        printf("\nSua opcao: ");
        (void)scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            insert_fila(&primeiro, &ultimo);
            break;
        case 2:
            if (primeiro == NULL )
            {
                printf("\nFila vazia\n");
            }
            else
            {
                printf("Informe a categoria: ");
                (void)scanf("%s", tmp_categoria);
                tmp_numero = docente_categoria(primeiro, tmp_categoria);
                if (tmp_numero == 0)
                {
                    printf("\nCategoria %s nao existe\n", tmp_categoria);
                }
                else
                {
                    printf("\nNº de docentes na categoria %s: %d\n", tmp_categoria, tmp_numero);
                }
            }
            break;
        case 3:
            if (primeiro == NULL )
            {
                printf("\nFila vazia\n");
            }
            else
            {
                printf("Informe a disciplina: ");
                (void)scanf("%s", tmp_disciplina);
                tmp_numero = docente_disciplina(primeiro, tmp_disciplina);
                if (tmp_numero == 0)
                {
                    printf("\nDisciplina %s nao existe\n", tmp_disciplina);
                }
                else
                {
                    printf("\nNº de docentes na disciplina %s: %d\n", tmp_disciplina, tmp_numero);
                }
            }
            break;
        case 4:
            mostrar_fila(primeiro);
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
