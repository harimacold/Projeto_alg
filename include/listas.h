#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo_lis{
  char *elem;
  struct _nodo_lis *prox, *ant;
} nodo_lis;

typedef nodo_lis *lista;

void inicLista (lista *);
int Lista_vazia (lista );
void insereLista (lista *, char *);
void removeLista (lista *, nodo_lis *);
void imprimeLista (lista );
void apagaLista (lista *);
void insereLista_Ordenada (lista *, char *);
void ordenaLista (lista *);

#endif
