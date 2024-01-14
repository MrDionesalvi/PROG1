#include <stdio.h>
#include <stdbool.h>


/*
Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, ed un array di interi (aLen, a)
definiamo come prodotto riga-array tra la riga i e l'array a[] la somma dei prodotti elemento per elemento tra la riga i della matrice e l'array, fino al limite della sequenza più piccola.
e1 determina se esistono righe per le quali il prodotto riga-array è sia maggiore di 0 che multiplo di 5: in quel caso, e1 ritorna true, e la somma di tutti i prodotti riga-array viene scritta nella variabile pSum.
In ogni altro caso, e1 ritorna false.
*/
bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) {
    bool ret = false;
    *pSum = 0;
    for (size_t i = 0; i < rows; i++){
        int sum = 0;
        for (size_t j = 0; j < rags[i] && j < aLen; j++){
            sum += mat[i][j] * a[j];
        }
        if(sum > 0 && sum % 5 == 0){
            ret = true;
            *pSum += sum;
        }
    }
    return ret;
    
}