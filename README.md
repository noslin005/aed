aed - Algorítimia e Estrutura de Dados
==

Algoritimos de ordenção e pesquisa em vectores. Foi compilado usando o gcc 4.2.1 em OS X Mavericks (i686-apple-darwin11-llvm-gcc-4.2 (GCC) 4.2.1). Quem for utilizar em Windows ou Linux deve substituir:

Windows:

    void pause(void){
        printf("\n\tTecle Enter para continuar ...");
        //esta linha
        fpurge(stdin);
        //por esta linha
        fflush(stdin);
        getchar();
    }
    
Linux:

    #include <stdio_ext>
    void pause(){
        printf("\n\tTecle Enter para continuar ...");
        //esta linha
        fpurge(stdin);
        //por esta linha
        __fpurge(stdin);
        getchar();
    }
