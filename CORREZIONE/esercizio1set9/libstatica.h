#ifndef LIBSTATICA_H_INCLUDED
#define LIBSTATICA_H_INCLUDED
#define DIM 20
#define UNDEFINED -2
#define EMPTYLIST -1
#include "dato.h"

//definizione struttura per lista con array statico
typedef struct{
    TipoDato dati[DIM];
    int last;
}TipoLista;

//dichiarazione funzioni per lista utilizzando array statico
void initListaStatica(TipoLista *lista);
void inserisciInTestaStatico(TipoLista *lista,TipoDato dato);
void inserisciInCodaStatico(TipoLista *lista,TipoDato dato);
void inserisciDopoPosizioneStatico(TipoLista *lista,TipoDato dato,int posizione);
void cancellaDaTestaStatico(TipoLista *lista);
void cancellaDaCodaStatico(TipoLista *lista);
void cancellaOccorrenzaStatico(TipoLista *lista,TipoDato dato);
int fullStatico(const TipoLista *lista);
int cerca(const TipoLista *lista,TipoDato dato);
int emptyStatico(const TipoLista *lista);
void statoListaStatica(const TipoLista *lista);

#endif // LIBSTATICA_H_INCLUDED
