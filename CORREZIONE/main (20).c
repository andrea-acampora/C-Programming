/*
 * ESERCIZIO 1 SETTIMANA 1
 * Scrivere un programma C che dichiari una variabile per ogni tipo studiato
 * (usando anche i qualificatori short, long, signed e unsigned), ne stampi il valore
 * e l’occupazione di memoria in byte.
 * Utilizzare TUTTI gli argomenti della funzione printf() studiati e TUTTE le diverse varianti:
 * (modificatore, campoMinimo, precisione, modificatoreLunghezza).
 * Per la prima chiamata alla funzione printf(), mostrare a video anche il numero di caratteri che quest’ultima ha stampato
 * (Aiuto: la funzione printf() restituisce un valore).
 * Stampare inoltre il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
int main()
{
    int nInt = 1, nCaratteriPrintf;
    short int nShortInt = 11;
    long int nLongInt = 125;
    unsigned int nUnsInt = 13;
    unsigned short int nUnsShortInt = 65;
    unsigned long int nUnsLongInt = 145;
    char letteraChar = 'a';
    signed char letteraSigChar = 'A';
    unsigned char letteraUnsChar = 'T';
    float nFloat = 10.550;
    double nDouble = 52.16;
    long double nLongDouble = 5.15;
    //char parola[20] = "Ciao!";
    printf("Sezione numeri interi:\n");
    nCaratteriPrintf = printf("Lunghezza del valore int %5d e': %d byte\t Lunghezza minima %d\t Lunghezza massima %d\n", nInt, sizeof(nInt), INT_MIN, INT_MAX);
    printf("Lunghezza in byte della prima printf(): %d\n", nCaratteriPrintf); //stampa la lunghezza in byte del primo printf();
    printf("Lunghezza del valore short int %5d e': %d byte\t Lunghezza minima %d\t Lunghezza massima %d\n", nShortInt, sizeof(nShortInt),SHRT_MIN, SHRT_MAX);
    printf("Lunghezza del valore long int %ld e': %d byte\t Lunghezza minima %ld\t Lunghezza massima %ld\n", nLongInt, sizeof(nLongInt), LONG_MIN, LONG_MAX);
    printf("Lunghezza del valore unsigned int %d e': %d byte\t Lunghezza minima %d\t Lunghezza massima %u\n", nUnsInt, sizeof(nUnsInt), 0, UINT_MAX);
    printf("Lunghezza del valore unsigned short int %d e': %d byte\t Lunghezza minima %d\t Lunghezza massima %d\n", nUnsShortInt, sizeof(nUnsShortInt), 0, USHRT_MAX);
    printf("Lunghezza del valore unsigned long int %lu e': %d byte\t Lunghezza minima %d\t Lunghezza massima %lu\n\n", nUnsLongInt, sizeof(nUnsLongInt), 0, ULONG_MAX);

    printf("Sezione caratteri:\n");
    printf("Lunghezza del valore char '%c' e': %d byte\t Lunghezza minima %d\t Lunghezza massima %d\n", letteraChar, sizeof(letteraChar), CHAR_MIN, CHAR_MAX);
    printf("Lunghezza del valore signed char '%c' e': %d byte\t Lunghezza minima %d\t Lunghezza massima %d\n", letteraSigChar, sizeof(letteraSigChar), SCHAR_MIN, SCHAR_MAX);
    printf("Lunghezza del valore unsigned char %c e': %d byte\t Lunghezza minima %d\t Lunghezza massima %d\n\n", letteraUnsChar, sizeof(letteraUnsChar), 0, UCHAR_MAX);

    printf("Sezione numeri con virgola:\n");
    printf("Lunghezza del valore float %.3f e': %d byte\t Lunghezza minima %.3g\t Lunghezza massima %.3g\n", nFloat, sizeof(nFloat),FLT_MIN, FLT_MAX);
    printf("Lunghezza del valore double %.3f e': %d byte\t Lunghezza minima %.3g\t Lunghezza massima %.3g\n", nDouble, sizeof(nDouble), DBL_MIN,DBL_MAX); // %g perchè il range è estremamente lungo, quindi l'ho inserito in notazione esponenziale!
    __mingw_printf("Lunghezza del valore long double %.2Lf e': %d byte\t Lunghezza minima %.5Lu\t Lunghezza massima %.5Lu\n", nLongDouble, sizeof(nLongDouble), LDBL_MIN, LDBL_MAX);
    printf("Lunghezza della parola %s e': %d byte\n", "Ciao!", sizeof("ciao!"));

    return 0;
}
