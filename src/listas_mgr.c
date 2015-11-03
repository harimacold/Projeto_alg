#include "listas.h"

int main (void)
{
  lista lis;
  nodo *aux;
  int i;
  char str[256];
  inicLista(&lis);
  printf ("Isto eh um teste!\nMenu:\n1 - Novo Elemento\n2 - Remove Elemento\n3 - Imprime Lista\n4 - Versao Ordenada\n0 - Sair\n\nEntre com numero: ");
  scanf ("%d", &i);
  while ((i != 0)&&(i != 4))
    {
      switch (i)
	{
	case 1:
	  printf ("Entre com elemento: ");
	  scanf ("\n%[^\n]", str);
	  insereLista(&lis, str);
	  break;
	case 2:
	  if (Lista_vazia(lis))
	    printf("Lista Vazia!\n");
	  else
	    {
	      printf ("Qual? ");
	      scanf ("\n%[^\n]", str);
	      aux = lis->prox;
	      while ((aux != lis) && (strcmp(aux->elem, str) != 0))
		aux = aux->prox;
	      if (aux == lis)
		printf ("Este elemento nao existe!\n");
	      else
		removeLista(&lis, aux);
	    }
	  break;
	case 3:
	  imprimeLista(lis);
	  break;
	}
      printf ("Entre com numero: ");
      scanf ("%d", &i);
    }
  if (i == 4)
    {
      printf ("Ordenando...\n");
      ordenaLista(&lis);
      printf ("Menu:\n1 - Novo Elemento\n2 - Remove Elemento\n3 - Imprime Lista\n0 - Sair\n\nEntre com numero: ");
      scanf ("%d", &i);
      while (i != 0)
	{
	  switch (i)
	    {
	    case 1:
	      printf ("Entre com elemento: ");
	      scanf ("\n%[^\n]", str);
	      insereLista_Ordenada(&lis, str);
	      break;
	    case 2:
	      if (Lista_vazia(lis))
		printf("Lista Vazia!\n");
	      else
		{
		  printf ("Qual? ");
		  scanf ("\n%[^\n]", str);
		  aux = lis->prox;
		  while ((aux != lis) && (strcmp(aux->elem, str) != 0))
		    aux = aux->prox;
		  if (aux == lis)
		    printf ("Este elemento nao existe!\n");
		  else
		    removeLista(&lis, aux);
		}
	      break;
	    case 3:
	      imprimeLista(lis);
	      break;
	    }
	  printf ("Entre com numero: ");
	  scanf ("%d", &i);
	}
    }
  printf ("Programa encerrado!\n");
}
