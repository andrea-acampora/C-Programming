#include "Library.h"
#include "Library2.h"
#include "Library3.h"
#include <stdlib.h>
#include <stdio.h>

/**FUNZIONI PER CODA IMPLEMENTATA CON STRUTTURE COLLEGATE**/

void push(TipoCoda **c,int num)//FUNZIONE PER INSERIRE IN CODA
{
     TipoCoda *nuovo, *temp; /*puntatori a struttura*/
     temp = NULL;
     nuovo = (TipoCoda*) malloc (sizeof(TipoCoda));     /*alloco*/
     nuovo->valore = num;         /*assegno valore*/
     nuovo->next=NULL;        /*imposto puntatore*/

     if (nuovo == NULL)       /*controlli malloc*/
     {
          printf("\nERRORE NELL'ALLOCAZIONE DELLA MEMORIA\n");
          system("pause");
          exit(1);
     }

     if (*c == NULL)      /*se la testa è a null*/
          *c = nuovo;     /*la faccio puntare al nuovo elemento*/
     else
     {
          temp = *c;      /*altrimenti imposto un puntatore temporaneo alla testa*/
          while (temp->next != NULL)    /*scorro la lista */
               temp = temp ->next;      /*e sposto avanti tutti gli elementi*/

          temp->next = nuovo;      /*faccio puntare a temp la nuova struttura*/
     }
}

struct cella *pop(TipoCoda **c)//FUNZIONE PER CANCELLARE IN TESTA
{
     if (c != NULL)  /*se la lista non è vuota*/
     {
          TipoCoda *temp;   /*dichiaro un puntatore*/
          temp = *c; /*lo pongo uguale alla testa della lista*/
          *c = (*c)->next; /*imposto la nuova testa*/
          free(temp);              /*dealloco spazio*/
     }
}

void ResetCoda(TipoCoda **c)//FUNZIONE PER RESETTARE LA PILA
{
 struct cella *temp;
 while(*c!=NULL)
 {
     temp=pop(c);
     if(temp!=NULL)
     {
         free(temp);
     }
 }
}
void stato(TipoCoda *c)//FUNZIONE PER STAMPARE E AZZERARE
{
     TipoCoda *temp;        /*dichiaro un puntatore a LISTA e lo pongo uguale alla testa*/
     temp = c;

          printf("\nELEMENTI DELLA LISTA: ");
          while (temp!= NULL)          /*stampo tutti gli elementi fino  a che la il puntatore non punta a NULL*/
          {
               printf("%d  ", temp->valore);
               temp = temp->next;       /*sposto il puntatore alla struttura successiva*/
          }
}
void StampaAzzera(TipoCoda **c)
{
         TipoCoda *temp;        /*dichiaro un puntatore a LISTA e lo pongo uguale alla testa*/
        temp = c;

          printf("\nELEMENTI DELLA LISTA: ");
          while (temp!= NULL)          /*stampo tutti gli elementi fino  a che la il puntatore non punta a NULL*/
          {
               printf("%d  ", temp->valore);
               temp = temp->next;       /*sposto il puntatore alla struttura successiva*/
          }
             while(*c!=NULL)
            {
             temp=pop(c);
             if(temp!=NULL)
             {
                 free(temp);
             }
             exit(1);
 }

}
