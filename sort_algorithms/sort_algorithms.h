/*
 * sort_algorithms.h
 * Algotimos de Ordenaçao e pesquisa em vectores
 *
 * Created by Nilson Lopes on 30/06/14.
 * Copyright (c) 2014 Nilson Lopes. All rights reserved.
 */

#ifndef _liblsortalg_h
#define _liblsortalg_h

// cria um novo tipo de dados para dar suporte a numeros muito grandes
typedef long int l_int;


/* Troca dois elementos de posicao dentro de um vetor */
void swap(l_int *vetor, int index1, int index2);

/* Ordena o vector usando algoritimo quick sort */
void quick_sort(l_int *vetor, int size);

/* Ordena o vector usando algoritimo buble sort */
void buble_sort(l_int *vetor, int size);

/* Ordena o vector usando algoritimo merge sort */
void merge_sort(l_int *vetor, int size);


/* Pesquisa um valor(chave) no vector usando linear/sequencial
   Recebe como parametros:
        1. Vetor onde se deve procurar o valor/chave
        2. Tamanho do vector
        3. Chave/Valor a ser procurado
    Retorna -1 se o chave/valor nao for encontrado no vector ou a posicao onde
    o valor/chave se o valor for encontrado.
*/
int linear_search(l_int *vetor, int size, l_int key);

int binary_search(l_int *vetor, int size, l_int key);

/* Extra */
void pause(void);
#endif