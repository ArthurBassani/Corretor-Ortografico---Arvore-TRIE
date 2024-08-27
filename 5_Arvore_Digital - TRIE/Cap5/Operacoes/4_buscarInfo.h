#ifndef BUSCAR_INFO_TRIE_H
#define BUSCAR_INFO_TRIE_H


pNohTRIE buscarInfoTRIE(pDTRIE pd,char chave[],int tamChave){
    pNohTRIE pTrie = pd->raiz;
    pDLista pLista = pTrie->pFilhos;
    pNoh pAux = pLista->primeiro;
    int i;
    int find;
    char digito;
    for (i = 0; i < tamChave; i++)
    {
        find = 0;
        digito = chave[i];
        while (pAux != NULL)
        {
            pTrie = pAux->info;
            if(*(char*)pTrie->digito == digito){
                find = 1;
                break;
            }
            pAux = pAux->prox;
        }


        if(!find) return NULL;

        pLista = pTrie->pFilhos;
        pAux = pLista->primeiro;

        if(i == tamChave - 1) return pTrie;
    }
}









/* ----------------------------------------------------------*/
// pNohTRIE buscarInfoTRIERecursivo (pNohTRIE raiz, pDLista alfabeto, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
// {
//     printf("\n -------> Buscando chave=%s -  k=%d - L=%d", chave, k, *L);
//     if (*L < k){
//        // determina a posi��o j do d�gito da chave (d) dentro do alfabeto
//        void *d = pff(chave, *L);
//        int jEsimo = contemInfo(alfabeto, d, pfc);
//        printf (" =====> Simbolo:%c - jEsimo:%d", *((char*)d), jEsimo);

//        pNohTRIE filho = buscarInfoPos(raiz->pFilhos, jEsimo);
//        if(filho != NULL){
//           (*L)++;
//           return buscarInfoTRIERecursivo(filho, alfabeto, chave, k, L, C, pfc, pff);
//        }
//        return raiz;
//     }
//     else{
//         if (raiz->terminal == 1){
//             *C = 1;       // indica que a chave foi localizada na �rvore
//             return raiz;
//         }
//     }
// }

// /* ----------------------------------------------------------*/
// pNohTRIE buscarInfoTRIE (pDTRIE arvore, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
// {
//     *L = 0;
//     *C = 0;
//     return buscarInfoTRIERecursivo(arvore->raiz, arvore->alfabeto, chave, k, L, C, pfc, pff);
// }

#endif

