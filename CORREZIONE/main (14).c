#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int main()
{
    /* ASSEGNAZIONE VARIABILI */
    char c='A';
    unsigned char uc='B';
    short s=3200;
    int i=25046;
    unsigned int ui=65000;
    long l=646458876;
    unsigned long  ul=643486862;
    float f=25.8653;
    double d=68.21456415;
    long double ld=1.4687737;   //non va sto long double
    int n=0;  //Numero caratteri stampati dalla printf



    n = printf(" %c\n %c\n %d\n %d\n %d\n %ld\n %ld\n %f\n %f\n %f\n",c,uc,s,i,ui,l,ul,f,d,ld);  /*Stampa valori delle varibili*/
    printf("ha stampato %d caratteri",n);      //Stampa numero caratteri stmapati
    n = printf("\n\n %c\n %c\n %3d\n %10d\n %5d\n %6ld\n %ld\n %8.4f\n %9.3f\n %f\n",c,uc,s,i,ui,l,ul,f,d,ld);  /*Stampa valori delle varibili*/
    printf("ha stampato %d caratteri",n);      //Stampa numero caratteri stmapati
    n = printf("\n\ncarattere (char) byte: %d", sizeof(char));      //Stampa occupazione memoria delle variabili
    printf(" ha stampato %d caratteri",n);
    n = printf("\ncarattere (unsigned char) byte: %d", sizeof(unsigned char));
    printf(" ha stampato %d caratteri",n);
    n = printf("\nnumero intero (int) byte: %d", sizeof(int));
    printf(" ha stampato %d caratteri",n);
    n = printf("\nnumero intero senza segno (unsigned int) byte: %d", sizeof(unsigned int));
    printf(" ha stampato %d caratteri",n);
    n = printf("\nnumero intero lungo (long) byte: %d", sizeof(long));
    printf(" ha stampato %d caratteri",n);
    n = printf("\nnumero intero lungo senza segno(unsigned long) byte: %d", sizeof(unsigned long));
    printf(" ha stampato %d caratteri",n);
    n = printf("\nnumero con virgola (float) byte: %d", sizeof(float));
    printf(" ha stampato %d caratteri",n);
    n = printf("\nnumero con virgola (double) byte: %d", sizeof(double));
    printf(" ha stampato %d caratteri",n);
    n = printf("\nnumero con virgola (long double) byte: %d",sizeof(long double));
    printf(" ha stampato %d caratteri",n);

    /* VALORI MASSIMI DEI DIVERSI TIPI DI VARIABILI */

    n = printf("\n\nIl valore massimo dello short e': %d e il minimo e': %d",SHRT_MAX,SHRT_MIN);
    printf(" ha stampato %d caratteri",n);
    n = printf("\nIl valore massimo dell' unsigned short e': %d",USHRT_MAX);
    printf(" ha stampato %d caratteri",n);
    n = printf("\nIl valore massimo dell' intero e': %d e il minimo e': %d",INT_MAX,INT_MIN);
    printf(" ha stampato %d caratteri",n);
    n = printf("\nIl valore massimo dell' intero senza segno e': %d",UINT_MAX);
    printf(" ha stampato %d caratteri",n);
    n = printf("\nIl valore massimo dell long e': %d e il minimo e': %d",LONG_MAX,LONG_MIN);
    printf(" ha stampato %d caratteri",n);
    n = printf("\nIl valore massimo dell' unsigned long e': %d",ULONG_MAX);
    printf(" ha stampato %d caratteri",n);

    return 0;

}
