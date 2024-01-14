/*
Per completare una gara di slalom sciistico, uno sciatore percorre una discesa lunga c.

Lo sciatore scendendo può muoversi a destra o a sinistra. Per ciascuna unità di c, se lo sciatore scende a destra si muove orizzontalmente di a metri, mentre se scende a sinistra si muove orizzontalmente di b metri. Assumendo che lo sciatore parta orizzontalmente dalla posizione 0, deve raggiungere una posizione finale compresa nell'intervallo [d1, d2), che delimitano le porte del traguardo. Lo sciatore può cambiare direzione della discesa (destra o sinistra) per ogni unità di c.

Siano x ed y rispettivamente il numero di discese a destra e a sinistra (per unità di discesa c). Avremo quindi il sistema:

x + y = c
a*x + b*y compreso tra d1 e d2
x>=0, y>=0
Formulare il problema rispetto all'algoritmo di Euclide esteso, e scrivere un programma ricorsivo che, letto da input i 5 valori interi a, b, c, d1 e d2, stampa in output le posizioni finali intere valide e il numero x ed y di discese a destra e a sinistra.

OUTPUT: ogni linea viene formattata come "d=%d x=%d y=%d\n" indicando la posizione orizzontale raggiunta nell'intervallo della porta, ed i valori x ed y. Se ci sono più soluzioni possibili, stamparle in ordine crescente del valore d.

ESEMPIO: con a=9, b=-7, c=12 allora x=9,y=3 è una soluzione valida per d=60 ∈ [58, 83), in quanto a*x + b*y = 60 e x+y=12.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// calcola il massimo comun divisore di a e b
// assieme ai coefficienti dell'identità di Bézout x e y 
// tali che: ax+by = gcd(a,b)
int mcd_euclide_extR(int a, int b, int* pX, int* pY) {
    int x, y;
    if (b == 0) {
        x = 1;
        y = 0;
        *pX = x;
        *pY = y;
        return a;
    }
    int mcd = mcd_euclide_extR(b, a%b, &x, &y);
    *pX = y;
    *pY = x - (a/b)*y;
    return mcd;
}

void findSolution(int a, int b, int c, int *x, int *y) {
    int gcd = mcd_euclide_extR(a, b, x, y);

    if (c % gcd == 0) {
        *x *= c / gcd;
        *y *= c / gcd;
    } else {
        *x = -1;
        *y = -1;
    }
}

void slalomSolverR(int a, int b, int c, int d1, int d2, int x, int y) {
    if (x + y == c) {
        int position = a * x + b * y;
        if (position >= d1 && position < d2) {
            printf("d=%d x=%d y=%d\n", position, x, y);
        }
        return;
    }

    if (x < c) {
        slalomSolverR(a, b, c, d1, d2, x + 1, y);
    }
    if (y < c) {
        slalomSolverR(a, b, c, d1, d2, x, y + 1);
    }
}

int main() {
    int a, b, c, d1, d2;
    scanf("%d %d %d %d %d", &a, &b, &c, &d1, &d2);
    assert(a != 0 && b != 0 && c != 0 && d1 < d2);
    int x, y;
    mcd_euclide_extR(a, b, &x, &y);
    if(x != -1){
        slalomSolverR(a, b, c, d1, d2, 0, 0);
    }
    return 0;

}

