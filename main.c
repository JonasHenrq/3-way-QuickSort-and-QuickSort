#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ES.h"
#include "metodosLogaritmicos.h"

int main(int argc, char *argv[]) {
    int count = 0, count2 = 0, n=10;
    int tamanhoVet[n], tipoMetodo, tipoEntrada, tipoOrdem, semente, i;
    clock_t tempo;
    float tempoTotal;
    char entrada[11], saida[11], nome[100], ordem[15];

    semente = atoi(argv[1]);
    strcpy(entrada, argv[2]);
    strcpy(saida, argv[3]);
//    semente = 5;
//    strcpy(entrada, "entrada.txt");
//    strcpy(saida, "saida5.txt");

    //Ler entrada.txt e inserir no vetor ~tamanhoVet~ os números de elementos dos conjuntos
    lerEntrada(entrada, tamanhoVet);
    
    printf("Você deseja usar um arquivo ou gerar os numeros randômicos? \n");
    printf(" 1 - Inserir arquivo \n");
    printf(" 2 - Gerar números randomicos \n");
    scanf("%d", &tipoEntrada);
    printf("Em qual ordem? \n");
    printf(" 1 - Aleatória \n");
    printf(" 2 - Crescente \n");
    printf(" 3 - Decrescente \n");
    scanf("%d", &tipoOrdem);
    if (tipoOrdem == 1)
        strcpy(ordem, "Aleatoria");
    else if (tipoOrdem == 2)
        strcpy(ordem, "Crescente");
    else if (tipoOrdem == 3)
        strcpy(ordem, "Decrescente");
    
    if (tipoEntrada == 2) {
        for (i = 0; i < n; i++) {
            geraNomeArquivo(nome, tamanhoVet[i], "Desordenado", ordem); //Gera nome de arquivo. Ex: ArquivoDesordenado5000.txt
            geraVetor(tamanhoVet[i], nome, semente, tipoOrdem); //Gera vetor na ordem desejada e salva no arquivo ~nome~
        }
        return 0;
    }
    //PERGUNTAR O ALGORITMO DE ORDENAÇÃO A SER UTILIZADO
    printf("Qual o algoritmo de ordenacao que deseja utilizar?\n");
    printf(" 1 - QuickSort \n");
    printf(" 2 - QuickSort 3-way \n");
    scanf("%d", &tipoMetodo);
    
    for (i = 0; i < n; i++) {
        long long int *vetor;
        vetor = (long long int*)malloc(sizeof(long long int)*tamanhoVet[i]);
        if(vetor == NULL){
            printf("!");
        }
        geraNomeArquivo(nome, tamanhoVet[i], "Desordenado", ordem); //Gera nome de arquivo. Ex: ArquivoDesordenado5000.txt
        lerArquivo(nome, vetor);
        count = count2 = 0;
        switch (tipoMetodo) {
            case 1:
                tempo = clock();
                quickSort(vetor, 0, tamanhoVet[i] - 1, &count, &count2);
                tempoTotal = (clock() - tempo) / (double) CLOCKS_PER_SEC;
                break;
            case 2:
                tempo = clock();
                quick_sort(vetor, 0, tamanhoVet[i] - 1, &count, &count2);
                tempoTotal = (clock() - tempo) / (double) CLOCKS_PER_SEC;
                break;
        }
        //ABRIR O ARQUIVO DE SAÍDA E ESCREVER NELE O VETOR ORDENADO (USANDO A FUNÇÃO escreveArquivo)
        printf("Tempo: %f segundo(s)\n", tempoTotal);
        printf("Comparações:%d\n", count);
        printf("Trocas:%d\n", count2);
        geraNomeArquivo(nome, tamanhoVet[i], "Ordenado", ordem);
        escreveArquivo(nome, vetor, tamanhoVet[i]);
        escreveEstatistica(saida, tamanhoVet[i], tipoMetodo, tempoTotal, count, count2, ordem, i);
        free(vetor);
    }
    return (EXIT_SUCCESS);
}

