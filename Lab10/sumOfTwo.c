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