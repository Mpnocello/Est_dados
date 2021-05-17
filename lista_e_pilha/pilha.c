#include <stdio.h>
#include <stdlib.h>

int pilha[10];
int topo=0;


int empty();
void push(int x);
int pop();
int stackpop();
int segundo_elemento();
void mostrar_pilha();
int i;

int main()
{
    int opcao, numero;
    do
    {
        printf("1 - Push\n");
        printf("2 - Mostrar segundo elemento\n");
        printf("3 - Mostrar pilha\n");
        printf("5 - Sair do programa\n");
        scanf("%d", &opcao);


        switch (opcao)
        {
        case 1:
            printf("Digite um numero:\n");
            scanf("%d", &numero);
            push(numero);
            break;
        case 2:
            printf("Segundo elemento: %d\n", segundo_elemento());
            break;
        case 3:
            mostrar_pilha();
            break;
        case 5:
            printf("Saindo do programa\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 5);
    
}

int empty()
{
    if(topo==0)
    {
        return 1;
    }else{
        return 0;
    }
}

void push(int x)
{
    if (topo==10)
    {
        printf("Pilha cheia\n");
    }else
    {
        pilha[topo]=x;
        topo++;
    }
}

int pop()
{
    if(empty())
    {
        printf("Pilha vazia\n");
        return -1;
    }else
    {
        return pilha[--topo];
    }
}

int stackpop()
{
    if (empty())
    {
        printf("Pilha vazia\n");
    }else
    {
        return pilha[topo-1];
    }
}

int segundo_elemento()
{
    pop();
    int i = pop();
    return i;
}

void mostrar_pilha()
{
    int i = topo-1;

    if (empty())
    {
        printf("Pilha vazia\n");
        return;
    }

    while (i>=0)
    {
        printf("> %d\n", pilha[i]);
        i--;
    }
}