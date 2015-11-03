#include "filas.h"

void inicFila(fila *F)
{
  F->frente = (nodo *) malloc (sizeof(nodo));
  F->fim = F->frente;
  F->frente->prox = NULL;
}

int Fila_vazia(fila F)
{
  return (F.frente->prox == NULL);
}

void enfileirar(fila *F, char *str)
{
  F->fim->prox = (nodo *) malloc (sizeof(nodo));
  F->fim = F->fim->prox;
  F->fim->elem = (char *) malloc (sizeof(char) * (strlen(str)+1));
  strcpy(F->fim->elem, str);
  F->fim->prox = NULL;
}

//como nosso nodo.elem é do tipo char*, devemos retirar o valor antes de desenfileirar!
void desenfileirar(fila *F)
{
  nodo *aux;
  if (Fila_vazia(*F))
    printf ("Fila vazia!\n");
  else
    {
      aux = F->frente;
      F->frente = aux->prox;
      free(aux);
    }
}

void imprimeFila(fila F)
{
  nodo *aux;
  if (Fila_vazia(F))
    printf ("Fila vazia!\n");
  else
    for (aux = F.frente->prox; aux != NULL; aux = aux->prox)
      printf ("%s\n", aux->elem);
}
