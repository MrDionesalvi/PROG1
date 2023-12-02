#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


/*
Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, ed un puntatore ad un intero pMinSumProd
una riga i viene definita come selezionata in base a questo criterio: calcoliamo i prodotti degli elementi di ciascuna colonna j<rags[i] per la quale l'elemento i,j è multiplo di 3; la riga i è selezionata se almeno una colonna j soddisfa il criterio, e se la somma di tutti questi prodotti è divisibile per 10.
e1 restituisce true se esistono almeno due righe selezionate. In questo caso, il valore di pMinSumProd viene inizializzato alla più piccola somma dei prodotti presente in una riga selezionata

*/

/**
 * The function e1 checks if there are at least two rows in a matrix where the sum of the products of
 * the elements divisible by 3 is a multiple of 10, and if so, it returns true and assigns the minimum
 * sum of products to the variable pointed to by pMinSumProd.
 * 
 * @param rows The number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 * @param mat A 2D array of integers with dimensions rows x cols. Each element in the array represents
 * a value in the matrix.
 * @param rags The parameter `rags` is an array of size `rows` that specifies the number of columns in
 * each row of the matrix `mat`.
 * @param pMinSumProd A pointer to an integer variable that will store the minimum sum product value if
 * the condition is met.
 * 
 * @return a boolean value.
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
				int prod = 1;
				for(size_t k = 0; k < rows; k++){
					if(j < rags[k]){
						prod *= mat[k][j];
					}
				}
				sumProd += prod;
			}
		}
		if(sumProd % 10 == 0 && sumProd != 0){
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