#include <stdio.h>


int main(){
    /* This code is reading an integer `lenA` from the user and then creating an array `subseq` of size
    `lenA`. It then reads `lenA` integers from the user and stores them in the `subseq` array. Finally,
    it reads an integer `maxError` from the user. */
    int lenA;
    scanf("%d", &lenA);
    
    int subseq[lenA];
    int check = 1;
    
    for(size_t i = 0; i < lenA; i++){
        scanf("%d", &subseq[i]);
    }
    int maxError = 0;    
    scanf("%d", &maxError);
    
    while(check){
        int len;
        int error = 0;
        scanf("%d", &len);
        
        // Check if the value passed is 0 otherwise exit from the while loop.
        if (len != 0){
            // Create a new array of integers, the length of the array will be 'len'
            int seq[len];
            
            for(size_t i = 0; i < len; i++){
                scanf("%d", &seq[i]);
            }
            
            int start = 0;
            int end = 0;
            int resultFound = 0;
            
            /* The code snippet you provided is a nested loop that is used to find a subsequence in the
            `seq` array that matches the `subseq` array with a maximum number of errors
            (`maxError`). Here's a breakdown of what the code does: */
            for(size_t i = 0; i < len && !resultFound; i++){ 
                int a = 0;
                start = i;
                end = i;
                for(size_t j = i;error <= maxError && a < lenA;j++, end++, a++){
                    if(seq[j] != subseq[a]){
                        error++;
                    }
                }
                if (error <= maxError && start != end){
                    resultFound = 1;
                }
                else {
                    end = 0;
                    start = 0;
                    error = 0;
                }
            }
            /* This code snippet is responsible for printing the result of the subsequence search. */
            if(end != 0){
                printf("[%d, %d) errori=%d\n", start, end++, error);
            }
            else{
                printf("NO\n");
            }
        }
        else {
            check = 0;
        }
    }
}