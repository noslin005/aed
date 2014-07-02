aed - Algorítimia e Estrutura de Dados
==

###1. Listas encadeadas
###2. Pilhas
###3. Filas
###4. Algoritimos de pesquisa e ordencao de vectores

Foi compilado usando o gcc 4.2.1 em OS X Mavericks (i686-apple-darwin11-llvm-gcc-4.2 (GCC) 4.2.1). Quem for utilizar em Windows ou Linux deve substituir:

Windows:

    //substituir esta linha
    fpurge(stdin);
    //por esta linha
    fflush(stdin);
    
Linux:

    //incluir esta linha no cabeçalho
    #include <stdio_ext>
    //substitui esta linha
    fpurge(stdin);
    //por esta linha
    __fpurge(stdin);

Estas funções (`fpurge(stdin)`; `fflush(stdin)` e `__fpurge(stdin)`) servem para limpeza de buffer em OS X, Window e Linux, respectivamente.
