#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_MAX 50

/**
 * The function checks if a given word is a palindrome by comparing it with its reversed version.
 * 
 * @param parola The parameter "parola" is a character array that represents a word.
 * @param parolaReversed The parameter "parolaReversed" is a character array that represents a reversed
 * version of a word or phrase.
 * 
 * @return a boolean value.
 */
bool isPalindroma(char parola[], char parolaReversed[]){
    int ret = false;
    if(strcmp(parola, parolaReversed) == 0){
        ret = true;
    }
    return ret;
}

/**
 * The above function takes a word as input, reverses it, and checks if it is a palindrome.
 */
int main(void) {
    char parola[WORD_MAX];
    char parolaReversed[WORD_MAX];

    scanf("%s", parola);

    int j = strlen(parola) - 1;
    for(int i = 0; i < strlen(parola); i++, j--){
        parolaReversed[j] = parola[i];
    }
    parolaReversed[strlen(parola)] = '\0';

    if (isPalindroma(parola, parolaReversed)){
        printf("PALINDROMA");
    }
    else {
        printf("%s %s", parola, parolaReversed);
    }

}
