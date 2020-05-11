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

#ifndef LISTE_STATICHE_H_INCLUDED
#define LISTE_STATICHE_H_INCLUDED


/*=====INCLUSIONE LIBRERIE==============================================================================================================*/
#include <stdlib.h>
#include <stdio.h>



/*=====DEFINE==============================================================================================================*/
#define EMPTY (-1)
#define UNDEFINED (-2)
#define M (10)



/*=====TYPEDEF==============================================================================================================*/
typedef int tipo_elemento;

typedef struct {
     tipo_elemento elem[M];
     int last_elem;
}LISTA_STATICA;



/*=====PROTOTIPI FUNZIONI==============================================================================================================*/
int isFull_static(const LISTA_STATICA *);
int isEmpty_static(const LISTA_STATICA *);
int End_static(const LISTA_STATICA *);
int LocateElem_static(const LISTA_STATICA *list, tipo_elemento x);

void StampaLista_static(LISTA_STATICA, int);

void ins_testa_static(LISTA_STATICA *list);
void ins_coda_static(LISTA_STATICA *list);
void ins_elem_static(LISTA_STATICA *list);
void canc_testa_static(LISTA_STATICA *list);
void canc_coda_static(LISTA_STATICA *list);
void canc_elem_static(LISTA_STATICA *list);

#endif // LISTE_STATICHE_H_INCLUDED
