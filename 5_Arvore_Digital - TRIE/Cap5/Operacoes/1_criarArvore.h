#ifndef CRIAR_ARVORE_TRIE_H
#define CRIAR_ARVORE_TRIE_H

//---------------------------------
pNohTRIE criarNohTRIE(int terminal,void* digito,void* info){
    pNohTRIE pNovo  = malloc(sizeof(NohTRIE));
    pNovo->pFilhos   = criarLista();
    pNovo->info = info;
    pNovo->digito = digito;
    pNovo->terminal = terminal;
    return pNovo;
}
pNoh criarNoh(void* info){
    pNoh pNovo  = malloc(sizeof(Noh));
    pNovo->info = info;
    pNovo->prox = NULL;
    return pNovo;
}

/* --------------------------*/
pDTRIE criarArvoreTRIE(char alfabeto[], int ordem){
    pDTRIE trie    = malloc(sizeof(DTRIE));
    trie->raiz     = criarNohTRIE(0,NULL,NULL);  // o zero indica que a raiz n�o � terminal
    trie->ordem    = ordem; // Tamanho do alfabeto
    trie->pAlfabeto = criarLista();

    // fazer um loop para adicionar cada elemento do alfabeto[] na lista do alfabeto do descritor
    
    int i;
    for(i=0; i<ordem; i++){
       char* simbolo = malloc(sizeof(char));
       *simbolo = alfabeto[i];
       incluirInfo(trie->pAlfabeto, simbolo);
    }
    return trie;
};

#endif
