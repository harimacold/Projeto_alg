#include "filas.h"

void inicFila(fila *F)
{
  F->frente = (nodo_F *) malloc (sizeof(nodo_F));
  F->fim = F->frente;
  F->frente->prox = NULL;
}

int Fila_vazia(fila F)
{
  return (F.frente->prox == NULL);
}

void enfileirar(fila *F, pessoa novo)
{
  F->fim->prox = (nodo_F *) malloc (sizeof(nodo_F));
  F->fim = F->fim->prox;
  strcpy((F->fim->elem).nome, pessoa.nome);
  copia
  F->fim->prox = NULL;
}

//como nosso nodo.elem é do tipo char*, devemos retirar o valor antes de desenfileirar!
void desenfileirar(fila *F)
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

void imprimeFila(fila F)
{
  nodo_F *aux;
  if (Fila_vazia(F))
    printf ("Fila vazia!\n");
  else
    for (aux = F.frente->prox; aux != NULL; aux = aux->prox)
      printf ("%s\n", (aux->elem).nome);
}
