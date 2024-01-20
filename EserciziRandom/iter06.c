#include <stdio.h>
#include <stdbool.h>

bool esisteEl(int arr[], const size_t cols, int element){
    bool ret = false;
    for(int i = 0; i < cols && !ret; i++){
        if(arr[i] == element)
            ret = true;
    }
    return ret;
}

void rimuoviElemento(int arr[], size_t cols, int start){
    for(int i = start; i < cols-1; i++){
        arr[i] = arr[i+1];
    }
}

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) {
    bool ret = false;
    for(int i = 1; i < rows; i++){
        for(int j = 0; j < rags[i]; j++){
            if(esisteEl(mat[i-1],rags[i-1], mat[i][j])){
                rimuoviElemento(mat[i], rags[i], j);
                rags[i]--;
                j--;
                ret = true;
            }
        }
    }
    return ret;
}