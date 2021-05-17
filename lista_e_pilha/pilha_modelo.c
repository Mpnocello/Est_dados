#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    int valor;
    struct registro * prox;
}registro;

typedef struct pilha{
    struct registro * topo;
}pilha;

registro * aloca_registro()
{
    registro * novo;
    novo = (registro*)calloc(1, sizeof(registro));
    return novo;
}

pilha * aloca_pilha()
{
    pilha * nova;
    nova = (pilha*)calloc(1, sizeof(pilha));
    return nova;
}

int empty(pilha * p)
{
    if(p->topo == NULL)
        return 1;
    else
        return 0;
}

void push(pilha * p, int num)
{
    registro * novo;
    novo = aloca_registro();
    novo->valor = num;

    if(empty(p))
        p->topo = novo;
    else{
        novo->prox = p->topo;
        p->topo = novo;
    }
}

int pop(pilha * p)
{
    if(empty(p))
        return -1;
    else{
        registro * aux;
        int num;

        aux = p->topo;
        num = aux->valor;
        p->topo = p->topo->prox;
        free(aux);
        return num;
    }
}

int stackpop(pilha * p)
{
    if(empty(p))
        return -1;
    else
        return p->topo->valor;
}

void mostra_pilha(pilha * p)
{
    if(empty(p))
        printf("\n lista vazia");
    else{
        registro * aux;
        aux = p->topo;
        while(aux){
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }
}