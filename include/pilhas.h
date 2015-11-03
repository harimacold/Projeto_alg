#ifndef PILHAS_H
#define PILHAS_H

#include <stdio.h>
#include <string.h>
#define pilhamax 255

typedef struct _recibo{
  char cliente[50];
  float total;
} recibo;

typedef struct _pilha{
  recibo vet[pilhamax];
  int topo;
} pilha;

void inicPilha(pilha *);
int Pilha_vazia(pilha *);
void push(pilha *, recibo );
void pop(pilha *);
void imprimePilha(pilha *);
int tamanhoPilha(pilha *);
void invertePilha(pilha *);

#endif
