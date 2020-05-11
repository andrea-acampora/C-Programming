#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
/*
Scrivere un programma C che dichiari una variabile per ogni tipo studiato
(usando anche i qualificatori short, long, signed e unsigned), ne stampi il valore e l’occupazione di memoria in byte.
Utilizzare TUTTI gli argomenti della funzione printf() studiati e TUTTE le diverse varianti
modificatore, campoMinimo, precisione, modificatoreLunghezza). Per la prima chiamata alla funzione printf(),
mostrare a video anche il numero di caratteri che quest’ultima ha stampato (Aiuto: la funzione printf() restituisce un valore).
Stampare inoltre il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato. */
int main()
{
    int lunghezza=printf("4567");
    short int varShortInt = 30;
    char varChar='A';
    signed char varSignChar = -2;
    unsigned char varUnsChar='P';
    float varFloat = 2.5;
    double varDouble = 192.479;
    long double varLongDouble = 123459.98754;
    unsigned short int varUnsigShInt = 18;
    signed int varSigInt = -1457;
    signed long int varSigLonInt = 145987;
    unsigned long int varUnsLongInt = 876789449;
    unsigned int varUnsInt = 9558423;
        /*Stampa valore variabili,Dimensione e Valori minimo e massimo*/
        printf(" numero caratteri %d \n",lunghezza);
        printf("\n");
        /*CHAR*/
        printf("valore variabile Char %c \n",varChar);
        printf("Dimensione di Char= %d bytes \n", sizeof(varChar));
        printf("Valore minimo: %d Valore massimo: %d \n",CHAR_MIN,CHAR_MAX);
        printf("\n");
        /*SIGNED CHAR*/
        printf("valore variabile Signed Char %d \n",varSignChar);
        printf("Dimensione di Signed Char= %d bytes\n", sizeof(varSignChar));
        printf("Valore minimo: %d Valore massimo: %d \n",CHAR_MIN,CHAR_MAX);
        printf("\n");
        /*UNSIGNED CHAR*/
        printf("valore variabile Unsigned Char %c \n",varUnsChar);
        printf("Dimensione di Unsigned Char= %d bytes\n", sizeof(varUnsChar));
        printf("Valore minimo: 0 Valore massimo: %d \n",UCHAR_MAX);
        printf("\n");
        /*FLOAT*/
        printf("valore variabile Float %g \n",varFloat);
        printf("Dimensione di Float= %d bytes\n", sizeof(varFloat));
        printf("Valore minimo: %e Valore massimo: %e \n",FLT_MIN,FLT_MAX);
        printf("\n");
        /*SHORT INT*/
        printf("valore variabile ShortInt %d \n",varShortInt);
        printf("Dimensione di ShortInt= %d bytes\n", sizeof(varShortInt));
        printf("Valore minimo: %d Valore massimo: %d \n",SHRT_MIN,SHRT_MAX);
        printf("\n");
        /*UNSIGNED SHORT INT*/
        printf("valore variabile Unsigned Short Int %d \n",varUnsigShInt);
        printf("Dimensione di Unsigned Short Int= %d bytes\n", sizeof(varUnsigShInt));
        printf("Valore minimo: 0 Valore massimo: %u \n",USHRT_MAX);
        printf("\n");
        /*DOUBLE*/
        printf("valore variabile Double %g \n",varDouble);
        printf("Dimensione di Double= %d bytes\n", sizeof(varDouble));
        printf("Valore minimo: %e Valore massimo: %e \n",DBL_MIN,DBL_MAX);
        printf("\n");
        /*LONG DOUBLE*/
        printf("valore variabile LongDouble %Lf \n",varLongDouble);
        printf("Dimensione di LongDouble= %d bytes\n", sizeof(varLongDouble));
        printf("Valore minimo: %Le Valore massimo: %Le \n",LDBL_MIN,LDBL_MAX);
        printf("\n");
        /*SIGNED INT*/
        printf("valore variabile Signed Int %d \n",varSigInt);
        printf("Dimensione di Signed Int= %d bytes\n", sizeof(varSigInt));
        printf("Valore minimo: %d Valore massimo: %d \n",INT_MIN,INT_MAX);
        printf("\n");
        /*SIGNED LONG INT*/
        printf("valore variabile Signed Long Int %d \n",varSigLonInt);
        printf("Dimensione di Signed Long Int= %d bytes\n", sizeof(varSigLonInt));
        printf("Valore minimo: %d Valore massimo: %d \n",LONG_MIN,LONG_MAX);
        printf("\n");
        /*UNSIGNED LONG INT*/
        printf("valore variabile Unsigned Long Int %u \n",varUnsLongInt);
        printf("Dimensione di Unsigned Long Int= %u bytes\n", sizeof(varUnsLongInt));
        printf("Valore minimo: 0 Valore massimo: %u \n",ULONG_MAX);
        printf("\n");
        /*UNSIGNED INT*/
        printf("valore variabile Unsigned Int %d \n",varUnsInt);
        printf("Dimensione di Unsigned Int= %u bytes\n", sizeof(varUnsInt));
        printf("Valore minimo: 0 Valore massimo: %d \n",UINT_MAX);
        printf("\n");
        printf("\n");
        /*Argomenti printf*/
        printf("Valore di tre variabili= %c %g %d \n",varChar,varFloat,varUnsInt);
        printf("variabile con allineamento a destra: %12d \n",varUnsInt);
        printf("variabile con allineamento a sinistra: %-d \n",varUnsInt);
        printf("variabile con minimo 5 caratteri e 2 cifre: %5.2g \n",varFloat);

        printf("\n");
        system("pause");
}
