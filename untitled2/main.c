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
    return EXIT_SUCCESS;
}
