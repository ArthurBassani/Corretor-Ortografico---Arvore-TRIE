#ifndef STRUCT_NOH_TRIE_H
#define STRUCT_NOH_TRIE_H

struct nohTRIE{
   int      terminal;   // Indica se o noh representa uma chave ou nao
   pDLista  pFilhos;    // Lista de "Filhos" do Noh
   void*    digito;     // Representa o dígito usado para chegar ao noh
   void*    info;       // Ponteiro para a informacao armazenada
};

#endif
