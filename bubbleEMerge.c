//Creato da Alessandro Casula 11/8/2020.

/*
 * Sorting array in bubble sort e merge sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 6

void bubbleSort(int[], size_t, char);
void mergeSort(int[], size_t, char);
void merge(int[], size_t, size_t, size_t, size_t, char);
void sort(int[], size_t, size_t, char);

int main(){
    int array[DIM];
    short i;

    for(i = 0; i < DIM; i++)
        array[i] = rand() % (DIM * 10) ;

    char ordine;
    printf("Ordinamento crescente (C) o decrescente (ogni altro carattere)");
    scanf("%c", &ordine);
    printf("Prima dell'ordinamento\n");
    for (i = 0; i < DIM; i++)
        printf("%d " , array[i]);

    char metodo;
    scanf("%*c");
    printf("\nMetodo Bubble (B), Merge (ogni altro carattere)");
    scanf("%c", &metodo);
    clock_t c1, c2;
    switch(metodo){
        case 'B':
            c1 = clock();
            bubbleSort(array, DIM, ordine);
            c2 = clock();
            printf("\nTempo di ordinamento Bubble Sort %.10f\n", (double) (c2-c1)/CLOCKS_PER_SEC);
            break;
        default:
            c1 = clock();
            mergeSort(array, DIM, ordine);
            c2 = clock();
            printf("Tempo di ordinamento Merge Sort %.10f\n", (double) (c2-c1)/CLOCKS_PER_SEC);
            break;
    }

    printf("Dopo l'ordinamento\n");
    for(i = 0; i < DIM; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void bubbleSort(int array[], size_t dim, char verso) {
    int tmp;
    for(int passate = 0; passate < dim; passate++){
        for(int i =0; i < (dim - 1); i++){
            switch(verso){
                case 'C':
                    if(array[i] > array[i+1]){
                        tmp = array[i];
                        array[i] = array[i+1];
                        array[i+1] = tmp;
                    }
                    break;
                default:
                    if(array[i] < array[i+1]){
                        tmp = array[i];
                        array[i] = array[i+1];
                        array[i+1] = tmp;
                    }
                    break;
            }
        }
    }
}

void mergeSort(int array[], size_t dim, char verso) {
    sort(array, 0, dim-1, verso);
}

void merge(int array[], size_t sx, size_t centro1, size_t centro2, size_t dx, char order) {
    size_t sx_i = sx;
    size_t dx_i = centro2;
    size_t fondi_i = sx;
    static int temp_a[DIM];
    while(sx_i <= centro1 && dx_i <= dx){
        //Inserisce nell'array finale l'elemento corretto in base all'ordinamento scelto
        switch(order){
            case 'I':
                if(array[sx_i] <= array[dx_i])
                    temp_a[fondi_i++] = array[sx_i++];
                else
                    temp_a[fondi_i++] = array[dx_i++];
                break;
            default:
                if (array[sx_i] <= array[dx_i])
                    temp_a[fondi_i++] = array[dx_i++];
                else
                    temp_a[fondi_i++] = array[sx_i++];
                break;
        }
    }
    //Se esaurisco il sotto-array sinistro
    if(sx_i == centro2)
        while(dx_i <= dx)
            temp_a[fondi_i++] = array[dx_i++];
    else
        //Ho esaurito il sotto-array destro
        while(sx_i <= centro1)
            temp_a[fondi_i++] = array[sx_i++];
    //Copio l'array temporaneo in quello originale
    for(size_t i = sx; i <= dx; i++)
        array[i] = temp_a[i];
}

void sort(int array[], size_t inizio, size_t fine, char verso) {
    if((fine - inizio) >= 1){
        //Non è il caso base
        size_t centro1 = (inizio + fine) / 2;
        size_t centro2 = centro1 + 1;
        //Divide l'array e ordina i due sotto-array ricorsivamente
        sort(array, inizio, centro1, verso);
        sort(array, centro2, fine, verso);
        //Fonde i due sotto-array ordinati
        merge(array, inizio, centro1, centro2, fine, verso);
    }
    //Non ho bisogno di else, perché in tal caso lárray é di 1 elemento, ovvero giá ordinato
}