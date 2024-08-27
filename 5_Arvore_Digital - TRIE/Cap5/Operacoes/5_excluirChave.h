#ifndef EXCLUIRCHAVE_BTREE_H
#define EXCLUIRCHAVE_BTREE_H

int excluirChaveTRIE  (pDTRIE pd,char chave[],int tamChave,FuncaoComparacao pfc){
        for (int c = 0; c < tamChave; c++)
        {
            if (!contemDigito(pd,chave[c])) return 0;
            
        }
        pNohTRIE pTrie = pd->raiz;
        pNohTRIE pAntTrie = pd->raiz;
        pDLista pLista = pTrie->pFilhos;
        pDLista pBiOrInfo = pTrie->pFilhos;
        pNoh pAux = pLista->primeiro;
        pNoh pNohBi = pLista->primeiro;
        int find;
        char digito;
        for (int i = 0; i < tamChave; i++)
        {
            digito = chave[i];
            find = 0;
            while (pAux != NULL)
            {
                pTrie = pAux->info;
                if(*(char*)pTrie->digito == digito)
                {
                    find = 1;
                    break;
                }
                pAux = pAux->prox;
            }
            if(!find) return 0;

            if(pLista->quantidade > 1 || pAntTrie->info != NULL){
                pBiOrInfo = pLista;
                pNohBi = pAux;
            }
            pAntTrie = pTrie;
            pLista = pTrie->pFilhos;
            pAux = pLista->primeiro;

        }
        
        //Vê se existe alguma chave mais pra frente, se sim libera a info e encerra a função
        if(pTrie->pFilhos->quantidade > 0){
            free(pTrie->info);
            return 1;
        }
        
        pTrie = pNohBi->info;
        excluirInfo(pBiOrInfo,pNohBi->info,comparaDigitos);

        pLista = pTrie->pFilhos;
        pAux = pLista->primeiro;

        while (pAux != NULL)
        {
            pAntTrie = pTrie;
            pTrie = pAux->info;
            
            liberaNohTRIE(pAntTrie);
            destruirLista(pLista);
            free(pLista);

            pLista = pTrie->pFilhos;
            pAux = pLista->primeiro;
        }

        liberaNohTRIE(pTrie);
        free(pLista);
        return 1;
}


#endif
