#ifndef TRIE_TAD_H
#define TRIE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/

/* estrutura do noh da arvore B */
typedef struct nohTRIE NohTRIE;
typedef NohTRIE*       pNohTRIE;

/* descritor da arvore B */
typedef struct dTRIE  DTRIE;
typedef DTRIE*        pDTRIE;

/* tipos referentes aos ponteiros para funcao */
typedef int   (*FuncaoComparacaoAlfabeto)(void*, void*);
typedef void  (*FuncaoImpressao) (void*);
typedef void* (*FuncaoFatiamento) (void*, int);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDTRIE   criarArvoreTRIE(char [],int);   // alfabeto e seu tamanho

int      incluirInfoTRIE (pDTRIE, char[], int, void*);
int      excluirInfoTRIE (pDTRIE, char[], int);
int      excluirChaveTRIE (pDTRIE, char[], int,FuncaoComparacao);
pNohTRIE buscarInfoTRIE  (pDTRIE, char[], int);

int comparaDigitos(void*, void*);
int contemDigito(pDTRIE, char);
void liberaNohTRIE(pNohTRIE);
void     desenhaArvoreTrie (pDTRIE, FuncaoImpressao);
void     desenhaArvoreTrieRecursivo(pNohTRIE, FuncaoImpressao);
pDLista buscaChaves(pDTRIE pd,int n);
void buscaChavesRecursivo(pDLista pd, pNohTRIE raiz, char chave[],int i ,int n);
#endif