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

void leggi_matrice(const size_t rows, const size_t cols,
				   int mat[rows][cols]) {
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

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

	// COMPLETARE
    for (size_t i = 0; i < cols; i++){
        int resultColonna = 0;
        for (size_t j = 0; j < rows; j++){
            if(div(mat[j][i])){
                resultColonna++;
            }
        }
        //printf("%d %zu\n", resultColonna, cols);
        if(resultColonna == rows){
            //printf("Dentro con %d \n", i);
            for (size_t j = 0; j < rows; j++){
                int resultRiga = 0;
                //printf("Dentro il for con la riga %d\n", j);
                for(size_t k = 0; k < cols; k++){
                    //printf("Dentro il for con la riga %d\n", k);
                    if(div(mat[j][k])){
                        resultRiga++;
                    }
                }
                //printf("%d", resultRiga);
                if(resultRiga == cols){
                    printf("%zu %zu\n", j, i);
                }
            }
            

        }
        resultColonna = 0;
        
    }
    
}