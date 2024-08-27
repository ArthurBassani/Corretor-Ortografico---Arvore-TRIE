#ifndef DESENHA_ARVORE_TRIE_H
#define DESENHA_ARVORE_TRIE_H


void desenhaArvoreTrieRecursivo(pNohTRIE raiz, FuncaoImpressao fi) {
    printf("[ ");
    pNoh pAux = raiz->pFilhos->primeiro;
    pNohTRIE pTrie;
    while(pAux != NULL){
        pTrie = pAux->info; 
        fi(pTrie->digito);
        imprimeInt(pTrie->terminal);
        if(pTrie->pFilhos->quantidade > 0){
            desenhaArvoreTrieRecursivo(pTrie, fi);
            printf(" - ");
        }
        pAux = pAux->prox;
    }    

   printf(" ]");
}
void desenhaArvoreTrie(pDTRIE pd,FuncaoImpressao fi){
    if(pd->raiz->pFilhos->quantidade == 0){
        printf("Árvore Sem Chaves\n");
        return;
    }
    desenhaArvoreTrieRecursivo(pd->raiz,fi);
    printf("\n");
}

#define ESPACO 5

#endif
