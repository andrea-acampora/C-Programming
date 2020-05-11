#ifndef ARRAYDINLIBRARY_H_INCLUDED
#define ARRAYDINLIBRARY_H_INCLUDED
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




#endif // ARRAYDINLIBRARY_H_INCLUDED
