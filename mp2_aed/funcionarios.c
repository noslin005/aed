//
//  funcionarios.c
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 25/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#include "util.h"
#include "funcionarios.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

funcionario *emp_head; // apontador para inicio da lista de funcionarios

/* Inicia a lista */
void emp_init(void)
{
    emp_head = NULL;
}

/* Verifica se um funcionario esta registrado ou nao */
funcionario *emp_is_registered(int emp_nif)
{
    if (emp_head == NULL)
    {
        return NULL;
    }
    funcionario *current = emp_head;
    while (current != NULL)
    {
        if (current->nif == emp_nif)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// aloca espaco na memoria para um novo 'no' e completa-o com os dados do funcionario
funcionario *emp_new_node(void)
{
    funcionario *emp_exists = NULL;
    funcionario *novo = (funcionario *)malloc(sizeof(funcionario));
    if (novo == NULL)
    {
        fprintf(stderr, "\n\tFalta de memória");
        exit(1);
    }
    while (TRUE)
    {
        printf("\n\t\tNIF Funcionario [0 - Cancelar]: ");
        flush_buffer();
        (void)scanf("%d", &novo->nif);

        if (novo->nif == 0)
        {
            return NULL;
        }

        emp_exists = emp_is_registered(novo->nif);
        if (emp_exists == NULL)
        {
            break;
        }
        else
        {
            printf("\n\t\tEste funcionario já existe.");
        }
    }

    printf("\t\tNome: ");
    flush_buffer();
    (void)scanf("%s", novo->nome);

    printf("\t\tFuncao: ");
    flush_buffer();
    (void)scanf("%s", novo->funcao);

    printf("\t\tCategoria: ");
    flush_buffer();
    (void)scanf("%s", novo->categoria);

    printf("\t\tSalario: ");
    flush_buffer();
    (void)scanf("%f", &novo->salario);

    novo->next = NULL;

    return novo;
}

// insere um novo funcionario por ordem crescente de NIF
void emp_insert_ord()
{
    // cria um novo 'NO'
    funcionario *novo = emp_new_node();

    //verifica se foi alocado espco na memoria.
    if (novo == NULL)
    {
        return;
    }

    // Se a lista de funcionarios estiver vazia, insere no inicio
    if (emp_head == NULL)
    {
        emp_head = novo;
    }
    // Se o NIF do funcionario for menor do que aquele que esta no primeiro 'NO', insere no inicio
    else if (novo->nif < emp_head->nif)
    {
        novo -> next = emp_head;
        emp_head = novo;
    }
    else
    {

        funcionario *anterior = emp_head;
        funcionario *atual = emp_head -> next;


        // Percorre a lista a procura da posicao onde inserir o novo 'NO'
        while (atual != NULL && novo->nif > atual->nif)
        {
            anterior = atual;
            atual = atual -> next;
        }


        // Insere no final da lista, se depois da pesquisa e nao encontrar nenhum
        // funcionario com NIF maio do que aquele que foi fornecido (emp_nif)
        if (atual == NULL)
        {
            anterior -> next = novo;
        }
        // Senao, insere numa posiciao especifica
        else
        {
            novo -> next = atual;
            anterior -> next = novo;
        }
    }
}

// Funcao para procurar um funcionario por NIF ou por Nome
funcionario *emp_search_by(int nif, char *emp_nome)
{
    // Lista vazia
    if (emp_head == NULL)
    {
        return NULL;
    }
    // se nome do funcionario for passado como NULL, entao procura por NIF
    if (emp_nome == NULL)
    {
        return emp_is_registered(nif);
    }
    // senao procura por NOME
    funcionario *current = emp_head;
    while (current != NULL)
    {
        if (strcasecmp(current->nome, emp_nome) == 0)
        {
            return current; // retorna um pronteiro para o primero funcionario encontrado
        }
        current = current->next;
    }
    return NULL; // se nao encontra nenhum funcionario, retorna NULL;
}

// Menu para procurar um funcionario
void emp_search(void)
{
    int nif;
    char opcao, nome[20];
    funcionario *temp = NULL;
    printf("\t\tPesquisar por [N]NOME [I]NIF: ");
    flush_buffer();
    scanf("%c", &opcao);
    opcao = tolower(opcao);
    switch (opcao)
    {
    case 'n': //pesquisa por nome
    {
        printf("\t\tNome a procurar: ");
        scanf("%s", nome);

        temp = emp_search_by(0, nome);
        if (temp != NULL)
        {
            printf("\n\tNif: %d", temp->nif);
            printf("\n\tNome: %s", temp->nome);
            printf("\n\tFuncao: %s", temp->funcao);
            printf("\n\tCategoria: %s", temp->categoria);
            printf("\n\tSalario: %.2f\n", temp->salario);
            temp = NULL;
        }
        else
        {
            printf("\n\t\tFuncionario nao encontrado.");
        }
        break;
    }

    case 'i': // pesquisa por NIF
    {
        printf("\t\tNIF a pesquisar: ");
        scanf("%d", &nif);
        temp = emp_search_by(nif, NULL);
        if (temp != NULL)
        {
            printf("\n\tNif: %d", temp->nif);
            printf("\n\tNome: %s", temp->nome);
            printf("\n\tFuncao: %s", temp->funcao);
            printf("\n\tCategoria: %s", temp->categoria);
            printf("\n\tSalario: %.2f\n", temp->salario);
            temp = NULL;
        }
        else
        {
            printf("\n\t\tFuncionario nao encontrado.");
        }
        break;
    }

    default:
        printf("\t\tOpção inválida.");
        break;
    }
    pause();
}


void emp_delete(int emp_nif)
{
    if (emp_head == NULL)
    {
        printf("\n\t\tLista de funcionários está vazia.") ;
        return;
    }

    funcionario *tmpDelete = NULL; //ponteiro para o no a ser removido
    if (emp_head->next == NULL && emp_head->nif == emp_nif) // se for o unico elemento da lista
    {
        free(emp_head);
        emp_head = NULL;
    }
    else if (emp_head->next != NULL && emp_head->nif == emp_nif) // se estiver no inicio da lista
    {
        tmpDelete = emp_head;
        emp_head = emp_head->next;
        free(tmpDelete);
    }
    else
    {
        funcionario *current = emp_head;
        while (current->next != NULL && current->next->nif != emp_nif)
        {
            current = current->next;
        }

        if (current->next == NULL)
        {
            printf("\n\t\tFuncionario nao encontrado.");
        }
        else
        {
            tmpDelete = current->next;
            current->next = tmpDelete->next;
            free(tmpDelete);
        }

    }
}





// mostra a lista de funcionarios
void emp_show(void)
{
    if (emp_head == NULL)
    {
        printf("\n\t\tLista está vazia.");
        return;
    }
    funcionario *atual = emp_head;
    while (atual != NULL)
    {
        printf("\n\tNif: %d", atual->nif);
        printf("\n\tNome: %s", atual->nome);
        printf("\n\tFuncao: %s", atual->funcao);
        printf("\n\tCategoria: %s", atual->categoria);
        printf("\n\tSalario: %.2f\n", atual->salario);
        atual = atual->next;
    }
}

void emp_calcula_despesas()
{
    if (emp_head == NULL)
    {
        return;
    }
    // variaveis
    funcionario *current = NULL;
    float total = 0;
    char opcao, emp_categoria[20];
    int num_funcionario;
    //
    printf("\t\tDespesas [t]total ou por [c]categoria: ");
    flush_buffer();
    scanf("%c", &opcao);
    opcao = tolower(opcao);

    switch (opcao)
    {
    case 'c':
        num_funcionario = 0;
        printf("\t\tCategoria a procurar: ");
        scanf("%s", emp_categoria);
        current = emp_head;
        while (current != NULL)
        {
            if  (strcasecmp(current->categoria, emp_categoria) == 0)
            {
                total += current->salario;
                num_funcionario ++;
            }
            current = current->next;
        }
        if (num_funcionario > 0)
        {
            printf("\n\t\tDESPESA POR CATEGORIA");
            printf("\n\t\tCategoria: %s", emp_categoria);
            printf("\n\t\tTotal: %.2f\n", total);
        }
        else
        {
            printf("\n\tNão existem funcionários registrados nessa categoria: %s.\n", emp_categoria);
        }

        break;
    case 't': // calcula despesas totais
        num_funcionario = 0;
        current = emp_head;
        while (current != NULL)
        {
            num_funcionario++;
            total += current->salario;
            current = current->next;
        }
        if (num_funcionario > 0)
        {
            printf("\n\t\tDESPESA TOTAL DA UNIVERSIDADE: %.2f\n", total);
        }
        break;
    default:
        printf("\t\tOpção inválida.");
        break;
    }
    pause();
}




// submenu verificar funcionario
int emp_check(void)
{

    int option;
    system("cls||clear");
    printf_logo();
    puts("\t\tCONSULTAR FUNCIONÁRIOS");
    puts("\t\t===================================");
    puts("\t\t[1] - Funcao e Categoria do funcionário.");
    puts("\t\t[2] - Despesas com os funcionários.");
    puts("\t\t[3] - Menu anterior.");
    puts("\t\t[0] - Sair.");
    printf("\t\tOpcao: ");
    flush_buffer();
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        puts("\t\tPesquisa por Nome ou NIF.");
        emp_search();
        break;
    case 2:
        puts("\t\tConsulta despesas.");
        emp_calcula_despesas();
        break;
    case 3:
        break;
    case 0:
        exit(0);
    default:
        printf("\t\tOpcao invalida.");
        break;
    }
    return option;
}

void emp_submenu(void)
{
    int executar = 1;
    int submenu_activo;

    while (executar)
    {
        submenu_activo = submenu("Funcionarios");
        switch (submenu_activo)
        {
        case 0:
            exit(0);
        case 1: // novo funcionario
            emp_insert_ord();
            pause();
            break;
        case 2: // eliminar aluno
        {
            int emp_nif;
            printf("Nif do funcionário: ");
            (void)scanf("%d", &emp_nif);
            emp_delete(emp_nif);
            pause();
            break;
        }
        case 3: // verificar funcionario
        {
            int emp_option = 1;
            while (emp_option != 3)
            {
                emp_option = emp_check();
            }
            break;
        }
        case 4: // mostrar funcionario
            emp_show();
            pause();
            break;
        case 5: // menu anterior
            executar = 0; /* Termina o ciclo while e volta ao menu principal. */
            break;
        default:
            printf("\n\t\tOpcao invalida");
            break;
        }

    }
}


