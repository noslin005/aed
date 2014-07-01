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
#include "students.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    std_init();
    while (1)
    {
        int menu = menu_principal();
        switch (menu)
        {
            case 1: // Menu Funcionarios
                break;
            case 2: // Menu Docentes

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


