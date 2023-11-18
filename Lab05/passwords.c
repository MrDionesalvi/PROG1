/*
Scrivere un programma C che legge dallo standard input una stringa (con massimo 20 caratteri).
In seguito il programma determina delle proprietà e stampa un sommario finale.
Le proprietà da determinare sono:

P1:  esiste almeno un carattere che è una cifra;
P2:  tutte i caratteri sono lettere;
P3:  ci sono almeno due lettere maiuscole;
P4:  ci sono almeno due cifre consecutive;
P5:  gli ultimi due caratteri sono segni di punteggiatura.
Il sommario stampato deve avere forma:

<password>  P1 P2 P3 P4 P5

dove P1..P5 sono valori 1 (se la corrispondente proprietà é soddisfatta) oppure 0.



For example:

Input	
pippo12345!

Result
pippo12345! 1 0 0 1 0

*/
#include <stdio.h>
#include <ctype.h>


int main(){
    char password[20];
    scanf("%s", password);
    
    int P1 = 0;
    int P2 = 1;
    int P3 = 0;
    int P4 = 0;
    int P5 = 0;
    
    int upper = 0;
    
    for(int i = 0; i < sizeof(password); i++){
        if(password[i] == '\0'){
            //printf("%d, %c %c ||", i, password[i-2], password[i-1]);
            if(ispunct(password[i-1]) && ispunct(password[i-2])){
                P5 = 1;
            }
            i = sizeof(password);
        }
        else{
            //printf("%c\n", password[i]);
            if(isdigit(password[i])){
                P1 = 1;
                P2 = 0;
                if(i != 0 && (isdigit(password[i-1]) || isdigit(password[i+1]))){
                    P4 = 1;
                }
            }
            if(isupper(password[i])){
               upper += 1; 
            }
            if(ispunct(password[i]))
                P2 = 0;
            if(i == 19){
                if(ispunct(password[i]) && ispunct(password[i-1])){
                    P5 = 1;
                }
            }
        }
    }
    
    if(upper >= 2)
        P3 = 1;
    printf("%s %d %d %d %d %d", password, P1, P2, P3, P4, P5);
    
    
    return 0;
}