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

}

int main(void)
{
    printf("\n\tTecle ENTER para continuar...");
    fflush(stdin);
    fpurge(stdin);
    getchar();
    return 1;
}
