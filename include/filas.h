#ifndef FILAS_H
#define FILAS_H

#include "listas.h"

typedef struct _pessoa{
    char nome[50];
    lista lista_LP;
} pessoa;
// pessoa é uma estrutura que contém o nome de um cliente e as sua lista

typedef struct _nodo_F{
    pessoa elem;
    struct _nodo_F *prox;
} nodo_F;
// nodo_F é a estrutura base para uma fila (FIFO) de clientes, ou pessoas

typedef struct _fila{
    nodo_F *frente, *fim;
} fila;
// fila é uma estrutura que possui um ponteiro para o nodo cabeça (frente) e outro para seu último elemento (fim)

void inicFila(fila *);
int Fila_vazia(fila );
void enfileirar(fila *, pessoa);
void desenfileirar(fila *);
void imprimeFila(fila );

#endif
