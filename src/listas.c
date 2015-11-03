#include "listas.h"

void inicLista (lista *lis)
{
  *lis = (nodo *) malloc (sizeof (nodo));
  (*lis)->prox = *lis;
  (*lis)->ant = *lis;
}

int Lista_vazia (lista lis)
{
  return (lis->prox == lis);
}

void insereLista (lista *lis, char *str)
{
  (*lis)->ant->prox = (nodo *) malloc (sizeof (nodo));
  (*lis)->ant->prox->ant = (*lis)->ant;
  (*lis)->ant = (*lis)->ant->prox;
  (*lis)->ant->prox = (*lis);
  //necessário abrir o espeaço para a string nodo.elem do tamanho de str +1(para o \0)
  (*lis)->ant->elem = (char *) malloc ((strlen(str)+1)*sizeof(char));
  strcpy((*lis)->ant->elem, str);
}

//como nodo.elem é uma string será necessário lidar com seu valor com mais cuidado!
void removeLista (lista *lis, nodo *pt)
{
  nodo *aux;
  if (Lista_vazia(*lis))
    return;
  aux = pt->ant;
  aux->prox = pt->prox;
  aux->prox->ant = aux;
  free(pt);
}

void imprimeLista(lista lis)
{
  nodo *aux;
  if (Lista_vazia(lis))
    printf ("Lista vazia");
  else
    for (aux = lis->prox; aux != lis; aux = aux->prox)
      printf ("%s\n", aux->elem);
}

void apagaLista (lista *lis)
{
  nodo *aux;
  for (aux = (*lis)->prox; aux != *lis; aux = aux->prox)
    removeLista (lis, aux);
}

void insereLista_Ordenada(lista *lis, char *str)
{
  nodo *aux;
  char *save1, *save2;
  if (Lista_vazia(*lis))
    insereLista(lis, str);
  else
    {
      aux = (*lis)->prox; 
      while ((aux != (*lis)) && (strcmp(aux->elem, str) <= 0))
	aux = aux->prox;
      save1 = (char *) malloc (sizeof(char) * (1 + strlen(str)));
      strcpy (save1, str);
      while (aux != (*lis))
	{
	  save2 = (char *) malloc (sizeof(char) * (1 + strlen(aux->elem)));
	  strcpy (save2, aux->elem);
	  strcpy (aux->elem, save1);
	  free (save1);
	  save1 = (char *) malloc (sizeof(char) * (1 + strlen(save2)));
	  strcpy (save1, save2);
	  free (save2);
	  aux = aux->prox;
	}
      insereLista(lis, save1);
      free (save1);
    }
}

void ordenaLista (lista *lis)
{
  lista aux;
  inicLista(&aux);
  while ((*lis)->prox != (*lis))
    {
      insereLista_Ordenada(&aux, (*lis)->prox->elem);
      removeLista(lis, (*lis)->prox);
    }
  while (aux->prox != aux)
    {
      insereLista(lis, aux->prox->elem);
      removeLista(&aux, aux->prox);
    }
  free(aux);
}
