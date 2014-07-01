/*
 * main.c
 * Algotimos de Ordenaçao e pesquisa em vectores
 *
 * Created by Nilson Lopes on 30/06/14.
 * Copyright (c) 2014 Nilson Lopes. All rights reserved.
 */

#include "sort_algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0




// aloca espaco na memoria para um vector que é criado dinamicamente
l_int *create_vetor(int size)
{
    l_int *tmp = (l_int *)malloc(size * sizeof(l_int));
    return tmp;
}


// preenche o vector com numeros introduzidos pelo utilizador
void fill_vetor(l_int *vetor, int size)
{
    int i = 0;

    while (i < size)
    {
        printf("\tPosicao %d: ", i + 1);
        (void)scanf("%ld", &vetor[i]);
        i++;
    }
}

// imprime os elementos do vetor
void print_vetor(l_int *vetor, int size)
{
    int i = 0;
    printf("\n\t");
    while (i < size)
    {
        printf("%ld ", vetor[i]);
        i++;
    }
}

// funcao princial
int main(void)
{
    l_int *vetor = NULL; // ponteiro para vector do tipo long int
    int size;  // tamanho do vector
    int is_sorted = FALSE; // inicalmente o vetor nao esta ordenado.
    int option; // recebe a opcao do utilizador
    l_int key; // chave(valor) a ser procurado no vector
    int position; // toma valor -1 se valor/key  nao for encontrado ou a posicao onde o valor se encontra no vector
    int run = TRUE; // controla o menu, quando for FALSE termina o programa
    do
    {
        (void)system("clear");
        printf("\n\t=================================");
        printf("\n\tOrdenção e Pesquisa em vectores");
        printf("\n\t=================================");
        printf("\n\tNilson lopes <noslin005@gmail.com");
        printf("\n\t=================================");
        printf("\n\t0. Sair");
        printf("\n\t1. Criar/Preencher Vector.");
        printf("\n\t2. Destruir Vector.");
        printf("\n\t3. Imprimir Vector.");
        printf("\n\t4. Ordenar: Quick Sort.");
        printf("\n\t5. Ordenar: Buble Sort.");
        printf("\n\t6. Ordenar: Merge Sort.");
        printf("\n\t7. Pesquisa: Linear.");
        printf("\n\t8. Pesquisa: Binária.");
        printf("\n\tSua opcao: ");
        (void)scanf("%d", &option);
        switch (option)
        {
        case 0:
            run = FALSE;
            break;
        case 1:
            if (vetor == NULL)
            {
                printf("\n\tTamanho do vetor: ");
                (void)scanf("%d", &size);
                vetor = create_vetor(size);
                fill_vetor(vetor, size);
                is_sorted = FALSE;
            }
            else
            {
                printf("\n\tVetor ja foi criado. Use opcao 2 para destrui-la.");

            }
            break;
        case 2:
            free(vetor);
            vetor = NULL;
            is_sorted = FALSE;
            printf("\n\tVetor destruido com sucesso.");
            break;
        case 3:
            if (vetor == NULL)
            {
                printf("\n\tVetor ainda nao foi criado. Use opcao 1 para cria-la.");
            }
            else
            {
                print_vetor(vetor, size);

            }
            break;
        case 4:
            break;
        case 5:// buble_sort
            if (vetor == NULL)
            {
                printf("\n\tVetor ainda nao foi criado. Use opcao 1 para cria-la.");
            }
            else if (is_sorted == FALSE)
            {
                buble_sort(vetor, size);
                printf("\n\tVetor ordenado com sucesso.\n");
                is_sorted = TRUE;
                print_vetor(vetor, size);

            }
            else
            {
                printf("\n\tVetor já foi ordenado anteriormente.");

            }
            break;
        case 6:
            break;
        case 7:
            if (vetor == NULL)
            {
                printf("\n\tVetor ainda nao foi criado. Use opcao 1 para cria-la.");
            }
            else
            {
                printf("\n\tChave/Valor a ser procurado: ");
                (void)scanf("%ld", &key);
                position = linear_search(vetor, size, key);
                if (position != -1)
                {
                    printf("\n\tValor %ld esta na posicao %d do vetor", key, position + 1);
                }
                else
                {
                    printf("\n\tValor %ld nao se encontra no vetor", key);
                }
            }
            break;

        case 8:
            if (vetor == NULL)
            {
                printf("\n\tVetor ainda nao foi criado. Use opcao 1 para cria-la.");
            }
            else
            {
                if (is_sorted == FALSE)
                {
                    printf("\n\tVetor ainda não está ordenado.");
                    printf("\n\tA pesquisa binária é utilizada para vectores ordenados.");
                    printf("\n\tUtiliza um dos metodos de ordaneção e depois faça à pesquisa.");
                }
                else
                {
                    printf("\n\tChave/Valor a ser procurado: ");
                    (void)scanf("%ld", &key);
                    position = linear_search(vetor, size, key);
                    if (position != -1)
                    {
                        printf("\n\tValor %ld esta na posicao %d do vetor", key, position + 1);
                    }
                    else
                    {
                        printf("\n\tValor %ld nao se encontra no vetor", key);

                    }
                }
            }
            break;

        default:
            printf("\n\tOpcao invalida.");
            break;
        }
        pause();
    }
    while (run == TRUE);
    return 0;
}
