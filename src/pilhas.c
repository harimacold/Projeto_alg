#include "pilhas.h"

void inicPilha(pilha *pil)
{
  pil->topo = -1;
}

int Pilha_vazia(pilha *pil)
{
  return (pil->topo == -1);
}

void push(pilha *pil, recibo novo)
{
  if (pil->topo == pilhamax - 1)
    printf ("Pilha cheia!\n");
  else
    {
      (pil->topo)++;
      strcpy((pil->vet)[pil->topo].cliente, novo.cliente);
      (pil->vet)[pil->topo].total = novo.total;
      if (pil->topo == pilhamax - 1)
	printf ("Pilha cheia!\n");
    }
}

void pop(pilha *pil)
{
  if (Pilha_vazia(pil))
    printf ("Pilha vazia");
  else
    (pil->topo)--;
}

void imprimePilha(pilha *pil)
{
  int i;
  for (i = 0; i <= pil->topo; i++)
    printf ("Cliente: %s\nValor: %f\n\n", (pil->vet)[i].cliente, (pil->vet)[i].total);
  printf ("Tamanho da Pilha: %d\n", i);
}

int tamanhoPilha(pilha *pil)
{
  return (pil->topo + 1);
}

void invertePilha(pilha *pil)
{
  pilha aux;
  int i;
  inicPilha(&aux);
  for(i=0; i <= pil->topo; i++)
    push(&aux, pil->vet[i]);
  for(i=aux.topo; i >= 0; i--)
    {
      strcpy(pil->vet[pil->topo - i].cliente, aux.vet[i].cliente);
      pil->vet[pil->topo - i].total = aux.vet[i].total;
    }
}
