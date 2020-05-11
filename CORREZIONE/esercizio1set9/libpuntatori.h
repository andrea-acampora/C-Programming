#ifndef LIBPUNTATORI_H_INCLUDED
#define LIBPUNTATORI_H_INCLUDED
#include "dato.h"

typedef int TipoDato;

struct StructLista{
    TipoDato info;
    struct StructLista *next;
};

typedef struct StructLista NodoLista;

void initLista(NodoLista **lista);
void cancellaLista(NodoLista **lista);

void inserisciInTesta(NodoLista **lista,TipoDato dato);
void inserisciInCoda(NodoLista **lista,TipoDato dato);
void inserisciDopoPosizione(NodoLista **lista,TipoDato dato,int posizione);
void cancellaDaTesta(NodoLista **lista);
void cancellaDaCoda(NodoLista **lista);
void cancellaOccorrenza(NodoLista **lista,TipoDato dato);

void statoLista(NodoLista *lista);

int contaElementi(NodoLista *lista);


#endif // LIBPUNTATORI_H_INCLUDED
