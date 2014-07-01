//
//  menu.c
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 25/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#include "menu.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void printf_logo(){
    puts("\t\t===================================");
    puts("\t\tSISTEMA CONTROLE PESSOAL - v1.00");
    puts("\t\tCreated By: Nilson Lopes, 2014 \n\t\t\t  <noslin005@gmail.com>");
    puts("\t\t===================================");
}
int menu_principal(void)
{
    int opcao;
    char s[80];
    system(clear_screen);
    printf_logo();
    puts("\t\tMENU PRINCIPAL:");
    puts("\t\t===================================");
    puts("\t\t[1] => FUNCIONÁRIOS");
    puts("\t\t[2] => DOCENTES");
    puts("\t\t[3] => ALUNOS");
    puts("\t\t[0] => SAIR");
    printf("\t\tEscolha uma opcao: ");
    flush_buffer();
    scanf("%s", s);
    opcao = atoi(s);
    return opcao;
}

int submenu(char titulo[]){
    int opcao_func;
    char s[80];
    system(clear_screen);
    printf_logo();
    printf("\t\tSUBMENU: %s\n", titulo);
    puts("\t\t===================================");
    printf("\t\t[1] => Inserir %s.\n", titulo);
    printf("\t\t[2] => Eliminar %s.\n", titulo);
    printf("\t\t[3] => Verificar %s.\n", titulo);
    printf("\t\t[4] => Mostrar Dados %s.\n", titulo);
    printf("\t\t[5] => Menu Principal.\n");
    printf("\t\tEscolha uma opcao: ");
    scanf("%s", s);
    flush_buffer();
    opcao_func = atoi(s);
    return opcao_func;
}
