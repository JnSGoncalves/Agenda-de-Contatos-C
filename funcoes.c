#include <stdio.h>
#include <string.h>

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}