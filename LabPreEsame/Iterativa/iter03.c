#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/*
Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, ed un puntatore ad un intero pMinSumProd
e1 determina se ciascuna riga i é selezionata, seguendo queste regole: 
definiamo prod_j il prodotti degli elementi validi di una colonna j
definiamo sum_prod la somma dei prod_j di tutte le colonne j<rags[i] per le quali l'elemento i,j è multiplo di 3;
la riga i è selezionata se valgono contemporaneamente queste due condizioni:
  esiste almeno una colonna j<rags[i] per la quale l'elemento i,j è multiplo di 3;
  il valore sum_prod è divisibile per 10
e1 restituisce true se esistono almeno due righe selezionate. In questo caso, il valore di pMinSumProd viene inizializzato alla più piccola somma dei prodotti presente in una riga selezionata
*/

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    int *pMinSumProd) {
    int rowSel = 0;
    int min = INT_MAX;
    bool ret = false;
    for (size_t i = 0; i < rows; i++){
        bool check = false;
        int sum_prod = 0;
        for (size_t j = 0; j < rags[i]; j++){
            int prod_j = 1;
            if(mat[i][j] % 3 == 0){
                check = true;
                for (size_t k = 0; k < rows; k++){
                    if(rags[k] > j){
                        prod_j *= mat[k][j];
                    }
                }
                sum_prod += prod_j;
            }
        }
        if(check && (sum_prod % 10 == 0)){
            rowSel++;
            if(sum_prod < min){
                min = sum_prod;
            }
        }   
    }
    if(rowSel >= 2 ){
        ret = true;
        *pMinSumProd = min;
    }
    return ret;
}