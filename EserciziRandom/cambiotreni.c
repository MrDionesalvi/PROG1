#include <stdio.h>
#include <stdbool.h>

// Stats in vista dell'esame: 
// Tempo impiegato: 19 minuti
// Complessità: O^n3

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
	// leggi la matrice irregolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);
	int mat[rows][cols];
	size_t rags[rows];
	leggi_matrice_irregolare(rows, cols, mat, rags);

	// leggi il numero di interrogazioni
	size_t q, from, to;
	scanf("%zu", &q);
	for(int i = 0; i < q; i++){
        scanf("%zu %zu", &from, &to);
        bool found = false;
        for(int j = 0; j < rags[from] && !found; j++){
            if(mat[from][j] == to){
                found = true;
                printf("DIRETTO\n");
            }
        }
        if(!found){
            for(int j = 0; j < rags[from] && !found; j++){
                for(int k = 0; k < rags[mat[from][j]]; k++){
                    size_t new_from = mat[from][j];
                    if(mat[new_from][k] == to){
                        found = true;
                        printf("1 CAMBIO\n");
                    }
                }
            }
        }
        if(!found){
            printf("NO\n");
        }
    }
}
