#ifndef ARRAYSTATLIBRARY_H_INCLUDED
#define ARRAYSTATLIBRARY_H_INCLUDED
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

