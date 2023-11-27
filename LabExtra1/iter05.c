#include <stdio.h>
#include <stdbool.h>
/*
Scrivere ua funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
e1 modifica in-place la matrice irregolare;
e1 non modifica la riga 0;
per ciascuna riga i>0, la funzione e1 scorre gli elementi e filtra via tutti gli elementi che compaiono sulla riga precedente;
e1 ritorna true se esiste almeno una riga che è stata modificata.
*/
bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) {
    bool ret = false;
    int count = 0;
    for (size_t i = 1; i < rows; i++){
        int ammount = rags[i];
        for (size_t j = 0; j < ammount; j++){
            int posDelete;
            bool findEl = false;
            //printf("Cerco l'elemento: %d, sono alla %zu:%zu colonna\n", mat[i][j], i,j);
            for (size_t k = 0; k < rags[i-1] && !findEl; k++){
                if(mat[i][j] == mat[i-1][k]){
                    findEl = true;
                    posDelete = j;
                }
                    
            }
            if (findEl){
                //printf("Trovato il signorotto per l'elemento: %d, nella posizione: %zu\n", mat[i][j], j);
                for(size_t k = posDelete; k < rags[i]-1; k++){
                    mat[i][k] = mat[i][k+1];
                }
                rags[i]--;
                if(j > 1){
                    j--;
                    ammount--;
                }
                count++;
            }
        }
        //printf("\n");
        
    }
    if(count > 0)
        ret = true;
    return ret;
}
