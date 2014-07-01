//
//  queue.c
//  queue - Este programa serve mostra como utilizar listas encadeadas
//  para implementar Filas (queue em ingles).
//
//  Filas (Queue) diferem de Pilhas (Stack) e de Listas Simples, tendo em conta
//  que para implementa-las sera necessario dois ponteiros:
//      First (Primeiro) - que aponta para o inicio da fila
//      Last (Ultimo)    - que aponta para o final da fila
//  Ao ser inserido um novo elemento, este deve ser colocado no final da fila
//  O processo de remoção de um elemento da fila deve ser no inicio da fila.
//
//  Created by Nilson Lopes on 29/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

//#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

// Definição do 'no' a ser utilizado para implementar a pilha
struct q_node
{
    int data;
    struct q_node *next;
};
// Variaveis Globais que apontam para o inicio e o final da fila
struct q_node *first;
struct q_node *last;

// Inicia a fila
void q_init(void)
{
    first = last = NULL;
}

// aloca espaco para um novo 'no' a ser inserido na Fila
struct q_node *q_new_node(int valor)
{
    // aloca espaco para o novo 'no'
    struct q_node *tmp = (struct q_node *)malloc(sizeof(struct q_node));
    // se nao houver memoria suficiente
    if (tmp == NULL)
    {
        printf("\tFalta de memória.");
        exit(1);
    }
    // passa o parametro da funcao para o novo 'no' que voi alocado na memoria
    tmp->data = valor;
    tmp->next = NULL;
    return tmp; // retorna o endereço onde foi alocado a memoria para o 'no'
}

// verifica se um elemento ja esta na fila
int is_on_queue(int data)
{
    struct q_node *aux = first;
    if (last == NULL)   // se ultimo apontar para NULL, nao existem elementos na Fila
    {
        return FALSE;   // por isso retorna FALSE, i.e, o elemento nao existe na Fila
    }

    while (aux != NULL) // precorre a Fila
    {
        if (aux->data == data) // compara o elemento actual na FILA com o elemento a ser procurado
        {
            return TRUE;      // Se encontar o elemento, retorna TRUE, elemento existe na FILA
        }
        aux = aux->next;
    }
    return FALSE;           // se ao percorrer a fila, nao encontrar nehum elemento, logo
    // ele nao existe na fila, retorna FALSE
}

// Insere um novo 'no' na fila, sempre no final
void q_insert(int data)
{
    struct q_node *aux = q_new_node(data);
    aux->next = NULL;
    // se o ponteiro ultimo (last) apontar para NULL
    // entao a fila esta vazia
    if (last == NULL)
    {
        last = aux; // ultimo aponta para o novo 'no'
        last->next = NULL; // ultimo aponta para NULL, ou seja, nao existem 'nos' seguintes
        first = last; // primeiro e ultimo apontam para o mesmo lugar
    }
    else
    {
        last->next = aux; // coloca o novo 'no' no final
        last = last->next; // ultimo passa a ser o novo elemento colocado no final
        last->next = NULL; // nenhum elemento a seguir ao ultimo, por isso ele aponta para NULL
    }
}

// exclui o 'no' que esta no inicio da fila
void q_delete(void)
{
    if (last == NULL)
    {
        printf("\tFila vazia.");
    }
    else
    {
        struct q_node *tmp = first; // 'no' a ser removido aponta para o primeiro 'no'
        first = first->next; // primeiro aponta para o 'no' que estava na segunda posicao
        printf("\tElemento removido: %d", tmp->data);
        free(tmp); // liberta o espaco ocupado pelo 'no' que estava no inicio
        if (first == NULL)   // se todos os elementos foram removidos
        {
            last = NULL;     // e preciso que ultimo aponte para NULL
        }
    }
}

// mostra o conteudo da fila
void q_show(void)
{
    if (last == NULL)
    {
        printf("\tFila vazia.");
        return;
    }
    struct q_node *aux = first;
    printf("\tElementos na fila: ");
    while (aux != NULL)
    {
        printf("%d  ", aux->data);
        aux = aux->next;
    }
}

// Funcao auxiliar, para limpar o buffer e imprimir mensagem no ecra
// esperando o utlizador pressionar Enter para continuar
void pause(void)
{
    printf("\n\tTecle Enter para continuar ...");
    fflush(stdin);
    getchar();
}

// Funcao principal
int main(void)
{
    q_init(); //inicia a fila
    int run = 1, opcao, data;
    while (run)
    {
        (void)system("clear");
        printf("\n\t+===================================+");
        printf("\n\t|  Filas usando listas encadeadas   |");
        printf("\n\t+===================================+");
        printf("\n\t| Nilson Lopes <noslin005@gmail.com |");
        printf("\n\t+===================================+");
        printf("\n\t0. Sair");
        printf("\n\t1. Inserir.\n\t2. Retirar\n\t3. Mostrar");
        printf("\n\t4. Primeiro elemento.\n\t5. Ultimo elemento");
        printf("\n\n\tDigite sua opção: ");
        (void)scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:// sair
            run = 0;
            break;
        case 1:// inserir
            printf("\tDigite o numero: ");
            (void)scanf("%d", &data);
            if (is_on_queue(data))
            {
                printf("\tEste elemento já se encontra na fila.");
            }
            else
            {
                q_insert(data);
                printf("\tElemento inserido na fila com sucesso.");
            }
            pause();
            break;
        case 2:// retirar
            q_delete();
            pause();
            break;

        case 3:// Mostrar
            q_show();
            pause();
            break;

        case 4:// Primeiro
            if (last != NULL)
            {
                printf("\nPrimeiro elemento da fila: %d", first->data);
            }
            else
            {
                printf("\tPilha vazia");
            }
            pause();
            break;

        case 5:// Ultimo
            if (last != NULL)
            {
                printf("\nUltimo elemento da fila: %d", last->data);
            }
            else
            {
                printf("\tPilha vazia");
            }
            pause();
            break;

        default:
            printf("\n\tOpção errada.");
            pause();
            break;
        }
    }
    return 0;
}
