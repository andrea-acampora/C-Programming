#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    /*Inizializzo come richiesto una variabile di tipo int, una di tipo float, una di tipo double, una di tipo char, ed un array di 5 interi contenente i valori 10, 20, 30, 40, 50.*/
    int intero;
    float flo;
    double doppio;
    char carattere;
    int vettore[]={10,20,30,40,50};

    /*Per ciascuna delle variabili sopra dichiarate inizializzo un puntatore**/
    int *pIntero;
    float *pFloat;
    double *pDouble;
    char *pCarattere;
    int *pVettore;

    /*Assegno alla variabile puntatore la variabile a cui deve puntare*/
    pIntero=&intero;
    pFloat=&flo;
    pDouble=&doppio;
    pCarattere=&carattere;
    pVettore=vettore;

    /*Per ciascuna variabile faccio inserire all'utente un valore tramite la scanf seguita da fflush*/

    printf("\n  Inserire un valore per la variabile di tipo int:");
    scanf("%d",&intero);
    fflush(stdin);
    printf("\n\n");

    printf("  Inserire un valore per la variabile di tipo float:");
    scanf("%f",&flo);
    fflush(stdin);
    printf("\n\n");

    printf("  Inserire un valore per la variabile di tipo double:");
    scanf("%lf",&doppio);
    fflush(stdin);
    printf("\n\n");

    /*Mi assicuro che l'utente inserisca una lettera*/

    printf("  Inserire un valore per la variabile di tipo char:");
    scanf("%c",&carattere);
    fflush(stdin);
    printf("\n\n");

    printf("\n  ");
    system("PAUSE");
    system("cls");

    /*Visualizzo i valori delle variabili tramite accesso diretto alla variabile*/

    printf("\n  Visualizzo i valori tramite accesso diretto: \n");

    printf("  Il valore della variabile di tipo int e': %d\n",intero);

    printf("  Il valore della variabile di tipo float e': %f\n",flo);

    printf("  Il valore della variabile di tipo double e': %lf\n",doppio);

    printf("  Il valore della variabile di tipo char e': %c\n",carattere);

    printf("  I valori all'interno del vettore sono:");
    for(int i=0;i<5;i++)
        printf(" %d",vettore[i]);

    printf("\n  ");
    system("PAUSE");
    system("cls");

    /*Visualizzo i valori delle variabili tramite accesso indiretto ovvero tramite utilizzo del suo puntatore*/

    printf("\n  Visualizzo i valori tramite accesso indiretto:\n");

    printf("  Il valore della variabile di tipo int e': %d\n",*pIntero);

    printf("  Il valore della variabile di tipo float e': %f\n",*pFloat);

    printf("  Il valore della variabile di tipo double e': %lf\n",*pDouble);

    printf("  Il valore della variabile di tipo char e': %c\n",*pCarattere);

    printf("  I valori all'interno del vettore sono:");
    for(int i=0;i<5;i++)
        printf(" %d",pVettore[i]);

    printf("\n  ");
    system("PAUSE");
    system("cls");

    /*Visualizzo la POSIZIONE in memoria VARIABILE tramite l'utilizzo diretto della variabile*/

    printf("\n  Visualizzo la posizione in memoria tramite utilizzo diretto della variabile:\n");

    printf("  L'indirizzo di memoria della variabile di tipo int e': %p\n\n",&intero);

    printf("  L'indirizzo di memoria della variabile di tipo float e': %p\n\n",&flo);

    printf("  L'indirizzo di memoria della variabile di tipo double e': %p\n\n",&doppio);

    printf("  L'indirizzo di memoria della variabile di tipo char e': %p\n\n",&carattere);

    for(int i=0;i<5;i++)
    printf("  L'indirizzo di memoria dell'elemento del vettore con indice %d e' : %p\n\n",i,&vettore[i]);

    printf("\n  ");
    system("PAUSE");
    system("cls");

    /*Visualizzo la POSIZIONE in memoria della VARIABILE tramite il suo puntatore*/

    printf("\n  Visualizzo la posizione in memoria tramite utilizzo del puntatore:\n");

    printf("  L'indirizzo di memoria della variabile di tipo int e': %p\n\n",pIntero);

    printf("  L'indirizzo di memoria della variabile di tipo float e': %p\n\n",pFloat);

    printf("  L'indirizzo di memoria della variabile di tipo double e': %p\n\n",pDouble);

    printf("  L'indirizzo di memoria della variabile di tipo char e': %p\n\n",pCarattere);

    for(int i=0;i<5;i++)
    printf("  L'indirizzo di memoria dell'elemento del vettore con indice %d e' : %p\n\n",i,pVettore++);

    printf("\n  ");
    system("PAUSE");
    system("cls");


    /*Visualizzo la POSIZIONE in memoria del PUNTATORE */

    printf("\n  Visualizzo la posizione in memoria dei puntatori:\n");

    printf("  L'indirizzo di memoria del puntatore di tipo int e': %p\n\n",&pIntero);

    printf("  L'indirizzo di memoria del puntatore di tipo float e': %p\n\n",&pFloat);

    printf("  L'indirizzo di memoria del puntatore di tipo double e': %p\n\n",&pDouble);

    printf("  L'indirizzo di memoria del puntatore di tipo char e': %p\n\n",&pCarattere);

    printf("  L'indirizzo di memoria del puntatore al vettore e': %p\n\n",&pVettore);

    return 0;
}
