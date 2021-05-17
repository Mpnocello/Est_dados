#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vet(long long int n);
void mostrar_vet(long long int *vet, long long int tam);
void quicksort (long long int * vet, long long int inicio, long long int fim);


int main()
{
    long long int *vet;
    long long int tam;
    srand(time(NULL));
    double t1,t2;
    FILE * arq;

    arq = fopen("tempos.csv","a+");
    if ( arq==NULL)
        return 0;

    for (tam = 100000; tam <= 10000000 ; tam = tam + 100000)
    {
        //printf("\n Tamanho do vet: %lld",tam);
        vet = cria_vet(tam);
        //printf("\n vet desordenado: ");
        //mostrar_vet(vet, tam);
        t1 = omp_get_wtime();
        quicksort(vet, 0,tam-1);
        t2 = omp_get_wtime();
        printf("\n Tempo para ordenar: %f",t2-t1);
        fprintf(arq,"%lld;%f\n",tam,t2-t1);
        //printf("\n vet Ordenado: ");
        //mostrar_vet(vet, tam);
        free(vet);
    }
    fclose(arq);

    printf("\n");
    return 0;
}

long long int *cria_vet(long long int n)
{
    long long int *vet, i, sorteio, aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    for (i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        sorteio = rand() % n;
        aux = vet[i];
        vet[i] = vet[sorteio];
        vet[sorteio] = aux;
    }
    return vet;
}

void mostrar_vet(long long int *vet, long long int tam)
{
    long long int i;
    printf("\nvet: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void quicksort (long long int * vet, long long int inicio, long long int fim)
{

    if(inicio<fim)
    {
        int i, j, pivo, aux;

        i = inicio;
        j = fim;
        pivo = vet[i];

        while(i!=j)
        {
            if(i>j)
            {
                if(vet[j]>pivo)
                {
                    aux = vet[j];
                    vet[j] = vet[i];
                    vet[i] = aux;

                    aux = i;
                    i = j;
                    j = aux;
                }

            }else
            {
                if(vet[j]<pivo)
                {
                    aux = vet[j];
                    vet[j] = vet[i];
                    vet[i] = aux;

                    aux = i;
                    i = j;
                    j = aux;
                }
            }
            if(i>j)
            {
                j++;
            }else{
                j--;
            }
        }
        quicksort(vet,inicio,i);
        quicksort(vet,i+1,fim);
    }
}

