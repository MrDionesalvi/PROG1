#include <stdio.h>


int main(){
    int lenA;
    scanf("%d", &lenA);
    
    int subseq[lenA];
    int zero = 1;
    
    for(size_t i = 0; i < lenA; i++){
        scanf("%d", &subseq[i]);
    }
    int maxE = 0;    
    scanf("%d", &maxE);
    
    while(zero){
        int len;
        int error = 0;
        
        scanf("%d", &len);
        if (len != 0){
            int seq[len];
            
            for(size_t i = 0; i < len; i++){
                scanf("%d", &seq[i]);
            }
            
            int start = 0;
            int end = 0;
            
            int err  = 0;
            for(size_t i = 0; i < len; i++){ //
                int a = 0;
                start = i;
                end = i;
                for(size_t j = i; i < (len) && err <= maxE && a < lenA;j++){
                    //printf("%ld %ld %d\n", i, j, a);
                    if(seq[j] == subseq[a]){
                        end++;
                    }
                    else{
                        err++;
                        end++;
                    }
                    a++;
                }
                if (err <= maxE && start != end){
                    i = len;
                    error = err;
                }
                else {
                    end = 0;
                    start = 0;
                    err = 0;
                }
            }
            if(end != 0){
                printf("[%d, %d) errori=%d\n", start, end++, error);
            }
            else{
                printf("NO\n");
            }
        }
        else {
            zero = 0;
        }
    }
}