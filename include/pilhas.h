#ifndef PILHAS_H
#define PILHAS_H

#include <stdio.h>
#include <string.h>
#define pilhamax 255

typedef struct _recibo{
    char cliente[50];
    float total;
} recibo;
// recibo é uma estrutura que contém o nome do cliente correspondente e o valor total da lista do mesmo

typedef struct _pilha{
    recibo vet[pilhamax];
    int topo;
} pilha;
// pilha é uma estrutura que possui um vetor de recibos, e um inteiro que indica o topo (no vetor)

void inicPilha(pilha *);
int Pilha_vazia(pilha *);
void push(pilha *, recibo );
void pop(pilha *);
void imprimePilha(pilha *);
int tamanhoPilha(pilha *);
void invertePilha(pilha *);

#endif
