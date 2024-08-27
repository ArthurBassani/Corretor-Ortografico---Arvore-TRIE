#ifndef INCLUIR_INFO_TRIE_H
#define INCLUIR_INFO_TRIE_H
#include "../Utils.h"
/* --------------------------*/
int incluirInfoTRIE(pDTRIE pd,char chave[],int tamChave,void* info){
   for (int c = 0; c < tamChave; c++)
   {
      if(!contemDigito(pd,chave[c])) return 0;
   }

   pNohTRIE pTrie = pd->raiz;
   pDLista pLista = pTrie->pFilhos;
   pNoh pAux = pLista->primeiro;
   int i; //Posição do digito na chave
   int find; //1 se achou a chave procurada, 0 caso contrário
   char digito; //Digito Atual da Chave
   for(i = 0; i < tamChave; i++){
      digito = chave[i];
      find = 0; 
      while (pAux != NULL)
      {
         pTrie = pAux->info;  
         if(*(char*)pTrie->digito == digito){
            find = 1;
            break;
         }
         pAux = pAux->prox;
      }

      if(!find){  
         if(i == tamChave - 1) pTrie = criarNohTRIE(1,alocaChar(digito),info);
         else                  pTrie = criarNohTRIE(0,alocaChar(digito),NULL);
         incluirInfo(pLista,pTrie);
      }

      if(i == tamChave - 1 && pTrie->info == NULL){
         pTrie->info = info;
         pTrie->terminal = 1;
         return 1;
      }

      pLista = pTrie->pFilhos;
      pAux = pLista->primeiro;
   }

   return 1;
}

#endif

