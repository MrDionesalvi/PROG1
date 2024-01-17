/*
Scrivere una funzione e2 con le seguenti caratteristiche:

e2 prende in ingresso un array a[] di dimensione *p_aVal, e due interi min e max
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere inoltre una funzione e2R con le seguenti caratteristiche:

e2R esegue una ricorsione sugli elementi dell'array a[]
e2R filtra e modifica in-place gli elementi di a[], mantenendo solo gli elementi che sono compresi tra min e max (estremi inclusi)
alla fine della ricorsione, e2R modifica anche il valore puntato da *p_aVal, scrivendo il numero di elementi rimasti nell'array a[].
*/

#include <stdio.h>
#include <stdbool.h>

void e2R(size_t *p_aVal, int a[], const int min, const int max, int i, int j) {
    if(i  == *p_aVal){
        *p_aVal = j;
        return;
   }
   else {
        if(a[i] >= min && a[i] <= max){
            a[j] = a[i];
            return e2R(p_aVal, a, min, max , i+1, j+1);
        }
        else{
            return e2R(p_aVal, a, min, max, i+1, j);
        }
   }
}

void e2(size_t *p_aVal, int a[], const int min, const int max) {
    return e2R(p_aVal, a, min, max, 0, 0);
}
