#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "libstatica.h"
#include "libdinamica.h"
#include "libpuntatori.h"
#include "dato.h"

void usaListaStatica();
void usaListaDinamica();
void usaListaPuntatori();

int main(){
    int scelta;
    do{
        printf("Inserisci:\n(1) per usare la lista statica,\n(2) per usare la lista allocata dinamicamente,"
               "\n(3) per usare la lista di puntatori e struct,\n(0) per uscire.\n\nScelta: ");
        //ottengo il carattere da tastiera
        scelta=getchar();
        fflush(stdin);
        printf("\n");
        //a seconda della scelta, eseguo una determinata funzione
        switch (scelta){
            case '1':
                usaListaStatica();
                break;
            case '2':
                usaListaDinamica();
                break;
            case '3':
                usaListaPuntatori();
                break;
            case '0':
                break;
            default:
                printf("Scelta non riconosciuta.\n");
        }
        //dopo ogni operazione, pulisco lo schermo
        system("cls");
    }while(scelta!='0');

    return 0;
}


void usaListaStatica(){
    TipoLista lista;
    char scelta;
    TipoDato nuovoDato;
    int posizione;
    initListaStatica(&lista);
    //pulisco lo schermo e mostro lo stato della lista
    system("cls");
    statoListaStatica(&lista);
    printf("\nPremi qualsiasi tasto per continuare.\n");
    getch();
    system("cls");
    do{
        printf("| LISTA STATICA |\n\n");
        printf("Inserisci:\n(1) per aggiungere in testa,\n(2) per aggiungere in coda,\n(3) per aggiungere dopo una specifica posizione,"
               "\n(4) per cancellare in testa,\n(5) per cancellare in coda,\n(6) per cancellare la prima occorrenza di un valore,\n(0) per tornare alla scelta della lista.\n\nScelta: ");
        //ottengo il carattere da tastiera e lo converto in minuscolo
        scelta=getchar();
        fflush(stdin);
        printf("\n");
        //a seconda della scelta, eseguo una determinata funzione
        switch (scelta){
            case '1':
                //aggiungi in testa (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                inserisciInTestaStatico(&lista,nuovoDato);
                break;
            case '2':
                //aggiungi in coda (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                inserisciInCodaStatico(&lista,nuovoDato);
                break;
            case '3':
                //aggiungi dopo una certa posizione (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                printf("Inserisci la posizione dopo cui inserire il dato: ");
                scanf("%d",&posizione);
                fflush(stdin);
                inserisciDopoPosizioneStatico(&lista,nuovoDato,posizione);
                break;
            case '4':
                cancellaDaTestaStatico(&lista);
                break;
            case '5':
                cancellaDaCodaStatico(&lista);
                break;
            case '6':
                printf("Dato da cercare. ");
                nuovoDato = ottieniDato();
                cancellaOccorrenzaStatico(&lista,nuovoDato);
                break;
            case '0':
                break;
            default:
                printf("Scelta non riconosciuta.\n");
        }
        //dopo ogni operazione, pulisco lo schermo
        statoListaStatica(&lista);
        printf("\nPremi qualsiasi tasto per continuare.\n");
        getch();
        system("cls");
    }while(scelta!='0');
}

