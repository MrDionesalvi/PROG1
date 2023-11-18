#include <stdio.h>

// copia in pB (dimensione massima nmaxB) tutti gli elementi 
// dell'array pA (dimensione lenA) seguendo le regole.
// ritorna il numero di elementi copiati
size_t trasforma_array(const int* pA, const size_t lenA,
					   int *pB, const size_t nmaxB){
    
    size_t startpB = 0;
    size_t counter = 0;
    
    for(size_t i = 0; i < lenA && counter < nmaxB; i++){
        if (pA[i] >= 10){
            if (pA[i] % 2 == 0 && pA[i] % 4 == 0){
                size_t limit = startpB + 4;
                for(size_t j = startpB; j < limit && startpB < nmaxB && counter < nmaxB; startpB++, j++){
                    pB[startpB] = pA[i];
                    counter++;
                }
            }
            else if (pA[i] % 2 == 0 && pA[i] % 4 != 0){
                size_t limit = startpB + 2;
                for(size_t j = startpB; j < limit && startpB < nmaxB && counter < nmaxB; startpB++, j++){
                    pB[startpB] = pA[i];
                    counter++;
                }
            }
            else if (!(pA[i] % 2 != 0 && pA[i] % 3 == 0)){
                if (startpB != 0 && startpB != nmaxB){
                    pB[startpB] = pA[i];
                    startpB += 1;
                }
                else {
                    pB[startpB] = pA[i];
                    startpB += 1;
                }
                counter += 1;
            }
        }
    }
    return counter;
}

//------------------------------------------------------------------
// stampa gli elementi dell'array *pA (di dimensione lenA)
void stampa_array(const int* pA, const size_t lenA) 
{
	printf("len=%zu: [ ", lenA);
	for (size_t i=0; i<lenA; i++) {
		printf("%d ", pA[i]);
	}
	printf("]\n");
}

//------------------------------------------------------------------
// leggi da standard input un array, riempi il buffer pA 
// e ritorna il numero di elementi inseriti nel buffer
size_t leggi_array(int* pA, const size_t nmaxA) 
{
	size_t n, lenA=0;
	scanf("%zu", &n); // numero di elementi da leggere
	for (size_t i=0; i<n; i++) {
		int elem;
		scanf("%d", &elem);
		if (lenA < nmaxA) {
			pA[lenA] = elem;
			lenA++;
		}
	}
	return lenA;
}

//------------------------------------------------------------------
#define NMAX  10
int main(void) {
    int A[NMAX], B[NMAX]; 
    size_t nA = leggi_array(A, NMAX); 
    size_t nB = trasforma_array(A, nA, B, NMAX); 
    stampa_array(B, nB);
}

//------------------------------------------------------------------
