#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcola_fattoriale(int n_fattoriale, char *indentazione)
{
    //Dichiarazioni:
    unsigned long long int risultato;//Contiene il fattoriale calcolato di volta in volta.
    char *puntatore_ultima_occorrenza;//Contiene l'ultimo tab da togliere per tornare indietro a scrivere.



    //Programma:

    printf("\n%scalcola fattoriale di %d = ",indentazione,n_fattoriale);//Scrive indentando il calcolo del fattoriale incompleto per dare l'idea della semplificazione del problema.

    //Verifica caso 0! o 1!
    if(n_fattoriale == 1 || n_fattoriale == 0)//Il programma verifica di essere arrivato al caso base, in questo caso da il primo risultato.
    {
        risultato = 1;
        printf("%lu",risultato);
    }
    else
    {
        strcat(indentazione," ");//Aumenta l'indentazione per la successiva iterazione della funzione.
        risultato = n_fattoriale * calcola_fattoriale(n_fattoriale - 1, indentazione);//Calcola il fattoriale per ricorsione richiamando con i valori aggiornati la stessa funzione.
        puntatore_ultima_occorrenza = strrchr(indentazione,(int)' ');//Serve per puntare all'ultima occorrenza dell'indentazione.
        strcpy(puntatore_ultima_occorrenza,"");//Elimina l'ultima indentazione.
        printf("\n%scalcola fattoriale di %d = %lu",indentazione,n_fattoriale,risultato);// Scrive il fattoriale evidenziando la ricostruzione del problema iniziale.
    }







    return risultato;
}
int main()
{
    //Dichiarazioni:
    int verifica;//Utilizzato per verificare che l'input dell'utente sia andato a buon fine.
    int n_fattoriale;//Numero del quale calacolare il fattoriale.
    char *indentazione;//Contiene una stringa di spazi utilizzata per indentare i risultati.



    //Programma:
    //Inserimento del numero sul quale calcolare il fattoriale:
    do
    {
        system("cls");
        printf("Inserire un numero intero positivo del quale si desidera calcolare il fattoriale: ");
        verifica = scanf("%d",&n_fattoriale);
        fflush(stdin);
        if(verifica == 0 || n_fattoriale < 0)
        {
            verifica = 0;
            printf("Errore: Inserire un numero intero positivo.");
            system("pause");
        }

    }while(verifica == 0);

    indentazione = (char*)malloc(n_fattoriale*sizeof(char));//Alloca la stringa che verrà incrementata o diminuita per l'indentazione.
    strcpy(indentazione,"");//Inserito per istanziare una prima stringa con terminatore per far lavorare bene la strcat.
    calcola_fattoriale(n_fattoriale,indentazione);//Chiama la funzione per calcolare il fattoriale.



    return 0;
}
