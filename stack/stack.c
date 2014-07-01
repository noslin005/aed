//
//  stack.c
//
//  Created by Nilson Lopes on 29/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack_node* head =  NULL;

// inicia a pilha
void stack_init(void)
{
    head = NULL;
}

// verifica se a pilha a esta vazia
int stack_isempty(void)
{
    return head == NULL;
}

// aloca memoria para un novo novo no a ser inserido na pilha
// a insercao é feita no inicio
struct stack_node* new_node(int data, struct stack_node *next)
{
    struct stack_node* aux = (struct stack_node *)malloc(sizeof(struct stack_node));
    if (aux == NULL) {
        printf("\n\tErro. Falta de memória.\n");
        exit(1);
    }
    aux->data = data;
    aux->next = next;
    return aux;
}

// coloca um novo no no inicio da lista, ou seja, no topo da pilha
void stack_push(int data)
{
    head = new_node(data, head);
}

// retira um elemento da pilha
void stack_pop(void)
{
    int item;
    if (head==NULL)
    {
        printf("\n\tPilha vazia, sem elementos.\n");
        return;
    }
    item = head->data;
    struct stack_node *aux = head->next;
    free(head);
    head = aux;
    printf("\n\tElemento retirado: %d", item);
}

// mostra o conteudo da pilha
void stack_show(void)
{
    struct stack_node * aux = head;
    while (aux != NULL)
    {
        printf("\t %d\n", aux->data);
        aux = aux->next;
    }
}

// limpa o buffer e espera digitar enter pa continuar o programa
void pause(void){
    printf("\n\tTecle Enter para continuar ...");
    fpurge(stdin);
    getchar();
    
}
// funcao principal
int main(void)
{
    int data, opcao;
    stack_init();
    while(1){
        (void)system("clear");
        printf("\n\t** Pilhas com Listas Encadeadas **");
        printf("\n\t**********************************");
        printf("\n\tNilson Lopes <noslin005@gmail.com>");
        printf("\n\t**********************************");
        printf("\n\t1. Colocar\n\t2. Retirar\n\t3. Verificar se Vazia\n\t4. Mostrar\n\t0. Sair");
        printf("\n\n\tDigite a sua opção: ");
        fpurge(stdin);
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
            {
                printf("\n\tValor a ser colocado: ");
                fpurge(stdin);
                (void)scanf("%d", &data);
                stack_push(data);
                break;
            }
            case 2:
            {
                stack_pop();
                pause();
                break;
            }
            case 3:
            {
                data = stack_isempty();
                if (data == 0) {
                    printf("\n\tPilha nao está vazia.\n");
                }else{
                    printf("\n\tPilha vazia.\n");
                }
                pause();
                break;
            }
            case 4:
            {
                printf("\n\tConteúdo da pilha:\n");
                stack_show();
                pause();
                break;
            }
            case 0:
                exit(0);
            default:
                printf("\tOpcao errada.");
                pause();
                break;
        }
    }
    return 0;
}

