#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
    struct registro * fim;
}lista;


typedef struct registro
{
    int valor;
    struct registro * ant;
    struct registro * prox;
}registro;

void incluir_no_final(lista *l, int x);
void incluir_no_inicio(lista *l , int x);
void mostrar_lista(lista *l);
registro *aloca_registro();
lista *aloca_lista();

int main()
{
    lista *l;
    int opcao, numero;

    l = aloca_lista();

    do
    {
        printf("\n1 - Incluir no inicio da lista\n");
        printf("2 - Incluir no final da lista\n");
        printf("3 - Mostrar lista\n");
        printf("4 - Mostrar primos da lista\n");
        printf("5 - Mostrar lista de tras pra frente\n");
        printf("6 - Remover elemento da lista\n");
        printf("7 - Remover primos da lista\n");
        printf("8 - Sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Qual numero incluir no inicio da lista:\n");
            scanf("%d", &numero);
            incluir_no_inicio(l, numero);
            break;
        case 2:
            printf("Qual numero incluir no final da lista:\n");
            scanf("%d", &numero);
            incluir_no_final(l,numero);
            break;
        case 3:
            mostrar_lista(l);
            break;
        case 8:
            printf("Saindo do programa");
            break;
            
        default:
        printf("Opcao invalida");
            break;
        }

    } while (opcao!=8);
    
    return 0;
}

void incluir_no_inicio(lista *l , int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->inicio;

        l->inicio = novo;
        novo->prox = aux;
        aux->ant = novo;
    }
    l->qtd++;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->fim;
        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;
    }
    l->qtd++;
}


void mostrar_lista(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\nValor = %d", aux->valor);
            aux = aux->prox;
        }
    }
}

void mostrar_primos(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {

            printf("\nValor = %d", aux->valor);
            aux = aux->prox;
        }
    }
}
