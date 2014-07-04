//
//  docentes.c
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 23/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#include "util.h"
#include "menu.h"
#include "docentes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

docente *doc_head;

void doc_init(void)
{
    doc_head = NULL;
}

docente *doc_is_registerd(int doc_nif)
{
    if (doc_head == NULL)
    {
        return NULL;
    }
    docente *current = doc_head;
    while (current != NULL)
    {
        if (current->nif == doc_nif)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

docente *doc_new_node(void)
{
    int tmp = 0;
    docente *novo = (docente *)malloc(sizeof(docente));
    if (novo == NULL)
    {
        fprintf(stderr, "Falta de memoria");
        exit(1);
    }
    while (TRUE)
    {
        printf("\n\t\tNIF [0 - Cancelar]: ");
        flush_buffer();
        (void)scanf("%d", &novo->nif);
        if (novo->nif == 0)
        {
            return NULL;
        }
        if (doc_is_registerd(novo->nif) == NULL)
        {
            break;
        }
        else
        {
            printf("\n\t\tDocente com este NIF ja existe.");
        }
    }
    printf("\t\tNome: ");
    flush_buffer(); (void)scanf("%s", novo->nome);

    do
    {

        printf("\t\tCategoria [1. Licenciado, 2-Mestre, 3-Doutor]: ");
        flush_buffer(); (void)scanf("%d", &tmp);
    }
    while (tmp < 0 || tmp > 3);

    switch (tmp)
    {
    case 1:
        strcpy(novo->categoria, "Licenciado");
        break;
    case 2:
        strcpy(novo->categoria, "Mestre");
        break;
    case 3:
        strcpy(novo->categoria, "Doutor");
        break;
    default:
        strcpy(novo->categoria, "Outros");
        break;
    }
    printf("\t\tQuantas disciplinas: ");
    flush_buffer(); (void)scanf("%d", &novo->num_disciplinas);

    for (tmp = 0; tmp < (novo->num_disciplinas) && tmp < MAX_DISCIPLINA; ++tmp)
    {
        printf("\t\t%dº disciplina: ", tmp + 1);
        flush_buffer();
        (void)scanf("%s", novo->disciplinas[tmp].descricao);
    }
    printf("\t\tSalario: ");
    flush_buffer(); (void)scanf("%f", &novo->salario);

    novo->next = NULL;
    return novo;
}

void doc_insert()
{
    // cria um novo 'NO'
    docente *novo = doc_new_node();

    //verifica se foi alocado espco na memoria.
    if (novo == NULL)
    {
        return;
    }

    // Se a lista de docentes estiver vazia, insere no inicio
    if (doc_head == NULL)
    {
        doc_head = novo;
    }
    // Se o NIF do docente for menor do que aquele que esta no primeiro 'NO', insere no inicio
    else if (novo->nif < doc_head->nif)
    {
        novo -> next = doc_head;
        doc_head = novo;
    }
    else
    {

        docente *anterior = doc_head;
        docente *atual = doc_head -> next;


        // Percorre a lista a procura da posicao onde inserir o novo 'NO'
        while (atual != NULL && novo->nif > atual->nif)
        {
            anterior = atual;
            atual = atual -> next;
        }


        // Insere no final da lista, se depois da pesquisa e nao encontrar nenhum
        // docente com NIF maior do que aquele que foi fornecido
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

void doc_show(void)
{
    if (doc_head == NULL)
    {
        printf("\n\t\tLista de docentes está vazia.");
        return;
    }
    docente *current_node = doc_head;
    while (current_node != NULL)
    {
        int i = 0;
        printf("\n\tNIF: %d", current_node->nif);
        printf("\n\tNome: %s", current_node->nome);
        printf("\n\tCategoria: %s ", current_node->categoria);
        printf("\n\tDisciplinas: ");
        while (i < current_node->num_disciplinas)
        {
            printf("%s ", current_node->disciplinas[i].descricao);
            i++;
        }
        printf("\n\tSalario Base: %.2f\n", current_node->salario);
        current_node = current_node->next;
    }
}

void doc_delete(int doc_nif)
{
    if (doc_head == NULL)
    {
        printf("\n\t\tLista de docentes está vazia.") ;
        return;
    }

    docente *tmpDelete = NULL; //ponteiro para o no a ser removido
    if (doc_head->next == NULL && doc_head->nif == doc_nif) // se for o unico elemento da lista
    {
        free(doc_head);
        doc_head = NULL;
        printf("\n\t\tDocente excluido com sucesso.");
    }
    else if (doc_head->next != NULL && doc_head->nif == doc_nif) // se estiver no inicio da lista
    {
        tmpDelete = doc_head;
        doc_head = doc_head->next;
        free(tmpDelete);
        printf("\n\t\tDocente excluido com sucesso.");
    }
    else
    {
        docente *current = doc_head;
        while (current->next != NULL && current->next->nif != doc_nif)
        {
            current = current->next;
        }

        if (current->next == NULL)
        {
            printf("\n\t\tDocente nao encontrado.");
        }
        else
        {
            tmpDelete = current->next;
            current->next = tmpDelete->next;
            free(tmpDelete);
            printf("\n\t\tDocente excluido com sucesso.");
        }
    }
}




void doc_search_by_course(char *disciplina)
{
    if (doc_head == NULL)
    {
        return;
    }
    docente *current = doc_head;
    int total = 0;
    while (current != NULL)
    {
        int i = 0;
        while (i < current->num_disciplinas)
        {
            if (strcasecmp(current->disciplinas[i].descricao, disciplina) == 0)
            {
                printf("\n\tNIF: %d", current->nif);
                printf("\n\tNome: %s", current->nome);
                printf("\n\tCategoria: %s\n", current->categoria);
                printf("\n\tSalario Base: %.2f\n", current->salario);
                total++;
            }
            i++;
        }
        current = current->next;
    }
    if (total > 0)
    {
        printf("\n\tDisciplina de: %s\n\tTotal de docentes: %d\n", disciplina, total);
    }
    else
    {
        printf("\n\tDisciplina %s ainda nao esta registrada.", disciplina);
    }
}


/* calculo do salario e tempo extra */
void doc_calcula_salario(int doc_nif)
{
    docente *doc = doc_is_registerd(doc_nif);
    float salario_total = 0;
    char *categoria[3] = { "Licenciado", "Mestre", "Doutor"};
    if (doc == NULL)
    {
        printf("\n\tLista de docentes esta vazia.");
        return;
    }
    // mestre
    if (strcasecmp(doc->categoria, categoria[1]) == 0)
    {
        if (doc->num_disciplinas < 4)
        {
            salario_total = doc->salario;
        }
        else if (doc->num_disciplinas == 4)
        {
            salario_total = doc->salario + ( 2500 * ( ( 1 * ( 4 * 4 ) - 8 )));
        }
        else
        {
            salario_total = doc->salario + ( 2500 * ( 2 * ( 4 * 4 ) - 24 ));
        }

    }
    // doutor
    else if (strcasecmp(doc->categoria, categoria[2]) == 0)
    {
        if (doc->num_disciplinas < 4)
        {
            salario_total = doc->salario;
        }
        else if (doc->num_disciplinas == 4)
        {
            salario_total = doc->salario + ( 3500 * ( ( 1 * ( 4 * 4 ) - 8 )));
        }
        else
        {
            salario_total = doc->salario + ( 3500 * ( 2 * ( 4 * 4 ) - 24 ));
        }
    }
    // licenciado
    else
    {
        if (doc->num_disciplinas < 4)
        {
            salario_total = doc->salario;
        }
        else if (doc->num_disciplinas == 4)
        {
            salario_total = doc->salario + ( 2000 * ( ( 1 * ( 4 * 4 ) - 8 )));
        }
        else
        {
            salario_total = doc->salario + ( 2000 * ( 2 * ( 4 * 4 ) - 24 ));
        }
    }
    printf("\n\tNIF: %d", doc->nif);
    printf("\n\tNome: %s", doc->nome);
    printf("\n\tNumero disciplinas: %d", doc->num_disciplinas);
    printf("\n\tSalario Base: %.2f", doc->salario);
    printf("\n\tSalario Extra: %.2f", salario_total);
}

void doc_submenu(void)
{
    int executar = 1;
    int submenu_activo;
    int temp = 1;

    while (executar)
    {
        submenu_activo = submenu("Docente");
        switch (submenu_activo)
        {
        case 1:
            doc_insert();
            break;
        case 2:
            printf("\n\t\tNIF do docente: ");
            (void)scanf("%d", &temp);
            doc_delete(temp);
            break;
        case 3: // submenu verificar docente
        {
            temp = 1;
            while (temp != 4)
            {
                temp = doc_check();
            }
            break;
        }
        case 4: //mostrar docente
            doc_show();
            break;
        case 5:
            executar = 0; /* Termina o ciclo while e volta ao menu principal. */
            break;
        case 0:
            exit(0);
        default:
            printf("\n\t\tOpcao invalida");
        }
        pause();
    }
}

int doc_check(void)
{
    int option;
    system("clear||cls");
    printf_logo();
    puts("\t\tCONSULTAR DOCENTES");
    puts("\t\t===================================");
    puts("\t\t[1] => Por NIF.");
    puts("\t\t[2] => Por Disciplinas.");
    puts("\t\t[3] => Salário");
    puts("\t\t[4] => Menu anterior.");
    puts("\t\t[0] => Sair.");
    printf("\n\t\tOpcao: ");
    (void)scanf("%d", &option);
    switch (option)
    {
    case 1: // procurar por NIF
    {
        int doc_nif;
        printf("\n\t\tNIF do docente: ");
        flush_buffer(); (void)scanf("%d", &doc_nif);
        docente *doc = doc_is_registerd(doc_nif);
        if (doc != NULL)
        {
            printf("\n\tNIF: %d", doc->nif);
            printf("\n\tNome: %s", doc->nome);
            printf("\n\tCategoria: %s", doc->categoria);
            printf("\n\tDisciplinas: ");
            int i = 0;
            while (i < doc->num_disciplinas)
            {
                printf("%s ", doc->disciplinas[i].descricao);
                i++;
            }
            printf("\n\tSalario Base: %.2f\n", doc->salario);
        }
        else
        {
            printf("\n\t\tDocente com este nif nao esta na lista.");
        }
        pause();
        break;
    }
    case 2: // procurar por disciplinas
    {
        char diciplina[30];
        printf("\n\t\tNome da disciplina: ");
        flush_buffer();
        (void)scanf("%s", diciplina);
        doc_search_by_course(diciplina);
        pause();
        break;
    }
    case 3:// calcular salario
    {
        int doc_nif;
        printf("\n\t\tNIF do docente: ");
        flush_buffer(); (void)scanf("%d", &doc_nif);
        doc_calcula_salario(doc_nif);
        pause();
        break;
    }

    case 4: //menu anterior
        break;
    case 0: // sair
        exit(0);
    default:
        break;
    }

    return option;
}

