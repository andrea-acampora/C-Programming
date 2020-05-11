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
          -cancella la prima occorrenza dell’elemento.
     Il programma deve visualizzare lo stato della lista ad inizio
     esecuzione (vuota) e dopo ogni operazione scelta dall'utente.
*/

#include "liste_dinamiche.h"



/*========================================================================================================*/

int isEmpty_dinamic(const LISTA_DINAMICA *list)  //funzione per il controllo della lista vuota
{
     return(list->last_elem == EMPTY);  //se la lista è vuota viene restituito 0
}


/*========================================================================================================*/


int isFull_dinamic(LISTA_DINAMICA *list)        //funzione per il controllo della lista piena
{
     if (list->last_elem == (list->dim-1))      //se la lista è piena avvisa l'utente
    {
         printf("\nLa lista e\' piena!\n");     //avviso che la funzione è piena
    }
     return(list->last_elem == (list->dim-1));  //se la lista è vuota restituisco 0
}


/*========================================================================================================*/
LISTA_DINAMICA CreateList_dinamic()
{
     LISTA_DINAMICA tmp;

     tmp.elem =NULL;     /*inizializzo a null il puntatore*/
     tmp.dim = 0;        /*pongo = 0 la dimensione del vettore*/
     tmp.last_elem = -1; /*segnalo che il vettore è vuoto*/
     tmp.elem = (tipo_elemento*) malloc (N*sizeof(tipo_elemento));    /*alloco il vettore*/
     if(tmp.elem != NULL )    /*se il puntatore non è nullo*/
     {
          tmp.dim=N;          /*pongo = N la dimensione del vettore*/
          tmp.last_elem = -1;              /*inizializzo la struttura con un valore che  indica che la struttura è vuota*/
          printf("\n\nLista creata\n");
     }
     else
     {
          printf("\nERRORE: memoria non disponibile\n");    /*avviso che non è presente sufficiente memoria*/
     }

     return tmp ; /*restituisco il puntatore alla nuova zona allocata*/
}


void ExtendList_dinamic(LISTA_DINAMICA *list)
{
     list->elem = (tipo_elemento*) realloc (list->elem, 2*(list->dim)*sizeof(tipo_elemento)); /*alloco nuova memoria per la lista, ampliandola*/
     if(list->elem != NULL )  /*se ho allocato memoria*/
     {
          list->dim *= 2;     /*raddoppio lo spazio della lista*/
          printf("La lista era piena ma ora ho raddoppiato lo spazio disponibile!\n\n");
     }
     else
          printf("ERRORE: spazio non allocato");  /*se non sono riuscito ad allocare spazio, avviso dell'errore*/

     return;
}





int LocateElem_dinamic(const LISTA_DINAMICA *list, tipo_elemento x)  //funzione per trovare la posizione di un elemento
{
     int i;         //variabile locale

     if (!isEmpty_dinamic(list))     //se la lista NON è vuota, ovvero se contiene almeno un elemento
     {
          for (i = 0; i <= list->last_elem; i++)  //con un ciclo for scorro tutti gli elementi fino all'ultimo
          {
                if(list->elem[i] == x)  //se trovo l'elemento cercato restituisco la posizione i
                    return i;
          }

     }
     else           //se  la lista è vuota avvisto l'utente
          return(EMPTY);

     return(UNDEFINED);  //se non trovo l'elemento avviso l'utente
}


/*========================================================================================================*/


void StampaLista_dinamic(LISTA_DINAMICA list, int last_elem)         //funzione per la stampa della lista e del suo stato
{
     int i;
     if (!isEmpty_dinamic(&list))     //se la lista non è vuota, stampo i suoi elementi
     {
          printf("\nGli elementi della lista sono: ");
          for (i = 0; i <= last_elem; i++)   //con un cilo for scorro gli elementi
          {
               printf("%d  ", list.elem[i]); //stampo gli elementi
          }
     }
     else      //se la lista dovesse essere vuota, allora avviso l'utente
     {
          printf("\nStato della lista: VUOTA\n");
     }

     return;
}


/*========================================================================================================*/


void ins_testa_dinamic(LISTA_DINAMICA *list)        //funzione per l'inserimento in testa
{
     int x_elem, x_position = 0;   //variabili locali
     int i;


     printf("\n\n");
     StampaLista_dinamic(*list, list->last_elem);         //stampo lo stato della lista prima di eseguire la funzione
     printf("\n\n");

     if (isFull_dinamic(list))       //se la lista non è piena
     {
           ExtendList_dinamic(list);
     }

          printf("\nInserire l'elemento da aggiungere alla lista: >> ");        //chiedo che elemento inserire in testa
          scanf("%d", &x_elem);                                                 //prendo in input l'elemento

          if (isEmpty_dinamic(list))  //se la lista è vuota inserisco l'elemento nella prima posizione
          {
               list->elem[0] = x_elem;  //assegno alla posizione 0 l'elemento
               list->last_elem ++;      //incremento il valore che indica la posizione dell'ultimo elemento
          }
          else      //invece se la lista non è vuota
          {
               for (i = list->last_elem; i >= x_position ; i--)       //con un ciclo for
               {
                    list->elem[i+1] = list->elem[i];             //sposto avanti di una posizione tutti gli elementi
               }

               list->elem[0] = x_elem;       /* in prima posizione inserisco l'elemento digitato dall'utente */
               list->last_elem ++;           /* incremento il valore che indica la posizione dell'ultimo eleento */
          }

          StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
          printf("\n\n");

     return;
}


/*========================================================================================================*/


