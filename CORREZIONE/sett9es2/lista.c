#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

//funzione per stampare gli elementi della lista
void stampaLista(struttura*testa)
{
    int i=1;
    struttura*temp; //utilizzo un puntatore d'appoggio per non perdere il riferimento al primo elemento
    temp=testa;
    if (testa==NULL)
        printf("\n Lista vuota\n\n");
    else
    {
        while (temp!=NULL) //scorro tutte le strutture e stampo il contenuto
        {
            printf("\n\tLIBRO %d:", i);
            printf("\n Titolo: %s", temp->titolo);
            printf("\n Autore: %s", temp->autore);
            printf("\n Anno di pubblicazione: %d", temp->pubblicazione);
            printf("\n Casa editrice: %s", temp->casaEditrice);
            printf("\n Genere: %s", temp->genere);
            printf("\n Codice identificativo: %d", temp->codice);
            printf("\n Valutazione: %d", temp->valutazione);
            printf("\n\n");
            i=i+1;
            temp=temp->next;
        }
    }
}

//funzione per stampare gli elementi della lista con una certa valutazione
void stampaValutazione (int valutazione, struttura*testa)
{
    int trovato=0;
    int i=1;
    struttura*temp; //utilizzo un puntatore d'appoggio per non perdere il riferimento al primo elemento
    temp=testa;
    if (testa==NULL)
        printf("\n Lista vuota\n\n");
    else
    {
        while (temp!=NULL) //scorro tutte le strutture
        {
            if (temp->valutazione==valutazione)
            {
                printf("\n\tLIBRO %d:", i);
                printf("\n Titolo: %s", temp->titolo);
                printf("\n Autore: %s", temp->autore);
                printf("\n Anno di pubblicazione: %d", temp->pubblicazione);
                printf("\n Casa editrice: %s", temp->casaEditrice);
                printf("\n Genere: %s", temp->genere);
                printf("\n Codice identificativo: %d", temp->codice);
                printf("\n Valutazione: %d", temp->valutazione);
                printf("\n\n");
                i=i+1;
                trovato=1;
            }
            temp=temp->next;
        }
        if(trovato==0)
            printf("\n Non sono presenti libri con valutazione %d\n\n", valutazione);
    }
}

//funzione per inserire un elemento nella lista
void inserisciLibro(struttura**testa)
{
    struttura*nuovo;
    nuovo=(struttura*)malloc(sizeof(struttura)); //alloco la nuova struttura
    if(nuovo==NULL)//controllo che la struttura sia stata alocata correttamente
    {
        printf("\n Errore:memoria insufficiente. \n");
        exit(0);
    }
    //inserimento dati da tastiera
    printf("\n Codice identificativo: ");
    scanf(" %d", &nuovo->codice);
    fflush(stdin);
    //controllo che il libro non sia già presente
    struttura*temp; //utilizzo un puntatore d'appoggio per non perdere il riferimento al primo elemento
    temp=*testa;
    int trovato=0;
    while (temp!=NULL) //scorro tutte le strutture
    {
        if (temp->codice==nuovo->codice)
        {
            free(nuovo);
            trovato=1;
            printf("\n Libro gia\' presente. \n");
            break;
        }
        temp=temp->next;
    }

    if (trovato==0) //se il libro non è gia\' presente continuo con l'inserimento dei dati
    {
        printf(" Titolo: ");
        scanf(" %s", nuovo->titolo);
        fflush(stdin);
        printf(" Autore: ");
        scanf(" %s", nuovo->autore);
        fflush(stdin);
        printf(" Anno di pubblicazione: ");
        scanf(" %d", &nuovo->pubblicazione);
        fflush(stdin);
        printf(" Casa editrice: ");
        scanf(" %s", nuovo->casaEditrice);
        fflush(stdin);
        printf(" Genere: ");
        scanf(" %s", nuovo->genere);
        fflush(stdin);
        do
        {
            printf(" Valutazione (inserire numero compreso tra 0 e 3) : ");
            scanf(" %d", &nuovo->valutazione);
            fflush(stdin);
        }
        while (nuovo->valutazione!=0 && nuovo->valutazione!=1 && nuovo->valutazione!=2 && nuovo->valutazione!=3);
        //inserisco la struttura in testa alla lista
        nuovo->next=*testa;
        *testa=nuovo;
    }
}

//funzione per cancellare un libro dalla lista tramite il codice identificativo
void cancellaLibro(struttura**testa, int codice)
{
    int trovato=0;
    struttura*temp; //utilizzo un puntatore d'appoggio per non perdere il riferimento al primo elemento
    temp=*testa;
    struttura*prec; //puntatore d'appoggio che mi indica l'elemento precedente a quello puntato da temp
    prec=NULL;
    if (*testa==NULL)  //se la lista è vuota non ci sono strutture da cancellare
        printf("\n Lista vuota, impossibile cancellare elemento.\n\n");

    else
    {
        while (temp!=NULL)  //scorro tutta la lista
        {
            if (temp->codice==codice)  //se trovo l'elemento da eliminare
            {
                if (prec==NULL)  //caso in cui sia il primo elemento, la testa punta al successivo
                    *testa=(*testa)->next;
                else
                    prec->next=temp->next;
                free(temp);  //faccio la free di temp per eliminare la struttura
                trovato=1;
                break;
            }
            prec=temp;
            temp=temp->next;
        }
        if (trovato==0)  //caso in cui l'elemento da eliminare non sia presente
            printf("\n Impossibile eliminare il libro. Non sono presenti libri con codice identificativo %d\n\n", codice);
    }
}
