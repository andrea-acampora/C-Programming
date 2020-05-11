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

/*inclusione delle librerie*/
#include "liste_statiche.h"
#include "liste_dinamiche.h"
#include "liste_collegate.h"

#include <stdlib.h>
#include <stdio.h>

int main() /*======================MAIN================*/
{
     int code;


     for(;;)   //ciclo for per permettere all'utente di decidere quale tipologia di lista utilizzare
     {
          system("cls"); //cancello l'output visualizzato
          printf("Inserire il codice relatico al tipo di lista da utilizzare\n");
          printf("\t1) per LISTE STATICHE\n\t2) per LISTE DINAMICHE\n\t3) per LISTE COLLEGATE\n\t0) per USCIRE\n>> ");
          scanf("%d", &code);      /*prendo in input il codice relativo all'operazione*/

          switch (code)  /*===----SWITCH PER SCELTA TIPO LISTA-------------------------------------------===*/
          {
               case 0: {return 0;};     /*Se viene inserito 0 esco dal ciclo for*/

               case 1:   /*=================LISTE STATICHE=============================================================================*/
               {
                    LISTA_STATICA lista;          /*dichiaro un dato di tipo LISTA_STATICA, ovvero di tipo struttura*/
                    LISTA_STATICA *p_lista = &lista;   /*dichiaro un puntatore a struttura (LISTA STATICA) e assegno l'indirizzo della struttura*/
                    lista.last_elem = -1;         /*inizializzo la struttura con un valore che  indica che la struttura � vuota*/



                    for(;;)                       /*con un ciclo che esce solo per valore = 0 mostro il menu*/
                    {
                         system("cls");           /*pulisco lo schermo*/
                         printf("Inserire il codice relativo all'operazione\n");
                         printf("\t1) per INSERIRE in TESTA\n\t2) per INSERIRE in CODA\n\t3) per INSERIRE DOPO un certo ELEMENTO\n\t4) per CANCELLARE dalla testa\n\t5) per CANCELLARE dalla coda\n\t6) per CANCELLARE la prima occorrenza dell'ELEMENTO INSERITO\n\t0) per USCIRE\n>> ");
                         scanf("%d", &code);      /*prendo in input il codice relativo all'operazione*/

                         switch (code) /* Switch per scelta operaazione su liste statiche*/
                         {
                              case 0: {return 0;};     /*se l'utente inserisce 0 esco dall'esecuzione*/

                              case 1:                  /*se l'utente inserisce 1 */
                              {
                                   ins_testa_static(p_lista);    /*richiamo la funzione per inserire in testa*/
                                   system("pause");
                                   break;
                              };

                              case 2:                  /*se l'utente inserisce 2*/
                              {
                                   ins_coda_static(p_lista);     /*richiamo la funzione per inserire in coda*/
                                   system("pause");
                                   break;
                              };

                              case 3:                  /*se l'utente inserisce 3*/
                              {
                                   ins_elem_static(p_lista);     /*richiamo la funzione per inserire un elemento a scelta*/
                                   system("pause");
                                   break;
                              };

                              case 4:                  /*se l'utente inserisce 4*/
                              {
                                   canc_testa_static(p_lista);   /*richiamo la funzione per cancellare in testa*/
                                   system("pause");
                                   break;
                              };

                              case 5:                  /*se l'utente inserisce 5*/
                              {
                                   canc_coda_static(p_lista);    /*richiamo la funzione per cancellare in coda*/
                                   system("pause");
                                   break;
                              };

                              case 6:                  /*se l'utente inserisce 6*/
                              {
                                   canc_elem_static(p_lista);    /*richiamo la funzione per cancellare un elemento a scelta*/
                                   system("pause");
                                   break;
                              };

                              default:                 /*se l'utente inserisce qualsiasi altro codice segnalo l'errore e faccio inserire di nuovo*/
                              {
                                   printf("\n\n");
                                   printf("Il codice inserito non e\' valido, reinserirlo.\n\n");
                                   system("pause");
                              };
                         }
                    }
                    return 0;
               };





               case 2:   /*=================LISTE DINAMICHE=============================================================================*/
               {
                    LISTA_DINAMICA lista;               /*dichiaro un dato di tipo LISTA_STATICA, ovvero di tipo struttura*/
                    lista = CreateList_dinamic();      /*creo la lista*/
                    system("pause");



                    for(;;)                       /*con un ciclo che esce solo per valore = 0 mostro il menu*/
                    {
                         system("cls");           /*pulisco lo schermo*/
                         printf("Inserire il codice relativo all'operazione\n");
                         printf("\t1) per INSERIRE in TESTA\n\t2) per INSERIRE in CODA\n\t3) per INSERIRE DOPO un certo ELEMENTO\n\t4) per CANCELLARE dalla testa\n\t5) per CANCELLARE dalla coda\n\t6) per CANCELLARE la prima occorrenza dell'ELEMENTO INSERITO\n\t0) per USCIRE\n>> ");
                         scanf("%d", &code);      /*prendo in input il codice relativo all'operazione*/

                         switch (code) /* Switch per scelta operaazione su liste dinamiche*/
                         {
                              case 0:             /*se l'utente inserisce 0 esco dall'esecuzione*/
                              {
                                   if (lista.elem != NULL)
                                        free(lista.elem);        /*dealloco la memoria*/
                                   return 0;
                              };

                              case 1:                  /*se l'utente inserisce 1 */
                              {
                                   ins_testa_dinamic(&lista);    /*richiamo la funzione per inserire in testa*/
                                   system("pause");
                                   break;
                              };

                              case 2:                  /*se l'utente inserisce 2*/
                              {
                                   ins_coda_dinamic(&lista);     /*richiamo la funzione per inserire in coda*/
                                   system("pause");
                                   break;
                              };

                              case 3:                  /*se l'utente inserisce 3*/
                              {
                                   ins_elem_dinamic(&lista);     /*richiamo la funzione per inserire un elemento a scelta*/
                                   system("pause");
                                   break;
                              };

                              case 4:                  /*se l'utente inserisce 4*/
                              {
                                   canc_testa_dinamic(&lista);   /*richiamo la funzione per cancellare in testa*/
                                   system("pause");
                                   break;
                              };

                              case 5:                  /*se l'utente inserisce 5*/
                              {
                                   canc_coda_dinamic(&lista);    /*richiamo la funzione per cancellare in coda*/
                                   system("pause");
                                   break;
                              };

                              case 6:                  /*se l'utente inserisce 6*/
                              {
                                   canc_elem_dinamic(&lista);    /*richiamo la funzione per cancellare un elemento a scelta*/
                                   system("pause");
                                   break;
                              };

                              default:                 /*se l'utente inserisce qualsiasi altro codice segnalo l'errore e faccio inserire di nuovo*/
                              {
                                   printf("\n\n");
                                   printf("Il codice inserito non e\' valido, reinserirlo.\n\n");
                                   system("pause");
                              };
                         }
                    }
                    return 0;
               };





               case 3:   /*=================LISTE COLLEGATE=============================================================================*/
               {
                    LISTA *testa;  /*dichiaro un puntatore alla testa della lista*/
                    testa = NULL;  /*pongo la testa a null*/

                    tipo_elemento x_elem, x_position;

                    for(;;)                       /*con un ciclo che esce solo per valore = 0 mostro il menu*/
                    {
                         system("cls");           /*pulisco lo schermo*/
                         printf("Inserire il codice relativo all'operazione\n");
                         printf("\t1) per INSERIRE in TESTA\n\t2) per INSERIRE in CODA\n\t3) per INSERIRE DOPO un certo ELEMENTO\n\t4) per CANCELLARE dalla testa\n\t5) per CANCELLARE dalla coda\n\t6) per CANCELLARE la prima occorrenza dell'ELEMENTO INSERITO\n\t0) per USCIRE\n>> ");
                         scanf("%d", &code);      /*prendo in input il codice relativo all'operazione*/

                         switch (code) /* Switch per scelta operaazione su liste collegate*/
                         {
                              case 0:
                              {
                                   free(testa); /*libero la memoria e esco*/
                                   return 0;
                              };     /*se l'utente inserisce 0 esco dall'esecuzione*/

                              case 1:                  /*se l'utente inserisce 1 */
                              {
                                   stampa_lista(testa);     /*stampo la lista*/

                                   printf("\nInserire l'elemento da aggiungere alla lista: >> ");   /*prendo in input il nuovo elemento da inserire*/
                                   scanf("%d", &x_elem);

                                    ins_testa_lista(&testa, x_elem);    /*richiamo la funzione per inserire in testa*/

                                   stampa_lista(testa);     /*stampo la lista*/

                                   system("pause");
                                   break;
                              };

                              case 2:                  /*se l'utente inserisce 2*/
                              {
                                   stampa_lista(testa);     /*stampo la lista*/

                                   printf("\nInserire l'elemento da aggiungere alla lista: >> ");   /*prendo in input il nuovo elemento da inserire*/
                                   scanf("%d", &x_elem);

                                   ins_coda_lista(&testa, x_elem);     /*richiamo la funzione per inserire in coda*/

                                   stampa_lista(testa);/*stampo la lista*/

                                   system("pause");
                                   break;
                              };

                              case 3:                  /*se l'utente inserisce 3*/
                              {
                                   stampa_lista(testa);/*stampo la lista*/

                                   if (testa == NULL)  /*se la lista è vuota, esco*/
                                   {
                                        printf("La lista e\' vuota!\n\n");
                                        system("pause");
                                        break;
                                   }

                                   printf("\nInserire l'elemento da aggiungere alla lista: >> ");   /*prendo in input il nuovo elemento da inserire*/
                                   scanf("%d", &x_elem);

                                   printf("\nDopo quale elemento lo vuoi aggiungere alla lista?: >> ");   /*prendo in input la posizione dell'elemento da inserire*/
                                   scanf("%d", &x_position);

                                   ins_elem_input_lista(testa, x_elem, x_position);     /*richiamo la funzione per inserire un elemento a scelta*/

                                   stampa_lista(testa);/*stampo la lista*/

                                   system("pause");
                                   break;
                              };

                              case 4:                  /*se l'utente inserisce 4*/
                              {
                                   stampa_lista(testa);     /*stampo la lista*/
                                   if (testa != NULL)
                                   {
                                        canc_testa_lista(&testa); /*richiamo la funzione per cancellare in testa*/

                                        stampa_lista(testa);     /*stampo la lista*/
                                        system("pause");
                                        break;
                                   }
                              };

                              case 5:                  /*se l'utente inserisce 5*/
                              {
                                   stampa_lista(testa);     /*stampo la lista*/
                                   if (testa != NULL)       /*se la lista contiene almeno un elemento*/
                                   {
                                        canc_coda_lista(&testa);    /*richiamo la funzione per cancellare in coda*/
                                        stampa_lista(testa);     /*stampo la lista*/
                                        system("pause");
                                        break;
                                   }
                              };

                              case 6:                  /*se l'utente inserisce 6*/
                              {
                                   stampa_lista(testa);     /*stampo la lista*/
                                   printf("\nInserire l'elemento da cancellare dalla lista: >> ");   /*prendo in input il nuovo elemento da inserire*/
                                   scanf("%d", &x_elem);
                                   canc_elem_input_lista(&testa, x_elem);    /*richiamo la funzione per cancellare un elemento a scelta*/
                                   stampa_lista(testa);     /*stampo la lista*/
                                   system("pause");
                                   break;
                              };

                              default:                 /*se l'utente inserisce qualsiasi altro codice segnalo l'errore e faccio inserire di nuovo*/
                              {
                                   printf("\n\n");
                                   printf("Il codice inserito non e\' valido, reinserirlo.\n\n");
                                   system("pause");
                              };
                         }
                    }
                    return 0;
               };

     return 0;
          }
     }return 0;
}
