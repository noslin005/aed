//
//  linked_list.h
//
//  Created by Nilson Lopes on 29/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#ifndef _liblinked_list_h
#define _liblinked_list_h
#define TRUE 1
#define FALSE 0

struct ll_node
{
    int data;
    struct ll_node *next;
};

extern struct ll_node *head;

// inicia a lista
void ll_init(void);

// verfica de a lista está vazia
int ll_isempty(void);

// aloca espaço para um novo "nó" da lista
struct ll_node *ll_new_node(int data);

// Insere novo no no inicio da lista
void ll_insert_beg(int data);

// insere novo "nó" no final da lista
void ll_insert_end(int data);

// insere novo "nó" numa determinada posicao (pos)
void ll_insert_pos(int pos, int data);

// Insere os 'no' de forma ordenado (por ordem crescente do valor/data)
void ll_insert_ord(int data);

// exclui um "nó" na cabeca, inicio da lista
void ll_delete_beg(void);

// exclui um "nó" na cauda, final da lista
void ll_delete_end(void);

// exclui um "nó" numa determinada posicao da lista
void ll_delete_pos(int pos);

// mostra no ecrã o conteudo da lista
void ll_show(void);

// Troca dois 'nos' de posicao e retorna o endereco do 'no' que esta em primeiro lugar
struct ll_node *ll_swap(struct ll_node *, struct ll_node *);

// Algoritmo buble sort para ordem a lista
void ll_buble_sort(void);

// Funcao extra, limpeza de buffer
void pause(void);
#endif
