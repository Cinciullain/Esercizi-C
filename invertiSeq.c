//Creato da Alessandro Casula 6/8/2020.

/*
 * Inverte una frase
 */

#include <stdio.h>

void invertiSeq(void);

int main() {
    printf("Inserisci seq da invertire: \n");
    invertiSeq();
    return 0;
}

void invertiSeq(void){
    int c;
    c = getchar();
    if(c == '\n'){
        printf("La seq inversa e\': ");
        return;
    }
    invertiSeq();
    putchar(c);
    return;
}

