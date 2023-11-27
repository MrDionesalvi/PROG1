#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows]) {
    int ret = 0;
    int allCheck = 1;
    for (size_t i = 0; i < rows && allCheck; i++){
        int currentRow = 1;
        for (size_t j = 0; j < rags[i] && currentRow; j++){
            if(rags[i] < rows){
                allCheck = 0;
            }
            if((mat[i][j] % 7 == 0) && allCheck){
                ret += mat[i][j];
                currentRow = 0;
            }
        }
        
    }
    if(!allCheck){
        ret = 0;
    }
    return ret;
    
}