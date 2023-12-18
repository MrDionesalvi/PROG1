/*
Scrivere una funzione e2 con le seguenti caratteristiche:
e2 prende in ingresso un puntatore ad una stringa
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere inoltre una funzione e2R con le seguenti caratteristiche:
e2R modifica in-place la stringa, filtrando i caratteri secondo un criterio. Dopo la modifica, la stringa deve essere terminata correttamente con il terminatore '\0'.
e2R scorre i caratteri della stringa uno ad uno. Dato un carattere c, se non esistono altre occorrenze di c nel resto della stringa, allora c viene mantenuto. Altrimenti c viene scartato.
*/


// TODO: RISOLVERE UTILIZZO PROBABILMENTE ILLEGALE DELLA VARIABILE SENTINELLA "-".
#include <stdio.h>
#include <stdbool.h>

bool esiste_carattere(char* pStr, char c) { // metodo suggerito da implementare
    bool ret = false;
    int counter = 0;
    for(; *pStr != '\0'; pStr++){
        if(*pStr == c){
            counter++;
        }    
    }
    if(counter > 1){
        ret = true;
    }
    return ret;
}

void e2R(char* pStr, char* pStd, char* iStr) {
    //printf("Carattere: %c ", *pStr);
    if (*pStr == '\0'){
        //printf("Return 0");
        *pStd = '\0';
        return;
    }
    else {
        if(!esiste_carattere(iStr, *pStr) && *pStr != '-'){
            //printf("carattere unico!");
            *pStd = *pStr;
            pStd++;
        }
        else {
            *pStr = '-';
        }
    }
    //printf("%s\n", iStr);
    return e2R(pStr+1, pStd, iStr);
}

void e2(char* pStr) {
    e2R(pStr, pStr, pStr);
    return;
}


