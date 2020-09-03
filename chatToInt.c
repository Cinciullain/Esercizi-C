//Creato da Alessandro Casula 3/9/2020.

/*
 * Converte char in int
 */

#include <stdio.h>

int main() {
    int input;
    char stringa[3];
    int numero = 0, i = 0;

    while ((input = getchar()) != '\n' && input != EOF){
        stringa[i] = input;
        i++;
    }

    for(i = 0; i < 3; i++){
        numero += stringa[i] - '0';
        if(i < 2)
            numero = numero * 10;
    }

    printf("%d", numero);
    return 0;
}