void ins_coda_dinamic(LISTA_DINAMICA *list) /*funzione per l'inserimento in coda*/
{
     int x_elem;    /*variabili locali*/

     printf("\n\n");
     StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
     printf("\n");

     if (isFull_dinamic(list))       /*se la lista non è piena*/
     {
           ExtendList_dinamic(list);
     }

          printf("\nInserire l'elemento da aggiungere alla lista: >> ");/*chiedo l'elemento da inserire in coda*/
          scanf("%d", &x_elem);    /*prendo in input il valore*/

          if (isEmpty_dinamic(list))  /*se la lista è vuota inserisco il valore in prima posizione*/
          {
               list->elem[0] = x_elem;  /*assegno alla prima posizione l'elemento */
               list->last_elem ++;      /*incremento il valore che indica la posizione dell'ultimo elemento*/
          }
          else                /*se la lista non è vuota*/
          {
               list->elem[list->last_elem+1] = x_elem;      /*inserisco l'elemento in ultima posizione*/
               list->last_elem ++;                          /*incremento il valore che indica la posizione dell'ultimo elemento*/
          }

          StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
          printf("\n\n");

     return;
     }


/*========================================================================================================*/


void ins_elem_dinamic(LISTA_DINAMICA *list)   /*funzione per l'inserimento di un elemento in seguito ad un altro*/
{
     int x_position, x_elem;  /*variabili locali*/
     int i;


     printf("\n\n");
     StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
     printf("\n");

      if (isFull_dinamic(list))       /*se la lista non è piena*/
      {
           ExtendList_dinamic(list);
      }

     printf("Inserire il valore dopo cui inserire l'elemento: >> ");  /*chiedo all'utente dopo quale valore inserire il nuovo elemento*/
     scanf("%d", &x_elem);         /*prendo in input il valore*/

     x_position = LocateElem_dinamic(list, x_elem);       /*richiamo la funzione locate che individua l'esatta posizione dell'elemento*/
     if (x_position >= 0)                         /*se la posizione è >-1*/
     {
          printf("\nInserire l'elemento da aggiungere alla lista: >> ");   /*prendo in input il nuovo elemento da inserire*/
          scanf("%d", &x_elem);
          for (i = list->last_elem; i > x_position; i--)         /*scorro gli elementi della lista a partire dall'ultimo fino a quello successivo rispetto a quello trovato*/
          {
               list->elem[i+1] = list->elem[i];        /*sposto avanti di una posizione gli elementi successivi al valore indicato*/
          }
          list->elem[x_position+1] = x_elem;           /*inserisco nella posizione indicata il valore dell'utente*/
          list->last_elem ++;                          /*incremento il valore che indica la posizione dell'ultimo elemento*/
          StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
          printf("\n\n");

     }
     else if (x_position == -1)
     {
          printf("La lista e\' vuota\n\n");
     }
     else {printf("Elemento non presente nella lista\n\n");}
     return;
} /*ins_elem_static*/


/*========================================================================================================*/


void canc_testa_dinamic(LISTA_DINAMICA *list)  /*funzione per il cancellamento in testa dell'elemento*/
{
     int i = 0;     /*variabili locali*/

     printf("\n\n");
     StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
     printf("\n");

     if (isEmpty_dinamic(list))                 /*se la lista è vuota*/
     {
         printf("La lista e\' gia\' vuota!");     /*non faccio nulla e avviso l'utente*/
     }
     else                /*altrimenti*/
     {
          for (i = 0; i <= list->last_elem ; i++)      /*scorro tutti gli elementi dal primo all'ultimo*/
          {
               list->elem[i] = list->elem[i+1];        /*e li sposto indietro di una posizione*/
          }

          list->last_elem --;                     /*decremento il valore che indica la posizione dell'ultimo elemento*/
          StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
     }

     printf("\n\n");

     return;
}

/*========================================================================================================*/



void canc_coda_dinamic(LISTA_DINAMICA *list)        /*funzione per il cancellamento dell'elemento in coda*/
{
     printf("\n\n");
     StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
     printf("\n");

     if (isEmpty_dinamic(list))                           /*se la lista è vuota*/
     {
         printf("La lista e\' gia\' vuota!");     /*non eseguo alcun istruzione e avviso l'utente*/
     }
     else                                    /*altrimenti*/
     {
          list->last_elem--;                      /*decremento il valore che indica la posizione dell'ultimo elemento*/
          StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
     }

     printf("\n\n");

     return;
}


/*========================================================================================================*/


void canc_elem_dinamic(LISTA_DINAMICA *list)        /*funzione per cancellare un elemento dalla lista in qualsiasi posizione*/
{
     int x_position, x_elem;  /*variabili locali*/
     int i = 0;

     printf("\n\n");
     StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
     printf("\n");

     if (isEmpty_dinamic(list))       /*se la lista è vuota*/
     {
         printf("La lista e\' gia\' vuota!");     /*avviso l'utente e non effettuo operazioni*/
     }
     else                     /*altrimenti se la lista contiene elementi*/
     {
          printf("Inserire l'elemento da cancellare: >> ");      /*chiedo che elemento vuole cancellare*/
          scanf("%d", &x_elem);                                  /*prendo in input tale valore*/

          x_position = LocateElem_dinamic(list, x_elem);                 /*trovo la posizione dell'elemento tramite la funzione locate*/
          if (x_position >= 0)
          {
               for (i = x_position; i <= list->last_elem ; i++)  /*scorro gli elementi da quello trovao all'ultimo*/
               {
                    list->elem[i] = list->elem[i+1];             /*e sposto indietro di una posizione tali elementi*/
               }

               list->last_elem --;                      /*decremento il valore che indica la posizione dell'ultimo elemento*/
               StampaLista_dinamic(*list, list->last_elem);    /* stampo nuovamente lo stato della lista */
          }
     }

     printf("\n\n");

     return;
}

