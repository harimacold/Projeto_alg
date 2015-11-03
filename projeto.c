#include "filas.h"
#include "pilhas.h"
#include "listas.h"

void cadastra_lp(lista *lps){
	LP lp;
	inicLista(lps);
	printf ("Nome LP: ");
	scanf("\n%[^\n]",lp.nome);
	while (lp.nome[0] != '0'){
	  printf ("Nome Album: ");
	  scanf("\n%[^\n]",lp.album);
	  printf ("Valor: ");
	  scanf("%f",&(lp.valor));
	  insereLista(lps,lp);
	  printf ("Nome LP: ");
	  scanf("\n%[^\n]",lp.nome);
	}
}
void cadastra_pessoa(fila *F){
	pessoa cliente;
	printf ("Nome Pessoa: ");
	scanf("\n%[^\n]",cliente.nome);
	while(cliente.nome[0] != '0'){
		cadastra_lp(&cliente.lista_LP);	
		enfileirar(F, cliente);
		printf ("Nome Pessoa: ");
		scanf("\n%[^\n]",cliente.nome);
	}
}

int main(void){
	fila pessoas;
	cadastra_pessoa(&pessoas);
	imprimeFila(pessoas);
}
  
