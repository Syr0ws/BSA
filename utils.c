#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

unsigned int input_number(char* message) {

    unsigned int number;

    printf("%s\n", message);

    scanf("%u", &number);
    clear_input();

    return number;
}

void clear_input() {

    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

// Ce code ne nous appartient pas et a été repris d'une solution
// stackoverflow : https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
char* input_string(size_t size){

    char *str;
    int ch;
    size_t len = 0;

    str = realloc(NULL, sizeof(*str) * size);
    
    if(!str) return str;

    while(EOF != (ch=fgetc(stdin)) && ch != '\n') {

        str[len++]=ch;

        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str) return str;
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(*str)*len);
}