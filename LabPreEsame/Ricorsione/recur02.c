#include <stdio.h>
#include <stdbool.h>

/*
Scrivere una funzione e2 con le seguenti caratteristiche:

e2 prende in ingresso due array: (aLen, a) e (bLen, b)
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere inoltre una funzione e2R con le seguenti caratteristiche:

e2R considera ciascuna coppia di elementi di a e di b nella medesima posizione, fino alla lunghezza massima di entrambi gli array.
Per ciascuna posizione, e2R calcola il prodotto (se entrambi gli elementi della coppia sono disponibili), oppure il quadrato dell'elemento (se un solo elemento è disponibile, e l'altro array è terminato).
e2R ritorna la somma dei valori calcolati fino alla lunghezza massima di entrambi gli array.
Se non ci sono elementi nei due array, e2R ritorna 0.
*/

int e2R(const size_t aLen, const int a[], const size_t bLen, const int b[], size_t maxLen, size_t sum, size_t i) {
    if(i == maxLen){
        return sum;
    }
    else {
        if(i < aLen && i < bLen){
            sum += a[i] * b[i];
        }
        else if(i < aLen && i >= bLen){
            sum += a[i]*a[i];
        }
        else if(i >= aLen && i < bLen){
            sum += b[i]*b[i];
        }
        return e2R(aLen, a, bLen, b, maxLen, sum, i+1);
    }
    return e2R(aLen, a, bLen, b, maxLen, sum, i+1);
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    size_t maxLen = 0;
    if(aLen > bLen){
        maxLen = aLen;
    }
    else {
        maxLen = bLen;
    }
    return e2R(aLen, a, bLen, b, maxLen,0, 0);
}