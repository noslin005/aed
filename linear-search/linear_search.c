#include <stdio.h>
#include <stdlib.h>

void print_vetor(int *vetor, int size)
{
    int i;
    printf("\n\t");
    for (i = 0; i < size; ++i)
    {
        printf("%d ", vetor[i]);
    }
}
/*  Procura um valor(chave) no vector usando o metodo linear. Se a chave existir
    retorna a posicao onde ela esta, senao retorna -1.
        Pior Caso   : N buscas (valor nao encontrado ou valor no final)
        Melhor Caso : 1 (valor no inicio do vetor)
        Caso Medio  : (N+1)/2, ou seja valor esta no meio do vetor
*/
int linear_search(int *vetor, int key, int size)
{
    int pos = 0;
    /* Percorre o vector em busca do elemento a procurar
       O ciclo pode terminar de dois modos:
            1. O valor é encontrado, i.e, vetor[pos]== key
            2. Chegando ao final e nao encontrar a chave procurada, i.e, pos > size
       */
    while (pos < size && vetor[pos] != key)
    {
        pos++;
    }
    // Ao sair do ciclo se posicao for maior que o tamanho, nao encontrou a chave
    // retorna -1;
    if (pos > size)
    {
        return -1;
    }
    // senao é porque a chave foi encontrada a chave
    return pos;

}
int main(void)
{
    int size, i, chave;
    int *vetor = NULL;

    (void)system("clear");
    printf("\tQual o tamanho do vector? ");
    (void)scanf("%d", &size);

    // aloca espaco na memoria para do tamanho do vector
    vetor = (int *)malloc(size * sizeof(int));

    // preenchimento do vector
    printf("\tDigite os valores: \n");
    for (i = 0; i < size; ++i)
    {
        printf("\tPosicao %d: ", i + 1);
        (void)scanf("%d", &vetor[i]);
    }

    printf("\tChave(valor) a procurar: ");
    (void)scanf("%d", &chave);
    int posicao = linear_search(vetor, chave, size);
    if (posicao)
    {
        printf("\tChave %d encontrada na posicao %d", chave, posicao+1);
        print_vetor(vetor, size);
    }
    else
    {
        printf("\tChave %d nao encontrada", chave);
    }

    printf("\n\n\tTecle Enter para continuar ...\n");
    fpurge(stdin);
    getchar();
    return 0;
}