void usaListaDinamica(){
    TipoListaDinamica lista;
    TipoDato nuovoDato;
    char scelta;
    int posizione;
    lista = creaListaDinamica();
    //pulisco lo schermo e mostro lo stato della lista
    system("cls");
    statoListaDinamica(&lista);
    printf("\nPremi qualsiasi tasto per continuare.\n");
    getch();
    system("cls");
    do{
        printf("| LISTA DINAMICA |\n\n");
        printf("Inserisci:\n(1) per aggiungere in testa,\n(2) per aggiungere in coda,\n(3) per aggiungere dopo una specifica posizione,"
               "\n(4) per cancellare in testa,\n(5) per cancellare in coda,\n(6) per cancellare la prima occorrenza di un valore,\n(0) per tornare alla scelta della lista.\n\nScelta: ");
        //ottengo il carattere da tastiera e lo converto in minuscolo
        scelta=getchar();
        fflush(stdin);
        printf("\n");
        //a seconda della scelta, eseguo una determinata funzione
        switch (scelta){
            case '1':
                //aggiungi in testa (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                inserisciInTestaDinamico(&lista,nuovoDato);
                break;
            case '2':
                //aggiungi in coda (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                inserisciInCodaDinamico(&lista,nuovoDato);
                break;
            case '3':
                //aggiungi dopo una certa posizione (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                printf("Inserisci la posizione dopo cui inserire il dato: ");
                scanf("%d",&posizione);
                fflush(stdin);
                inserisciDopoPosizioneDinamico(&lista,nuovoDato,posizione);
                break;
            case '4':
                cancellaDaTestaDinamico(&lista);
                break;
            case '5':
                cancellaDaCodaDinamico(&lista);
                break;
            case '6':
                printf("Dato da cercare. ");
                nuovoDato = ottieniDato();
                cancellaOccorrenzaDinamico(&lista,nuovoDato);
                break;
            case '0':
                eliminaListaDinamica(&lista);
                break;
            default:
                printf("Scelta non riconosciuta.\n");
        }
        //dopo ogni operazione, pulisco lo schermo
        statoListaDinamica(&lista);
        printf("\nPremi qualsiasi tasto per continuare.\n");
        getch();
        system("cls");
    }while(scelta!='0');
}

void usaListaPuntatori(){
    //inizializzo la testa della lista
    NodoLista *testa;
    char scelta;
    int posizione;
    TipoDato nuovoDato;
    initLista(&testa);
    //pulisco lo schermo e mostro lo stato della lista
    system("cls");
    statoLista(testa);
    printf("\nPremi qualsiasi tasto per continuare.\n");
    getchar();
    system("cls");
    do{
        printf("| LISTA CON PUNTATORI E STRUTTURE |\n\n");
        printf("Inserisci:\n(1) per aggiungere in testa,\n(2) per aggiungere in coda,\n(3) per aggiungere dopo una specifica posizione,"
               "\n(4) per cancellare in testa,\n(5) per cancellare in coda,\n(6) per cancellare la prima occorrenza di un valore,\n(0) per tornare alla scelta della lista.\n\nScelta: ");
        //ottengo il carattere da tastiera e lo converto in minuscolo
        scelta=getchar();
        fflush(stdin);
        printf("\n");
        //a seconda della scelta, eseguo una determinata funzione
        switch (scelta){
            case '1':
                //aggiungi in testa (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                inserisciInTesta(&testa,nuovoDato);
                break;
            case '2':
                //aggiungi in coda (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                inserisciInCoda(&testa,nuovoDato);
                break;
            case '3':
                //aggiungi dopo una certa posizione (chiedo all'utente il dato da inserire)
                nuovoDato = ottieniDato();
                printf("Inserisci la posizione dopo cui inserire il dato: ");
                scanf("%d",&posizione);
                fflush(stdin);
                inserisciDopoPosizione(&testa,nuovoDato,posizione);
                break;
            case '4':
                cancellaDaTesta(&testa);
                break;
            case '5':
                cancellaDaCoda(&testa);
                break;
            case '6':
                printf("Dato da cercare. ");
                nuovoDato = ottieniDato();
                cancellaOccorrenza(&testa,nuovoDato);
                break;
            case '0':
                printf("Uscita dal programma.\n");
                cancellaLista(&testa);
                printf("Lista cancellata.\n");
                break;
            default:
                printf("Scelta non riconosciuta.\n");
        }
        //dopo ogni operazione, pulisco lo schermo
        statoLista(testa);
        printf("\nPremi qualsiasi tasto per continuare.\n");
        getchar();
        system("cls");
    }while(scelta!='0');
}
