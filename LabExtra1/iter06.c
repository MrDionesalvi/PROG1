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

/**
 * The function e1 checks if each row of a given matrix has a unique element that is both the maximum
 * in its row and the minimum in its column.
 * 
 * @param rows The parameter "rows" represents the number of rows in the matrix.
 * @param cols The parameter `cols` represents the number of columns in the matrix `mat`.
 * @param mat The parameter `mat` is a 2D array of integers with `rows` rows and `cols` columns.
 * 
 * @return The function `e1` returns a boolean value.
 */
bool e1(const size_t rows, const size_t cols, const int mat[rows][cols]){
    bool ret = false;
    int lastI = -1;
    int count = 0;
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            bool isMax = true;
            bool isMin = true;
            
            for (size_t k = 0; k < cols; k++){
                if(mat[i][j] < mat[i][k])
                    isMax = false;
            }
            for (size_t k = 0; k < rows; k++){
                if(mat[i][j] > mat[k][j])
                    isMin = false;
            }
            if(isMax && isMin){
                if(lastI != i){
                    count++;
                    lastI = i;
                }
                printf("%zu %zu\n", i, j);
            }
        }
    }

    if(count == rows)
        ret = true;
    return ret;
}