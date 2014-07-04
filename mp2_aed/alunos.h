//
//  alunos.h
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 23/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#ifndef __libalunos_h
#define __libalunos_h
#define TRUE 1
#define FALSE 0
#define NUM_DISCIPLINA 5

struct disciplinas
{
    unsigned int id;
    char descricao[20];
};

struct std_node // prefixo std = student/aluno
{
    int                 numero;
    char                nome[20];
    char                curso[20];
    struct disciplinas  disciplinas[NUM_DISCIPLINA];
    int                 numDisciplinas;
    int                 ano_curso;
    int                 estado;
    struct std_node *next;
};

// variaveis globais
extern struct std_node *std_head;
/* Prototipo para as funções-metodos associados aos alunos */

void std_init(void);
struct std_node *std_is_registered(int std_num);
struct std_node *std_new_node(void);
struct std_node *std_search_by(char *std_nome, char *std_curso);
void std_insert(void);
void std_show(void);
void std_delete(void);


//menus e submenu
void std_submenu(void);
int std_check(void);
#endif
