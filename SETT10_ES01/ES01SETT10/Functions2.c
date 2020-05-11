#include "Library.h"
#include "Library2.h"
#include "Library3.h"
#include <stdlib.h>
#include <stdio.h>

/**FUNZIONI PER PILA IMPLEMENTATA CON VETTORE STATICO**/

void pushStatic(PILA_STATICA *pila)
{
    int x_elem, x_position =0;   //variabili locali
     int i;
          printf("\nINSERISCI ELEMENTO DA AGGIUNGERE: >> ");        //chiedo che elemento inserire in testa
          scanf("%d",&x_elem);                                                 //prendo in input l'elemento

          if (isEmpty_static(pila))  //se la lista è vuota inserisco l'elemento nella prima posizione
          {
               pila->elem[0] = x_elem;  //assegno alla posizione 0 l'elemento
               pila->last_elem ++;      //incremento il valore che indica la posizione dell'ultimo elemento
          }
          else      //invece se la lista non è vuota
          {
               for (i=pila->last_elem; i>= x_position ; i--)       //con un ciclo for
               {
                    pila->elem[i+1] = pila->elem[i];             //sposto avanti di una posizione tutti gli elementi
               }

               pila->elem[0] = x_elem;       /* in prima posizione inserisco l'elemento digitato dall'utente */
               pila->last_elem ++;           /* incremento il valore che indica la posizione dell'ultimo eleento */
          }
     return;
}

void popStatic(PILA_STATICA *pila)
{
    int i = 0;     /*variabili locali*/
          for (i = 0; i <= pila->last_elem ; i++)      /*scorro tutti gli elementi dal primo all'ultimo*/
          {
               pila->elem[i] = pila->elem[i+1];        /*e li sposto indietro di una posizione*/
          }
          pila->last_elem --;                     /*decremento il valore che indica la posizione dell'ultimo elemento*/
     return;
}

int isEmpty_static(const PILA_STATICA *pila)
{
    return(pila->last_elem == EMPTY);  //se la lista è vuota viene restituito 0
}
void StatoPila_static(PILA_STATICA *pilaStat)         //funzione per la stampa della lista e del suo stato
{
     int i;
     if (!isEmpty_static(pilaStat))     //se la lista non è vuota, stampo i suoi elementi
     {
          printf("\nELEMENTI DELLA LISTA:\n");
          for (i = 0;i<=pilaStat->last_elem; i++)   //con un cilo for scorro gli elementi
          {
               printf("%d - ",pilaStat->elem[i]); //stampo gli elementi
          }
     }
     return;
}
void resetStatic(PILA_STATICA *pila)
{
    pila->last_elem=-1; //comando per azzerare la pila
}
void StampaPila_static(PILA_STATICA *pila)         //funzione per la stampa della pila e azzera
{
     int i;
          printf("\nELEMENTI DELLA LISTA:\n");
          for (i = 0;i<=pila->last_elem; i++)   //con un cilo for scorro gli elementi
          {
               printf("%d - ",pila->elem[i]); //stampo gli elementi
          }
        pila->last_elem=-1;  //azzero la pila
     return;
}
