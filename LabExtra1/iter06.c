#include <stdio.h>
#include <stdbool.h>

/*
Scrivere un funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice rettangolare (rows, cols, mat[rows][cols]) di interi.
e1 stampa in output tutte le coppie (i,j) che rappresentano l'indice di un punto di sella.
Chiamiamo 'punto di sella' un elemento nella matrice mat[i][j] alla posizione (i,j) che ha le seguenti caratteristiche:
l'elemento mat[i][j] è il massimo nella riga i e minimo nella riga j.


NOTA: (i1, j1) deve essere stampata prima della coppia (i2, j2) se i1<i2 oppure se (i1==i2 && j1<j2).
*/

bool e1(const size_t rows, const size_t cols, const int mat[rows][cols]){
    bool ret = false;
    for (size_t i = 0; i < rows; i++){
        int max = mat[i][0];
        int posMax = 0;
        for (size_t j = 1; j < cols; j++){
            if(mat[i][j] > max){
                max = mat[i][j];
                posMax = j;
            }
        }
        int min = mat[0][posMax];
        for (size_t j = 1; j < rows; j++){
            if(mat[j][posMax] < min){
                min = mat[j][posMax];
            }
        }
        if(min == max){
            printf("%zu %d\n", i, posMax);
            ret = true;
        }
    }
    return ret;
}