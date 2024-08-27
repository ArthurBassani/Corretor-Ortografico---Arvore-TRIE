#ifndef EXCLUIRINFO_BTREE_H
#define EXCLUIRINFO_BTREE_H

int excluirInfoTRIE  (pDTRIE pd,char chave[],int tamChave){
    
    pNohTRIE pTrie = buscarInfoTRIE(pd,chave,tamChave);

    if(pTrie){
        pTrie->info = NULL;
        pTrie->terminal = 0;
        return 1;
    }
    
    return 0;
}

#endif
