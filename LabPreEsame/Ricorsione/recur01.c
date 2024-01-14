/*
Scrivere una funzione e2 con le seguenti caratteristiche:
e2 prende in ingresso un'array (aLen, a), un secondo array (*p_bLen, b), ed un valore val.
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere inoltre una funzione e2R con le seguenti caratteristiche:
e2R considera ciascun elemento di a: se tale elemento é strettamente maggiore di val, allora e2R copia nell'array b la differenza dell'elemento di a con il valore val.
Al più *p_bLen elementi vengono scritti nell'array b. Quando e2R termina, il valore puntato da *p_bLen viene modificato con il numero di elementi effettivamente scritti nell'array b.
*/

#include <stdio.h>
#include <stdbool.h>

void e2R(const size_t aLen, const int a[], size_t* p_bLen, size_t bLen, int b[], 
		const int val, size_t i) {
    if(i == aLen) {
        return;
    }
    else {
        if(a[i] > val && *p_bLen < bLen) {
            b[*p_bLen] = a[i] - val;
            (*p_bLen)++;
        }
        return e2R(aLen, a, p_bLen, bLen, b, val, i+1);
    }
}

void e2(const size_t aLen, const int a[], size_t* p_bLen, int b[], 
		const int val) {
    size_t bLen = *p_bLen;
    *p_bLen = 0;
    e2R(aLen, a, p_bLen, bLen, b, val, 0);
}