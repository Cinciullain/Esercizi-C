//Creato da Alessandro Casula 8/8/2020.

/*
 * Torre di Hanoi ricorsiva con libreria time.h per contare tempo di esecuzione
 */

#include <stdio.h>
#include <time.h>

void mossa(int, int, int, int);

int main(){
    int n;
    printf("Numero di dischi? \n");
    while (scanf("%d", &n) != 1 || n < 0) {
        scanf("%*[^\n]%*c");
        printf("Numero errato!\n");
        printf("Numero di dischi? \n");
    }
    clock_t clock1, clock2;
    time_t sec1, sec2;
    sec1 = time(NULL);
    clock1 = clock();
    mossa(n, 1, 2, 3);
    sec2 = time(NULL);
    clock2 = clock();
    printf("Tempo di esecuzione %f\n", (double) sec2 - sec1);
    printf("Tempo di esecuzione %f\n", (double) (clock2-clock1)/CLOCKS_PER_SEC);
}

void mossa(int n, int si, int ce, int dx){
    //Caso base
    if(n == 1)
        printf("%d -> %d\n", si, dx);
        //Passo ricorsivo
    else{
        mossa(n-1, si, dx, ce);
        printf("%d -> %d\n", si, dx);
        mossa(n-1, ce, si, dx);
    }
}

