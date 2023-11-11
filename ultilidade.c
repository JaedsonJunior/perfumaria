#include <stdio.h>

void limparBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    }
