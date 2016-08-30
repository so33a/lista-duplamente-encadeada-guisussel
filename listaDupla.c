#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"




link novoNo (int item, link prev, link next) {
  link aux = malloc(sizeof(struct node));
  if (aux == NULL) {
    printf ("Erro ao alocar um novo no\n");
    exit(-1);
  }
  aux->item = item;
  aux->prev = prev;
  aux->next = next;
  return aux;
}


ListaDupla inicializa() {
  ListaDupla aux;
  aux = malloc(sizeof *aux);
  aux->head = NULL;
  aux->z = novoNo(0, NULL, NULL);
  return aux;
}

void insereDepois (ListaDupla l, link x, link t) {
  if (x == NULL) {
    l->head = t;
    t->next = l->z;
    t->prev = l->z;
    l->z->prev = t;
    l->z->next = t;
  } else {
    t->next = x->next;
    t->prev = x;
    x->next = t;
    t->next->prev = t;
  }
}

link removeNo (link x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
  return x;
}
void imprimeReverso(ListaDupla l) {
  link t = l->z->prev;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->prev;
  }
  printf("\n");
}


void imprime(ListaDupla l) {
  link t = l->head;
  while ( t != l->z ) {
    printf ("%d ", t->item);
    t = t->next;
  }
  printf("\n");
}

link buscar(ListaDupla l, int item) {
  link t = l->head;
  while ( t != l->z ) {
    if(t->item == item)
      return t;
    t = t->next;
  }
  return NULL;
}
/*
void insereAntes (ListaDupla l, link x, link t);
*/

/*
Implemente no arquivo listaDupla.c a função que busca o menor elemento da lista.
*/
link buscarMenor(ListaDupla l) {
    link t = l->head;
    link aux = t;
  while ( t != l->z ) {
    if(t->item < aux->item)
      aux=t;
    t = t->next;
  }
  return aux;
}

/*
Implemente no arquivo listaDupla.c a função que ordena a lista
*/
ListaDupla ordenaLista(ListaDupla l){
    link aux = l-> head;

    ListaDupla novaLista = inicializa();

    while (aux != l->z ) {
        insereDepois(novaLista, novaLista->z->prev, removeNo(buscarMenor(l)));

        aux = aux->next;
        printf("aqui");
    }
    destroiLista(l);
    return novaLista;
  //1- buscamenor L
  //2- insereDepois ListaNova
  //3- free lista L
  //4- retorna listaNova
}

void destroiLista(ListaDupla l) {
  link t = l->head;
  while (t != l->z) {
    l->head = t->next;
    l->z->next = t->next;
    l->head->prev = l->z;
    free(t);
    t = l->head;
  }
  free(t);
  free(l);
}

