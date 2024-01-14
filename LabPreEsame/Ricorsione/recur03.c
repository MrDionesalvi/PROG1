/*
Scrivere una funzione e2 con le seguenti caratteristiche:

e2 prende in ingresso un array (aLen, a) e un valore intero positivo val
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere inoltre una funzione e2R con le seguenti caratteristiche:
e2R esegue una ricorsione dicotomica sugli elementi di a[]
e2R ritorna la somma di tutti gli elementi di a[] il cui valore è compreso tra -val e +val, estremi inclusi.
Se non ci sono elementi nell'array a[], e2R ritorna 0.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int e2R(const size_t right, const int a[], const int val, size_t left){
    int sum = 0;
    if(left+1==right || left==right){
        if(a[left] >= -val && a[left] <= val){
            sum = a[left];
        }
    }
    else{
        int middle = (left+right) / 2;
        sum += e2R(middle, a, val, left);
        sum += e2R(right, a, val, middle);
    }
    return sum;
}

int e2(const size_t aLen, const int a[], const int val) {
    return e2R(aLen, a, val, 0);
}