#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Utils.h"
#include "TRIE.h"

//----------------------------------------
int comparaChar(void* info1, void* info2){
   char* c1 = (char*) info1;
   char* c2 = (char*) info2;
   return *c2 - *c1;
}

//----------------------------------------
void* fatiaString (void* info, int pos){
    char* chave = (char*) info;
    char* simbolo = malloc(sizeof(char));
    *simbolo = chave[pos];
    return simbolo;
}

/* ---------------------------------------- */
void imprimeChar(void *info){
   char *pc = (char *) info;
   printf("%c - ", *pc);
}

//----------------------------------------
int main(){

    char alfabeto[]={'a', 'b', 'c', 'i'};

    // define a ordem da �rvore B
    pDTRIE trie = criarArvoreTRIE(alfabeto, 4);

    char chave1[] = "bacia";
    char chave2[] = "abicia";
    char chave3[] = "ciba";
    char chave4[] = "baba";

    /* teste de inclusao */
    incluirInfoTRIE(trie, chave1, strlen(chave1), comparaChar);
    //incluirInfoTRIE(trie, chave2, strlen(chave2), comparaChar, fatiaString);
    //incluirInfoTRIE(trie, chave3, strlen(chave3), comparaChar, fatiaString);
    //incluirInfoTRIE(trie, chave4, strlen(chave4), comparaChar, fatiaString);

    printf("\n\n --- Arvore final --- \n\n");
    desenhaTRIE(trie, imprimeChar);
}
