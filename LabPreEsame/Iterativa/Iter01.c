#include <stdio.h>
#include <stdbool.h>

/*
Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi
e1 determina se le righe della matrice in ingresso sono tutte lunghe almeno quanto rows, e se in ciascuna riga i esiste un elemento multiplo di 7. In questo caso, ritorna la somma dei primi multipli di 7 che compaiono sulla sinistra di ciascuna riga. Altrimenti, ritorna 0.

*/

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows]) {
    int sum = 0;
    bool check = true;
    for(size_t i = 0; i < rows && check; i++){
        if(rags[i] >= rows){
            bool elFound = false;
            for(size_t j = 0; j < rags[i]; j++){
                if((mat[i][j] % 7 == 0) && !elFound){
                    sum += mat[i][j];
                    elFound = true; 
                }
            }
        }
        else {
            check = false;
        }
    }

    if(!check)
        sum = 0;

    return sum;
}