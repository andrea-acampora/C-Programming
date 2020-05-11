#include "Library.h"
#include "Library2.h"
#include "Library3.h"
#include <stdlib.h>
#include <stdio.h>

/**FUNZIONI PER CODA IMPLEMENTATA CON VETTORE STATICO**/

void pushStatic(CODA_STATICA *coda)
{
    int x_elem, x_position =0;   //variabili locali
     int i;
          printf("\nINSERISCI ELEMENTO DA AGGIUNGERE: >> ");        //chiedo che elemento inserire in testa
          scanf("%d",&x_elem);                                                 //prendo in input l'elemento

          if (isEmpty_static(coda))  //se la lista è vuota inserisco l'elemento nella prima posizione
          {
               coda->elem[0] = x_elem;  //assegno alla posizione 0 l'elemento
               coda->last_elem ++;      //incremento il valore che indica la posizione dell'ultimo elemento
          }
          else      //invece se la lista non è vuota
          {
            coda->elem[coda->last_elem+1] = x_elem;      /*inserisco l'elemento in ultima posizione*/
            coda->last_elem ++;                          /*incremento il valore che indica la posizione dell'ultimo elemento*/
          }
     return;
}

void popStatic(CODA_STATICA *coda)
{
    int i = 0;     /*variabili locali*/
          for (i = 0; i <= coda->last_elem ; i++)      /*scorro tutti gli elementi dal primo all'ultimo*/
          {
               coda->elem[i] = coda->elem[i+1];        /*e li sposto indietro di una posizione*/
          }
          coda->last_elem --;                     /*decremento il valore che indica la posizione dell'ultimo elemento*/
     return;
}

int isEmpty_static(const CODA_STATICA *coda)
{
    return(coda->last_elem == EMPTY);  //se la lista è vuota viene restituito 0
}
void StatoCoda_static(CODA_STATICA *codaStat)         //funzione per la stampa della lista e del suo stato
{
     int i;
     if (!isEmpty_static(codaStat))     //se la lista non è vuota, stampo i suoi elementi
     {
          printf("\nELEMENTI DELLA LISTA:\n");
          for (i = 0;i<=codaStat->last_elem; i++)   //con un cilo for scorro gli elementi
          {
               printf("%d - ",codaStat->elem[i]); //stampo gli elementi
          }
     }
     return;
}
void resetStatic(CODA_STATICA *coda)
{
    coda->last_elem=-1; //comando per azzerare la pila
}
void StampaCoda_static(CODA_STATICA *coda)         //funzione per la stampa della pila e azzera
{
     int i;
          printf("\nELEMENTI DELLA LISTA:\n");
          for (i = 0;i<=coda->last_elem; i++)   //con un cilo for scorro gli elementi
          {
               printf("%d - ",coda->elem[i]); //stampo gli elementi
          }
        coda->last_elem=-1;  //azzero la pila
     return;
}
