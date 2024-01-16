/*
Scrivere una funzione e2 con le seguenti caratteristiche:
e2 prende in ingresso due array: (aLen, a) e (bLen, b)
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere una funzione e2R con le seguenti caratteristiche:
e2R rimuove in place tutte le occorrenze, eccetto la prima, di ogni elemento di a che compare anche in b.
e2R restituisce la nuova dimensione di a.
*/

#include <stdio.h>
#include <stdbool.h>

//TODO: DA RIVEDERE!!!!!!!!

// restituisce true se un elemento val esiste in un dato array
bool esiste_elemento(size_t* p_aLen, int a[], const size_t bLen, const int b[], const int number, size_t* position) {
    bool ret = false;
    size_t elFound = 0;
    for(size_t i = 0; i < *p_aLen && elFound < 2; i++){
        for(size_t j = 0; j < bLen; j++){
            if((a[i] == b[j]) && (a[i] == number)){
                elFound++;
                *position = i;
            }
        }
    }
    if(elFound > 1){
        ret = true;
    }
    return ret;
}

// rimuove tutte le occorrenze di un elemento val in un array, 
// partendo da un indice i data in input.
void rimuovi_elementiR(size_t* p_aLen, int a[], size_t left, size_t i){
    if(i+1 == *p_aLen){
        return;
    }
    else {
        a[i] = a[i+1];
    }
    return rimuovi_elementiR(p_aLen, a, left, i+1);

}

int e2R(size_t* p_aLen, int a[], const size_t bLen, const int b[], size_t result, size_t i) {
    if(i == *p_aLen){
        return result;
    }
    else {
        size_t position = 0;
        if(esiste_elemento(p_aLen, a, bLen, b, a[i], &position)){
            rimuovi_elementiR(p_aLen, a, position, position);
            *p_aLen = *p_aLen - 1;
            return e2R(p_aLen, a, bLen, b, result + 1, i +1);
        }
    }
    return e2R(p_aLen, a, bLen, b, result, i +1);
}

int e2(size_t* p_aLen, int a[], const size_t bLen, const int b[]) {
    return e2R(p_aLen, a, bLen, b, 0, 0);
}