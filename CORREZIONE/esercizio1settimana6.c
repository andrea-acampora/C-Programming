
/** Esercizio sulle funzioni*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/** Creo la funzione "*cerca" che prende in entrata un vettore e due interi (dimensione vettore e elemento da cercare)*/
/** Essa restituisce un vettore di puntatori ad intero*/
int *cerca(int vettore[], int dimensione, int elem)
{
    /** Dichiaro le variabili locali necessarie alla funzione*/
    int i;
    /** Attraverso malloc creo un vettore di interi in cui inserire gli indici di tutte le occorrenze*/
    /** Creo uno spazio di memoria grande "dimensione + 1" perche oltre alle occorrenze deve essere inserito un terminatore*/
    int *risultati = (int *)malloc(sizeof(int)*(dimensione+1));

    /** Se non è presente abbastanza memoria avverto l'utente e chiudo il programma*/
    if (risultati == NULL)
    {
        printf("Non c'e' memoria sufficiente! Il programma verra' interrotto!");
        exit(1);
    }
    int nRisultati = 0;//Conto con una variabile il numero di occorrenze trovate
    /** Con un ciclo dico al programma di ricercare nel vettore l'elemento desiderato e in base a ciò inserire nel vettore il suo indice*/
    for (i = 0; i < dimensione; i++)
    {
        if (vettore[i] == elem)
        {
            risultati[nRisultati] = i;// Mi deve restituire l'indice dell'elemento
            nRisultati++;
        }
    }
    /**Chiudo la serie di numeri con -1 in modo da concludere la serie di indici e poterli stampare (in quanto non conosco il numero di occorrenze)*/
    risultati[nRisultati] = -1;
    return risultati;// Nel caso non trovi nulla deve restituire -1
}
/** Creo la funzione "*cerca_vettore_ordinato" che prende in entrata un vettore e due interi (dimensione vettore e elemento da cercare)*/
/** Essa restituisce un vettore di puntatori ad intero*/
int *cerca_vettore_ordinato(int vettore[], int dimensione, int elem)
{
    /** Dichiaro le variabili locali necessarie alla funzione*/
    int i;
    /** Attraverso malloc creo un vettore di interi in cui inserire gli indici di tutte le occorrenze*/
    /** Creo uno spazio di memoria grande "dimensione + 1" perche oltre alle occorrenze deve essere inserito un terminatore*/
    int *risultati = (int *)malloc(sizeof(int)*(dimensione+1));
    /** Se non è presente abbastanza memoria avverto l'utente e chiudo il programma*/
    if (risultati == NULL)
    {
        printf("Non c'e' memoria sufficiente! Il programma verra' interrotto!");
        exit(1);
    }
    int nRisultati = 0;//Conto con una variabile il numero di occorrenze trovate
    /** Con un ciclo dico al programma di ricercare nel vettore l'elemento desiderato e in base a ciò inserire nel vettore il suo indice*/
    for (i = 0; i < dimensione; i++)
    {
        if (vettore[i] == elem)
        {
            risultati[nRisultati] = i;// Mi deve restituire l'indice dell'elemento
            nRisultati++;
        }
        /** Essendo il vettore ordinato se il programma esamina un numero maggiore di quello che deve trovare termino immediatamente il ciclo*/
        if (vettore[i] > elem)
            break;
    }
    /**Chiudo la serie di numeri con -1 in modo da concludere la serie di indici e poterli stampare (in quanto non conosco il numero di occorrenze)*/
    risultati[nRisultati] = -1;
    return risultati;// Nel caso non trovi nulla deve restituire -1
}
int main()
{
    printf("Esercizio con vettore disordinato e funzione cerca()\n\n");
    /** Dichiaro le variabili locali del main (sia per l'esercizio con "cerca" sia per quello con "cerca_vettore_ordinato"*/
    int numeroElementi, i, *vettoreElementi, *risultati;//Per "cerca"
    int numeroElementiOrdinati, *vettoreElementiOrdinati, *risultatiOrdinati;//Per "cerca_vettore_ordinato"
    int elemento, elementoInserito, controlloScanf;//Queste sono in comune per gli esercizi con le due diverse funzioni
    bool controllo;//In comune
    /** Chiedo all'utente quanto deve essere grande il vettore e inserisco gli opportuni controlli*/
    do
    {
        controllo = false;
        printf("Inserire il numero di elementi che si vuole inserire (da 1 a 100)\n==> ");
        controlloScanf = scanf("%d",&numeroElementi);
        fflush(stdin);
        if ((controlloScanf != 1)||((numeroElementi < 1)||(numeroElementi >100)))
        {
            controllo = true;
            printf("Il valore inserito non e' valido!\n");
        }
    }while (controllo == true);
    /** Alloco il vettore in base alla dimensione chiesta dall'utente attraverso malloc*/
    vettoreElementi = (int *)malloc(sizeof(int)*numeroElementi);
    /** Se non è presente abbastanza memoria avverto l'utente e chiudo il programma*/
    if (vettoreElementi == NULL)
    {
        printf("Non c'e' memoria sufficiente! Il programma verra' interrotto!");
        exit(1);
    }
    /**Chiedo all'utente di inserire gli elementi nel vettore e inserisco gli opportuni controlli*/
    for (i = 0; i < numeroElementi; i++)
    {
        do
        {
            controllo = false;
            printf("Inserire l'elemento numero %d\n==> ",i+1);
            controlloScanf = scanf("%d",&elementoInserito);
            fflush(stdin);
            if (controlloScanf != 1)
            {
                controllo = true;
                printf("Il valore inserito non e' valido!\n");
            }
        } while (controllo == true);
        vettoreElementi[i] = elementoInserito;
    }
    /**Chiedo all'utente di inserire l'elemento da ricercare nel vettore e inserisco gli opportuni controlli*/
    do
    {
        controllo = false;
        printf("Inserire l'elemento da ricercare\n==> ");
        controlloScanf = scanf("%d",&elemento);
        fflush(stdin);
        if (controlloScanf != 1)
        {
            controllo = true;
            printf("Il valore inserito non e' valido!\n");
        }
    } while (controllo == true);
    /** risultati chiama la funzione cerca e mi restituisce l'opportuno risultato*/
    risultati = cerca(vettoreElementi, numeroElementi, elemento);
    if (*risultati == -1)//Nessuna occorrenza
        printf("Righe con elemento %d non trovato => la funzione ritorna %d\n",elemento,risultati[0]);
    else//Stampa gli indici di tutte le occorrenze
    {
        printf("L'elemento %d e' stato trovato all'indice:\n",elemento);
        for (int i=0; risultati[i] != -1; i++)
            printf("=>%d\n", risultati[i]);
    }
    /** Pulisco la zona di memoria allocata con la malloc nella heap per i valori di ritorno dalla ricerca*/
    free(risultati);
    /** Pulisco la zona di memoria per contenere i valori chiesti all'utente*/
    free(vettoreElementi);

    printf("\nPer continuare (esercizio con vettore ordinato) premere invio");
    getchar();//Aspetto
    system("cls");//Pulisco la schermata

    printf("Esercizio con vettore ordinato e funzione cerca_vettore_ordinato()\n\n");
    /** Chhiedo all'utente quanto deve essere grande il vettore e inserisco gli opportuni controlli*/
    do
    {
        controllo = false;
        printf("Inserire il numero di elementi che si vuole inserire (da 1 a 100)\n");
        printf("Il vettore deve essere ordinato\n==> ");
        controlloScanf = scanf("%d",&numeroElementiOrdinati);
        fflush(stdin);
        if ((controlloScanf != 1)||((numeroElementiOrdinati < 1)||(numeroElementiOrdinati >100)))
        {
            controllo = true;
            printf("Il valore inserito non e' valido!\n");
        }
    }while (controllo == true);
    /** Alloco il vettore in base alla dimensione chiesta dall'utente attraverso malloc*/
    vettoreElementiOrdinati = (int *)malloc(sizeof(int)*numeroElementiOrdinati);
    /** Se non è presente abbastanza memoria avverto l'utente e chiudo il programma*/
    if (vettoreElementiOrdinati == NULL)
    {
        printf("Non c'e' memoria sufficiente! Il programma verra' interrotto!");
        exit(1);
    }
    /**Chiedo all'utente di inserire gli elementi nel vettore e inserisco gli opportuni controlli*/
    for (i = 0; i < numeroElementiOrdinati; i++)
    {
        do
        {
            controllo = false;
            printf("Inserire l'elemento numero %d\n==> ",i+1);
            controlloScanf = scanf("%d",&elementoInserito);
            fflush(stdin);
            if (controlloScanf != 1)
            {
                controllo = true;
                printf("Il valore inserito non e' valido!\n");
            }
            if (i > 0)
            {
                if (elementoInserito < vettoreElementiOrdinati[i-1])/** Se l'elemento inserito è minore del precedente avverto l'utente dell'errore*/
                {
                    controllo = true;
                    printf("Il valore inserito e' minore del precedente! (dovrebbe essere uguale o maggiore)\n");
                }
            }
        } while (controllo == true);
        vettoreElementiOrdinati[i] = elementoInserito;
    }
    /**Chiedo all'utente di inserire l'elemento da ricercare nel vettore e inserisco gli opportuni controlli*/
    do
    {
        controllo = false;
        printf("Inserire l'elemento da ricercare\n==> ");
        controlloScanf = scanf("%d",&elemento);
        fflush(stdin);
        if (controlloScanf != 1)
        {
            controllo = true;
            printf("Il valore inserito non e' valido!\n");
        }
    } while (controllo == true);
    /** risultatiOrdinati chiama la funzione cerca e mi restituisce l'opportuno risultato*/
    risultatiOrdinati = cerca_vettore_ordinato(vettoreElementiOrdinati, numeroElementiOrdinati, elemento);
    if (*risultatiOrdinati == -1)//Nessuna occorrenza
        printf("Righe con elemento %d non trovato => la funzione ritorna %d\n",elemento,risultatiOrdinati[0]);
    else//Stampa gli indici di tutte le occorrenze
    {
        printf("L'elemento %d e' stato trovato all'indice:\n",elemento);
        for (int i = 0; risultatiOrdinati[i] != -1; i++)
            printf("=>%d\n", risultatiOrdinati[i]);
    }
    /** Pulisco la zona di memoria allocata con la malloc nella heap per i valori di ritorno dalla ricerca*/
    free(risultatiOrdinati);
    /** Pulisco la zona di memoria per contenere i valori chiesti all'utente*/
    free(vettoreElementiOrdinati);
    getchar();

}
