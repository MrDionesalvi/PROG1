/*
Scrivere una funzione e2 con le seguenti caratteristiche:

e2 prende in ingresso un puntatore ad una stringa
e2 é una funzione involucro che chiama una funzione ricorsiva e2R.
Scrivere inoltre una funzione e2R con le seguenti caratteristiche:

e2R modifica in-place la stringa, filtrando i caratteri secondo un criterio. Dopo la modifica, la stringa deve essere terminata correttamente con il terminatore '\0'.
e2R scorre i caratteri della stringa uno ad uno. Dato un carattere c, se non esistono altre occorrenze di c nel resto della stringa, allora c viene mantenuto. Altrimenti c viene scartato.
*/

#include <stdio.h>
#include <stdbool.h>

bool esiste_carattere(char *str, char element) { // metodo suggerito da implementare
    bool ret = false;
    int elFound = 0;
    for(; *str != '\0' && !ret; str++){
        if(*str == element){
            elFound++;
            if(elFound > 1 ){
                ret = true;
            }
        }
    }
    return ret;
}

void e2R(char* pStr, char* dStr) {
    if(*dStr == '\0'){
        *pStr = '\0';
        return;
    }
    else{
        if(esiste_carattere(dStr, *dStr)){
            return e2R(pStr, dStr+1);
        }
        else {
            *pStr = *dStr;
            return e2R(pStr+1, dStr+1);
        }
    }
}

void e2(char* pStr) {
    return e2R(pStr, pStr);
}