#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <locale.h>
#include "5_Arvore_Digital - TRIE/Cap5/TRIE.h"
#include <ctype.h>

int main(int argc, char* argv[]){
    setlocale(LC_ALL,"Portuguese");

    char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 
                       'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                       's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    pDTRIE trie = criarArvoreTRIE(alfabeto, strlen(alfabeto));

    char dict_path[] = { "dicionario.txt" };
    char text_path[] = { "texto.txt" };
    if(argc < 3){
        printf("Argumentos Insuficientes\n");
        printf("Informe o *caminho do texto* *caminho do dicionario*\n");
        return 0;
    }
    FILE* texto = fopen(argv[1],"r");
    FILE* dict = fopen(argv[2],"r");
    char palavra[256];
    
    while (fscanf(dict,"%256s",palavra) == 1)
    {
        converteParaMinusculo(palavra);
        incluirInfoTRIE(trie,palavra,strlen(palavra),alocaInt(1));
    };

    pNohTRIE pTrie;
    pDLista pListaChaves;
    while (fscanf(texto,"%256s",palavra) == 1)
    {
        converteParaMinusculo(palavra);
        pTrie = buscarInfoTRIE(trie,palavra,strlen(palavra));
        if(pTrie != NULL)
            if(pTrie->terminal == 1)
                continue;
        
        pListaChaves = buscaChaves(trie,strlen(palavra));
        ordenaLista(pListaChaves,comparaPontosDecrescente);
        
        printf("Palavra -%s- nao encontrada no dicionario\n",palavra);
        if(pListaChaves->quantidade > 0){
            printf("Sugestoes de palavras proximas:\n");
            imprimeListaN(pListaChaves,5,imprimeChave);
        }else{
            printf("Não foi possível encontrar palavras próximas\n");
        }


    }   
    
    printf("\n\n");
    desenhaArvoreTrie(trie,imprimeChar);
    
    fclose(dict);
    fclose(texto);
}





    // char alfabeto_completo[] = {'a', 'á', 'â', 'ã', 'à', 'b', 'c', 'ç', 'd', 
    //                    'e', 'é', 'ê', 'f', 'g', 'h', 'i', 'í', 'î', 
    //                    'j', 'k', 'l', 'm', 'n', 'o', 'ó', 'ô', 'õ', 
    //                    'p', 'q', 'r', 's', 't', 'u', 'ú', 'û', 'ü', 
    //                    'v', 'w', 'x', 'y', 'z' };
    // fgets(palavra,sizeof(palavra),dict) != NULL