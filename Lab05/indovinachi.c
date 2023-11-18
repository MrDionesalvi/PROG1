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

int main(void) {
	char carr[15];
	
	
	scanf("%s", carr);
	
	for(int i = 0; i <sizeof(carr) && carr[i] != '\0'; i++){
		if(isalpha(carr[i]) && isupper(carr[i])){ 
			for(int j = 0; j < NUM_PERS; j++){ 
				for(int k = 0; k < sizeof(attributi[j]) && attributi[j][k] != '\0'; k++){
					if(toupper(attributi[j][k]) == carr[i]){
						nomi[j] = "0";
					}
				}
			}
		}
		else if(isalpha(carr[i]) && islower(carr[i])){
			for(int j = 0; j < NUM_PERS; j++){
				int flag = 0;
				for(int k = 0; k < sizeof(attributi[j]) && attributi[j][k] != '\0'; k++){
					if(tolower((attributi[j][k])) == carr[i])
						flag = 1;
				}
				if(!flag)
					nomi[j] = "0";
			}
		}
	}
	
	int result = 0;
	for(int i = 0; i < 24; i++){
	   if(*nomi[i] != '0'){
	        printf("%s\n", nomi[i]); 
	        result += 1;	       
	   }
    }
    printf("%d",result);
    
    
	    
}
