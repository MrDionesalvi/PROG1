/*Completare la funzione ricerca_binaria il cui prototipo è già fornito. La funzione riceve in input:
un intervallo semiaperto [left, right) in un array a[] contenente numeri interi ordinati in ordine crescente;
una variabile val di tipo intero;
un puntatore ad un indice *pIndice.
La funzione deve cercare, tramite ricerca dicotomica, l'elemento di valore val all'interno dell'intervallo semiaperto [left, right) in a[]. 
Se un elemento di valore val esiste, allora la funzione ricerca_binaria deve restituire true e, al momento del ritorno, *pIndice deve contenere l'indice dell'elemento individuato nell'array (quindi a[*pIndice]==val).
In ogni altro caso ricerca_binaria deve restituire false.
NOTA: Non scrivete il main (la funzione viene chiamata "esternamente").
OUTPUT: per ciascun test, la funzione ricerca_binaria viene chiamata 20 volte. In output viene stampato un singolo carattere per chiamata: T=il valore val esiste nell'array a[], ed è stato trovato da ricerca_binaria; N=il valore val esiste nell'array a[], e ricerca_binaria ha ritornato false; F=la risposta di ricerca_binaria è sbagliata.*/
#include <stdio.h>
#include <stdbool.h>


bool ricerca_binaria(const int a[], const int val, size_t *pIndice,
                const size_t left, const size_t right) {
    int ret = false;
    if (left+1==right) {
        if (a[left]==val) {
            *pIndice = left;
            return true;
        }
    }
    else {
        int middle = (left+right)/2; 
        if(val < a[middle]) {
            ret = ricerca_binaria(a, val, pIndice , left, middle); 
        }
        else { //key >= a[middle]
            ret = ricerca_binaria(a, val,pIndice, middle, right);
        }       
    }
return ret;
}

