//
//  stack.h
//
//  Created by Nilson Lopes on 29/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#ifndef _libstack_h
#define _libstack_h

struct stack_node{
    int data;
    struct stack_node *next;
};

// global
// ponteiro que aponta para a cabeca da lista, ou seja, o topo
// da pilha.
extern struct stack_node *head;

// Inicia a lista/pilha
void stack_init(void);

// Verifica se a pilha esta vazia
int stack_isempty(void);

//aloca memoria para un novo novo no a ser inserido na pilha
struct stack_node* new_node(int data, struct stack_node *);

// coloca um novo no no inicio da lista, ou seja, no topo da pilha
void stack_push(int data);

// retira um elemento da pilha
void stack_pop(void);

// mostra o conteudo da pilha
void stack_show(void);

// funcao extra
// limpa o buffer e espera digitar enter pa continuar o programa
void pause(void);
#endif
