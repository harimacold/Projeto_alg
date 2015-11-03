#ifndef FILAS_H
#define FILAS_H

#include "listas.h"

typedef struct _pessoa{
  char nome[50];
  lista lista_LP;
} pessoa;

typedef struct _nodo_F{
  pessoa elem;
  struct _nodo_F *prox;
} nodo_F;


typedef struct _fila{
  nodo_F *frente, *fim;
} fila;

void inicFila(fila *);
int Fila_vazia(fila );
void enfileirar(fila *, pessoa);
void desenfileirar(fila *);
void imprimeFila(fila );

#endif
