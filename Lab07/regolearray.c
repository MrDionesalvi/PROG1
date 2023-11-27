#include <stdio.h>


/**
 * The function `trasforma_array` takes an array `pA` of integers and its length `lenA`, and transforms
 * it into another array `pB` of integers with a maximum length of `nmaxB` based on certain conditions.
 * 
 * @param pA A pointer to the first element of an array of integers.
 * @param lenA The parameter `lenA` represents the length of the array `pA`. It specifies the number of
 * elements in the array `pA` that should be considered for processing.
 * @param pB pB is a pointer to an array of integers where the transformed elements will be stored.
 * @param nmaxB The parameter `nmaxB` represents the maximum size of the array `pB`. It specifies the
 * maximum number of elements that can be stored in the array `pB`.
 * 
 * @return The function `trasforma_array` returns the value of the variable `counter`, which represents
 * the number of elements that have been successfully transformed and stored in the array `pB`.
 */
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
