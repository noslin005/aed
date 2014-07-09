//
//  alunos.c
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 23/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//
#include "util.h"
#include "alunos.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct std_node *std_head = NULL; // prefixo std = student

void std_init(void)
{
    std_head = NULL;
}

struct std_node *std_is_registered(int std_num)
{

    if (std_head == NULL)
    {
        return NULL;
    }
    struct std_node *current_node = std_head;
    while (current_node != NULL)
    {
        if (current_node->numero == std_num)
        {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}
/* aloca espaço na memoria para um novo elemento (nodo) da lista alunos */
struct std_node *std_new_node(void)
{
    struct std_node *tmp = (struct std_node *)malloc(sizeof(struct std_node));
    int opt_estado;
    if (tmp == NULL)
    {
        printf("Falta de memória");
        exit(1);
    }

    while (TRUE)
    {
        printf("\t\tNº [0 - Cancelar]: ");
        flush_buffer();
        scanf("%d", &tmp->numero);

        if (tmp->numero == 0)
        {
            return NULL;
        }
        if (std_is_registered(tmp->numero) != NULL)
        {
            printf ("\t\tEste aluno já existe.\n");

        }
        else
        {
            break;
        }
    }
    printf("\t\tNome: ");
    flush_buffer();
    (void)scanf("%s", tmp->nome);

    printf("\t\tCurso: ");
    flush_buffer();
    (void)scanf("%s", tmp->curso);

    printf("\t\tAno de curso: ");
    flush_buffer();
    (void)scanf("%d", &tmp->ano_curso);


    do
    {
        printf("\t\tEstado\n\t\t\t1-Regular\n\t\t\t2-Irregular: ");
        fpurge(stdin);
        (void)scanf("%d", &opt_estado);
        if (opt_estado == 1)
        {
            strcpy(tmp->estado, "regular");
            break;
        }
        else if (opt_estado == 2)
        {
            strcpy(tmp->estado, "irrregular");
            break;
        }
        else
        {
            printf("\nOpcao invalida");
        }
    }
    while (opt_estado != 1 || opt_estado != 2);

    printf("\t\tNumero de disciplinas [Máximo %d]: ", NUM_DISCIPLINA);
    flush_buffer();
    (void)scanf("%d", &tmp->numDisciplinas);
    int i = 0;
    for (i = 0; i < tmp->numDisciplinas && i < NUM_DISCIPLINA; ++i)
    {
        printf("\t\t%d Diciplina: ", i + 1);
        flush_buffer();
        (void)scanf("%s", tmp->disciplinas[i].descricao);
    }

    tmp->next = NULL;
    return tmp;
}

// Insere novo aluno na lista de forma ordenada
void std_insert(void)
{
    // cria um novo 'NO'
    struct std_node *novo = std_new_node();

    //verifica se foi alocado espco na memoria.
    if (novo == NULL)
    {
        return;
    }

    // Se a lista de struct alunos estiver vazia, insere no inicio
    if (std_head == NULL)
    {
        std_head = novo;
    }
    // Se o numero do aluno for menor do que aquele que esta no primeiro 'NO', insere no inicio
    else if (novo->numero < std_head->numero)
    {
        novo -> next = std_head;
        std_head = novo;
    }
    else
    {
        struct std_node *anterior = std_head;
        struct std_node *atual = std_head -> next;

        // Percorre a lista a procura da posicao onde inserir o novo 'NO'
        while (atual != NULL && novo->numero > atual->numero)
        {
            anterior = atual;
            atual = atual -> next;
        }

        // Insere no final da lista, se depois da pesquisa nao encontrar nenhum
        // aluno com numero maio do que aquele que foi fornecido
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

// Funcao para procurar um struct std_node por numero ou por Nome
struct std_node *std_search_by(char *std_nome, char *std_curso)
{
    // Lista vazia
    if (std_head == NULL)
    {
        return NULL;
    }
    struct std_node *current = std_head;
    // pesquisa por NOMe
    if (std_curso == NULL)
    {
        while (current != NULL && std_nome != NULL)
        {
            if (strcasecmp(current->nome, std_nome) == 0)
            {
                return current; // retorna um pronteiro para o primero struct std_node encontrado
            }
            current = current->next;
        }
    }
    else if (std_curso != NULL && std_nome == NULL)
    {
        while (current != NULL)
        {
            if (strcasecmp(current->curso, std_curso) == 0)
            {

                int i = 0;
                printf("\n\tNº: %d", current->numero);
                printf("\n\tNome: %s", current->nome);
                printf("\n\tCurso: %s ", current->curso);
                printf("\n\tAno Curso: %d", current->ano_curso);
                printf("\n\tSituaçao: %s", current->estado);
                printf("\n\tDisciplinas: ");
                while (i < current->numDisciplinas)
                {
                    printf("%s ", current->disciplinas[i].descricao);
                    i++;
                }
                printf("\n");
            }
            current = current->next;
        }

    }
    return NULL; // se nao encontra nenhum aluno, retorna NULL;
}


// Funcao para procurar um struct std_node por numero ou por Nome
void std_irregular (void)
{
    // Lista vazia
    if (std_head == NULL)
    {
        return;
    }
    struct std_node *current = std_head;
    // pesquisa por NOMe

    while (current != NULL)
    {
        if (strcasecmp(current->nome, "irrregular") == 0)
        {
            int i = 0;
            printf("\n\tNº: %d", current->numero);
            printf("\n\tNome: %s", current->nome);
            printf("\n\tCurso: %s ", current->curso);
            printf("\n\tAno Curso: %d", current->ano_curso);
            printf("\n\tSituaçao: %s", current->estado);
            printf("\n\tDisciplinas: ");
            while (i < current->numDisciplinas)
            {
                printf("%s ", current->disciplinas[i].descricao);
                i++;
            }
            printf("\n");
        }
        current = current->next;
    }
}

void std_show(void)
{
    int i;
    if (std_head == NULL)
    {
        printf("\n\t\tLista de alunos está vazia.");
        return;
    }
    struct std_node *current_node = std_head;
    while (current_node != NULL)
    {
        i = 0;
        printf("\n\tNº: %d", current_node->numero);
        printf("\n\tNome: %s", current_node->nome);
        printf("\n\tCurso: %s ", current_node->curso);
        printf("\n\tAno Curso: %d", current_node->ano_curso);
        printf("\n\tSituaçao: %s", current_node->estado);
        printf("\n\tDisciplinas: ");
        while (i < current_node->numDisciplinas)
        {
            printf("%s ", current_node->disciplinas[i].descricao);
            i++;
        }
        printf("\n");
        current_node = current_node->next;
    }
}


void std_delete(int std_numero)
{
    if (std_head == NULL)
    {
        printf("\n\t\tLista de alunos está vazia.") ;
        return;
    }

    struct std_node *tmpDelete = NULL; //ponteiro para o no a ser removido
    if (std_head->next == NULL && std_head->numero == std_numero) // se for o unico elemento da lista
    {
        free(std_head);
        std_head = NULL;
        printf("\n\t\tAluno excluido com sucesso.");
    }
    else if (std_head->next != NULL && std_head->numero == std_numero) // se estiver no inicio da lista
    {
        tmpDelete = std_head;
        std_head = std_head->next;
        free(tmpDelete);
        printf("\n\t\tAluno excluido com sucesso.");
    }
    else
    {
        struct std_node *current = std_head;
        while (current->next != NULL && current->next->numero != std_numero)
        {
            current = current->next;
        }

        if (current->next == NULL)
        {
            printf("\n\t\tAluno nao encontrado.");
        }
        else
        {
            tmpDelete = current->next;
            current->next = tmpDelete->next;
            free(tmpDelete);
            printf("\n\t\tAluno excluido com sucesso.");
        }

    }
}

void std_submenu(void)
{
    int executar = 1;
    int submenu_activo;
    int std_numero;
    while (executar)
    {
        submenu_activo = submenu("Alunos");
        switch (submenu_activo)
        {
        case 0:
            exit(0);
        case 1: // novo aluno
            std_insert();
            break;
        case 2: // eliminar aluno
            printf("\n\t\tNº do aluno: ");
            (void)scanf("%d", &std_numero);
            std_delete(std_numero);
            break;
        case 3: // verificar aluno
        {
            int std_option = 1;
            while (std_option != 4)
            {
                std_option = std_check();
            }
            break;
        }
        case 4: // mostrar aluno
            std_show();
            break;
        case 5: // menu anterior
            executar = 0; /* Termina o ciclo while e volta ao menu principal. */
            break;

        default:
            printf("\n\t\tOpcao invalida.");
            break;
        }
        pause();

    }
}

int std_check(void)
{
    struct std_node *temp = NULL;
    int option;
    char s[80];

    system("cls||clear");
    printf_logo();
    puts("\t\tCONSULTAR ALUNO");
    puts("\t\t===================================");
    puts("\t\t[1] -> Por Nome.");
    puts("\t\t[2] -> Por Curso/Turma.");
    puts("\t\t[3] -> Em Estado Irregular.");
    puts("\t\t[4] -> Menu anterior.");
    puts("\t\t[0] -> Sair.");
    printf("\t\tEscolhe uma opcao: ");
    fgets(s, sizeof(s), stdin);
    option = atoi(s);
    switch (option)
    {
    case 1:
    {
        char tmpNome[20];
        puts("\t\tCONSULTA:: ALUNOS POR NOME: ");
        printf("\t\tNome a procurar: ");
        scanf("%s", tmpNome);
        temp = std_search_by(tmpNome, NULL);
        if (temp != NULL)
        {
            int i = 0;
            printf("\nNº: %d", temp->numero);
            printf("\nNome: %s", temp->nome);
            printf("\nCurso: %s ", temp->curso);
            printf("\nAno Curso: %d", temp->ano_curso);
            printf("\nSituaçao: %s", temp->estado);
            printf("\nDisciplinas: ");
            while (i < temp->numDisciplinas)
            {
                printf("%s ", temp->disciplinas[i].descricao);
                i++;
            }
            printf("\n");
            pause();
        }
        else
        {
            printf("\n\tEste aluno nao esta na lista.");
            pause();
        }
        break;
    }
    case 2:
    {
        char tmpCurso[20];
        puts("\t\tCONSULTA:: ALUNOS POR CURSO: ");
        printf("\t\tCurso a procurar: ");
        scanf("%s", tmpCurso);
        temp = std_search_by(NULL, tmpCurso);
        pause();
        break;
    }
    case 3:
        puts("\t\tALUNOS IRREGULARES: ");
        std_irregular();
        pause();
        break;
    case 4:
        break;
    default:
        puts("\t\tOpção inválida.");
        pause();
        break;
    }

    return option;
}
