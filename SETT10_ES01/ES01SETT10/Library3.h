#ifndef LIBRARY3_H_INCLUDED
#define LIBRARY3_H_INCLUDED
#define EMPTY (-1)
#define UNDEFINED (-2)
#define N (3)
#include <stdio.h>
#include <stdlib.h>

/**LIBRERIA PER PILA IMPLEMENTATA CON VETTORE DINAMICO**/

typedef int tipo_elemento;

typedef struct{
     tipo_elemento *elem;
     int dim;
     int last_elem;
}PILA_DINAMICA;

PILA_DINAMICA CreateList_dinamic();
/*=====PROTOTIPI FUNZIONI=================*/
int IsEmpty_dinamic(const PILA_DINAMICA *pilaDin);
int isFullDinamic(PILA_DINAMICA *pilaDin);
void PushDinamic(PILA_DINAMICA *pilaDin);
void PopDinamic(PILA_DINAMICA *pilaDin);
void PrintDinamic(PILA_DINAMICA *pilaDin);
void ResetDinamic(PILA_DINAMICA *pilaDin);
void ExtendDinamic(PILA_DINAMICA *piladin);
#endif // LIBRARY3_H_INCLUDED
