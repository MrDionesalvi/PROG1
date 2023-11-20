/*
Scrivere un programma che legge dall'input una matrice rettangolare, e stampa in output tutte le coppie di indici r,c tali per cui tutti i numeri sulla riga r e sulla colonna c risultano non-negativi e pari.
INPUT: le dimensioni rows e cols, seguite da rows*cols interi che rappresentano le righe della matrice
OUTPUT: le coppie di indici che soddisfano i criteri indicati (una coppia per riga)
For example:
Input	
3 5
-9  10   0  -9   2 
0  10   6   2   6 
6   6  -4   2  -1 
Result
1 1

*/

#include <stdio.h>
#include <stdbool.h>

/**
 * The function `leggi_matrice` reads values from the user and stores them in a 2D array.
 * 
 * @param rows The number of rows in the matrix.
 * @param cols The parameter "cols" represents the number of columns in the matrix.
 * @param mat The parameter "mat" is a 2D array of integers. It represents a matrix with "rows" number
 * of rows and "cols" number of columns.
 */
void leggi_matrice(const size_t rows, const size_t cols,
				   int mat[rows][cols]) {
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

/**
 * The function "div" returns 1 if the input number is a positive even number, and 0 otherwise.
 * 
 * @param a The parameter "a" is an integer value that represents the number being checked for
 * divisibility and if is >= 0.
 * 
 * @return the value of the variable "ret".
 */
int div(int a){
    int ret = 0;
    if(a % 2 == 0 && a >= 0)
        ret = 1;
    return ret;
}

int main(void) {
	// leggi le dimensioni della matrice rettangolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);

	// riserva la memoria per la matrice di dimensione rows * cols
	int mat[rows][cols];
	
	// leggi i dati
	leggi_matrice(rows, cols, mat);

	
    /* The code snippet is iterating over each row of the matrix and checking if all the numbers in that
    row are non-negative and even. If all the numbers in the row satisfy the condition, it then iterates
    over each column and checks if all the numbers in that column are non-negative and even. If both the
    row and column satisfy the condition, it prints the indices of that cell (row and column) as output. */
    for (size_t i = 0; i < rows; i++){
        int resultRiga = 0;
        for (size_t j = 0; j < cols; j++){
            if(div(mat[i][j])){
                resultRiga++;
            }
        }
        if(resultRiga == cols){
            for (size_t j = 0; j < cols; j++){
                int resultColonna = 0;
                for(size_t k = 0; k < rows; k++){
                    if(div(mat[k][j])){
                        resultColonna++;
                    }
                }
                if(resultColonna == rows){
                    printf("%zu %zu\n", i, j);
                }
            }
            

        }
        resultRiga = 0;
        
    }
    
}