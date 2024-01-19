#include <stdio.h>
#include <stdbool.h>


int ricerca_binaria(const int a[], const int val,
                const size_t left, const size_t right) {
    int ret = -1;
    if (left+1==right || left >= right) {
        if (a[left]==val) {
            ret = left;
        }
        return ret;
    }
    else {
        int middle = (left+right)/2; 
        if(val < a[middle]) {
            ret = ricerca_binaria(a, val, left, middle); 
        }
        else { //key >= a[middle]
            ret = ricerca_binaria(a, val, middle, right);
        }       
    }
return ret;
}


bool trova_coppia(const int a[], const int somma_target,
             const size_t left, const size_t right,
             size_t *pIndice1, size_t *pIndice2){
    bool result = false;
    if(left+1==right){
        return result;
    }
    else{
        int target = somma_target - a[left];
        int elementFind = ricerca_binaria(a, target, left, right);
        if(elementFind != -1){
            *pIndice1 = left;
            *pIndice2 = elementFind;
            result = true;
        }
        else{
            return trova_coppia(a, somma_target, left+1, right, pIndice1, pIndice2);
        }
    }
    return result;

}