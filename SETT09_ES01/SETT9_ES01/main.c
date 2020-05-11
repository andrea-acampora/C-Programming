#include "StructLibrary.h"
#include "ArrayDinLibrary.h"
#include "ArrayStatLibrary.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
int scelta;
for(;;)//ciclo for per permettere all'utente di decidere quale tipologia di lista utilizzare
     {
          system("cls"); //cancello l'output visualizzato
          printf("SCEGLIERE LA MODALITA':\n\n\n");
          printf("1-LISTA IMPLEMENTATA CON ARRAY STATICO\n\n2-LISTA IMPLEMENTATA CON VETTORE DINAMICO\n\n3-LISTA IMPLEMENTATA CON STRUTTURE COLLEGATE\n\n0-USCIRE DAL PROGRAMMA\n\n>> ");
          scanf("%d",&scelta);
          switch (scelta)
          {
               case 0:{return 0;};/*Se viene inserito 0 esco dal ciclo for*/

               case 1://LISTE STATICHE
               {
                    LISTA_STATICA lista;
                    LISTA_STATICA *p_lista = &lista;
                    lista.last_elem = -1;
                    for(;;)
                    {
                         system("cls");
                         printf("SCEGLIERE COSA EFFETTUARE\n\n");
                         printf("\t1)INSERIRE IN TESTA\n\t2)INSERIRE IN CODA\n\t3)INSERIRE DOPO UN CERTO ELEMENTO\n\t4)CANCELLARE DALLA TESTA\n\t5)CANCELLARE DALLA CODA\n\t6)CANCELLARE LA PRIMA OCCORRENZA DELL'ELEMENTO\n\t0)USCIRE\n>> ");
                         scanf("%d", &scelta);

                         switch (scelta) /*Switch per scelta operazione su liste statiche*/
                         {
                              case 0: {return 0;};

                              case 1:
                              {
                                   ins_testa_static(p_lista);
                                   system("pause");
                                   break;
                              };

                              case 2:
                              {
                                   ins_coda_static(p_lista);
                                   system("pause");
                                   break;
                              };

                              case 3:
                              {
                                   ins_elem_static(p_lista);
                                   system("pause");
                                   break;
                              };

                              case 4:
                              {
                                   canc_testa_static(p_lista);
                                   system("pause");
                                   break;
                              };

                              case 5:
                              {
                                   canc_coda_static(p_lista);    /*richiamo la funzione per cancellare in coda*/
                                   system("pause");
                                   break;
                              };

                              case 6:
                              {
                                   canc_elem_static(p_lista);    /*richiamo la funzione per cancellare un elemento a scelta*/
                                   system("pause");
                                   break;
                              };

                              default:                 /*se l'utente inserisce qualsiasi altro codice segnalo l'errore e faccio inserire di nuovo*/
                              {
                                   printf("\n\n");
                                   printf("CODICE INSERITO NON CORRETTO, RIPROVARE\n\n");
                                   system("pause");
                              };
                         }
                    }
                    return 0;
               };





               case 2:
               {
                    LISTA_DINAMICA lista;               /*dichiaro un dato di tipo LISTA_STATICA, ovvero di tipo struttura*/
                    lista = CreateList_dinamic();      /*creo la lista*/
                    system("pause");



                    for(;;)
                    {
                         system("cls");
                         printf("SCEGLIERE COSA EFFETTUARE\n\n");
                         printf("\t1)INSERIRE IN TESTA\n\t2)INSERIRE IN CODA\n\t3)INSERIRE DOPO UN CERTO ELEMENTO\n\t4)CANCELLARE DALLA TESTA\n\t5)CANCELLARE DALLA CODA\n\t6)CANCELLARE LA PRIMA OCCORRENZA DELL'ELEMENTO\n\t0)USCIRE\n>> ");
                         scanf("%d", &scelta);
                         switch (scelta) /* Switch per scelta operaazione su liste dinamiche*/
                         {
                              case 0:
                              {
                                   if (lista.elem != NULL)
                                        free(lista.elem);        /*dealloco la memoria*/
                                   return 0;
                              };

                              case 1:
                              {
                                   ins_testa_dinamic(&lista);    /*richiamo la funzione per inserire in testa*/
                                   system("pause");
                                   break;
                              };

                              case 2:
                              {
                                   ins_coda_dinamic(&lista);     /*richiamo la funzione per inserire in coda*/
                                   system("pause");
                                   break;
                              };

                              case 3:
                              {
                                   ins_elem_dinamic(&lista);     /*richiamo la funzione per inserire un elemento a scelta*/
                                   system("pause");
                                   break;
                              };

                              case 4:
                              {
                                   canc_testa_dinamic(&lista);   /*richiamo la funzione per cancellare in testa*/
                                   system("pause");
                                   break;
                              };

                              case 5:
                              {
                                   canc_coda_dinamic(&lista);    /*richiamo la funzione per cancellare in coda*/
                                   system("pause");
                                   break;
                              };

                              case 6:
                              {
                                   canc_elem_dinamic(&lista);    /*richiamo la funzione per cancellare un elemento a scelta*/
                                   system("pause");
                                   break;
                              };

                              default:                 /*se l'utente inserisce qualsiasi altro codice segnalo l'errore e faccio inserire di nuovo*/
                              {
                                   printf("\n\n");
                                   printf("CODICE INSERITO NON CORRETTO, RIPROVARE!\n\n");
                                   system("pause");
                              };
                         }
                    }
                    return 0;
               };

               case 3:
               {
                    LISTA *testa;  /*dichiaro un puntatore alla testa della lista*/
                    testa = NULL;  /*pongo la testa a null*/

                    tipo_elemento x_elem, x_position;

                    for(;;)
                    {
                         system("cls");
                         printf("SCEGLIERE COSA EFFETTUARE\n\n");
                         printf("\t1)INSERIRE IN TESTA\n\t2)INSERIRE IN CODA\n\t3)INSERIRE DOPO UN CERTO ELEMENTO\n\t4)CANCELLARE DALLA TESTA\n\t5)CANCELLARE DALLA CODA\n\t6)CANCELLARE LA PRIMA OCCORRENZA DELL'ELEMENTO\n\t0)USCIRE\n>> ");
                         scanf("%d", &scelta);

                         switch (scelta)
                         {
                              case 0:
                              {
                                   free(testa); /*libero la memoria e esco*/
                                   return 0;
                              };

                              case 1:
                              {
                                   stampa_lista(testa);     /*stampo la lista*/

                                   printf("\nINSERIRE ELEMENTO DA AGGIUNGERE: >> ");
                                   scanf("%d", &x_elem);

                                    ins_testa_lista(&testa, x_elem);    /*richiamo la funzione per inserire in testa*/

                                   stampa_lista(testa);     /*stampo la lista*/

                                   system("pause");
                                   break;
                              };

                              case 2:
                              {
                                   stampa_lista(testa);     /*stampo la lista*/

                                   printf("\nINSERIRE ELEMENTO DA AGGIUNGERE: >> ");
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
                                        printf("LISTA VUOTA!\n\n");
                                        system("pause");
                                        break;
                                   }

                                   printf("\nINSERIRE ELEMENTO DA AGGIUNGERE: >> ");
                                   scanf("%d", &x_elem);

                                   printf("\nDOPO QUALE ELEMENTO LO VUOI AGGIUNGERE?: >> ");   /*prendo in input la posizione dell'elemento da inserire*/
                                   scanf("%d", &x_position);

                                   ins_elem_input_lista(testa, x_elem, x_position);     /*richiamo la funzione per inserire un elemento a scelta*/

                                   stampa_lista(testa);/*stampo la lista*/

                                   system("pause");
                                   break;
                              };
                            case 4:
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
                              case 5:
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

                              case 6:
                              {
                                   stampa_lista(testa);     /*stampo la lista*/
                                   printf("\nINSERIRE ELEMENTO DA CANCELLARE: >> ");   /*prendo in input il nuovo elemento da inserire*/
                                   scanf("%d", &x_elem);
                                   canc_elem_input_lista(&testa, x_elem);    /*richiamo la funzione per cancellare un elemento a scelta*/
                                   stampa_lista(testa);     /*stampo la lista*/
                                   system("pause");
                                   break;
                              };

                              default:                 /*se l'utente inserisce qualsiasi altro codice segnalo l'errore e faccio inserire di nuovo*/
                              {
                                   printf("\n\n");
                                   printf("CODICE INSERITO NON CORRETTO, RIPROVARE!\n\n");
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
