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


// ritorna true se un elemento val esiste in un dato array
bool esiste_elemento(const int a[], size_t p_aLen, int elToFind, int pos) { // metodo suggerito da implementare
    bool ret = false;
    for(size_t i = pos; i < p_aLen && !ret; i++){
        if(a[i] == elToFind){
            ret = true;
        }
    }
    return ret;
}

int posizione_ultimoElemento(const int a[], size_t p_aLen, int elToFind, int pos) {
    int ret = -1;
    for(size_t i = pos; i < p_aLen; i++){
        if(a[i] == elToFind){
            ret = i;
        }
    }
    return ret;
}

// rimuove tutte le occorrenze di un elemento val in un array, 
// partendo da un indice i data in input.
void rimuovi_elementiR(int a[], size_t* p_aLen, int i){ // metodo suggerito da implementare
    if(i+1 == *p_aLen){
        return;
    }
    else {
        a[i] = a[i+1];
        return rimuovi_elementiR(a, p_aLen, i+1);
    }
}

int e2R(size_t* p_aLen, int a[], const size_t bLen, const int b[], size_t i, size_t result) {
    if(i == *p_aLen){
        return result;
    }
    else {
        if(esiste_elemento(b, bLen, a[i], 0) && esiste_elemento(a, *p_aLen, a[i], i+1)){
            int pos = posizione_ultimoElemento(a, *p_aLen, a[i], i+1);
            if(pos != -1){
                rimuovi_elementiR(a, p_aLen, pos);
                *p_aLen = *p_aLen - 1;
                return e2R(p_aLen, a, bLen, b, i, result + 1);
            }
        }
    }
    return e2R(p_aLen, a, bLen, b, i + 1, result);
}

int e2(size_t* p_aLen, int a[], const size_t bLen, const int b[]) {
    return e2R(p_aLen, a, bLen, b, 0, 0);
}