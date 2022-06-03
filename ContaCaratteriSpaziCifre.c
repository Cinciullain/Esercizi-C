//Creato da Alessandro Casula 4/8/2020.

/*
 * Conta le cifre, spazi e caratteri del testo in ingresso
 */

#include <stdio.h>

int main() {
    int inputTastiera, i;
    int numeroSpazi = 0;
    int numeroCaratteri = 0;
    int numeroCifre[10];

    //Inizializzazione array
    for(i = 0; i < 10; i++)
        numeroCifre[i] = 0;

    //Input da statiera
    while((inputTastiera = getchar()) != EOF && inputTastiera != '\n'){
        if(inputTastiera >= '0' && inputTastiera <= '9')
            numeroCifre[inputTastiera - '0']++;
        else if(inputTastiera == ' ' || inputTastiera == '\t')
            numeroSpazi++;
        else
            numeroCaratteri++;
    }

    printf("Cifre: ");
    for(i = 0; i < 10; i++)
        printf("%d: %d\t", i, numeroCifre[i]);

    printf("\nSpazi: %d\nCaratteri: %d", numeroSpazi, numeroCaratteri);

    return 0;
}
