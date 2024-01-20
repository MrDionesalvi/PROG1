#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define NUM_PERS 24

// I nomi dei soggetti fermati
const char* nomi[NUM_PERS] = {
    "Claire","Eric",   "Maria", "George","Bernard","Sam",    "Tom",    "Paul",
    "Joe",   "Frans",  "Anne",  "Max",   "Alex",   "Philip", "Bill",   "Anita",  
    "David", "Charles","Herman","Peter", "Susan",  "Robert", "Richard","Alfred", 
};

// Gli attributi dei soggetti fermati, codificati come stringa
const char* attributi[NUM_PERS] = {
    "drco", "bc",   "dtc", "wc",   "tcg",  "wpo",  "npzo", "wo",  
    "bo",   "r",    "dn",  "nfsg", "nfs",  "nal",  "rpal", "dblz", 
    "ba",   "bfs",  "rpg", "wszg", "dwls", "tlzg", "tpfa", "rfz", 
};

bool carattereContenuto(char car, const char stringa[]){
    bool ret = false;
    for(int i = 0; stringa[i] != '\0' && !ret; i++){
        if(tolower(car) == stringa[i])
            ret = true;
    } 
    return ret;
}

int main(void) {
	char carr[15];
    int counter = 0;
	
	
	scanf("%s", carr);
	
	for(int i = 0; i < NUM_PERS; i++){
        int lowerCheck = true;
        int upperCheck = true;
        for(int j = 0; carr[j] != '\0' && lowerCheck && upperCheck; j++){
            bool result = carattereContenuto(carr[j], attributi[i]);
            if(islower(carr[j])){
                if(!result)
                    lowerCheck = false;
            }
            else if(isupper(carr[j])){
                if(result)
                    upperCheck = false;
            }
        }
        if(lowerCheck && upperCheck){
            printf("%s\n", nomi[i]);
            counter++;
        }
    }
    printf("%d", counter);
}
