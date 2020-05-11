#include "Library.h"
#include "Library2.h"
#include "Library3.h"
#include <stdlib.h>
#include <stdio.h>
#define N 10

/**FUNZIONI PER PILA IMPLEMENTATA CON VETTORE DINAMICO**/

PILA_DINAMICA CreateList_dinamic()
{
     PILA_DINAMICA temp;
     temp.elem =NULL;     /*inizializzo a null il puntatore*/
     temp.dim = 0;        /*pongo = 0 la dimensione del vettore*/
     temp.last_elem = -1; /*segnalo che il vettore è vuoto*/
     temp.elem = (tipo_elemento*)malloc (N*sizeof(tipo_elemento));    /*alloco il vettore*/
     if(temp.elem != NULL )    /*se il puntatore non è nullo*/
     {
          temp.dim=N;                       /*pongo = N la dimensione del vettore*/
          temp.last_elem = -1;              /*inizializzo la struttura con un valore che  indica che la struttura è vuota*/
     }
     else
     {
          printf("\nERRORE NELL'ALLOCAZIONE DELLA MEMORIA\n");    /*avviso che non è presente sufficiente memoria*/
     }

     return temp ; /*restituisco il puntatore alla nuova zona allocata*/
}

int IsEmpty_dinamic(const PILA_DINAMICA *pila)  //funzione per il controllo della lista vuota
{
     return(pila->last_elem == EMPTY);  //se la lista è vuota viene restituito 0
}

int isFull_dinamic(PILA_DINAMICA *pila)        //funzione per il controllo della lista piena
{
     if (pila->last_elem == (pila->dim-1))      //se la lista è piena avvisa l'utente
    {
         printf("\nLISTA PIENA!\n");     //avviso che la funzione è piena
    }
     return(pila->last_elem == (pila->dim-1));  //se la lista è vuota restituisco 0
}
void PushDinamic(PILA_DINAMICA *pila)        //funzione per l'inserimento in testa
{
     int x_elem, x_position = 0;   //variabili locali
     int i;
     if (isFull_dinamic(pila))       //se la lista non è piena
     {
           ExtendDinamic(pila);
     }

          printf("\nINSERIRE ELEMENTO DA AGGIUNGERE: >> ");        //chiedo che elemento inserire in testa
          scanf("%d", &x_elem);                                                 //prendo in input l'elemento

          if (IsEmpty_dinamic(pila))  //se la lista è vuota inserisco l'elemento nella prima posizione
          {
               pila->elem[0] = x_elem;  //assegno alla posizione 0 l'elemento
               pila->last_elem ++;      //incremento il valore che indica la posizione dell'ultimo elemento
          }
          else      //invece se la lista non è vuota
          {
               for (i =pila->last_elem; i >= x_position ; i--)       //con un ciclo for
               {
                    pila->elem[i+1] = pila->elem[i];             //sposto avanti di una posizione tutti gli elementi
               }

               pila->elem[0] = x_elem;       /* in prima posizione inserisco l'elemento digitato dall'utente */
               pila->last_elem ++;           /* incremento il valore che indica la posizione dell'ultimo eleento */
          }
     return;
}
void ExtendDinamic(PILA_DINAMICA *pila)
{
     pila->elem = (tipo_elemento*) realloc (pila->elem, 2*(pila->dim)*sizeof(tipo_elemento)); /*alloco nuova memoria per la lista, ampliandola*/
     if(pila->elem != NULL )  /*se ho allocato memoria*/
     {
          pila->dim *= 2;     /*raddoppio lo spazio della lista*/
          printf("REALLOCAZIONE DELLA MEMORIA EFFETTUATA!\n\n");
     }
     else
          printf("ERRORE NELL'ALLOCAZIONE DELLA MEMORIA\n");  /*se non sono riuscito ad allocare spazio, avviso dell'errore*/

     return;
}
void PopDinamic(PILA_DINAMICA *pila)  /*funzione per il cancellamento in testa dell'elemento*/
{
     int i = 0;     /*variabili locali*/
          for (i = 0; i <= pila->last_elem ; i++)      /*scorro tutti gli elementi dal primo all'ultimo*/
          {
               pila->elem[i] = pila->elem[i+1];        /*e li sposto indietro di una posizione*/
          }

          pila->last_elem --;                     /*decremento il valore che indica la posizione dell'ultimo elemento*/
     return;
}
void PrintDinamic(PILA_DINAMICA *pila)         //funzione per la stampa della lista e del suo stato
{
     int i;
          printf("\nELEMENTI DELLA LISTA:\n");
          for (i = 0;i<=pila->last_elem; i++)   //con un cilo for scorro gli elementi
          {
               printf("%d - ",pila->elem[i]); //stampo gli elementi
          }
        pila->last_elem=-1; //comando per azzerare la pila
     return;
}
void ResetDinamic(PILA_DINAMICA *pila)
{
    pila->last_elem=-1; //funzione per azzerare la pila
}
void StatoDinamic(PILA_DINAMICA *pila)         //funzione per la stampa della lista e del suo stato
{
     int i;
          printf("\nELEMENTI DELLA LISTA:\n");
          for (i = 0;i<=pila->last_elem; i++)   //con un cilo for scorro gli elementi
          {
               printf("%d - ",pila->elem[i]); //stampo gli elementi
          }
     return;
}
