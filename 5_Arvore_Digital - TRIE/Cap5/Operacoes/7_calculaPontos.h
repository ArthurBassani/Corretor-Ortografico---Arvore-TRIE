#ifndef CALCULA_PONTOS_H
#define CALCULA_PONTOS_H

void calculaPontos(pDLista pd, char* palavra,int tamChave){
    pNoh pAux = pd->primeiro;
    pChave chave;
    while (pAux != NULL)
    {
        chave = pAux->info;
        for (int i = 0; i < tamChave; i++)
        {
            if(chave->chave[i] == palavra[i]){
                chave->pontos++;
            }
        }
        pAux = pAux->prox;
    }
}

#endif