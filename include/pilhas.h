#ifndef PILHAS_H
#define PILHAS_H

#include <stdio.h>
#include <string.h>
#define strmax 255
#define pilhamax 255

typedef struct _pilha{
  char vet[pilhamax][strmax];
  int topo;
} pilha;

void inicPilha(pilha *);
int Pilha_vazia(pilha *);
void push(pilha *, char *);
void pop(pilha *);
void imprimePilha(pilha *);
int tamanhoPilha(pilha *);
void invertePilha(pilha *);

#endif
