/*
Scrivere un programma che legge una serie di sequenze di numeri interi positivi terminati dallo zero.
Per ciascuna sequenza letta, il main deve stampare, su di una linea di testo, i seguenti elementi:

la somma degli elementi della sequenza
la somma dei quadrati degli elementi della sequenza
il massimo degli elementi della sequenza
Se la sequenza letta non ha elementi (cioè é subito terminata dallo zero), il programma termina.

SUGGERIMENTO: scrivere una funzione leggi_sequenza, che si occupa di leggere una singola sequenza terminata da 0 e restituisce al main le tre quantità da stampare. La funzione restituisce true se la sequenza letta non è vuota.

Scrivere nel main un ciclo che chiama leggi_sequenza() e poi stampa le tre quantità richieste.
Il ciclo nel main termina quando viene letta la sequenza vuota.

NOTA: non bisogna usare un array per leggere l'input!

For example:

Input	
1 0
1 2 0
0

Result
1 1 1
3 5 
*/

#include <stdio.h>
#include <stdbool.h>

void leggi_sequenza(int firstNumber) {
    int numero = firstNumber;
    int sommaEl = firstNumber;
    int sommaQuadEl = firstNumber*firstNumber;
    int maxEl = firstNumber;
    int check = 1;
    
    while (check){
        scanf("%d", &numero);
        if (numero != 0){
            sommaEl += numero;
            sommaQuadEl += (numero * numero);
            if (numero > maxEl){
                maxEl = numero;
            }
        }
        else {
            check = 0;
        }
    }
    printf("%d %d %d\n", sommaEl, sommaQuadEl, maxEl);
}

int main(void) {
    int fNumero = 1;
    int check = 1;
    while (check){
        scanf("%d", &fNumero);
        if (fNumero != 0){
            leggi_sequenza(fNumero);
        }
        else {
            check = 0;
        }
    }
    return 0;
}