#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * The function checks if a given character is a vowel.
 * 
 * @param ch The parameter `ch` is a character that we want to check if it is a vowel or not.
 * 
 * @return The function is_vowel is returning a boolean value indicating whether the given character is
 * a vowel or not.
 */
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
    
    /* The code snippet is iterating over each character in the string `parola` and checking if the
    character is a vowel or not using the `is_vowel` function. If the character is not a vowel, it
    is added to the string `prl` at the current index `startPrl` and `startPrl` is incremented. This
    effectively removes all the vowels from the string `parola` and stores the result in the string
    `prl`. */
    for(size_t i = 0; i < strlen(parola); i++){
        if(!is_vowel(parola[i])){
            prl[startPrl] = parola[i];
            startPrl++;
        }
    }
    prl[startPrl] = '\0';
    
    printf("%s", prl);
    
}
