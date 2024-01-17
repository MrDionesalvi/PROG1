/*
Scrivere una funzione e2 con le seguenti caratteristiche:

e2 prende in ingresso una matrice irregolare di interi (rows, cols, mat, args) e un valore intero val
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere una funzione e2R con le seguenti caratteristiche:

e2R esegue una ricorsione sulle righe della matrice mat
e2R ritorna la somma delle lunghezze di tutte le righe i di mat per le quali esiste almeno un'occorrenza dell'elemento val lungo la riga. (Suggerimento: scrivere una ulteriore funzione ricorsiva esiste_val_in_arrayR)
*/

#include <stdio.h>
#include <stdbool.h>

bool esiste_val_in_arrayR(const int a[], size_t p_aLen, int val, size_t i){
    bool ret = false;
    if(i == p_aLen){
        return false;
    }
    else {
        if(a[i] == val){
            ret = true;
        }
        else {
            ret = esiste_val_in_arrayR(a, p_aLen, val, i+1);
        }
    }
    return ret;
}

int e2R(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val, size_t i, size_t result) {
    if(i == rows){
        return result;
    }
    else {
        if(esiste_val_in_arrayR(mat[i], rags[i], val, 0)){
            return e2R(rows, cols, mat, rags, val, i+1, result + rags[i]);
        }
        else {
            return e2R(rows, cols, mat, rags, val, i+1, result);
        }
    }
}

int e2(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val){
    return e2R(rows, cols, mat, rags, val, 0, 0);
}