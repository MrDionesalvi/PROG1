/*
Ci sono rows città connesse da delle tratte ferroviarie. Una matrice irregolare mat rappresenta tali connessioni: la citta i è connessa da una tratta ferroviaria con la città j se il valore j compare nella riga i-esima di mat. Nella matrice è garantito che, se i è connessa con j, allora anche j è connessa con i.
Scrivere un programma che legge in input una matrice irregolare, seguita da un numero q di richieste. Per ogni richiesta, viene letta una coppia (from, to) che rappresentano il numero della città di partenza e della città di destinazione. Il programma deve rispondere ad ogni richiesta stampando una stringa:
"DIRETTO" se esiste una connessione diretta tra from e to;
"1 CAMBIO" se non esiste una connessione diretta tra from e to, ma esiste una città intermedia di indice middle tale che sia from che to sono connesse a middle;
"NO" se non esiste né una connessione diretta, né una connessione con un cambio.
INPUT: la matrice irregolare è fornita indicando le dimensioni rows e cols, seguite, per ogni riga, dal numero di elementi inizializzati di tale riga e successivamente dagli elementi stessi della riga.
L'elenco delle richieste è fornito indicando il numero totale q di richieste, seguito dalle coppie from to.
OUTPUT: una stringa per riga, per ciascuna delle q richieste.

Input	
5 3
2  1 2
3  0 2 4
2  0 1
1  4
2  1 3

3
0 1
2 4
0 3

Result
DIRETTO
1 CAMBIO
NO
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

/**
 * The function `leggi_matrice_regolare` reads values from the user and stores them in a 2D array.
 * 
 * @param rows The number of rows in the matrix.
 * @param cols The parameter "cols" represents the number of columns in the matrix.
 * @param mat The parameter "mat" is a 2-dimensional array of integers with "rows" rows and "cols"
 * columns.
 */
void leggi_matrice_regolare(const size_t rows, const size_t cols,
				              int mat[rows][cols]) 
{
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}


int main(void) {
	// leggi la matrice irregolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);
	int mat[rows][cols];
	size_t rags[rows];
	leggi_matrice_irregolare(rows, cols, mat, rags);

	// leggi il numero di interrogazioni
	size_t q;
	scanf("%zu", &q);
	int quesiti[q][2];
    leggi_matrice_regolare(q, 2, quesiti);

    /* The code snippet is a loop that iterates through each query and checks for the type of connection
    between two cities. */
    for(size_t i = 0; i < q; i++){
        int found = 0;
        int fromStation = quesiti[i][0];
        int toStation = quesiti[i][1];

        /* This for loop is iterating through the connections of the "fromStation" city. It checks if
        there is a direct connection between the "fromStation" and the "toStation" by comparing the
        values in the "mat" matrix. If a direct connection is found, the variable "found" is set to
        1. */
        for(size_t j = 0; j < rags[fromStation] && !found; j++){
            if(toStation == mat[fromStation][j]){
                found = 1;
            }
        }
        if(found){
            printf("DIRETTO\n");
        }
        else{
            for(size_t j = 0; j < rags[fromStation] && !found; j++){
                int nextStation = mat[fromStation][j];
                for(size_t k = 0; k < rags[nextStation]; k++){
                    if(toStation == mat[nextStation][k]){
                        found = 1;
                    }
                }
            }
            if(found){
                printf("1 CAMBIO\n");
            }    
            else{
                printf("NO\n");
            }
        }
    }

	
}
