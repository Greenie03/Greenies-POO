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
    printf("%d\n", taille);
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
    str[pos] = rand() % 127;
    return str;
}

char* cesar(char* str, int k){
    for(int i=0;i < strlen(str);i++){
        str[i] = ((str[i]+k-65)%26) + 65;
    }
    return str;
}