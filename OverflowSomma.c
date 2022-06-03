//Creato da Alessandro Casula 11/8/2020.

/*
 * Check overflow somma fra short
 */

#include <stdio.h>
#include <stdlib.h>

short safeSum(short a, short b);

int main(){
    short somma, a, b;
    printf("Primo e secondo operando:");
    while (scanf("%hd %hd", &a, &b) != 2){
        scanf("%*[^\n]%*c");
        printf("Operandi errati!\n");
        printf("Primo e secondo operando operando?");
    }
    somma = safeSum(a, b);
    printf("La somma di %hd e %hd e\' %hd", a, b, somma);
    return 0;
}

short safeSum(short a, short b) {
    short risultato = a + b;
    if ((a > 0 && b > 0 && risultato < 0) || (a < 0 && b < 0 && risultato > 0)){
        printf("Overflow");
        exit(1);
    }
    else
        return risultato;
}
