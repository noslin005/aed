//
//  funcionarios.h
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 25/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#ifndef _libfuncionarios_h
#define _libfuncionarios_h
#define TRUE 1
#define FALSE 0

typedef struct emp_node // prefixo emp = employee/funcionario
{
    int nif;
    char nome[30];
    char funcao[20];
    char categoria[20];
    float salario;
    struct emp_node *next;
} funcionario;

extern funcionario *emp_head; // apontador para inicio da lista de funcionarios

// Prototipo para as funções-metodos associados aos funcionarios
void emp_init(void);
funcionario *emp_new_node(void);
funcionario *emp_is_registered(int emp_nif);
void emp_insert_ord(void);
void emp_show(void);
void emp_delete(int emp_nif);

// funcao para pesquisa
funcionario *emp_search_by(int nif, char name[30]);

// menu
void emp_submenu(void);
void emp_search(void);
void emp_calcula_despesas(void);


#endif
