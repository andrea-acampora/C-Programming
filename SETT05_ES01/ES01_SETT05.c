#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//SETTIMANA 05 - ESERCIZIO 1
/*Scrivere un programma C dove sono inizializzate una variabile di tipo int, una di tipo float,
 una di tipo double, una di tipo chart, ed un array di 5 interi (precisamente con i valori 10, 20, 30, 40, 50.
Inizializzare un puntatore per ciascuna di queste variabili.
 Assegnare ad ogni variabile un valore tramite l'utilizzo della funzione scanf.
 Visualizzare il valore di ogni variabile in due modi: prima tramite accesso diretto alla variabile
e a seguito tramite l'utilizzo del suo puntatore (accesso indiretto).
Visualizzare la posizione in memoria della variabile tramite l'utilizzo diretto della variabile
e tramite il suo puntatore. Visualizzare la posizione in memoria del puntatore. */
int main()
{
//DICHIARAZIONE VARIABILI
int i,*pint1,int1,v1[5]={10,20,30,40,50},(*pv1)[5];
float *pfloat1,float1;
double *pdouble1,double1;
char *pchar1,char1;
//ASSEGNAZIONE AI PUNTATORI DELLE VARIABILI A CUI PUNTARE
pint1=&int1;
pfloat1=&float1;
pdouble1=&double1;
pchar1=&char1;
pv1=&v1;
//ACQUISIZIONE VARIABILI
printf("Inserisci un numero intero \n");
scanf("%d",&int1);
fflush(stdin);
printf("Inserisci un numero float \n");
scanf("%f",&float1);
fflush(stdin);
printf("Inserisci un numero double \n");
scanf("%lf",&double1);
fflush(stdin);
printf("Inserisci un carattere \n");
scanf("%c",&char1);
fflush(stdin);
//STAMPA DEI VALORI DELLE VARIABILI TRAMITE ACCESSO A VARIABILE OPPURE AL CONTENUTO DELLA VARIABILE A CUI PUNTA IL PUNTATORE (*)
printf("Valore della variabile intero prima modalita': %d \n",int1);
printf("Valore della variabile intero seconda modalita': %d \n",*pint1);
printf("Valore della variabile float prima modalita': %g \n",float1);
printf("Valore della variabile float seconda modalita': %g \n",*pfloat1);
printf("Valore della variabile double prima modalita': %lf \n",double1);
printf("Valore della variabile double seconda modalita': %lf \n",*pdouble1);
printf("Valore della variabile char prima modalita': %c \n",char1);
printf("Valore della variabile char seconda modalita': %c \n",*pchar1);
//CICLO PER STAMPARE IL VETTORE IN TUTTE E DUE LE MODALITA
for(i=0;i<5;i++)
{
//SI ASSOCIANO GLI ELEMENTI DEL VETTORE AGLI ELEMENTI PUNTATI DAL VETTORE
*pv1[i]=v1[i];
printf("Valore del vettore : %d %d \n",v1[i],*pv1[i]);
}
//STAMPA POSIZIONE DELLE VARIABILI E DEL SUO PUNTATORE TRAMITE INDIRIZZO VARIABILE (&) OPPURE TRAMITE VARIABILE PUNTATORE (%x)
printf("Posizione in memoria variabile int : %x \n",&int1);
printf("Posizione in memoria variabile int tramite puntatore : %x \n",pint1);
printf("Posizione in memoria del suo puntatore: %x \n",&pint1);
printf("Posizione in memoria variabile float : %x \n",&float1);
printf("Posizione in memoria variabile flot tramite puntatore : %x \n",pfloat1);
printf("Posizione in memoria del suo puntatore: %x \n",&pfloat1);
printf("Posizione in memoria variabile double : %x \n",&double1);
printf("Posizione in memoria variabile double tramite puntatore : %x \n",pdouble1);
printf("Posizione in memoria del suo puntatore: %x \n",&pdouble1);
printf("Posizione in memoria variabile char : %x \n",&char1);
printf("Posizione in memoria variabile char tramite puntatore : %x \n",pchar1);
printf("Posizione in memoria del suo puntatore: %x \n",&pchar1);
printf("Posizione in memoria vettore : %x \n",&v1);
printf("Posizione in memoria vettore tramite puntatore : %x \n",pv1);
printf("Posizione in memoria del suo puntatore: %x \n",&pv1);
system("pause");
system("cls");
return 0;
}
