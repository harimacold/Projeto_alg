#include "filas.h"
#include "pilhas.h"
#include "listas.h"

typedef struct tp_pessoa{
  char nome[50];
  lista lista_LP;
} pessoa;

typedef struct tp_LP{
  char nome[50], album[50];
  float valor;
} LP;

typedef struct tp_recibo{
  char cliente[50];
  float total;
} recibo;

float valor_total(lista *lis)
{
  float total = 0;
  nodo_lis *aux;
  if (Lista_vazia(lis))
    printf ("Lista vazia");
  else
    for (aux = lis->prox; aux != lis; aux = aux->prox)
      total += lis->elem.valor;
  return total;
}

void cadastrar(fila *F)
{
  F->fim->prox = (

int main(void)
{
  
