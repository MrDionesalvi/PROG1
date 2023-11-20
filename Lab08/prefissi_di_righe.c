/*
Una riga rA di lunghezza lenA è prefisso di una riga rB di lunghezza lenB se lenA ≤ lenB e, per ogni elemento i ∈ [0, lenA), rA[i]==rB[i]. Scrivere un programma che, date due matrici irregolari matA e matB, determina se esistono righe di matA che sono prefissi di righe di matB.
INPUT: le matrici irregolari matA e matB. Ciascuna matrice irregolare è fornita indicando le dimensioni rows e cols, seguite, per ogni riga, dal numero di elementi inizializzati di tale riga e successivamente dagli elementi stessi della riga.
OUTPUT: le coppie di indici iA iB tali che la riga iA di matA è prefisso della riga iB di matB (una coppia di indici per linea dell'output).

Input	
2 3
3   9 -5 7 
1   2 
2 3
3   2 -5  9 
3   9 -5 -2

Result
1 0
*/

#include <stdio.h>
#include <stdbool.h>

/**
 * The function `leggi_matrice_irregolare` reads an irregular matrix from user input, where each row
 * has a different number of columns.
 * 
 * @param rows The number of rows in the matrix.
 * @param cols The parameter "cols" represents the number of columns in the matrix.
 * @param mat A 2D array representing the matrix.
 * @param rags The parameter "rags" is an array of size "rows" that stores the number of columns for
 * each row in the matrix.
 */
void leggi_matrice_irregolare(const size_t rows, const size_t cols,
				              int mat[rows][cols], size_t rags[rows]) 
{
	for (size_t r=0; r<rows; r++) {
	    scanf("%zu", &rags[r]);
		for (size_t c=0; c<rags[r]; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

int main(void) {
	// leggi la matrice irregolare A
	size_t rowsA, colsA;
	scanf("%zu %zu", &rowsA, &colsA);
	int matA[rowsA][colsA];
	size_t ragsA[rowsA];
	leggi_matrice_irregolare(rowsA, colsA, matA, ragsA);

	// leggi la matrice irregolare B
	size_t rowsB, colsB;
	scanf("%zu %zu", &rowsB, &colsB);
	int matB[rowsB][colsB];
	size_t ragsB[rowsB];
	leggi_matrice_irregolare(rowsB, colsB, matB, ragsB);

	/* The code snippet is a nested loop that compares each row of matrix A with each row of matrix B to
	check if any row in A is a prefix of a row in B. */
	for(size_t i = 0; i < rowsA; i++){
        for(size_t j = 0; j < rowsB; j++){
            int counter = 0;
            for(size_t k = 0; k < colsA && k < ragsA[i] && k < ragsB[j]; k++){
                if(matA[i][k] == matB[j][k]){
                    counter++;
                }
            }
            if(counter == ragsA[i]){
                printf("%zu %zu\n", i,j);
            }
        }
    }
}