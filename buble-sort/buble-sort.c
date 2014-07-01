    //
    //  buble-sort.c
    //  buble-sort
    //
    //  Created by Nilson Lopes on 30/06/14.
    //  Copyright (c) 2014 Nilson Lopes. All rights reserved.
    //

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
void swap(int* array, int index1, int index2)
{
    int temp;
    temp = array[index1];
    array[index1]=array[index2];
    array[index2]= temp;
}

void bubleSort(int* array, int max)
{
    int swapped;
    int i;
    do{
        swapped = FALSE;
        for (i= 1; i < max; i++) {
            if (array[i]<array[i-1])
            {
                swap(array, i, i-1);
                swapped = TRUE;
            }
        }
        
    }
    while (swapped == TRUE);
}

void bubleSort2(int* data, int n)
{
    int step, i;
    int temp;
    for(step=0;step<n-1;++step)
        for(i=0;i<n-step-1;++i)
        {
            if(data[i]>data[i+1])
            {
                temp=data[i];
                data[i]=data[i+1];
                data[i+1]=temp;
            }
        }
}

int main(void)
{
    int *vetor = NULL;
    int num, i;
    
    printf("Quantos elementos deseja colocar no vector: ");
    (void)scanf("%d", &num);
    vetor =(int *)malloc(num * sizeof(int));
    printf("Introduza os numeros:\n");
    for (i=0; i<num; i++) {
        (void)scanf("%d", &vetor[i]);
    }
    printf("\nVector antes da ordenacão:\n");
    for (i=0; i<num; i++) {
        printf("%d ", vetor[i]);
    }
    bubleSort(vetor, num);
    printf("\nVector Depois da ordenacão:\n");
    for (i=0; i<num; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\nTecle Enter para terminar ... \n");
    fflush(stdin);
    getchar();
    return 0;
}