/*
Scrivere una funzione e2 con le seguenti caratteristiche:
e2 prende in ingresso una matrice irregolare di interi (rows, cols, mat, args) e un valore intero val
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere una funzione e2R con le seguenti caratteristiche:
e2R esegue una ricorsione sulle righe della matrice mat
e2R delle lunghezze di tutte le righe i di mat per le quali esiste almeno un'occorrenza dell'elemento val lungo la riga. (Suggerimento: scrivere una ulteriore funzione ricorsiva esiste_val_in_arrayR)
*/

#include <stdio.h>
#include <stdbool.h>

bool esiste_val_in_arrayR(size_t cols, const int a[], int val){
    bool ret = false;
    for(int i = 0; i < cols; i++){
        if(val == a[i]){
            ret = true;
        }
    }
    return ret;
}

int e2R(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val,
       size_t i, size_t somma) {
    int sum = somma;
    if(i == rows){
        return sum;
    }
    else{
        if(esiste_val_in_arrayR(rags[i], mat[i], val)){
            sum += rags[i];
        }
    }
    return e2R(rows, cols, mat, rags, val, i + 1, sum);
}

int e2(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val){
    return e2R(rows, cols, mat, rags, val, 0, 0);
}