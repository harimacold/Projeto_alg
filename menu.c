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

void cadastra_cliente(fila *F, FILE *log)
{
    pessoa novo; // novo cliente da Fila
    LP aux;
    int tam, i;

    printf ("Nome: ");
    scanf ("\n%[^\n]", novo.nome); // recebe nome do cliente

    inicLista(&(novo.lista_LP));
	fprintf(log,"Cadastrado novo cliente com o nome: %s\n",novo.nome); 
    printf ("Tamanho da lista: "); // recebe o tamanho da lista do cliente
    scanf ("%d", &tam);
    while (tam < 0)
    {
        printf("Entrada Invalida!\nEntre com outro valor: ");
        scanf("%d", &tam);
    }
    for (i = 0; i < tam; i++)
    {
        printf ("LP %d\n", i + 1);
        printf ("Artista: ");
        scanf ("\n%[^\n]", aux.nome);
        printf ("Album: ");
        scanf ("\n%[^\n]", aux.album);
        printf ("Valor: ");
        scanf ("%f", &aux.valor);
	fprintf(log,"		-cadastrado vinil %d com nome: %s, album %s, e valor de R$ %.2f\n", i+1, aux.nome, aux.album, aux.valor);
        insereLista (&(novo.lista_LP), aux); // ao fim do FOR, a lista do cliente estará cadastrada
    }
    enfileirar(F, novo);
}

void atende_cliente(fila *F, pilha *pil)
{
    pessoa fst; // pessoa que será atendida
    recibo novo; // novo recibo a ser colocado na pilha
    float acum = 0;
    nodo_lis *aux;
    char ch;

    printf("Nome do primeiro: %s\n", (F->frente->prox->elem).nome);
    printf("Imprimir Lista? (S/N): ");
    scanf ("\n%c", &ch);
    strcpy(fst.nome, (F->frente->prox->elem).nome); // salvaremos as informações do cliente da frente da fila
    copiaLista(&(fst.lista_LP), (F->frente->prox->elem).lista_LP); // salvamos a lista do cliente da frente da fila
    desenfileirar(F);
    for (aux = (fst.lista_LP)->prox; aux != fst.lista_LP; aux = aux->prox)
        acum = acum + aux->elem.valor; // ao fim do FOR acum possui o valor total da lista do cliente
    strcpy(novo.cliente, fst.nome); // copiamos o nome do cliente para o recibo
    novo.total = acum; // copiamos o total do cliente para o recibo
    push(pil, novo);
    if ((ch == 'S')||(ch == 's'))
        imprimeLista(fst.lista_LP); // se pedido pelo usuário, mostramos a lista do cliente antes de descartá-la
}

int main (void)
{
    FILE *log;
    int men, cont, i;
    fila clientes;
    pilha recibos;
    pilha *gaveta; //Esta variável é um adicional não pedido pelo trabalho

     log = fopen("log.txt","w");
	fputs("-------------Começando o programa-------------\n",log);
	fputs("Inicia Fila de cliente\n",log);
    inicFila(&clientes);
	fputs("Inicia Pilha de recibos\n\n\n",log);
    inicPilha(&recibos);
    gaveta = (pilha *) malloc (sizeof(pilha)); // gaveta será um vetor dinâmico de pilhas
    cont = 0;   // cont conta o número de espaços ocupados em gaveta
    printf ("1 - Novo cliente\n2 - Atender cliente\n3 - Imprimir estado de Fila\n4 - imprimir estado de Pilha\n5 - Engavetar Pilha\n6 - Mostrar Estado da Gaveta\n7 - Imprimir Pilha dentro da Gaveta\n8 - Mostra Menu\n0 - Sair\n\nEntrada: ");
/*
1 - Novo cliente
2 - Atender cliente
3 - Imprimir estado de Fila
4 - Imprimir estado de Pilha
5 - Engavetar Pilha
6 - Mostrar Estado da Gaveta
7 - Imprimir Pilha dentro da Gaveta
8 - Mostrar Menu
0 - Sair
*/

    scanf ("%d", &men);
    while (men != 0)
    {
        switch (men)
        {
        case 1:
            cadastra_cliente(&clientes, log);
            fprintf (log, "Cliente %s entrou na fila.\n\n", clientes.fim->elem.nome);
            break;
        case 2:
            atende_cliente(&clientes, &recibos);
            fprintf (log, "Cliente %s foi atendido, e foi colocado na pilha um recibo de valor %.2f.\n\n", recibos.vet[recibos.topo].cliente, recibos.vet[recibos.topo].total);
            break;
        case 3:
            imprimeFila(clientes);
            fprintf (log, "Fila de clientes foi impressa.\n\n");
            break;
        case 4:
            imprimePilha(&recibos);
             fprintf (log, "O estado atual da pilha foi impresso, indicando tamanho da pilha em %d.\n\n", recibos.topo);
            break;
        case 5:
            invertePilha(&(gaveta[cont]), &recibos); //engavetar vai inverter a pilha de recibos e guardar no último espaço alocado para a gaveta
            cont++;
            gaveta = (pilha *) realloc (gaveta, cont*sizeof(pilha)); // aqui abrimos espaço para a próxima pilha invertida
             fprintf (log, "A pilha de recibos foi invertida, impressa e engavetada.\n\n");
            break;
        case 6:
            printf("Ha %d pilha(s) dentro da gaveta!\n", cont);
            break;
        case 7:
            printf ("Qual? ");
            scanf ("%d", &i);
            if ((i > 0)&&(i <= cont))
            {
                imprimePilha(&gaveta[i-1]);
                fprintf (log, "A pilha de numero %d de dentro da gaveta foi mostrada.\n", i);
            }
            else
            {
                printf("Valor invalido!\n");
                fprintf (log, "ERRO: o usuario deveria entrar com um valor entre 1 e %d!\n", cont);
            }
            break;
        case 8:
            printf ("1 - Novo cliente\n2 - Atender cliente\n3 - Imprimir estado de Fila\n4 - imprimir estado de Pilha\n5 - Engavetar Pilha\n6 - Mostrar Estado da Gaveta\n7 - Imprimir Pilha dentro da Gaveta\n8 - Mostra Menu\n0 - Sair\n");
            break;
        }
        printf ("\n\nEntrada: ");
        scanf ("%d", &men);
        if ((men < 0)||(men>8))
            printf ("Entrada Invalida!");
    }
    printf ("Programa encerrado!\n");
    fputs ( "Programa encerrado!\n",log);
}
