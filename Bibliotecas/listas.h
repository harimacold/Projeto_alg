#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _LP
{
    char nome[50], album[50];
    float valor;
} LP;
// LP é uma estrutura que contém o nome do artista, do album e do valor de um disco

typedef struct _nodo_lis{
    LP elem;
    struct _nodo_lis *prox, *ant;
} nodo_lis;
// nodo_lis é a estrutura base para uma lista circular

typedef nodo_lis *lista;
// lista é um ponteiro para o nodo cabeça da lista propriamente dita

void inicLista (lista *);
int Lista_vazia (lista );
void insereLista (lista *, LP );
void removeLista (lista *, nodo_lis *);
void imprimeLista (lista );
void copiaLista (lista *, lista);

#endif
