#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ES.h"
#include "metodosLogaritmicos.h"

void lerEntrada(char nomeEntrada[], int n[]){
    int i;
    FILE *arq;
    arq = fopen(nomeEntrada, "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    i=0;
    while(!feof(arq)){
        fscanf(arq, "%d", &n[i]);
        i++;
    }
    fclose(arq);
}

void lerArquivo(char nomeArquivoEntrada[], long long int vetor[])
{
    int i=0;
    FILE *arq;
    printf("nome: %s\n", nomeArquivoEntrada);
    arq = fopen(nomeArquivoEntrada, "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    fscanf(arq, "%*[^\n]");
    while (!feof(arq)){
        fscanf(arq, "%d", &vetor[i]);
        i++;
    }
    fclose(arq);
}
void escreveArquivo(char nomeArquivoSaida[], long long int vetOrdenado[], int tamVetor)
{
    FILE *arq;
    arq = fopen(nomeArquivoSaida, "w");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
    }
    fprintf(arq, "%d\r\n", tamVetor);
    for(int i=0; i< tamVetor; i++)
    {
        //printf("%d\n", vetOrdenado[i]);
        fprintf(arq, "%d \r\n", vetOrdenado[i]);
    }
    printf("\n\t O vetor foi ordenado e salvo no arquivo %s \n\n", nomeArquivoSaida);
    fclose(arq);
}

void geraVetor(int tamanhoVet, char nomeArquivoEntrada[], int semente, int ordem) {
    long long int *vet;
    vet = (long long int*)malloc(sizeof(long long int)*tamanhoVet);
    FILE *arq;
    arq = fopen(nomeArquivoEntrada, "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
    }
    fprintf(arq, "%d\r\n", tamanhoVet);
    int i;
    srand(semente);
    printf("1\n");
    for (i = 0; i < tamanhoVet; i++) {
        vet[i] = rand() % tamanhoVet;
    }
    printf("2\n");
    if(ordem == 1){
        for (i = 0; i < tamanhoVet; i++)
            fprintf(arq, "%d\r\n", vet[i]);
    printf("3\n");
    }
    else{
        int count, count2;
        quickSort(vet, 0, tamanhoVet - 1, &count, &count2);
        if(ordem == 2){
            for (i = 0; i < tamanhoVet; i++)
                fprintf(arq, "%d\r\n", vet[i]);
        }
        else{
            for (i = (tamanhoVet-1); i >= 0; i--)
                fprintf(arq, "%d\r\n", vet[i]);
        }
    }
    fclose(arq);
    free(vet);
    return;
}

void geraNomeArquivo(char nome[], int tamanhoVet, char nomeArquivo[], char ordem[]){
    char num[10];
    snprintf(num, 10, "%d", tamanhoVet);
    strcpy(nome, nomeArquivo);
    strcat(nome, ordem);
    strcat(nome, num);
    strcat(nome, ".txt");
}

void escreveEstatistica(char nomeSaida[], int tamanhoVet, int metodo, float tempo, int comparacao, int troca, char ordem[], int iteracao){
    FILE *arq;
    arq = fopen(nomeSaida, "a");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
    }
    if(iteracao==0){
        char quick[20];
        if(metodo == 1)
            strcpy(quick, "Quick Sort");
        else
            strcpy(quick, "Quick Sort 3-Way");

        fprintf(arq, "\nEstatísticas de %s em ordem %s\n\n", quick, ordem);
    }
    fprintf(arq, "%d elementos:\n", tamanhoVet);
    fprintf(arq, "Tempo: %f \tTrocas: %8d \tComparações: %8d \n\n", tempo, troca, comparacao);
    
    fclose(arq);
}