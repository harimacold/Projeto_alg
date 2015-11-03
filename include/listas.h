#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
  char *elem;
  struct _nodo *prox, *ant;
} nodo;

typedef nodo *lista;

void inicLista (lista *);
int Lista_vazia (lista );
void insereLista (lista *, char *);
void removeLista (lista *, nodo *);
void imprimeLista (lista );
void apagaLista (lista *);
void insereLista_Ordenada (lista *, char *);
void ordenaLista (lista *);

#endif
