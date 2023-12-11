/*Completare la funzione trova_coppia il cui prototipo è già fornito per risolvere efficientemente il seguente problema.
La funzione riceve in input:
un intervallo semiaperto [left, right) in un array a[] contenente numeri interi ordinati in ordine crescente;
una variabile somma_target di tipo intero;
due puntatori ad indici *pIndice1 e *pIndice2.
La funzione deve trovare due elementi all'interno dell'intervallo semiaperto [left, right) i cui valori sommano esattamente a somma_target. 
Se i due elementi esistono, allora la funzione trova_coppia deve ritornare true e, al momento del ritorno, *pIndice1 e *pIndice2  devono contenere gli indici dei due elementi individuati (quindi a[*pIndice1] + a[*pIndice2] == somma_target).
In ogni altro caso trova_coppia deve ritornare false.
NOTA: Non scrivete il main (la funzione viene chiamata "esternamente").
OUTPUT: per ciascun test, la funzione trova_coppia viene chiamata 20 volte. In output viene stampato un singolo carattere per chiamata: T=la somma target esiste, ed è stata trovata da trova_coppia; N=la somma_target non esiste, e trova_coppia ha ritornato false; F=la risposta di trova_coppia è sbagliata.*/

#include <stdio.h>
#include <stdbool.h>

int ricerca_binaria(const int a[], const int val,
                const size_t left, const size_t right) {
    int ret = -1;
    if (left >= right)
        return 0;
    if (left+1==right) {
        if (a[left]==val) {
            ret = left;
            return ret;
        }
    }
    else {
        int middle = (left+right)/2; 
        if(val < a[middle]) {
            ret = ricerca_binaria(a, val, left, middle); 
        }
        else { //key >= a[middle]
            ret = ricerca_binaria(a, val, middle, right);
        }       
    }
return ret;
}

bool trova_coppia(const int a[], const int somma_target,
             const size_t left, const size_t right,
             size_t *pIndice1, size_t *pIndice2){
    bool found = false;

    if(left+1==right || left >= right){
        return found;
    }
    else {
        int val = a[left];
        int elToFound = somma_target - val;
        int elFound = ricerca_binaria(a, elToFound, left, right);
        if(elFound != -1){
            found = true;
            *pIndice1 = left;
            *pIndice2 = elFound;
            return found;
        }
        else{
            return trova_coppia(a, somma_target, left+1, right, pIndice1, pIndice2);
        }
    }
    return found;
}