#include "pilhas.h"

void inicPilha(pilha *pil)
{
  pil->topo = -1;
}

int Pilha_vazia(pilha *pil)
{
  return (pil->topo == -1);
}

void push(pilha *pil, char *str)
{
  if (pil->topo == pilhamax - 1)
    printf ("Pilha cheia!\n");
  else
    {
      (pil->topo)++;
      strcpy((pil->vet)[pil->topo], str);
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
    printf ("%s\n", (pil->vet)[i]);
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
    strcpy(pil->vet[pil->topo - i], aux.vet[i]);
}
