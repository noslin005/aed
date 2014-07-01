//
//  linked_list.c
//
//  Created by Nilson Lopes on 29/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


struct ll_node *head = NULL;


void ll_init(void)
{
    head = NULL;
}

int ll_isempty(void)
{
    return head == NULL;
}

struct ll_node *ll_new_node(int data)
{
    struct ll_node *aux = (struct ll_node *)malloc(sizeof(struct ll_node));
    if (aux == NULL)
    {
        printf("\n\tErro. Falta de memória.");
        pause();
        exit(1);
    }
    aux->data = data;
    aux->next = NULL;
    return aux;
}

void ll_insert_beg(int data)
{
    struct ll_node *tmp = ll_new_node(data);
    tmp->next = head;
    head = tmp;
}

void ll_insert_end(int data)
{
    struct ll_node *tmp = ll_new_node(data);

    //Lista vazia, insere o "no" no inicio
    if (head == NULL)
    {
        tmp->next = head;
        head = tmp;
    }
    else
    {
        struct ll_node *aux = head;
        // procura o ultimo "no" na lista
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        // insere o "no" na ultima posicao da lista
        aux->next = tmp;
    }
}

void ll_insert_pos(int pos, int data)
{
    struct ll_node *tmp = ll_new_node(data);
    int tmp_pos = 1;
    // Lista vazia ou se a posicao for 1, insere no inicio
    if (head == NULL || pos == 1)
    {
        tmp->next = head;
        head = tmp;
    }
    else
    {
        struct ll_node *aux = head;
        while (aux->next != NULL && tmp_pos != pos - 1)
        {
            aux = aux->next;
            tmp_pos++;
        }

        // se a posicao coincidir com o final da lista
        // insere no final
        if (aux->next == NULL && pos == tmp_pos)
        {
            tmp->next = NULL;
            aux->next = tmp;
        }
        // se a posciao estiver fora do limite da lista nao insere
        else if ((aux->next == NULL && pos > tmp_pos) || pos < 0)
        {
            printf("\n\tPosicao inválida.");
            return;
        }
        // se a posicao estiver dentro dos limites da lista, ou seja, no meio da lista, insere na posicao indicada.
        else
        {
            tmp->next = aux ->next;
            aux->next = tmp;
        }
    }
}
// exclui o 'no' na cabeca, inicio da lista
void ll_delete_beg()
{
    if (head != NULL)
    {
        struct ll_node *tmpDelete;
        tmpDelete = head;
        head = head->next;
        free(tmpDelete);
        printf("\tFoi excluido o nó na cabeça, com sucesso!");
    }
    else
    {
        printf("Lista vazia. Não foi possivel excluir o nó.");
    }
}

// exclui o 'no' na cauda, fim da lista
void ll_delete_end(void)
{
    if (head == NULL)
    {
        printf("Lista vazia. Não foi possivel excluir o nó.");
    }
    else
    {
        struct ll_node *aux = head;
        if (aux->next == NULL)
        {
            head = NULL;
            free(aux);
        }
        else
        {

            struct ll_node *tmpDelete = NULL;

            while (aux->next->next != NULL)
            {
                aux = aux->next;
            }
            tmpDelete = aux->next;
            aux->next = NULL;
            free(tmpDelete);
        }
    }
}

// exclui um 'no' numa determinada posicao
void ll_delete_pos(int pos)
{
    struct ll_node *tmpDelete = NULL;
    // lista vazia
    if (head == NULL)
    {
        printf("Lista vazia. Não foi possivel excluir o nó.");
        return;
    }
    // posicao negativa ou 0
    else if (pos < 1)
    {
        printf("Posicao inválida!");
    }
    // remover o primeiro elemento
    else if (pos == 1)
    {
        tmpDelete = head;
        head = head->next;
        free(tmpDelete);
    }
    // caso geral
    else
    {
        struct ll_node *aux = head;
        int i = 1;
        while (aux->next != NULL && i != pos - 1)
        {
            aux = aux->next;
        }
        // se posico indica estiver alem do numero de elementos da lista
        if (aux->next == NULL)
        {
            printf("Posicao errada ou fora do limite.");
        }
        else
        {
            tmpDelete = aux->next;
            aux->next = tmpDelete->next;
            free(tmpDelete);
        }
    }
}

