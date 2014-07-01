//
//  students.h
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 23/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#ifndef __libstudents_h
#define __libstudents_h
#define NUM_DICIPLINA 5
struct disciplinas{
    unsigned int id;
    char descricao[20];
};

struct std_node{
    int                 numero;
    char                nome[20];
    char                curso[20];
    struct disciplinas  disciplinas[NUM_DICIPLINA];
    int                 ano_curso;
    int                 estado;
    struct std_node *next;
};

// variaveis globais
extern struct std_node *std_head;
/* Prototipo para as funções-metodos associados aos alunos */

void std_init(void);
int std_is_registered(int std_num);
struct std_node* std_new_node(void);
void std_insert(void);
void std_show(void);
void std_delete(void);

// formatacao para apresentacao
void std_print_header(void);
void std_print_footer(void);

//menus e submenu
void std_submenu(void);
int std_check(void);
#endif
