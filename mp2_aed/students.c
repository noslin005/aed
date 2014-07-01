//
//  students.c
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 23/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//
#include "util.h"
#include "students.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

struct std_node *std_head = NULL;

void std_init(void)
{
    std_head = NULL;
}

int std_is_registered(int std_num)
{
    
    if (std_head == NULL) {
        return 0;
    }
    struct std_node * current_node = std_head;
    while (current_node != NULL) {
        if (current_node->numero == std_num) {
            return 1;
        }
    }
    return 0;
}
/* aloca espaço na memoria para um novo elemento (nodo) da lista alunos */
struct std_node *std_new_node(void)
{
    struct std_node *tmp = (struct std_node *)malloc(sizeof(struct std_node));
    char answer = 's';
    int i = 0;
    if (tmp == NULL) {
        printf("Falta de memória");
        exit(1);
    }
inicio:
    printf("\t\tNº do Aluno [0 - Cancelar]: ");
    scanf("%d",&tmp->numero);
    if (tmp->numero == 0)
    {
        return NULL;
    }
    if (std_is_registered(tmp->numero) == 1)
    {
        printf ("\t\tEste aluno já existe.\n");
        goto inicio;
    }
    printf("\n");
    printf("\t\tNome: ");
    (void)scanf("%s", tmp->nome);
    printf("\t\tCurso: ");
    (void)scanf("%s", tmp->curso);
    printf("\t\tAno de curso: ");
    (void)scanf("%d", &tmp->ano_curso);
    printf("\t\tEstado: ");
    (void)scanf("%d", &tmp->estado);
    
    do{
        printf("\t\tDiciplina %d: ", i+1);
        (void)scanf("%s", tmp->disciplinas[i].descricao);
        printf("Adicionar mais disciplinas: (S = Sim)? ");
        flush_buffer();
        (void)scanf("%c", &answer);
        i++;
    }while ((answer == 's' || answer == 'S') && i < NUM_DICIPLINA);
    
    tmp->next = NULL;
    return tmp;
}


void std_insert(void)
{
    struct std_node * tmp = std_new_node();
    if (tmp == NULL) {
        return;
    }
    if (std_head == NULL) {
        tmp->next = std_head;
        std_head = tmp;
    }else{
        struct std_node *current_node = std_head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        tmp->next = NULL;
        current_node->next = tmp;
    }
}

void std_print_header(void){
    printf("\n\t\tLista de alunos:\n");
    printf("\n+-----+----------------+-------+-----+------------+-----------------+");
    printf("\n| Nº  | Nome           | Curso | Ano | Estado     | Disciplinas |");
    printf("\n+-----+----------------+-------+-----+------------+-------------+\n");
}

void std_show(void)
{
    int i;
    if (std_head == NULL) {
        printf("\n\t\tLista de alunos está vazia.");
        return;
    }
    struct std_node* current_node = std_head;
    std_print_header();
    while (current_node != NULL) {
        i= 0;
        printf("|%4d ", current_node->numero);
        printf("|%15s ", current_node->nome);
        printf("|%6s ", current_node->curso);
        printf("|%4d ", current_node->ano_curso);
        printf("|%11d |", current_node->estado);
        while (current_node->disciplinas[i].descricao != NULL && i < NUM_DICIPLINA) {
            printf("%5s ", current_node->disciplinas[i].descricao);
            i++;
        }
        printf("\n");
        current_node = current_node->next;
    }
}

void std_submenu(void)
{
    int executar = 1;
    int submenu_activo;
    
    while (executar)
    {
        submenu_activo = submenu("Alunos");
        switch (submenu_activo)
        {
            case 1: // novo aluno
                std_insert();
                pause();
                break;
            case 2: // eliminar aluno
                pause();
                break;
            case 3: // verificar aluno
            {
                int std_option = 1;
                while (std_option != 4) {
                    std_option = std_check();
                }
                break;
            }
            case 4: // mostrar aluno
                std_show();
                pause();
                break;
            case 5: // menu anterior
                executar = 0; /* Termina o ciclo while e volta ao menu principal. */
                break;
        }
        
    }
}

int std_check(void)
{
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
            break;
        }
        case 2:
        {
            char tmpCurso[20];
            puts("\t\tCONSULTA:: ALUNOS POR CURSO: ");
            printf("\t\tCurso a procurar: ");
            scanf("%s", tmpCurso);
            break;
        }
        case 3:
            puts("\t\tALUNOS IRREGULARES: ");
            break;
        default:
            puts("\t\tOpção inválida.");
            pause();
            break;
    }
    return option;
}