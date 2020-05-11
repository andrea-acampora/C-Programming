#ifndef LIBRARY3_H_INCLUDED
#define LIBRARY3_H_INCLUDED
#define EMPTY (-1)
#define UNDEFINED (-2)
#define N (3)
#include <stdio.h>
#include <stdlib.h>

/**LIBRERIA PER CODA IMPLEMENTATA CON VETTORE DINAMICO**/

typedef int tipo_elemento;

typedef struct{
     tipo_elemento *elem;
     int dim;
     int last_elem;
}CODA_DINAMICA;

CODA_DINAMICA CreateList_dinamic();
/*=====PROTOTIPI FUNZIONI=================*/
int IsEmpty_dinamic(const CODA_DINAMICA *codaDin);
int isFullDinamic(CODA_DINAMICA *codaDin);
void PushDinamic(CODA_DINAMICA *codaDin);
void PopDinamic(CODA_DINAMICA *codaDin);
void PrintDinamic(CODA_DINAMICA *codaDin);
void ResetDinamic(CODA_DINAMICA *codaDin);
void ExtendDinamic(CODA_DINAMICA *codaDin);
#endif // LIBRARY3_H_INCLUDED
