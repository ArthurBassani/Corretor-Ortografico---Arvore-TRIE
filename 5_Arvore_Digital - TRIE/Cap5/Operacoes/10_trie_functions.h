#ifndef TRIE_FUNCTIONS
#define TRIE_FUNCTIONS

int contemDigito(pDTRIE pd, char digito){
   pDLista pLista = pd->pAlfabeto;
   pNoh pAux = pLista->primeiro;
   while (pAux != NULL)
   {
      if (*(char*)pAux->info == digito)
         return 1;
      pAux = pAux->prox;
   }
   return 0;
}

int comparaDigitos(void* info1,void*info2){
   pNohTRIE t1 = (pNohTRIE)info1;
   pNohTRIE t2 = (pNohTRIE)info2;
   if (*(char*)t1->digito == *(char*)t2->digito)
      return 0;
   return 1;
}
void liberaNohTRIE(pNohTRIE pTrie){
   free(pTrie->info);
   free(pTrie->digito);
   free(pTrie);
}

#endif