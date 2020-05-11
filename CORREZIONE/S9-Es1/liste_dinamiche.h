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
          -cancella la prima occorrenza dellâ€™elemento.
     Il programma deve visualizzare lo stato della lista ad inizio
     esecuzione (vuota) e dopo ogni operazione scelta dall'utente.
*/


#ifndef LISTE_DINAMICHE_H_INCLUDED
#define LISTE_DINAMICHE_H_INCLUDED



/*=====INCLUSIONE LIBRERIE==============================================================================================================*/
#include <stdlib.h>
#include <stdio.h>



/*=====DEFINE==============================================================================================================*/
#define EMPTY (-1)
#define UNDEFINED (-2)
#define N (3)

/*=====TYPEDEF==============================================================================================================*/
typedef int tipo_elemento;

typedef struct {
     tipo_elemento *elem;
     int dim;
     int last_elem;
}LISTA_DINAMICA;



/*=====PROTOTIPI FUNZIONI==============================================================================================================*/
int isFull_dinamic(LISTA_DINAMICA *);
int isEmpty_dinamic(const LISTA_DINAMICA *);
int LocateElem_dinamic(const LISTA_DINAMICA *list, tipo_elemento x);

LISTA_DINAMICA CreateList_dinamic();
void ExtendList_dinamic(LISTA_DINAMICA *list);
void StampaLista_dinamic(LISTA_DINAMICA, int last_elem);

void ins_testa_dinamic(LISTA_DINAMICA *list);
void ins_coda_dinamic(LISTA_DINAMICA *list);
void ins_elem_dinamic(LISTA_DINAMICA *list);
void canc_testa_dinamic(LISTA_DINAMICA *list);
void canc_coda_dinamic(LISTA_DINAMICA *list);
void canc_elem_dinamic(LISTA_DINAMICA *list);


#endif // LISTE_DINAMICHE_H_INCLUDED
