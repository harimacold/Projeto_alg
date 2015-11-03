#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _LP{
  char nome[50], album[50];
  float valor;
} LP;

typedef struct _nodo_lis{
  LP elem;
  struct _nodo_lis *prox, *ant;
} nodo_lis;

typedef nodo_lis *lista;

void inicLista (lista *);
int Lista_vazia (lista );
void insereLista (lista *, LP );
void removeLista (lista *, nodo_lis *);
void imprimeLista (lista );
void copiaLista (lista *, lista);

#endif
