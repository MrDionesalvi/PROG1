#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) {
    bool ret = true;
    int max = INT_MIN;
    for(size_t i = 0; i < rows; i++){
        int sum = 0;
        for(size_t j = 0; j < rags[i]; j++){
            sum += mat[i][j];
        }
        if(sum % k == 0 && sum > max && sum != 0){
            max = sum;
        }
        else if (sum % k != 0){
            ret = false;
        }
    }
    if(max != INT_MIN)
        *pMaxSum = max;
    if(rows == 1 && rags[0] == 0){
        ret = false;
    }
    return ret;
}