//
//  docentes.h
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 23/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#ifndef __libdocentes_h_
#define __libdocentes_h_

#define TRUE 1
#define FALSE 0

#define MAX_DISCIPLINA 5

struct disciplina
{
    char descricao[20];
};

typedef struct doc_node
{
    int                 nif;
    char                nome[30];
    struct disciplina   disciplinas[MAX_DISCIPLINA];
    char                categoria[12];
    int                 num_disciplinas;
    float salario;
    struct doc_node     *next;
} docente;


// variaveis globais
extern docente *doc_head;

//
void doc_init(void);
docente *doc_new_node(void);
docente *doc_is_registerd(int doc_nif);
void doc_insert(void);
void doc_show(void);
void doc_delete(int nif);
void doc_search_by_course(char *doc_curso);

//menus e submenu
void doc_submenu(void);
int doc_check(void);

#endif
