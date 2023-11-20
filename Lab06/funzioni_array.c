#include <stdio.h>

/**
 * The function `leggi_array` reads integers from the user and stores them in an array.
 * 
 * @param dati The parameter "dati" is an array of integers. It is used to store the values read from
 * the user input.
 * @param dim The parameter `dim` is of type `size_t`, which is an unsigned integer type used to
 * represent the size of an array. It specifies the number of elements in the array `dati`.
 */
void leggi_array(int dati[], size_t dim){
    for(int i = 0; i < dim; i++){
        scanf("%d", &dati[i]);
    }
}

/**
 * The function `conta_univoci` counts the number of unique elements in an array.
 * 
 * @param dati An array of integers containing the data to be checked for unique values.
 * @param dim The parameter `dim` represents the size of the array `dati[]`. It indicates the number of
 * elements in the array that need to be processed.
 * 
 * @return The function `conta_univoci` returns the number of unique elements in the array `dati`.
 */
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

/**
 * The function "stampa_elementi_ripetuti" prints the elements that are repeated in two arrays.
 * 
 * @param fDati An array of integers representing the first set of data.
 * @param fDim The size of the first array, fDati.
 * @param sDati The parameter `sDati` is an array of integers containing the second set of data.
 * @param sDim The parameter `sDim` represents the size or length of the array `sDati`.
 */
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

/**
 * The main function reads two arrays from user input, counts the number of unique elements in each
 * array, and prints the count of unique elements for each array.
 */
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