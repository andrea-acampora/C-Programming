#include "Library.h"
#include "Library2.h"
#include "Library3.h"
#include <stdlib.h>
#include <stdio.h>

/**FUNZIONI PER PILA IMPLEMENTATA CON STRUTTURE COLLEGATE**/

void push(struct cella **p,int num)//FUNZIONE PER INSERIRE IN TESTA
{
struct cella *nuovo;
nuovo=(struct cella*)malloc(sizeof(struct cella));//ALLOCO SPAZIO IN MEMORIA
    if(nuovo==NULL)//CONTROLLO SULLA MALLOC
    {
    printf("ERRORE NELL'ALLOCAZIONE DELLA MEMORIA\n");
    system("pause");
    exit(1);
    }
nuovo->valore=num;
nuovo->next=*p;
*p=nuovo;
}

struct cella *pop(struct cella **p)//FUNZIONE PER CANCELLARE IN TESTA
{
    struct cella *temp;
    if(*p==NULL)
    {
    return *p;
    }
temp=*p;//ELIMINO IN TESTA SPOSTANDO IL PUNTATORE AL PUNTATORE SUCCESSIVO E LIBERANDO CON LA FREE
*p=(*p)->next;
temp->next=NULL;
free(temp);
}
void ResetPila(struct cella **p)//FUNZIONE PER RESETTARE LA PILA
{
 struct cella *temp;
 while(*p!=NULL)
 {
     temp=pop(p);
     if(temp!=NULL)
     {
         free(temp);
     }
 }
}
void StampaAzzera(struct cella **p)//FUNZIONE PER STAMPARE E AZZERARE
{
    while (*p!=NULL)
    {
        printf("- %d\n",(*p)->valore);
        *p = (*p)->next;
    }
}
