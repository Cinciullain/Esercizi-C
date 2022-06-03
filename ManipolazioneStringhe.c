//Creato da Alessandro Casula 26/8/2020.

/*
 * Manipolazione di stringhe con vettori e puntatori: comparazione, copia, lunghezza
 */

#include <stdio.h>

#define LUNGHEZZA 11


int strcmp(char *s, char *t);
int strcmpPtr(char *s, char *t);
void strcopy(char *s, char *t);
void strcpyPtr1(char *s, char *t);
void strcpyPtr2(char *s, char *t);
int strleng(char *s);

int main(){
    char stringa1[LUNGHEZZA];
    char stringa2[LUNGHEZZA];
    printf("Inserisci stringa 1 di %d caratteri: \n", LUNGHEZZA - 1);
    scanf("%s", stringa1);
    printf("Inserisci stringa 2 di %d caratteri: \n", LUNGHEZZA - 1);
    scanf("%s", stringa2);

//    printf("Inserisci stringa 1 di %d caratteri: \n", LUNGHEZZA - 1);
//    while((stringa1[i++] = getchar()) != '\n' && i < LUNGHEZZA)
//        ;
//    stringa1[i] = '\n';
//
//    i = 0;
//    printf("Inserisci stringa 2 di %d caratteri: \n", LUNGHEZZA - 1);
//    while((stringa2[i++] = getchar()) != '\n' && i < LUNGHEZZA)
//        ;
//    stringa2[i] = '\n';

//    printf("Stringa 1: %s\n", stringa1);
//    printf("Stringa 2: %s\n", stringa2);

    printf("\n");
    printf("String compare: %d\n", strcmp(stringa1, stringa2));
    printf("String compare ptr: %d\n", strcmpPtr(stringa1, stringa2));
    printf("Lunghezza stringhe: %d, %d\n", strleng(stringa1), strleng(stringa2));

    strcpyPtr1(stringa1, stringa2);
    printf("Copia da una stringa all\'altra: %s\n", stringa1);

    return 0;
}

//Compara s con t, restituisce <0 se s<t, 0 se s==t, >0 se s>t
int strcmp(char *s, char *t){
    int i;
    for(i = 0; s[i] == t[i]; i++)
        if(s[i] == '\0')
            return 0;

    return s[i] - t[i];
}

//Versione string compar con i puntatori
int strcmpPtr(char *s, char *t){
    for(; *s == *t; s++, t++)
        if(*s == '\0')
            return 0;

    return *s - *t;
}

//Copia t in s, versione vettoriale
void strcopy(char *s, char *t){
    int i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

//Versione 1 strcpy con i puntatori
void strcpyPtr1(char *s, char *t){
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

//Versione 2 strcpy con i puntatori
void strcpyPtr2(char *s, char *t){
    while((*s++ = *t++) != '\0')
        ;
}

//Restituisce lunghezza stringa
int strleng(char *s){
    char *p = s;
    while(*p != '\0')
        p++;

    return p - s;
}
