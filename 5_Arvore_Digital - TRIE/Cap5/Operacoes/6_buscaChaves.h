#ifndef LISTA_CHAVES_H
#define LISTA_CHAVES_H

pChave criaChave(char* palavra, int pontos){
    pChave p = (pChave) malloc(sizeof(Chave));
    p->chave = palavra;
    p->pontos = pontos;
}
pDLista buscaChaves(pDTRIE pd,int n){

    pDLista pL = criarLista(); //Lista Struct Chaves
    char chave[n + 1];
    memset(chave, '\0', n + 1);
    buscaChavesRecursivo(pL,pd->raiz,chave, 0 ,n);    

    return pL; 
}
void buscaChavesRecursivo(pDLista pd, pNohTRIE raiz, char key[],int i ,int n){
    pNoh pAux = raiz->pFilhos->primeiro;
    pNohTRIE pTrie;
    pChave chave;
    while(pAux != NULL){
        pTrie = pAux->info; 
        key[i] = *(char*)pTrie->digito;

        if(pTrie->pFilhos->quantidade > 0 && i + 1 < n){
            buscaChavesRecursivo(pd,pTrie,key,i + 1,n);
        }

        if(i + 1 == n && pTrie->terminal == 1){
            chave = criaChave(alocaString(key),0);
            incluirInfo(pd,chave);
        }

        pAux = pAux->prox;
    }
    
}
#endif