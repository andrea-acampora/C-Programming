#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    struttura*testa=NULL;
    int scelta, codice, valutazione;
    //menù per scegliare l'operazione da eseguire
    do
    {
        system("cls");
        printf("\n Seleziona l\'operazione\n");
        printf("\n 1-Inserire nuovo libro");
        printf("\n 2-Cancella libro");
        printf("\n 3-Visualizza tutti i libri");
        printf("\n 4-Visualizza i libri con una certa valutazione");
        printf("\n 5-Esci");
        printf("\n\n > ");
        scanf(" %d", &scelta);
        fflush(stdin);

        switch (scelta)
        {
            case(1):    inserisciLibro(&testa);
                        system("pause");
                        break;
            case(2):    printf("\n Quale libro vuoi eliminare\? Inserisci il codice identificativo: ");
                        scanf(" %d", &codice);
                        fflush(stdin);
                        cancellaLibro(&testa, codice);
                        system("pause");
                        break;
            case(3):    stampaLista(testa);
                        system("pause");
                        break;
            case(4):    printf("\n Valutazione in base a cui visualizzare i libri: ");
                        scanf(" %d", &valutazione);
                        fflush(stdin);
                        stampaValutazione(valutazione, testa);
                        system("pause");
                        break;
            case(5):    break;
            default:    printf("\n\n Valore inserito non valido.\n\n");
                        system("pause");
                        break;
        }
    }
    while (scelta!=5); //il programma viene terminato quando l'utente digita '5'

    return 0;
}
