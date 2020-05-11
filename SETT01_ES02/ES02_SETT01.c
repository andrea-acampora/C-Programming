#include <stdio.h>
/*Partendo dalla dichiarazione di quattro variabili, una variabile int, una float, una double, e una char,
 scrivere un programma C che usi TUTTI gli operatori studiati.
Stampare i valori delle variabili usate prima e dopo l’applicazione degli stessi. */
int main()
{
    int varInt = 15;
    char varChar = 'P';
    float varFloat = 34567.8793;
    double varDouble = 456723.998765234;

        printf("Variabili: %d %c %g %e \n",varInt,varChar,varFloat,varDouble);
        ++varInt;
        printf("Nuova variabile intero incrementata:%d\n",varInt);
        float ris=varInt/varFloat;
        printf("Il risultato di %d / %2.2f = %g \n",varInt,varFloat,ris);
        printf("Il doppio di %d e' %d \n",varInt,varInt+varInt);
        printf("%g * %g = %g \n",varDouble,varFloat,varDouble*varFloat);
        printf("valore variabile int: %d \n",varInt);
        --varInt;
        printf("valore variabile int decrementata: %d\n",varInt);
        +varInt;
        printf("Variabile positiva: %d\n",varInt);
        int varInt2=7;
        int ris2=varInt/varInt2;
        printf("Il risultato di %d / %d = %d",varInt,varInt2,ris2);
        float ris3=varInt%varInt2;
        printf("Il resto di %d / %d = %g",varInt,varInt2,ris3);


}
