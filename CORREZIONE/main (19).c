#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

    // Esercizio 1 Settimana 1, consegna entro domenica 30/09/2018

int main()
{
    // Dichiaro le variabili, una per ogni tipo
    char variabileChar='A';
    int variabileInt=10;
    short variabileShort=101;
    long int variabileLong=2114116;
    float variabileFloat=327362.52345;
    double variabileDouble=3334538342.62;
    long double variabileLongDouble=7427838982.748584;
    unsigned char variabileUnsChar=201;
    unsigned int variabileUnsInt=573;
    unsigned long int variabileUnsLongInt=383647294;

    //La funzione printf stampa a schermo una stringa e allo stesso momento restituisce un valore int (il numero di caratteri che stampa a schermo)
    //Per questo motivo dichiarando una variabile int: lunghezza=printf restituisco il valore della printf alla mia variabile lunghezza
    //Stampo poi a schermo il valore di tale variabile "lunghezza"
    int lunghezza = printf("La variabile di tipo char e': %c - L'occupazione di memoria e': %d byte - Valore massimo: %d Valore minimo: %d", variabileChar, sizeof(variabileChar), CHAR_MAX, CHAR_MIN);
    printf("\n");
    printf("Numero di cartteri stampati dalla funzione printf nella stringa precedente: %d\n", lunghezza);

    //Spampo a schermo il contenuto della variabile, utilizzando la funzione sizeof() identifico quanta memoria è richiesta per la memorizzazione del dato e stampo tale valore, stampo inoltre il valore massimo e minimo che può essere assegnato a tale variabile
    printf("La variabile di tipo int e': %d - L'occupazione di memoria e': %d byte - Valore massimo: %d Valore minimo: %d\n", variabileInt, sizeof(variabileInt), INT_MAX, INT_MIN );
    printf("La variabile di tipo short e': %d - L'occupazione di memoria e': %d byte - Valore massimo: %d Valore minimo: %d\n", variabileShort, sizeof(variabileShort), SHRT_MAX, SHRT_MIN );
    printf("La variabile di tipo long e': %d - L'occupazione di memoria e': %d byte - Valore massimo: %d Valore minimo: %d\n", variabileLong, sizeof(variabileLong), LONG_MAX, LONG_MIN );
    printf("La variabile di tipo float e': %f - L'occupazione di memoria e': %d byte - Valore massimo: %e Valore minimo: %e\n", variabileFloat, sizeof(variabileFloat), FLT_MAX, FLT_MIN );
    printf("La variabile di tipo double e': %f - L'occupazione di memoria e': %d byte - Valore massimo: %e Valore minimo: %e\n", variabileDouble, sizeof(variabileDouble), DBL_MAX, DBL_MIN );
    //per la varibile long double utilizzo la funzione __mingw_printf per problema di visualizzazione
    __mingw_printf("La variabile di tipo long double e': %Le - L'occupazione di memoria e': %d byte - Valore massimo: %Le Valore minimo: %Le\n", variabileLongDouble, sizeof(variabileLongDouble), LDBL_MAX, LDBL_MIN );
    printf("La variabile di tipo unsigned char e': %d - L'occupazione di memoria e': %d byte - Valore massimo: %d Valore minimo: 0\n", variabileUnsChar, sizeof(variabileUnsChar), UCHAR_MAX );
    printf("La variabile di tipo unsigned int e': %d - L'occupazione di memoria e': %d byte - Valore massimo: %u Valore minimo: 0\n", variabileUnsInt, sizeof(variabileUnsInt), UINT_MAX );
    printf("La variabile di tipo unsigned long int e': %lu - L'occupazione di memoria e': %d byte - Valore massimo: %lu Valore minimo: 0\n", variabileUnsLongInt, sizeof(variabileUnsLongInt), ULONG_MAX );


    printf("\n\n--------------------------------------------------------------------------------\n\n");


    //dichiaro alcune variabili utili per visualizzare i vari casi appartenenti alla funzione printf()
    int var1=117;
    float var2=5623.56763;
    short int var3=13;
    unsigned long int var4=35335328;
    long double var5=749472.473289;

    printf("Numero float senza formattazione: %f\n",var2);
    printf("Risultato dell'espressione %f*%f = %f\n",var2, var2, var2*var2);
    printf("Intero = %i\n", var1);
    printf("Intero con segno = %+d\n", var1);
    printf("Float con 10 caratteri dove i campi vuoti sono riempiti con la cifra 0 = %010.2f\n", var2);
    printf("Float con minimo 7 cifre dopo il separatore decimale in formato esponenziale = %.7e\n", var2);
    printf("Float con specifica di conversione ""g"" e un massimo di 4 cifre significative = %.4g\n", var2);
    printf("Short int con modificatore di lunghezza ""h"" = %hd\n", var3);
    printf("Unsigned long int con minimo 14 caratteri = %14lu\n", var4);
    printf("Valore di %d in hex allineato a sinistra con minimo 10 cifre e0x come primi due caratteri = %-#10x\n",var1, var1);
    //utilizzo long double con __mingw_printf per problema di visualizzazione
    __mingw_printf("Long double con modificatore di lunghezza ""L"" in notazione esponenziale= %Le\n", var5);
    __mingw_printf("Long double con 10 cifre dopo la virgola mobile = %.10Le\n", var5);

    system("pause");
    return 0;
}
