#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* ---------------------------------------- */
/* tipo de dado INT */
/* ---------------------------------------- */
int comparaInt(void *info1, void *info2){
    int *p1 = (int *) info1;
    int *p2 = (int *) info2;
    return *p2 - *p1;
}
/* ---------------------------------------- */
void imprimeInfoInt(void *info){
   int *pi = (int *) info;
   printf("%d - ", *pi);
}
/* ---------------------------------------- */
void imprimeInt(int n){
   printf("%d - ", n);
}
/* ---------------------------------------- */
void* alocaInfoInt(void *info){
   int * pi = (int *) malloc(sizeof(int));
   *pi = *((int*)info);
   return pi;
}
/* ---------------------------------------- */
int* alocaInt(int n){
   int *pi = (int *) malloc(sizeof(int));
   *pi = n;
   return pi;
}
/* ---------------------------------------- */
char* alocaChar(char n){
   char* pi = (char*) malloc(sizeof(char));
   *pi = n;
   return pi;
}
/* ---------------------------------------- */
/* tipo de dado STRUCT Data */
/* ---------------------------------------- */
struct Data{
   int dia, mes, ano;
};
/* ---------------------------------------- */
int          comparaData  (void *info1, void *info2){
    struct Data *p1 = (struct Data *) info1;
    struct Data *p2 = (struct Data *) info2;
    return ((p2->ano - p1->ano)*365) +
           ((p2->mes - p1->mes)*30)  +
            (p2->dia - p1->dia)  ;
}
/* ---------------------------------------- */
int comparaPontosDecrescente(void* info1, void* info2){
   pChave p1 = info1;
   pChave p2 = info2;

   if(p1->pontos > p2->pontos)
      return 0;
   return 1;

}
/* ---------------------------------------- */
void         imprimeData  (void *info){
   struct Data *pd = (struct Data *) info;
   printf("%d/%d/%d - ", pd->dia, pd->mes, pd->ano);
}
/* ---------------------------------------- */
void*        alocaInfoData(void *info){
   struct Data * pd = (struct Data *) malloc(sizeof(struct Data));
   pd->dia = ((struct Data*)info)->dia;
   pd->mes = ((struct Data*)info)->mes;
   pd->ano = ((struct Data*)info)->ano;
   return pd;
}
/* ---------------------------------------- */
struct Data* alocaData    (int dia, int mes, int ano){
   struct Data *pd = (struct Data *) malloc(sizeof(struct Data));
   pd->dia = dia;
   pd->mes = mes;
   pd->ano = ano;
   return pd;
}
/* ---------------------------------------- */
void imprimeEspaco(int n ){
   for (int i = 0; i < n; i++)
   {
      printf(" ");
   }
}
/* ---------------------------------------- */
void imprimeString(void* info){
   printf("%s\n",(char*)info);
}
/* ---------------------------------------- */
void imprimeChaveCompleta(void* info){
   pChave c = (pChave) info;
   printf("Chave: %s | Pontos: %d\n",(char*)c->chave,c->pontos);
}
/* ---------------------------------------- */
void imprimeChave(void* info){
   pChave c = (pChave) info;
   printf("%s\n",(char*)c->chave);
}
/* ---------------------------------------- */
void converteParaMinusculo(char* string){
    for (int i = 0; string[i] != '\0'; i++) {
        string[i] = tolower(string[i]);
    }
}
/* ---------------------------------------- */
char* alocaString(char string[]){
   char* c = malloc((strlen(string) + 1) * sizeof(char));
   strcpy(c,string);
   return c;
}
/* ---------------------------------------- */
int comparaChar(void* info1, void* info2){
   char* c1 = (char*) info1;
   char* c2 = (char*) info2;
   return *c2 - *c1;
}
/* ---------------------------------------- */
void* fatiaString (void* info, int pos){
    char* chave = (char*) info;
    char* simbolo = malloc(sizeof(char));
    *simbolo = chave[pos];
    return simbolo;
}
/* ---------------------------------------- */
void imprimeChar(void *info){
   char *pc = (char *) info;
   printf("%c - ", *pc);
}
/* ---------------------------------------- */

void imprimeListaN(pDLista pd, int n, FuncaoImpressao fi){
   pNoh pAux = pd->primeiro;
   while (pAux != NULL && n > 0)
   {
      fi(pAux->info);
      pAux = pAux->prox;
      n--;
   }
   
}

#endif /* UTILS_H */
