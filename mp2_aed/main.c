/*
 * @name:           main.c
 * @version:        2.0
 * @description:    Miniprojecto 2 EIC <1ºAno>
 * @date:           Junho 1, 2014
 * @intitute:       Universidade de Cabo Verde <2013/2014>
 * @course:         Engenharia Informática e de Computadores [EIC]
 * @discipline:     Algoritmia e Estrutura de Dados [AED]
 * @author:         Nilson Lopes <noslin005@gmail.com>
 */
#include "funcionarios.h"
#include "alunos.h"
#include "docentes.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    emp_init();
    std_init();
    doc_init();

    while (1)
    {
        int menu = menu_principal();
        switch (menu)
        {
        case 1: // Menu Funcionarios
            emp_submenu();
            break;
        case 2: // Menu Docentes
            doc_submenu();
            break;
        case 3: // Menu Alunos
            std_submenu();
            break;
        case 0: // Sair do programa
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}


