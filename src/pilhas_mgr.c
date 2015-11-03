#include "pilhas.h"

int main(void)
{
  pilha pil;
  int i;
  char str[256];
  inicPilha(&pil);
  printf ("Isto eh um teste!\nMenu:\n1 - Empilhar Elemento\n2 - Desempilhar\n3 - Imprime Pilha\n4 - Inverter Pilha\n0 - Sair\n");
  scanf("%d", &i);
  while (i != 0)
    {
      switch (i)
	{
	case 1:
	  if (pil.topo == pilhamax - 1)
	    printf ("Pilha cheia!\n");
	  else
	    {
	      printf ("Entre com elemento: ");
	      scanf ("\n%[^\n]", str);
	      push (&pil, str);
	    }
	  break;
	case 2:
	  if (Pilha_vazia(&pil))
	    printf ("Pilha Vazia!\n");
	  else
	    pop(&pil);
	  break;
	case 3:
	  imprimePilha(&pil);
	  break;
	case 4:
	  invertePilha(&pil);
	  break;
	}
      printf ("Entre com numero: ");
      scanf ("%d", &i);
    }
  printf ("Programa encerrado!\n");
}
