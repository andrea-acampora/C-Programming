#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define LENGTH 20

//struttura lista
typedef struct cella
{
    char titolo[LENGTH];
    char autore[LENGTH];
    int pubblicazione;
    char casaEditrice[LENGTH];
    char genere[LENGTH];
    int codice;
    int valutazione;
    struct cella*next; //puntatore alla struttura successiva
}struttura;

void stampaLista (struttura*testa);

void stampaValutazione (int valutazione, struttura*testa);

void inserisciLibro(struttura**testa);

void cancellaLibro(struttura**testa, int codice);


#endif // LISTA_H_INCLUDED
