//Creato da Alessandro Casula 5/8/2020.

/*
 * Trova tutte le righe che contengono la stringa pattern
 */

#include <stdio.h>
#define MAXLINE 1000

int getLine(char[], int);
int strIndex(char[], char[]);

char pattern[] = "ffjd"; //Pattern da trovare

int main() {
    char line[MAXLINE];
    int trovato = 0;

    while(getLine(line, MAXLINE) > 0){
        if(strIndex(line, pattern) >= 0){
            printf("%s\n", line);
            trovato++;
        }
    }

    printf("Pattern trovato %d volte", trovato);

    return 0;
}

//Legge una riga e ne restituise la lunghezza
int getLine(char s[], int lim){
    int c, i;

    i = 0;
    while(lim - 1 > 0 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }

    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

//Restituisce l'indice di t in s
int strIndex(char s[], char t[]){
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
