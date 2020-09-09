//Creato da Alessandro Casula 8/8/2020.

/*
 * Propagazione malattia infettiva seguendo l'eq base https://imgur.com/a/hP6VADr
 */

#include <stdio.h>

float infetti(int t, float rm, unsigned int p);
/*
void inputFloat(float *n);
void inputInt(int *n);
*/

int main(){
    float rateoMutazione;
    unsigned int popolazione;
    int tempo = 0;

    printf("Costante mutazione:");
    while(scanf("%f", &rateoMutazione) != 1 || rateoMutazione <= 0){
        scanf("%*[^\n]%*c");
        printf("Inserisci float positivo");
    }

    printf("Popolazione:");
    while(scanf("%d", &popolazione) != 1){
        scanf("%*[^\n]%*c");
        printf("Inserisci intero");
    }

    printf("Tempo:");
    while(scanf("%d", &tempo) != 1 || tempo < 0){
        scanf("%*[^\n]%*c");
        printf("Inserisci intero positivo");
    }

    printf("Al tempo %d gli infetti sono %d", tempo,
           (int)infetti(tempo, rateoMutazione, popolazione));
    return 0;
}

float infetti(int t, float rm, unsigned int p){
    float tmp;
    if(t == 0)
        return 1;
    else{
        tmp = infetti(t - 1, rm, p);
        tmp = tmp * (1 + rm * p) - rm * tmp * tmp;
        if(tmp > p)
            return p;
        else
            return tmp;
    }
}

/* TODO Utilizzare i puntatori per prendere input dall'utente
 * void inputFloat(float *n){
    float num;
    while (scanf("%f", &num) != 1 || num < 0) {
        scanf("%*[^\n]%*c");
        printf("Inserisci un reale positivo: ");
    }
    printf("%1.4f\n", num);
    n = &num;
}

void inputInt(int *n){
    int num;
    while (scanf("%d", &num) != 1 || num < 0) {
        scanf("%*[^\n]%*c");
        printf("Inserisci un intero positivo: ");
    }
    n = &num;
}*/


