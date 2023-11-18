#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_MAX 50

bool isPalindroma(char parola[], char parolaReversed[]){
    int ret = false;
    if(strcmp(parola, parolaReversed) == 0){
        ret = true;
    }
    return ret;
}

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
