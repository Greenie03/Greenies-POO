#include "fonctions.h"

bool palindrome(char* chaine){
    int taille = (int) strlen(chaine);
    for (int i=0; i<taille/2;i++){
        if(chaine[i] != chaine[taille-1-i]) {
            return false;
        }
    }
    return true;
}

char* cat(char* ch1, char* ch2){
    int taille  = (int) strlen(ch1) + (int) strlen(ch2) + 1;
    char* ch3 = malloc ( (taille)*sizeof(char));
    for (int i=0;i<taille;i++){
        if(i < strlen(ch1)){
            ch3[i] = ch1[i];
        }else{
            ch3[i] = ch2[i - strlen(ch1)];
        }
    }
    return ch3;
}

char* randMod(char* str){
    srand(time(NULL));
    int pos = rand() % (int) strlen(str);
    str[pos] = (rand() % 26) + 65;
    return str;
}

char* supp(char* str){
	char* str2 = malloc((strlen(str)+1)*sizeof(char));
	for (int i = 0; i < strlen(str); i++){
		if(str[i] == '#'){
			for(int j = 1; j <= i; j++){
				if(str2[i-j] != (char) 127){
					str2[i-j] = (char) 127;
					break;
				}
			}
			str2[i] = (char) 127;
		}else{
			str2[i] = str[i];
		}
	}
	str2[strlen(str)] = '\0';
	return str2;
}

char* cesar(char* str, int k){
    for(int i=0;i < strlen(str);i++){
        str[i] = ((str[i]+k-65)%26) + 65;
    }
    return str;
}

char** table_vigenere(){
	char** tV = malloc(26*sizeof(char*));
	for (int i=0; i < 26;i++){
		char* line = malloc(27*sizeof(char));
		for(int j=0; j < 26; j++){
			line[j] = (65 + (j+i) % 26);
		}
		line[26] = '\0';
		tV[i] = line;
	}
	return tV;
	
}

char* chiffrer(char* str, char** vig,char* k){
	char* str2 = malloc((strlen(str)+1)*sizeof(char));
	if(strlen(str) == strlen(k)){
		for(int i = 0; i < strlen(str); i++){
			str2[i] =(char) vig[(int) k[i] % 26][(int) str[i] % 26];
		}
		str2[strlen(str)] = '\0';
	}
	return str2;
}

char* dechiffrer(char* str, char** vig,char* k){
	char* str2 = malloc((strlen(str)+1)*sizeof(char));
	if(strlen(str) == strlen(k)){
		for(int i = 0; i < strlen(str); i++){
			str2[i] =(char) vig[((k[i] % 26) - 26) * -1][str[i] % 26];
		}
		str2[strlen(str)] = '\0';
	}
	return str2;
}

char** chiffrement(){
	srand(time(NULL));
	char** tV = malloc(26*sizeof(char*));
	for (int i=0; i < 26;i++){
		char* line = malloc(27*sizeof(char));
		int r = rand() % 26;
		for(int j=0; j < 26; j++){
			line[j] = (65 + (j+r) % 26);
		}
		line[26] = '\0';
		tV[i] = line;
	}
	return tV;
	
}
