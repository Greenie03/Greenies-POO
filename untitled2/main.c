#include <stdio.h>
#include "fonctions.h"

int main() {
    bool pal = palindrome("kayak");
    printf(pal ? "true\n" : "false\n");
    char* string = cat("HELLO","WORLDZ");
    printf("%s\n",string);
    randMod(string);
    printf("%s\n",string);
    cesar(string,6);
    printf("%s\n",string);
    free(string);
    char** vigenere = table_vigenere();
/*    for (int i=0;i<26;i++){
    	for(int j=0;j<26;j++){
    		printf("%c", vigenere[i][j]);
    	}
    	puts("\n");
    }*/
    char* string2 = cat("IMTHEOPERATORWITH","MYPOCKETCALCULATOR");
    char* key = "KRAFTWERKKRAFTWERKKRAFTWERKKRAFTWER";
    char* encoded = chiffrer(string2,vigenere,key);
    printf("chiffré : %s\n", encoded);
    char* t = "#a#bc#d";
    char* t1 = supp(t);
    printf("test 1 : %s\n", t1);
    char* nStr = dechiffrer(encoded,vigenere,key);
    printf("déchiffré : %s\n", nStr);
    char** chiff = chiffrement();
    for (int i=0;i<26;i++){
    	for(int j=0;j<26;j++){
    		printf("%c", chiff[i][j]);
    	}
    	puts("\n");
    }
    for (int i=0;i<26;i++){
    	free(vigenere[i]);
    }
        for (int i=0;i<26;i++){
    	free(chiff[i]);
    }
    free(chiff);
    free(nStr);
    free(t1);
    free(string2);
    free(vigenere);
    free(encoded);
    return EXIT_SUCCESS;
}
