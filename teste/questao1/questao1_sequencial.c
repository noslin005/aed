#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void pause(void)
{
    printf("\n\ttecle Enter para continuar.");
    fpurge(stdin);
    getchar();
}

int *criar_vector(int tamanho)
{
    int *vector;
    vector = (int *)malloc(tamanho * sizeof(int));
    if (vector == NULL)
    {
        fprintf(stderr, "Falta de memoria.");
        pause();
        exit(1);
    }
    return vector;
}

void preencher_vector(int *vector, int tamanho)
{
    int i;
    for ( i = 0; i < tamanho; ++i)
    {
        printf("\t%d Numero: ", i + 1);
        (void)scanf("%d", &vector[i]);
    }
}

void imprimir_vector(int *vector, int tamanho)
{
    int pos = 0;
    printf("\n\n\tConteudo do vector: \n\t");
    while (pos < tamanho)
    {
        printf("%d ", vector[pos]);
        pos++;
    }
    printf("\n\t");
}

int pesquisa_sequencial(int *vector, int tamanho, int valor_procura)
{
    int pos = 0;
    while (pos < tamanho)
    {
        if (vector[pos] == valor_procura)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

int pesquisa_binaria(int *vector, int tamanho, int valor_procura)
{
    int esquerda = 0;
    int direita = tamanho - 1;
    while (esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;
        if (vector[meio] == valor_procura)
        {
            return meio;
        }
        else if (valor_procura < vector[meio])
        {
            direita = meio - 1;
        }
        else
        {
            esquerda = meio + 1;
        }
    }
    return -1;
}

void buble_sort(int *vector, int tamanho)
{
    int sorted;
    int i, tmp;
    do
    {
        sorted = FALSE;
        for (i = 1; i < tamanho; ++i)
        {
            if (vector[i] < vector[i - 1])
            {
                tmp = vector[i - 1];
                vector[i - 1] = vector[i];
                vector[i] = tmp;
                sorted = TRUE;

            }
        }

    }
    while (sorted == TRUE);
}


int main(void)
{
    int opcao, run = TRUE;
    int sorted = FALSE;
    int *vector = NULL;
    int tamanho, valor_procura, posicao;
    do
    {
        (void)system("clear");
        printf("\n\t1. Preencher vector.");
        printf("\n\t2. Pesquisa sequencial.");
        printf("\n\t3. Pesquisa Binaria.");
        printf("\n\t4. Ordenar [Buble Sort]");
        printf("\n\t0. Sair");

        if (vector != NULL)
        {
            imprimir_vector(vector, tamanho);
        }

        printf("\n\tSua opcao: ");
        (void)scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:

            printf("\n\tTamanho do vector: ");
            (void)scanf("%d", &tamanho);
            free(vector);
            vector = criar_vector(tamanho);
            if (vector != NULL)
            {
                preencher_vector(vector, tamanho);
            }
            break;
        case 2:
            if (vector != NULL)
            {
                printf("\n\tNumero a procurar: ");
                (void)scanf("%d", &valor_procura);
                posicao = pesquisa_sequencial(vector, tamanho, valor_procura);
                if (posicao != -1)
                {
                    printf("\n\tValor encontrado na posicao %d", posicao + 1);
                }
                else
                {
                    printf("\n\tValor nao se encontra no vector");
                }
            }
            break;
        case 3:
            if (vector != NULL && sorted == TRUE)
            {
                printf("\n\tNumero a procurar: ");
                (void)scanf("%d", &valor_procura);
                posicao = pesquisa_binaria(vector, tamanho, valor_procura);
                if (posicao != -1)
                {
                    printf("\n\tValor encontrado na posicao %d", posicao + 1);
                }
                else
                {
                    printf("\n\tValor nao se encontra no vector");
                }
            }
            break;
        case 4:
            buble_sort(vector, tamanho);
            sorted = TRUE;
            break;
        case 0:
            break;
        default:
            printf("\n\tOpcao invalida.");
        }
        pause();
    }
    while (run == TRUE);
    return 0;
}
