#include "filas.h"

void inicFila(fila *F)
{
    F->frente = (nodo_F *) malloc (sizeof(nodo_F));
    F->fim = F->frente;
    F->frente->prox = NULL;
}
// inicFila aloca espaço para o nodo cabeça

int Fila_vazia(fila F)
{
    return (F.frente->prox == NULL);
}

void enfileirar(fila *F, pessoa novo)
{
    F->fim->prox = (nodo_F *) malloc (sizeof(nodo_F));
    F->fim = F->fim->prox;
    strcpy((F->fim->elem).nome, novo.nome);
    copiaLista (&((F->fim->elem).lista_LP), novo.lista_LP);
    F->fim->prox = NULL;
}
// enfileirar aloca espaço depois do fim da fila e coloca o elemento novo neste espaço

void desenfileirar(fila *F)
// como nosso nodo.elem é uma struct, devemos retirar seu valor antes de desenfileirar! Por isso usamos void.
{
    nodo_F *aux;
    if (Fila_vazia(*F))
        printf ("Fila vazia!\n");
    else
    {
        aux = F->frente;
        F->frente = aux->prox;
        free(aux);
    }
}
// remove o primeiro elemento que foi colocado na fila (FIFO) e muda o nodo cabeça pra frente

void imprimeFila(fila F)
{
    nodo_F *aux;
    if (Fila_vazia(F))
        printf ("Fila vazia!\n");
    else
        for (aux = F.frente->prox; aux != NULL; aux = aux->prox)
        printf ("%s\n", (aux->elem).nome);
}
