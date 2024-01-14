#include <stdio.h>
#include <stdbool.h>
/*
Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
e1 modifica in-place la matrice irregolare;
per ciascuna riga i, la funzione e1 scorre le colonne valide e, per ogni colonna j il cui elemento è maggiore di 0 e multiplo di 3, aggiunge in fondo alla riga I l'elemento stesso diviso 3.
L'aggiunta degli elementi si interrompe se la riga raggiunge la capacità massima cols.
e1 ritorna true se tutte le righe hanno ricevuto almeno un'aggiunta di elementi. Ritorna false altrimenti.

*/

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) {
    bool ret = true;
    bool check = false;
    for (size_t i = 0; i < rows; i++){
        int count = 0;
        for (size_t j = 0; j < rags[i]; j++){
            if(mat[i][j] > 0 && mat[i][j] % 3 == 0){
                if(rags[i] < cols){
                    mat[i][rags[i]] = mat[i][j] / 3;
                    rags[i]++;
                    check = true;
                    count++;
                }
            }
        }
        if(!check || (count == 0 && rows != 0 && cols != 0)){
            ret = false;
        }

        
    }
    return ret;
}