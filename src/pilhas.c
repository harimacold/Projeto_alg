#include "pilhas.h"

void inicPilha(pilha *pil)
{
    pil->topo = -1;
}
// inicPilha coloca o topo em -1 (nesse momento isso significa pilha vazia)

int Pilha_vazia(pilha *pil)
{
    return (pil->topo == -1);
}
// a pilha está fazia se seu topo for -1 e cheia se o topo for 255

void push(pilha *pil, recibo novo)
{
    if (pil->topo == pilhamax - 1)
        printf ("Pilha cheia!\n");
    else
    {
        (pil->topo)++;
        strcpy((pil->vet)[pil->topo].cliente, novo.cliente);
        (pil->vet)[pil->topo].total = novo.total;
        if (pil->topo == pilhamax - 1)
        printf ("Pilha cheia!\n");
    }
}
// push coloca um novo elemento acima do topo da pilha e aumenta então o valor do topo em 1
// se a pilha encher em decorrência disso, a função já avisa o usuário sobre isso

void pop(pilha *pil)
// os elemento da pilha são struct, então devemos tratar seu valor antes de entrar nesta função! Por isso usamos void.
{
    if (Pilha_vazia(pil))
        printf ("Pilha vazia");
    else
        (pil->topo)--;
}
// pop não precisa apagar o elemento, apenas diminuir o topo, o elemento então não será considerado a partir de então

void imprimePilha(pilha *pil)
{
    int i;
    if (Pilha_vazia(pil))
        printf("Pilha Vazia!\n");
    else
    {
        for (i = 0; i <= pil->topo; i++)
            printf ("Cliente: %s\nValor: %f\n\n", (pil->vet)[i].cliente, (pil->vet)[i].total);
        printf ("Tamanho da Pilha: %d\n\n", i);
    }
}
// além de imprimir o estado da pilha, imprime também seu tamanho

int tamanhoPilha(pilha *pil)
{
    return (pil->topo + 1);
}

void invertePilha(pilha *pilinv, pilha *pil)
{
    int i, j = pil->topo;
    inicPilha(pilinv);
    for(i=j; i >= 0; i--)
    {
        push(pilinv, pil->vet[i]);
        pop(pil);
    }
}
// invertePilha inverte pil e guarda o resultado em pilinv, além de apagar pil.
