/*
Scrivere un programma C che legge dall'input un numero intero non negativo N, che rappresenta la lunghezza di una sequenza. 
Dopodiché, il programma legge una sequenza di N numeri interi, e memorizza tale sequenza in un'array.
È garantito che la sequenza non abbia più di MAX_N=20 elementi.

Il programma quindi:

Stampa "Vuoto." se la sequenza letta non ha elementi
Stampa "Errore: numero di elementi non valido." se la sequenza non ha un numero valido di elementi.
Altrimenti stampa la somma di tutti gli elementi che sono maggiori o uguali al quadrato dell'elemento minimo dell'intera sequenza letta.
For example:

Input
4
2 3 4 6
Result
10
*/

#include <stdio.h>
#include <limits.h>

int main(void) {
    int n;
    int n_max = 20;
    
    int min = INT_MAX;
    int somma = 0;
    int check = 1;
    
    scanf("%d", &n);
    
    if(n == 0){
        printf("Vuoto.");
        check = 0;
    }
    if(n < 0 || n > n_max){
        printf("Errore: numero di elementi non valido.");
        check = 0;
    }
    
    if (check){
        int numeri[n];
        for(int i = 0; i < n; i++){
            int check = scanf("%d",&numeri[i]);
            if (check == 0){
                printf("Errore: numero di elementi non valido.");
                i = n;
            }
            else {
                if(min > numeri[i]){
                    min = numeri[i];
                }
            }
        }
        int quad_min = min * min;
        //printf("||%d|%d||", min, quad_min);
        for(int i = 0; i < n; i++){
            if (quad_min <= numeri[i]){
                somma += numeri[i];
            }
        }
        printf("%d", somma);
    }
    return 0;
}