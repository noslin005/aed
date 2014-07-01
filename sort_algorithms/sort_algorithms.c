/*
 * sort_algorithms.c
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



void pause(void)
{
    printf("\n\tTecle Enter para continuar ...\n");
    fpurge(stdin);
    getchar();
}



/* Troca dois elementos de posicao dentro de um vetor */
void swap(l_int *vetor, int i, int j)
{
    l_int tmp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = tmp;
}




/**/
void quick_sort(l_int *vetor, int size)
{
    return;
}



/**/
void buble_sort(l_int *vetor, int size)
{
    int sorted;
    int i;
    do
    {
        sorted = FALSE;
        for (i = 1; i < size; i++)
        {
            if (vetor[i] < vetor[i - 1])
            {
                swap(vetor, i, i - 1);
                sorted = TRUE;
            }
        }

    }
    while (sorted == TRUE);
}



/**/
void merge_sort(l_int *vetor, int size)
{
    return;
}




/* Pesquisa um valor(chave) no vector usando linear/sequencial */
int linear_search(l_int *vetor, int size, l_int key)
{
    int pos = 0;
    while (pos < size)
    {
        if (vetor[pos] == key)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}



/* Algoritmo de pesquisa binaria */
int binary_search(l_int *vetor, int size, l_int key)
{
    int left = 0;
    int right = size - 1;
    int midle = 0;
    while (left <= right)
    {
        midle = (left + right) / 2;
        if (key == vetor[midle])
        {
            return midle;
        }
        // valor esta à esquerda
        else if (key < vetor[midle])
        {
            right = midle - 1;
        }
        else
        {
            left = midle + 1;
        }

    }
    return -1; // valor/key nao for encontrado
}
