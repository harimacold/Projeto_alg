#include "filas.h"
#include "pilhas.h"
#include "listas.h"


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

void cadastra_pessoa(fila *F){
	pessoa cliente;
	scanf("\n%[^\n]",cliente.nome);
	while(cliente.nome !="0"){
		cadastra_lp(&cliente.lista_LP);	
		enfileirar(F, cliente);
		scanf("\n%[^\n]",cliente.nome);
	}
}
void cadastra_lp(lista *lps){
	LP lp;
	inicLista(lps);
	scanf("\n%[^\n]",lp.nome);
	while (lp.nome !="0"){
	scanf("\n%[^\n]",lp.album);
	scanf("%f",lp.valor);
	insereLista(lps,lp);
	scanf("\n%[^\n]",lp.nome);
	}
}
int main(void){
	fila pessoas;
	cadastra(&pessoas);
	imprimeFila(pessoas);
}
  
