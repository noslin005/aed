#include <stdio.h>
#include <stdlib.h>

/* Defincao e criacao da estrutura de dados */
struct l_node
{
    int codigo;
    char endereco[30];
    float peso;
    struct l_node *next;
};

/* Ponteiro para a cabeça da Lista, ou seja, o inicio da lista. */
struct l_node *head = NULL;

struct l_node *new_node(void)
{
    struct l_node *novo = (struct l_node *)malloc(sizeof(struct l_node));

    if (novo == NULL)
    {
        fprintf(stderr, "\n\tFalta de memoria.");
        exit(1);
    }
    novo->next = NULL;
    return novo;
}

int main(void)
{
    printf("\n\tTecle ENTER para continuar...");
    fflush(stdin);
    fpurge(stdin);
    getchar();
    return 1;
}
