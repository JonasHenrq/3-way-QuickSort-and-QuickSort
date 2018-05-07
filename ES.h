#ifndef ES_H
#define ES_H

void lerEntrada(char nomeEntrada[], int n[]);
void lerArquivo(char nomeArquivoEntrada[], long long int vetor[]);
void escreveArquivo(char nomeArquivoSaida[], long long int vetOrdenado[], int tamVetor);
void geraVetor(int tamanhoVet, char nomeArquivoEntrada[], int semente, int ordem);
void geraNomeArquivo(char nome[], int tamanhoVet, char nomeArquivo[], char ordem[]);
void escreveEstatistica(char nomeSaida[], int tamanhoVet, int metodo, float tempo, int troca, int comparacao, char ordem[], int iteracao);

#endif /* ES_H */

