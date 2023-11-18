/*
Scrivere un programma C che legge dallo standard input una sequenza di elementi:
<nome_montagna>  <altezza>
dove il nome_montagna è una stringa di caratteri (non superiore a 50 caratteri), e altezza è un numero intero maggiore di 0. La sequenza termina quando non è più possibile leggere elementi.

Quando la sequenza termina, il programma stampa il nome della montagna più alta nella sequenza.

SUGGERIMENTI:

leggere una coppia <nome_montagna> <altezza> alla volta con una singola scanf, che deve quindi restituire il valore 2 per indicare la corretta lettura di entrambi i campi.
usare un secondo array di supporto che memorizza il nome della cima più alta trovata sino a quel punto.
For example:

Input
Corno_Nero 4222
Rocciamelone 3538
Punta_Nordend 4609
Monviso 3841

Result
Punta_Nordend

*/
#include <stdio.h>
#include <string.h>

int main(){
    char montagna[50];
    int altezza;
    
    char max_Montagna[50];
    int max_h = 0;
    
    int check = 1;
    
    while(check){
        int par = scanf("%s%d", montagna, &altezza);
        if(par != 2 || altezza < 0){
            check = 0;
        }
        else{
            if(max_h < altezza){
                strncpy(max_Montagna, montagna, sizeof(montagna)); // Sostituibile con un for che copia char per char.
                max_h = altezza;
            }
        }
        
    }
    printf("%s", max_Montagna);
}