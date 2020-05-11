#ifndef LIBDINAMICA_H_INCLUDED
#define LIBDINAMICA_H_INCLUDED
#define DIM 20
#define UNDEFINED -2
#define EMPTYLIST -1
#include "dato.h"

typedef int TipoDato;

typedef struct{
    TipoDato *dati;
    int dimensione;
    int last;
}TipoListaDinamica;

//dichiarazione funzioni per lista utilizzando array statico
TipoListaDinamica creaListaDinamica();
void eliminaListaDinamica(TipoListaDinamica *lista);
int estendiListaDinamica(TipoListaDinamica *lista);

void inserisciInTestaDinamico(TipoListaDinamica *lista,TipoDato dato);
void inserisciInCodaDinamico(TipoListaDinamica *lista,TipoDato dato);
void inserisciDopoPosizioneDinamico(TipoListaDinamica *lista,TipoDato dato,int posizione);
void cancellaDaTestaDinamico(TipoListaDinamica *lista);
void cancellaDaCodaDinamico(TipoListaDinamica *lista);
void cancellaOccorrenzaDinamico(TipoListaDinamica *lista,TipoDato dato);
int fullDinamico(const TipoListaDinamica *lista);
int cercaDinamico(const TipoListaDinamica *lista,TipoDato dato);
int emptyDinamico(const TipoListaDinamica *lista);

void statoListaDinamica(const TipoListaDinamica *lista);


#endif // LIBDINAMICA_H_INCLUDED
