#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/*
e1 	riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, un intero k, ed un puntatore ad interi pMaxSum
e1 	restituisce true se in tutte le righe di lunghezza non zero la somma degli elementi della riga è multiplo di k, e se almeno una riga con tale proprietà sulla somma esiste. 
	In tale caso, il massimo di tutte le somme deve essere scritto nell'intero puntato da pMaxSum. 
	In ogni altro caso e1 restituisce false.
*/

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) {
	bool ret = true;
	bool allCheck = true;
	int maxSum = INT_MIN;
    for (size_t i = 0; i < rows && allCheck; i++){
		int sum = 0;
		for (size_t j = 0; j < rags[i]; j++){
			sum += mat[i][j];
		}
		if(sum % k == 0){
			if(sum > maxSum){
				maxSum = sum;
			}
		}
		else {
		    allCheck = false;
			ret = false;
		}
	}
	if(rows == 1 && rags[0] == 0){
		ret = true;
		maxSum = INT_MIN;
	}
	*pMaxSum = maxSum;
	return ret;
	
}