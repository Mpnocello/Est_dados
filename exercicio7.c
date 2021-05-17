#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vet(long long int n);
void mostrar_vet(long long int *vet, long long int n);
void busca_linear(long long int * vet, long long int n, long long int x);


int main()
{
    long long int x;
    long long int *vet;
    long long int n;
    srand(time(NULL));
    double t1,t2;
    FILE * arq;

    arq = fopen("tempos.csv","a+");
    if ( arq==NULL)
        return 0;

    printf("Digite um numero N:");
    scanf("%lld",&n);

    printf("Digite um numero X para ser encontrado:");
    scanf("%lld",&x);
    
    printf("\n Tamanho do vet: %lld",n);
    vet = cria_vet(n);
    //printf("\n vet desordenado: ");
    //mostrar_vet(vet, n);
    t1 = omp_get_wtime();
    t2 = omp_get_wtime();
    //printf("\n Tempo para ordenar: %f",t2-t1);
    fprintf(arq,"%lld;%f\n",n,t2-t1);
    printf("\n vet Ordenado: ");
    mostrar_vet(vet, n);
    printf("\n");
    busca_linear(vet,n,x);

    free(vet);
    
    fclose(arq);

    printf("\n");
    return 0;
}

long long int *cria_vet(long long int n)
{
    long long int *vet, i, sorteio, aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    vet[0]== rand()%3;
    for (i = 1; i < n; i++)
    {
        vet[i] = vet[i-1] + rand()%3+1;
    }


    return vet;
}

void mostrar_vet(long long int *vet, long long int n)
{
    long long int i;
    printf("\nvet: ");
    for (i = 0; i < n; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void busca_linear(long long int * vet, long long int n, long long int x)
{
    int i;
    int flag=0;

    for(i=0; i<n; i++)
    {   
        if(vet[i]==x)
        {
            printf("Numero encontrado:%lld\n",vet[i]);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("Numero nao encontrado");
    }
}

 void busca_binaria(long long int * vet, long long int n, long long int x, long long int inicio, long long int fim)
{

    long long int meio = (inicio+fim)/2;

    if(fim==inicio)
    {
        if(vet[inicio]==n){
            printf("Numero encontrado\n");
            return;
        }else{
            printf("Numero nao encontrado\n");
            return;
        }
    }

    if(vet[meio]==n)
    {
        printf("Numero encontrado:%lld"vet[meio]);
        return;
    }else{
        if(n>vet[meio])
        {
            busca_binaria(vet, n, meio+1, fim);
        }else{
            busca_binaria(vet, n, inicio, meio);
        }
    }
} 
