/*Scrivere un programma C dove sono inizializzate una variabile di tipo int,
una di tipo float, una di tipo double, una di tipo chart,
ed un array di 5 interi (precisamente con i valori 10, 20, 30, 40, 50).
Inizializzare un puntatore per ciascuna di queste variabili.
Assegnare ad ogni variabile un valore tramite l'utilizzo della funzione scanf.
Visualizzare il valore di ogni variabile in due modi:
prima tramite accesso diretto alla variabile e a seguito
tramite l'utilizzo del suo puntatore (accesso indiretto).
Visualizzare la posizione in memoria della variabile tramite
l'utilizzo diretto della variabile e tramite il suo puntatore.
Visualizzare la posizione in memoria del puntatore.*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    /*dichiarazione variabili ------------*/
    int Int;
    float Float;
    double Double;
    char Char;
    int Array[]= {10,20,30,40,50};
    int i;

    /*puntatori --------------------------*/
    int *pInt = &Int;
    float *pFloat = &Float;
    double *pDouble = &Double;
    char *pChar = &Char;
    int *pArray = Array;

    /*input -------------------------------*/
//int
    printf("\ninserisci un int <=100\n");
    do
    {
        scanf("%d",&Int);
        fflush(stdin);
    }
    while (Int>MAX);
//float
    printf("\ninserisci un float <=100\n");
    do
    {
        scanf("%f",&Float);
        fflush(stdin);
    }
    while (Float>MAX);
//double
    printf("\ninserisci un double <=100\n");
    do
    {
        scanf("%lf",&Double);
        fflush(stdin);
    }
    while (Double>MAX);
//char
    printf("\ninserisci un char\n");
    scanf("%c",&Char);
    fflush(stdin);
//array
    printf("\ninserisci <5> int <=100\n");
    for (i=0; i<5; i++)
    {
        do
        {
            scanf("%d",&Array[i]);
            fflush(stdin);
        }
        while (Array[i]>MAX);
    }

    /*output int -------------------------*/
    printf("\n\n------ INT ------");
//valore, accesso diretto
    printf("\nvalore della variabile (accesso diretto): %d",Int);
//valore, accesso indiretto
    printf("\nvalore della variabile (accesso indiretto): %d",*pInt);
//posizione variabile, accesso diretto
    printf("\nposizione della variabile (accesso diretto): %p",&Int);
//posizione variabile, accesso indiretto
    printf("\nposizione della variabile (accesso indiretto): %p",pInt);
//posizione puntatore
    printf("\nposizione del puntatore: %p",&pInt);

    /*output float -------------------------*/
    printf("\n\n------ FLOAT ------");
//valore, accesso diretto
    printf("\nvalore della variabile (accesso diretto): %f",Float);
//valore, accesso indiretto
    printf("\nvalore della variabile (accesso indiretto): %f",*pFloat);
//posizione variabile, accesso diretto
    printf("\nposizione della variabile (accesso diretto): %p",&Float);
//posizione variabile, accesso indiretto
    printf("\nposizione della variabile (accesso indiretto): %p",pFloat);
//posizione puntatore
    printf("\nposizione del puntatore: %p",&pFloat);

    /*output double -------------------------*/
    printf("\n\n------ DOUBLE ------");
//valore, accesso diretto
    printf("\nvalore della variabile (accesso diretto): %lf",Double);
//valore, accesso indiretto
    printf("\nvalore della variabile (accesso indiretto): %lf",*pDouble);
//posizione variabile, accesso diretto
    printf("\nposizione della variabile (accesso diretto): %p",&Double);
//posizione variabile, accesso indiretto
    printf("\nposizione della variabile (accesso indiretto): %p",pDouble);
//posizione puntatore
    printf("\nposizione del puntatore: %p",&pDouble);

    /*output char -------------------------*/
    printf("\n\n------ CHAR ------");
//valore, accesso diretto
    printf("\nvalore della variabile (accesso diretto): %c",Char);
//valore, accesso indiretto
    printf("\nvalore della variabile (accesso indiretto): %c",*pChar);
//posizione variabile, accesso diretto
    printf("\nposizione della variabile (accesso diretto): %p",&Char);
//posizione variabile, accesso indiretto
    printf("\nposizione della variabile (accesso indiretto): %p",pChar);
//posizione puntatore
    printf("\nposizione del puntatore: %p",&pChar);

    /*output array -------------------------*/
    for (i=0; (i<5); i++)
    {
        printf("\n\n------ ARRAY[%d] ------",i);
//valore, accesso diretto
        printf("\nvalore della variabile (accesso diretto): %d",Array[i]);
//valore, accesso indiretto
        printf("\nvalore della variabile (accesso indiretto): %d",*(pArray+i));
//posizione variabile, accesso diretto
        printf("\nposizione della variabile (accesso diretto): %p",&Array[i]);
//posizione variabile, accesso indiretto
        printf("\nposizione della variabile (accesso indiretto): %p",pArray+i);
//posizione puntatore
        printf("\nposizione del puntatore: %p",&pArray);
    }

    /*chiusura ------------------------------*/
    printf("\n\npremere invio per terminare\n");
    getchar();
    return 0;
}
