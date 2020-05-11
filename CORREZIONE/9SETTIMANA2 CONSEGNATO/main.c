#include <stdio.h>
#include <stdlib.h>
#include "lista_strutture_concatenate.h"

/*Stampa singolo libro*/
void stampa_libro(TipoLista paux)
{
    printf("\n\nTitolo del libro: %s",paux->info.titolo);
    printf("Nome dell'autore: %s",paux->info.autore);
    printf("Anno di pubblicazione: %d",paux->info.annoPubblicazione);
    printf("\nCasa editrice: %s",paux->info.casaEditrice);
    printf("Numero di pagine: %d",paux->info.numeroPagine);
    printf("\nGenere : %s",paux->info.genere);
    printf("Codice : %d",paux->info.codice);
    printf("\nValutazione: %d",paux->info.valutazione);
}

/*Funzione per stampare tutti dati di tutti i libri inseriti*/
void stampa_dati(TipoLista *lista)
{
    TipoLista paux=*lista;
    for(;paux!=NULL;)
    {
        stampa_libro(paux);
        paux=paux->next;
    }

}

/*Funzione per stampare tutti i dati di solo i libri con una determinata valutazione*/
void stampa_valutazione(TipoLista *lista,int cercato)
{
    TipoLista p_scorrimento=*lista;
    for(;p_scorrimento!=NULL;)
    {
        if(p_scorrimento->info.valutazione==cercato)
            stampa_libro(p_scorrimento);
        p_scorrimento=p_scorrimento->next;
    }


}

int main()
{
    /*Dichiaro la variabile "lista" di tipo "TipoLista"*/
    TipoLista lista;

    /*Inizializzo la lista*/
    InitLista(&lista);

    /*All'interno del main creo un menù per permettere all'utente di selezionare l'azione da far eseguire*/
    int scelta;

    /*Pongo il menù all'interno di un ciclo la cui fine viene determinata dalla scelta dell'utente*/
    for(;;)
    {
        if (lista==NULL)
            printf("\nLa lista e' vuota");
        printf("\n\nQuale operazione scegli\?\n1)Per inserire in testa \n2)Per inserire dopo un certo elemento\n3)Per inserire in coda\n4)Per cancellare il primo libro della lista\n5)Per cancellare un libro a scelta");
        printf("\n6)Per cancellare l'ultimo libro\n7)Per visualizzare tutti i libri\n8)Per visualizzare solo i libri con una certa valutazione.\nAltro per terminare\n");
        scanf("%d",&scelta);
        fflush(stdin);

        /*INSERISCI IN TESTA*/
        if(scelta==1)
            InserisciTestaLista(&lista);

        /*INSERISCI DOPO UN CERTO ELEMENTO*/
        if (scelta==2)
        {
            int cercato;
            printf("\nInserire il codice del libro dopo il quale inserire:");
            scanf("%d",&cercato);
            fflush(stdin);
            inserisci_dopo_elemento(&lista,cercato);
        }

        /*INSERISCI IN CODA*/
        if (scelta==3)
        {
            InserisciCodaLista(&lista);
        }

        /*CANCELLA PRIMO DELLA LISTA*/
        if (scelta==4)
        {
            CancellaPrimoLista(&lista);
        }

        /*CANCELLA SPECIFICO LIBRO*/
        if (scelta==5)
        {
            int cercato;
            printf("\nInserire il codice del libro da eliminare\?");
            scanf("%d",&cercato);
            fflush(stdin);
            CancLista(&lista,cercato);
        }
        /*CANCELLA ULTIMO LIBRO*/
        if (scelta==6)
        {
            cancella_ultimo_elemento(&lista);
        }

        /*VISUALIZZA TUTTI GLI ELEMENTI*/
        if(scelta==7)
        {
            stampa_dati(&lista);
        }

        /*VISUALIZZA GLI ELEMENTI CON DETERMINATA VALUTAZIONE*/
        if (scelta==8)
        {
            int cercato;
            printf("\nQuale valutazione vuoi considerare\?");
            scanf("%d",&cercato);
            fflush(stdin);
            stampa_valutazione(&lista,cercato);

        }

        /*LIBERO MEMORIA E TERMINO IL PROGRAMMA*/
        else if(scelta!=1&&scelta!=2&&scelta!=3&&scelta!=4&&scelta!=5&&scelta!=6&&scelta!=7&&scelta!=8)
        {
            while(lista!=NULL)
                CancellaPrimoLista(&lista);
            break;
        }
    }
    return 0;

}