// mostra no ecra o conteudo da lista
void ll_show(void)
{
    if (head == NULL)
    {
        printf("\n\tLista vazia.");
        return;
    }
    struct ll_node *tmp = head;
    printf("\n\t===================");
    printf("\n\tElementos da lista: ");
    while (tmp != NULL)
    {
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n\t===================");
}

// Troca dois 'nos' de posicao e retorna o endereco do 'no' que esta em primeiro lugar
struct ll_node *ll_swap(struct ll_node *no_a, struct ll_node *no_b )
{
    no_a->next = no_b->next; // no_a fica depois de no_b
    no_b->next = no_a; // no_b passa a ser o primeiro
    return no_b; // retorna no_b, que esta primeiro
}

// Insere os 'no' de forma ordenado (por ordem crescente do valor/data)
void ll_insert_ord(int data)
{

    struct ll_node *new = ll_new_node(data);
    if (head == NULL)
    {
        new->next = head;
        head = new;
    }
    else
    {
        struct ll_node *aux = head;
        while (aux->next != NULL && (aux->data) < (new->data))
        {
            aux = aux->next;
        }
        if (head->next == NULL)
        {
            new->next = head;
            head = new;
        }
        else
        {
            new->next = aux->next;
            aux->next = new;
        }
    }
}

// algoritmo buble sort para listas
void ll_buble_sort (void)
{
    struct ll_node *atual;
    struct ll_node *seguinte;

    int sorted = TRUE;
    struct ll_node *top = (struct ll_node *)malloc(sizeof(struct ll_node));
    if (top == NULL)
    {
        printf("\n\tFalta de memoria.");
        exit(1);
    }
    top->next = head;
    if (head != NULL && head->next != NULL)
    {

        while (sorted == TRUE)
        {
            sorted = FALSE;
            seguinte = top;
            atual = top->next;
            while (atual->next != NULL)
            {
                if (atual->data > atual->next->data)
                {
                    seguinte->next = ll_swap(atual, atual->next);
                    sorted = TRUE;
                }
                seguinte = atual;
                if (atual->next != NULL)
                {
                    atual = atual->next;
                }
            }

        }
    }
    //atual = top->next;
    free(top);

}
void pause(void)
{
    printf("\n\tTecle Enter para continuar ...");
    //fpurge(stdin); OS X
    //__fpurge(stdin); Linux
    fflush(stdin); // Windows
    getchar();
}

int main(void)
{
    int opcao, data, pos;
    int run = 1;

    ll_init();
    while (run)
    {
        (void)system("clear");
        printf("\n\t*** Listas Simplesmente Encadeada ***");
        printf("\n\t*************************************");
        printf("\n\t* Nilson Lopes <noslin005@gmail.com *");
        printf("\n\t*************************************");
        printf("\n\t0. Sair");
        printf("\n\t1. Inserir Inicio.\n\t2. Inserir Fim\n\t3. Inserir Meio");
        printf("\n\t4. Remover Inicio.\n\t5. Remover Fim\n\t6. Remover Meio");
        printf("\n\t7. Inserir (ordenado) \n\t8. Ordenar: Buble Sort");
        printf("\n");
        ll_show();
        printf("\n\n\tDigite sua opção: ");
        (void)scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:// sair
            run = 0;
            break;
        case 1:// inserir no inicio
            printf("\tDigite um numero: ");
            (void)scanf("%d", &data);
            ll_insert_beg(data);
            pause();
            break;
        case 2:// inserir no final
            printf("\tDigite um numero: ");
            (void)scanf("%d", &data);
            ll_insert_end(data);
            pause();
            break;

        case 3:// inserir no meio
            printf("\tDigite um numero: ");
            (void)scanf("%d", &data);
            printf("\tEm que posicao deseja inseri-lo? ");
            (void)scanf("%d", &pos);
            ll_insert_pos(pos, data);
            pause();
            break;

        case 4:// remover no inicio
            ll_delete_beg();
            pause();
            break;

        case 5:// remover no final
            ll_delete_end();
            pause();
            break;

        case 6:// remover no meio
            printf("\tEm que posicao deseja eliminar? ");
            (void)scanf("%d", &pos);
            ll_delete_pos(pos);
            break;
        case 7:
            printf("\tDigite um numero: ");
            (void)scanf("%d", &data);
            ll_insert_ord(data);
            pause();
            break;
        case 8:// ordenar buble sort
            ll_buble_sort();
            printf("\n\tLista ordenada com sucesso");
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