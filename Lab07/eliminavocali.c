#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// ritorna true se il carattere ch è una vocale
bool is_vowel(char ch) {
#   define NUM_VOWELS 10
    const char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    bool is_v = false;
    for (size_t i=0; i<NUM_VOWELS && !is_v; i++) {
        if (ch == vowels[i])
            is_v = true;
    }
    return is_v;
}


int main(void) {
    int max = 50;
    char parola[max];
    
    char prl[max]; // Parola senza vocali :D
    size_t startPrl = 0;

    scanf("%s", parola);
    
    for(size_t i = 0; i < strlen(parola); i++){
        if(!is_vowel(parola[i])){
            prl[startPrl] = parola[i];
            startPrl++;
        }
    }
    prl[startPrl] = '\0';
    
    printf("%s", prl);
    
}
