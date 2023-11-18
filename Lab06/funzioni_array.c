#include <stdio.h>

void leggi_array(int dati[], size_t dim){
    for(int i = 0; i < dim; i++){
        scanf("%d", &dati[i]);
    }
}

int conta_univoci(const int dati[], size_t dim){
    int sum = 0;
    for(int i  = 0; i < dim; i++){
        int check = 1;
        for(int j = 0; j < dim; j++){
            //printf("Debug %d - %d | sum: %d | dati[i]: %d, dati[j]: %d\n", i, j, sum, dati[i], dati[j]);
            if(i != j && dati[i] == dati[j]){
                check = 0;
            }
        }
        if(check){
            sum+=1;
        }
    }
    return sum;
}

void stampa_elementi_ripetuti(const int fDati[], size_t fDim, const int sDati[], size_t sDim){
    for(int i = 0; i < fDim; i++){
        int check = 1;
        for(int j = 0; j < sDim; j++){
            if(fDati[i] == sDati[j]){
                check = 0;
            }
        }
        if(!check){
            printf("%d ", fDati[i]);
        }
    }
}

int main(){
    int dim1;
    int dim2;

    scanf("%d", &dim1);
    int fDati[dim1];
    leggi_array(fDati, dim1);

    scanf("%d", &dim2);
    int sDati[dim2];
    leggi_array(sDati, dim2);


    printf("%d %d\n", conta_univoci(fDati, dim1), conta_univoci(sDati, dim2));
    stampa_elementi_ripetuti(fDati, dim1, sDati, dim2);

}