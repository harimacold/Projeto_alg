#include "filas.h"
#include "pilhas.h"

/* TIPOS DEFINIDOS EM BIBLIOTECA
- lista (LP elem, prox, ant)
- fila (pessoa elem, prox)
- pilha (float elem[255], int topo)
- LP (nome, album, valor)
- pessoa (nome, lista_LP)
- recibo (cliente, total)
 */

void cadastra_cliente(fila *F)
{
  pessoa novo;
  LP aux;
  int tam, i;
  printf ("Nome: ");
  scanf ("\n%[^\n]", novo.nome);
  printf ("Tamanho da lista: ");
  scanf ("%d", &tam);
  for (i = 0; i < tam; i++)
    {
      printf ("LP %d\n", i + 1);
      printf ("Artista: ");
      scanf ("\n%[^\n]", aux.nome);
      printf ("Album: ");
      scanf ("\n%[^\n]", aux.album);
      printf ("Valor: ");
      scanf ("%f", &aux.valor);
      insereLista (&(novo.lista_LP), aux);
    }
  enfileirar(F, novo);
}
void atende_cliente(fila *, pilha *);
pessoa* selecClient(fila *);

int main (void)
{
  int men;
  fila clientes;
  pilha recibos;
  inicFila(&clientes);
  inicPilha(&recibos);
  printf ("1 - Novo cliente\n2 - Atender cliente\n3 - Imprimir estado de Fila\n4 - imprimir estado de Pilha\n5 - Imprimir lista de um cliente\n0 - Sair\n\nEntrada: ");
  /*
1 - Novo cliente
2 - Atender cliente
3 - Imprimir estado de Fila
4 - Imprimir estado de Pilha
5 - Imprimir lista de um cliente
0 - Sair

  */

  scanf ("%d", &men);
  while (men != 0)
    {
      switch (men)
	{
	case 1:
	  cadastra_cliente(&clientes);
	  break;
	case 2:
	  atende_cliente(&clientes, &recibos);
	  break;
	case 3:
	  imprimeFila(clientes);
	  break;
	case 4:
	  imprimePilha(&recibos);
	  break;
	case 5:
	  imprimeLista(selecClient(&clientes)->lista_LP);
	  break;
	}
      printf ("Entrada: ");
      scanf ("%d", &men);
    }
}
