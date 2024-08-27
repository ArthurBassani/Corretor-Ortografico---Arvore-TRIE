#ifndef ORDENA_LISTA_H
#define ORDENA_LISTA_H

void ordenaLista(pDLista pd,FuncaoComparacao pfc){
    pNoh pAux,pAux2,pTemp;

    pAux = pd->primeiro;

    while (pAux != NULL)
    {   
        pAux2 = pAux->prox;
        
        while (pAux2 != NULL)
        {
            if(pfc(pAux2->info,pAux->info) == 0){
                pTemp = pAux->info;
                pAux->info = pAux2->info;
                pAux2->info = pTemp;
            }
            pAux2 = pAux2->prox;
        }

        pAux = pAux->prox;
    }
    

}

#endif