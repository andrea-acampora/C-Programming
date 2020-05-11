/*
     ESERCIZIO 1

     Predisporre una libreria di gestione del tipo di dato astratto LISTA,
     implementato sia tramite allocazione indicizzata (vettore statico e vettore dinamico)
     che tramite strutture collegate.
     Le funzioni che dovranno essere implementate sono:
          -inserisci in testa,
          -inserisci in coda,
          -inserisci dopo un certo elemento,
          -cancella dalla testa,
          -cancella dalla coda,
          -cancella la prima occorrenza dell�elemento.
     Il programma deve visualizzare lo stato della lista ad inizio
     esecuzione (vuota) e dopo ogni operazione scelta dall'utente.
*/




/*includo file di libreria .h*/
#include "liste_collegate.h"


void stampa_lista(LISTA *testa)    /*funzione per stampare la lista=======================================================================*/
{
     LISTA *temp;        /*dichiaro un puntatore a LISTA e lo pongo uguale alla testa*/
     temp = testa;

     if (temp == NULL)   /*se la lista è vuota lo notifico*/
     {
          printf("\nStato della lista: VUOTA\n");
          return;
     }
     else                /*altrimenti*/
     {
          printf("\nGli elementi della lista sono: ");
          while (temp != NULL)          /*stampo tutti gli elementi fino  a che la il puntatore non punta a NULL*/
          {
               printf("%d  ", temp->elem);
               temp = temp->next;       /*sposto il puntatore alla struttura successiva*/
          }
     }

     printf("\n\n");
}



LISTA* locate_position_elem_lista(LISTA *testa, tipo_elemento x)/*funzione per cercare elemento=======================================================================*/
{
     if (testa == NULL)   /*se la lista è vuota lo notifico*/
          printf("\n La lista e\' vuota");
     else
     {
          LISTA *temp;   /*dichiaro un puntatore temp*/
          temp = testa;  /*lo pongo = testa*/

          while (temp != NULL)     /*fino a che il puntatore è != da NULL*/
          {
               if (temp->elem == x)     /*se l'elemento == x*/
               {
                    return temp;        /*restituisco il puntatore alla struttura desiderata*/
               }
               temp = temp->next;       /*sposto avanti il puntaotre alla struttura successiva*/
          }
          printf("Elemento non presente nella lista\n\n");
     }
     return 0;
}


void ins_testa_lista(LISTA **testa, tipo_elemento x)/*funzione per inserire in testa alla lista=======================================================================*/
{
     LISTA *nuovo;       /*pntatore per allocare nuova struttura*/
     nuovo = (LISTA*) malloc (sizeof(LISTA));     /*alloco nuova struttura*/
     if (nuovo == NULL)                           /*controllo malloc*/
     {
          printf("\nErrore: memoria insufficiente.\n Il programma verr� chiuso");
          system("pause");
          exit(1);
     }

     nuovo->elem = x;    /*assegno il valore inserito dall'utente alla struttura*/
     nuovo->next = *testa;    /*faccio puntare next alla vecchia prima struttura*/

     *testa = nuovo;          /*la testa punta alla nuova struttura*/
}

void ins_coda_lista(LISTA **testa, tipo_elemento x)/*funzione per inserire in coda alla lista=======================================================================*/
{
     LISTA *nuovo, *temp; /*puntatori a struttura*/
     temp = NULL;
     nuovo = (LISTA*) malloc (sizeof(LISTA));     /*alloco*/
     nuovo->elem = x;         /*assegno valore*/
     nuovo->next=NULL;        /*imposto puntatore*/

     if (nuovo == NULL)       /*controlli malloc*/
     {
          printf("\nErrore: memoria insufficiente.\n Il programma verr� chiuso");
          system("pause");
          exit(1);
     }

     if (*testa == NULL)      /*se la testa è a null*/
          *testa = nuovo;     /*la faccio puntare al nuovo elemento*/
     else
     {
          temp = *testa;      /*altrimenti imposto un puntatore temporaneo alla testa*/
          while (temp->next != NULL)    /*scorro la lista */
               temp = temp ->next;      /*e sposto avanti tutti gli elementi*/

          temp->next = nuovo;      /*faccio puntare a temp la nuova struttura*/
     }
}

void ins_elem_input_lista(LISTA **testa, tipo_elemento x, tipo_elemento x_position)/*funzione per inserire in lista=======================================================================*/
{
     LISTA *nuovo, *temp;          /*puntatori a strutture*/
     nuovo = (LISTA*) malloc (sizeof(LISTA));     /*malloc*/
     if (nuovo == NULL)                           /*controlli malloc*/
     {
          printf("\nErrore: memoria insufficiente.\n Il programma verr� chiuso");
          system("pause");
          exit(1);
     }

     temp = locate_position_elem_lista(testa, x_position);  /*con una funzione trovo la posizione dell'elemento cercato*/
     nuovo->elem = x;    /*imposto l'elemento inserito dall'utente*/
     nuovo->next = temp->next;     /*imposto i puntatori alle strutture successive*/
     temp->next = nuovo;           /*imposto la posizione del nuovo elemento*/

}

void canc_testa_lista(LISTA **testa)/*funzione per cancellare la testa della lista=======================================================================*/
{
     if (testa != NULL)  /*se la lista non è vuota*/
     {
          LISTA *temp;   /*dichiaro un puntatore*/
          temp = *testa; /*lo pongo uguale alla testa della lista*/
          *testa = (*testa)->next; /*imposto la nuova testa*/
          free(temp);              /*dealloco spazio*/
     }
}
void canc_coda_lista(LISTA **testa)/*funzione per cancellare la coda della lista=======================================================================*/
{
     if (testa != NULL)            /*se la lista non è vuota*/
     {
          LISTA *temp;             /*dichiaro unpuntatore*/
          temp = *testa;           /*lo pongo uguale alla testa*/
          if (temp->next == NULL)  /*se il primo elemento è la coda*/
          {
               *testa = NULL;      /*faccio puntare la testa a null e dealloco memoria*/
               free(temp);
          }
          else                     /*se la coda non coincide con la testa*/
          {
               while (temp->next->next != NULL)   /*fino a che il successivo del successivo del puntatore non è NULL*/
                    temp = temp->next;  /*porto avanti il puntatore*/
               free(temp->next);        /*quando trovo l'ultimo dealloco la la memoria*/
               temp->next = NULL;
          }
     }
}
void canc_elem_input_lista(LISTA **testa, tipo_elemento x)/*funzione per cancellare un elemento nella lista=======================================================================*/
{
     LISTA *temp, *pos;  /*puntatori a lista*/
     temp = *testa;      /*li pongo uguali alla testa della lista*/
     pos = temp;

     if (temp==NULL)     /*se la lista è vuota esco*/
          return;
     /* se devo eliminare primo elemento della lista */
     if (temp->elem == x)         /*se il primo elemento è quello che cerco*/
     {
          *testa = (*testa)->next; /*porto avanti la testa*/
          free(temp);                   /*dealloco la memoria*/
          return;                       /*ed esco*/
     }
     while(temp->next && temp->next->elem != x)   /*se è in mezzo alla lista*/
     temp = temp->next;                           /*porto avanti il puntatore*/
     if (temp->next && temp->next->elem == x)     /*se lo trovo*/
     {
          pos = temp->next;                       /*salvo la posizione*/
          temp->next = temp->next->next;          /*sposto il puntatore*/
          free(pos);                              /*libero la memoria*/
     }
}
