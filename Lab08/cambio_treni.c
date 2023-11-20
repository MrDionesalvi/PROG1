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

    for(size_t i = 0; i < q; i++){
        int found = 0;
        int fromStation = quesiti[i][0];
        int toStation = quesiti[i][1];

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
