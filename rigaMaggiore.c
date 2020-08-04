//Creato da Alessandro Casula 4/8/2020.

/*
 * Trova e visualizza la riga piu' lunga tra quelle inserite, utilizzando gli array
 */

#include <stdio.h>
#define MAXLINE 1001

int getRiga(char[], int);
void copy(char[], char[]);

int main() {
    int lunghezzaCorrente; //Lunghezza riga corrente
    int lunghezzaMassima; //Lunghhezza massima riscontrata
    char line[MAXLINE]; //Riga corrente
    char longest[MAXLINE]; //Contiene la riga piu' lunga

    lunghezzaMassima = 0;
    while((lunghezzaCorrente = getRiga(line, MAXLINE)) > 2){
        if(lunghezzaCorrente > lunghezzaMassima){
            lunghezzaMassima = lunghezzaCorrente;
            copy(longest, line);
        }
    }

    if(lunghezzaMassima > 0) {
        int i = 0;
        while(longest[i + 1] != '\0') {
            printf("%c", longest[i]);
            i++;
        }
    }
    return 0;
}

int getRiga(char stringa[], int lim){
    int carattere, i;

    for(i = 0; i < lim - 1 && (carattere = getchar()) != EOF && carattere != '\n'; i++)
        stringa[i] = carattere;

    if(carattere == '\n'){
        stringa[i] = carattere;
        i++;
    }
    stringa[i] = '\0';
    return i;

}

void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\n')
        i++;
}