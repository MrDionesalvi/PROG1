#include <stdio.h>
#include <stdbool.h>
// Avanza la posizione del giocatore nella casella *pos
// in funzione del lancio del dado.
// Parametri:
//   dado   La quantità ottenuta dal lancio del dado (compresa tra 1 e 6)
//  *pos    La cella del giocatore che muove
// Ritorna true se il giocatore gioca ancora il prossimo turno, false altrimenti.
// Al ritorno, il valore di *pos è stato modificato aggiungendo il lancio 
// del dado, ed applicando tutte le rimanenti reole sulle scale e sulle serpi

/* Il primo giocatore che raggiunge o supera la casella 100 vince.
Le otto 🪜scale (base, cima) si trovano nelle seguenti caselle:
(1,38) (4,14) (8,30) (21,42) (28,76) (50,67) (71,92) (80,99)
mentre le sette 🐍serpi (testa, coda) si trovano nelle seguenti caselle:
(32,10) (36,6) (48,26) (62,18) (88,24) (95,56) (97,78)
*/
/**
 * The function "muovi_giocatore" moves a player on a game board based on the value of a dice roll, and
 * returns true if the dice roll is a 6.
 * 
 * @param dado An integer representing the number rolled on the dice.
 * @param pos The parameter `pos` is a pointer to an integer that represents the current position of
 * the player on the game board.
 * 
 * @return a boolean value. If the value of the variable "dado" is 6, then the function returns true
 * (1). Otherwise, it returns false (0).
 */
bool muovi_giocatore(int dado, int* pos) {
	int dimS = 8;
    int bScale[] = {1 , 4,  8,  21, 28, 50, 71, 80};
    int cScale[] = {38, 14, 30, 42, 76, 67, 92, 99};

    int dimSnake = 7;
    int tSnake[] = {32, 36, 48, 62, 88, 95, 97};
    int cSnake[] = {10,  6, 26, 18, 24, 56, 78};

    *pos += dado;

    for (size_t i = 0; i < dimS; i++){
        if (*pos == bScale[i]){
            *pos = cScale[i];
        }
    }

    for (size_t i = 0; i < dimSnake; i++){
        if(*pos == tSnake[i]){
            *pos = cSnake[i];
        }
    }
    
    int ret = 0;
    if (dado == 6){
        ret = 1;
    }
    
    return ret;
    

}

//------------------------------------------------------------------------------
// LEGGERE MA NON MODIFICARE IL CODICE SEGUENTE

// Simula il lancio di un dado a 6 facce
int lancia_dado() {
	return (rand() % 6) + 1;
}

// Realizza i turni del gioco delle scale e delle serpi
void scale_e_serpi(void) {
	int pos1 = 1, pos2 = 1; // la posizione dei due giocatori, inizialmente 1
	int turno = 1; 			// puo' valere 1 o 2

	// Esegui i turni
	while (pos1<100 && pos2<100) {
		// il giocatore lancia il dado
		int dado = lancia_dado();
		// muovi il giocatore attivo, e determina chi gioca il prossimo turno
		if (turno == 1) { 
			// muove il giocatore 1
			if (muovi_giocatore(dado, &pos1) == false)
				turno = 2; // passa il turno al giocatore 2
		}
		else { 
			// muove il giocatore 2
			if (muovi_giocatore(dado, &pos2) == false)
				turno = 1; // passa il turno al giocatore 1
		}
	}
	// Stampa il vincitore e le posizioni finali dei due giocatori
	printf("%d %d %d\n", turno, pos1, pos2);
}