
#include <stdio.h>
#include <stdlib.h>
#include "metodosLogaritmicos.h"

void quickSort(long long int vet[], int inicio, int fim, int *count, int *count2) {
    int pivo;
    if (inicio < fim) {
        pivo = particiona(vet, inicio, fim, count, count2);
        quickSort(vet, inicio, pivo - 1, count, count2);
        quickSort(vet, pivo + 1, fim, count, count2);
    }
    return;
}

int particiona(long long int vet[], int inicio, int fim, int *count, int *count2) {
    int pivo, pos, i, aux;
    pivo = vet[inicio];
    pos = inicio;
    for (i = inicio + 1; i <= fim; i++) {
        (*count)++;
        if (vet[i] < pivo) {
            pos++;
            (*count)++;
            if (i != pos) {
                aux = vet[i];
                vet[i] = vet[pos];
                vet[pos] = aux;
                (*count2)++;
            }
        }
    }
    aux = vet[pos];
    vet[pos] = vet[inicio];
    vet[inicio] = aux;
    (*count2)++;
    return pos;
}

void exchange_values(long long int input_array[], int left_index, int right_index) {
    int temp_value = input_array[left_index];
    input_array[left_index] = input_array[right_index];
    input_array[right_index] = temp_value;
    return;
}

void quick_sort(long long int input_array[], int bottom_bound, int upper_bound, int *count, int *count2) {
    if (upper_bound <= bottom_bound) {
        return;
    }
    int lowest_index = bottom_bound;
    int i = bottom_bound + 1;
    int top_index = upper_bound;
    int pivot = input_array[bottom_bound];

    while (i <= top_index) {
        if (input_array[i] < pivot) {
            (*count)++;
            (*count2)++;
            exchange_values(input_array, lowest_index++, i++);
        } else if (input_array[i] >= pivot) {
            (*count)+=2;
            (*count2)++;
            exchange_values(input_array, i, top_index--);
        } else {
            (*count)+=3;
            i++;
        }
    }
    quick_sort(input_array, bottom_bound, lowest_index - 1, count, count2);
    quick_sort(input_array, top_index + 1, upper_bound, count, count2);
}