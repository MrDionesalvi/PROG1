/*
Scrivere un programma che legge in input una matrice 3x3 di caratteri. I caratteri possibili sono tre: 'X', 'O' e '-', che rappresentano rispettivamente i simboli dei due giocatori, e la casella vuota. La matrice 3x3 rappresenta la griglia del gioco del tris. Un giocatore vince il gioco del tris se occupa una riga, una colonna o una delle due diagonali con il proprio simbolo.
Il programma deve:
stampare 'X' se nella griglia in input vince il giocatore 'X';
stampare 'O' se nella griglia in input vince il giocatore 'O';
stampare '-' se non vince ne 'X' ne 'O'.
È garantito che la griglia in input abbia al massimo un giocatore che vince.
SUGGERIMENTO: leggere i caratteri che formano la griglia di gioco 3x3 usando scanf con stringa di formato " %c" (spazio seguito da %c). Questa stringa di formato viene interpretato da scanf come: prima scarta tutti gli spazi e poi leggi il prossimo carattere (diverso da uno spazio).
*/

#include <stdio.h>
#include <stdbool.h>


char winner(size_t len, char board[len][len]);

int main(){
    int len = 3;
    char matrice[len][len];

    for (size_t i = 0; i < len; i++){
        for (size_t j = 0; j < len; j++){
            scanf(" %c", &matrice[i][j]);
        }
    }
    
    printf("%c\n", winner(len, matrice));

}

/**
 * The function "winner" checks for a winner in a tic-tac-toe board by examining the rows, columns, and
 * diagonals.
 * 
 * @param len The parameter `len` represents the size of the board. It is of type `size_t`, which is an
 * unsigned integer type used for representing sizes and counts. In this case, it represents the number
 * of rows and columns in the `board` array.
 * @param board The `board` parameter is a 2-dimensional array of characters representing a tic-tac-toe
 * board. The size of the board is `len` by `len`, where `len` is the number of rows and columns in the
 * board. Each element of the array represents a cell on the
 * 
 * @return the character that represents the winner of the game. If there is no winner, the function
 * returns '-' indicating a tie or an ongoing game.
 */
char winner(size_t len, char board[len][len]){
    char ret = '-';

    // Controllo righe orizzontali
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2]){
        ret = board[0][0];
    }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]){
        ret = board[1][0];
    }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]){
        ret = board[2][0];
    }
    // Controllo colonne verticali
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]){
        ret = board[0][0];
    }
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]){
        ret = board[0][1];
    }
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]){
        ret = board[0][2];
    }
    // Controllo diagonale superiore e inferiore
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        ret = board[0][0];
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        ret = board[0][2];
    }
    return ret;
}