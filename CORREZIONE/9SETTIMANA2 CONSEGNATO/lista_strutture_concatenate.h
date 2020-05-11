#include <stdio.h>
#define NOME 50
struct libro
{
    char titolo[NOME];
    char autore[NOME];
    int annoPubblicazione;
    char casaEditrice[NOME];
    int numeroPagine;
    char genere[NOME];
    int codice;
    int valutazione;
};

typedef struct libro TipoElemLista;

/*Definisco il tipo "StructLista" con all'interno un intero e un puntatore di tipo "StructLista"*/
struct StructLista
{
    TipoElemLista info;
    struct StructLista *next;
};

typedef struct StructLista TipoNodoLista;

typedef TipoNodoLista *TipoLista; /*E' puntatore a struttura di tipo "TipoNodoLista"*/

/*Prototipi delle funzioni*/
void InitLista(TipoLista *lis);
void InserisciTestaLista(TipoLista*lis);
void inserisci_dopo_elemento(TipoLista *lis,int cercato);
void InserisciCodaLista(TipoLista *lis);
void CancellaPrimoLista(TipoLista *lis);
void CancLista(TipoLista *lis,int cercato);
void cancella_ultimo_elemento(TipoLista*lis);

void inserisci_info(TipoLista *lis,TipoLista paux);



