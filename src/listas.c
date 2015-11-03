#include "listas.h"

void inicLista (lista *lis)
{
  *lis = (nodo_lis *) malloc (sizeof (nodo_lis));
  (*lis)->prox = *lis;
  (*lis)->ant = *lis;
}

int Lista_vazia (lista lis)
{
  return (lis->prox == lis);
}

void insereLista (lista *lis, LP novo)
{
  (*lis)->ant->prox = (nodo_lis *) malloc (sizeof (nodo_lis));
  (*lis)->ant->prox->ant = (*lis)->ant;
  (*lis)->ant = (*lis)->ant->prox;
  (*lis)->ant->prox = (*lis);
  strcpy(((*lis)->ant->elem).nome, novo.nome);
  strcpy(((*lis)->ant->elem).album, novo.album);
  ((*lis)->ant->elem).valor = novo.valor;
}

//como nodo.elem é uma struct será necessário lidar com seus valores com mais cuidado!
void removeLista (lista *lis, nodo_lis *pt)
{
  nodo_lis *aux;
  if (Lista_vazia(*lis))
    return;
  aux = pt->ant;
  aux->prox = pt->prox;
  aux->prox->ant = aux;
  free(pt);
}

void imprimeLista(lista lis)
{
  nodo_lis *aux;
  if (Lista_vazia(lis))
    printf ("Lista vazia");
  else
    for (aux = lis->prox; aux != lis; aux = aux->prox)
      printf ("Nome:%s\nAlbum:%s\nValor:%f\n\n", (aux->elem).nome, (aux->elem).album, (aux->elem).valor);
}

void copiaLista (lista *liscp, lista lis)
{
  nodo_lis *aux;
  inicLista(liscp);
  for (aux = lis->prox; aux != lis; aux = aux->prox)
    insereLista(liscp, lis.elem);
}
