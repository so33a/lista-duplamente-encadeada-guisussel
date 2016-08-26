#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct node * link;
struct node {
  int item;
  link next;
  link prev;
};

typedef struct {
   link head;
   link z;
} * ListaDupla;

ListaDupla inicializa();
link novoNo (int item, link prev, link next);
link buscar(ListaDupla l, int item);
void insereDepois (ListaDupla l, link x, link t);
void insereAntes (ListaDupla l, link x, link t);
link removeNo (link x);
void imprime(ListaDupla l);
void imprimeReverso(ListaDupla l);
void destroiLista(ListaDupla l);

/*
Acrescente um protótipo no arquivo listaDupla.h para uma função que encontra o nó com o menor elemento da lista duplamente encadeada. 
Esta função deve devolver um link para o nó encontrado.
*/
link buscaMenor(ListaDupla l);
/*
Acrescente um protótipo no arquivo listaDupla.h para uma função que ordena uma lista duplamente encadeada.
*/
listaDupla ordenaLista(ListaDupla l, ListaDupla m);

#endif
