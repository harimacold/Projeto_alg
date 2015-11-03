#ifndef FILAS_H
#define FILAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo{
  char *elem;
  struct _nodo *prox;
} nodo;

typedef struct _fila{
  nodo *frente, *fim;
} fila;

void inicFila(fila *);
int Fila_vazia(fila );
void enfileirar(fila *, char *);
void desenfileirar(fila *);
void imprimeFila(fila );

#endif
