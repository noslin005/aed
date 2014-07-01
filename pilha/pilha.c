//
//  pilha.c
//
//  Created by Nilson Lopes on 01/07/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct p_node
{
    int codigo;
    char produto[20];
    struct p_node *prox;
} pilha;

/* ============================================================
    Prototipo das funcoes/metodos asociados à pilha
   ============================================================ */
void iniciar_pilha(pilha *cabeca);

pilha *novo_no();

void inserir_pilha(pilha **cabeca);

pilha *retirar_pilha(pilha **cabeca);

void mostrar_pilha(pilha *cabeca);

void esvaziar_pilha(pilha **cabeca);
/* ============================================================
    Funcoes extras
   ============================================================ */
void pause(void);

/* ============================================================
    Funcao principal
   ============================================================ */
int main(void)
{
    pilha *cabeca = NULL;
    pilha *no_retirado = NULL;
    int opcao;
    int executar = TRUE;

    //menu
    do
    {
        (void)system("clear");
        printf("\n\t  Pilha usando Listas Dinamicas");
        printf("\n\t---------------------------------");
        printf("\n\tNilson Lopes <noslin005@gmail.com");
        printf("\n\t=================================");
        printf("\n\t0. Sair");
        printf("\n\t1. Inserir");
        printf("\n\t2. Retirar");
        printf("\n\t3. Mostrar");
        printf("\n\t4. Esvaziar");
        printf("\n\n\tOpcao: ");
        (void)scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            executar = FALSE;
            break;
        case 1: // inserir
            inserir_pilha(&cabeca);
            mostrar_pilha(cabeca);
            break;
        case 2://retirar
            no_retirado = retirar_pilha(&cabeca);
            if (no_retirado != NULL)
            {
                printf("\n\tProduto retirado:\n");
                printf("\t%d - %s\n", no_retirado->codigo, no_retirado->produto);
                free(no_retirado);
                no_retirado = NULL;
            }
            break;
        case 3://mostrar
            mostrar_pilha(cabeca);
            break;
        case 4:// esvaziar
            esvaziar_pilha(&cabeca);
            break;
        default:
            printf("\n\tOpcao invalida.");
            break;
        }
        pause();
    }
    while (executar == TRUE);
    return 0;
}


pilha *novo_no()
{
    pilha *temp = (pilha *)malloc(sizeof(pilha));
    if (temp == NULL)
    {
        fprintf(stderr, "\tFalta de memoria");
        exit(0);
    }
    printf("\tCodigo: ");
    fpurge(stdin);
    (void)scanf("%d", &temp->codigo);
    printf("\tProduto: ");
    fpurge(stdin);
    (void)scanf("%s", temp->produto);
    return temp;
}


void inserir_pilha(pilha **cabeca)
{
    pilha *novo = novo_no();
    if ((*cabeca) == NULL)
    {
        novo->prox = NULL;
    }
    else
    {
        novo->prox = (*cabeca);
    }
    (*cabeca) = novo;
}

pilha *retirar_pilha(pilha **cabeca)
{
    if ((*cabeca) == NULL)
    {
        printf("\n\tPilha está vazia.");
        return NULL;
    }
    else
    {
        pilha *temp = (*cabeca);
        (*cabeca) = (*cabeca)->prox;
        return temp;
    }
}

void mostrar_pilha(pilha *cabeca)
{
    if (cabeca == NULL)
    {
        printf("\n\tPilha está vazia.");
    }
    else
    {
        pilha *atual = cabeca;
        printf("\n\tConteúdo da pilha:\n");
        while (atual != NULL)
        {
            printf("\t%d - %s\n", atual->codigo, atual->produto);
            atual = atual->prox;
        }
    }
}

void esvaziar_pilha(pilha **cabeca)
{
    if (*cabeca == NULL)
    {
        printf("\n\tPilha está vazia.");
    }
    else
    {

        pilha *atual = (*cabeca);
        while (atual != NULL)
        {
            pilha *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(atual);
        (*cabeca) = NULL;
    }
}

void pause(void)
{
    printf("\n\tTecle Enter para continuar ...");
    fpurge(stdin);
    getchar();
}
