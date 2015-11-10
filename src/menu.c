#include "listas.h"
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
    inicLista(&(novo.lista_LP));
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

void atende_cliente(fila *F, pilha *pil)
{
    nodo_F *frnt = F->frente->prox;
    pessoa fst;
    recibo novo;
    float acum = 0;
    nodo_lis *aux;
    char ch;
    printf("Nome do primeiro: %s\n", (frnt->elem).nome);
    printf("Imprimir Lista? (S/N): ");
    scanf ("\n%c", &ch);
    strcpy(fst.nome, (frnt->elem).nome);
    copiaLista(&(fst.lista_LP), (frnt->elem).lista_LP);
    desenfileirar(F);
    for (aux = (fst.lista_LP)->prox; aux != fst.lista_LP; aux = aux->prox)
        acum = acum + aux->elem.valor;
    strcpy(novo.cliente, fst.nome);
    novo.total = acum;
    push(pil, novo);
    if (ch == 'S')
        imprimeLista(fst.lista_LP);
}

int main (void)
{
    int men;
    fila clientes;
    pilha recibos;
    inicFila(&clientes);
    inicPilha(&recibos);
    printf ("1 - Novo cliente\n2 - Atender cliente\n3 - Imprimir estado de Fila\n4 - imprimir estado de Pilha\n0 - Sair\n\nEntrada: ");
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
        }
        printf ("\n\nEntrada: ");
        scanf ("%d", &men);
    }
    printf ("Program encerrado!\n");
}