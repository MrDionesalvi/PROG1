#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// CODICE NON FUNZIONANTE :()

/*
Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, ed un puntatore ad un intero pMinSumProd
una riga i viene definita come selezionata in base a questo criterio: calcoliamo i prodotti degli elementi di ciascuna colonna j<rags[i] per la quale l'elemento i,j è multiplo di 3; la riga i è selezionata se almeno una colonna j soddisfa il criterio, e se la somma di tutti questi prodotti è divisibile per 10.
e1 restituisce true se esistono almeno due righe selezionate. In questo caso, il valore di pMinSumProd viene inizializzato alla più piccola somma dei prodotti presente in una riga selezionata

*/

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    int *pMinSumProd) {
    bool ret = false;
	int minSumProd = INT_MAX;
	int count = 0;
	for(size_t i = 0; i < rows; i++){
		int sumProd = 0;
		for(size_t j = 0; j < rags[i]; j++){
			if(mat[i][j] % 3 == 0){
				sumProd += mat[i][j];
			}
		}
		if(sumProd % 10 == 0){
			count++;
			if(sumProd < minSumProd){
				minSumProd = sumProd;
			}
		}
	}
	if(count >= 2){
		ret = true;
		*pMinSumProd = minSumProd;
	}
	return ret;
}