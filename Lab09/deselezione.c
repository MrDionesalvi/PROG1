#include <stdio.h>
#include <string.h>
/*
Una delezione nel DNA è un tipo di mutazione genica che consiste nella perdita di uno o più nucleotidi in una sequenza di DNA.
Scrivere un programma C che legge in input due stringhe (max: 100 caratteri) seq e del_seq. Dopodichè il programma, usando solo funzioni ricorsive, stampa tutti i caratteri di seq, eliminando tutte le occorrenze delle sottosequenze del_seq all'interno di seq e stampando al loro posto il carattere '-'.
Esempio: dati seq="TACGCACGAT" e del_seq="ACG", il programma deve stampare "T-C-AT".
Suggerimento: scrivere due funzioni ricorsive:
una funzione prefixR() che determina se una stringa è prefisso di un'altra stringa.
una funzione ricorsiva stampa_filtro_substrR() che, ad ogni passo, determina (usando prefixR) se dal carattere corrente inizia la stringa da non stampare. 
NOTA: non potete scrivere cicli for/while.
*/

#define MAX_STR  100

int prefixR(const char seq[], const char del_seq[], int i, int j) {
    if (del_seq[j] == '\0') {
        return 1;
    }
    if (seq[i] == del_seq[j]) {
        return 1 && prefixR(seq, del_seq, i + 1, j + 1);
    }
    return 0;
}

void stampa_filtro_substrR(const char seq[], const char del_seq[], int i, int j) {
    if (seq[i] == '\0') {
        return;
    }
    if (prefixR(seq, del_seq, i, j)) {
        printf("-");
        stampa_filtro_substrR(seq, del_seq, i + strlen(del_seq), 0);
    } else {
        printf("%c", seq[i]);
        stampa_filtro_substrR(seq, del_seq, i + 1, 0);
    }
}

int main(void) {
    char seq[MAX_STR + 1];
    char del_seq[MAX_STR + 1];
    scanf("%s", seq);
    scanf("%s", del_seq);
    stampa_filtro_substrR(seq, del_seq, 0, 0);

}