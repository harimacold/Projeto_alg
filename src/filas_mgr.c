#include "filas.h"

int main (void)
{
  fila F;
  int i;
  char str[256];
  inicFila(&F);
  printf ("Isto eh um teste!\nMenu:\n1 - Enfileirar Elemento\n2 - Desenfileirar\n3 - Imprime Fila\n0 - Sair\n\nEntre com numero: ");
  scanf ("%d", &i);
  while (i != 0)
    {
      switch (i)
	{
	case 1:	  printf ("Entre com elemento: ");
	  scanf ("\n%[^\n]", str);
	  enfileirar(&F, str);
	  break;
	case 2:
	  if (Fila_vazia(F))
	    printf("Fila Vazia!\n");
	  else
	    desenfileirar(&F);
	  break;
	case 3:
	  imprimeFila(F);
	  break;
	}
      printf ("Entre com numero: ");
      scanf ("%d", &i);
    }
  printf ("Programa encerrado!\n");
}
