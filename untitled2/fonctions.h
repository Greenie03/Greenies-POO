#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#ifndef FONCTIONS_H
#define FONCTIONS_H

bool palindrome(char* chaine);
char* cat(char* ch1, char* ch2);
char* randMod(char* str);
char* supp(char* str);
char* cesar(char* str, int k);
char** table_vigenere();
char* chiffrer(char* str, char** vig,char* k);
char* dechiffrer(char* str, char** vig,char* k);
char** chiffrement();

#endif
