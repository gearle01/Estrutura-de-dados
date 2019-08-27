#include<stdlib.h> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAMANHO 100000
void merge(int vetor[], int inicio, int meio, int fim, int compas, int troca);
void mergeSort(int vetor[], int inicio, int meio, int compas, int troca);

void main() {
    int compas, troca;
    int vetor[TAMANHO]; //vetor com tamanho definido
    clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
    srand(time(NULL)); //Cria uma semente para numeros aleatorios
    tempoInicial = clock(); //inicia contagem do tempo
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 10; //Atribui um inteiro aleatorio entre 0 e 9
    }
    //Mostra valores do vetor nao ordenado
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d\t", vetor[i]);
    }
    printf("\n");
    //Chama a fucao passando o vetor como parametro
    mergeSort(vetor, 0, TAMANHO - 1, compas, troca);
    //Mostra valores do vetor ordenado   
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d\t", vetor[i]);
    }
    printf("\nA quantidade de comparações é: %d ",compas);
    printf("\nA quantidade de trocas é: %d",troca);
    printf("\n");
    tempoFinal = clock(); //finaliza contagem do tempo
    //calcula e mostra o tempo total de execucao
    printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

void merge(int vetor[], int inicio, int meio, int fim, int compas, int troca) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        &compas;
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        }
        else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        &compas;
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        &compas;
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int inicio, int fim, int compas, int troca) {
    compas++;
    if (inicio < fim) {
        int m = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, m, compas, troca);
        mergeSort(vetor, m + 1, fim, compas, troca);
        merge(vetor, inicio, m, fim, compas, troca);
        troca++;
    }
}