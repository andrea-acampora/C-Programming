/*Implementare il tipo di dato astratto LISTA sia tramite allocazione
indicizzata (vettore statico e vettore dinamico) che tramite strutture
collegate. Le funzioni che dovranno essere implementate sono: inserisci in
testa, inserisci in coda, inserisci dopo un certo elemento, cancella dalla
testa, cancella dalla coda, cancella la prima occorrenza dell’elemento.
Il programma deve visualizzare lo stato della lista ad inizio esecuzione (vuota)
e dopo ogni operazione scelta dall'utente.
Considerare la lista come una struct contenete una semplice variabile int
 e organizzare le funzioni per gestire la variabile di questo tipo.
 Consegnare un file .zip contenete tutti i file .c e .h.*/
 /**------------------------------------------------------------------------**/

/*  N.B.
    lista_is --> lista indicizzata statica
    lista_id --> lista indicizzata dinamica
    lista_sc --> lista strutture collegate */

#include <stdio.h>
#include <stdlib.h>
#include "hdr_lista_is.h"
#include "hdr_lista_id.h"
#include "hdr_lista_sc.h"
#define MAX 10

int main()
{
    /**    DICHIARAZIONI    **/
    int scelta_lista; //quale tipo di lista usare
    int scelta_operaz; //quale operazione compiere

    /**     SCELTA TIPO DI LISTA     **/
    printf("scegliere tipo lista da utilizzare\n0 -> indicizz. statica\n1 -> indicizz. dinamica\n2 -> strutture collegate\n\n");
    scanf("%1d",&scelta_lista); //i controlli ci sono dopo

    /**     INIT LISTA      **/
    lista_is is = init_is();
    lista_id id = init_id();
    lista_sc *sc = init_sc();

    /**     CICLO DI ESECUZIONE     **/
    do
    {
        system("cls");
        puts("lista attuale:");
        switch(scelta_lista)
        {
            case 0: stampa_is(0,MAX,is); break;
            case 1: stampa_id(0,id.size,id); break;
            case 2: stampa_sc(sc); break;
        }
        printf("\n\ninserire codice operazione da effettuare\n0 --> termina programma\n1 --> inserisci in testa\n2 --> inserisci in coda\n3 --> inserisci dopo un certo elemento\n4 --> cancella dalla testa \
               \n5 --> cancella dalla coda\n6 --> cancella la prima occorrenza dell\'elemento\n\n");

        scanf("%1d",&scelta_operaz);

        /* -- CHIUSURA -- */
        if(scelta_operaz==0)
        {
            system("cls");
            /*FREE*/
            free(id.val);
            free(sc);
            puts("\n\nchiusura. premere invio per terminare\n");
            getchar();
        }
        /* -- INSERIMENTO IN TESTA -- */
        else if(scelta_operaz==1)
        {
            if(scelta_lista==0)
            {
                is = ins_testa_is(is);
            }
            else if(scelta_lista==1)
            {
                id = ins_testa_id(id);
            }
            else if(scelta_lista==2)
            {
                sc = ins_testa_sc(sc);
            }
        }
        /* -- INSERIMENTO IN CODA -- */
        else if(scelta_operaz==2)
        {
            if(scelta_lista==0)
            {
                is = ins_coda_is(is);
            }
            else if(scelta_lista==1)
            {
                id = ins_coda_id(id);
            }
            else if(scelta_lista==2)
            {
                sc = ins_coda_sc(sc);
            }
        }
        /* -- INSERIMENTO DOPO ELEMENTO -- */
        else if(scelta_operaz==3)
        {
            if(scelta_lista==0)
            {
                is = ins_dopoel_is(is);
            }
            else if(scelta_lista==1)
            {
                id = ins_dopoel_id(id);
            }
            else if(scelta_lista==2)
            {
                sc = ins_dopoel_sc(sc);
            }
        }
        /* -- CANCELLAZIONE DALLA TESTA -- */
        else if(scelta_operaz==4)
        {
            if(scelta_lista==0)
            {
                is = canc_testa_is(is);
            }
            else if(scelta_lista==1)
            {
                id = canc_testa_id(id);
            }
            else if(scelta_lista==2)
            {
                sc = canc_testa_sc(sc);
            }
        }
        /* -- CANCELLAZIONE DALLA CODA -- */
        else if(scelta_operaz==5)
        {
            if(scelta_lista==0)
            {
                is = canc_coda_is(is);
            }
            else if(scelta_lista==1)
            {
                id = canc_coda_id(id);
            }
            else if(scelta_lista==2)
            {
                sc = canc_coda_sc(sc);
            }
        }
        /* -- CANCELLA PRIMA OCCORRENZA -- */
        else if(scelta_operaz==6)
        {
            if(scelta_lista==0)
            {
                is = canc_elem_is(is);
            }
            else if(scelta_lista==1)
            {
                id = canc_elem_id(id);
            }
            else if(scelta_lista==2)
            {
                sc = canc_elem_sc(sc);
            }
        }
        /* -- INPUT NON CORRETTO -- */
        else
        {
            puts("\ninput non corretto! premere invio, quindi riprovare:\n");
            fflush(stdin);
            getchar();
        }
    }
    while(scelta_operaz!=0);
}
